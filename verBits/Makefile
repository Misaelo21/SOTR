CC = gcc

all: ejecutar

ejecutar: campos main_float main_int

campos: campos.c
	$(CC) $< -o $@

main_int: main_int.c
	$(CC) $< -o $@

main_float: main_float.c
	$(CC) $< -o $@

clean:
	rm -vf campos
	rm -vf main_int
	rm -vf main_float
