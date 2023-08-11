#include "application.h"

Application::Application()
{
    //ctor
}

Application::~Application()
{
    //dtor
     for(list<Carte*>::iterator i=LC.begin();i != LC.end();i++)
    {
        delete (*i);
    }
}
bool Application::ajouter(const Carte &C)
{
    if(get_carte(C.get_id())==LC.end())
    {
       Carte *p=new Carte(C);
        LC.push_back(p);
        return true;
    }
return false;
}
bool Application::ajouter(const Abonnement &A)
{
    if(get_carte(A.get_id())==LC.end())
    {
       Carte *p=new Carte(A);
        LC.push_back(p);
        return true;
    }
return false;
}
Application& Application::operator=(const Application &B)
{
    if(&B != this)
    {
        for(list<Carte*>::iterator j=LC.begin();j != LC.end();j++)
        {
            delete (*j);
        }
        LC.clear();

        Carte*p;
    LC=B.LC;
    for(list<Carte*>::const_iterator i=B.LC.begin(); i != B.LC.end();i++)
    {
        if(typeid(**i)==typeid(Carte)){
            p=new Carte(**i);
        }else if(typeid(**i)==typeid(Abonnement)){
            p=new Abonnement(static_cast<const Abonnement&>(**i));
        }
        LC.push_back(p);

    }
    }
    return (*this);
}
  list <Parking> :: iterator  Application :: recherchePark(int reff)
{
    for(list <Parking> :: iterator it=LP.begin(); it!=LP.end(); ++it)
    {
        if(it->getRef()==reff)
        {
            return it;
        }
    }
    return LP.end();
}
bool Application::ajouter( Parking& m)
{
    if(recherchePark(m.getRef())!=LP.end())
        return false;

    LP.push_back(m);
    return true;
}
bool Application :: verif1(int id,int reff)
{
    list <Parking> :: iterator it;
      list <int> :: iterator it1;
    for (it=LP.begin();it!=LP.end();++it)
    {
        if(it->getRef()==reff)
        {
            for(it1=it->getList1().begin();it1!=it->getList1().end();++it)
            {
                if(*it1 == id)
                {
                    return true;
                }

            }
            return false;
        }
    }
    return false;

}
bool Application :: verif2(int id,int reff)
{
    list <Parking> :: iterator it;
    for (it=LP.begin();it!=LP.end();++it)
    {
        if((it->getRef()==reff) && ((int) it->getList2().size() < it->getNbp()))
        {
            return true;
        }
    }
    return false;
}
bool Application :: verif3(int id,int reff)
{
    list <Parking> :: iterator it;
     list <int> :: iterator it1;
    for (it=LP.begin();it!=LP.end();++it)
    {
        if(it->getRef()==reff)
        {
          for(it1=it->getList2().begin();it1!=it->getList2().end();++it)
          {
              if (*it1 == id)
              {
                  return false;
              }
          }
          return true;
        }
    }
    return true;
}
void Application :: ajouterCarte(long id,int reff)
{
   list <Parking> :: iterator it=recherchePark(reff);
   try{
if (verif1(id,reff) && verif2(id,reff) && verif3(id,reff))
{
   it->getList2().push_back(id);
}
else
{
    throw("pas dajout");
}
   }
   catch(string err)
   {
       cout<<err;
   }
}
list<Carte*>::iterator Application::get_carte(int id)
{
    for(list<Carte*>::iterator i=LC.begin();i != LC.end();i++)
    {
        if ((**i).get_id()==id)
        {
            return i;
        }
    }
    return LC.end();
}
void Application :: afficher()const
{
    list <Carte*> :: const_iterator it;
    list <Parking> :: const_iterator it1;
    Carte* a;

    for (it=LC.begin();it!=LC.end();++it)
    {
        if (typeid(**it)==typeid(Abonnement))
        {
             a=(Abonnement*)(*it);
        }
        else
        {
            a=(Carte*) (*it);
        }
        a->afficher();
    }
     for (it1=LP.begin();it1!=LP.end();++it1)
     {
         it1->afficher();
     }
}
Parking* Application ::moinRentable(){
    Parking* moin = &*LP.begin();
    for(list <Parking> :: iterator it = LP.begin(); it != LP.end(); ++it){
        if(*it < *moin){
            moin = &*it;
        }
    }
    return moin;
}
void Application ::supprimer_c(Carte &c1)
{list <Carte*> :: iterator it;
       for(it=LC.begin(); it!=LC.end(); it++)
    {if ((*it)->getId()==c1.getId())
        {
            delete(*it);
            LC.erase(it);

        }
    }
    list<Parking> ::iterator i;
    for(i=LP.begin(); i!=LP.end(); ++i)
    {
        i->supprimer_carte(c1);
    }
}
