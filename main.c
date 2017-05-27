
#include "tp4.h"

int main()
{
    printf("Hello world!\n");

    Arbre* a = initABR();
    printf("init\n");
    Sommet* s1 = creerSommet(6);
    printf("init\n");
    insererSommet(a, s1);
    //printf("%d\n", b);


    return 0;
}
