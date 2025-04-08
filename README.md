# C/C++

## Setup VS Code for c and c++ <sup>[ref](https://takeuforward.org/set-up/how-to-set-up-visual-studio-code-for-c-cp-and-dsa/)</sup>

[How to Write And Run C and C++ Code in Visual Studio Code](https://www.freecodecamp.org/news/how-to-write-and-run-c-cpp-code-on-visual-studio-code/)

1. Install `C/C++ Extension Pack`
2. Configure to Run Code: `Terminal > Configure Tasks > Create tasks.json file from template > Others`
3. Paste the code in tasks.json

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "compile",
      "type": "shell",
      "command": "g++",
      "args": [
        "-std=c++17",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}",
        "${file}"
      ],
      "group": {
        "kind": "build",
        "isDefault": false
      },
      "problemMatcher": ["$gcc"],
      "presentation": {
        "reveal": "always",
        "panel": "shared"
      },
      "runOptions": {
        "runOn": "folderOpen"
      }
    },
    {
      "label": "compile and run",
      "type": "shell",
      "command": "g++",
      "args": [
        "-std=c++17",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}",
        "${file}",
        "&&",
        "${fileDirname}/${fileBasenameNoExtension}",
        "<",
        "input.txt",
        ">",
        "output.txt"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["$gcc"],
      "presentation": {
        "reveal": "always",
        "panel": "shared"
      },
      "runOptions": {
        "runOn": "folderOpen"
      }
    }
  ]
}
```

4. Fix `bits/stdc++.h` issue

```sh
# to get c++ compiler paths
echo | g++ -v -x c++ -E -

# Navigate to: /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
# create: "bits" directory
# then add: "stdc++.h" file
# paste from: https://gist.github.com/Einstrasse/ac0fe7d7450621a39364ed3b05cacd11
```

5. Run code: `Cmd + Shift + b`

## Compile and run C/C++ in terminal

```sh
# For C:
# gcc: Invokes the GNU Compiler
# -Wall: Enables most of the common compiler warnings
# -Wextra: Activates additional warning flags
# -Werror: Treats all warnings as errors
# -fsanitize=address: Enables AddressSanitizer, a tool for detecting memory issues like buffer overflows, use-after-free, etc.
# -g: Includes debugging information
# hello.c: The input source code file to be compiled
# -o hello.out: Specifies the name of the output executable file
# &&: Ensures that the executable is run only if the compilation is successful
gcc -Wall -Wextra -Werror -fsanitize=address -g hello.c -o hello.out && ./hello.out

# For C++:
g++ hello.c -o hello.out && ./hello.out
```

## LLDB Debugger <sup>[ref](https://www.youtube.com/watch?v=v_C1cvo1biI)</sup>

- Official site: <https://lldb.llvm.org/use/map.html>

```sh
# to compile with -g flag
cc -g hello.c

# to run
lldb ./a.out

# to create a debugging target
target create ./a.out

# lldb commands
# help
# b - set a breakpoint
# set a breakpoint in the current file
b 7
# set a breakpoint at a specific line
b hello.c:7
# set a breakpoint by function name
b main
# to view all breakpoints
br l
# deleting breakpoints
br del <breakpoint_number>
# run - launch the executable in the debugger
run arg1 arg2
# run in graphical interface
gui
# esc - to exit from gui
# n - stepping over calls
# s - stepping into calls
# continue execution until the next breakpoint
continue
# quit
q
```

## Valgrind <sup>[How to run Valgrind](https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks)</sup>

```sh
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=valgrind-log.txt \
         -s \
         ./executable param1
```

- `--leak-check=full`: Perform a detailed memory leak check.
- `--show-leak-kinds=all`: Show all kinds of leaks, including definitely lost, indirectly lost, possibly lost, and still reachable.
- `--track-origins=yes`: Track the origins of uninitialized values.
- `-s`: Provide a summary of the leak check.
- `--log-file`: Directs Valgrind's output to a specified file. This is useful for preserving extensive output that exceeds terminal capacity, allowing for easier review and analysis.

## Data Types

- bool - 1 byte or 8 bits
- int - 4 byte or 32 bits (4 billion possible values, e.g. 4x10^9, -2x10^9 to 2x10^9)
- long - 8 bytes or 64 bits
- float - 4 bytes or 32 bits
- double - 8 bytes or 64 bits
- char - 1 byte or 8 bits
- string - ? bytes

## Time & Space Complexity

**Worst Case (O - Big O):**

- O(n^2)
- O(n log n)
- O(n) - linear search
- O(log n) - binary search
- O(1)

**Best Case (Ω - Omega):**

- Ω(n^2)
- Ω(n log n)
- Ω(n)
- Ω(log n)
- Ω(1) - linear search, binary search

**Worst and Best Case are Same (Θ - Greek Theta):**

- Θ(n^2)
- Θ(n log n)
- Θ(n)
- Θ(log n)
- Θ(1)
