#include "MedecinVeterinaire.h"

MedecinVeterinaire::MedecinVeterinaire()
{
    //ctor
    idVeterinaire=0;
    nom="";
    prenom="";
}
MedecinVeterinaire::MedecinVeterinaire(int id, string n, string p)
{

    idVeterinaire=id;
    nom=n;
    prenom=p;
}
void MedecinVeterinaire::afficherVeterinaire()const
{
    cout<<"Veterinaire: "<<idVeterinaire<<" , "<<nom<<" , "<<prenom<<endl;
    cout<<"Les matricules des animaux: "<<endl;
    for(unsigned i=0; i<matriculesAnimaux.size(); i++)
        cout<<"matricule animal "<<i+1<<" : "<<matriculesAnimaux[i]<<endl;
}

bool MedecinVeterinaire::verifierAnimal(string matricule)
{
    for(unsigned i=0; i<matriculesAnimaux.size(); i++)
    {
        if(matriculesAnimaux[i]==matricule)
        {
            return true;
        }
    }
    return false;
}

bool MedecinVeterinaire::ajouterMatriculeAnimal(string matricule)
{
    if(!verifierAnimal(matricule))  //v�rification optionnel, elle s'effectue dans Zoo.
    {
        matriculesAnimaux.push_back(matricule);
        return true;
    }
    return false;

}
MedecinVeterinaire& MedecinVeterinaire::operator+=(const MedecinVeterinaire& vt)
{
    for(unsigned i=0; i<vt.matriculesAnimaux.size(); i++)
        matriculesAnimaux.push_back(vt.matriculesAnimaux[i]);
    return(*this);

}

MedecinVeterinaire::~MedecinVeterinaire()
{
    //dtor
}
