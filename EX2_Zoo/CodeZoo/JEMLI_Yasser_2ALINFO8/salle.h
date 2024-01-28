#ifndef SALLE_H
#define SALLE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Salle
{
    public:
        salle();
        salle(int,string,string);
        void afficherSalle()const;

        bool verifierSalle(string);
        bool ajouterMatriculeSalle(string);
        MedecinVeterinaire& operator+=(const MedecinVeterinaire&);

        ~salle();

        string GetnumeroSalle()const { return numeroSalle; }
        void SetnumeroSalle(int val) { numeroSalle = val; }
        string GetCapaciteSalle() { return CapaciteSalle; }
        void SetCapaciteSalle(string val) { CapaciteSalle = val; }
        string Getensembles_des_tickets_affectes() { return ensembles_des_tickets_affectes; }
        void Setensembles_des_tickets_affectes(string val) { ensembles_des_tickets_affectes = val; }
        vector<string> GetmatriculesAnimaux() { return matriculesAnimaux; }
        void SetmatriculesAnimaux(vector<string> val) { matriculesAnimaux = val; }

    protected:

    private:
        string numeroSalle;
        string CapaciteSalle;
        string ensembles_des_tickets_affectes;
};

#endif // SALLE_H
