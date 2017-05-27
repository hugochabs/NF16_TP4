
#include "tp4.h"

int main()
{
    printf("Hello world!\n");

    Arbre* a = initABR();
    printf("init\n");
    Sommet* s1 = creerSommet(6);
    Sommet* s2 = creerSommet(4);
    Sommet* s3 = creerSommet(8);
    printf("init\n");
    afficherSommet(s1);
    int b = insererSommet(a, s1);
    int c = insererSommet(a, s2);
    int d = insererSommet(a, s3);
    //Sommet* rech = recherche(a->racine, 4);
    afficherSommet(rech);
    int e = a->racine->gauche->val;
    printf("%d\n", d);


    return 0;
}
