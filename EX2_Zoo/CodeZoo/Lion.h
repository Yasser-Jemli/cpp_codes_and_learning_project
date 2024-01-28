#ifndef LION_H
#define LION_H

#include "Animal.h"


class Lion : public Animal
{
    public:
        Lion();
        Lion(string, string, float); // ou fonction de saisie
        void afficherAnimal()const;
        ~Lion();

        float GetquanttViande() const{ return quanttViande; }
        void SetquanttViande(float val) { quanttViande = val; }


    protected:

    private:
        float quanttViande;
};

#endif // LION_H
