#ifndef ERROR_H
# define ERROR_H

#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define RED     "\033[0;31m"
#define YELLOW  "\033[0;33m"
#define GREEN   "\033[0;32m"
#define CYAN    "\033[0;36m"
#define RESET   "\033[0m"

#define LOG_INFO_TAG   GREEN  "[INFO] " RESET
#define LOG_WARN_TAG   YELLOW "[WARN] " RESET
#define LOG_ERROR_TAG  RED    "[ERROR]" RESET
#define LOG_DEBUG_TAG  CYAN   "[DEBUG]" RESET

void set_log_file(const char *filename);
void log_info(const char *fmt, ...);
void log_warn(const char *fmt, ...);
void log_error(const char *msg);
void log_debug(const char *fmt, ...);
void close_log_file(void);

#endif
