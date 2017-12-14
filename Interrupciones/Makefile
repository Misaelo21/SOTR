CC = gcc

all: ejecutar

ejecutar: excepcion setjmp-1
    
excepcion: excepcion.c
	$(CC) $< -o $@

setjmp-1: setjmp-1.c
	$(CC) $< -o $@

run_python: 
	python excepcion.py
   
clean:
	rm -vf excepcion
	rm -vf setjmp-1
