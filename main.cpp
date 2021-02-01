#include "Classes/SystemNetwork.h"

#define file "../Cache/systemNetworks.txt"

#ifdef _WIN32
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <wincon.h>

// Fix compilatin on MinGW
#ifndef DISABLE_NEWLINE_AUTO_RETURN
#define DISABLE_NEWLINE_AUTO_RETURN 0x0008
#endif

#ifndef ENABLE_VIRTUAL_TERMINAL_INPUT
#define ENABLE_VIRTUAL_TERMINAL_INPUT 0x0200
#endif

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
/**
 * configura a consola no Windows de modo a que os ASCII codes sejam aceites. Código retirado do Microsoft Docs:
 * https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences#example-of-enabling-virtual-terminal-processing
 * Set output mode to handle virtual terminal sequences
 * @return false if it couldn't create the console, true otherwise
 */
bool SetupConsole() {

	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hIn == INVALID_HANDLE_VALUE || hOut == INVALID_HANDLE_VALUE) {
		return false;
	}
	DWORD dwOriginalInMode = 0;
	DWORD dwOriginalOutMode = 0;
	if (!GetConsoleMode(hIn, &dwOriginalInMode)) {
		return false;
	}
	if (!GetConsoleMode(hOut, &dwOriginalOutMode)) {
		return false;
	}
	DWORD dwInMode = dwOriginalInMode | ENABLE_VIRTUAL_TERMINAL_INPUT;
	if (!SetConsoleMode(hIn, dwInMode))
	{
		// Failed to set VT input mode, can't do anything here.
		return false;
	}
	DWORD dwOutMode = dwOriginalOutMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING | DISABLE_NEWLINE_AUTO_RETURN;
	if (!SetConsoleMode(hOut, dwOutMode)) {
		// we failed to set both modes, try to step down mode gracefully.
		dwOutMode = dwOriginalOutMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		if (!SetConsoleMode(hOut, dwOutMode))
		{
			// Failed to set any VT mode, can't do anything here.
			return false;
		}
	}
	return true;
}
#endif //_WIN32

using namespace std;

int main(int argc, char* argv[]) {
    #ifdef _WIN32
        SetupConsole();
    #endif
    Utils utils;
    char* err;
    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("../DataBase/aeda20-21.db", &db);
    if (rc != SQLITE_OK) {
        cout << "error: " << err << endl;
        utils.waitForInput();
    }
    SystemNetwork system;

    int index;
    try {
        system.read(file);
    }
    catch (FileDoesNotExist &e) {
        cout << "EXCEPTION: File" << e.getFile() << "does not exist." << endl;
    }

    /*sqlite3_prepare(db,"SELECT * from Employees e",-1,&stmt,nullptr);

    while (sqlite3_step(stmt) != SQLITE_DONE) {
        string name; int id;
        id = sqlite3_column_int(stmt,0);
        name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,1)));
        if (name == "Fernando")
            cout << "Name: " << name << " - ID: " << id << endl;
    }

    for (int i = 0; i < system.employees->getNumEmployees(); i++) {
        string query = "INSERT INTO Employees (name) VALUES ('" +
                system.employees->getEmployee(i)->getName() + "')";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK) {
            cout << "error: " << err << endl;
            utils.waitForInput();
        }
    }

    for (int i = 0 ; i < system.highways->getNumHighways(); i++){
        string query = "INSERT INTO Highways (name) VALUES ('" + system.highways->getHighwayIndex(i)->getInfo() + "')";
        rc = sqlite3_exec(db,query.c_str() ,NULL,NULL, &err);
        if (rc != SQLITE_OK) {
            cout << "error: " << err << endl;
            utils.waitForInput();
        }
    }
    for (int j = 0 ; j < system.highways->getNumHighways(); j++){
        for (int i = 0; i < system.highways->getHighwayIndex(j)->getNumTolls(); i++) {
            string query = "INSERT INTO Tolls (highway_id, name,geolocal,highway_kilometer,type) VALUES (" +
                    to_string(j+1) + ",'" +
                    system.highways->getHighwayIndex(j)->getTollIndex(i)->getName() + "','" +
                    system.highways->getHighwayIndex(j)->getTollIndex(i)->getGeolocal() + "'," +
                    to_string(system.highways->getHighwayIndex(j)->getTollIndex(i)->getKilometer()) + "," +
                    to_string(system.highways->getHighwayIndex(j)->getTollIndex(i)->getType()) + ")";
            rc = sqlite3_exec(db,query.c_str() ,NULL,NULL, &err);
            if (rc != SQLITE_OK) {
                cout << "error: " << err << endl;
                utils.waitForInput();
            }
        }
    }
    for (int k = 0 ; k < system.highways->getNumHighways(); k++){
        for (int j = 0; j < system.highways->getHighwayIndex(k)->getNumTolls(); j++) {
            for (int i = 0; i < system.highways->getHighwayIndex(k)->getTollIndex(j)->getNumLanes(); i++) {
                cout << "entrei" << endl;
                Lane* lane = system.highways->getHighwayIndex(k)->getTollIndex(j)->getLane(i);
                int employee_id;
                string query;
                if (lane->getEmployee() == nullptr) {
                    cout << "entrei1" << endl;
                    query = "INSERT INTO Lanes (toll_id,lane_number,green_lane) VALUES (" +
                            to_string(j + 1) + "," +
                            to_string(system.highways->getHighwayIndex(k)->getTollIndex(j)->getLane(i)->getLaneNumber()) + "," +
                            to_string(system.highways->getHighwayIndex(k)->getTollIndex(j)->getLane(i)->getGreenLane()) + ")";
                }
                else {
                    cout << "entrei2" << endl;
                    cout << lane->getEmployee()->getName() << endl;
                    string query1 = "SELECT * from Employees e where e.name = '" + lane->getEmployee()->getName()+"'";
                    sqlite3_prepare(db,query1.c_str(),-1,&stmt,nullptr);
                    sqlite3_step(stmt);
                    employee_id = sqlite3_column_int(stmt, 0);
                    query = "INSERT INTO Lanes (employee_id,toll_id,lane_number,green_lane) VALUES (" +
                            to_string(employee_id) + "," +
                            to_string(j+1) + "," +
                            to_string(system.highways->getHighwayIndex(k)->getTollIndex(j)->getLane(i)->getLaneNumber())+","+
                            to_string(system.highways->getHighwayIndex(k)->getTollIndex(j)->getLane(i)->getGreenLane()) + ")";
                }
                rc = sqlite3_exec(db,query.c_str() ,NULL,NULL, &err);
                if (rc != SQLITE_OK) {
                    cout << "error: " << err << endl;
                    utils.waitForInput();
                }
            }
        }
    }
    for (int i = 0; i < system.vehicles->getNumVehicles(); i++) {
        Vehicle* v = system.vehicles->getVehicleIndex(i);
        string query = "insert into Vehicles (plate,v_class,greenlane,tax) values ('" +
                v->getPlate() + "'," + to_string(v->getClass()) + "," +
                to_string(v->getGreenLaneBool()) + "," + to_string(v->getTax()) + ")";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK) {
            cout << "erro: " << err << endl;
            utils.waitForInput();
        }
    }
    for (int i = 0; i < system.owners->getNumOwners(); i++) {
        Owner o = system.owners->getOwner(i);
        string query1 = "insert into Owners (name) values ('" + o.getName() + "')";
        rc = sqlite3_exec(db,query1.c_str(), NULL, NULL, &err);
        if (rc != SQLITE_OK){
            cout << "error: " << err << endl;
            utils.waitForInput();
        }
        vector<Vehicle*> v = o.getVehicles();
        for (int j = 0; j < v.size(); j++) {
            string query2 = "update Vehicles set owner_id=" + to_string(i+1) +
                    " where plate = '" + v[j]->getPlate()+ "'";
            rc = sqlite3_exec(db, query2.c_str(), NULL,NULL,&err);
            if (rc != SQLITE_OK) {
                cout << "error: " << err << endl;
                utils.waitForInput();
            }
        }
    }
    vector<Movement*> v = system.movements->getMovements();
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getType()) {
            string query = "insert into Movements (type,vehicle_id,highway_id,";
        }
        else {
            string query;
        }
    }*/

    do {
        utils.clrScreen();

        index = utils.ShowMenu({"Manage Movements", "Manage Highways", "Manage Employees" , "Manage Vehicles",
                                "Input Taxes for vehicles", "Manage Interventions", "Manage Technicians",
                                "Manage Owners", "Statistics"});
        switch (index) {
            case(1):
                system.manageMovements();
                break;
            case(2):
                system.manageHighways();
                break;
            case(3):
                system.manageEmployee();
                break;
            case(4):
                system.manageVehicle();
                break;
            case 5:
                system.getTaxesFromUser();
                break;
            case 6:
                system.manageInterventions();
                break;
            case 7:
                system.manageTechnicians();
                break;
            case 8:
                system.manageOwners();
                break;
            case 9:
                system.manageStatistics();
                break;
        }
    } while (index);
    system.write();
    return 0;
}