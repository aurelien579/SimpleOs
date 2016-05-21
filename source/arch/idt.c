#include "idt.h"
#include "system.h"

#define IDT_SIZE 256

#define PIC1			0x20		/* IO base address for master PIC */
#define PIC2			0xA0		/* IO base address for slave PIC */
#define PIC1_COMMAND	PIC1
#define PIC1_DATA		(PIC1+1)
#define PIC2_COMMAND	PIC2
#define PIC2_DATA		(PIC2+1)
#define PIC_EOI			0x20		/* End-of-interrupt command code */
#define ICW1_ICW4		0x01		/* ICW4 (not) needed */
#define ICW1_SINGLE		0x02		/* Single (cascade) mode */
#define ICW1_INTERVAL4	0x04		/* Call address interval 4 (8) */
#define ICW1_LEVEL		0x08		/* Level triggered (edge) mode */
#define ICW1_INIT		0x10		/* Initialization - required! */

#define ICW4_8086		0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO		0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM		0x10		/* Special fully nested (not) */

#define OFFSET1 		0x20
#define OFFSET2 		0x28

/* Defined in isr_asm.asm */
extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

static void idt_create_descriptor (u16 num, u32 base, u16 selector, u8 flags);
static irq_handler_t irq_handlers[16];
static idt_descsriptor_t idt[IDT_SIZE];
static idt_pointer_t idt_pointer;

void idt_initialize ()
{
    idt_pointer.limit = (sizeof (idt_descsriptor_t) * IDT_SIZE) - 1;
    idt_pointer.base = (u32) idt;

    asm ("lidt (idt_pointer)");
    log_info ("Idt initialized");
}

static void idt_create_descriptor (u16 num, u32 base, u16 selector, u8 flags)
{
    idt[num].base_low = base & 0xFFFF;
    idt[num].base_high = (base >> 16) & 0xFFFF;

    idt[num].selector = selector;
    idt[num].always0 = 0;
    idt[num].flags = flags;
}

void irq_set_handler (u32 irq, irq_handler_t handler)
{
    irq_handlers[irq] = handler;
}

void irq_remove_handler (u32 irq)
{
    irq_handlers[irq] = 0;
}

void isr_initialize ()
{
    idt_create_descriptor (0, (u32)isr0, 0x08, 0x8E);
    idt_create_descriptor (1, (u32)isr1, 0x08, 0x8E);
    idt_create_descriptor (2, (u32)isr2, 0x08, 0x8E);
    idt_create_descriptor (3, (u32)isr3, 0x08, 0x8E);
    idt_create_descriptor (4, (u32)isr4, 0x08, 0x8E);
    idt_create_descriptor (5, (u32)isr5, 0x08, 0x8E);
    idt_create_descriptor (6, (u32)isr6, 0x08, 0x8E);
    idt_create_descriptor (7, (u32)isr7, 0x08, 0x8E);

    idt_create_descriptor (8, (u32)isr8, 0x08, 0x8E);
    idt_create_descriptor (9, (u32)isr9, 0x08, 0x8E);
    idt_create_descriptor (10, (u32)isr10, 0x08, 0x8E);
    idt_create_descriptor (11, (u32)isr11, 0x08, 0x8E);
    idt_create_descriptor (12, (u32)isr12, 0x08, 0x8E);
    idt_create_descriptor (13, (u32)isr13, 0x08, 0x8E);
    idt_create_descriptor (14, (u32)isr14, 0x08, 0x8E);
    idt_create_descriptor (15, (u32)isr15, 0x08, 0x8E);

    idt_create_descriptor (16, (u32)isr16, 0x08, 0x8E);
    idt_create_descriptor (17, (u32)isr17, 0x08, 0x8E);
    idt_create_descriptor (18, (u32)isr18, 0x08, 0x8E);
    idt_create_descriptor (19, (u32)isr19, 0x08, 0x8E);
    idt_create_descriptor (20, (u32)isr20, 0x08, 0x8E);
    idt_create_descriptor (21, (u32)isr21, 0x08, 0x8E);
    idt_create_descriptor (22, (u32)isr22, 0x08, 0x8E);
    idt_create_descriptor (23, (u32)isr23, 0x08, 0x8E);

    idt_create_descriptor (24, (u32)isr24, 0x08, 0x8E);
    idt_create_descriptor (25, (u32)isr25, 0x08, 0x8E);
    idt_create_descriptor (26, (u32)isr26, 0x08, 0x8E);
    idt_create_descriptor (27, (u32)isr27, 0x08, 0x8E);
    idt_create_descriptor (28, (u32)isr28, 0x08, 0x8E);
    idt_create_descriptor (29, (u32)isr29, 0x08, 0x8E);
    idt_create_descriptor (30, (u32)isr30, 0x08, 0x8E);
    idt_create_descriptor (31, (u32)isr31, 0x08, 0x8E);

    log_info ("Isr initialized");
}

void irq_initialize ()
{
    u8 a = inb (PIC1_DATA);
    u8 b = inb (PIC2_DATA);

    outb (PIC1_COMMAND, ICW1_INIT + ICW1_ICW4);
    outb (PIC2_COMMAND, ICW1_INIT + ICW1_ICW4);
    outb (PIC1_DATA, OFFSET1);
    outb (PIC2_DATA, OFFSET2);
    outb (PIC1_DATA, 0x04);
    outb (PIC2_DATA, 0x02);
    outb (PIC1_DATA, ICW4_8086);
    outb (PIC2_DATA, ICW4_8086);
    outb (PIC1_DATA, a);
    outb (PIC2_DATA, b);

    idt_create_descriptor (32, (u32)irq0, 0x08, 0x8E);
    idt_create_descriptor (33, (u32)irq1, 0x08, 0x8E);
    idt_create_descriptor (34, (u32)irq2, 0x08, 0x8E);
    idt_create_descriptor (35, (u32)irq3, 0x08, 0x8E);
    idt_create_descriptor (36, (u32)irq4, 0x08, 0x8E);
    idt_create_descriptor (37, (u32)irq5, 0x08, 0x8E);
    idt_create_descriptor (38, (u32)irq6, 0x08, 0x8E);
    idt_create_descriptor (39, (u32)irq7, 0x08, 0x8E);
    idt_create_descriptor (40, (u32)irq8, 0x08, 0x8E);
    idt_create_descriptor (41, (u32)irq9, 0x08, 0x8E);
    idt_create_descriptor (42, (u32)irq10, 0x08, 0x8E);
    idt_create_descriptor (43, (u32)irq11, 0x08, 0x8E);
    idt_create_descriptor (44, (u32)irq12, 0x08, 0x8E);
    idt_create_descriptor (45, (u32)irq13, 0x08, 0x8E);
    idt_create_descriptor (46, (u32)irq14, 0x08, 0x8E);
    idt_create_descriptor (47, (u32)irq15, 0x08, 0x8E);

    asm volatile ("sti");

    log_info ("Irq initialized");
}

void isr_clock_int ()
{
    static u32 ticks;
    ticks++;
}

void irq_common_handler (registers_t* regs)
{
    irq_handler_t handler = irq_handlers[regs->int_no - 32];
    if (handler)
    {
        handler (regs);
    }

    if (regs->int_no >= 40)
    {
        outb (0xA0, 0x20);
    }

    outb (0x20, 0x20);
}

void fault_handler (registers_t* regs)
{
    if (regs->int_no < 32)
    {
        log_error (error_messages[regs->int_no]);
        for (;;) {
            asm("hlt");
        }
    }
}
