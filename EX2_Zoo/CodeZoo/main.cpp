#include <iostream>
#include "Zoo.h"
using namespace std;

int main()
{

    Animal A1("A001","carnivore");
    Animal A2("A002","herbivore");
    Animal A3("A002","herbivore");
    ///
    Lion L1("L003","carnivore",3.5);
    Lion L2("L004","carnivore",4.5);
    ///
    MedecinVeterinaire V1(123,"ali", "bel ali");
    MedecinVeterinaire V2(123,"ali", "bel ali");
    MedecinVeterinaire V3(124,"ali", "bel ali");
    ///
    cout<<"*******************Ajout dans ZOO**********************"<<endl;
    Zoo Zo("Belvidaire");
    Zo.ajouter(A1);
    Zo.ajouter(A2);
    Zo.ajouter(A3);
    Zo.ajouter(L1);
    Zo.ajouter(L2);
    Zo.ajouter(V1);
    Zo.ajouter(V2);
    Zo.ajouter(V3);
    cout<<"******************Ajout des vaccins ************************"<<endl;
    Zo.ajouterDateVaccinAnimal("A001", "22/01/2019");
     Zo.ajouterDateVaccinAnimal("A001","22/01/2019");
     Zo.ajouterDateVaccinAnimal("A001","22/01/2020");
    Zo.ajouterDateVaccinAnimal("A002","22/03/2018");
     Zo.ajouterDateVaccinAnimal("L003","22/03/2017");
     Zo.ajouterDateVaccinAnimal("L003","22/03/2016");
    Zo.ajouterDateVaccinAnimal("L004","22/03/2018");
   Zo.ajouterDateVaccinAnimal("L004","22/04/2018");
    cout<<"********************affecter animaux aux veterinaires ********************"<<endl;
    Zo.affecterAnimalVeterinaire("A001",123);
    cout<<"***************************************************"<<endl;
    Zo.affecterAnimalVeterinaire("A002",123);
    cout<<"***************************************************"<<endl;
    //lever exception.... animal inexistant
    Zo.affecterAnimalVeterinaire("L001",123);
     cout<<"***************************************************"<<endl;
    Zo.affecterAnimalVeterinaire("L003",123);
     cout<<"***************************************************"<<endl;
    Zo.affecterAnimalVeterinaire("L004",124);
     cout<<"****************afficher ZOO ************************"<<endl;
    ///
    Zo.afficherZoo();
     cout<<"*************affichage animaux par veterinaire ***********************"<<endl;
    ///
    Zo.afficherAnimauxVeterinaires(123);
     cout<<"***************************************************"<<endl;
    ///
    cout<<"Nombre total des animaux pris en charge: "<<Zo.totalAnimauxEnCharge()<<endl;
     cout<<"***************************************************"<<endl;
    ///
    Zo.enregistrerLions(4);
     cout<<"***************************************************"<<endl;


    return 0;
}
