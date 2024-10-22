
#include "algoXOR.h"
#include <stddef.h>

// Fonction pour chiffrer ou déchiffrer un message avec XOR
void algoXOR(const unsigned char *message, const unsigned char *cle, unsigned char *output, size_t len) {
    size_t cle_len = 0;

    // Calculer la longueur de la clé
    while (cle[cle_len] != '\0') {
        cle_len++;
    }

    for (size_t i = 0; i < len; i++) {
        output[i] = message[i] ^ cle[i % cle_len];
    }
}
