#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
Arbre* initABR2(int n);

Sommet* creerSommet(int cle);

void afficherSommet(Sommet* s);

Sommet* minimum(Sommet* s);

Sommet* recherche(Sommet* s, int x);

Sommet* successeur(Arbre* a, Sommet* s);

int vide(Arbre* a);

int insererSommet(Arbre* a, Sommet* s);

void afficherArbre(Arbre* a);
Arbre* initABRrand(int n);

//--PARTIE B--//

typedef struct SommetCompact {
    struct SommetCompact* gauche;
    struct SommetCompact* droit;
    int inf;
    int sup;
    struct SommetCompact* pere; //non indiqué dans le sujet
} SommetCompact;

typedef struct ArbreCompact {
    SommetCompact* racine;
} ArbreCompact;

ArbreCompact* initABRCompact();
SommetCompact* creerSommetCompact(int cle);
int insererElement (int cle, ArbreCompact* a);
SommetCompact* successeurC(ArbreCompact* a, SommetCompact* s);
SommetCompact* minimumC(SommetCompact* s);
void afficherSommetC(SommetCompact* s);
void afficherArbreC(ArbreCompact* a);
SommetCompact* rechercheC(SommetCompact* s, int inf, int sup);
int tailleABRC(ArbreCompact* a);

ArbreCompact* initABRCompact2(int n);
ArbreCompact* initABRCrand(int n);

void interface();
void interfacebisA(Arbre* a);
void interfacebisAC(ArbreCompact* a);



#endif // TP4_H_INCLUDED
