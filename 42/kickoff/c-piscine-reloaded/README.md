# C Piscine Reloaded

- Permissions types

| Number | Permission Type                | Symbol |
| ------ | ------------------------------ | ------ |
| 0      | No Permission                  | ---    |
| 1      | Execute                        | --x    |
| 2      | Write                          | -w-    |
| 3      | Execute + Write (1+2)          | -wx    |
| 4      | Read                           | r--    |
| 5      | Read + Execute (4+1)           | r-x    |
| 6      | Read + Write (4+2)             | rw-    |
| 7      | Read + Write + Execute (4+2+1) | rwx    |

- Create file with specific size:

```sh
# can't directly resize a file
# to make a file of size 4 bytes
truncate -s 4 filename

# to create a file of specific size
dd if=/dev/zero of=filename bs=1 count=4

# allocate space but without actually writing
fallocate -l 4 filename
```

- Change Permissions:

```sh
chmod 751 filename

# symlink
chmod -h 751 filename
```

- Change ownership:

```sh
chown owner:group filename
```

- Change file timestamp

```sh
# June 1, 2023, at 20:47:00
touch -t 202306012047.00 test0

# symlink
touch -ht 202306012047.00 test6
```

- To create a new symlink

```sh
ln -sf /path/target_file /path/symlink
```

- To compress files to a tar file

```sh
tar -cf ex00.tar *
```

- To echo content to a file

```sh
# adding a newline at the end
echo "hello" > filename.txt

# adding without a newline at the end
echo -n "hello" > filename.txt
```

- Find and delete the files

```sh
find . -type f \( -name '*~' -o -name '#*#' \) -exec rm -v {} \+

# find . - searches from the current directory (.) and below
# -type -f - limits the search to files only
# \( -name '*~' -o -name '#*#' \) - matches files whose name ends with ~ or starts and ends with #
# "-exec rm -v {} \+" - for each files found, rm -v is used to remove files with verbose output (-v shows what files are being deleted).
# {} is replace by the file path that match.
# The \+ makes the command efficient by passing multiple files to rm in a single invocation, rather than invoking rm separately for each file.

# \ vs \;
# for "\;" - find runs the command (rm) once for each file
# for "\+" - find groups the results and runs the command with multiple files at once, making it more efficient.
```

- Find and print the files

```sh
# find and print full path
find . -type f -name '*.sh' -print

# find and print filename with ext
find . -type f -name '*.sh' -exec basename {} \;

# find and print filename without ext
find . -type f -name "*.sh" -exec basename {} .sh \;
# "-exec basename {} .sh \;" - for each file found, basename is used to remove the directory path and the .sh extension.
```

- script file

```sh
#!/bin/bash

find . -type f -name '*.sh' -exec basename {} \;
```

run:

```sh
./find_sh.sh | cat -e
```

- print mac addresses

```sh
ifconfig | awk '/ether /{print $2}'
# $2 - print the second field of the line
```

- Run c program

```sh
cc -Wall -Wextra -Werror -fsanitize=address -g filename.c && ./a.out
```

- MAC setup

```sh
# install homebrew
cd ~
mkdir homebrew && curl -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C homebrew

# to add Homebrew to your PATH
(echo; echo 'eval "$($HOME/homebrew/bin/brew shellenv)"') >> $HOME/.zprofile
eval "$($HOME/homebrew/bin/brew shellenv)"

# install pipx
brew install pipx

# norminette
pipx install norminette
pipx ensurepath

# c formatter 42
pipx install c_formatter_42
c_formatter_42 file1.c file2.c # to format
c_formatter_42 -h # to get details

# Install oh my zsh
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

# Update everything (e.g. plugins)
omz update
```

- .zshrc

```sh
# custom function for compiling C code
mycc() {
  # If no arguments are passed, display an error
  if [ "$#" -eq 0 ]; then
    echo "Usage: mycc <file(s)> [<args for a.out>]"
    return 1
  fi

  cc -Wall -Wextra -Werror -fsanitize=address -g "$@" && ./a.out
}

# format c files for 42
cf() {
    c_formatter_42 "$@"
}

# aliases
alias cls="clear"
alias valgrind='docker run -it --rm -v $PWD:/valgrind -w /valgrind --name valgrind valgrind:1.0'
```
