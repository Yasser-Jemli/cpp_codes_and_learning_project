#include "evenement.h"
#include <algorithm>
#include <fstream>

Evenement::Evenement(const std::string& nom)
    : nom(nom) {}

Evenement::~Evenement() {}

Evenement::Evenement(const Evenement& other)
    : nom(other.nom), salles(other.salles) {}

Evenement& Evenement::operator=(const Evenement& other) {
    if (this != &other) {
        nom = other.nom;
        salles = other.salles;
    }
    return *this;
}

const std::string& Evenement::getNom() const {
    return nom;
}

const std::vector<Salle>& Evenement::getSalles() const {
    return salles;
}

void Evenement::ajouterSalle(const Salle& salle) {
    for (const Salle& existingSalle : salles) {
        if (existingSalle.getNumeroUnique() == salle.getNumeroUnique()) {
            throw std::runtime_error("Le numéro de salle existe déjà.");
        }
    }
    salles.push_back(salle);
}

void Evenement::affecterTicket(int numeroSalle, Ticket* ticket) {
    Salle* salle = nullptr;
    for (Salle& existingSalle : salles) {
        if (existingSalle.getNumeroUnique() == numeroSalle) {
            salle = &existingSalle;
            break;
        }
    }

    if (salle == nullptr) {
        throw std::runtime_error("Le numéro de salle n'existe pas.");
    }

    salle->ajouterTicket(ticket);
}

double Evenement::calculerRevenue() const {
    double revenue = 0.0;
    for (const Salle& salle : salles) {
        for (const Ticket* ticket : salle.getTickets()) {
            revenue += ticket->getPrix();
        }
    }
    return revenue;
}

int Evenement::sallePlusRemplie() const {
    int maxCapacite = 0;
    int sallePlusRemplie = -1;

    for (const Salle& salle : salles) {
        if (salle.getCapacite() > maxCapacite) {
            maxCapacite = salle.getCapacite();
            sallePlusRemplie = salle.getNumeroUnique();
        }
    }

    return sallePlusRemplie;
}

void Evenement::enregistrerTicketsVIP(int numeroSalle, const std::string& nomFichier) const {
    std::ofstream fichier(nomFichier);
    for (const Salle& salle : salles) {
        if (salle.getNumeroUnique() == numeroSalle) {
            for (const Ticket* ticket : salle.getTickets()) {
                if (dynamic_cast<const TicketVIP*>(ticket) != nullptr) {
                    fichier << ticket->getNumeroUnique() << std::endl;
                }
            }
            return;
        }
    }

    throw std::runtime_error("Le numéro de salle n'existe pas.");
}