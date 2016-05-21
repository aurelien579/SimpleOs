#ifndef UTILS_H
#define UTILS_H

#include "../types.h"

void memcpy (const u32 *src, u32 *dest, u32 size);
u32 strlen (const char *string);
void memset (u32 *src, u32 value, u32 count);

#endif