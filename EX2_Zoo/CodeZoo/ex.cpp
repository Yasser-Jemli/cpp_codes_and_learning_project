#include <iostream>
#include <string>
#include <vector>

// Animal class
class Animal {
public:
    std::string name;
    std::string species;
    std::string vaccineDate;

    Animal(std::string name, std::string species) : name(name), species(species) {}

    void setVaccineDate(std::string date) {
        vaccineDate = date;
    }
};

// Zoo class
class Zoo {
private:
    std::vector<Animal> animals;

public:
    void insertAnimal(const Animal& animal) {
        animals.push_back(animal);
    }

    void displayAnimals() {
        for (const auto& animal : animals) {
            std::cout << "Name: " << animal.name << ", Species: " << animal.species;
            if (!animal.vaccineDate.empty()) {
                std::cout << ", Last Vaccine Date: " << animal.vaccineDate;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Zoo myZoo;

    // Inserting a new animal
    Animal lion("Leo", "Lion");
    lion.setVaccineDate("2023-12-31");
    myZoo.insertAnimal(lion);

    // Displaying animals
    myZoo.displayAnimals();

    return 0;
}

*******************************************************************************************
#include <iostream>
#include <string>
#include <vector>

// Animal class
class Animal {
public:
    std::string name;
    std::string species;
    std::string vaccineDate;
    int weight;

    Animal(std::string name, std::string species, int weight) : name(name), species(species), weight(weight) {}

    void setVaccineDate(std::string date) {
        vaccineDate = date;
    }

    void setWeight(int weight) {
        this->weight = weight;
    }

    void displayInfo() {
        std::cout << "Name: " << name << ", Species: " << species;
        std::cout << ", Weight: " << weight;
        if (!vaccineDate.empty()) {
            std::cout << ", Last Vaccine Date: " << vaccineDate;
        }
        std::cout << std::endl;
    }
};

// Zoo class
class Zoo {
private:
    std::vector<Animal> animals;

public:
    void insertAnimal(const Animal& animal) {
        animals.push_back(animal);
    }

    void displayAnimals() {
        for (const auto& animal : animals) {
            animal.displayInfo();
        }
    }

    void updateVaccineDate(int index, std::string newDate) {
        if (index >= 0 && index < animals.size()) {
            animals[index].setVaccineDate(newDate);
        }
    }

    void updateWeight(int index, int newWeight) {
        if (index >= 0 && index < animals.size()) {
            animals[index].setWeight(newWeight);
        }
    }
};

int main() {
    Zoo myZoo;

    // Inserting a new animal
    Animal lion("Leo", "Lion", 150);
    myZoo.insertAnimal(lion);

    // Updating the vaccine date
    myZoo.updateVaccineDate(0, "2023-12-31");

    // Updating the weight
    myZoo.updateWeight(0, 160);

    // Displaying animals
    myZoo.displayAnimals();

    return 0;
}
