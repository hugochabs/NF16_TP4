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
    if (s) {
    printf("Sommet  : %p\n", s);
    printf("val : %d\n", s->val);
    printf("pere : %p\n", s->pere);
    printf("fils droit : %p\n", s->droit);
    printf("fils gauche : %p\n\n", s->gauche);
    }

    else
        printf("ce sommet n'existe pas \n");
}

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
    if (!s || !a)
        return -1;

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
    if (!a || a->racine==NULL) {
        printf("arbre vide\n");
        return;
    }
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
    if (!a) {
        return 0;
    }

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
    if (!s) {
        return NULL;
    }

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

SommetCompact* rechercheCompact(SommetCompact* s, int cle){
    if(s==NULL || (cle >= s->inf && cle <= s->sup))
        return s;
    if(cle <s->inf){
        return rechercheCompact(s->gauche, cle);
    }
    if(cle > s->sup){
        return rechercheCompact(s->droit, cle);
    }
}

SommetCompact* successeurC(ArbreCompact* a, SommetCompact* s) {
    if (!a || !s) {
        return NULL;
    }

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
            temp2 = temp;
            temp = temp->gauche;
        }
        else if (temp->sup < cle) {
            temp2 = temp;
            temp = temp->droit;
        }
    }

    if (ind == 0) {
        SommetCompact* s = creerSommetCompact(cle);
        if(!s)
            return -1;

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
    if (!s)
        printf("ce sommet n'existe pas \n");
    else {
    printf("inf : %d\n", s->inf);
    printf("sup : %d\n\n", s->sup);
    }
}

void afficherArbreC(ArbreCompact* a) {
    if (!a || !a->racine) {
        printf("arbre vide\n");
    }

    SommetCompact* temp = minimumC(a->racine);
    //afficherSommetC(temp);
    while(temp != NULL){
        afficherSommetC(temp);
        temp = successeurC(a, temp);
    }
}

int tailleABRC(ArbreCompact* a){
    if (!a)
        return 0;

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

//--INTERFACE--//

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


    while (choix != 9) {
        printf("Entrez un choix : \n");
        printf("1. initialiser un ABR simple\n");
        printf("2. initialiser un ABR compact\n");
        printf("3. pre-charger un ABR simple de maniere aleatoire \n");
        printf("4. pre-charger un ABR compact de maniere aleatoire \n");
        printf("5. afficher l'ABR simple\n");
        printf("6. afficher l'ABR compact\n");
        printf("7. appeler interface abr simple \n");
        printf("8. appeler interface abr compact \n");
        printf("9. Quitter \n");
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

        case 5 :
            if(a)
                afficherArbre(a);
            else
                printf("aucun arbre simple n'a ete initialise\n");
            break;

        case 6:
            if(ac)
                afficherArbreC(ac);
            else
                printf("aucun arbre compact n'a ete initialise\n");
            break;


        case 7:
            if(a)
                interfacebisA(a);
            else
                printf("aucun arbre simple n'a ete initialise\n");
            break;

        case 8:
            if(ac)
                interfacebisAC(ac);
            else
                printf("aucun arbre compact n'a ete initialise\n");
            break;

        }
    }

    freeSimple(a);
    printf("arbre simple libere\n");
    a = NULL;
    freeCompact(ac);
    printf("arbre simple libere\n");
    ac = NULL;
}

void interfacebisA(Arbre* a){
    int choix=-1, nb, cle, taille, tailleC;
    ArbreCompact* ac = NULL;
    Sommet* s;

    while (choix != 5) {
        printf("Quelles actions voulez-vous effectuer ?  \n");
        printf("1. inserer un element\n");
        printf("2. rechercher et afficher un element \n");
        printf("3. convertir l'arbre simple en arbre compact \n");
        printf("4. comparer la taille de l'arbre simple à un arbre compact \n");
        printf("5. quitter l'interface de l arbre simple \n");
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
        case 3:
            if (!ac) {
                ac = initABRCompact();
                ac = simpleToCompact(a);
            }
            afficherArbreC(ac);

        case 4:
            if (!ac) {
                ac = initABRCompact();
                ac = simpleToCompact(a);
            }
            tailleC = tailleABRC(ac);
            taille = tailleABR(a);
            printf("la taille de votre ABR simple est de %d \n", taille);
            printf("la taille de votre ABR compact est de %d \n", tailleC);
            printf("taille(ABR Simple) - taille(ABR Compact) = %d\n\n", taille-tailleC);
            break;

        }
    }
    freeCompact(ac);
    ac = NULL;

}

void interfacebisAC(ArbreCompact* a) {
    int choix=-1, nb, cle, taille, tailleS;
    Arbre* as = NULL;
    SommetCompact* s;

    while (choix != 5) {
        printf("Quelles actions voulez-vous effectuer ?  \n");
        printf("1. inserer un element\n");
        printf("2. rechercher et afficher un element \n");
        printf("3. convertir l'arbre compact en arbre simple \n");
        printf("4. comparer la taille de l'arbre compact à un arbre simple \n");
        printf("5. quitter l'interface de l arbre compact \n");
        scanf("%d", &choix);
        switch(choix){
        case 1:
            printf("entrez la valeur de l'element a ajoute\n");
            scanf("%d", &cle);
            insererElement(cle, a);
            afficherArbreC(a);
            break;
        case 2:
            printf("entrez la valeur de l'element que vous cherchez\n");
            scanf("%d", &cle);
            s = rechercheCompact(a->racine, cle);
            afficherSommetC(s);
            break;
        case 3:
            if (!as) {
                as = initABR();
                as = compactToSimple(a);
            }
            afficherArbre(as);
        case 4:
            if (!as) {
                as = initABR();
                as = compactToSimple(a);
            }
            tailleS = tailleABR(as);
            taille = tailleABRC(a);
            printf("la taille de votre ABR compact est de %d \n", taille);
            printf("la taille de votre ABR simple est de %d \n", tailleS);
            printf("taille(ABR Compact) - taille(ABR Simple) = %d\n\n", taille-tailleS);
            break;

        }
    }

    freeSimple(as);
    as = NULL;

}

Arbre* compactToSimple (ArbreCompact* ac) {
    if (!ac || !ac->racine) { //on initialise pas un arbre pour le cas de l'arbre vide car le traitement est sans conséquence
        return NULL;
    }

    Arbre* a = initABR();
    int i, inf, sup;
    SommetCompact* temp = minimumC(ac->racine);
    Sommet* s;
    while(temp != NULL){
        inf = temp->inf;
        sup = temp->sup;
        for (i=inf; i<sup+1; i++) {
            s = creerSommet(i);
            insererSommet(a, s);
        }
        temp = successeurC(ac, temp);
    }

    return a;
}

ArbreCompact* simpleToCompact (Arbre* a) {
    if (!a || !a->racine) { //on initialise pas un arbre pour le cas de l'arbre vide car on ne s'en servira pas ici
        return NULL;
    }

    ArbreCompact* ac = initABRCompact();

    Sommet* temp = minimum(a->racine);
    while(temp != NULL){
        insererElement(temp->val, ac);
        temp = successeur(a, temp);
    }
    return ac;
}

void freeSimple (Arbre* a) {
    if (!a)
        return;
    if (!a->racine) {
        free(a);
    }

    desallocationSimple(minimum(a->racine));

    free(a);
}

void desallocationSimple (Sommet* s) {

    if (s->gauche == NULL && s->droit == NULL && s->pere != NULL) {
        Sommet* s2 = s->pere;
        if (s == s2->droit)
            s2->droit = NULL;
        if (s == s2->gauche)
            s2->gauche = NULL;
        printf("sommet desalloue d'adresse %p et de valeur %d\n", s, s->val);
        free(s);
        desallocationSimple(s2);
    }

    else if (s->droit != NULL && s->pere == NULL) {
        desallocationSimple(s->droit);
    }

    else if (s->gauche == NULL && s->droit == NULL && s->pere == NULL) {
        printf("racine desalloue d'adresse %p et de valeur %d\n", s, s->val);
        free(s);
    }

    else if (s->gauche != NULL) {
        desallocationSimple(s->gauche);
    }

    else if(s->droit != NULL) {
        desallocationSimple(s->droit);
    }
}

void freeCompact (ArbreCompact* a) {
    if (!a)
        return;
    if (!a->racine) {
        free(a);
    }
    desallocationCompact(minimumC(a->racine));

    free(a);
}

void desallocationCompact (SommetCompact* s) {
    if (s->gauche == NULL && s->droit == NULL && s->pere != NULL) {
        SommetCompact* s2 = s->pere;
        if (s == s2->droit)
            s2->droit = NULL;
        if (s == s2->gauche)
            s2->gauche = NULL;
        printf("sommet desalloue d'adresse %p et de valeur %d\n", s, s->inf);
        free(s);
        desallocationCompact(s2);
    }

    else if (s->droit != NULL && s->pere == NULL) {
        desallocationCompact(s->droit);
    }

    else if (s->gauche == NULL && s->droit == NULL && s->pere == NULL) {
        printf("racine desalloue d'adresse %p et de valeur %d\n", s, s->inf);
        free(s);
    }

    else if (s->gauche != NULL) {
        desallocationCompact(s->gauche);
    }

    else if(s->droit != NULL) {
        desallocationCompact(s->droit);
    }

}
