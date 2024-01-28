#include "Lion.h"

Lion::Lion()
{
    //ctor
    quanttViande=0;
}
Lion::Lion(string matricule, string espece, float quanttViande):Animal(matricule,espece)
{
    this->quanttViande=quanttViande;

}
void Lion::afficherAnimal()const
{
    Animal::afficherAnimal();
    cout<<"Quantit� de la viande consomm�e: "<<quanttViande<<endl;

}

Lion::~Lion()
{
    //dtor
}
