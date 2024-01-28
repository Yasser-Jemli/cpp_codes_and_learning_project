#include "Animal.h"

Animal::Animal()
{
    //ctor
    espece="";
    matricule="";
}
Animal::Animal(string matricule, string espece)
{
    this->matricule=matricule;
    this->espece=espece;

}
Animal::~Animal()
{
    //dtor
}
void Animal::afficherAnimal()const
{
    cout<<"Animal:  "<<matricule<<" de l'espèce: "<<espece<<endl;
    cout<<"Les dates de< vaccins: "<<endl;
    for(unsigned int i=0; i< datesVaccins.size(); i++)
        cout<<datesVaccins[i]<<endl;

}

// une fonction de recherche peut être définie à part
bool Animal::ajouterVaccin(string date)
{
    //vérifier unicté de la date.
    for(vector<string>::iterator it=datesVaccins.begin(); it!=datesVaccins.end(); it++)
    {
        if((*it)==date)
        {
            cout<<"Vaccin existe dèjà!!"<<endl;
            return false;
        }
    }

        datesVaccins.push_back(date);
        cout<<"Vaccin ajouté"<<endl;
        return true;
}

