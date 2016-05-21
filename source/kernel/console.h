#ifndef CONSOLE_H
#define CONSOLE_H

#include "../types.h"

typedef enum _console_color
{
	CONSOLE_COLOR_BLACK,
	CONSOLE_COLOR_BLUE,
	CONSOLE_COLOR_GREEN,
	CONSOLE_COLOR_CYAN,
	CONSOLE_COLOR_RED,
	CONSOLE_COLOR_MAGENTA,
	CONSOLE_COLOR_BROWN,
	CONSOLE_COLOR_LIGHT_GREY,
	CONSOLE_COLOR_DARK_GREY,
	CONSOLE_COLOR_LIGHT_BLUE,
	CONSOLE_COLOR_LIGHT_GREEN,
	CONSOLE_COLOR_LIGHT_CYAN,
	CONSOLE_COLOR_LIGHT_RED,
	CONSOLE_COLOR_LIGHT_MAGENTA,
	CONSOLE_COLOR_LIGHT_BROWN,
	CONSOLE_COLOR_WHITE,
} console_color_t;

typedef struct _console
{
	u32 x;
	u32 y;
	u16 *buffer;
	console_color_t color;
} console_t;

void console_initialize 	();
void console_write_char 	(const char c);
void console_write_string 	(const string_t str);
void console_clear 			();

#endif
