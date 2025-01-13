# Valgrind with Docker

You can use valgrind easily without installing it in your operating system with Docker. This is also useful for macOS because installing valgrind in macOS is tough.

To use valgrind with Docker, you have to follow these instructions:

## 1. Create a docker image using Dockerfile

Dockerfile

```Dockerfile
FROM alpine:latest

# Install dependencies
RUN apk update && apk add valgrind gcc g++ make
```

Now, run the build command to build the docker image in same directory where your Dockerfile is located.

```sh
docker build . -t valgrind:1.0
```

## 2. Running the Docker image

To run the image, navigate to your program directory and run this

```sh
docker run -it --rm -v $PWD:/valgrind -w /valgrind --name valgrind valgrind:1.0
```

- `docker run -it` — this will run your docker container interactively
- `--rm` — this will remove the container after it exits
- `-v $PWD:/valgrind` — this will mount your current directory to /valgrind inside the container
- `-w /valgrind` — this will set the containers working directory to /valgrind
- `valgrind:1.0` — this is the name and tag of the docker image we created

You can set this as alias in your bash or zsh shell following to `~/.bashrc` or `~/.zshrc`

```sh
alias valgrind='docker run -it --rm -v $PWD:/valgrind -w /valgrind --name valgrind valgrind:1.0'
```

Now you can test your program using only `valgrind` command.

## Example in C

For example, your program structure is

```
memory/
  memory_leaks.c
```

```c
#include <stdlib.h>

// memory leak: allocated memory is not freed
// heap buffer overflow: writing beyond allocated memory
int main(void)
{
  int *arr;

  arr = malloc(5 * sizeof(int));
  for (int i = 0; i <= 5; i++)
  {
    arr[i] = i;
  }

  return (0);
}
```

Run `valgrind` inside `memory/` directory

```sh
valgrind
```

compile the program

```
/valgrind # cc memory_leaks.c
```

Now use valgrind

```
/valgrind # valgrind --leak-check=full ./a.out
==12== Memcheck, a memory error detector
==12== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==12== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==12== Command: ./a.out
==12==
==12== Invalid write of size 4
==12==    at 0x108810: main (in /valgrind/memory/a.out)
==12==  Address 0x4915054 is 0 bytes after a block of size 20 alloc'd
==12==    at 0x48E9720: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-arm64-linux.so)
==12==    by 0x1087EF: main (in /valgrind/memory/a.out)
==12==
==12==
==12== HEAP SUMMARY:
==12==     in use at exit: 20 bytes in 1 blocks
==12==   total heap usage: 1 allocs, 0 frees, 20 bytes allocated
==12==
==12== LEAK SUMMARY:
==12==    definitely lost: 20 bytes in 1 blocks
==12==    indirectly lost: 0 bytes in 0 blocks
==12==      possibly lost: 0 bytes in 0 blocks
==12==    still reachable: 0 bytes in 0 blocks
==12==         suppressed: 0 bytes in 0 blocks
==12== Rerun with --leak-check=full to see details of leaked memory
==12==
==12== For lists of detected and suppressed errors, rerun with: -s
==12== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
