//
// Created by mim on 15/12/20.
//

#include "InterventionRecord.h"
#include "Utils.h"

InterventionRecord::InterventionRecord() : interventions(Intervention("", new Highway(""), new Toll("","",0,0), new Date(0,0,0),new Date(0,0,0),new Technician("",""),0,false)) {}

bool InterventionRecord::addIntervention(const Intervention& i1) {
    return interventions.insert(i1);
}

bool InterventionRecord::removeIntervention(const Intervention& i1) {
    return interventions.remove(i1);
}

vector<string> InterventionRecord::showInterventions() {
    vector<string> v;
    for (auto it = BSTItrIn<Intervention>(interventions); !it.isAtEnd(); it.advance()){
        Intervention i = it.retrieve();
        string s = i.showIntervention();
        v.push_back(s);
    }
    return v;
}

vector<string> InterventionRecord::showInterventionsNotConcluded() {
    vector<string> v;
    for (auto it = BSTItrIn<Intervention>(interventions); !it.isAtEnd(); it.advance()){
        if (!it.retrieve().getState()) {
            Intervention i = it.retrieve();
            string s = i.showIntervention();
            v.push_back(s);
        }
    }
    return v;
}

Intervention InterventionRecord::getIntervention(int indexIn) {
    for (auto it = BSTItrIn<Intervention>(interventions); !it.isAtEnd(); it.advance()){
        if (indexIn == 0 && !it.retrieve().getState()) {
            return it.retrieve();
        }
        if (!it.retrieve().getState())
            indexIn--;
    }
    return Intervention("", nullptr, nullptr, nullptr, nullptr);
}

BST<Intervention> InterventionRecord::getInterventions(){return interventions;}