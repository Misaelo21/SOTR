CC = as

all: ejecutar

ejecutar: ejercicio1 ejercicio2 ejercicio3 ejercicio4 ejercicio5

ejercicio1: ejercicio1.s
	$(CC) --32  $< -o $@.o
	ld -m elf_i386 $@.o -o $@

ejercicio2: ejercicio2.s
	$(CC) --32  $< -o $@.o
	ld -m elf_i386 $@.o -o $@

ejercicio3: ejercicio3.s
	$(CC) --32  $< -o $@.o
	ld -m elf_i386 $@.o -o $@

ejercicio4: ejercicio4.s
	$(CC) --32  $< -o $@.o
	ld -m elf_i386 $@.o -o $@

ejercicio5: ejercicio5.s
	$(CC) --32  $< -o $@.o
	ld -m elf_i386 $@.o -o $@

clean:
	rm -vf ejercicio1
	rm -vf ejercicio2
	rm -vf ejercicio3
	rm -vf ejercicio4
	rm -vf ejercicio5
