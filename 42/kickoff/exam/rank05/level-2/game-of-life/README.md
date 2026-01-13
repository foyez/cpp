# Conway's Game of Life with Pen Drawing - Explanation

## Program Overview

This program implements Conway's Game of Life with a unique pen-based drawing system to create the initial board configuration.

### Compilation & Usage
```bash
gcc -Wall -Wextra -Werror life.c -o life
echo 'sdxddssaaww' | ./life 5 5 0
```

**Arguments:**
- `width`: Board width
- `height`: Board height  
- `iterations`: Number of Game of Life generations to simulate

---

## Part 1: Pen Drawing System

### How the Pen Works

The pen starts at position `(0, 0)` (top-left corner) with the pen **lifted** (not drawing).

### Commands:
- `w` - Move up (y-1)
- `a` - Move left (x-1)
- `s` - Move down (y+1)
- `d` - Move right (x+1)
- `x` - Toggle pen (lift/lower)

### Key Rules:
1. Pen only draws when **lowered** (after 'x' command)
2. Pen cannot move outside board boundaries
3. Invalid commands are ignored
4. When pen is lowered (`x`), it immediately draws at current position

---

## Detailed Code Walkthrough

### Data Structures

```c
typedef struct {
    int x;          // Current x position
    int y;          // Current y position
    int pen_down;   // 0 = pen up, 1 = pen down
} Pen;

typedef struct {
    char **grid;    // 2D array of cells
    int width;
    int height;
} Board;
```

### Board Initialization

```c
Board* create_board(int width, int height) {
    Board *board = malloc(sizeof(Board));
    board->width = width;
    board->height = height;
    board->grid = malloc(sizeof(char*) * height);
    
    for (int i = 0; i < height; i++) {
        board->grid[i] = calloc(width, sizeof(char));
        // calloc initializes to 0 (null chars) = dead cells
    }
    
    return board;
}
```

**Why `calloc`?** 
- Automatically initializes memory to 0
- Dead cells are represented by spaces (or null chars initially)

### Command Processing

```c
void process_command(Board *board, Pen *pen, char cmd) {
    int new_x = pen->x;
    int new_y = pen->y;
    
    // Calculate new position based on command
    if (cmd == 'w') {
        new_y = pen->y - 1;  // Move up
    } else if (cmd == 's') {
        new_y = pen->y + 1;  // Move down
    } else if (cmd == 'a') {
        new_x = pen->x - 1;  // Move left
    } else if (cmd == 'd') {
        new_x = pen->x + 1;  // Move right
    } else if (cmd == 'x') {
        pen->pen_down = !pen->pen_down;  // Toggle pen
        if (pen->pen_down) {
            board->grid[pen->y][pen->x] = '0';  // Draw immediately
        }
        return;
    } else {
        return; // Invalid command - do nothing
    }
    
    // Bounds checking
    if (new_x >= 0 && new_x < board->width && 
        new_y >= 0 && new_y < board->height) {
        pen->x = new_x;
        pen->y = new_y;
        
        // Draw if pen is down
        if (pen->pen_down) {
            board->grid[pen->y][pen->x] = '0';
        }
    }
    // If out of bounds, pen stays still
}
```

**Key Points:**
- Calculate new position first, then check bounds
- Only move if new position is valid
- Draw at new position if pen is down

---

## Part 2: Conway's Game of Life

### The Rules

For each cell in each generation:

1. **Survival**: Live cell with 2-3 neighbors survives
2. **Birth**: Dead cell with exactly 3 neighbors becomes alive
3. **Death**: All other cells die or stay dead

### Counting Neighbors

```c
int count_neighbors(Board *board, int x, int y) {
    int count = 0;
    
    // Check all 8 neighbors (3x3 grid minus center)
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;  // Skip center cell
            
            int nx = x + dx;
            int ny = y + dy;
            
            // Only count if neighbor is within bounds
            if (nx >= 0 && nx < board->width && 
                ny >= 0 && ny < board->height) {
                if (board->grid[ny][nx] == '0') {
                    count++;
                }
            }
            // Cells outside board are considered dead (contribute 0)
        }
    }
    
    return count;
}
```

**Neighbor Pattern:**
```
(-1,-1) (0,-1) (1,-1)
(-1, 0) [CELL] (1, 0)
(-1, 1) (0, 1) (1, 1)
```

### Simulating a Generation

```c
void simulate_generation(Board *board) {
    // Create temporary board for new generation
    Board *new_board = create_board(board->width, board->height);
    
    for (int y = 0; y < board->height; y++) {
        for (int x = 0; x < board->width; x++) {
            int neighbors = count_neighbors(board, x, y);
            int is_alive = (board->grid[y][x] == '0');
            
            // Apply Game of Life rules
            if (is_alive && (neighbors == 2 || neighbors == 3)) {
                // Survival: 2-3 neighbors
                new_board->grid[y][x] = '0';
            } else if (!is_alive && neighbors == 3) {
                // Birth: exactly 3 neighbors
                new_board->grid[y][x] = '0';
            } else {
                // Death: all other cases
                new_board->grid[y][x] = ' ';
            }
        }
    }
    
    // Copy new generation back to original board
    for (int y = 0; y < board->height; y++) {
        for (int x = 0; x < board->width; x++) {
            board->grid[y][x] = new_board->grid[y][x];
        }
    }
    
    free_board(new_board);
}
```

**Why create a new board?**
- Game of Life rules apply simultaneously to all cells
- Can't update in-place or early updates affect later calculations
- Must calculate all new states, then swap boards

---

## Example Walkthrough: `echo 'dxss' | ./life 3 3 1`

### Step 1: Initial Drawing

```
Commands: d x s s
Pen starts at (0,0), pen up

Command 'd': Move right → pen at (1,0), pen still up
Command 'x': Lower pen → pen at (1,0), pen down, draw '0'
Board:
 0 
   
   

Command 's': Move down → pen at (1,1), pen down, draw '0'
Board:
 0 
 0 
   

Command 's': Move down → pen at (1,2), pen down, draw '0'
Board:
 0 
 0 
 0 
```

### Step 2: Game of Life (1 iteration)

**Analyze each cell:**

```
Initial board:
 0    (positions: row,col)
 0    (0,1) (1,1) (2,1) are alive
 0 

Count neighbors for each cell:

(0,0): neighbors = 1 (only 0,1) → dead, needs 3 → stays dead
(0,1): neighbors = 1 (only 1,1) → alive, needs 2-3 → dies
(0,2): neighbors = 1 (only 0,1) → dead, needs 3 → stays dead

(1,0): neighbors = 2 (0,1 and 1,1) → dead, needs 3 → stays dead
(1,1): neighbors = 2 (0,1 and 2,1) → alive, has 2 → survives
(1,2): neighbors = 2 (1,1 and 2,1) → dead, needs 3 → stays dead

(2,0): neighbors = 1 (only 1,1) → dead, needs 3 → stays dead
(2,1): neighbors = 1 (only 1,1) → alive, needs 2-3 → dies
(2,2): neighbors = 1 (only 2,1) → dead, needs 3 → stays dead

BUT WAIT! Let me recalculate more carefully:

(0,1): Check neighbors at (-1,0), (-1,1), (-1,2), (0,0), (0,2), (1,0), (1,1), (1,2)
       Only (1,1) is in bounds and alive → 1 neighbor → dies

(1,1): Check neighbors at (0,0), (0,1), (0,2), (1,0), (1,2), (2,0), (2,1), (2,2)
       (0,1) and (2,1) are alive → 2 neighbors → survives!

(2,1): Check neighbors: only (1,1) is alive → 1 neighbor → dies

Wait, let me check (1,0), (1,2):
(1,0): neighbors are (0,1) and (1,1) → 2 neighbors, but cell is dead → needs 3 → stays dead
(1,2): neighbors are (1,1) and (2,1) → 2 neighbors, but cell is dead → needs 3 → stays dead

Actually, horizontal cells (1,0) and (1,2):
(1,0): Count neighbors including (0,0), (0,1), (1,1), (2,0), (2,1)
       Alive: (0,1), (1,1), (2,1) = 3 neighbors → dead cell with 3 neighbors → BIRTH!

(1,2): Count neighbors including (0,1), (0,2), (1,1), (2,1), (2,2)
       Alive: (0,1), (1,1), (2,1) = 3 neighbors → dead cell with 3 neighbors → BIRTH!

Result after 1 iteration:
   
000
   
```

This matches the expected output!

---

## Key Programming Concepts

### Memory Management

```c
// Allocation
char **grid = malloc(sizeof(char*) * height);
for (int i = 0; i < height; i++) {
    grid[i] = calloc(width, sizeof(char));
}

// Deallocation (important!)
for (int i = 0; i < height; i++) {
    free(grid[i]);
}
free(grid);
```

### Reading from stdin

```c
char cmd;
while (read(0, &cmd, 1) > 0) {
    // Process each character
}
```

**Why `read(0, &cmd, 1)`?**
- File descriptor 0 = stdin
- Read 1 byte at a time
- Returns number of bytes read (0 = EOF)

### Custom putchar

```c
void putchar_custom(char c) {
    write(1, &c, 1);  // fd 1 = stdout
}
```

Used instead of standard `putchar` to show we're only using allowed functions.

---

## Common Pitfalls & Solutions

### Pitfall 1: Updating Board In-Place
**Wrong:**
```c
board->grid[y][x] = new_value;  // Changes affect next calculations!
```

**Right:**
```c
new_board->grid[y][x] = new_value;  // Use temporary board
```

### Pitfall 2: Off-by-One Errors in Neighbor Counting
Make sure to:
- Skip center cell (`if (dx == 0 && dy == 0) continue`)
- Check bounds before accessing array

### Pitfall 3: Pen Drawing Logic
Remember:
- 'x' command draws immediately at current position
- Movement commands only draw if pen is already down

---

## Testing Strategy

Test each component:

1. **Pen drawing without iterations** (iterations = 0)
2. **Simple patterns** (vertical line, horizontal line)
3. **Game of Life oscillators** (patterns that repeat)
4. **Edge cases** (commands going out of bounds)

Example oscillator:
```bash
echo 'dxss' | ./life 3 3 0  # Vertical line
echo 'dxss' | ./life 3 3 1  # Becomes horizontal
echo 'dxss' | ./life 3 3 2  # Back to vertical
```

---