#ifndef ZOO_H
#define ZOO_H
#include "MedecinVeterinaire.h"
#include "Animal.h"
#include "Lion.h"
#include <typeinfo>
#include <fstream>
class Zoo
{
    public:
        Zoo();
        Zoo(string);
        //////////////
        ~Zoo();
        Zoo(const Zoo&);
        Zoo& operator=(const Zoo&);
        void afficherZoo()const;
        //1//////
        vector<Animal*>::iterator chercherAnimal(string);
        bool ajouter(const Animal&);
        bool ajouter (const Lion&);
        //2 ////
        bool ajouterDateVaccinAnimal(string matricule, string date);
        // 3///
        vector<MedecinVeterinaire>::iterator chercherVeterinaire(int);
         bool ajouter (const MedecinVeterinaire&);
         // 4///
         void affecterAnimalVeterinaire(string, int);
         //5 ///
         void afficherAnimauxVeterinaires(int id);

        // 6///
        int totalAnimauxEnCharge();
        // 7 ///
        void enregistrerLions(int seuil); // seuil peut être demandé dans la fonction


        string Getadresse() { return adresse; }
        void Setadresse(string val) { adresse = val; }
        vector<Animal*> GetlesAnimaux() { return lesAnimaux; }
        void SetlesAnimaux(vector<Animal*> val) { lesAnimaux = val; }
        vector<MedecinVeterinaire> GetlesVeterinaires() { return lesVeterinaires; }
        void SetlesVeterinaires(vector<MedecinVeterinaire> val) { lesVeterinaires = val; }

    protected:

    private:
        string adresse;
        vector<Animal*> lesAnimaux;
        vector<MedecinVeterinaire> lesVeterinaires;
};

#endif // ZOO_H
