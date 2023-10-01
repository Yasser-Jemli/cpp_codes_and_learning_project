#include <iostream>
#include <string>

class Etudiant {
private:
    std::string nom;
    std::string prenom;
    double tab_notes[5]; // Nous supposerons que l'étudiant a 5 notes.

public:
    // Constructeur par défaut
    Etudiant() {
        nom = "";
        prenom = "";
        for (int i = 0; i < 5; i++) {
            tab_notes[i] = 0.0;
        }
    }

    // Méthode pour saisir les informations de l'étudiant
    void saisir() {
        std::cout << "Entrez le nom de l'etudiant : ";
        std::cin >> nom;

        std::cout << "Entrez le prenom de l'etudiant : ";
        std::cin >> prenom;

        std::cout << "Entrez les 5 notes de l'etudiant : ";
        for (int i = 0; i < 5; i++) {
            std::cin >> tab_notes[i];
        }
    }

    // Méthode pour calculer la moyenne des notes de l'étudiant
    float calculerMoyenne() {
        float somme = 0.0;
        for (int i = 0; i < 5; i++) {
            somme += tab_notes[i];
        }
        return somme / 5.0;
    }

    // Méthode pour déterminer si l'étudiant est admis
    bool estAdmis() {
        return calculerMoyenne() >= 10.0; // Supposons que la note minimale pour être admis est 10.0
    }

    // Méthode pour afficher les informations de l'étudiant
    void afficher() {
        std::cout << "Nom : " << nom << std::endl;
        std::cout << "Prenom : " << prenom << std::endl;
        std::cout << "Notes : ";
        for (int i = 0; i < 5; i++) {
            std::cout << tab_notes[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Moyenne : " << calculerMoyenne() << std::endl;
        std::cout << "Admis : " << (estAdmis() ? "Oui" : "Non") << std::endl;
    }
};

int main() {
    Etudiant etudiant;
    
    // Saisie des informations de l'étudiant
    etudiant.saisir();

    // Affichage des informations de l'étudiant
    etudiant.afficher();
    
    return 0;
}
