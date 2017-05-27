#include "tp4.h"

Arbre* initABR(){
    Arbre* newABR = malloc(sizeof(Arbre));
    if(newABR)
        return NULL;
    newABR->racine=NULL;
    return newABR;
}

Sommet* creerSommet(int cle){
    Sommet* newS = malloc(sizeof(Sommet));
    if(newS)
        return NULL;
    newS->val = cle;
    newS->droit = NULL;
    newS->gauche = NULL;
    newS->pere = NULL;
    return newS;
}

/*int vide(Arbre* a){
    if(a->racine==NULL)
        return 0;
    else return 1;
}*/

int insererSommet(Arbre* a, Sommet* s){
    //Insertion si arbre vide
    if(a->racine==NULL){
        printf("test\n");
        a->racine=s;
    }

    //Insertion en feuille

    return 1;
}
