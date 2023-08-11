#ifndef APPLICATION_H
#define APPLICATION_H
#include"abonnement.h"
#include"parking.h"
#include<typeinfo>
class Application
{
public:
    Application();
    virtual ~Application();
    bool ajouter(const Carte &);
    list<Carte*>::iterator get_carte(int );
    bool ajouter( Parking& );
    list <Parking> :: iterator   recherchePark(int );
    Application& operator=(const Application &);
    bool  verif1(int,int);
    void ajouterCarte(long id,int reff);
    bool  verif3(int,int );
void afficher()const;
Parking* moinRentable();
void supprimer_c(Carte &);



bool verif2(int,int);



    bool ajouter(const Abonnement &);


protected:

private:
    list<Parking>LP;
    list<Carte*>LC;
};

#endif // APPLICATION_H
