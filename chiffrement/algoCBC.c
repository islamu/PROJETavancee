// algoCBC.c

#include "algoCBC.h"
#include <string.h>

// Fonction XOR pour deux blocs
static void xor_blocs(const unsigned char *bloc1, const unsigned char *bloc2, unsigned char *res, size_t taille_bloc) {
    for (size_t i = 0; i < taille_bloc; i++) {
        res[i] = bloc1[i] ^ bloc2[i];
    }
}

// Chiffrement CBC
void cbc_crypt(const unsigned char *message, const unsigned char *cle, const unsigned char *iv, unsigned char *res, size_t len) {
    size_t taille_bloc = 16; // Taille des blocs (par exemple, 16 octets)
    unsigned char bloc[taille_bloc];
    unsigned char bloc_avant[taille_bloc];

    // Copie du vecteur d'initialisation (iv) dans le bloc précédent
    memcpy(bloc_avant, iv, taille_bloc);

    for (size_t i = 0; i < len; i += taille_bloc) {
        // Copier le bloc de message actuel
        memcpy(bloc, message + i, taille_bloc);

        // XOR entre le bloc actuel et le bloc précédent (ou iv pour le premier bloc)
        xor_blocs(bloc, bloc_avant, bloc, taille_bloc);

        // Chiffrement du bloc avec la clé (ici, on utilise un XOR simple pour simplifier)
        xor_blocs(bloc, cle, res + i, taille_bloc);

        // Copier le bloc chiffré actuel dans le bloc précédent pour le prochain tour
        memcpy(bloc_avant, res + i, taille_bloc);
    }
}

// Déchiffrement CBC
void cbc_decrypt(const unsigned char *chiffre, const unsigned char *cle, const unsigned char *iv, unsigned char *res, size_t len) {
    size_t taille_bloc = 16;
    unsigned char bloc[taille_bloc];
    unsigned char bloc_avant[taille_bloc];

    // Copie du vecteur d'initialisation (iv) dans le bloc précédent
    memcpy(bloc_avant, iv, taille_bloc);

    for (size_t i = 0; i < len; i += taille_bloc) {
        // Copier le bloc chiffré actuel
        memcpy(bloc, chiffre + i, taille_bloc);

        // Déchiffrement du bloc avec la clé (ici, on utilise un XOR simple pour simplifier)
        xor_blocs(bloc, cle, res + i, taille_bloc);

        // XOR avec le bloc précédent (ou iv pour le premier bloc)
        xor_blocs(res + i, bloc_avant, res + i, taille_bloc);

        // Mettre à jour le bloc précédent avec le bloc chiffré actuel
        memcpy(bloc_avant, chiffre + i, taille_bloc);
    }
}
