#include "stdio.h"
#include "bocek.h"

Bocek BocekOlustur()
{
    Bocek this;
    this = (Bocek)malloc(sizeof(struct BOCEK));
    this->super= Canli_Olustur();
    this->yoket_bocek = &yoket_bocek;
    this->super->gorunum = &gorunumBocek;
    return this;
}

int degerGoster(const Bocek bocek)
{
  return bocek->super->sayiDeger;
}

void yoket_bocek(const Bocek this)
{
    if (this == NULL)
  {
    return;
  }
  
  this->super->yoket(this->super);
  free(this);
}

char* gorunumBocek()
{
    return "C";
}