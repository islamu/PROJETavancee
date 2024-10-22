// tests_chiffrement.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoCBC.h"
#include "algoXOR.h"

int main() {
    // Exemple de message et de clé
    const unsigned char message[] = "Les carottes sont cuites !!!";
    const unsigned char cle[] = "clefsecrete12345";  // Clé de 16 octets (adaptée à la taille des blocs)
    const unsigned char vi[] = "initial_vector123";  // vi de 16 octets

    size_t len = strlen((const char*)message);
    size_t len_ajustee = (len % 16 == 0) ? len : len + (16 - (len % 16));  // Taille ajustée pour les blocs

    unsigned char *creptee = (unsigned char *)malloc(len_ajustee);
    unsigned char *decreptee = (unsigned char *)malloc(len_ajustee + 1);  // +1 pour le caractère nul

    if (!creptee || !decreptee) {
        perror("Erreur d'allocation mémoire");
        return EXIT_FAILURE;
    }

    // Chiffrement CBC
    cbc_crypt(message, cle, vi, creptee, len_ajustee);

    // Affichage du message chiffré en hexadécimal
    printf("Message chiffré (CBC, hex) : ");
    for (size_t i = 0; i < len_ajustee; i++) {
        printf("%02x ", creptee[i]);
    }
    printf("\n");

    // Déchiffrement CBC
    cbc_decrypt(creptee, cle, vi, decreptee, len_ajustee);
    decreptee[len] = '\0';  // Ajouter le caractère nul

    // Affichage du message déchiffré
    printf("Message déchiffré (CBC) : %s\n", decreptee);

    // Vérification
    if (strcmp((const char *)message, (const char *)decreptee) == 0) {
        printf("Test réussi : Le message déchiffré correspond au message original.\n");
    } else {
        printf("Test échoué : Le message déchiffré ne correspond pas au message original.\n");
    }

    // Libération de la mémoire
    free(creptee);
    free(decreptee);

    return EXIT_SUCCESS;
}
