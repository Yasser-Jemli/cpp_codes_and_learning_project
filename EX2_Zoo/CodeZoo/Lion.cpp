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
    cout<<"Quantité de la viande consommée: "<<quanttViande<<endl;

}

Lion::~Lion()
{
    //dtor
}
