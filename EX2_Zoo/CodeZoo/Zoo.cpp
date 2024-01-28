#include "Zoo.h"

Zoo::Zoo()
{
    //ctor
    adresse="";
}
Zoo::Zoo(string adr)
{
    adresse=adr;
}
Zoo::~Zoo()
{
    //dtor
    for(vector<Animal*>::iterator it=lesAnimaux.begin(); it!=lesAnimaux.end(); it++)
        delete(*it);
}
Zoo::Zoo(const Zoo& zo)
{
    lesVeterinaires=zo.lesVeterinaires;
    Animal *p;

    vector< Animal*>::const_iterator i;
    for(i=zo.lesAnimaux.begin(); i!=zo.lesAnimaux.end(); i++)
    {
        if(typeid(**i)==typeid( Animal))
        {
            p=new  Animal (**i);
        }
        else
        {
            p=new Lion (static_cast<const Lion&>(**i));
        }

        lesAnimaux.push_back(p);

    }
}
Zoo& Zoo::operator=(const Zoo& zo)
{
    if(this!=&zo)
    {
        for(vector<Animal*>::iterator it=lesAnimaux.begin(); it!=lesAnimaux.end(); it++)
            delete(*it);
        lesAnimaux.clear();
        lesVeterinaires=zo.lesVeterinaires;
        Animal *p;

        vector< Animal*>::const_iterator i;
        for(i=zo.lesAnimaux.begin(); i!=zo.lesAnimaux.end(); i++)
        {
            if(typeid(**i)==typeid( Animal))
            {
                p=new  Animal (**i);
            }
            else
            {
                p=new Lion (static_cast<const Lion&>(**i));
            }

            lesAnimaux.push_back(p);

        }


    }
    return(*this);

}

void Zoo::afficherZoo()const
{

    cout<<"Zoo : "<<adresse<<endl;
    cout<<"liste des animaux: "<<endl;
    for(vector<Animal*>::const_iterator itAn=lesAnimaux.begin(); itAn!=lesAnimaux.end(); itAn++)
        (*itAn)->afficherAnimal();
    cout<<"liste des medecins veterinaires: "<<endl;
    for(vector<MedecinVeterinaire>::const_iterator itVt=lesVeterinaires.begin(); itVt!=lesVeterinaires.end(); itVt++)
        itVt->afficherVeterinaire();
}
//1//
vector<Animal*>::iterator Zoo::chercherAnimal(string matricule)
{
    for(vector<Animal*>::iterator it=lesAnimaux.begin(); it!=lesAnimaux.end(); it++)
    {
        if((*it)->Getmatricule()==matricule)
            return it;
    }
    return lesAnimaux.end();


}

bool Zoo::ajouter(const Animal& an)
{
    if(chercherAnimal(an.Getmatricule())==lesAnimaux.end())
    {
        Animal* p=new Animal(an);
        lesAnimaux.push_back(p);
        return true;
    }
    return false;

}
bool Zoo::ajouter(const Lion& ln)
{
    if(chercherAnimal(ln.Getmatricule())==lesAnimaux.end())
    {
        Animal* p=new Lion(ln);
        lesAnimaux.push_back(p);
        return true;
    }
    return false;

}
//2///
 bool Zoo::ajouterDateVaccinAnimal(string matricule, string date){
  vector<Animal*>::iterator itAn=chercherAnimal(matricule);
  if(itAn!=lesAnimaux.end())
   {
      (*itAn)->ajouterVaccin(date);
      return true;
   }

    cout<<"Animal n existe pas!"<<endl;
    return false;
 }

//3///
vector<MedecinVeterinaire>::iterator Zoo::chercherVeterinaire(int id)
{
    for(vector<MedecinVeterinaire>::iterator it=lesVeterinaires.begin(); it!=lesVeterinaires.end(); it++)
    {
        if((it)->GetidVeterinaire()==id)
            return it;
    }
    return lesVeterinaires.end();

}
bool Zoo::ajouter (const MedecinVeterinaire& vt)
{

    if(chercherVeterinaire(vt.GetidVeterinaire())==lesVeterinaires.end())
    {
        lesVeterinaires.push_back(vt);
        return true;
    }
    return false;
}

//4///
void Zoo::affecterAnimalVeterinaire(string matricule, int idVet)
{
    vector<MedecinVeterinaire>::iterator itVt=chercherVeterinaire(idVet);
    vector<Animal*>::iterator itAn=chercherAnimal(matricule);
    try
    {
        if(itVt!=lesVeterinaires.end() && itAn!=lesAnimaux.end()&& !itVt->verifierAnimal(matricule))
            itVt->ajouterMatriculeAnimal(matricule);
        else
            throw string("Animal ou Veterinaire inexistant ou bien animal deja affecte au veterinaire\n");

    }
    catch (string const& ch)
    {
        cerr<<ch<<endl;
    }

}
// 5///

void Zoo::afficherAnimauxVeterinaires(int id)
{
    vector<MedecinVeterinaire>::iterator itVt=chercherVeterinaire(id);
    if(itVt!=lesVeterinaires.end())
    {
        for(vector<Animal*>::iterator itAn=lesAnimaux.begin(); itAn!=lesAnimaux.end(); itAn++)
        {
            if(itVt->verifierAnimal( (**itAn).Getmatricule()))
                (**itAn).afficherAnimal();
        }

    }
    else
        cout<<"Veterinaire n existe pas!!"<<endl;
}
// 6///
int Zoo::totalAnimauxEnCharge()
{
    MedecinVeterinaire vtr;

    for(vector<MedecinVeterinaire>::iterator itVt=lesVeterinaires.begin(); itVt!=lesVeterinaires.end(); itVt++)
    {
        vtr+=(*itVt);

    }

    return vtr.GetmatriculesAnimaux().size();

}

void Zoo::enregistrerLions(int seuil)
{

    ofstream fichier("Lions.txt");
    if(fichier)
    {
        for(vector<Animal*>::iterator itAn=lesAnimaux.begin(); itAn!=lesAnimaux.end(); itAn++)
        {
            if(typeid(**itAn)==typeid(Lion))
            {
                Lion *ln = (Lion*)(*itAn);
                if(ln->GetquanttViande()>seuil)
                {
                    fichier<<"lion: "<<ln->Getmatricule()<<","<<ln->Getespece()<<","<<ln->GetquanttViande()<<'\n';
                    fichier<<"les dates des vaccins:"<<'\n';
                    for(unsigned i=0;i<ln->GetdatesVaccins().size();i++)
                        fichier<<ln->GetdatesVaccins()[i]<<'\n';

                }
            }


        }
        cout<<"enregistrement terminé"<<endl;
        fichier.close();
    }
    else
        cout<<"erreur d'ouverture "<<endl;
}
