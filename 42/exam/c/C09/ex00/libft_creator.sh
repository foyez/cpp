#!/bin/sh

rm -f libft.a
find . -name "*.c" -type f -exec cc -Wall -Wextra -Werror -c {} \;
ar rcs libft.a *.o
find . -name "*.o" -type f -delete

# list the object files: ar t libft.a
# https://makori-mildred.medium.com/how-to-create-static-library-in-c-and-how-to-use-it-b8b3e1fde999
