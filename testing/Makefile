CC = cc
CFLAGS = -Wall -Wextra -Werror
CMOCKA_FLAGS = `pkg-config --cflags --libs cmocka`

SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

SRC_FILES = $(SRC_DIR)/ft_calloc.c $(SRC_DIR)/mylib.c
TEST_FILES = $(TEST_DIR)/testsuite.c

TARGET = $(BUILD_DIR)/test_runner

all: test

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(BUILD_DIR) $(SRC_FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) $(TEST_FILES) -o $(TARGET) $(CMOCKA_FLAGS) -Dmalloc=__wrap_malloc

test: $(TARGET)
	$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
