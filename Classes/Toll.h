
#ifndef AEDA2020_PORTAGENS_TOLLS_H
#define AEDA2020_PORTAGENS_TOLLS_H

#include "Lane.h"
#include "Technician.h"
#include <string>
#include <vector>
#include <queue>

using namespace std;

class MyCompare {
public:
    bool operator()(Technician *a, Technician *b) {
        return (*a) < (*b);
    }
};

/**
 * The class Toll is a class that has information about each
 * and every toll
 *
 * Each toll has a name, a geographic localization, a certain length, a certain number of lanes
 * which have different amounts of vehicles. Besides that, the toll can be an entrance toll or an
 * exit toll.
 *
 * @param name is a unique string that identifies the Toll
 * @param geolocal is the geographical location of the toll (e.g. a city)
 * @param highway_kilometer is the kilometer on the highway on which the toll is located
 * @param type is true when it is an exit toll, false when it isn't
 * @param lanes is a container that has all the different lanes that are part of the toll
 */
class Toll {
protected:
    string name;
    string geolocal;
    float highway_kilometer;
    bool type;
    vector<Lane *> lanes;
    priority_queue<Technician*, vector<Technician*>, MyCompare> technicians;
public:
    /**
     * Initializes a new Toll object with the input provided by the user
     * @param name sets 'name' attribute
     * @param geolocal sets 'geolocal' attribute
     * @param highway_kilometer sets 'highway_kilometer' attribute
     * @param type sets 'type' attribute
     */
    Toll(string name, string geolocal, float highway_kilometer,bool type);

    /**
     * Default constructor. \n
     * Initializes a new Toll object with "" as 'name' attribute, "" as 'geolocal' attribute,
     * 0 as 'highway_kilometer' attribute and 'type' set to true (is an exit toll)
     */
    Toll();

    /**
     * @return 'name' attribute
     */
    string getName() const;

    /**
     * @return 'type' attribute
     */
    bool getType() const;

    /**
     * @return 'geolocal' attribute
     */
    string getGeolocal() const;

    /**
     * @return 'highway_kilometer' attribute
     */
    float getKilometer() const;

    /**
     * @return string in the following format:
     * name + " - " + geolocal + " - " + highway_kilometer + " - " + type;
     */
    string getInfo() const;

    /**
     * @param i is the index , in the vector 'lanes', of the lane (Lane object)
     * @return the Lane object that has the index 'i' if it exists, nullptr otherwise
     */
    Lane * getLane(int i);

    /**
     * @return the number of Lane objects already in the 'lanes' container
     */
    int getNumLanes() const;

    /**
     * @return string in the following format:
     * "Toll Name: " + name + " - Geographic Location: " + geolocal + " - Highway Kilometer: " + highway_kilometer + " - Type: " + "Exit" or "Entrance", depending on the type
     */
    string showToll() const;

    /**
     * @param type sets 'type' attribute
     */
    void setType(bool type);

    /**
     * @param name sets 'name' attribute
     */
    void setName(string name);

    /**
     * @param geolocal sets 'geolocal' attribute
     */
    void setGeolocal(string geolocal);

    /**
     * @param kilometer sets 'kilometer' attribute
     */
    void setKilometer(float kilometer);

    /**
     * Sets the 'green_lane' attribute of selected Lane object to true
     * @param lane is the Lane object to be changed
     */
    void setGreenLaneTrue(Lane * lane);

    /**
     * Sets the 'green_lane' attribute of selected Lane object to false
     * @param lane is the Lane object to be changed
     */
    void setGreenLaneFalse(Lane * lane, Employee* e);

    /**
     * removeLane function removes a Lane object making use of its index in the
     * vector 'lanes'
     * @param i is the index, in the vector 'lanes', of the Lane object to remove from the container
     * @return true if the Lane object with the index i was successfully removed from the
     * container, false otherwise
     */
    bool removeLane(int i);

    /**
     * @brief Overloads the '==' operator to be able to know if two different Toll objects are the same
     * @param l2 is the object of class Toll to compare the current object to
     * @return true if both Toll objects have the same 'name','geolocal', 'highway_kilometer' and 'type' attributes,
     * false otherwise
     */
    bool operator==(const Toll& l2) const;

    virtual void addLane() {};
    virtual void addLane(Lane * l);
    virtual void addLane(Employee * e) {};

    /**
     * Finds if there already is a technician with the name "name"
     * @param name is a string which is the name to find
     * @return false if there is a technician with that name, true otherwise
     */
    bool checkTechnicianName(string name);

    /**
     * Adds a new Technician object with name "name" and specialty "specialty" to the technicians container
     * @param name is a string with the name that the technician will have
     * @param specialty is a string which is the specialty that the technician will have
     * @return true if it was able to add, false otherwise
     */
    bool addTechnician(string name, string specialty);
    /**
     * Adds a Technician object to the technicians container
     * @param technician object to add
     * @return true if it was able to add, false otherwise
     */
    bool addTechnician(Technician* technician);

    /**
     * Returns a Technician object with the name provided, if it exists
     * @param name of the Technician object to find
     * @return Technician object if it was found, nullptr otherwise
     */
    Technician* getTechnicianName(string name);

    /**
     * Returns a Technician object with the specialty provided, if it exists
     * @param type of the Technician object to find
     * @return Technician object if it was found, nullptr otherwise
     */
    Technician* getTechnicianSpeciality(string type);

    /**
     *
     * @return
     */
    vector<string> readTechnicians();
    vector<string> readTechniciansv2();
    bool deleteTechnician(string name);
};


/**
 * The class TollEntrance is a class derived publicly from Toll class.
 * It has information about a Toll that is an entrance to a Highway.
 *
 */
class TollEntrance : public Toll {
public:
    /**
     * Initializes a new TollEntrance object with the input provided by the user
     * @param name sets 'name' attribute
     * @param geolocal sets 'geolocal' attribute
     * @param highway_kilometer sets 'highway_kilometer' attribute
     */
    TollEntrance(string name, string geolocal, float highway_kilometer);

    /**
     * addLane function creates and adds a Lane object
     * to the container 'lanes'
     * It adds a Lane object with lane number set to the size of the 'lanes' container (so that two numbers are never repeated)
     * and isn't a green lane.
     */
    void addLane();

    /**
     * addLane function adds desired Lane object to the container 'lanes'
     * @param l is the Lane object to add
     */
    void addLane(Lane * l);
};



/**
 * The class TollOut is a class derived publicly from Toll class.
 * It has information about a Toll that is an exit to a Highway.
 *
 */
class TollOut : public Toll {
public:
    /**
     * Initializes a new TollOut object with the input provided by the user
     * @param name sets 'name' attribute
     * @param geolocal sets 'geolocal' attribute
     * @param highway_kilometer sets 'highway_kilometer' attribute
     */
    TollOut(string name, string geolocal, float highway_kilometer);

    /**
     * addLane function creates and adds a Lane object
     * to the container 'lanes'
     * It adds a Lane object with lane number set to the size of the 'lanes' container (so that two numbers are never repeated)
     * and is a green lane.
     */
    void addLane();

    /**
     * addLane function creates and adds a Lane object
     * to the container 'lanes' with an assigned Employee
     * It adds a Lane object with lane number set to the size of the 'lanes' container (so that two numbers are never repeated)
     * and is a green lane.
     * @param e is the Employee object assigned to the lane
     */
    void addLane(Employee * e);

    /**
     * addLane function adds desired Lane object to the container 'lanes'
     * @param l is the Lane object to add
     */
    void addLane(Lane * l);
};

#endif //AEDA2020_PORTAGENS_TOLL_H