COMPILER = cc
CFLAGS = -Iinclude -Wall -Wextra -Werror -g

EX_SRC = $(wildcard ../${proj}/${name}/*.c)
TEST_SRC = ${proj}/test_${name}.c

## cc: run code using cc compiler
cc:
	@echo "Running..."
	@echo "Exercise: ${name}"
	@${COMPILER} ${CFLAGS} ${EX_SRC} ${TEST_SRC}
	@./a.out

.PHONY: cc
