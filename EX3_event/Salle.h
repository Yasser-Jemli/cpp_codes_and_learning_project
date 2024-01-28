#ifndef SALLE_H
#define SALLE_H

#include <vector>
#include "Ticket.h"

class Salle {
// les attributs des classes a definir ne doivent pas etre publics 
private:
    int numeroUnique;
    int capacite;
    std::vector<Ticket*> tickets;

public:
    Salle(int numeroUnique, int capacite);
    ~Salle();
    Salle(const Salle& other);
    Salle& operator=(const Salle& other);
    
    int getNumeroUnique() const;
    int getCapacite() const;
    const std::vector<Ticket*>& getTickets() const;
    
    void ajouterTicket(Ticket* ticket);
};

#endif /* SALLE_H */