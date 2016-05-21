#include "console.h"
#include "kernel.h"

#include "utils.h"

#define CONSOLE_DEFAULT_COLOR 	CONSOLE_COLOR_WHITE
#define CONSOLE_MEMORY 			0xB8000

#define CONSOLE_WIDTH 	80
#define CONSOLE_HEIGHT 	25

static void console_scroll 				();
static u32  console_get_current_index 	();
static void console_put_char 			(const char c);
static void console_write_new_line 		();

static console_t console;

void console_initialize ()
{
	console.x = 0;
	console.y = 0;
	console.color = CONSOLE_DEFAULT_COLOR;

	console.buffer = (u16*) CONSOLE_MEMORY;

	console_clear ();

	log_info ("Console initialized");
}

void console_write_char (const char c)
{
	switch (c)
	{
		case '\n':
			console_write_new_line ();
			break;
		case '\t':
			console.x = console.x + 4;
			break;
		default:
			console_put_char (c);
			break;
	}
}

void console_write_string (const string_t str)
{
	for (u32 i = 0; i < strlen(str); i++)
		console_write_char (str[i]);
}

void console_clear ()
{
	memset ((u32*) CONSOLE_MEMORY, 0, CONSOLE_HEIGHT * CONSOLE_WIDTH * 8);
}

static void console_write_new_line ()
{
	if (++console.y == CONSOLE_HEIGHT)
		console_scroll ();
	console.x = 0;
}

static void console_put_char (const char c)
{
	u32 index = console_get_current_index ();
	console.buffer[index] = c | console.color << 8;
	if (++console.x == CONSOLE_WIDTH)
		console_write_new_line ();
}

static void console_scroll ()
{
	memcpy (console.buffer,
			&console.buffer[CONSOLE_WIDTH],
			CONSOLE_WIDTH * CONSOLE_WIDTH * CONSOLE_HEIGHT);
}

static u32 console_get_current_index ()
{
	return console.y * CONSOLE_WIDTH + console.x;
}
