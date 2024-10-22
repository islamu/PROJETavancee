// algoCBC.h

#ifndef ALGO_CBC_H
#define ALGO_CBC_H

#include <stddef.h>

// Chiffrement CBC
// message : pointeur vers le message en clair
// cle : clé de chiffrement
// vi : vecteur d'initialisation (vecteur initial)
// res : pointeur vers le message chiffré
// len : longueur du message en octets
void cbc_crypt(const unsigned char *message, const unsigned char *cle, const unsigned char *iv, unsigned char *res, size_t len);

// Déchiffrement CBC
// chiffre : pointeur vers le message chiffré
// cle : clé de déchiffrement
// iv : vecteur d'initialisation (Initial Vector)
// res : pointeur vers le message déchiffré
// len : longueur du message chiffré en octets
void cbc_decrypt(const unsigned char *chiffre, const unsigned char *cle, const unsigned char *iv, unsigned char *res, size_t len);

#endif // ALGO_CBC_H
