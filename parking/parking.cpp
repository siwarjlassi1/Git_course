#include "parking.h"

Parking::Parking()
{
    //ctor
}
Parking::Parking(int a,int b)
{
    //ctor
    refer=a;
    nbrplaces=b;
}
Parking::~Parking()
{
    //dtor
}
void Parking::afficher() const
{
    cout<<"refference: "<<refer<<endl;
    cout<<"nombre de places: "<<nbrplaces<<endl;
     list <int> ::const_iterator it;

     for(it=l1.begin();it!=l1.end();++it){
        cout << *it << endl;
    }

    cout << "List  Util : " << endl;
    for(it=l2.begin();it!=l2.end();++it){
        cout << *it << endl;
    }
}
bool Parking::operator<(const Parking& P){
    return this->l1.size() < P.l2.size();
}
void Parking::supprimer_carte(Carte &c)
  {
      list<int> ::iterator it;
       for(it=l1.begin(); it!=l1.end(); ++it)
    {if ((*it)==c.getId())
    {
        l1.erase(it);
    }

     }
      for(it=l2.begin(); it!=l2.end(); ++it)
    {if ((*it)==c.getId())
    {
        l2.erase(it);
    }
     }
  }
