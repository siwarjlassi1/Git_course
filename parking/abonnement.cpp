#include "abonnement.h"

Abonnement::Abonnement()
{
    //ctor
}
Abonnement::Abonnement(int a,int b,float c,string d):Carte(a,b,c)
{
    date=d;
}
Abonnement::~Abonnement()
{
    //dtor
}
void Abonnement::afficher() const
{
    Carte::afficher();
    cout<<"date: "<<date<<endl;
}
