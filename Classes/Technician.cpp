//
// Created by mim on 15/12/20.
//

#include "Technician.h"

Technician::Technician(string name, string specialty) : name(name), specialty(specialty) {
    performance = 0;
    num_intervetion = 0;
}

string Technician::getName() const {return name; }

void Technician::setName(string name) {this->name = name; }

string Technician::getSpecialty() const {return specialty; }

void Technician::setSpecialty(string specialty) {this->specialty = specialty; }

float Technician::getPerformance() const {return performance; }

void Technician::setPerformance(float performance) {this->performance = performance; }

int Technician::getNumIntervetion() const {return num_intervetion; }

void Technician::addIntervention() {num_intervetion++; }

void Technician::setIntervention(int num) {num_intervetion = num; }

bool Technician::operator<(const Technician& t1) const {
    return performance > t1.getPerformance();
}

string Technician::getInfo() const {return name + " - " + specialty + " - " + to_string(performance) + " - " + to_string(num_intervetion); }

string Technician::showTechnician() const {
    return "Name: " + name + " - " + "Specialty: " + specialty + " - " + "Performance: " + to_string(performance)
                                        + " - " + "Number of Interventions: " + to_string(num_intervetion);
}

