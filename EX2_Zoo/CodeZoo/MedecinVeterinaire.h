#ifndef MEDECINVETERINAIRE_H
#define MEDECINVETERINAIRE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MedecinVeterinaire
{
    public:
        MedecinVeterinaire();
        MedecinVeterinaire(int,string,string);
        void afficherVeterinaire()const;

        bool verifierAnimal(string);
        bool ajouterMatriculeAnimal(string);
        MedecinVeterinaire& operator+=(const MedecinVeterinaire&);

        ~MedecinVeterinaire();

         int GetidVeterinaire()const { return idVeterinaire; }
        void SetidVeterinaire(int val) { idVeterinaire = val; }
        string Getnom() { return nom; }
        void Setnom(string val) { nom = val; }
        string Getprenom() { return prenom; }
        void Setprenom(string val) { prenom = val; }
        vector<string> GetmatriculesAnimaux() { return matriculesAnimaux; }
        void SetmatriculesAnimaux(vector<string> val) { matriculesAnimaux = val; }

    protected:

    private:
        int idVeterinaire;
        string nom;
        string prenom;
        vector<string> matriculesAnimaux;
};

#endif // MEDECINVETERINAIRE_H
