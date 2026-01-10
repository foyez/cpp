# BSQ (Biggest Square)

## Problem Overview

Find the largest square that can fit on a map while avoiding obstacles, then fill it with a special character.

### Input Format

**First line:** `rows empty_char obstacle_char full_char`
- Number of rows in the map
- Character representing empty space
- Character representing obstacle
- Character to fill the square with

**Following lines:** The actual map

### Example
```
9 . o x
...........................
....o......................
............o..............
```

---

## Algorithm: Dynamic Programming

### The Key Insight

For each cell `(i, j)`, calculate the **size of the largest square** that has its **bottom-right corner** at that position.

### DP Formula

```
If cell[i][j] is an obstacle:
    dp[i][j] = 0

If cell[i][j] is empty:
    If i == 0 or j == 0:
        dp[i][j] = 1  (edge cells can only have 1x1 squares)
    Else:
        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
```

### Why This Formula Works

Consider a cell at position `(i, j)`. To form a square of size `k` with bottom-right at `(i, j)`:
- There must be a square of size `k-1` at `(i-1, j)` (above)
- There must be a square of size `k-1` at `(i, j-1)` (left)
- There must be a square of size `k-1` at `(i-1, j-1)` (diagonal)

The minimum of these three determines the maximum square size we can create.

### Visual Example

```
Map:
. . . .
. . . .
. . o .
. . . .

DP Table (step by step):

After row 0:
1 1 1 1

After row 1:
1 1 1 1
1 2 2 2

After row 2:
1 1 1 1
1 2 2 2
1 2 0 1

After row 3:
1 1 1 1
1 2 2 2
1 2 0 1
1 2 1 2

Largest value: 2 (appears at multiple positions)
First occurrence (top-left priority): position (0,1) creates a 2x2 square
```

---

## Code Walkthrough

### Data Structures

```c
typedef struct {
    int rows;           // Number of rows
    int cols;           // Number of columns
    char empty_char;    // Character for empty cells
    char obstacle_char; // Character for obstacles
    char full_char;     // Character to fill solution
    char **map;         // 2D array of the map
} Map;

typedef struct {
    int size;  // Size of the square
    int row;   // Top-left row position
    int col;   // Top-left column position
} Square;
```

### Reading the Map

```c
Map* read_map(FILE *fp) {
    Map *map = malloc(sizeof(Map));
    
    // Read first line: rows empty obstacle full
    if (fscanf(fp, "%d %c %c %c\n", &map->rows, &map->empty_char, 
               &map->obstacle_char, &map->full_char) != 4) {
        free(map);
        return NULL;
    }
    
    // Validate characters are different
    if (map->empty_char == map->obstacle_char || 
        map->empty_char == map->full_char || 
        map->obstacle_char == map->full_char) {
        free(map);
        return NULL;
    }
    
    // Allocate and read map lines
    map->map = malloc(sizeof(char*) * map->rows);
    
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int row = 0;
    
    while (row < map->rows && (read = getline(&line, &len, fp)) != -1) {
        // Remove newline
        if (read > 0 && line[read - 1] == '\n') {
            line[read - 1] = '\0';
            read--;
        }
        
        // Set column count from first row
        if (row == 0) {
            map->cols = read;
        }
        
        // Validate all rows have same length
        if (read != map->cols) {
            // Cleanup and return NULL
        }
        
        // Copy line to map
        map->map[row] = malloc(sizeof(char) * (map->cols + 1));
        strcpy(map->map[row], line);
        row++;
    }
    
    return map;
}
```

**Key Points:**
- `fscanf` reads the metadata line
- `getline` reads each map line (handles variable length)
- Validation happens during reading
- Early return on any error

### Finding the Biggest Square

```c
Square find_biggest_square(Map *map) {
    Square result = {0, 0, 0};
    
    // Create DP table
    int **dp = malloc(sizeof(int*) * map->rows);
    for (int i = 0; i < map->rows; i++) {
        dp[i] = calloc(map->cols, sizeof(int));
    }
    
    // Fill DP table
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            if (map->map[i][j] == map->obstacle_char) {
                dp[i][j] = 0;
            } else {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                }
                
                // Update result if bigger square found
                if (dp[i][j] > result.size) {
                    result.size = dp[i][j];
                    // Convert bottom-right to top-left
                    result.row = i - dp[i][j] + 1;
                    result.col = j - dp[i][j] + 1;
                }
                // Handle ties (prefer top-left)
                else if (dp[i][j] == result.size && result.size > 0) {
                    int new_row = i - dp[i][j] + 1;
                    int new_col = j - dp[i][j] + 1;
                    
                    if (new_row < result.row || 
                        (new_row == result.row && new_col < result.col)) {
                        result.row = new_row;
                        result.col = new_col;
                    }
                }
            }
        }
    }
    
    // Free DP table
    for (int i = 0; i < map->rows; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}
```

**Critical Details:**

1. **DP stores bottom-right positions**, but we need **top-left for result**
   ```c
   result.row = i - dp[i][j] + 1;  // Convert to top-left
   ```

2. **Tie-breaking**: When multiple squares have same size, choose:
   - Topmost (smallest row)
   - If same row, leftmost (smallest col)

3. **Memory management**: DP table is temporary, must be freed

### Filling the Square

```c
void fill_square(Map *map, Square square) {
    for (int i = square.row; i < square.row + square.size; i++) {
        for (int j = square.col; j < square.col + square.size; j++) {
            map->map[i][j] = map->full_char;
        }
    }
}
```

Simple nested loop to fill the square area.

---

## Validation Rules

### Valid Map Requirements

1. ✅ **All lines same length**
   ```c
   if (read != map->cols) return NULL;
   ```

2. ✅ **At least one line of at least one box**
   ```c
   if (map->rows <= 0 || map->cols <= 0) return NULL;
   ```

3. ✅ **Three characters must be different**
   ```c
   if (empty == obstacle || empty == full || obstacle == full)
       return NULL;
   ```

4. ✅ **Only valid characters in map**
   ```c
   if (c != empty_char && c != obstacle_char)
       return 0;
   ```

### Error Handling

```c
void process_map(FILE *fp) {
    Map *map = read_map(fp);
    
    if (!map || !validate_map(map)) {
        fprintf(stderr, "map error\n");
        if (map) free_map(map);
        return;
    }
    
    // Process valid map...
}
```

All errors print "map error" to **stderr**, not stdout.

---

## Complete Example Trace

### Input
```
5 . o x
.....
.....
..o..
.....
.....
```

### Step 1: Parse Metadata
- rows = 5
- empty_char = '.'
- obstacle_char = 'o'
- full_char = 'x'

### Step 2: Build DP Table

**Initial map:**
```
. . . . .
. . . . .
. . o . .
. . . . .
. . . . .
```

**DP Table construction (row by row):**

```
Row 0:
1 1 1 1 1

Row 1:
1 1 1 1 1
1 2 2 2 2

Row 2:
1 1 1 1 1
1 2 2 2 2
1 2 0 1 1

Row 3:
1 1 1 1 1
1 2 2 2 2
1 2 0 1 1
1 2 1 2 2

Row 4:
1 1 1 1 1
1 2 2 2 2
1 2 0 1 1
1 2 1 2 2
1 2 1 2 3
```

### Step 3: Find Largest Square

Largest value in DP table: **3** at position (4, 4) (bottom-right)
Convert to top-left: (4 - 3 + 1, 4 - 3 + 1) = **(2, 2)**

Wait, but there's an obstacle at (2, 2)!

Let me recalculate... Actually looking at the map:
- At position (2, 2) there's an obstacle 'o'
- So dp[2][2] = 0

The largest square of size 2 appears first at position (1, 1) (bottom-right)
Top-left would be: (1 - 2 + 1, 1 - 2 + 1) = **(0, 0)**

### Step 4: Fill Square

Fill 2x2 square starting at (0, 0):
```
x x . . .
x x . . .
. . o . .
. . . . .
. . . . .
```

---

## Time & Space Complexity

### Time Complexity: O(rows × cols)
- Single pass through map to build DP table
- Constant work per cell

### Space Complexity: O(rows × cols)
- DP table storage
- Original map storage

### Optimization Possibility
Could reduce space to O(cols) by only keeping previous row of DP table, but code clarity is preferred here.

---

## Edge Cases Handled

1. **Empty map** (no obstacles)
   - Entire map becomes the square

2. **Map full of obstacles**
   - Returns square of size 0 or 1

3. **Single row/column**
   - Finds largest horizontal/vertical line

4. **Multiple equal squares**
   - Chooses top-left priority

5. **Invalid maps**
   - Different line lengths
   - Invalid characters
   - Duplicate metadata characters
   - Wrong number of rows

---

## Common Pitfalls & Solutions

### Pitfall 1: Coordinate Confusion

**Problem:** DP stores bottom-right, but we need top-left

**Solution:**
```c
// DP[i][j] = size of square with bottom-right at (i, j)
// To get top-left:
top_left_row = i - size + 1;
top_left_col = j - size + 1;
```

### Pitfall 2: Tie-Breaking Logic

**Problem:** Multiple squares of same size

**Solution:** Compare systematically
```c
if (new_row < result.row || 
    (new_row == result.row && new_col < result.col)) {
    // New square is more top-left
}
```

### Pitfall 3: Memory Leaks

**Problem:** Many early returns with allocated memory

**Solution:** Careful cleanup on every error path
```c
if (error) {
    for (int i = 0; i < rows_allocated; i++) 
        free(map[i]);
    free(map);
    return NULL;
}
```

### Pitfall 4: getline() Buffer Management

**Problem:** `getline()` allocates memory that must be freed

**Solution:**
```c
char *line = NULL;
size_t len = 0;
while (getline(&line, &len, fp) != -1) {
    // Process line
}
free(line);  // Free at end, even if loop breaks
```

---

## Testing Strategy

### Sample Test Commands

```bash
# Basic test
./bsq example_file

# stdin test
cat example_file | ./bsq

# Multiple files
./bsq file1 file2 file3

# Error handling
./bsq invalid_map  # Should print "map error" to stderr
```

---

## Summary

**BSQ uses dynamic programming to efficiently find the largest square:**

1. Build DP table where `dp[i][j]` = size of largest square ending at `(i, j)`
2. Track the largest square found (with top-left priority for ties)
3. Fill that square in the original map
4. Output the result

**Key formula:**
```
dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
```

This elegant solution solves what would be an O(n³) brute force problem in just O(n²) time!