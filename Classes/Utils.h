#ifndef AEDA2020_PORTAGENS_UTILS_H
#define AEDA2020_PORTAGENS_UTILS_H

#include "Date.h"
#include <ctime>
#include <string>
#include <vector>

using namespace std;

/**
 * Utils class is a class that has diverse functions used to manage the terminal menu and allows
 * the user to input values used to create Classes' objects.
 *
 */
class Utils {
public:

    /**
     * Default constructor of Utils class.
     */
    Utils() =default;

    /**
     * Clears the terminal
     */
    void clrScreen();

    /**
     * Allows the user to input an integer to use in some Classes' methods
     * @param max
     * @return number inputted by the user
     */
    int getNumber(int max);

    /**
     * Displays a menu in the terminal using cout
     * @param menu
     * @return
     */
    int ShowMenu(vector<string> menu);

    int ShowMenu(vector<string> menu, int lane_index);

    /**
     * Allows the user to input a float to use in some Classes' methods
     * @return float inputted by the user
     */
    float getFloat();

    /**
     * Allows the user to input a string that represents a vehicle's plate
     * @return string inputted by the user
     */
    string getPlate();

    /**
     * Waits for the user to press enter in order to continue program execution
     */
    void waitForInput();

    /**
     * Allows the user to input a string that represents the date
     * @return date inputted by the user
     */
    Date* getDate();
};


#endif //AEDA2020_PORTAGENS_UTILS_H
