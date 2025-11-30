# Network Practice

## Table of Contents
1. [Understanding Network Fundamentals](#fundamentals)
2. [IP Addressing](#ip-addressing)
3. [Subnet Masks (CIDR)](#subnet-masks)
4. [Routing Tables](#routing-tables)
5. [Step-by-Step Problem Solving](#problem-solving)
6. [Level-by-Level Solutions](#solutions)
7. [Common Mistakes & Tips](#tips)

---

## 1. Understanding Network Fundamentals {#fundamentals}

### Network Components

**Host**: A computer/device with an IP address (e.g., Computer A, Server)
**Router**: Connects different networks, forwards packets between them
**Switch**: Connects devices in the same network (Layer 2, no routing)
**Internet**: Special router representing external networks

### Direct Connection Rules
- Devices on the **same link** must be in the **same subnet**
- A router's interfaces must be on **different subnets**
- Switches forward all traffic (no IP configuration needed)

---

## 2. IP Addressing {#ip-addressing}

### IP Address Format
`A.B.C.D` where each octet (A, B, C, D) is 0-255

### Reserved Addresses
- **Network address**: First IP in subnet (e.g., `192.168.1.0/24` → `192.168.1.0`)
- **Broadcast address**: Last IP in subnet (e.g., `192.168.1.0/24` → `192.168.1.255`)
- **Loopback**: `127.0.0.0/8` (invalid for external interfaces)

### Private vs Public IPs

**Private IP Ranges** (not routable over Internet):
- `10.0.0.0/8` → 10.0.0.0 - 10.255.255.255
- `172.16.0.0/12` → 172.16.0.0 - 172.31.255.255
- `192.168.0.0/16` → 192.168.0.0 - 192.168.255.255

**Public IPs**: Everything else (e.g., `86.64.x.x`, `50.198.x.x`)

**Important**: In net_practice, Internet refuses to route private IPs!

### Choosing IP Addresses

**Example from Level 9:**
```
Network 1 (A-B-R1): 50.198.100.0/25
- A1: 50.198.100.2
- B1: 50.198.100.42
- R11: 50.198.100.1
```

**Why these choices?**
- All in same `/25` subnet (0-127)
- Avoid .0 (network) and .127 (broadcast)
- Router typically gets .1 or .254
- Hosts get sequential IPs (.2, .42, etc.)

**Alternatives:**
```
Same network, different IPs:
- A1: 50.198.100.10
- B1: 50.198.100.20
- R11: 50.198.100.1
```

---

## 3. Subnet Masks (CIDR) {#subnet-masks}

### CIDR Notation

`/N` means first N bits are network, remaining bits are hosts

### Common Masks

| CIDR | Decimal Mask | Hosts | Network Size | Example Range |
|------|--------------|-------|--------------|---------------|
| `/30` | 255.255.255.252 | 2 | Point-to-point | 192.168.1.0-3 |
| `/29` | 255.255.255.248 | 6 | Small network | 192.168.1.0-7 |
| `/28` | 255.255.255.240 | 14 | Tiny network | 192.168.1.0-15 |
| `/27` | 255.255.255.224 | 30 | | 192.168.1.0-31 |
| `/26` | 255.255.255.192 | 62 | | 192.168.1.0-63 |
| `/25` | 255.255.255.128 | 126 | | 192.168.1.0-127 |
| `/24` | 255.255.255.0 | 254 | Standard LAN | 192.168.1.0-255 |
| `/18` | 255.255.192.0 | 16,382 | Large network | 86.64.64.0-127.255 |
| `/16` | 255.255.0.0 | 65,534 | Class B | 192.168.0.0-255.255 |
| `/8` | 255.0.0.0 | 16,777,214 | Class A | 10.0.0.0-255.255.255 |

### Calculating Subnets

**Example: `86.64.102.72/18`**

1. `/18` = first 18 bits are network
2. Binary: `86.64.01100110.01001000`
3. Mask: `11111111.11111111.11000000.00000000`
4. Network: `86.64.01000000.00000000` = `86.64.64.0`
5. Range: `86.64.64.0` - `86.64.127.255`

**Quick Check**: Does `86.64.102.72` fit in `86.64.64.0/18`?
- 102 is between 64-127 ✅

### Choosing Masks

**For directly connected devices:**
- Use same mask (or compatible masks where one encompasses the other)
- Example: `/24` and `/25` can coexist if both are within same /24

**For router-to-router links:**
- Use `/30` (minimal waste, only 2 usable IPs)
- Example: R13 (`50.100.17.254/30`) ↔ R21 (`50.100.17.253/30`)

**For hosts with many devices:**
- Use `/24` (254 hosts - standard)
- Use `/25` (126 hosts - moderate)

---

## 4. Routing Tables {#routing-tables}

### Route Components

**Route**: Destination network (CIDR notation)
**Gateway**: Next-hop IP address to reach that network

### Route Types

**1. Default Route** (`0.0.0.0/0` or `default`)
- Matches ALL destinations
- Catch-all for unknown networks
- Use for simple hosts or routers with one upstream path

**Example:**
```
Host A route: 0.0.0.0/0, gateway: 192.168.1.1
Meaning: "Send ALL traffic to router at 192.168.1.1"
```

**2. Specific Route**
- Matches specific network/subnet
- Takes priority over broader routes
- Use when you need precise control

**Example:**
```
R1 route: 86.64.0.0/16, gateway: 50.100.17.253
Meaning: "Send traffic for 86.64.x.x to router at 50.100.17.253"
```

**3. Host Route** (`/32`)
- Matches single IP
- Most specific possible

### Route Priority

Routes are processed **most specific first**:
1. `/32` (single host)
2. `/24` (256 IPs)
3. `/16` (65K IPs)
4. `/8` (16M IPs)
5. `/0` (default - all IPs)

**Example:**
```
Router has:
- Route 1: 86.64.102.0/24, gateway A
- Route 2: 86.64.0.0/16, gateway B
- Route 3: 0.0.0.0/0, gateway C

Packet to 86.64.102.50: Uses Route 1 (most specific)
Packet to 86.64.200.1: Uses Route 2 (matches /16)
Packet to 8.8.8.8: Uses Route 3 (default)
```

### Gateway Selection

**Gateway must be:**
1. On the same subnet as the outgoing interface
2. The IP of the next-hop device (router/host)

**Example from Level 9:**
```
Host A needs to reach Internet:
- A1: 50.198.100.2/25
- R11: 50.198.100.1/25 (same subnet ✅)
- A's route: 0.0.0.0/0, gateway: 50.198.100.1
```

**Why this works:**
- A sends packet to 50.198.100.1 (directly reachable)
- R1 receives packet, consults its routing table
- R1 forwards toward Internet

**Common Mistake:**
```
❌ A's route: 0.0.0.0/0, gateway: 163.172.250.1
Problem: 163.172.250.1 is NOT on A's subnet!
```

---

## 5. Step-by-Step Problem Solving {#problem-solving}

### Phase 1: Analyze Topology

1. **Identify all devices** (hosts, routers, switches, Internet)
2. **Map connections** (which interfaces link together)
3. **Note fixed values** (ip_edit='false', mask_edit='false')
4. **Identify goals** (which hosts must communicate)

### Phase 2: Configure Networks

**For each physical link:**

1. **Determine subnet size**
   - 2 devices only (router-router): `/30`
   - Small network (2-30 hosts): `/27` - `/24`
   - Switch with multiple hosts: `/24`

2. **Assign IPs in same subnet**
   ```
   Link: R1 ↔ R2
   Choose: 50.100.17.0/30
   - R1: 50.100.17.254
   - R2: 50.100.17.253
   ```

3. **Verify no conflicts**
   - Router interfaces on DIFFERENT subnets
   - No duplicate IPs
   - Avoid network/broadcast addresses

### Phase 3: Configure Routing

**For each device:**

1. **Hosts**: Usually one default route
   ```
   Host A route: default, gateway: <router_IP_on_same_subnet>
   ```

2. **Routers**: Multiple routes for different destinations
   ```
   R1 routes:
   - Route to network X: X.X.X.X/N, gateway: <next_router_IP>
   - Route to network Y: Y.Y.Y.Y/N, gateway: <next_router_IP>
   - Default route: 0.0.0.0/0, gateway: <upstream_router_IP>
   ```

3. **Internet**: Routes back to internal networks
   ```
   Internet routes:
   - Route 1: <internal_network_1>, gateway: <edge_router_IP>
   - Route 2: <internal_network_2>, gateway: <edge_router_IP>
   ```

### Phase 4: Test & Debug

1. **Trace forward path**: Source → Destination
2. **Trace reverse path**: Destination → Source
3. **Common errors**:
   - "No forward way": Missing/incorrect route at intermediate router
   - "No reverse way": Missing return route (often at Internet)
   - "Duplicate IP": Two interfaces have same IP
   - "Invalid IP": IP is network/broadcast address or out of range
   - "Private subnets not routed": Using 10.x, 172.16.x, or 192.168.x with Internet

---

## 6. Level-by-Level Solutions {#solutions}

### Level 2: Basic Subnet Configuration
**Goal**: A ↔ B, C ↔ D (two separate networks)

**Solution:**
```
Network A-B:
- A1: 192.168.100.1, mask: /27 (fixed)
- B1: 192.168.100.222, mask: /24 (change to fit .222)

Network C-D:
- C1: 192.0.0.1, mask: /30 (not loopback!)
- D1: 192.0.0.2, mask: /30
```

**Key Learning**: Expand mask to encompass mismatched IPs

### Level 5: Basic Routing
**Goal**: A ↔ B through router R

**Solution:**
```
Network A-R1: 50.100.100.0/25
- A1: 50.100.100.2/25
- R1: 50.100.100.126/25

Network B-R2: 150.100.100.0/18
- B1: 150.100.100.42/18
- R2: 150.100.100.254/18

Routes:
- A: route 150.100.0.0/18, gateway 50.100.100.126
- B: route default, gateway 150.100.100.254
```

**Key Learning**: Gateway = router's IP on your network

### Level 9: Complex Multi-Router with Internet
**Goal**: All hosts communicate with each other and Internet

**Full Configuration:**
```
Variables: e=50, f=100, g=24, h=24, i=24, j=50, k=100, a=86, b=64, c=102, d=73

Networks:
1. A-B-R1 (switch): 50.198.100.0/25
   - A1: 50.198.100.2/25
   - B1: 50.198.100.42/25
   - R11: 50.198.100.1/25

2. R1-R2: 50.100.17.0/24 ↔ 50.100.17.252/30
   - R13: 50.100.17.254/24
   - R21: 50.100.17.253/30

3. R2-C: 86.64.1.0/24
   - R22: 86.64.1.254/24
   - C1: 86.64.1.1/24

4. R2-D: 86.64.64.0/18
   - R23: 86.64.102.73/18
   - D1: 86.64.102.72/18

5. R1-Internet: 163.172.250.0/28
   - R12: 163.172.250.12/28
   - I1: 163.172.250.1/28

Routes:
- A: default → 50.198.100.1
- B: default → 50.198.100.1
- C: default → 86.64.1.254
- D: default → 86.64.102.73
- R1: 86.64.0.0/16 → 50.100.17.253
- R1: default → 163.172.250.1
- R2: default → 50.100.17.254
- Internet: 50.198.100.0/22 → 163.172.250.12
- Internet: 86.64.1.0/24 → 163.172.250.12
- Internet: 86.64.64.0/18 → 163.172.250.12
```

**Key Learning**: Use public IPs for Internet-facing hosts

---

## 7. Common Mistakes & Tips {#tips}

### Mistakes to Avoid

❌ **Using loopback (127.x.x.x) for interfaces**
```
Bad: C1: 127.0.0.1/30
Good: C1: 192.0.0.1/30
```

❌ **Gateway not on same subnet**
```
Bad: A (192.168.1.2/24), gateway: 10.0.0.1
Good: A (192.168.1.2/24), gateway: 192.168.1.1
```

❌ **Router interfaces on same network**
```
Bad: R1: 192.168.1.1/24, R2: 192.168.1.2/24
Good: R1: 192.168.1.1/24, R2: 10.0.0.1/24
```

❌ **Using private IPs with Internet**
```
Bad: C: 10.0.0.1 reaching Internet
Good: C: 86.64.1.1 reaching Internet
```

❌ **Network/broadcast address as IP**
```
Bad: IP 192.168.1.0/24 (network address)
Bad: IP 192.168.1.255/24 (broadcast)
Good: IP 192.168.1.1/24
```

### Tips for Speed

✅ **Use default routes when possible**
- Simpler configuration
- Fewer mistakes
- Works for most hosts

✅ **Use /30 for router links**
- Minimal IP waste
- Clear point-to-point connections

✅ **Use /24 for host networks**
- Standard size
- Easy to calculate

✅ **Keep IP schemes consistent**
- Use same first octets for related networks
- Example: 50.100.X.X for all internal, 86.64.X.X for public

✅ **Router IPs typically .1 or .254**
- Easy to remember
- Standard convention

✅ **Test incrementally**
- Configure one network at a time
- Verify before moving to next

### Quick Reference Card

```
Subnet Sizes:
/30 = 4 IPs (2 usable) - Router links
/24 = 256 IPs (254 usable) - Standard LAN
/18 = 16K IPs - Large network

Private IP Ranges:
10.0.0.0/8
172.16.0.0/12
192.168.0.0/16

Route Types:
0.0.0.0/0 = Default (all traffic)
X.X.X.X/N = Specific network

Gateway Rules:
- Must be on same subnet
- Must be directly reachable
- Typically router's IP
```

---

**Remember**: Net_practice is about understanding how packets flow through networks. Master subnetting, routing, and gateway selection, and you'll solve any level!

## Useful Resources

- [Networking Basics (2025) | What is a switch, router, gateway, subnet, gateway, firewall & DMZ](https://www.youtube.com/watch?v=_IOZ8_cPgu8)
- [You Suck at Subnetting](https://www.youtube.com/playlist?list=PLIhvC56v63IKrRHh3gvZZBAGvsvOhwrRF)