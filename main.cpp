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

    for (int i = 0 ; i < system.highways->getNumHighways(); i++){
        string query = "INSERT INTO Highways (name) VALUES ('" + system.highways->getHighwayIndex(i)->getInfo() + "')";
        rc = sqlite3_exec(db,query.c_str() ,NULL,NULL, &err);
        if (rc != SQLITE_OK) {
            cout << "error: " << err << endl;
            utils.waitForInput();
        }
        /*for (int j = 0; j < system.highways->getHighwayIndex(i)->getNumTolls(); j++) {
            query = "INSERT INTO Highways (name) VALUES ('" + system.highways->getHighwayIndex(i)->getInfo() + "')";
            rc = sqlite3_exec(db,query.c_str() ,NULL,NULL, &err);
            if (rc != SQLITE_OK) {
                cout << "error: " << err << endl;
                utils.waitForInput();
            }
        }*/
    }


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