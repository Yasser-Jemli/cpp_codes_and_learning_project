#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal
{
    public:
        Animal();
        Animal(string, string); // ou bien fonction de saisir
        virtual void afficherAnimal()const;
        // 2 ///
        bool ajouterVaccin(string);
        //
        virtual ~Animal();

        string Getmatricule() const{ return matricule; }
        void Setmatricule(string val) { matricule = val; }
        string Getespece() const{ return espece; }
        void Setespece(string val) { espece = val; }
        vector <string> GetdatesVaccins() const { return datesVaccins; }
        void SetdatesVaccins(vector <string> val) { datesVaccins = val; }

    protected:
        string matricule;
        string espece;
        vector <string> datesVaccins;
};

#endif // ANIMAL_H
