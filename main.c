
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
    printf("%d\n", b);


    return 0;
}
