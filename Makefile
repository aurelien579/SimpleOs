CC=gcc
CCFLAGS=-ffreestanding -fbuiltin -Wall -Wextra -std=gnu11 -m32 -nostdlib
AS=nasm
ASFLAGS=-felf32

include source/arch/Makefile.cfg
include source/kernel/Makefile.cfg

OBJS:=\
	$(ARCH_OBJS) \
	$(KERN_OBJS)

all: iso

iso: build/kernel.bin
	mkdir -p build/isodir
	mkdir -p build/isodir/boot
	mkdir -p build/isodir/boot/grub

	cp build/kernel.bin build/isodir/
	cp config/menu.lst build/isodir/boot/grub/
	cp dependencies/efi.img build/isodir/
	cp dependencies/stage2_eltorito build/isodir/boot

	genisoimage -R -b boot/stage2_eltorito  -no-emul-boot -boot-load-size 4 -boot-info-table -o build/myos.iso build/isodir


build/kernel.bin: $(OBJS)
	$(CC) -T source/arch/linker.ld -o $@ $(CCFLAGS) $(OBJS)

%.o: %.c
	@echo ========== $< ==========
	$(CC) -c $< -o $@ $(CCFLAGS)

%.o: %.asm
	@echo ========== $< ==========
	$(AS) $< -o $@ $(ASFLAGS)

clean:
	rm $(OBJS) build/kernel.bin
	rm build/isodir/* -r
	rm myos.iso

qemu: all
	qemu-system-i386 -cdrom build/myos.iso -monitor stdio
	
bochs: all
	bochs -f config/bochs.cfg -q
