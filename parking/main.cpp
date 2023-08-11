#include <iostream>
#include "abonnement.h"
#include "carte.h"
#include "application.h"
#include "parking.h"
using namespace std;

int main()
{
    Application g;
    Carte c(1,12,5);
    Abonnement a(2,12,5,"a");
    Parking p(1,20);

    g.ajouter(c);
    g.ajouter(a);
    g.ajouter(p);
    g.afficher();
        cout<<"******************************"<<endl;

    //g.supprimer_c(c);

    g.afficher();
    //g.moinRentable()->afficher();
    //g.enregistrer();
    return 0;
}
