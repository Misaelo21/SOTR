CC = as

all: ejecutar

ejecutar: pila

pila: pila.s
	$(CC) --32 $< -o $@.o
	objdump -D $@.o
	ld -melf_i386 $@.o -o $@
	./pila
	echo $?

clean:
	rm -vf pila
