#ifndef IDT_H
#define IDT_H

#include "../types.h"

typedef struct
{
    u16 base_low;
    u16 selector;
    u8 always0;
    u8 flags;
    u16 base_high;
} __attribute__((packed)) idt_descsriptor_t;

typedef struct
{
    u16 limit;
    u32 base;
} __attribute__((packed)) idt_pointer_t;

static char *error_messages[] =
{
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

typedef void (*irq_handler_t)(registers_t*);

void idt_initialize ();
void irq_set_handler (u32 irq, irq_handler_t handler);
void irq_remove_handler (u32 irq);
void irq_initialize ();
void isr_initialize ();
#endif
