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
        return sizeof(Arbre);
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
    return taille;

}

Arbre* initABR2(int n) {

    int tab[n];
    int i;

    for (i=0; i<n; i++) {
        printf("entrez les valeurs a inserer dans l'arbre : ");
        scanf("%d", &tab[i]);
    }

    Arbre* a = initABR();
    Sommet* s;

    for (i=0; i<n; i++) {
        s = creerSommet(tab[i]);
        insererSommet(a, s);
    }

    return a;

}

Arbre* initABRrand(int n){
    int tab[n];
    int i;
    srand(time(NULL));
    for (i=0; i<n; i++) {
        tab[i] = rand();
    }
    Arbre* a = initABR();
    Sommet* s;

    for (i=0; i<n; i++) {
        s = creerSommet(tab[i]);
        insererSommet(a, s);
    }

    return a;
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
    newS->pere = NULL;
    return newS;
}

SommetCompact* minimumC(SommetCompact* s){
    SommetCompact* temp = s;
    while(temp->gauche!=NULL)
        temp=temp->gauche;
    return temp;
}


SommetCompact* rechercheC(SommetCompact* s, int inf, int sup){
    if(s==NULL || (s->inf==inf && s->sup == sup))
        return s;
    if(sup <s->inf){
        return rechercheC(s->gauche, inf, sup);
    }
    if(inf > s->sup){
        return rechercheC(s->droit, inf, sup);
    }
}

SommetCompact* successeurC(ArbreCompact* a, SommetCompact* s) {
    if(!rechercheC(a->racine, s->sup, s->inf))
        return NULL;
    if(s->droit!=NULL)
        return minimumC(s->droit);
    SommetCompact* temp = s;
    SommetCompact* y = s->pere;
    while(y!=NULL && temp==y->droit){
        temp=y;
        y=y->pere;
    }
    return y;

}

int insererElement (int cle, ArbreCompact* a) {
    int ind =0;
    if (!a) {
        return -1;
    }

    if (!a->racine) {
        SommetCompact* s = creerSommetCompact(cle);
        if(!s)
            return -1;
        a->racine = s;
        return 1;
    }

    SommetCompact* temp = a->racine;
    SommetCompact* temp2 = NULL;
    while (temp!= NULL && ind == 0) {
        //CAs où la clé est comprise dans intervalle ou cle = borne in ou cle = borne sup
        if ((temp->inf < cle && temp->sup > cle) || temp->inf == cle || temp->sup == cle) {
            ind = 1;
        }

        else if (temp->inf == cle+1) {
            temp->inf--; //on décale la borne inf
            ind = 1;
        }

        else if (temp->sup == cle-1) {
            temp->sup++; //on décale la borne sup
            ind = 1;
        }

        else if (temp->inf > cle) {
            temp = temp->gauche;
        }
        else if (temp->sup < cle) {
            temp = temp->droit;
        }
    }

    if (ind == 0) {
        SommetCompact* s = creerSommetCompact(cle);
        if(!s)
            return -1;
        temp = a->racine;
        while (temp != NULL) {
            temp2 = temp;
            if (temp->inf > cle) {
                temp = temp->gauche;
            }
            else if (temp->sup < cle) {
                temp = temp->droit;
            }
        }

        if (temp2->inf > cle) {
            s->pere = temp2;
            temp2->gauche = s;
        }
        else if (temp2->sup < cle) {
            s->pere = temp2;
            temp2->droit = s;
        }
    }
    return 1;
}

void afficherSommetC(SommetCompact* s) {
    printf("inf : %d\n", s->inf);
    printf("sup : %d\n\n", s->sup);
}


void afficherArbreC(ArbreCompact* a) {
    SommetCompact* temp = minimumC(a->racine);
    //afficherSommetC(temp);
    while(temp != NULL){
        afficherSommetC(temp);
        temp = successeurC(a, temp);
    }
}

int tailleABRC(ArbreCompact* a){
    if (!a->racine) {
        return sizeof(ArbreCompact);
    }

    int tArbre = sizeof(ArbreCompact);
    int tSommet = sizeof(SommetCompact);
    int i=0;
    SommetCompact* temp = minimum(a->racine);
    while(temp!=NULL){
        i++;
        temp = successeurC(a, temp);
    }
    int taille = tSommet*i + tArbre;
    return taille;
}

ArbreCompact* initABRCompact2(int n) {
    int tab[n];
    int i;

    for (i=0; i<n; i++) {
        printf("entrez les valeurs a inserer dans l'arbre : ");
        scanf("%d", &tab[i]);
    }

    ArbreCompact* a = initABRCompact();

    for (i=0; i<n; i++) {
        insererElement(tab[i], a);
    }

    return a;

}

ArbreCompact* initABRCrand(int n){
    int tab[n];
    int i;
    srand(time(NULL));
    for (i=0; i<n; i++) {
        tab[i] = rand();
    }
    ArbreCompact* a = initABRCompact();

    for (i=0; i<n; i++) {
        insererElement(tab[i], a);
    }

    return a;
}

void interface(){
    Arbre* a = NULL;
    ArbreCompact* ac = NULL;
    int choix=-1, nb;


    while (choix != 7) {
        printf("Entrez un choix : \n");
        printf("1. initialiser un ABR simple\n");
        printf("2. initialiser un ABR compact\n");
        printf("3. pre-charger un ABR simple de maniere aleatoire \n");
        printf("4. pre-charger un ABR compact de maniere aleatoire \n");
        printf("5. appeler interface abr simple \n");
        printf("6. appeler interface abr compact \n");
        printf("7. Quitter \n");
        scanf("%d", &choix);
        switch(choix) {
        case 1 :
            printf("Combien de sommet voulez-vous inserer : ");
            scanf("%d", &nb);
            a = initABR2(nb);
            afficherArbre(a);
            break;
        case 2:
            printf("Combien de sommet voulez-vous inserer : ");
            scanf("%d", &nb);
            ac = initABRCompact2(nb);
            afficherArbreC(ac);
            break;

        case 3:
            printf("Combien de sommet voulez-vous inserer : ");
            scanf("%d", &nb);
            a = initABRrand(nb);
            afficherArbre(a);
            break;

        case 4:
            printf("Combien de sommet voulez-vous inserer : ");
            scanf("%d", &nb);
            ac = initABRCrand(nb);
            afficherArbreC(ac);
            break;

        case 5:
            if(a)
                interfacebisA(a);
            else
                printf("aucun arbre simple n'a ete initialise\n");
            break;

        case 6:
            if(ac)
                interfacebisA(ac);
            else
                printf("aucun arbre simple n'a ete initialise\n");
            break;

        }
    }
}

void interfacebisA(Arbre* a){
    int choix=-1, nb, cle;
    Sommet* s;
    printf("Quelles actions voulez-vous effectuer ?  \n");
    printf("1. inserer un element\n");
    printf("2. afficher un element de l'arbre\n");
    printf("3. rechercher un element \n");
    printf("4. quitter l'interface de l arbre simple \n");
    scanf("%d", &choix);

    while (choix != 3) {
        printf("Quelles actions voulez-vous effectuer ?  \n");
        printf("1. inserer un element\n");
        printf("2. rechercher et afficher un element \n");
        printf("3. quitter l'interface de l arbre simple \n");
        scanf("%d", &choix);
        switch(choix){
        case 1:
            printf("entrez la valeur de l'element a ajoute\n");
            scanf("%d", &cle);
            s = creerSommet(cle);
            insererSommet(a, s);
            afficherArbre(a);
            break;
        case 2:
            printf("entrez la cle de l'element que vous cherchez\n");
            scanf("%d", &cle);
            s = recherche(a->racine, cle);
            afficherSommet(s);
            break;

        }
    }


}

void interfacebisAC(ArbreCompact* a) {
    int choix=-1, nb, inf, sup;
    SommetCompact* s;
    printf("Quelles actions voulez-vous effectuer ?  \n");
    printf("1. inserer un element\n");
    printf("2. afficher un element de l'arbre\n");
    printf("3. rechercher un element \n");
    printf("4. quitter l'interface de l arbre simple \n");
    scanf("%d", &choix);

    while (choix != 3) {
        printf("Quelles actions voulez-vous effectuer ?  \n");
        printf("1. inserer un element\n");
        printf("2. rechercher et afficher un element \n");
        printf("3. quitter l'interface de l arbre simple \n");
        scanf("%d", &choix);
        switch(choix){
        case 1:
            printf("entrez la valeur de l'element a ajoute\n");
            scanf("%d", &inf);
            insererElement(inf, a);
            afficherArbreC(a);
            break;
        case 2:
            printf("entrez la borne inferieur de l'element que vous cherchez\n");
            scanf("%d", &inf);
            printf("entrez la borne superieur de l'element que vous cherchez\n");
            scanf("%d", &sup);
            s = rechercheC(a->racine, inf, sup);
            afficherSommetC(s);
            break;

        }
    }

}


