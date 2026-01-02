### Level 5 (Basic Router Configuration)

- Why specific IP addresses were chosen (e.g., [`50.100.100.2`](42/kickoff/netpractice/README.md:302), [`50.100.100.126`](42/kickoff/netpractice/README.md:303))
- Subnet mask selection (`/25` and `/18`)
- Why routing uses default vs specific routes
- Gateway selection principles
- Alternative IP schemes using private ranges

### Level 9 (Complex Multi-Router with Internet)

- All network segments explained with rationale:
  - A-B-R1 switch network using [`50.198.100.0/25`](42/kickoff/netpractice/README.md:324)
  - R1-R2 backbone with different masks (`/24` and `/30` compatibility)
  - R2-C using public IPs [`86.64.1.0/24`](42/kickoff/netpractice/README.md:333)
  - **R2-D with `/18` mask** ([`86.64.64.0/18`](42/kickoff/netpractice/README.md:337)) explained in detail
  - R1-Internet edge connection
- Why default routes are used for hosts and downstream routers
- Why R1 uses [`86.64.0.0/16`](42/kickoff/netpractice/README.md:350) summary route
- Why Internet needs specific return routes
- Complete packet flow examples
- **Why public IPs are required** for Internet connectivity

### Level 10 (Overlapping Networks Solution)

- **Variable Length Subnet Masking (VLSM)** explained
- How different masks prevent IP overlaps
- Why R22 needs different mask than other interfaces
- Binary subnet calculation examples
- Multiple alternative solutions with pros/cons

### IP Conservation Best Practices

- Right-sizing subnets based on actual needs
- Using `/30` for router-to-router links
- Summary route aggregation strategies
- Hierarchical network planning

### Step-by-Step Problem-Solving Framework

- Default vs specific route decision matrix
- IP address selection conventions
- Mask selection to avoid overlaps
- Gateway configuration rules
- Complete verification checklist

The tutorial provides multiple alternative solutions for each problem, discusses trade-offs, and includes practical examples of packet flow through the networks.
