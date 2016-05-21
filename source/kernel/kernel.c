#include "kernel.h"
#include "../arch/gdt.h"
#include "console.h"
#include "../arch/idt.h"

#define KERNEL_STACK_SIZE 	0X10000
#define KERNEL_STACK 		0x40000 + KERNEL_STACK_SIZE

extern void switch_stack (u32 stack_top); // Defined in boot.asm

static void kernel_initialize ()
{
	console_initialize ();
	gdt_initialize ();
	idt_initialize ();
	isr_initialize ();
	irq_initialize ();
}

static void kernel_run ()
{
	console_write_string ("Kernel \n");
}

static void kernel_exit ()
{
	for (;;);
}

void kernel_main ()
{
	kernel_initialize ();
	switch_stack (KERNEL_STACK);
	kernel_run ();
	kernel_exit ();
}
