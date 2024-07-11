#include "stdio.h"
#include "stdlib.h"
#include "habitat.h"
#include "canli.h"


Habitat HabitatOlustur()
{
    Habitat this;
    this = (Habitat)malloc(sizeof(struct HABITAT));
    this->islemYap = islemYap;
    this->yoket_habitat = yoket_habitat;
    this->gorunumHabitat = gorunumHabitat;
    return this;
}

char* gorunumHabitat()
{
    FILE *dosya;
    int sayi;
    dosya = fopen("Veri.txt", "r");

    if (dosya == NULL)
    {
        printf("Dosya acilamadi");
    }

    while (fscanf(dosya, "%d", &sayi) != EOF)
    {
        if (sayi >= 1 && sayi <= 9)
        {
            printf("%s ",gorunumBitki());
        }
        else if (sayi >= 10 && sayi <= 20)
        {
            printf("%s ",gorunumBocek());
        }
        else if (sayi >= 21 && sayi <= 50)
        {
            printf("%s ",gorunumSinek());
        }
        else if (sayi >= 51 && sayi <= 99)
        {
            printf("%s ",gorunumPire());
        }

        if (fgetc(dosya) == '\n')
        {
            printf("\n");
        }
    }
}

void yoket_habitat(const Habitat this)
{
    if(this != NULL)
    {
        free(this);
    }
}

void islemYap()
{
    FILE *dosya;
    int sayi;
    dosya = fopen("Veri.txt", "r");
    int satir = 1;
    int sutun = 0;

    if (dosya == NULL)
    {
        printf("Dosya acilamadi");
    }

    while (fscanf(dosya, "%d", &sayi) != EOF)
    {
        if (sayi >= 1 && sayi <= 9)
        {
            sutun++;
        }
        else if (sayi >= 10 && sayi <= 20)
        {
            sutun++;
        }
        else if (sayi >= 21 && sayi <= 50)
        {
            sutun++;
        }
        else if (sayi >= 51 && sayi <= 99)
        {
            sutun++;
        }

        if (fgetc(dosya) == '\n')
        {
            satir++;
            sutun=0;
        }
    }
    int elemanSayisi=sutun*satir;

    fseek(dosya, 0, SEEK_SET);

    Canli hbtAdres[elemanSayisi];

    int satir1 = 1;
    int sutun1 = 0;

    while (fscanf(dosya, "%d", &sayi) != EOF)
    {
        if (sayi >= 1 && sayi <= 9)
        {
            Bitki b = BitkiOlustur();
            b->super->sayiDeger = sayi;
            b->super->id = 1;
            hbtAdres[sutun1] = b->super;
            sutun1++;
        }
        else if (sayi >= 10 && sayi <= 20)
        {
            Bocek c = BocekOlustur();
            c->super->sayiDeger = sayi;
            c->super->id = 2;
            hbtAdres[sutun1] = c->super;
            sutun1++;
        }
        else if (sayi >= 21 && sayi <= 50)
        {
            Sinek s = SinekOlustur();
            s->super->super->sayiDeger = sayi;
            s->super->super->id = 3;
            hbtAdres[sutun1] = s->super->super;
            sutun1++;
        }
        else if (sayi >= 51 && sayi <= 99)
        {
            Pire p = PireOlustur();
            p->super->super->sayiDeger = sayi;
            p->super->super->id = 4;
            hbtAdres[sutun1] = p->super->super;
            sutun1++;
        }

        if (fgetc(dosya) == '\n')
        {
            satir1++;
        }
    }
    fclose(dosya);
    sutun1 = sutun1/satir1;
    savasmaIslemleri(hbtAdres,elemanSayisi,sutun1,satir1);
}


void savasmaIslemleri(Canli *c,int toplam,int sutunSay,int satirSay)
{
    int digerC = 1;
    int ilkC = 0;
    int sutun = sutunSay;

    for (int i = 0; i < toplam; ++i) {
        canlilariYazdir(c,toplam,sutun);
        if((c[ilkC]->id == 1 && c[digerC]->id == 3) ||(c[ilkC]->id == 1 && c[digerC]->id == 4))
        {
            c[digerC]->sayiDeger = 0;
            c[digerC]->yoket(c[digerC]);
            if(digerC<toplam-1)
            {
                digerC++;
            }
        }
        else if(c[ilkC]->id == 1 && c[digerC]->id == 2)
        {
            c[ilkC]->sayiDeger = 0;
            c[ilkC]->yoket(c[ilkC]);
            ilkC = digerC;
            if(digerC<toplam-1)
            {
                digerC++;
            }
        }
        else if((c[ilkC]->id == 2 && c[digerC]->id == 4)||(c[ilkC]->id == 2 && c[digerC]->id == 1))
        {
             c[digerC]->sayiDeger = 0;
            c[digerC]->yoket(c[digerC]);
            if(digerC<toplam-1)
            {
                digerC++;
            }
        }
        else if(c[ilkC]->id == 2 && c[digerC]->id == 3)
        {
            c[ilkC]->sayiDeger = 0;
            c[ilkC]->yoket(c[ilkC]);
            ilkC = digerC;
            if(digerC<toplam-1)
            {
                digerC++;
            }
        }


        else if((c[ilkC]->id == 3 && c[digerC]->id == 2)||(c[ilkC]->id == 3 && c[digerC]->id == 4))
        {
            c[digerC]->sayiDeger = 0;
            c[digerC]->yoket(c[digerC]);
            if(digerC<toplam-1)
            {
                digerC++;
            }
        }
        else if(c[ilkC]->id == 3 && c[digerC]->id == 1)
        {
            c[ilkC]->sayiDeger = 0;
            c[ilkC]->yoket(c[ilkC]);
            ilkC = digerC;
            if(digerC<toplam-1)
            {
                digerC++;
            }

        }
        else if((c[ilkC]->id == 4 && c[digerC]->id == 1)||(c[ilkC]->id == 4 && c[digerC]->id == 2)||(c[ilkC]->id == 4 && c[digerC]->id == 3))
        {
            c[ilkC]->sayiDeger = 0;
            c[ilkC]->yoket(c[ilkC]);
            ilkC = digerC;
            if(digerC<toplam-1)
            {
                digerC++;
            }
        }
        else if((c[ilkC]->id == 1 && c[digerC]->id == 1)||(c[ilkC]->id == 2 && c[digerC]->id == 2)||(c[ilkC]->id == 3 && c[digerC]->id == 3)||(c[ilkC]->id == 4 && c[digerC]->id == 4))
        {
            if(c[ilkC]->sayiDeger > c[digerC]->sayiDeger)
            {
               c[digerC]->sayiDeger = 0;
                c[digerC]->yoket(c[digerC]);
                if(digerC<toplam-1)
                {
                    digerC++;
                }
            }
            else if(c[ilkC]->sayiDeger < c[digerC]->sayiDeger)
            {
                c[ilkC]->sayiDeger = 0;
                c[ilkC]->yoket(c[ilkC]);
                ilkC = digerC;
                if(digerC<toplam-1)
                {
                    digerC++;
                }
            }
            else if(c[ilkC]->sayiDeger == c[digerC]->sayiDeger)
            {
                c[digerC]->sayiDeger = 0;
                c[digerC]->yoket(c[digerC]);
                if(digerC<toplam-1)
                {
                    digerC++;
                }

            }

        }

    }

    int sayac = 0;
    int diziDeger = 0;

    while(c[diziDeger]->sayiDeger == 0 || c[diziDeger]->sayiDeger > 100)
    {
        sayac++;
        diziDeger++;

    }

    int konumY = 0;
    while(sutunSay<sayac)
    {
        sayac = sayac - sutunSay;
        konumY++;
    }
    int konumX = sayac;


    if(c[diziDeger]->id == 1)
    {
        printf("Kazanan : B ( %d , %d )",konumY,konumX);
    }
    else if(c[diziDeger]->id == 2)
    {
        printf("Kazanan : C ( %d , %d )",konumY,konumX);
    }
    else if(c[diziDeger]->id == 3)
    {
        printf("Kazanan : S ( %d , %d )",konumY,konumX);
    }
    else if(c[diziDeger]->id == 4)
    {
        printf("Kazanan : P ( %d , %d )",konumY,konumX);
    }

}