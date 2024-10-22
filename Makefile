# Makefile

# Définition du compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c11 -g

# Les fichiers sources
SRCS = chiffrement/algoXOR.c chiffrement/tests_chiffrement.c

# Les fichiers objets correspondants
OBJS = $(SRCS:.c=.o)

# Le fichier exécutable final
TARGET = chiffrement/tests_chiffrement

# Règle par défaut (compilation complète)
all: $(TARGET)

# Règle pour la création de l'exécutable final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Règle pour compiler chaque fichier .c en fichier .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour exécuter les tests
test: $(TARGET)
	./$(TARGET)

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)

# Règle pour recompiler tout
rebuild: clean all

.PHONY: all test clean rebuild
