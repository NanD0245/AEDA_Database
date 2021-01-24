//
// Created by mim on 15/12/20.
//

#ifndef AEDA2020_PORTAGENS_INTERVENTION_H
#define AEDA2020_PORTAGENS_INTERVENTION_H

#include <iostream>
#include "Date.h"
#include "HighwayRecord.h"
#include "Technician.h"

class Intervention {
    string type; // revisão ; avaria(eletrónica ; informática)
    Highway* highway;
    Toll* toll;
    Date* start_date, *end_date;
    Technician* technician;
    float duration;
    bool state; // em espera ; concluido
public:
    /**
     * Creates an Intervention object with the according attributes
     * @param type sets 'type'
     * @param technician sets 'technician'
     * @param date sets 'date'
     * @param highway sets 'highway'
     * @param toll sets 'toll'
     */
    Intervention(string type, Technician* technician, Date* date, Highway* highway, Toll* toll);
    /**
     * Creates an Intervention object with the according attributes
     * @param type sets 'type'
     * @param highway sets 'highway'
     * @param toll sets 'toll'
     * @param start_date sets 'start_date'
     * @param end_date sets 'end_date'
     * @param technician sets 'technician'
     * @param duration sets 'duration'
     * @param state sets 'state'
     */
    Intervention(string type, Highway* highway, Toll* toll, Date* start_date, Date* end_date, Technician* technician, float duration, bool state );
    /**
     * Finishes an intervention
     * @param end_date sets 'end_date'
     */
    void concludeIntervention(Date* end_date);

    /**
     * @return type of the Intervention object
     */
    string getType() const;

    /**
     * @param type sets 'type'
     */
    void setType(string type);

    /**
     * @return Highway in which the Intervention happened
     */
    Highway * getHighway() const;

    /**
     * @return Toll in which the Intervention happened
     */
    Toll* getToll() const;

    /**
     * @return state of the Intervention
     */
    bool getState() const;

    void changeState();
    /**
     * @return start_date attribute
     */
    Date* getStartDate() const;

    /**
     * @return end_date attribute
     */
    Date* getEndDate() const;

    /**
     * @return Technician object associated with current Intervention
     */


    Technician* getTechnician() const;
    /**
     * @return duration attribute
     */
    float getDuration() const;
    /**
     * @param sets duration
     */
    void setDuration(float duration);

    /**
     *
     * @return string with information about the Intervention
     */
    string showIntervention();

    /**
     *
     * @return string in the form: type + " - " + highway->getInfo() + " - " + toll->getName() + " - " + start_date->getInfo()
     * + " - " + end_date->getInfo() + " - " + technician->getName()+ " - " + duration + " - "
     * + state;

     */
    string getInfo() const;

    /**
     * @param i1 is the Intervention object to compare the current one to
     * @return true if the date is before the object compared, false otherwise
     */
    bool operator<(const Intervention& i1) const;
};


#endif //AEDA2020_PORTAGENS_INTERVENTION_H
