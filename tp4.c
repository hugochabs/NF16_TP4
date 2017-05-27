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
    printf("val : %d\n", s->val);
    printf("pere : %d\n", s->pere);
    printf("fils droit : %d\n", s->droit);
    printf("fils gauche : %d\n", s->gauche);
}

/*int vide(Arbre* a){
    if(a->racine==NULL)
        return 0;
    else return 1;
}*/

Sommet* recherche(Sommet* s, int x){
    if(s->val==NULL || s->val==x)
        return s;
    if(x<s->val){
        return recherche(s->gauche, x);
    }
    if(x>s->val){
        return recherche(s->droit, x);
    }
}

Sommet* successeur(Arbre* a, Sommet* s){

}

int insererSommet(Arbre* a, Sommet* s){
    //Insertion si arbre vide
    if(!a->racine){
        a->racine=s;
        return 1;
    }

    //Insertion en feuille
    int cle = s->val;
    Sommet* temp1 = NULL;
    Sommet* temp2 = a->racine;
    //afficherSommet(temp2);
    while(temp2!=NULL){
        temp1 = temp2;
        if(cle<temp2->val){
            printf("premier if\n");
            temp2=temp2->gauche;
        }
        else if(cle>temp2->val){
            temp2=temp2->droit;
        }
        else if(cle==temp2->val){
            return 0;
        }
    }
    s->pere=temp1;
    if(cle>temp1->val)
        temp1->droit = s;
    else
        temp1->gauche = s;
    return 1;
}


