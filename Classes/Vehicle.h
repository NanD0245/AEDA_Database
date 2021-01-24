#ifndef AEDA2020_PORTAGENS_VEHICLE_H
#define AEDA2020_PORTAGENS_VEHICLE_H

#include <string>

using namespace std;

/**
 * The Vehicle class is a class that gives information about
 * the vehicle its driver is using.
 *
 * @param plate is a non-empty string that identifies the vehicle (e.g. 89BL32)
 * @param v_class is a number that defines the type of the vehicle
 * there is class 1, class 2, class 3 and class 4, as such, v_class can be 1, 2, 3 or 4, according to
 * the vehicle's class
 * @param greenlane is true if the car driver would rather use
 * green lanes than non green, false otherwise
 * @param tax is the value that the vehicle pays per kilometer, according to its vehicle class
 */
class Vehicle {
    string plate;
    int v_class;
    bool greenlane;
    float tax;
public:
    /**
     * Initializes plate, v_class and tax attributes as the values inputted by the user when
     * the constructor is called
     *
     * @param plate is a non-empty string that will be the 'plate' attribute (e.g. 89BL32)
     * @param v_class is a number (1, 2, 3 or 4) that will be the 'v_class' attribute
     * @param tax is
     */
    Vehicle(string plate, int v_class, float tax);

    /**
     * @return current 'plate' attribute
     */
    string getPlate() const;

    /**
     * @return current 'greenlane' attribute
     */
    bool getGreenLaneBool() const;

    /**
     * @return current 'v_class' attribute
     */
    int getClass() const;

    /**
     * @return current 'tax' attribute
     */
    float getTax() const;

    /*!
     * @return string with current info about the vehicle: plate, the vehicle's class and if it uses green lanes
     * in the following format: plate + " - " + v_class + " - " + greenlane
     */
    string getInfo() const;

    /**
     * @return string with info about the vehicle: plate, the vehicle's class and if it uses green lanes in the following format:
     * "Plate: " + plate + " - Classe: " + v_class + " - Greenlane: " + greenlane
     */
    string showVehicle() const;


    /**
     * @param greenlane sets 'greenlane' attribute
     */
    void defineLaneType(bool greenlane);

    /**
     * sets 'greenlane' attribute to true
     */
    void setGreenLaneTrue();

    /**
     * sets 'greenlane' attribute to false
     */
    void setGreenLaneFalse();
    /**
     * @param v_class sets 'v_class' attribute
     */
    void setVehicleClass(int v_class);

    /**
     * @param plate sets 'plate' attribute
     */
    void setPlate(string plate);

    /**
     * @param tax sets 'tax' attribute
     */
    void setTax(float tax);

    /**
     * @return string in the format : plate + " " + v_class + " " + greenlane
     */
    string getInfov2() const;

    /**
     * @brief Overloads the '==' operator to be able to know if two different vehicles are the same
     * @param d1 Object of class Vehicle to compare the current object to
     * @return true if the plate is the same, false otherwise
     */
    bool operator==(Vehicle v1);
};


#endif //AEDA2020_PORTAGENS_VEHICLE_H
