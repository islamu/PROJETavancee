// tests_chiffrement.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoXOR.h"

int main() {
    // Exemple de message et de clé
    const char *message = "Les carottes sont cuites";
    const char *cle = "rutabaga";

    size_t len = strlen(message);
    unsigned char *encrypted = (unsigned char *)malloc(len);
    unsigned char *decrypted = (unsigned char *)malloc(len + 1); // +1 pour le caractère nul

    if (!encrypted || !decrypted) {
        perror("Erreur d'allocation mémoire");
        return EXIT_FAILURE;
    }

    // Chiffrement
    algoXOR((const unsigned char *)message, (const unsigned char *)cle, encrypted, len);

    // Affichage du message chiffré en hexadécimal
    printf("Message chiffré (hex) : ");
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", encrypted[i]);
    }
    printf("\n");

    // Déchiffrement
    algoXOR(encrypted, (const unsigned char *)cle, decrypted, len);
    decrypted[len] = '\0'; // Ajouter le caractère nul

    // Affichage du message déchiffré
    printf("Message déchiffré : %s\n", decrypted);

    // Vérification
    if (strcmp(message, (const char *)decrypted) == 0) {
        printf("Test réussi : Le message déchiffré correspond au message original.\n");
    } else {
        printf("Test échoué : Le message déchiffré ne correspond pas au message original.\n");
    }

    // Libération de la mémoire
    free(encrypted);
    free(decrypted);

    return EXIT_SUCCESS;
}

