#ifndef AEDA2020_PORTAGENS_TECHNICIAN_H
#define AEDA2020_PORTAGENS_TECHNICIAN_H

#include <string>

using namespace std;

class Technician {
    string name;
    string specialty; // revisão ; avaria(eletrónica ; informática)
    float performance; //tempo médio (quanto menor for melhor)
    int num_intervetion;
public:
    /**
     * Initializes 'name' and 'specialty'  attributes
     * as the values inputted by the user when the constructor is called
     * @param name sets 'name'
     * @param specialty sets 'specialty'
     */
    Technician(string name, string specialty);

    /**
     * @return name of Technician object
     */
    string getName() const;

    /**
     * @param name sets 'name'
     */
    void setName(string name);

    /**
     * @return specialty of Technician object
     */
    string getSpecialty() const;

    /**
     * @param specialty sets 'specialty'
     */
    void setSpecialty(string specialty);

    /**
     * @return 'performance' of Technician object
     */
    float getPerformance() const;

    /**
     * @param performance sets 'performance'
     */
    void setPerformance(float performance);

    /**
     * @return 'num_intervetion' of Technician object
     */
    int getNumIntervetion() const;

    /**
     * increments 'num_intervetion' by one
     */
    void addIntervention();

    /**
     * @param num sets 'num_intervetion'
     */
    void setIntervention(int num);

    /**
     * @return string in the format name + " - " + specialty + " - " +
     * performance + " - " + num_intervetion
     */
    string getInfo() const;

    /**
     * @return "Name: " + name + " - " + "Specialty: " + specialty + " - " + "Performance: " + performance
                                        + " - " + "Number of Interventions: " + num_intervetion;
     */
    string showTechnician() const;

    /**
     *
     * @param t1 Technician object to compare to
     * @return
     */
    bool operator<(const Technician& t1) const;

};


#endif //AEDA2020_PORTAGENS_TECHNICIAN_H
