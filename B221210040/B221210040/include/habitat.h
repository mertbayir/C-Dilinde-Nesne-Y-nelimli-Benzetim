#ifndef HABITAT_H
#define HABITAT_H

#include "stdio.h"
#include "stdlib.h"
#include "pire.h"
#include "bocek.h"
#include "sinek.h"
#include "canli.h"
#include "bitki.h"


struct HABITAT
{
    void (*islemYap)();
    void (*yoket_habitat)(struct HABITAT*);
    char* (*gorunumHabitat)();
    void (*savasmaIslemleri)(struct CANLI**);
};

typedef struct HABITAT* Habitat;

Habitat HabitatOlustur();

char* gorunumHabitat();

void yoket_habitat(const Habitat);

void islemYap();

void savasmaIslemleri(Canli*,int,int,int);



#endif