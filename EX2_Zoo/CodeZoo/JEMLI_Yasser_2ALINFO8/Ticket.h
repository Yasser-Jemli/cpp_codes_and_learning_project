#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ticket
{
    public:
        Ticket();
        Ticket(string, string, string); 
        virtual void afficherTicket()const;

        bool ajouterNumeroDuTicket(string)
        
        virtual ~Ticket();

        string Getnumero_du_chaise() const{ return numero_du_chaise; }
        void Setnumero_du_chaise(string val) { numero_du_chaise = val; }
        string Getprix_ticket() const{ return prix_ticket; }
        void Setprix_ticket(string val) { prix_ticket = val; }
        vector <string> Getnumero_ticket() const { return numero_ticket; }
        void Setnumero_ticket(vector <string> val) { numero_ticket = val; }

    protected:
        string numero_du_chaise;
        string prix_ticket;
        vector <string> numero_ticket;
};

#endif 