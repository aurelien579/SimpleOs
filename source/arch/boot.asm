MBALIGN     equ  1<<0                   ; align loaded modules on page boundaries
MEMINFO     equ  1<<1                   ; provide memory map
MFLAGS      equ  MBALIGN | MEMINFO      ; this is the Multiboot 'flag' field
MAGIC       equ  0x1BADB002             ; 'magic number' lets bootloader find the header
CHECKSUM    equ -(MAGIC + MFLAGS)       ; checksum of above, to prove we are multiboot

global loader
extern kernel_main

section .multiboot
align 4
multiboot_header:
	dd MAGIC
	dd MFLAGS
	dd CHECKSUM

section .text
loader:
    mov esp, stack_top
    push eax
    push ebx

    call kernel_main
    jmp $

STACKSIZE equ 0x4000

global switch_stack
switch_stack:
	mov ax, 0x18 		; Stack GDT segment
	mov	ss, ax

	pop eax				; Return address
	pop ebx				; New stack address
	pop ecx				; Old-return address

	mov esp, ebx
	push ecx
	push eax

	ret

section .bss

stack_bottom:
	resb STACKSIZE
stack_top:
