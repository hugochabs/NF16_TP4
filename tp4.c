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
    if (!a->racine) {
        return sizeof(Arbre)+4;
    }

    int tArbre = sizeof(Arbre);
    int tSommet = sizeof(Sommet);
    int i=0;
    Sommet* temp = minimum(a->racine);
    while(temp!=NULL){
        i++;
        temp = successeur(a, temp);
    }
    int taille = tSommet*i + tArbre;
    //int taille = tSommet*i + i*4 + tArbre + 4;
    return taille;

}


//Partie B

ArbreCompact* initABRCompact() {
    ArbreCompact* newABR = malloc(sizeof(ArbreCompact));
    if(!newABR)
        return NULL;
    newABR->racine=NULL;
    return newABR;
}
SommetCompact* creerSommetCompact(int cle) {
    SommetCompact* newS = malloc(sizeof(SommetCompact));
    if(!newS)
        return NULL;
    newS->inf = cle;
    newS->sup = cle;
    newS->droit = NULL;
    newS->gauche = NULL;
    return newS;
}

/*SommetCompact* minimum(SommetCompact* s){
    SommetCompact* temp = s;
    while(temp->gauche!=NULL)
        temp=temp->gauche;
    return temp;
}*/

/*SommetCompact* successeur(ArbreCompact* a, SommetCompact* s) {
    //verif si sommet existe dans arbre
    if(s->droit!=NULL)
        return minimum(s->droit);
    SommetCompact* temp = s;
    SommetCompact* y = s->pere;
    while(y!=NULL && temp==y->droit){
        temp=y;
        y=y->pere;
    }
    return y;

}*/

int insererElement (int cle, ArbreCompact* a) {
    int ind =0;
    if (!a) {
        return -1;
    }

    if (!a->racine) {
        SommetCompact* s = creerSommetCompact(cle);
        a->racine = s;
        return 1;
    }

    SommetCompact* temp = a->racine;
    SommetCompact* temp2 = NULL;
    while (temp!= NULL && ind == 0) {
        if ((temp->inf < cle && temp->sup > cle) || temp->inf == cle || temp->sup == cle) {
            ind = 1;
        }

        else if (temp->inf == cle+1) {
            temp->inf--;
            ind = 1;
        }

        else if (temp->sup == cle-1) {
            temp->sup++;
            ind = 1;
        }
    }

    if (ind == 0) {
        SommetCompact* s = creerSommetCompact(cle);
        temp = a->racine;
        while (temp != NULL) {
            temp2 = temp;
            if (temp->inf < cle) {
                temp = temp->gauche;
            }
            else if (temp->sup > cle) {
                temp = temp->droit;
            }
        }

        if (temp2->inf > cle) {
            temp2->gauche = s;
        }
        else if (temp2->sup < cle) {
            temp2->droit = s;
        }
    }

    return 1;

}

