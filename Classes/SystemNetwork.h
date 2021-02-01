#ifndef AEDA2020_PORTAGENS_SYSTEMNETWORK_H
#define AEDA2020_PORTAGENS_SYSTEMNETWORK_H

#include "HighwayRecord.h"
#include "MovementRecord.h"
#include "VehicleRecord.h"
#include "EmployeeRecord.h"
#include "Utils.h"
#include "Exceptions.h"
#include "InterventionRecord.h"
#include "OwnerRecord.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <sqlite3.h>

using namespace std;


/**
 * SystemNetwork class is a class that manages all the other classes, effectively allowing the user to
 * create, read, update and delete all the various objects that fulfill the project, i.e. administrating
 * the various tolls in a existing network of Highways, optimizing their performance and registering movements,
 * employees, vehicles, tolls, among other important data.
 *
 * @param highways is the Highways object that stores all the different Highway objects and their info
 * @param movements is the Movements object that stores all the different Movement objects and their info
 * @param vehicles is the Vehicles object that stores all the different Vehicle objects and their info
 * @param utils is the Utils object that has several important methods that are used to create the menu and allow the user to input values
 * @param employees is the Employee object that stores all the different Employee objects and their info
 */
class SystemNetwork {
public:
    HighwayRecord* highways;
    Highway* highway;
    MovementRecord* movements;
    VehicleRecord* vehicles;
    Utils* utils;
    EmployeeRecord* employees;
    InterventionRecord* interventions;
    OwnerRecord* owners;

    /*int Checkdb() {
        sqlite3* db = utils->openDB();
        sqlite3_stmt* stmt;
        sqlite3_prepare(db,"SELECT * from Employees e",-1,&stmt,nullptr);

        while (sqlite3_step(stmt) != SQLITE_DONE) {
            string name; int id;
            id = sqlite3_column_int(stmt,0);
            name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,1)));
            cout << "Name: " << name << " - ID: " << id << endl;
        }
        return 0;
    }*/


    /**
     * The SystemNetwork constructor initializes all of its attributes using its' corresponding classes' constructors.
     *
     */
    SystemNetwork();

    /**
     * Allows the user to either create a new Highway object that or update, read, delete and manage already existing Highway objects.
     */
    void manageHighways();

    /**
     * Allows the user to either create a new Toll object (in current Highway object)
     * or update, read, delete and manage already existing Toll objects.
     * @param Highway object which the user will manage
     */
    void manageHighway(int highway_id);

    /**
     * Allows the user to either create a new Lane object (in current Toll object)
     * or update, read and delete  already existing Toll objects.
     * @param Toll object which the user will manage
     */
    void manageToll(Toll * toll);

    /**
     * Allows the user to either create a new Employee object
     * or update, read and delete  already existing Employee objects.
     */
    void manageEmployee();

    /**
     * Allows the user to either create a new Vehicle object
     * or update, read and delete  already existing Vehicle objects.
     */
    void manageVehicle();

    /**
     * Allows the user to add an Entry Movement, add an Exit Movement or
     * manage already existing Vehicle objects.
     */
    void manageMovements();

    /**
     * Allows the user to manage all movements, Highway movements, Toll movements, Vehicle movements or Employee movements
     */
    void manageReadMovements();

    /**
     * Attempts to show the user movements in the different Highway objects sorted by alphabetical order (object's name, ascending),
     * by the movements' price (descending) and by the movements' date (earlier to late)
     */
    void manageMovementsHighway();

    /**
     * Attempts to show the user movements in the different Toll objects sorted by alphabetical order (object's name, ascending),
     * by the tolls' worth (descending) and by the tolls' type (entrance or exit)
     */
    void manageMovementsToll();

    /**
     * Attempts to show the user movements in the different Lane objects sorted by the lane's number (ascending) and by lane price
     */
    void manageMovementsLane();

    /**
     * Attempts to show the user movements in the different Vehicle objects sorted by price, car distance and date
     */
    void manageMovementsCar();

    /**
     * Attemps to show the user movements using diverse interactive statistics:
     * Most Valuable Highway, Most Valuable Toll, Most Valuable Lane, Vehicle that spent most money,
     * Highway with more movements , Toll with more movements, Lane with more movements
     */
    void manageStatistics();


    /**
     * Allows the user to input a name (which is different of all the other Highway objects)
     * that will be used to create a new Highway object, and adds the object to 'highways'
     */
    void createHighway();

    /**
     * Prints information in the console about all Highway objects
     */
    void readHighways();

    /**
     * Allows the user to select a Highway, and then update its name
     */
    void updateHighway();

    /**
     * Alows the user to select a Highway, and then delete it
     */
    void deleteHighway();

    /**
     * Allows the user to input a number (index) which selects a Highway. As long as the index isn't -1, if it's an invalid number
     * the program continues to ask the user for a valid index.
     * @return nullptr if index is -1, the selected Highway otherwise
     */
    int chooseHighway();

    /**
     *
     * @return a menu that prints all the highways and their respective indexes
     */
    int chooseIndexHighway() const;

    /**
     * Allows the user to input a name (which is different of all the other Toll objects), a geographical location
     * and the toll's highway kilometer that will be used to create a new Toll object that will belong to the tolls
     * attribute of selected Highway object
     * @param highway is the selected Highway object referred above
     */
    void createToll(Highway * highway);

    /**
     * Prints information in the console about all Toll objects that belong to the provided Highway
     * @param highway is the selected Highway object referred above
     */
    void readTolls(int highway_id);

    /**
     * Allows the user to select a Toll that belongs to the Highway object, and then update its attributes
     * @param highway is the selected Highway object
     */
    void updateToll(Highway * highway);

    /**
     * Allows the user to select a Toll that belongs to the Highway object, and then delete it
     * @param highway is the selected Highway object
     */
    void deleteToll(Highway * highway);

    /**
     *
     * @return a menu that prints all the Toll objects that belong to a certain Highway 'highway'
     * and their respective indexes
     * @param highway is the selected Highway object
     */
    int chooseIndexToll(Highway * highway) const;

    /**
     * Allows the user to input a number (index) which selects a Toll. As long as the index isn't -1, if it's an invalid number
     * the program continues to ask the user for a valid index.
     * @return nullptr if index is -1, the selected Toll otherwise
     */
    Toll* chooseToll(Highway* highway);

    /**
     * Allows the user to add a Lane object to selected Toll object 'toll'. If the Toll object is an entrance toll, the
     * object is simply added. Otherwise, the user has to specify if the Lane object is a green lane or not. The Lane is then added
     * unless it isn't a green lane and there aren't any employees
     * @param toll is the selected Toll object referred above
     */
    void createLane(Toll* toll);

    /**
     * Prints information in the console about all Lane objects that belong to the provided toll
     * @param toll is the selected Toll object referred above
     */
    void readLanes(Toll* toll);

    /**
     * Allows the user to select a Lane that belongs to the Toll object, and then update its attributes, unless the
     * toll is an entrance Toll, which means there are no attributes for the Lane to update
     * @param toll is the selected Toll object
     */
    void updateLane(Toll* toll);

    /**
     * Allows the user to select a Lane that belongs to the Toll object, and then delete it
     * @param toll is the selected Toll object
     */
    void deleteLane(Toll* toll);

    /**
     *
     * @return a menu that prints all the Lane objects that belong to a certain Toll 'toll'
     * and their respective indexes
     * @param toll is the selected Toll object
     */
    int chooseIndexLane(Toll* toll) const;

    /**
     *
     * @return a menu that prints all the Lane objects that belong to a certain Toll 'toll'
     * and their respective indexes
     * @param toll is the selected Toll object
     * @param index is the index of the chosen Lane
     */
    int chooseIndexLane(Toll* toll,int index) const;

    /**
     * Allows the user to input a number (index) which selects a Lane. As long as the index isn't -1, if it's an invalid number
     * the program continues to ask the user for a valid index.
     * @param index is the index of the Lane
     * @param toll is the Toll to which the Lanes belong
     * @return nullptr if index is -1, the selected Lane otherwise
     */

    Lane* chooseLane(Toll* toll, int index);

    /**
     * Allows the user to create an Employee object.
     */
    void createEmployee();

    /**
     * Prints information in the console about all Employee objects
     */
    void readEmployees();

    /**
     * Allows the user to select an Employee, and then update its attributes
     */
    void updateEmployee();

    /**
     * Allows the user to select an Employee, and then delete it
     */
    void deleteEmployee();

    /**
     *
     * @return a menu that prints all the Employee objects and their respective indexes
     */
    int chooseIndexEmployee() const;

    /**
     * Allows the user to create a Vehicle object.
     */
    void createVehicle();

    /**
     * Prints information in the console about all Vehicle objects
     */
    void readVehicles();

    /**
     * Allows the user to select an Vehicle, and then update its attributes
     */
    void updateVehicle();

    /**
     * Allows the user to select an Employee, and then delete it
     */
    void deleteVehicle();

    /**
     *
     * @return a menu that prints all the Vehicle objects and their respective indexes
     */
    int chooseIndexVehicle() const;

    /**
     * Calculates the lane which the user when it enters a Highway
     * @param toll is the toll in which the user is entering
     * @param date is the moment when the user is entering
     * @return index of lane which the user should use
     */
    int adviceEntryLane(Toll * toll, Date * date);

    /**
     * Calculates the lane which the user when it exits a Highway
     * @param toll is the toll which the user is exiting
     * @param date is the moment when the user is exiting
     * @return index of lane which the user should use
     */
    int adviceOutLane(Vehicle* vehicle, Toll * toll, Date * date);

    /**
     * Allows the user to input values for each of the vehicle classes' taxes
     */
    void getTaxesFromUser();

    /**
     * Tries to create an Entry Movement in a certain Lane object, which belongs to a TollEntrance object of a certain Highway,
     * made by a Vehicle.
     */
    void addEntryMovement();

    /**
     * Tries to create an Exit Movement in a certain Lane object, which belongs to a TollOut object of a certain Highway,
     * made by a Vehicle.
     */
    void addExitMovement();

    /**
     * Sorts and prints all Movements by Highway name (ascending order)
     */
    void showMovementsByHighwayName();

    /**
     * Sorts and prints all Movements by Highway price (descending order)
     */
    void showMovementsByHighwayPrice();

    /**
     * Sorts and prints all Movements by their date (earlier to later)
     */
    void showMovementsByDate();

    /**
     * Sorts and prints all Movements of the Toll objects that belong to a highway by Toll name (ascending order)
     * @param highway is the the object to which the Toll objects belong
     */
    void showMovementsByTollName(Highway* highway);

    /**
     * Sorts and prints all Movements of the Toll objects that belong to a highway by Toll type (entrance or exit)
     * @param highway is the the object to which the Toll objects belong
     */
    void showMovementsByTollType(Highway* highway);

    /**
     * Sorts and prints all Movements of the Toll objects that belong to a highway by Toll price (descending order)
     * @param highway is the the object to which the Toll objects belong
     */
    void showMovementsByTollPrice(Highway* highway);

    /**
     * Sorts and prints all Movements of the Lane objects that belong to a Toll by Lane number (ascending order)
     * @param toll is the the object to which the Lane objects belong
     */
    void showMovementsbyLaneNumber(Toll * toll);

    /**
     * Sorts and prints all Movements of the Lane objects that belong to a Toll by Lane price (descending order)
     * @param toll is the the object to which the Lane objects belong
     */
    void showMovementsbyLanePrice(Toll * toll);

    /**
     * Sorts and prints all Movements of the Vehicle objects by date (earlier to later)
     */
    void showCarMovementsbyDate();

    /**
     * Sorts and prints all Movements of the Vehicle objects by distance travelled (descending order)
     */
    void showCarMovementsbyDistance();

    /**
     * Sorts and prints all Movements of the Vehicle objects by price (descending order)
     */
    void showCarMovementsbyPrice();

    /**
     * Prints all Movements of the Employee objects
     */
    void showEmployeeMovements();

    /**
     * Prints information about the Vehicle that spent the most money, and the money it spent
     */
    void carSpentMoreMoney();

    /**
     * Prints information about the Highway that made the most money , and the money it made
     */
    void BestWorthHighway();

    /**
     * Prints information about the Toll that made the most money , and the money it made
     */
    void BestWorthToll();

    /**
     * Prints information about the Lane that made the most money , and the money it made
     */
    void BestWorthLane();

    /**
     * Prints information about the Highway that had the most movements , and the total number of movements in that highway
     */
    void HighwayMoreMoves();

    /**
     * Prints information about the Toll that had the most movements , and the total number of movements in that highway
     */
    void TollMoreMoves();

    /**
     * Prints information about the Highway that had the most movements , and the total number of movements in that highway
     */
    void LaneMoreMoves();

    /**
     * reads file '../Cache/systemNetworks.txt' and creates objects that represent the information of the file
     * @param file is a .txt file (e.g. '../Cache/systemNetworks.txt' file)
     */
    //void read(string file);

    /**
     * writes file '../Cache/systemNetworks.txt' according to the objects that make up the program's data
     */
    //void write();

    /**
     * Allows the user to create, read, update or delete the Technician objects.
     */
    void manageTechnicians();

    /**
     * Allows the user to add, read or conclude interventions.
     */
    void manageInterventions();

    /**
     * Allows the user to read all owners or select one of them to manage
     */
    void manageOwners();

    /**
     * Allows the user to read all interventions, on a single day, by type, or by a single technician
     */
    void manageReadInterventions();

    /**
     * Allows the user to read all owners, by quantity of vehicles or by ownership of a specific vehicle
     */
    void manageReadOwners();
    /**
     * Allows the user to add a vehicle to a certain owner, read all vehicles that a owner has, or
     * remove one of the owner's vehicles
     */
    void manageOwner(Owner o1);

    /**
     * Adds an intervention
     */
    void addIntervention();

    /**
     * Concludes an intervention
     */
    void concludeIntervention();

    /**
     * Reads all interventions
     */
    void readInterventions();

    /**
     * Reads interventions on a single day
     */
    void readInterventionsDay();

    /**
     * Reads interventions by a technician
     */
    void readInterventionsTechnician();

    /**
     * Reads interventions by type
     */
    void readInterventionsType();

    /**
     * Creates a new Technician object
     */
    void createTechnician();

    /**
     * Updates a Technician object chosen by the user
     */
    void updateTechnician();

    /**
     * Shows all Technician objects and their information to the user
     */
    void readTechnicians();

    /**
     * Deletes a Technician object chosen by the user
     */
    void deleteTechnician();

    /**
     * Shows all Owner objects and their information to the user
     */
    void readOwners();

    /**
     * Reads owners by number of vehicles
     */
    void readOwnersNumVehicles();

    /**
     * Reads an owner by ownership of a specific vehicle
     */
    void readOwnerVehicle();

    /**
     * Adds a certain vehicle to the Owner o1
     * @param o1 is a Owner object
     */
    void addVehicleOwner(Owner& o1);

    /**
     * Shows the vehicle that owner o1 has
     * @param o1 is an Owner object
     */
    void readVehiclesOwner(Owner& o1);

    /**
     * Deletes the vehicle that owner o1 has
     * @param o1 is the Owner object
     */
    void deleteVehicleOwner(Owner& o1);
    /**
     * Shows the user the owner with the most vehicles
     */
    void ownerMoreVehicles();

};


#endif //AEDA2020_PORTAGENS_SYSTEMNETWORK_H


void addVehicleOwner(Owner& o1);
void readVehiclesOwner(Owner& o1);
void deleteVehicleOwner(Owner& o1);