# Memory

# Check Memory Leaks

- Valgrind

```sh
# in mac
brew install valgrind

# manual
./configure --prefix=/usr/local
make
sudo make install
```

- AddressSanitizer

```sh
cc -fSanitize=address -g file.c && ./a.out

# to enable memory leak
cc -fSanitize=address -g file.c
ASAN_OPTIONS=detect_leaks=1 ./a.out # or, export ASAN_OPTIONS=detect_leaks=1
```
