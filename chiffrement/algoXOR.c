
#include "algoXOR.h"
#include <stddef.h>
// Fonction pour chiffrer ou déchiffrer un message avec XOR
void algoXOR(const unsigned char *message, const unsigned char *key, unsigned char *output, size_t len) {
    size_t key_len = 0;

    // Calculer la longueur de la clé
    while (key[key_len] != '\0') {
        key_len++;
    }

    for (size_t i = 0; i < len; i++) {
        output[i] = message[i] ^ key[i % key_len];
    }
}
