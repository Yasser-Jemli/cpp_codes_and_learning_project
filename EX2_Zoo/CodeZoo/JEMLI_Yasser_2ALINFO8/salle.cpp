#include "salle.h"

salle::salle()
{
    //ctor
    numeroSalle="";
    CapaciteSalle="";
    ensembles_des_tickets_affectes="";
}
salle::salle(string n, string c, string e)
{

    numeroSalle=n;
    CapaciteSalle=c;
    ensembles_des_tickets_affectes=p;
}
void salle::afficherSalle()const
{
    cout<<"La Numero Du Salle est : "<<numeroSalle<<endl;
    cout<<"La  capacite du la salle est : "<<CapaciteSalle<<endl;
    cout<<"L'ensemble des ticket affectes a cette salle est : "<<ensembles_des_tickets_affectes<<endl;
   
}

bool salle::verifierNumeroSAlle(string numeroSalle)
{
    for(unsigned i=0; i<lesNumDesSalles.size(); i++)
    {
        if(lesNumDesSalles[i]==numeroSalle)
        {
            cout<<"La numero du salle est exite deja !! verifie la numero stp !"<<endl;
            return fasle;
        }
    }
    cout("La numero du salle est unique !")<<endl;
    return true;
}

bool Salle::ajouterNumeroDuSalle(string numeroSalle)
{
    if(!verifierNumeroSAlle(numeroSalle))  //v�rification optionnel, elle s'effectue dans Zoo.
    {
        lesNumDesSalles.push_back(numeroSalle);
        return true;
    }
    return false;

}

salle::~salle()
{
    //dtor
}
