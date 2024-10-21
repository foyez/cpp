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

- For C: `gcc hello.c -o hello.out && ./hello.out`
- For C++: `g++ hello.c -o hello.out && ./hello.out`
