#include "Ticket.h"

Ticket::Ticket()
{
    //ctor
    numero_ticket="";
    prix_ticket="";
    numero_du_chaise="";
}
Ticket::Ticekt(string numero_ticket, string prix_ticket , string numero_du_chaise)
{
    this->numero_ticket=numero_ticket;
    this->prix_ticket=prix_ticket;
    this->numero_du_chaise=numero_du_chaise

}
Ticket::~Ticekt()
{
    //dtor
}
void Ticket::afficherTicket()const
{
    cout<<"le numero du ticekt est :  "<<numero_ticket<<" le prix est: "<<prix_ticket<<endl;
    cout<<"Le numero du chaise est : "<<numero_du_chaise<<endl;

}

bool Ticket::ajouterNumeroDuTicket(string numero_ticket)
{
    //verfification de l'unicite de numero !
    for(vector<string>::iterator it=numero_tickets.begin(); it!=numero_tickets.end(); it++)
    {
        if((*it)==numero_ticket)
        {
            cout<<"Numero Du Ticket est existe Deja!!"<<endl;
            cout<<"Tu dois ajouter un autre numero !!"<<endl;
            return false;
        }
    }

        numero_tickets.push_back(numero_ticket);
        cout<<"La numero Du ticket est ajoute avec success !! "<<endl;
        return true;
}


