#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//--PARTIE A--//

typedef struct Sommet{
    int val;
    struct Sommet* gauche;
    struct Sommet* droit;
    struct Sommet* pere;
}Sommet;

typedef struct Arbre{
    Sommet* racine;
}Arbre;

Arbre* initABR();

Sommet* creerSommet(int cle);

int vide(Arbre* a);

int insererSommet(Arbre* a, Sommet* s);

#endif // TP4_H_INCLUDED
