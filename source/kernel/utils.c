#include "utils.h"

void memcpy (const u32 *src, u32 *dest, u32 size)
{
	for (u32 i = 0; i < size; i++)
	{
		dest[i] = src[i];
	}
}

void memset (u32 *src, u32 value, u32 count)
{
	for (u32 i = 0; i < count; i++)
		src[i] = value;
}

u32 strlen (const char *str)
{
    const char *s;
    for (s = str; *s; ++s);
    return (s - str);
}