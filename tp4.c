#include "tp4.h"

Arbre* initABR(){
    Arbre* newABR = malloc(sizeof(Arbre));
    if(!newABR)
        return NULL;
    newABR->racine=NULL;
    return newABR;
}

Sommet* creerSommet(int cle){
    Sommet* newS = malloc(sizeof(Sommet));
    if(!newS)
        return NULL;
    newS->val = cle;
    newS->droit = NULL;
    newS->gauche = NULL;
    newS->pere = NULL;
    return newS;
}

void afficherSommet(Sommet* s){
    printf("%d\n", s->val);
}

/*int vide(Arbre* a){
    if(a->racine==NULL)
        return 0;
    else return 1;
}*/

int insererSommet(Arbre* a, Sommet* s){
    //Insertion si arbre vide
    if(!a->racine){
        a->racine=s;
        return 1;
    }

    //Insertion en feuille
    int cle = s->val;
    Sommet* temp = a->racine;
    afficherSommet(temp);
    while(temp->droit!=NULL && temp->droit!=NULL){
        if(cle<temp->val){
            printf("premier if\n");
            temp=temp->gauche;
        }
        else if(cle>temp->val){
            temp=temp->droit;
        }
        else if(cle==temp->val){
            return 0;
        }
    }
    if(temp->val>cle){
        s->pere = temp;
        temp->droit = s;
    }
    else{
        s->pere = temp;
        temp->gauche = s;
    }
    return 1;
}
