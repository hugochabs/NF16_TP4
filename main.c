
#include "tp4.h"

int main()
{
    printf("Hello world!\n");

    Arbre* a = initABR();
    //printf("init\n");
    Sommet* s1 = creerSommet(6);
    Sommet* s2 = creerSommet(4);
    Sommet* s3 = creerSommet(8);
    Sommet* s4 = creerSommet(10);
    Sommet* s5 = creerSommet(2);
    Sommet* s6 = creerSommet(3);
    //printf("init\n");

    int b = insererSommet(a, s1);
    int c = insererSommet(a, s2);
    int d = insererSommet(a, s3);
    int e = insererSommet(a, s4);
    int f = insererSommet(a, s5);
    int g = insererSommet(a, s6);
    //afficherSommet(s4);
    //Sommet* rech = recherche(a->racine, 4);
    //afficherSommet(successeur(a, s5));
    afficherArbre(a);
    //int e = a->racine->gauche->val;
    printf("%d octets\n", tailleABR(a));


    return 0;
}
