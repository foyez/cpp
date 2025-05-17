#include "error.h"

int log_fd = -1;

static void get_timestamp(char *buf, size_t size) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    struct tm *tm_info = localtime(&tv.tv_sec);
    strftime(buf, size, "%Y-%m-%d %H:%M:%S", tm_info);
    size_t len = strlen(buf);
    snprintf(buf + len, size - len, ".%03d", tv.tv_usec / 1000);
}

void set_log_file(const char *filename) {
    log_fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (log_fd == -1)
        perror("open log file");
}

void log_info(const char *fmt, ...) {
    char timestamp[64];
    get_timestamp(timestamp, sizeof(timestamp));

    va_list args;
    va_start(args, fmt);
    fprintf(stderr, LOG_INFO_TAG "[%s][PID:%d] ", timestamp, getpid());
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    if (log_fd != -1) {
        dprintf(log_fd, "[INFO] [%s][PID:%d] ", timestamp, getpid());
        va_start(args, fmt);
        vdprintf(log_fd, fmt, args);
        dprintf(log_fd, "\n");
    }
    va_end(args);
}

void log_warn(const char *fmt, ...) {
    char timestamp[64];
    get_timestamp(timestamp, sizeof(timestamp));

    va_list args;
    va_start(args, fmt);
    fprintf(stderr, LOG_WARN_TAG "[%s][PID:%d] ", timestamp, getpid());
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    if (log_fd != -1) {
        dprintf(log_fd, "[WARN] [%s][PID:%d] ", timestamp, getpid());
        va_start(args, fmt);
        vdprintf(log_fd, fmt, args);
        dprintf(log_fd, "\n");
    }
    va_end(args);
}

void log_error(const char *msg) {
    char timestamp[64];
    get_timestamp(timestamp, sizeof(timestamp));

    fprintf(stderr, LOG_ERROR_TAG "[%s][PID:%d] %s: %s\n", timestamp, getpid(), msg, strerror(errno));

    if (log_fd != -1)
        dprintf(log_fd, "[ERROR] [%s][PID:%d] %s: %s\n", timestamp, getpid(), msg, strerror(errno));
}

void log_debug(const char *fmt, ...) {
    char timestamp[64];
    get_timestamp(timestamp, sizeof(timestamp));

    va_list args;
    va_start(args, fmt);
    fprintf(stderr, LOG_DEBUG_TAG "[%s][PID:%d] ", timestamp, getpid());
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    if (log_fd != -1) {
        dprintf(log_fd, "[DEBUG] [%s][PID:%d] ", timestamp, getpid());
        va_start(args, fmt);
        vdprintf(log_fd, fmt, args);
        dprintf(log_fd, "\n");
    }
    va_end(args);
}

void close_log_file(void) {
    if (log_fd != -1) {
        close(log_fd);
        log_fd = -1;
    }
}
