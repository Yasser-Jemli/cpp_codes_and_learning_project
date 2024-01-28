#include <iostream>
#include "evenement.h"
#include "Ticket.h"
#include "TicketVIP.h"

int main() {
    // Création d'un événement
    Evenement concert("Concert");

    // Création de salles
    Salle salle1(101, 300);
    Salle salle2(102, 400);

    // Ajout des salles à l'événement
    concert.ajouterSalle(salle1);
    concert.ajouterSalle(salle2);

    // Création de tickets
    Ticket ticket1(1, 60.0, 10);
    TicketVIP ticket2(2, 80.0, 20, 10.0);

    // Affectation des tickets aux salles
    concert.affecterTicket(1, &ticket1);
    concert.affecterTicket(2, &ticket2);

    // Calcul du revenu total de l'événement
    double revenuTotal = concert.calculerRevenue();
    std::cout << "Revenu total de l'evenement : " << revenuTotal << std::endl;

    // Identification de la salle la plus remplie
    int salleRemplie = concert.sallePlusRemplie();
    std::cout << "Salle la plus remplie : " << salleRemplie << std::endl;

    // Enregistrement des tickets VIP dans un fichier
    try {
        concert.enregistrerTicketsVIP(2, "tickets_vip.txt");
        std::cout << "Les tickets VIP de la salle 2 ont ete enregistres dans le fichier 'tickets_vip.txt'." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}