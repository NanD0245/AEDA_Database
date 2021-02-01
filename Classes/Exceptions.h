#ifndef AEDA2020_PORTAGENS_EXCEPTIONS_H
#define AEDA2020_PORTAGENS_EXCEPTIONS_H

#include <string>
using namespace std;


/**
 * Class relative to the exception of no existing movements
 */
class DontExistAnyMovement {
public:
    /**
     * Creates a new DontExistAnyMovement exception object
     *
     */
    DontExistAnyMovement() = default;
};

/**
 * Class relative to the exception of no existing exit movements
 */
class DontExistAnyExitMovement {
public:
    /**
     * Creates a new DontExistAnyExitMovement exception object
     *
     */
    DontExistAnyExitMovement() = default;
};

/**
 * Class relative to the exception of no existing vehicles with a certain plate
 *
 * @param plate is the plate attribute that identifies a Vehicle object (which may not exist)
 */
class VehicleDoesNotExist {
    string plate;
public:
    /**
     * Creates a new VehicleDoesNotExist exception object
     *
     * @param plate is the 'plate' attribute which the Exception tries to find an existing one with the same plate
     */
    VehicleDoesNotExist(string plate) : plate(plate) {}

    /**
     * @return plate
     */
    string getPlate() const {return plate;}
};


/**
 * Class relative to the exception of no existing employees with a certain name
 *
 * @param name is the name attribute that identifies a Employee object (which may not exist)
 */
class EmployeeDoesNotExist {
    string name;
public:
    /**
     * Creates a new EmployeeDoesNotExist exception object
     *
     * @param name is the 'name' attribute which the Exception tries to find an existing one with the same name
     */
    EmployeeDoesNotExist(string name) : name(name) {}
    /**
     * @return name
     */
    string getName() const {return name;}
};

/**
 * Class relative to the exception of no existing file
 *
 * @param file is a that is the file's location and name (e.g. "file.txt")
 */
class FileDoesNotExist {
    string file;
public:
    /**
     * Creates a new FileDoesNotExist exception object
     *
     * @param file is the 'file' attribute which the Exception tries to find
     */
    FileDoesNotExist(string file) : file(file) {}
    /**
     * @return file name
     */
    string getFile() const {return file;}
};

class DataBaseDoesNotExist {
    string dir;
    char* err;
public:
    DataBaseDoesNotExist(string dir,char* err) : dir(dir), err(err) {}
    string getDir() {return dir; }
    char* getErr()  {return err; }
};

#endif //AEDA2020_PORTAGENS_EXCEPTIONS_H
