#ifndef TICKETVIP_H
#define TICKETVIP_H

#include "Ticket.h"

class TicketVIP : public Ticket {
private:
    double pourcentageReduction;

public:
    TicketVIP(int numeroUnique, double prix, int numeroChaise, double pourcentageReduction);
    
    double getPourcentageReduction() const;
    void setPourcentageReduction(double pourcentageReduction);
};


#endif /* TICKETVIP_H */