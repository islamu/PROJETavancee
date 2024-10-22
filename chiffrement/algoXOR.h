<<<<<<< HEAD
// algoXOR.h


#ifndef algoXOR_H
#define algoXOR_H

#include <stddef.h>

// Fonction pour chiffrer ou déchiffrer un message avec XOR
// message : pointeur vers le message en clair ou chiffré
// cle : pointeur vers la clé de chiffrement
// res : pointeur vers le buffer de sortie (doit être alloué par l'appelant)
// len : longueur du message en octets
void algoXOR(const unsigned char *message, const unsigned char *cle, unsigned char *res, size_t len);

#endif // algoXOR_H
=======
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
>>>>>>> 3a01e5abc3530918ce7b568bb1bd49f5a73e5798
