#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include<string>
using namespace std;

class Carte
{
    public:
        Carte();
        Carte (int ,int,float);
    void  virtual afficher() const;
    int getId() const {return id;}
        virtual ~Carte();
        int virtual get_id() const {return id;}
    protected:
    int id;
        int nbrheures;
        float prix;
    private:

};

#endif // CARTE_H
