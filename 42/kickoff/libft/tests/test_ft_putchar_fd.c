#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "stdlib.h"

/**
 * Helper function to capture output from a file descriptor.
 */
static char *capture_fd_output(int fd, void (*func)(char, int), char input) {
    int pipe_fds[2];
    char *buffer = (char *)malloc(2); // 1 char + null terminator

    if (!buffer)
        return NULL;

    if (pipe(pipe_fds) == -1) {
        free(buffer);
        return NULL;
    }

    int saved_fd = dup(fd); // Save original fd
    dup2(pipe_fds[1], fd);  // Redirect fd to pipe
    close(pipe_fds[1]);

    func(input, fd); // Call ft_putchar_fd

    read(pipe_fds[0], buffer, 1);
    buffer[1] = '\0';

    dup2(saved_fd, fd); // Restore original fd
    close(saved_fd);
    close(pipe_fds[0]);

    return buffer;
}

/**
 * Test writing to stdout.
 */
static void test_putchar_stdout(void **state) {
    (void) state;
    char *output = capture_fd_output(1, ft_putchar_fd, 'A');
    assert_non_null(output);
    assert_string_equal(output, "A");
    free(output);
}

/**
 * Test writing to stderr.
 */
static void test_putchar_stderr(void **state) {
    (void) state;
    char *output = capture_fd_output(2, ft_putchar_fd, 'E');
    assert_non_null(output);
    assert_string_equal(output, "E");
    free(output);
}

/**
 * Test writing to a file.
 */
static void test_putchar_file(void **state) {
    (void) state;
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    assert_true(fd >= 0);

    ft_putchar_fd('F', fd);
    close(fd);

    // Read the file and check contents
    char buffer[2] = {0};
    fd = open("test_output.txt", O_RDONLY);
    assert_true(fd >= 0);
    read(fd, buffer, 1);
    close(fd);

    assert_string_equal(buffer, "F");
}

/**
 * Test invalid file descriptor.
 */
static void test_putchar_invalid_fd(void **state) {
    (void) state;
    // Pass an invalid fd (-1), this should not crash
    ft_putchar_fd('X', -1);
}

