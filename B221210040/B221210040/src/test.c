#include "stdio.h"
#include "habitat.h"


int main()
{

    Habitat h1 = HabitatOlustur();
    
    printf("Canlilar:\n");
    h1->gorunumHabitat();

    printf("\n Islemlere Devam Etmek Icin Bir Tusa Basiniz!\n");
    getchar();

    h1->islemYap();
    h1->yoket_habitat(h1);

    
    return 0;
}