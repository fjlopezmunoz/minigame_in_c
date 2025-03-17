# Compilador y flags
CC = gcc
CFLAGS = -std=c99 -Wall -pedantic `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lm

# Lista de ficheros fuente y objeto
SRCS = main.c Colisiones.c Ejercito.c Pantalla.c Rafaga.c
OBJS = $(SRCS:.c=.o)

# Nombre del ejecutable
TARGET = piedras_picudas

# Regla por defecto
all: $(TARGET)

# Enlaza los objetos para crear el ejecutable
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

# Regla genérica para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpia los ficheros objeto y el ejecutable
clean:
	rm -f $(OBJS) $(TARGET)
