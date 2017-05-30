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

void afficherSommet(Sommet* s);

Sommet* minimum(Sommet* s);

Sommet* recherche(Sommet* s, int x);

Sommet* successeur(Arbre* a, Sommet* s);

int vide(Arbre* a);

int insererSommet(Arbre* a, Sommet* s);

void afficherArbre(Arbre* a);

//--PARTIE B--//

typedef struct SommetCompact {
    struct SommetCompact gauche;
    struct SommetCompact droit;
    int inf;
    int sup;
    //struct SommetCompact pere; //non indiqué dans le sujet
} SommetCompact;

typedef struct ArbreCompact {
    SommetCompact* racine;
}

ArbreCompact* initABRCompact();
SommetCompact* creerSommetCompact(int cle);
int insererElement (int cle, ArbreCompact* a);
//Sommet* successeur(Arbre* a, Sommet* s);
//SommetCompact* minimum(SommetCompact* s);



#endif // TP4_H_INCLUDED
