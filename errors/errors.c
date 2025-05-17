#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define RESET   "\033[0m"

# define LOG_INFO_TAG   GREEN  "[INFO] " RESET
# define LOG_WARN_TAG   YELLOW "[WARN] " RESET
# define LOG_ERROR_TAG  RED    "[ERROR]" RESET

FILE *log_file = NULL; // Optional: write logs to file too
void set_log_file(const char *filename) {
    log_file = fopen(filename, "a");
    if (!log_file)
        perror("fopen log file");
}

// int log_fd = -1; // file descriptor for log file
// void set_log_file(const char *filename) {
//     log_fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
//     if (log_fd == -1)
//         perror("open log file");
// }

void log_info(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, LOG_INFO_TAG);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    if (log_file) {
        fprintf(log_file, "[INFO] ");
        vfprintf(log_file, fmt, args);
        fprintf(log_file, "\n");
        fflush(log_file);
    }
    va_end(args);
}

void log_warn(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, LOG_WARN_TAG);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    if (log_file) {
        fprintf(log_file, "[WARN] ");
        vfprintf(log_file, fmt, args);
        fprintf(log_file, "\n");
        fflush(log_file);
    }
    va_end(args);
}

void log_error(const char *msg) {
    fprintf(stderr, LOG_ERROR_TAG " %s: %s\n", msg, strerror(errno));
    if (log_file) {
        fprintf(log_file, "[ERROR] %s: %s\n", msg, strerror(errno));
        fflush(log_file);
    }
}

// Sometimes you want errors written to a file instead of the terminal.
void redirect_stderr_to_log() {
    int err_fd = open("error.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (err_fd == -1)
        return;

    dup2(err_fd, 2); // Now fprintf(stderr, ...) goes to error.log
}

// Quick debug/error message	perror("read")
// Custom message + system error	fprintf(stderr, "...: %s", strerror(errno))
// Full custom logging	fprintf(stderr, "Something went wrong\n")
int main(void)
{
	int fd = open("nofile.txt", O_RDONLY);
	if (fd == -1) {
		perror("open"); // Method 1
		fprintf(stderr, "open failed: %s\n", strerror(errno)); // Method 2
		fprintf(stderr, "open: could not open input file.\n"); // Method 3
	}

	redirect_stderr_to_log();
	FILE *fp = fopen("nofile.txt", "r");
    if (!fp)
        fprintf(stderr, "fopen failed: %s\n", strerror(errno)); // goes to error.log

	// logfile
	set_log_file("log.txt"); // optional
    log_info("Starting program with PID = %d", getpid());
    FILE *fp = fopen("nofile.txt", "r");
    if (!fp)
        log_error("fopen");
    log_warn("This is just a warning, nothing fatal.");
    log_info("Program finished cleanly.");
    if (log_file)
        fclose(log_file);

	return (0);
}
