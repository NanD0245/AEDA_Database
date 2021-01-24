#include "HighwayRecord.h"

HighwayRecord::HighwayRecord() {highways.clear();}

int HighwayRecord::getNumHighways() const {return highways.size();}

Highway * HighwayRecord::getHighway(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getInfo())
            return highways[i];
    }
    return nullptr;
}

Highway * HighwayRecord::getHighwayIndex(int i) {
    if (i < highways.size())
        return highways[i];
    return nullptr;
}

bool HighwayRecord::checkHighwayName(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getInfo())
            return true;
    }
    return false;
}

bool HighwayRecord::addHighway(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getInfo())
            return false;
    }
    auto *a1 = new Highway(name);
    highways.push_back(a1);
    return true;
}

void HighwayRecord::addHighway(Highway * h){
    highways.push_back(h);
}

bool HighwayRecord::removeHighway(int i) {
    if (i >= highways.size())
        return false;
    highways.erase(highways.begin()+i);
    return true;
}

bool HighwayRecord::checkTechnicianName(string name) {
    for (Highway* h :highways) {
        if (!h->checkTechnicianName(name))
            return false;
    }
    return true;
}