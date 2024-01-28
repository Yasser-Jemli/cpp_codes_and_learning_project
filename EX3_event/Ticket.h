#ifndef TICKET_H
#define TICKET_H

class Ticket {
private:
    int numeroUnique;
    double prix;
    int numeroChaise;

public:
    Ticket(int numeroUnique, double prix, int numeroChaise);
    
    int getNumeroUnique() const;
    double getPrix() const;
    int getNumeroChaise() const;
    void setPrix(double prix);
    void setNumeroChaise(int numeroChaise);
};

#endif /* TICKET_H */