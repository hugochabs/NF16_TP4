#include "tp4.h"

//--PARTIE A--//

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
    printf("fils gauche : %d\n\n", s->gauche);
}

/*int vide(Arbre* a){
    if(a->racine==NULL)
        return 0;
    else return 1;
}*/

Sommet* minimum(Sommet* s){
    Sommet* temp = s;
    while(temp->gauche!=NULL)
        temp=temp->gauche;
    return temp;
}

Sommet* recherche(Sommet* s, int x){
    if(s==NULL || s->val==x)
        return s;
    if(x<s->val){
        return recherche(s->gauche, x);
    }
    if(x>s->val){
        return recherche(s->droit, x);
    }
}

Sommet* successeur(Arbre* a, Sommet* s){
    if(recherche(a->racine, s->val)==NULL)
        return NULL;
    if(s->droit!=NULL)
        return minimum(s->droit);
    Sommet* temp = s;
    Sommet* y = s->pere;
    while(y!=NULL && temp==y->droit){
        temp=y;
        y=y->pere;
    }
    return y;
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
            //printf("premier if\n");
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

void afficherArbre(Arbre* a){
    Sommet* temp = minimum(a->racine);
    printf("Voici tous les elements de l'arbre %d\n", a);
    while(temp!=NULL){
        if(temp->pere==NULL){
            printf("Voici la racine de l'arbre :\n");
            afficherSommet(temp);
        }
        else{
            afficherSommet(temp);
        }
        temp = successeur(a, temp);
    }
}

int tailleABR(Arbre* a){
    int tArbre = sizeof(Arbre);
    int tSommet = sizeof(Sommet);
    int i=0;
    Sommet* temp = minimum(a->racine);
    while(temp!=NULL){
        i++;
        temp = successeur(a, temp);
    }
    int taille = tSommet*i + tArbre;
    return taille;

}


