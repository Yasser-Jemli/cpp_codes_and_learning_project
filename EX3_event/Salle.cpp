#include "Salle.h"

// ctor
Salle::Salle(int numeroUnique, int capacite)
    : numeroUnique(numeroUnique), capacite(capacite) {}

//dtor
Salle::~Salle() {
    for (Ticket* ticket : tickets) {
        delete ticket;
    }
}

Salle::Salle(const Salle& other)
    : numeroUnique(other.numeroUnique), capacite(other.capacite) {
    for (Ticket* ticket : other.tickets) {
        tickets.push_back(new Ticket(*ticket));
    }
}

Salle& Salle::operator=(const Salle& other) {
    if (this != &other) {
        numeroUnique = other.numeroUnique;
        capacite = other.capacite;

        for (Ticket* ticket : tickets) {
            delete ticket;
        }
        tickets.clear();

        for (Ticket* ticket : other.tickets) {
            tickets.push_back(new Ticket(*ticket));
        }
    }
    return *this;
}

int Salle::getNumeroUnique() const {
    return numeroUnique;
    
}

int Salle::getCapacite() const {
    return capacite;
}

const std::vector<Ticket*>& Salle::getTickets() const {
    return tickets;
}

void Salle::ajouterTicket(Ticket* ticket) {
    if (tickets.size() >= capacite) {
        throw std::runtime_error("La salle est pleine.");
    }
    tickets.push_back(ticket);
}

 for(vector<string>::iterator it=datesVaccins.begin(); it!=datesVaccins.end(); it++)
    {
        if((*it)==date)
        {
            cout<<"NUmero du salle est est existe deja !!"<<endl;
            return false;
        }
    }

        datesVaccins.push_back(date);
        cout<<"Numero du salle est ajoute Clairement"<<endl;
        
        return true;
}
