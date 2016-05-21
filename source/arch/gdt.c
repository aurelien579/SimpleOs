#include "gdt.h"

#define GDT_SIZE 8

static void gdt_install ();

static gdt_descriptor_t gdt[GDT_SIZE];
static gdt_pointer_t gdt_pointer;

void gdt_initialize ()
{
	gdt_pointer.limit = (sizeof (gdt_descriptor_t) * GDT_SIZE) - 1;
	gdt_pointer.base = (u32) gdt;

	gdt_create_descriptor (0, 0, 0, 0, 0);				/* Null descritptor        */
	gdt_create_descriptor (1, 0, 0xFFFF, 0x9B, 0x0D);	/* Kernel Code descriptor  */
	gdt_create_descriptor (2, 0, 0xFFFF, 0x93, 0x0D);	/* Kernel Data descriptor  */
	gdt_create_descriptor (3, 0, 0,   0x97, 0x0D);		/* Kernel Stack descriptor */

	gdt_create_descriptor (4, 0, 0xFFFF, 0xFF, 0x0D);	/* User Code descriptor    */
	gdt_create_descriptor (5, 0, 0xFFFF, 0xF3, 0x0D);	/* User Data descriptor    */
	gdt_create_descriptor (6, 0, 0,   0xF7, 0x0D);		/* User Stack descriptor   */

	gdt_install ();

    console_write_string ("[INFO] Gdt initialized\n");
}

void gdt_create_descriptor (u16 index, u32 base, u32 limit, u8 access, u16 flags)
{
    gdt[index].limit_low = (limit & 0xFFFF);
    gdt[index].limit_high = (limit & 0xF0000) >> 16;

    gdt[index].base_low = (base & 0xFFFF);
    gdt[index].base_middle = (base & 0xFF0000) >> 16;
    gdt[index].base_high = (base & 0xFF000000) >> 24;

    gdt[index].access = access;
    gdt[index].flags = (flags & 0xF);
}

static void gdt_install ()
{
	asm("lgdtl %0           \n \
         movw $0x10, %%ax 	\n \
         movw %%ax, %%ds    \n \
         movw %%ax, %%es    \n \
         movw %%ax, %%fs    \n \
         movw %%ax, %%gs    \n \
         ljmp $0x08, $test  \n \
         test:              \n"
         :: "m"(gdt_pointer)
        );
}
