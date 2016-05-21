#ifndef GDT_H
#define GDT_H

#include "../types.h"

typedef struct _gdt_descriptor {
	u16 limit_low;		/* Bits 0-15  : Limit 0-15 */
	u16 base_low;		/* Bits 16-31 : Base 0-15  */
	u8 base_middle;		/* Bits 32-39 : Base 16-23 */
	u8 access;			/* Bits 40-47 : Access */
	u8 limit_high   : 4;	/* Bits 48-51 : Limit 16-19 */
	u8 flags       : 4; /* Bits 52-55 : Flags */
	u8 base_high;		/* Bits 56-63 : Base 24-31*/
} __attribute__((packed)) gdt_descriptor_t;

typedef struct _gdt_pointer {
	u16 limit;
	u32 base;
} __attribute__((packed)) gdt_pointer_t;

void gdt_initialize ();
void gdt_create_descriptor (u16 index, u32 base, u32 limit, u8 access, u16 flags);

#endif
