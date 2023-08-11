#ifndef ABONNEMENT_H
#define ABONNEMENT_H

#include "carte.h"


class Abonnement : public Carte
{
    public:
        Abonnement();
        Abonnement(int,int,float,string);
    void afficher() const;

        virtual ~Abonnement();

    protected:

    private:
        string date;
};

#endif // ABONNEMENT_H
