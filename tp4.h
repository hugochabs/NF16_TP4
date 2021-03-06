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

Sommet* creerSommet(int cle);

void afficherSommet(Sommet* s);

Sommet* minimum(Sommet* s);

Sommet* recherche(Sommet* s, int x);

Sommet* successeur(Arbre* a, Sommet* s);

int insererSommet(Arbre* a, Sommet* s);

void afficherArbre(Arbre* a);

void afficherArbreBis(Sommet *s);

int tailleABR(Arbre* a);
//--PARTIE B--//

typedef struct SommetCompact {
    struct SommetCompact* gauche;
    struct SommetCompact* droit;
    int inf;
    int sup;
    struct SommetCompact* pere;
} SommetCompact;

typedef struct ArbreCompact {
    SommetCompact* racine;
} ArbreCompact;

ArbreCompact* initABRCompact();

SommetCompact* creerSommetCompact(int cle);

SommetCompact* maximumC(SommetCompact* s);

SommetCompact* minimumC(SommetCompact* s);

SommetCompact* rechercheC(SommetCompact* s, int inf, int sup);

SommetCompact* successeurC(ArbreCompact* a, SommetCompact* s);

SommetCompact* predecesseurC(ArbreCompact* a, SommetCompact* s);

int insererElement (int cle, ArbreCompact* a);

void afficherSommetC(SommetCompact* s);

void afficherArbreC(ArbreCompact* a);

SommetCompact* rechercheC(SommetCompact* s, int inf, int sup);

SommetCompact* rechercheCompact(SommetCompact* s, int cle);

int tailleABRC(ArbreCompact* a);

ArbreCompact* compaction(ArbreCompact* a);

void supprimerNoeud(ArbreCompact* a ,SommetCompact* s);

//--INTERFACE--//

void interface();
void interfacebisA(Arbre* a);
void interfacebisAC(ArbreCompact* a);

Arbre* initABR2(int n);
Arbre* initABRrand(int n);

ArbreCompact* initABRCompact2(int n);
ArbreCompact* initABRCrand(int n);

Arbre* compactToSimple (ArbreCompact* a);
ArbreCompact* simpleToCompact (Arbre* a);

void freeSimple (Arbre* a);
void desallocationSimple (Sommet* s);
void freeCompact (ArbreCompact* a);
void desallocationCompact (SommetCompact* s);


#endif // TP4_H_INCLUDED
