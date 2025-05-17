#include "error.h"

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

	// redirect_stderr_to_log();
	// FILE *fp = fopen("nofile.txt", "r");
    // if (!fp)
    //     fprintf(stderr, "fopen failed: %s\n", strerror(errno)); // goes to error.log

	// logfile
	set_log_file("log.txt");
    log_info("App started with PID %d", getpid());
    fd = open("nofile.txt", O_RDONLY);
    if (fd == -1)
        log_error("open");
    log_warn("This is just a test warning.");
    log_info("Shutting down cleanly.");
    log_debug("Value of fd: %d", fd);
    close_log_file();

	return (0);
}
