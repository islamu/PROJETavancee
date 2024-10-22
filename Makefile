# Définition du compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c11 -g

# Dossiers
SRCDIR = chiffrement
OBJDIR = build

# Les fichiers sources
SRC_XOR = $(SRCDIR)/algoXOR.c $(SRCDIR)/tests_chiffrement.c
SRC_CBC = $(SRCDIR)/algoCBC.c $(SRCDIR)/tests_chiffrementCBC.c

# Les fichiers objets correspondants
OBJ_XOR = $(SRC_XOR:.c=.o)
OBJ_CBC = $(SRC_CBC:.c=.o)

# Les fichiers exécutables
TARGET_XOR = chiffrement/tests_chiffrement
TARGET_CBC = chiffrement/tests_chiffrementCBC

# Règle par défaut pour générer les deux exécutables
all: $(TARGET_XOR) $(TARGET_CBC)

# Compilation pour XOR
$(TARGET_XOR): $(OBJ_XOR)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation pour CBC
$(TARGET_CBC): $(OBJ_CBC)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour compiler chaque fichier .c en fichier .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour tester XOR
test1: $(TARGET_XOR)
	./$(TARGET_XOR)

# Règle pour tester CBC
test2: $(TARGET_CBC)
	./$(TARGET_CBC)

# Règle pour nettoyer les fichiers objets et les exécutables
clean:
	rm -f $(OBJ_XOR) $(OBJ_CBC) $(TARGET_XOR) $(TARGET_CBC)
	rm -rf $(OBJDIR)

# Règle pour recompiler tout
rebuild: clean all

.PHONY: all test1 test2 clean rebuild
