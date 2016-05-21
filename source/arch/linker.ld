ENTRY(loader)
OUTPUT_FORMAT(elf32-i386)

SECTIONS {
    . = 0x00100000;

    .multiboot : {
        *(.multiboot)
    }

    .text : {
        *(.text)
        *(.rodata*)
    }

    .data ALIGN (0x1000) : {
        *(.data)
    }

    .bss : {
		_sbss = .;
		*(COMMON)
		*(.bss)
		_ebss = .;
    }
}
