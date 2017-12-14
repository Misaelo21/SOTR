CC = gcc

all: ejecutar

ejecutar: semaforos varCompartida dekker peterson

semaforos: semaforos.c
	$(CC) $< -o $@

varCompartida: varCompartida.c
	$(CC) $< -o $@

dekker: varCompartida_dekker.c
	$(CC) $< -o $@

peterson: varCompartida_peterson.c
	$(CC) $< -o $@

clean:
	rm -vf semaforos
	rm -vf varCompartida
	rm -vf dekker
	rm -vf peterson

