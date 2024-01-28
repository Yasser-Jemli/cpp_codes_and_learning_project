#include "TicketVIP.h"

TicketVIP::TicketVIP()
{
    //ctor
    pourcentageDuReduction=0;
}
TicketVIP::TicketVIP(string numero_ticket, string prix_ticket, string numero_du_chaise ,float pourcentageDuReduction):Ticket(numero_ticket,prix_ticket,numero_du_chaise)
{
    this->pourcentageDuReduction=pourcentageDuReduction;

}
void TicketVIP::afficherTicket()const
{
    Ticket::afficherTicket();
    cout<<"Le pourcentage du reduction Pour cette Ticket VIP es : "<<pourcentageDuReduction<<endl;

}

TicketVIP::~TicketVIP()
{
    //dtor
}
