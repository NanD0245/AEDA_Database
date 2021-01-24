//
// Created by mim on 15/12/20.
//

#ifndef AEDA2020_PORTAGENS_INTERVENTIONRECORDS_H
#define AEDA2020_PORTAGENS_INTERVENTIONRECORDS_H

#include "Intervention.h"
#include "bst.h"

class InterventionRecord {
    BST<Intervention> interventions;
public:
    /**
     * Creates the Binary Tree (empty) which contains all interventions
     */
    InterventionRecord();

    /**
     * Adds an intervention to the interventions tree
     * @param i1 is the Intervention object to add
     * @return true if it was able to add, false otherwise
     */
    bool addIntervention(const Intervention& i1);

    /**
     * Removes an intervention from the interventions tree
     * @param i1 is the Intervention object to remove
     * @return true if it was able to remove, false otherwise
     */
    bool removeIntervention(const Intervention& i1);

    /**
     * @return a vector of strings with information about all interventions
     */
    vector<string> showInterventions();

    /**
     * @return a vector of strings with information about all interventions which haven't concluded yet
     */
    vector<string> showInterventionsNotConcluded();

    /**
     * @param indexIn to search in the binary tree
     * @return the Intervention object at the index provided
     */
    Intervention getIntervention(int indexIn);

    /**
     * @return a binary tree with all interventions
     */
    BST<Intervention> getInterventions();
};


#endif //AEDA2020_PORTAGENS_INTERNTIONRECORDS_H
