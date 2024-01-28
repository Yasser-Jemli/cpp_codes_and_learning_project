#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <string>
#include <vector>
#include "Salle.h"

class Evenement {
private:
    std::string nom;
    std::vector<Salle> salles;

public:
    Evenement(const std::string& nom);
    ~Evenement();
    Evenement(const Evenement& other);
    Evenement& operator=(const Evenement& other);
    
    const std::string& getNom() const;
    const std::vector<Salle>& getSalles() const;
    
    void ajouterSalle(const Salle& salle);
    void affecterTicket(int numeroSalle, Ticket* ticket);
    double calculerRevenue() const;
    int sallePlusRemplie() const;
    void enregistrerTicketsVIP(int numeroSalle, const std::string& nomFichier) const;
};

#endif /* EVENEMENT_H */