#ifndef TICKETVIP_H
#define TICKETVIP_H

#include "Ticket.h"


class TicketVIP : public Ticket
{
    public:
        TicketVIP();
        TicketVIP(string, string, float); // ou fonction de saisie
        void afficherTicket()const;
        ~TicketVIP();

        float GetpourcentageDuReduction() const{ return pourcentageDuReduction; }
        void SetpourcentageDuReduction(float val) { pourcentageDuReduction = val; }


    protected:

    private:
        float pourcentageDuReduction;
};

#endif // TICKETVIP_H
