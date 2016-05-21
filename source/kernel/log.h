#ifndef LOG_H
#define LOG_H

#include "../types.h"

void println    (const string_t msg);
void print      (const string_t msg);
void log_debug  (const string_t msg);
void log        (const string_t prefix, const string_t msg);
void log_info   (const string_t msg);
void log_error  (const string_t msg);


#endif
