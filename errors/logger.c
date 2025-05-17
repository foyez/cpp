#include "error.h"

int log_fd = -1;

static void get_timestamp(char *buf, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buf, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

void set_log_file(const char *filename) {
    log_fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (log_fd == -1)
        perror("open log file");
}

void log_info(const char *fmt, ...) {
    char timestamp[32];
    get_timestamp(timestamp, sizeof(timestamp));

    va_list args;
    va_start(args, fmt);
    fprintf(stderr, LOG_INFO_TAG "[%s] ", timestamp);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    if (log_fd != -1) {
        dprintf(log_fd, "[INFO] [%s] ", timestamp);
        va_start(args, fmt);
        vdprintf(log_fd, fmt, args);
        dprintf(log_fd, "\n");
    }
    va_end(args);
}

void log_warn(const char *fmt, ...) {
    char timestamp[32];
    get_timestamp(timestamp, sizeof(timestamp));

    va_list args;
    va_start(args, fmt);
    fprintf(stderr, LOG_WARN_TAG "[%s] ", timestamp);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    if (log_fd != -1) {
        dprintf(log_fd, "[WARN] [%s] ", timestamp);
        va_start(args, fmt);
        vdprintf(log_fd, fmt, args);
        dprintf(log_fd, "\n");
    }
    va_end(args);
}

void log_error(const char *msg) {
    char timestamp[32];
    get_timestamp(timestamp, sizeof(timestamp));

    fprintf(stderr, LOG_ERROR_TAG "[%s] %s: %s\n", timestamp, msg, strerror(errno));

    if (log_fd != -1)
        dprintf(log_fd, "[ERROR] [%s] %s: %s\n", timestamp, msg, strerror(errno));
}

void close_log_file(void) {
    if (log_fd != -1) {
        close(log_fd);
        log_fd = -1;
    }
}
