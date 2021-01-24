
#include "Toll.h"
#include <iostream>

using namespace std;

Toll::Toll(string name, string geolocal, float highway_kilometer, bool type) : name(name), geolocal(geolocal), highway_kilometer(highway_kilometer),type(type) {
    lanes.clear();
}

Toll::Toll(){
    name="";
    geolocal="";
    highway_kilometer=0;
    type=true;
}

string Toll::getName() const {return name;}

bool Toll::getType() const {return type;}

string Toll::getGeolocal() const {return geolocal;}

float Toll::getKilometer() const {return highway_kilometer;}

string Toll::getInfo() const {
    return name + " - " + geolocal + " - " + to_string(highway_kilometer) + " - " + to_string(type);
}

Lane * Toll::getLane(int i) {
    if (i < lanes.size())
        return lanes[i];
    return nullptr;
}

int Toll::getNumLanes() const {return lanes.size();}

string Toll::showToll() const {
    string s_type = type ? "Exit" : "Entrance";
    return "Toll Name: " + name + " - Geographic Location: " + geolocal + " - Highway Kilometer: " + to_string(highway_kilometer) + " - Type: " + s_type;
}

void Toll::setType(bool type) {this->type = type;}

void Toll::setName(string name) {this->name = name;}

void Toll::setGeolocal(string geolocal) {this->geolocal = geolocal;}

void Toll::setKilometer(float kilometer) {this->highway_kilometer = kilometer;}

void Toll::setGreenLaneTrue(Lane * lane) {
    int index = lane->getLaneNumber();
    lanes.erase(lanes.begin() + index);
    auto *l1 = new Lane(index, true);
    lanes.insert(lanes.begin()+index,l1);
    for (size_t i = 0; i < lanes.size(); i++)
        lanes[i]->setLaneNumber(i);
}

void Toll::setGreenLaneFalse(Lane *lane, Employee *e) {
    int index = lane->getLaneNumber();
    lanes.erase(lanes.begin()+index);
    auto *l1 = new LaneEmployee(index,false,e);
    lanes.insert(lanes.begin()+index, l1);
    for (size_t i = 0; i < lanes.size(); i++)
        lanes[i]->setLaneNumber(i);
}

bool Toll::removeLane(int i) {
    bool check = false;
    if (i < lanes.size()) {
        lanes.erase(lanes.begin() + i);
        check= true;
    }
    if (!check)
        return false;
    for (size_t i = 0; i < lanes.size(); i++) {
        lanes[i]->setLaneNumber(i);
    }
    return true;
}

bool Toll::operator==(const Toll& l2) const {
    return name == l2.getName() && geolocal == l2.getGeolocal() && highway_kilometer == l2.getKilometer() && type == l2.getType();
}

void Toll::addLane(Lane * l){
    lanes.push_back(l);
}

bool Toll::checkTechnicianName(string name) {
    priority_queue<Technician*, vector<Technician*>, MyCompare> p = technicians;
    while(!p.empty()) {
        if (p.top()->getName() == name)
            return false;
        p.pop();
    }
    return true;
}

bool Toll::addTechnician(string name, string specialty) {
    technicians.push(new Technician(name,specialty));
    return true;
}

bool Toll::addTechnician(Technician* technician) {
    technicians.push(technician);
    return true;
}

vector<string> Toll::readTechnicians() {
    vector<string> techs;
    priority_queue<Technician*, vector<Technician*>, MyCompare> p = technicians;
    while(!p.empty()) {
        techs.push_back(p.top()->showTechnician());
        p.pop();
    }
    return techs;
}

vector<string> Toll::readTechniciansv2() {
    vector<string> techs;
    priority_queue<Technician*, vector<Technician*>, MyCompare> p = technicians;
    while(!p.empty()) {
        techs.push_back(p.top()->getInfo());
        p.pop();
    }
    return techs;
}

Technician* Toll::getTechnicianName(string name) {
    priority_queue<Technician*, vector<Technician*>, MyCompare> p = technicians;
    Technician a("","");
    while (!p.empty()) {
        if (p.top()->getName() == name)
            return p.top();
        p.pop();
    }
    return nullptr;
}

Technician* Toll::getTechnicianSpeciality(string speciality) {
    priority_queue<Technician*, vector<Technician*>, MyCompare> p = technicians;
    Technician a("","");
    while (!p.empty()) {
        if (technicians.top()->getSpecialty() == speciality)
            return technicians.top();
        p.pop();
    }
    return nullptr;
}

bool Toll::deleteTechnician(string name) {
    bool check = false;
    priority_queue<Technician*, vector<Technician*>, MyCompare> p;
    while (!technicians.empty()) {
        if (technicians.top()->getName() != name)
            p.push(technicians.top());
        else check = true;
        technicians.pop();
    }
    technicians = p;
    if (check)
        return true;
    return false;
}


TollEntrance::TollEntrance(string name, string geolocal, float highway_kilometer) : Toll(name,geolocal,highway_kilometer,false) {}

void TollEntrance::addLane() {
    int n_lane = lanes.size();
    auto *l1 = new Lane(n_lane, false);
    lanes.push_back(l1);
}

void TollEntrance::addLane(Lane * l) {
    lanes.push_back(l);
}



TollOut::TollOut(string name, string geolocal, float highway_kilometer) : Toll(name,geolocal,highway_kilometer,true) {}

void TollOut::addLane() {
    int n_lane = lanes.size();
    auto *l1 = new Lane(n_lane, true);
    lanes.push_back(l1);
}

void TollOut::addLane(Employee *e) {
    int n_lane = lanes.size();
    auto *l1 = new LaneEmployee(n_lane, false, e);
    lanes.push_back(l1);
}

void TollOut::addLane(Lane * l) {
    Toll::addLane(l);
}




