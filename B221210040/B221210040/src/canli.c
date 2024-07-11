#include "canli.h"
#include "habitat.h"


Canli Canli_Olustur(int deger)
{
    Canli this ;
    this = (Canli)malloc(sizeof(struct CANLI));
    this->sayiDeger = deger;
    this->yoket = yoket;
    return this;
}

void yoket(const Canli this)
{
    if(this != NULL)
    {
        free(this);
    }   
    
}

void ekran_sil()
{
    printf("\033[2J\033[H");
}

void canlilariYazdir(Canli* c,int toplam,int sutunSay)
{
    int ilkSutun = sutunSay;
    sutunSay = sutunSay -1 ;
    ekran_sil();
    for (int i = 0; i < toplam; ++i) {
        if(c[i]->sayiDeger >= 1 && c[i]->sayiDeger <= 9 )
        {
            printf("%s ", gorunumBitki());
        }
        else if(c[i]->sayiDeger >= 10 && c[i]->sayiDeger <= 20 )
        {
            printf("%s ", gorunumBocek());
        }
        else if(c[i]->sayiDeger >= 21 && c[i]->sayiDeger <= 50 )
        {
            printf("%s ", gorunumSinek());
        }
        else if(c[i]->sayiDeger >= 51 && c[i]->sayiDeger <= 99 )
        {
            printf("%s ", gorunumPire());
        }
        else
        {
            printf("X ");
        }


        if(sutunSay == i)
        {
            printf("\n");
            sutunSay = sutunSay + ilkSutun ;
        }
    }
}

