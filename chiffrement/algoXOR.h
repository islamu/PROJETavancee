
// algoXOR.h

#ifndef ALGOXOR_H
#define ALGOXOR_H

#include <stddef.h>

// Fonction pour chiffrer ou déchiffrer un message avec XOR
// message : pointeur vers le message en clair ou chiffré
// cle : pointeur vers la clé de chiffrement
// output : pointeur vers le buffer de sortie (doit être alloué par l'appelant)
// len : longueur du message en octets
void algoXOR(const unsigned char *message, const unsigned char *cle, unsigned char *output, size_t len);

#endif // ALGOXOR_H

