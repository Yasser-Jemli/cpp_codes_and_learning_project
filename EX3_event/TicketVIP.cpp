#include "TicketVIP.h"

TicketVIP::TicketVIP(int numeroUnique, double prix, int numeroChaise, double pourcentageReduction)
    : Ticket(numeroUnique, prix, numeroChaise), pourcentageReduction(pourcentageReduction) {}

double TicketVIP::getPourcentageReduction() const {
    return pourcentageReduction;
}

void TicketVIP::setPourcentageReduction(double pourcentageReduction) {
    this->pourcentageReduction = pourcentageReduction;
}