#include "Ticket.h"

Ticket::Ticket(int numeroUnique, double prix, int numeroChaise)
    : numeroUnique(numeroUnique), prix(prix), numeroChaise(numeroChaise) {}

int Ticket::getNumeroUnique() const {
    return numeroUnique;
}

double Ticket::getPrix() const {
    return prix;
}

int Ticket::getNumeroChaise() const {
    return numeroChaise;
}

void Ticket::setPrix(double prix) {
    this->prix = prix;
}

void Ticket::setNumeroChaise(int numeroChaise) {
    this->numeroChaise = numeroChaise;
}