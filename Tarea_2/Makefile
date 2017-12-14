CC = as

all: ejecutar

ejecutar: power

power: 
	$(CC) --32  power1.s -o power1.o
	$(CC) --32  power2.s -o power2.o
	ld -m elf_i386 power1.o power2.o -o $@
	./$@
	echo $?

clean:
	rm -vf power
