#include "log.h"

void println (const string_t msg)
{
    print (msg);
    print ("\n");
}

void print (const string_t msg)
{
    console_write_string (msg);
}

void log_debug (const string_t msg)
{
    log ("DEBUG", msg);
}

void log (const string_t prefix, const string_t msg)
{
    print ("[");
    print (prefix);
    print ("] ");
    println (msg);
}

void log_info (const string_t msg)
{
    log ("INFO", msg);
}

void log_error (const string_t msg)
{
    log ("ERROR", msg);
}
