#ifndef PARKING_H
#define PARKING_H
#include<list>
using namespace std;
#include <iostream>
#include"carte.h"
class Parking
{
    public:
        Parking();
        Parking(int,int);
        virtual ~Parking();
        int getRef() {return refer;}
            list <int> getList1(){return l1;};
                list <int> getList2(){return l2;};
void afficher()const;
bool operator<(const Parking& );
void supprimer_carte(Carte &);


                    int getNbp(){return nbrplaces;}
    protected:

    private:
        int refer;
        int nbrplaces;
        list<int>l1;
        list<int>l2;
};

#endif // PARKING_H
