#include "carte.h"

Carte::Carte()
{
    //ctor
}
Carte::Carte(int a ,int b,float c)
{
    //ctor
    id=a;
    nbrheures=b;
    prix=c;

}
Carte::~Carte()
{
    //dtor
}
void Carte::afficher() const
{
    cout<<"id: "<<id<<endl;
    cout<<"nbr heures: "<<nbrheures<<endl;
    cout<<"prix: "<<prix<<endl;
}
