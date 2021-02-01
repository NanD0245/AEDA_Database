#include "SystemNetwork.h"

using namespace std;

SystemNetwork::SystemNetwork() {
    highways = new HighwayRecord();
    highway = new Highway("");
    toll = new Toll("","",0,false);
    movements = new MovementRecord();
    vehicles = new VehicleRecord();
    utils = new Utils();
    employees = new EmployeeRecord();
    interventions = new InterventionRecord();
    owners = new OwnerRecord();
}

void SystemNetwork::manageHighways() {
    int index;
    do {
        index = utils->ShowMenu({"Create Highway", "Update Highway", "Delete Highway", "Read Highways", "Manage Highway"});
        switch(index) {
            case 1:
                utils->clrScreen();
                createHighway();
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                updateHighway();
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                deleteHighway();
                utils->clrScreen();
                break;
            case 4:
                utils->clrScreen();
                readHighways();
                utils->clrScreen();
                break;
            case 5:
                utils->clrScreen();
                int id = chooseHighway();
                utils->clrScreen();
                if (id == -1)
                    break;
                manageHighway(id);
                utils->clrScreen();
                break;
        }
    } while(index);
}

void SystemNetwork::manageHighway(int highway_id) {
    int index;
    do {
        index = utils->ShowMenu({"Create Toll", "Update Toll", "Delete Toll", "Read Tolls","Manage Toll"});
        switch(index) {
            case 1:
                utils->clrScreen();
                createToll(highway_id);
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                updateToll(highway_id);
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                deleteToll(highway_id);
                utils->clrScreen();
                break;
            case 4:
                utils->clrScreen();
                readTolls(highway_id);
                utils->clrScreen();
                break;
            case 5:
                utils->clrScreen();
                int toll_id = chooseToll(highway_id);
                utils->clrScreen();
                if (toll_id == -1)
                    break;
                manageToll(toll_id);
                utils->clrScreen();
                break;
        }
    } while(index);
}

void SystemNetwork::manageToll(int toll_id) {
    int index;
    do {
        index = utils->ShowMenu({"Create Lane", "Update Lane", "Delete Lane", "Read Lanes"});
        switch(index) {
            case 1:
                utils->clrScreen();
                createLane(toll_id);
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                updateLane(toll_id);
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                deleteLane(toll_id);
                utils->clrScreen();
                break;
            case 4:
                utils->clrScreen();
                readLanes(toll_id);
                utils->clrScreen();
                break;
        }
    } while(index);
}

void SystemNetwork::manageEmployee() {
    int index;
    do {
        index = utils->ShowMenu({"Create Employee", "Update Employee", "Delete Employee", "Read Employees"});
        switch(index) {
            case 1:
                utils->clrScreen();
                createEmployee();
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                updateEmployee();
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                deleteEmployee();
                utils->clrScreen();
                break;
            case 4:
                utils->clrScreen();
                readEmployees();
                utils->clrScreen();
                break;
        }
    } while(index);
}

void SystemNetwork::manageVehicle() {
    int index;
    do {
        index = utils->ShowMenu({"Register Vehicle", "Update Vehicle", "Delete Vehicle", "Read Vehicles"});
        switch(index) {
            case 1:
                utils->clrScreen();
                createVehicle();
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                updateVehicle();
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                deleteVehicle();
                utils->clrScreen();
                break;
            case 4:
                utils->clrScreen();
                readVehicles();
                utils->clrScreen();
                break;
        }
    } while(index);
}

void SystemNetwork::manageMovements() {
    int index;
    do {
        index = utils->ShowMenu({"Add a entry movement on a highway", "Add a exit movement of the highway", "Read Movements"});
        switch(index) {
            case 1:
                utils->clrScreen();
                addEntryMovement();
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                addExitMovement();
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                manageReadMovements();
                utils->clrScreen();
                break;
        }
    } while(index);
}

void SystemNetwork::manageReadMovements() {
    int index;
    Highway* a1;
    Toll* t1;
    do {
        index = utils->ShowMenu({"All movements", "Highway movements", "Toll movements", "Vehicle Movements", "Employee Movements"});
        switch (index) {
            case 1:
                utils->clrScreen();
                manageMovementsHighway();
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                manageMovementsToll();
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                manageMovementsLane();
                utils->clrScreen();
                break;
            case 4:
                utils->clrScreen();
                manageMovementsCar();
                utils->clrScreen();
                break;
            case 5:
                utils->clrScreen();
                try {
                    showEmployeeMovements();
                    utils->clrScreen();
                }
                catch (DontExistAnyMovement &e) {
                    cout << "EXCEPTION: There are no employee movements." << endl;
                }
                catch (EmployeeDoesNotExist &e) {
                    cout << "EXCEPTION: There are no employees with the name " << e.getName() << "." << endl;
                }
                break;
        }
    } while (index);
}

void SystemNetwork::manageMovementsHighway() {
    int index;
    do {
        index = utils->ShowMenu({"By highway name", "By price", "By date"});
        switch (index) {
            case 1:
                utils->clrScreen();
                try {
                    showMovementsByHighwayName();
                }
                catch (DontExistAnyMovement &e) {
                    cout << "EXCEPTION: There are no movements." << endl;
                }
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                try {
                    showMovementsByHighwayPrice();
                    utils->clrScreen();
                }
                catch (DontExistAnyExitMovement &e) {
                    cout << "EXCEPTION: There are no exit movements." << endl;
                }
                break;
            case 3:
                utils->clrScreen();
                try {
                    showMovementsByDate();
                    utils->clrScreen();
                }
                catch (DontExistAnyMovement &e) {
                    cout << "EXCEPTION: There are no exit movements." << endl;
                }
                break;
        }
    } while (index);
}

void SystemNetwork::manageMovementsToll() {
    /*int index;
    Highway* a1;
    do {
        index = utils->ShowMenu({"By toll name", "By toll worth", "By toll type"});
        switch (index) {
            case 1:
                utils->clrScreen();
                a1 = chooseHighway();
                utils->clrScreen();
                if (a1 == nullptr) break;
                try {
                    showMovementsByTollName(a1);
                    utils->clrScreen();
                }
                catch (DontExistAnyMovement &e) {
                    cout << "EXCEPTION: There are no movements." << endl;
                }
                break;
            case 2:
                utils->clrScreen();
                a1 = chooseHighway();
                utils->clrScreen();
                if (a1 == nullptr) break;
                try {
                    showMovementsByTollPrice(a1);
                    utils->clrScreen();
                }
                catch (DontExistAnyExitMovement &e) {
                    cout << "EXCEPTION: There are no exit movements." << endl;
                }
                break;
            case 3:
                utils->clrScreen();
                a1 = chooseHighway();
                utils->clrScreen();
                if (a1 == nullptr) break;
                try {
                    showMovementsByTollType(a1);
                    utils->clrScreen();
                }
                catch (DontExistAnyMovement &e) {
                    cout << "EXCEPTION: There are no movements." << endl;
                }
                break;
        }
    } while (index);*/
}

void SystemNetwork::manageMovementsLane() {
    /*int index;
    Highway* a1;
    Toll* t1;
    do {
        index = utils->ShowMenu({"By lane number", "By lane price"});
        switch (index) {
            case 1:
                utils->clrScreen();
                a1 = chooseHighway();
                utils->clrScreen();
                if (a1 == nullptr) break;
                t1 = chooseToll(a1);
                utils->clrScreen();
                if (t1 == nullptr) break;
                try {
                    showMovementsbyLaneNumber(t1);
                    utils->clrScreen();
                }
                catch (DontExistAnyMovement &e) {
                    cout << "EXCEPTION: There are no movements." << endl;
                }
                break;
            case 2:
                utils->clrScreen();
                a1 = chooseHighway();
                utils->clrScreen();
                if (a1 == nullptr) break;
                t1 = chooseToll(a1);
                utils->clrScreen();
                if (t1 == nullptr) break;
                try {
                    showMovementsbyLanePrice(t1);
                    utils->clrScreen();
                }
                catch (DontExistAnyExitMovement &e) {
                    cout << "EXCEPTION: There are no exit movements." << endl;
                }
                break;
        }
    } while(index);*/
}

void SystemNetwork::manageMovementsCar() {
    int index;
    do {
        index = utils->ShowMenu({"By price", "By car distance", "By date"});
        switch (index) {
            case 1:
                utils->clrScreen();
                try {
                    showCarMovementsbyPrice();
                    utils->clrScreen();
                }
                catch (DontExistAnyExitMovement &e) {
                    cout << "EXCEPTION: There are no exit movements." << endl;
                }
                catch (VehicleDoesNotExist &e) {
                    cout << "EXCEPTION: There are no vehicles with the plate " << e.getPlate() << "." << endl;
                }
                break;
            case 2:
                utils->clrScreen();
                try {
                    showCarMovementsbyDistance();
                    utils->clrScreen();
                }
                catch (DontExistAnyExitMovement &e) {
                    cout << "EXCEPTION: There are no exit movements." << endl;
                }
                catch (VehicleDoesNotExist &e) {
                    cout << "EXCEPTION: There are no vehicles with the plate " << e.getPlate() << "." << endl;
                }
                break;
            case 3:
                utils->clrScreen();
                try {
                    showCarMovementsbyDate();
                    utils->clrScreen();
                }
                catch (DontExistAnyMovement &e) {
                    cout << "EXCEPTION: There are no movements." << endl;
                }
                catch (VehicleDoesNotExist &e) {
                    cout << "EXCEPTION: There are no vehicles with the plate " << e.getPlate() << "." << endl;
                }
                break;
        }
    } while(index);
}

void SystemNetwork::manageStatistics() {
    int index;
    do {
        index = utils->ShowMenu({"Best Worth Highway", "Best Worth Toll", "Best Worth Lane",
                                 "Vehicle that spend most money","Highway with more movements", "Toll with more movements",
                                 "Lane with more movements","Owner with more vehicles"});
        switch (index) {
            case 1:
                utils->clrScreen();
                try {
                    BestWorthHighway();
                    utils->clrScreen();
                }
                catch (DontExistAnyExitMovement &e) {
                    cout << "EXCEPTION: There are no exit movements." << endl;
                }
                break;
            case 2:
                utils->clrScreen();
                try {
                    BestWorthToll();
                    utils->clrScreen();
                }
                catch (DontExistAnyExitMovement &e) {
                    cout << "EXCEPTION: There are no exit movements." << endl;
                }
                break;
            case 3:
                utils->clrScreen();
                try {
                    BestWorthLane();
                    utils->clrScreen();
                }
                catch (DontExistAnyExitMovement &e) {
                    cout << "EXCEPTION: There are no exit movements." << endl;
                }
                break;
            case 4:
                utils->clrScreen();
                try {
                    carSpentMoreMoney();
                    utils->clrScreen();
                }
                catch (DontExistAnyExitMovement &e) {
                    cout << "EXCEPTION: There are no exit movements." << endl;
                }
                break;
            case 5:
                utils->clrScreen();
                try {
                    HighwayMoreMoves();
                    utils->clrScreen();
                }
                catch (DontExistAnyMovement &e) {
                    cout << "EXCEPTION: There are no movements." << endl;
                }
                break;
            case 6:
                utils->clrScreen();
                try {
                    TollMoreMoves();
                    utils->clrScreen();
                }
                catch (DontExistAnyMovement &e) {
                    cout << "EXCEPTION: There are no movements." << endl;
                }
                break;
            case 7:
                utils->clrScreen();
                try {
                    LaneMoreMoves();
                    utils->clrScreen();
                }
                catch (DontExistAnyMovement &e) {
                    cout << "EXCEPTION: There are no movements." << endl;
                }
                break;
            case 8:
                utils->clrScreen();
                ownerMoreVehicles();
                utils->clrScreen();
                break;
        }
    } while(index);
}



void SystemNetwork::createHighway() {
    string s_name;
    while (s_name != "EXIT") {
        cout << "Input the highway name: (if you want to exit without creating a highway please input EXIT)" << endl;
        getline(cin, s_name);
        if (s_name != "EXIT" && highways->addHighway(s_name)) {
            cout << "Highway created with success!" << endl;
            utils->waitForInput();
            break;
        }
        cout << "ERROR: name of highway already exists." << endl;
    }
}

void SystemNetwork::readHighways() {
    sqlite3_prepare(db,"select count(*) from Highways", -1, &stmt, nullptr);
    sqlite3_step(stmt);
    cout << "Highways: " << sqlite3_column_int(stmt,0) << endl;
    sqlite3_prepare(db,"select * from Highways", -1, &stmt, nullptr);
    int count = 0;
    while (sqlite3_step(stmt) != SQLITE_DONE) {
        cout << ++count << " - Highway Name: " << sqlite3_column_text(stmt,1) << endl;
    }
    utils->waitForInput();
    /*sqlite3_prepare(db,"select count(*) from Highways; select * from Highways;", -1, &stmt, nullptr);
    for (int i = 0; sqlite3_step(stmt) != SQLITE_DONE; i++) {
        if (i == 0)
            cout << "Highways: " << sqlite3_column_int(stmt,0) << endl;
        else
            cout << sqlite3_column_int(stmt,0) << " - " << sqlite3_column_text(stmt,1) << endl;
        //sqlite3_step(stmt);
    }*/
}

void SystemNetwork::updateHighway() {
    string s_index, s_name, s_menu;
    int id;
    id = chooseHighway();
    if (id > -1)
        while (s_name != "EXIT") {
            cout << "Input the highway name: (if you want to exit without updating a highway please input EXIT)" << endl;
            getline(cin, s_name);
            if (s_name != "EXIT" && !highways->checkHighwayName(s_name)) {
                highway->setName(id,s_name);
                cout << "Highway updated with success!" << endl;
                utils->waitForInput();
                break;
            }
            cout << "ERROR: name of highway already exists." << endl;
        }
}

void SystemNetwork::deleteHighway() {
    string s_index, s_name;
    int id;
    id = chooseHighway();
    if (id > -1)
        if (highways->removeHighway(id)) {
            cout << "Highway deleted with success!" << endl;
            utils->waitForInput();
        }
}

int SystemNetwork::chooseHighway() {
    int index;
    vector<int> id;
    vector<string> options;
    sqlite3_prepare_v2(db,"select * from highways;",-1,&stmt, nullptr);
    while (sqlite3_step(stmt) != SQLITE_DONE) {
        id.push_back(sqlite3_column_int(stmt,0));
        options.push_back("Highway Name: " + string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,1))));
    }
    index = utils->ShowMenu(options)-1;
    utils->clrScreen();
    if (index == -1)
        return -1;
    return id[index];
}

/*int SystemNetwork::chooseIndexHighway() const {
    vector<string> options;
    sqlite3_prepare_v2(db,"select name from highways;",-1,&stmt, nullptr);
    while (sqlite3_step(stmt) != SQLITE_DONE) {
        options.push_back("Highway Name: " + string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,0))));
    }
    utils->clrScreen();
    return utils->ShowMenu(options)-1;
    return 0;
}*/



void SystemNetwork::createToll(int highway_id) {
    string s_name, s_geolocal;
    float kilometer;
    int i_type;
    bool type;
    while (!(s_name == "EXIT" || kilometer == -1 || i_type == 0)) {
        cout << "Input the toll's name: (if you want to exit without creating a toll please input EXIT)" << endl;
        getline(cin, s_name);
        cout << !highway->checkTollName(highway_id, s_name) << endl;
        if (s_name != "EXIT" && !highway->checkTollName(highway_id,s_name)) {
            cout << "Input the toll's geographic location: (if you want to exit without creating a toll please input EXIT)"<< endl;
            getline(cin, s_geolocal);
            if (s_geolocal != "EXIT") {
                cout << "Input the toll's highway kilometer: (if you want to exit without creating a toll please input EXIT)"<< endl;
                kilometer = utils->getFloat();
                if (kilometer != -1) {
                    while(!(i_type == 1 || i_type == 2 || i_type == 0)) {
                        i_type = utils->ShowMenu({"Entrance - type","Exit - type"});
                    }
                    type = (i_type == 2);
                    if (i_type != 0) {
                        string query = "insert into tolls (highway_id,name,geolocal,highway_kilometer,type) values ("
                                + to_string(highway_id) + ",'" + s_name + "','" + s_geolocal + "'," + to_string(kilometer) + "," + to_string(type) + ")";
                        int rc = sqlite3_exec(db,query.c_str(),NULL,NULL,&err);
                        if (rc != SQLITE_OK) {
                            Utils::checkDbErr(rc);
                        }
                        utils->waitForInput();
                        break;
                    }
                }
            }
        }
        if(!(s_name == "EXIT" || kilometer == -1 || i_type == 0))
            cout << "ERROR: name of toll already exists." << endl;
    }
}

void SystemNetwork::readTolls(int highway_id) {
    string type, query = string("select count(*) from tolls where highway_id = ") + to_string(highway_id);
    sqlite3_prepare(db,query.c_str(),-1,&stmt, nullptr);
    sqlite3_step(stmt);
    cout << "Tolls: " << sqlite3_column_int(stmt,0) << endl;
    query = "select * from tolls where highway_id = " + to_string(highway_id);
    sqlite3_prepare(db,query.c_str(),-1,&stmt, nullptr);
    while (sqlite3_step(stmt) != SQLITE_DONE) {
        if (sqlite3_column_int(stmt,5) == 0) type = "Entrance";
        else type = "Exit";
        cout << "Toll Name: " << sqlite3_column_text(stmt,2) << " - Geographic Location: " << sqlite3_column_text(stmt,3)
                                << " - Highway Kilometer: " << sqlite3_column_double(stmt,4) << " - Type: " << type << endl;
    }
    utils->waitForInput();
}

void SystemNetwork::updateToll(int highway_id) {
    int index=0, toll_id = chooseToll(highway_id);
    float kilometer;
    string s_name;
    if (toll_id!= -1) index = utils->ShowMenu({"Toll's name","Toll's geographic location", "Toll's highway kilometer", "Toll's type"});
    switch (index) {
        case 0:
            break;
        case 1:
            while (s_name != "EXIT") {
                cout << "Input the toll name: (if you want to exit without creating a toll please input EXIT)" << endl;
                getline(cin, s_name);
                if (s_name != "EXIT" && !highway->checkTollName(highway_id, s_name)) {
                    toll->setName(toll_id,s_name);
                    cout << "Toll's name updated with success!" << endl;
                    utils->waitForInput();
                    break;
                }
                if (s_name!="EXIT")
                    cout << "ERROR: toll's name already exists." << endl;
            }
            break;
        case 2:
            cout << "Input the toll's geographic location: (if you want to exit without updating a toll please input EXIT)" << endl;
            getline(cin, s_name);
            if (s_name != "EXIT") {
                toll->setGeolocal(toll_id,s_name);
                cout << "Toll's geographic location updated with success!" << endl;
                utils->waitForInput();
                break;
            }
            break;
        case 3:
            kilometer = utils->getFloat();
            if (kilometer != -1)
                toll->setKilometer(toll_id,kilometer);
            break;
        case 4:

            /*if (highway->getTollIndex(toll_id)->getNumLanes() == 0) {
                cout << "Not possible to update toll's type because the toll have at least one lane" << endl;
                utils->waitForInput();
            }*/
            //else {
            do {
                index = utils->ShowMenu({"Entrance", "Exit"});
            } while (!(index == 1 || index == 2 || index == 0));
            if (index != 0) {
                toll->setType(toll_id,index == 2);
                cout << "Toll's type updated with success!" << endl;
                utils->waitForInput();
            }
            //}
    }
}

void SystemNetwork::deleteToll(int highway_id) {
    int toll_id;
    toll_id = chooseToll(highway_id);
    if (highway->removeToll(toll_id)) {
        cout << "Toll removed with success!" << endl;
        utils->waitForInput();
    }
}

int SystemNetwork::chooseToll(int highway_id) {
    vector<string> options;
    vector<int> id;
    string type,option,query = "select * from tolls where highway_id = " + to_string(highway_id);
    sqlite3_prepare_v2(db,query.c_str(),-1,&stmt, nullptr);
    while (sqlite3_step(stmt) != SQLITE_DONE) {
        id.push_back(sqlite3_column_int(stmt,0));
        if (sqlite3_column_int(stmt,5) == 0) type = "Entrance";
        else type = "Exit";
        option = "Toll Name: " + string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,2))) + " - Geographic Location: "
                + string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,3)))
                + " - Highway Kilometer: " + to_string(sqlite3_column_double(stmt,4)) + " - Type: " + type;
        options.push_back(option);
    }
    int index = utils->ShowMenu(options)-1;
    if (index == -1)
        return -1;
    return id[index];
}

/*int SystemNetwork::chooseIndexToll(Highway* highway) const {
    string s_type, s_menu;
    vector<string> v1;
    cout << "Tolls: " << highway->getNumTolls() << endl;
    for (size_t i = 0; i < highway->getNumTolls(); i++) {
        s_menu = highway->getTollIndex(i)->showToll();
        v1.push_back(s_menu);
    }
    utils->clrScreen();
    return utils->ShowMenu(v1)-1;
}*/



void SystemNetwork::createLane(int toll_id) {
    int index;
    if (!toll->getType()) {
        toll->addLane();
        cout << "Lane created with success!" << endl;
        utils->waitForInput();
    }
    else {
        index = utils->ShowMenu({"Normal lane", "Green lane"});
        if (index == 2) {
            toll->addLane();
            cout << "Lane created with success!" << endl;
            utils->waitForInput();
        }
        else if (index == 1) {
            if (employees->getNumEmployees() == 0) {
                cout << "ERROR: It's necessary to have at least one employee to add a normal lane in a exit toll." << endl;
                utils->waitForInput();
            }
            else {
                readEmployees();
                index = utils->getNumber(employees->getNumEmployees())-1;
                if (index > -1) {
                    toll->addLane(employees->getEmployeeIndex(index));
                    cout << "Lane created with success!" << endl;
                    utils->waitForInput();
                }
            }
        }
    }
}

void SystemNetwork::readLanes(int toll_id) {
    string query = "select * from lanes where toll_id = " + to_string(toll_id);
    sqlite3_prepare_v2(db,query.c_str(),-1,&stmt, nullptr);
    while (sqlite3_step(stmt) != SQLITE_DONE) {
        //por acabar
    }
}

void SystemNetwork::updateLane(int toll_id) {
    int lane_index, index;
    if (toll->getType()) {
        lane_index = chooseLane(toll_id);
        if (lane_index == -1) {}
        else if (toll->getLane(lane_index)->getGreenLane()) {
            index = utils->ShowMenu({"Green to normal lane"});
            if (index == 1) {
                index = chooseIndexEmployee();
                toll->setGreenLaneFalse(toll->getLane(lane_index),employees->getEmployeeIndex(index));
                cout << "Lane updated with success!" << endl;
                utils->waitForInput();
            }
        }
        else {
            index = utils->ShowMenu({"Normal to GreenLane", "Lane's employee"});
            if (index == 1) {
                toll->setGreenLaneTrue(toll->getLane(lane_index));
                cout << "Lane updated with success!" << endl;
                utils->waitForInput();
            }
            else if (index == 2) {
                index = chooseIndexEmployee();
                if (index > -1) {
                    toll->getLane(lane_index)->setEmployee(employees->getEmployeeIndex(index));
                    cout << "Lane's employee updated with success!" << endl;
                    utils->waitForInput();
                }
            }
        }
    }
    else {
        cout << "This is a entrance toll so there is nothing to update." << endl;
        utils->waitForInput();
    }
}

void SystemNetwork::deleteLane(int toll_id) {
    int lane_index;
    lane_index = chooseLane(toll_id);
    if (toll->removeLane(lane_index)) {
        cout << "Toll removed with success!" << endl;
        utils->waitForInput();
    }
}


int SystemNetwork::chooseLane(int toll_id) {
    vector<string> options;
    vector<int> id;
    string option, query = "select * from lanes where employee_id is null and toll_id = " + to_string(toll_id);
    sqlite3_prepare_v2(db,query.c_str(),-1,&stmt, nullptr);
    while (sqlite3_step(stmt) != SQLITE_DONE) {
        id.push_back(sqlite3_column_int(stmt,0));
        string s_greenlane = sqlite3_column_int(stmt,3) ? "True" : "False";
        option = "Lane Number: " + to_string(sqlite3_column_int(stmt,2)) + " - Greenlane: " + s_greenlane;
        options.push_back(option);
    }
    query = "select * from lanes,employees where Lanes.employee_id = Employees.id and Lanes.toll_id = " + to_string(toll_id);
    sqlite3_prepare_v2(db,query.c_str(),-1,&stmt, nullptr);
    while (sqlite3_step(stmt) != SQLITE_DONE) {
        id.push_back(sqlite3_column_int(stmt,0));
        string s_greenlane = sqlite3_column_int(stmt,3) ? "True" : "False";
        option = "Lane Number: " + to_string(sqlite3_column_int(stmt,2)) + " - Greenlane: " + s_greenlane + " - Employee Name: "
                + string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,6))) + " - Code: " + to_string(sqlite3_column_int(stmt,5));
        options.push_back(option);
    }
    int index = utils->ShowMenu(options) -1;
    if (index == -1)
        return -1;
    return id[index];
}

/*int SystemNetwork::chooseIndexLane(int toll_id) const {
    string s_type, s_menu;
    vector<string> v1;
    cout << "Lanes: " << toll->getNumLanes() << endl;
    for (size_t i = 0; i < toll->getNumLanes(); i++) {
        s_menu = toll->getLane(i)->showLane();
        v1.push_back(s_menu);
    }
    utils->clrScreen();
    return utils->ShowMenu(v1)-1;
}

int SystemNetwork::chooseIndexLane(Toll* toll,int index) const {
    string s_type, s_menu;
    vector<string> v1;
    cout << "Lanes: " << toll->getNumLanes() << endl;
    for (size_t i = 0; i < toll->getNumLanes(); i++) {
        s_menu = toll->getLane(i)->showLane();
        v1.push_back(s_menu);
    }
    utils->clrScreen();
    return utils->ShowMenu(v1,index)-1;
}*/

void SystemNetwork::createEmployee() {
    string s_name;
    while (s_name != "EXIT") {
        cout << "Input the employee name: (if you want to exit without creating a employee please input EXIT)" << endl;
        getline(cin, s_name);
        if (s_name != "EXIT" && employees->addEmployee(s_name)) {
            cout << "employee created with success!" << endl;
            utils->waitForInput();
            break;
        }
        if (s_name!= "EXIT")
            cout << "ERROR: name of employee already exists." << endl;
    }
}

void SystemNetwork::updateEmployee() {
    string s_index, s_name;
    int index;
    index = chooseIndexEmployee();
    if (index > -1)
        while (s_name != "EXIT") {
            cout << "Input the employee name: (if you want to exit without updating a employee please input EXIT)" << endl;
            getline(cin, s_name);
            if (s_name != "EXIT" && employees->checkEmployeeName(s_name)) {
                employees->getEmployeeIndex(index)->setName(s_name);
                cout << "Employee updated with success!" << endl;
                utils->waitForInput();
                break;
            }
            if (s_name != "EXIT")
                cout << "ERROR: name of employee already exists." << endl;
        }
}

void SystemNetwork::deleteEmployee() {
    int index;
    index = chooseIndexEmployee();
    if (index != -1) {
        employees->removeEmployee(index);
        cout << "Employee deleted with success!" << endl;
        utils->waitForInput();
    }
}

void SystemNetwork::readEmployees() {

    cout << "Employees: " << employees->getNumEmployees() << endl;

    for (int i = 0; i <employees->getNumEmployees(); i++) {
        cout << i+1 << " - " << employees->getEmployeeIndex(i)->showEmployee() << endl;
    }
    utils->waitForInput();
}

int SystemNetwork::chooseIndexEmployee() const {
    string s_menu;
    vector<string> v1;
    cout << "Employees: " << employees->getNumEmployees() << endl;
    for (int i = 0; i <employees->getNumEmployees(); i++) {
        s_menu = employees->getEmployeeIndex(i)->showEmployee();
        v1.push_back(s_menu);
    }
    utils->clrScreen();
    return utils->ShowMenu(v1)-1;
}



void SystemNetwork::createVehicle() {
    string s_plate;
    int v_class, greenlane;
    while (s_plate != "EXIT") {
        s_plate = utils->getPlate();
        if (s_plate != "EXIT") {
            if (!vehicles->checkPlate(s_plate)) {
                cout << "Choose the vehicle class: " << endl;
                v_class = utils->ShowMenu(
                        {"Classe 1 - Motas", "Classe 2 - Light vehicle (passengers or goods)", "Class 3 - Bus",
                         "Class 4 - Heavy goods vehicle "});
                if (v_class != 0) {
                    cout << "Choose one of the options: " << endl;
                    greenlane = utils->ShowMenu(
                            {"To travel on Green lanes or Normal lanes", "To travel just on Normal lanes"});
                    if (greenlane != 0) {
                        if (greenlane == 1) {
                            vehicles->addVehicle(s_plate, v_class, true);
                        } else {
                            vehicles->addVehicle(s_plate, v_class);
                        }
                        cout << "Vehicle created with success!" << endl;
                        utils->waitForInput();
                        break;
                    } else if (greenlane == 0)
                        s_plate = "EXIT";
                } else if (v_class == 0)
                    s_plate = "EXIT";
            }
        }
        if (!(s_plate == "EXIT" || v_class == 0 || greenlane == 0))
            cout << "ERROR: plate of vehicle already exists." << endl;
    }
}

void SystemNetwork::updateVehicle() {
    string s_index, s_plate;
    int v_index,index;
    v_index = chooseIndexVehicle();
    if (v_index > -1) {
        index = utils->ShowMenu({"Plate", "Vehicle class", "Type of lanes to travel"});
        switch (index) {
            case 1:
                while (s_plate != "EXIT") {
                    s_plate = utils->getPlate();
                    if (s_plate != "EXIT" && !vehicles->checkPlate(s_plate)) {
                        vehicles->getVehicleIndex(v_index)->setPlate(s_plate);
                        cout << "Vehicle updated with success!" << endl;
                        utils->waitForInput();
                        break;
                    }
                    if (s_plate != "EXIT")
                        cout << "ERROR: plate of vehicle already exists." << endl;
                }
                break;
            case 2:
                cout << "Choose the vehicle class: " << endl;
                index = utils->ShowMenu({"Classe 1 - Motas", "Classe 2 - Light vehicle (passengers or goods)", "Class 3 - Bus", "Class 4 - Heavy goods vehicle "});
                if (index != 0) {
                    vehicles->getVehicleIndex(v_index)->setVehicleClass(index);
                    cout << "Vehicle updated with success!" << endl;
                    utils->waitForInput();
                }
                break;
            case 3:
                cout << "Choose one of the options: " << endl;
                index = utils->ShowMenu({"To travel on Green lanes or Normal lanes", "To travel just on Normal lanes"});
                if (index == 1) {
                    vehicles->getVehicleIndex(v_index)->setGreenLaneTrue();
                    cout << "Vehicle updated with success!" << endl;
                    utils->waitForInput();
                }
                else if (index == 2) {
                    vehicles->getVehicleIndex(v_index)->setGreenLaneFalse();
                    cout << "Vehicle updated with success!" << endl;
                    utils->waitForInput();
                }
                break;
        }
    }
}

void SystemNetwork::deleteVehicle() {
    int index;
    index = chooseIndexVehicle();
    if (index > -1) {
        vehicles->removeVehicle(index);
        cout << "Vehicle deleted with success!" << endl;
        utils->waitForInput();
    }
}

void SystemNetwork::readVehicles() {
    string string1;
    cout << "Vehicles: " << vehicles->getNumVehicles() << endl;
    for (int i = 0; i < vehicles->getNumVehicles(); i++) {
        cout << vehicles->getVehicleIndex(i)->showVehicle() << endl;
    }
    utils->waitForInput();
}

int SystemNetwork::chooseIndexVehicle() const {
    string string1, s_menu;
    vector<string> v1;
    cout << "Vehicles: " << vehicles->getNumVehicles() << endl;
    for (int i = 0; i < vehicles->getNumVehicles(); i++) {
        s_menu = vehicles->getVehicleIndex(i)->showVehicle();
        v1.push_back(s_menu);
    }
    return utils->ShowMenu(v1)-1;
}



void SystemNetwork::getTaxesFromUser() {
    float taxe[4];
    bool exit = false;
    for (int i = 0; i < 4; i++) {
        cout << "Input the tax (euro per kilometer) for the class " << i+1 << ". (if you want to exit without setting a tax please input EXIT) " << endl;
        float a = utils->getFloat();
        if (a == -1) {
            exit = true;
            break;
        }
        else taxe[i] = a;
    }
    if (!exit) {
        vehicles->setTaxes(taxe[0], taxe[1], taxe[2], taxe[3]);
        for (size_t i = 0; i < vehicles->getNumVehicles(); i++) {
            switch (vehicles->getVehicleIndex(i)->getClass()) {
                case 1:
                    vehicles->getVehicleIndex(i)->setTax(taxe[0]);
                    break;
                case 2:
                    vehicles->getVehicleIndex(i)->setTax(taxe[1]);
                    break;
                case 3:
                    vehicles->getVehicleIndex(i)->setTax(taxe[2]);
                    break;
                case 4:
                    vehicles->getVehicleIndex(i)->setTax(taxe[3]);
                    break;
            }
        }
        cout << "Taxes updated with success!" << endl;
        utils->waitForInput();
    }
}

int SystemNetwork::adviceEntryLane(Toll * toll, Date * date) {
    int min = -1, counter = 0, index;
    for (size_t i = 0; i < toll->getNumLanes(); i++) {
        counter = 0;
        for (size_t j = 0; j < movements->getNumMovements(); j++) {
            if (*movements->getMovementIndex(j)->getToll() ==  *toll) {
                if (movements->getMovementIndex(j)->getDate()->dayEqual(*date))
                    if (*movements->getMovementIndex(j)->getLane() == *toll->getLane(i))
                        counter++;
            }
        }
        if (min == -1 || counter < min) {
            min = counter;
            index = i;
        }
    }
    return index;
}

int SystemNetwork::adviceOutLane(Vehicle* vehicle, Toll * toll, Date * date) {
    int min = -1, counter = 0, index;
    for (size_t i = 0; i < toll->getNumLanes(); i++) {
        if (!vehicle->getGreenLaneBool() && toll->getLane(i)->getGreenLane()) {
            continue;
        }
        counter = 0;
        for (size_t j = 0; j < movements->getNumMovements(); j++) {
            if (*movements->getMovementIndex(j)->getToll() ==  *toll) {
                if (movements->getMovementIndex(j)->getDate()->dayEqual(*date))
                    if (*movements->getMovementIndex(j)->getLane() == *toll->getLane(i))
                        counter++;
            }
        }
        if (min == -1) {
            min = counter;
            index = i;
        }
        else if (counter < min) {
            min = counter;
            index = i;
        }
    }
    return index;
}

void SystemNetwork::addEntryMovement() {

    /*string s_plate,s_name;
    int index = -1, lane_index;
    Vehicle* vehicle = nullptr;

    Highway* highway = nullptr;
    Toll *toll = nullptr;

    Date* date = utils->getDate();
    while (s_plate != "EXIT" && index != 0) {
        if (vehicles->getTaxes(1) == -1 || vehicles->getTaxes(2) == -1 || vehicles->getTaxes(3) == -1 || vehicles->getTaxes(4) == -1) {
            cout << "ERROR: Before this you have to input the taxes for each vehicle class" << index << endl;
            s_plate = "EXIT";
            //utils->waitForInput();
            continue;
        }
        s_plate = utils->getPlate();
        if (s_plate == "EXIT") continue;
        if (!vehicles->checkPlate(s_plate)) {
            cout << "Vehicle is not registed. To advance, input vehicle class" << endl;
            index = utils->ShowMenu({"Classe 1 - Motas", "Classe 2 - Light vehicle (passengers or goods)", "Class 3 - Bus", "Class 4 - Heavy goods vehicle "});
            if (index != 0)
                vehicle = new Vehicle(s_plate,index,vehicles->getTaxes(index));
            else continue;
        }
        else {
            int counter = 0;
            for (int i = 0; i < movements->getNumMovements(); i++){
                if (movements->getMovementIndex(i)->getVehicle()->getPlate() == s_plate) {
                    counter++;
                }
            }
            if (counter % 2 == 1) {
                vehicle = nullptr;
            }
            else if (counter % 2 == 0 || counter == 0) {
                vehicle = vehicles->getVehicle(s_plate);
            }
        }
        if (vehicle == nullptr) {
            cout << "ERROR: This vehicle is already in a highway." << endl;
            continue;
        }
        while (s_name.empty()) {
            cout << endl << "Input the owner of the vehicle: (if you want to exit without creating a employee please input EXIT)"
                 << endl;
            getline(cin, s_name);
        }
        if (s_name == "EXIT")
            s_plate = "EXIT";
        owners->addOwner(s_name);
        auto u = owners->getOwners();
        bool check = false;
        for (Owner o: u)
            for (Vehicle* v: o.getVehicles())
                if (v->getPlate() == s_plate)
                    check = true;
        if (!check)
            owners->addVehicleOwner(s_name,vehicle);
        do {
            highway = chooseHighway();
            if (highway == nullptr) {
                s_plate = "EXIT";
                //utils->waitForInput();
                break;
            }
            if (highway->getNumTolls() == 0) {
                cout << "ERROR: This highway doesn't have a toll." << endl;
            }
        } while (highway->getNumTolls() == 0);
        if (s_plate == "EXIT") continue;
        do {
            toll = chooseToll(highway);
            if (toll == nullptr) {
                s_plate = "EXIT";
                //utils->waitForInput();
                break;
            }
            if (toll->getType()) {
                cout << "ERROR: This is an exit toll." << endl;
            }
            if (toll->getNumLanes() == 0) {
                cout << "ERROR: This toll doesn't have a lane." << endl;
            }
        } while(toll->getNumLanes() == 0 || toll->getType());
        if (s_plate == "EXIT") continue;
        Lane *lane = chooseLane(toll,adviceEntryLane(toll, date));
        if (lane == nullptr) {
            s_plate = "EXIT";
            continue;
        }

        auto* m1 = new MovementEntry(vehicle, highway, toll, lane, date);
        movements->addMovement(m1);
        cout << "Entry movement created with success!" << endl;
        break;
    }
    utils->waitForInput();*/
}

void SystemNetwork::addExitMovement() {
    /*string s_plate;
    int lane_index;
    Movement* entry = nullptr;
    Highway* highway = nullptr;
    Toll *toll = nullptr;
    Lane *lane = nullptr;
    while (s_plate != "EXIT") {
        if (movements->getNumMovements() == 0) {
            cout << "ERROR: Before you do this you have to add a entry movement" << endl;
            //utils->waitForInput();
            s_plate = "EXIT";
            continue;
        }
        s_plate = utils->getPlate();
        if (s_plate == "EXIT") continue;

        int counter = 0;
        for (int i = 0; i < movements->getNumMovements(); i++){
            if (movements->getMovementIndex(i)->getVehicle()->getPlate() == s_plate) {
                counter++;
            }
        }
        if (counter % 2 == 0 || counter == 0) {
            entry = nullptr;
        }
        if (counter % 2 == 1 && counter != 0) {
            for (int i = movements->getNumMovements() - 1; i > -1; i-- ) {
                if (s_plate == movements->getMovementIndex(i)->getVehicle()->getPlate()) {
                    if (!movements->getMovementIndex(i)->getType()) {
                        entry = movements->getMovementIndex(i);
                        break;
                    }
                }
            }
        }
        if (entry == nullptr) {
            cout << "ERROR: Vehicle isn't in a highway." << endl;
            //utils->waitForInput();
            continue;
        }
        highway = entry->getHighway();
        do {
            toll = chooseToll(highway);
            if (toll == nullptr) {
                s_plate = "EXIT";
                break;
            }
            if (!toll->getType()) {
                cout << "ERROR: This is a entrance toll." << endl;
            }
            if (toll->getNumLanes() == 0) {
                cout << "ERROR: This toll doesn't have a lane." << endl;
            }
        } while(toll->getNumLanes() == 0 || !toll->getType());
        if (s_plate == "EXIT") continue;
        Date* date = utils->getDate();
        lane_index = adviceOutLane(entry->getVehicle(), toll, date);
        cout << "Our advice: Lane " << lane_index << ". (Lane with less traffic)" << endl;
        do {
            lane = chooseLane(toll,adviceEntryLane(toll, date));
            if (lane == nullptr) {
                s_plate = "EXIT";
                break;
            }
            if (!entry->getVehicle()->getGreenLaneBool() && lane->getGreenLane()) {
                cout << "ERROR: This is a green lane and your car only travels on normal lanes." << endl;
            }
        } while(!entry->getVehicle()->getGreenLaneBool() && lane->getGreenLane());

        if (lane == nullptr) {
            s_plate = "EXIT";
            //utils->waitForInput();
            continue;
        }

        auto *m1 = new MovementOut(entry->getVehicle(),highway,toll,lane,date,entry);
        movements->addMovement(m1);
        cout << "Exit movement created with success!" << endl;
        break;
    }
    utils->waitForInput();*/
}

void SystemNetwork::showMovementsByHighwayName() {
    if (movements->getNumMovements() == 0) throw DontExistAnyMovement();
    if (movements->getNumMovements() == 0)
        cout << "There are no Highways" << endl;
    if (movements->getNumMovements() == 0)
        cout << "There are no movements" << endl;
    vector<Movement*> v1 = movements->getMovements();
    sort(v1.begin(),v1.end(),[](Movement* m1,Movement* m2){
        return (m1->getHighway()->getInfo() < m2->getHighway()->getInfo());
    });
    for (size_t i = 0; i < v1.size(); i++) {
        cout << i+1 << " - " << v1[i]->showMovement() << endl;
    }
    utils->waitForInput();
}

void SystemNetwork::showMovementsByHighwayPrice() {
    if (highways->getNumHighways() <= 1) throw DontExistAnyExitMovement();
    if (movements->getNumMovements() == 0)
        cout << "There are no Highways" << endl;
    if (movements->getNumMovements() == 0)
        cout << "There are no movements" << endl;
    vector<Movement*> v1;
    for (size_t i = 0; i < movements->getNumMovements(); i++) {
        if (movements->getMovementIndex(i)->getType()==1)
            v1.push_back(movements->getMovementIndex(i));
    }
    sort(v1.begin(),v1.end(),[](Movement* m1,Movement* m2){
        return (m1->getPrice() > m2->getPrice());
    });
    for (size_t i = 0; i < v1.size(); i++) {
        cout << i+1 << " - " << v1[i]->showMovement() << endl;
    }
    utils->waitForInput();
}

void SystemNetwork::showMovementsByDate() {
    if (movements->getNumMovements() == 0) throw DontExistAnyMovement();
    vector<Movement*> v1 = movements->getMovements();
    sort(v1.begin(),v1.end(),[](Movement* m1,Movement* m2){
        return (*(m1->getDate()) > *(m2->getDate()));
    });
    for (size_t i = 0; i < v1.size(); i++) {
        cout << i+1 << " - " << v1[i]->showMovement() << endl;
    }
    utils->waitForInput();
}

void SystemNetwork::showMovementsByTollName(Highway* highway) {
    if (movements->getNumMovements() == 0) throw DontExistAnyMovement();
    vector<Movement*> v1;
    for (size_t i = 0; i < movements->getNumMovements(); i++) {
        if (movements->getMovementIndex(i)->getHighway()==highway)
            v1.push_back(movements->getMovementIndex(i));
    }
    sort(v1.begin(),v1.end(),[](Movement* m1,Movement* m2){
        return (m1->getToll()->getName() < m2->getToll()->getName());
    });
    for (size_t i = 0; i < v1.size(); i++) {
        cout << i+1 << " - " << v1[i]->showMovement() << endl;
    }
    utils->waitForInput();
}

void SystemNetwork::showMovementsByTollPrice(Highway *highway) {
    if (movements->getNumMovements() <= 1) throw DontExistAnyExitMovement();
    vector<Movement*> v1;
    for (size_t i = 0; i < movements->getNumMovements(); i++) {
        if (movements->getMovementIndex(i)->getHighway()==highway && movements->getMovementIndex(i)->getType())
            v1.push_back(movements->getMovementIndex(i));
    }
    sort(v1.begin(),v1.end(),[](Movement* m1, Movement* m2){
        return (m1->getPrice() > m2->getPrice());
    });
    for (size_t i = 0; i < v1.size(); i++) {
        cout << i+1 << " - " << v1[i]->showMovement() << endl;
    }
    utils->waitForInput();
}



void SystemNetwork::showMovementsByTollType(Highway *highway) {
    if (movements->getNumMovements() == 0) throw DontExistAnyMovement();
    vector<Movement*> v1;
    for (size_t i = 0; i < movements->getNumMovements(); i++) {
        if (movements->getMovementIndex(i)->getHighway()==highway)
            v1.push_back(movements->getMovementIndex(i));
    }
    sort(v1.begin(),v1.end(),[](Movement* m1,Movement* m2){
        return (m1->getToll()->getType() < m2->getToll()->getType());
    });
    for (size_t i = 0; i < v1.size(); i++) {
        cout << i+1 << " - " << v1[i]->showMovement() << endl;
    }
    utils->waitForInput();
}



void SystemNetwork::showMovementsbyLaneNumber(Toll *toll) {
    if (movements->getNumMovements() == 0) throw DontExistAnyMovement();
    vector<Movement*> v1;
    for (size_t i = 0; i < movements->getNumMovements(); i++) {
        if (movements->getMovementIndex(i)->getToll()==toll )
            v1.push_back(movements->getMovementIndex(i));
    }
    sort(v1.begin(),v1.end(),[](Movement* m1,Movement* m2){
        return (m1->getLane()->getLaneNumber() < m2->getLane()->getLaneNumber());
    });
    for (size_t i = 0; i < v1.size(); i++) {
        cout << i+1 << " - " << v1[i]->showMovement() << endl;
    }
    utils->waitForInput();
}



void SystemNetwork::showMovementsbyLanePrice(Toll *toll) {
    if (movements->getNumMovements() <= 1) throw DontExistAnyExitMovement();
    vector<Movement*> v1;
    for (size_t i = 0; i < movements->getNumMovements(); i++) {
        if (movements->getMovementIndex(i)->getToll() == toll && movements->getMovementIndex(i)->getType())
            v1.push_back(movements->getMovementIndex(i));
    }
    sort(v1.begin(),v1.end(),[](Movement* m1,Movement* m2){
        return (m1->getPrice() > m2->getPrice());
    });
    for (size_t i = 0; i < v1.size(); i++) {
        cout << i+1 << " - " << v1[i]->showMovement() << endl;
    }
    utils->waitForInput();
}



void SystemNetwork::showCarMovementsbyDate() {
    if (movements->getNumMovements() == 0) throw DontExistAnyMovement();
    string s_plate;
    int v_class, greenlane;
    bool check = false;
    while (s_plate != "EXIT") {
        s_plate = utils->getPlate();
        if (s_plate != "EXIT") {
            for (size_t i = 0; i < vehicles->getNumVehicles(); i++) {
                if (vehicles->getVehicleIndex(i)->getPlate() == s_plate) {
                    check = true;
                    break;
                }
            }
            if (!check) {
                throw VehicleDoesNotExist(s_plate);
                break;
            }
            if (check) break;
        }
    }
    if (s_plate != "EXIT") {
        vector<Movement*> v1;
        for (size_t i = 0; i < movements->getNumMovements(); i++) {
            if (movements->getMovementIndex(i)->getVehicle()->getPlate() == s_plate)
                v1.push_back(movements->getMovementIndex(i));
        }
        sort(v1.begin(),v1.end(),[](Movement* m1,Movement* m2){
            return (*(m1->getDate()) > *(m2->getDate()));
        });
        for (size_t i = 0; i < v1.size(); i++) {
            cout << i+1 << " - " << v1[i]->showMovement() << endl;
        }
    }
    utils->waitForInput();
}



void SystemNetwork::showCarMovementsbyDistance() {
    if (movements->getNumMovements() <= 1) throw DontExistAnyExitMovement();
    string s_plate;
    int v_class, greenlane;
    bool check = false;
    while (s_plate != "EXIT") {
        s_plate = utils->getPlate();
        if (s_plate != "EXIT") {
            for (size_t i = 0; i < vehicles->getNumVehicles(); i++) {
                if (vehicles->getVehicleIndex(i)->getPlate() == s_plate) {
                    check = true;
                    break;
                }
            }
            if (!check) {
                throw VehicleDoesNotExist(s_plate);
                break;
            }
            if (check) break;
        }
    }
    if (s_plate != "EXIT") {
        vector<Movement*> v1;
        for (size_t i = 0; i < movements->getNumMovements(); i++) {
            if (movements->getMovementIndex(i)->getType() && movements->getMovementIndex(i)->getVehicle()->getPlate() == s_plate)
                v1.push_back(movements->getMovementIndex(i));
        }
        sort(v1.begin(),v1.end(),[](Movement* m1,Movement* m2){
            return (m1->getDistance() > m2->getDistance());
        });
        for (size_t i = 0; i < v1.size(); i++) {
            cout << i+1 << " - " << v1[i]->showMovement() << endl;
        }
    }
    utils->waitForInput();
}



void SystemNetwork::showCarMovementsbyPrice() {
    if (movements->getNumMovements() <= 1) throw DontExistAnyExitMovement();
    string s_plate;
    int v_class, greenlane;
    bool check = false;
    while (s_plate != "EXIT") {
        s_plate = utils->getPlate();
        if (s_plate != "EXIT") {
            for (size_t i = 0; i < vehicles->getNumVehicles(); i++) {
                if (vehicles->getVehicleIndex(i)->getPlate() == s_plate) {
                    check = true;
                    break;
                }
            }
            if (!check) {
                throw VehicleDoesNotExist(s_plate);
                break;
            }
            if (check) break;
        }
    }
    if (s_plate != "EXIT") {
        vector<Movement*> v1;
        for (size_t i = 0; i < movements->getNumMovements(); i++) {
            if (movements->getMovementIndex(i)->getType() && movements->getMovementIndex(i)->getVehicle()->getPlate() == s_plate)
                v1.push_back(movements->getMovementIndex(i));
        }
        sort(v1.begin(),v1.end(),[](Movement* m1,Movement* m2){
            return (m1->getDistance() > m2->getDistance());
        });
        for (size_t i = 0; i < v1.size(); i++) {
            cout << i+1 << " - " << v1[i]->showMovement() << endl;
        }
    }
    utils->waitForInput();
}



void SystemNetwork::showEmployeeMovements() {
    if (movements->getNumMovements() == 0) throw DontExistAnyMovement();
    string s_name;
    bool check = false;
    while (s_name != "EXIT") {
        cout << "Input the employee name: (if you want to exit without creating an employee please input EXIT)" << endl;
        getline(cin, s_name);
        if (s_name != "EXIT") {
            for (size_t i = 0; i < employees->getNumEmployees(); i++) {
                if (employees->getEmployeeIndex(i)->getName() == s_name) {
                    check = true;
                    break;
                }
            }
            if (!check) {
                throw EmployeeDoesNotExist(s_name);
                break;
            }
            if (check) break;
        }
    }
    if (s_name != "EXIT") {
        vector<Movement*> v1;
        for (size_t i = 0; i < movements->getNumMovements(); i++) {
            if (movements->getMovementIndex(i)->getType() && !movements->getMovementIndex(i)->getLane()->getGreenLane()
                && movements->getMovementIndex(i)->getLane()->getEmployee()->getName() == s_name)
                v1.push_back(movements->getMovementIndex(i));
        }
        sort(v1.begin(),v1.end(),[](Movement* m1,Movement* m2){
            return (m1->getDate() > m2->getDate());
        });
        for (size_t i = 0; i < v1.size(); i++) {
            cout << i+1 << " - " << v1[i]->showMovement() << endl;
        }
    }
    utils->waitForInput();
}



void SystemNetwork::carSpentMoreMoney() {
    if (movements->getNumMovements() <= 1) throw DontExistAnyExitMovement();
    Vehicle* vehicle;
    float total_price = 0, price;
    for (size_t i = 0; i <vehicles->getNumVehicles();i++) {
        price = 0;
        for (size_t j = 0; j < movements->getNumMovements(); j++) {
            if (movements->getMovementIndex(j)->getType() &&
                movements->getMovementIndex(j)->getVehicle()->getPlate() == vehicles->getVehicleIndex(i)->getPlate()) {
                price += movements->getMovementIndex(j)->getPrice();
            }
        }
        if (price > total_price) {
            total_price = price;
            vehicle = vehicles->getVehicleIndex(i);
        }
    }
    cout << vehicle->showVehicle() << " - Total price = " << total_price << endl;
    utils->waitForInput();
}



void SystemNetwork::BestWorthHighway() {
    if (movements->getNumMovements() <= 1) throw DontExistAnyExitMovement();
    Highway* highway;
    float total_price = 0, price;
    for (size_t i = 0; i <highways->getNumHighways();i++) {
        price = 0;
        for (size_t j = 0; j < movements->getNumMovements(); j++) {
            if (movements->getMovementIndex(j)->getType() && movements->getMovementIndex(j)->getHighway()->getInfo() == highways->getHighwayIndex(i)->getInfo())
                price += movements->getMovementIndex(j)->getPrice();
        }
        if (price > total_price) {
            total_price = price;
            highway = highways->getHighwayIndex(i);
        }
    }
    cout << highway->showHighway() << " - Total price = " << total_price << endl;
    utils->waitForInput();
}



void SystemNetwork::BestWorthToll() {
    if (movements->getNumMovements() <= 1) throw DontExistAnyExitMovement();
    Toll* toll;
    float total_price = 0, price;
    for (size_t i = 0; i <highways->getNumHighways();i++) {
        for (size_t k = 0; k < highways->getHighwayIndex(i)->getNumTolls(); k++) {
            price = 0;
            for (size_t j = 0; j < movements->getNumMovements(); j++) {
                if (movements->getMovementIndex(j)->getType() &&
                    movements->getMovementIndex(j)->getToll()->getName() == highways->getHighwayIndex(i)->getTollIndex(k)->getName())
                    price += movements->getMovementIndex(j)->getPrice();
            }
            if (price > total_price) {
                total_price = price;
                toll = highways->getHighwayIndex(i)->getTollIndex(k);
            }
        }
    }
    cout << toll->showToll() << " - Total price = " << total_price << endl;
    utils->waitForInput();
}



void SystemNetwork::BestWorthLane() {
    if (movements->getNumMovements() <= 1) throw DontExistAnyExitMovement();
    Lane* lane;
    float total_price = 0, price;
    for (size_t i = 0; i <highways->getNumHighways();i++) {
        for (size_t k = 0; k < highways->getHighwayIndex(i)->getNumTolls(); k++) {
            for (size_t l = 0; l < highways->getHighwayIndex(i)->getTollIndex(k)->getNumLanes(); l++) {
                price = 0;
                for (size_t j = 0; j < movements->getNumMovements(); j++) {
                    if (movements->getMovementIndex(j)->getType() &&
                        movements->getMovementIndex(j)->getLane() ==
                        highways->getHighwayIndex(i)->getTollIndex(k)->getLane(l))
                        price += movements->getMovementIndex(j)->getPrice();
                }
                if (price > total_price) {
                    total_price = price;
                    lane = highways->getHighwayIndex(i)->getTollIndex(k)->getLane(l);
                }
            }
        }
    }
    cout << lane->showLane() << " - Total price = " << total_price << endl;
    utils->waitForInput();
}



void SystemNetwork::HighwayMoreMoves() {
    if (movements->getNumMovements() == 0) throw DontExistAnyMovement();
    Highway* highway;
    int total_moves = 0, moves;
    for (size_t i = 0; i <highways->getNumHighways();i++) {
        moves = 0;
        for (size_t j = 0; j < movements->getNumMovements(); j++) {
            if (movements->getMovementIndex(j)->getHighway()->getInfo() == highways->getHighwayIndex(i)->getInfo())
                moves++;
        }
        if (moves > total_moves) {
            total_moves = moves;
            highway = highways->getHighwayIndex(i);
        }
    }
    cout << highway->showHighway() << " - Total moves = " << total_moves << endl;
    utils->waitForInput();
}



void SystemNetwork::TollMoreMoves() {
    if (movements->getNumMovements() == 0) throw DontExistAnyMovement();
    Toll* toll;
    Highway* highway;
    int total_moves = 0, moves;
    for (size_t i = 0; i <highways->getNumHighways();i++) {
        for (size_t k = 0; k < highways->getHighwayIndex(i)->getNumTolls(); k++) {
            moves = 0;
            for (size_t j = 0; j < movements->getNumMovements(); j++) {
                if (movements->getMovementIndex(j)->getToll() == highways->getHighwayIndex(i)->getTollIndex(k))
                    moves++;
            }
            if (moves > total_moves) {
                total_moves = moves;
                toll = highways->getHighwayIndex(i)->getTollIndex(k);
                highway = highways->getHighwayIndex(i);
            }
        }
    }
    cout << highway->showHighway() << " - " << toll->showToll() << " - Total moves = " << total_moves << endl;
    utils->waitForInput();
}



void SystemNetwork::LaneMoreMoves() {
    if (movements->getNumMovements() == 0) throw DontExistAnyMovement();
    Lane* lane;
    Highway* highway;
    Toll* toll;
    int total_moves = 0, moves;
    for (size_t i = 0; i <highways->getNumHighways();i++) {
        for (size_t k = 0; k < highways->getHighwayIndex(i)->getNumTolls(); k++) {
            for (size_t l = 0; l < highways->getHighwayIndex(i)->getTollIndex(k)->getNumLanes(); l++) {
                moves = 0;
                for (size_t j = 0; j < movements->getNumMovements(); j++) {
                    if (movements->getMovementIndex(j)->getLane() ==
                        highways->getHighwayIndex(i)->getTollIndex(k)->getLane(l))
                        moves++;
                }
                if (moves > total_moves) {
                    total_moves = moves;
                    lane = highways->getHighwayIndex(i)->getTollIndex(k)->getLane(l);
                    toll = highways->getHighwayIndex(i)->getTollIndex(k);
                    highway = highways->getHighwayIndex(i);
                }
            }
        }
    }
    cout << highway->showHighway() << " - Toll name: "<< toll->getName() << " - " << lane->showLane() << " - Total moves = " << total_moves << endl;
    utils->waitForInput();
}



void SystemNetwork::manageInterventions() {
    int index;
    do {
        utils->clrScreen();
        index = utils->ShowMenu({"Add Intervention", "Conclude Intervention", "Read Interventions"});
        switch(index) {
            case 1:
                utils->clrScreen();
                addIntervention();
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                concludeIntervention();
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                manageReadInterventions();
                utils->clrScreen();
                break;
        }
    } while(index);
}



void SystemNetwork::manageReadInterventions() {
    int index;
    do {
        index = utils->ShowMenu({"Read All Interventions", "Read One-day Interventions", "Interventions by Type", "Interventions by a Technician"});
        switch(index) {
            case 1:
                utils->clrScreen();
                readInterventions();
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                readInterventionsDay();
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                readInterventionsType();
                utils->clrScreen();
                break;
            case 4:
                utils->clrScreen();
                readInterventionsTechnician();
                utils->clrScreen();
                break;
        }
    } while(index);
}



void SystemNetwork::manageTechnicians() {
    int index;
    do {
        index = utils->ShowMenu({"Create Technician", "Read Technician", "Update Technician", "Delete Technician"});
        switch(index) {
            case 1:
                utils->clrScreen();
                createTechnician();
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                readTechnicians();
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                updateTechnician();
                utils->clrScreen();
                break;
            case 4:
                utils->clrScreen();
                deleteTechnician();
                utils->clrScreen();
                break;
        }
    } while(index);
}



void SystemNetwork::manageOwners() {
    int index;
    do {
        index = utils->ShowMenu({"Read Owners","Manage Owner"});
        switch(index) {
            case 1:
                utils->clrScreen();
                manageReadOwners();
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                index = utils->ShowMenu(owners->showOwners())-1;
                utils->clrScreen();
                if (index < 0) break;
                manageOwner(owners->getOwner(index));
                utils->clrScreen();
                break;
        }
    } while(index);
}



void SystemNetwork::manageReadOwners() {
    int index;
    do {
        index = utils->ShowMenu({"Read all owners","Read owners by quantity of vehicles", "Owner of a vehicle"});
        switch(index) {
            case 1:
                utils->clrScreen();
                readOwners();
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                readOwnersNumVehicles();
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                readOwnerVehicle();
                utils->clrScreen();
                break;
        }
    } while(index);
}



void SystemNetwork::manageOwner(Owner o1) {
    int index;
    do {
        index = utils->ShowMenu({"Add Vehicle", "Read Vehicles","Remove Vehicle"});
        switch(index) {
            case 1:
                utils->clrScreen();
                addVehicleOwner(o1);
                utils->clrScreen();
                break;
            case 2:
                utils->clrScreen();
                readVehiclesOwner(o1);
                utils->clrScreen();
                break;
            case 3:
                utils->clrScreen();
                deleteVehicleOwner(o1);
                utils->clrScreen();
                break;
        }
    } while(index);
}



void SystemNetwork::addIntervention() {
    /*string s_type;
    Highway* highway = chooseHighway();
    if (highway == nullptr) {
        utils->waitForInput();
        return;
    }
    Toll* toll = chooseToll(highway);
    if (toll == nullptr) {
        utils->waitForInput();
        return;
    }
    int index = utils->ShowMenu({"Review Technician","Electronics Technician","Informatic Technician"});
    if (index == 0) {
        utils->waitForInput();
        return;
    }
    switch (index) {
        case 1:
            s_type = "review";
            break;
        case 2:
            s_type = "eletronic";
            break;
        case 3:
            s_type = "informatic";
            break;
    }
    Date* start_date = utils->getDate();
    Technician* technician = toll->getTechnicianSpeciality(s_type);
    if (technician == nullptr) {
        vector<Toll *> tolls = highway->sortTollDistance(toll);
        for (Toll* tol : tolls) {
            technician = tol->getTechnicianSpeciality(s_type);
            if (technician != nullptr)
                break;
        }
    }
    if (technician == nullptr) {
        cout << "ERROR: There's no technician of this specialty on this highway." << endl;
        utils->waitForInput();
        return;
    }
    Intervention i(s_type,technician,start_date, highway, toll);
    if (interventions->addIntervention(i))
        cout << "Intervention started with success!" << endl;
    utils->waitForInput();*/
}



void SystemNetwork::concludeIntervention() {
    int index = utils->ShowMenu(interventions->showInterventionsNotConcluded()) -1;
    if (index == -1 )return;
    Intervention i = interventions->getIntervention(index);
    interventions->removeIntervention(i);
    Date* end_date = utils->getDate();
    i.concludeIntervention(end_date);
    interventions->addIntervention(i);
    cout << "Intervention concluded with success!" << endl;
    utils->waitForInput();
}



void SystemNetwork::readInterventions() {
    vector<string> v = interventions->showInterventions();
    for (string s: v)
        cout << s << endl;
    utils->waitForInput();
}



void SystemNetwork::readInterventionsDay() {
    cout << "Please input the year of interventions." << endl;
    int year = utils->getNumber(2021);
    if (year == -1) {
        utils->waitForInput();
        return;
    }
    cout << "Please input the month of interventions." << endl;
    int month = utils->getNumber(12);
    if (month == -1) {
        utils->waitForInput();
        return;
    }
    cout << "Please input the day of interventions." << endl;
    int day = utils->getNumber(31);
    if (day == -1) {
        utils->waitForInput();
        return;
    }
    Date* date = new Date(year,month,day);
    BST<Intervention> bst = interventions->getInterventions();
    bool check = false;
    for (auto it = BSTItrIn<Intervention>(bst); !it.isAtEnd(); it.advance())
        if (it.retrieve().getStartDate()->dayEqual(*date)) {
            check = true;
            Intervention i = it.retrieve();
            cout << i.showIntervention() << endl;
        }
    if (!check)
        cout << "There is no intervention on this day." << endl;
    utils->waitForInput();
}



void SystemNetwork::readInterventionsTechnician() {
    string s_name;
    cout << "Input the technician name: (if you want to exit without creating a employee please input EXIT)" << endl;
    do {
        getline(cin, s_name);
    } while(s_name.empty());
    if (s_name == "EXIT") return;
    BST<Intervention> bst = interventions->getInterventions();
    for (auto it = BSTItrIn<Intervention>(bst); !it.isAtEnd(); it.advance()) {
        if (it.retrieve().getTechnician()->getName() == s_name) {
            string s = "Start Date: " + it.retrieve().getStartDate()->getInfo() + " - Specialty: " + it.retrieve().getType() +
                       " - " + it.retrieve().getHighway()->showHighway() +
                       " - Toll Name: " + it.retrieve().getToll()->getName() + " - Technician: " + it.retrieve().getTechnician()->showTechnician();
            if (it.retrieve().getState())
                s += "\n\t\tEnd Date: " + it.retrieve().getEndDate()->getInfo() + " - Duration: " + to_string(it.retrieve().getDuration());
            cout << s << endl;
        }
    }
    utils->waitForInput();
}



void SystemNetwork::readInterventionsType() {
    string s_type;
    int index = utils->ShowMenu({"Review Technician","Electronics Technician","Informatic Technician"});
    if (index == 0) {
        utils->waitForInput();
        return;
    }
    switch (index) {
        case 1:
            s_type = "review";
            break;
        case 2:
            s_type = "eletronic";
            break;
        case 3:
            s_type = "informatic";
            break;
    }
    BST<Intervention> bst = interventions->getInterventions();
    for (auto it = BSTItrIn<Intervention>(bst); !it.isAtEnd(); it.advance()) {
        if (it.retrieve().getType() == s_type) {
            string s = "Start Date: " + it.retrieve().getStartDate()->getInfo() + " - Specialty: " + it.retrieve().getType() +
                       " - " + it.retrieve().getHighway()->showHighway() +
                       " - Toll Name: " + it.retrieve().getToll()->getName() + " - Technician: " + it.retrieve().getTechnician()->showTechnician();
            if (it.retrieve().getState())
                s += "\n\t\tEnd Date: " + it.retrieve().getEndDate()->getInfo() + " - Duration: " + to_string(it.retrieve().getDuration());
            cout << s << endl;
        }
    }
    utils->waitForInput();
}



void SystemNetwork::createTechnician() {
    /*int index;
    Highway* h = chooseHighway();
    if (h == nullptr)
        return;
    Toll* t = chooseToll(h);
    if (t == nullptr)
        return;
    string s_name, s_type;
    while (s_name != "EXIT") {
        cout << "Input the technician name: (if you want to exit without creating a employee please input EXIT)" << endl;
        getline(cin, s_name);
        if (s_name == "EXIT")
            continue;
        else if (!s_name.empty() && highways->checkTechnicianName(s_name)) {
            utils->clrScreen();
            index = utils->ShowMenu({"Review Technician","Electronics Technician","Informatic Technician"});
            if (index == 0) break;
            switch (index) {
                case 1:
                    s_type = "review";
                    break;
                case 2:
                    s_type = "eletronic";
                    break;
                case 3:
                    s_type = "informatic";
                    break;
            }
            t->addTechnician(s_name,s_type);
            cout << "Technician created with success!" << endl;
            utils->waitForInput();
            break;
        }
        else if (s_name!= "EXIT")
            cout << "ERROR: name of technician already exists." << endl;
    }*/
}



void SystemNetwork::readTechnicians() {
    /*int index;
    vector<string> techs,techs1;
    index = utils->ShowMenu({"All technicians", "Technicians on a specific toll"});
    switch (index) {
        case 1:
            for (size_t i = 0; i < highways->getNumHighways(); i++) {
                Highway* highway = highways->getHighwayIndex(i);
                for (size_t j = 0; j < highway->getNumTolls(); j++) {
                    Toll* toll = highway->getTollIndex(j);
                    techs1 = toll->readTechnicians();
                    string s_ht = " - " + highway->showHighway() + " - " + "Toll: " + toll->getName();
                    for (string s : techs1)
                        techs.push_back(s+s_ht);
                }
            }
            cout << "Technicians: " << techs.size() << endl;
            for (string s : techs) {
                cout << s << endl;
            }
            utils->waitForInput();
            break;
        case 2:
            Highway* h = chooseHighway();
            if (h == nullptr)
                return;
            Toll* t = chooseToll(h);
            if (t == nullptr)
                return;
            techs = t->readTechnicians();
            cout << "Technicians: " << techs.size() << endl;
            for (string s : techs) {
                cout << s << " - " << h->showHighway() << " - Toll: "<< t->getName() << endl;
            }
            utils->waitForInput();
            break;
    }*/
}



void SystemNetwork::updateTechnician() {
    /*Highway* h = chooseHighway();
    if (h == nullptr)
        return;
    Toll* t = chooseToll(h);
    if (t == nullptr)
        return;
    vector<string> techs = t->readTechnicians();
    int index = utils->ShowMenu(techs) -1;
    if (index == -1) return;
    string t_name;
    for (char a: techs[index]) {
        if (a == '-')
            break;
        t_name += a;
    }
    t_name = t_name.substr(6,t_name.size()-2);
    t_name.pop_back();
    Technician* technician = t->getTechnicianName(t_name);
    index = utils->ShowMenu({"Update Name", "Update Specialty"});
    string s_name,s_type;
    switch (index) {
        case 1:
            cout << "Input the technician name: (if you want to exit without creating a employee please input EXIT)" << endl;
            while (s_name != "EXIT") {
                getline(cin, s_name);
                if (s_name == "EXIT")
                    continue;
                else if (!s_name.empty() && t->checkTechnicianName(s_name)) {
                    t->deleteTechnician(t_name);
                    technician->setName(s_name);
                    t->addTechnician(technician);
                    cout << "Technician updated with success!" << endl;
                    break;
                }
            }
            utils->waitForInput();
            break;
        case 2:
            cout << "Input the technician specialty: (if you want to exit without creating a employee please input EXIT)" << endl;
            index = utils->ShowMenu({"Review Technician","Electronics Technician","Informatic Technician"});
            if (index == 0) break;
            switch (index) {
                case 1:
                    s_type = "review";
                    break;
                case 2:
                    s_type = "eletronic";
                    break;
                case 3:
                    s_type = "informatic";
                    break;
            }
            if (index > 0) {
                technician->setSpecialty(s_type);
                t->deleteTechnician(t_name);
                t->addTechnician(technician);
                cout << "Technician updated with success!" << endl;
            }
            utils->waitForInput();
            break;
    }*/
}



void SystemNetwork::deleteTechnician() {
    /*Highway* h = chooseHighway();
    if (h == nullptr)
        return;
    Toll* t = chooseToll(h);
    if (t == nullptr)
        return;
    vector<string> techs =  t->readTechnicians();
    int index = utils->ShowMenu(techs) - 1;
    if (index == -1) return;
    string t_name;
    for (char a: techs[index]) {
        if (a == '-')
            break;
        t_name += a;
    }
    t_name = t_name.substr(6,t_name.size()-2);
    t_name.pop_back();
    if (t->deleteTechnician(t_name))
        cout << "Technician deleted with success!" << endl;
    else cout << "ERROR: Technician doesn't exist." << endl;
    utils->waitForInput();*/
}



void SystemNetwork::readOwners() {
    vector<string> v = owners->showOwners();
    for (const string& s: v)
        cout << s << endl;
    utils->waitForInput();
}



void SystemNetwork::readOwnersNumVehicles() {
    vector<Owner> v;
    for (Owner o : owners->getOwners())
        v.push_back(o);
    sort(v.begin(),v.end(),[](Owner o1, Owner o2) {
        if (o1.getNumVehicles() > o2.getNumVehicles())
            return true;
        return false;
    });
    for (Owner o : v)
        cout << "Name: " << o.getName() << " - Number of Vehicles: " << o.getNumVehicles() << endl;
    utils->waitForInput();
}



void SystemNetwork::readOwnerVehicle() {
    string s_plate;
    bool check =false;
    s_plate = utils->getPlate();
    if (s_plate == "EXIT")
        return;
    auto u = owners->getOwners();
    for (Owner o: u) {
        check = false;
        for (Vehicle* v : o.getVehicles())
            if (v->getPlate() == s_plate) {
                check = true;
                break;
            }
        if (check) {
            cout << "Name: " << o.getName() << " - Number of Vehicles: " << o.getNumVehicles() << endl;
            break;
        }
    }
    if (!check)
        cout << "ERROR: Owner not found." << endl;
    utils->waitForInput();
}



void SystemNetwork::addVehicleOwner(Owner &o1) {
    unordered_set<Owner, ownerHash,ownerHash> a = owners->getOwners();
    owners->deleteOwner(o1);
    vector<Vehicle*> v;
    vector<string> s;
    for (int i = 0; i < vehicles->getNumVehicles(); i++) {
        bool check = false;
        for (Owner o: a) {
            for (Vehicle* vv : o.getVehicles()) {
                if (*vv == *vehicles->getVehicleIndex(i)) {
                    check = true;
                    break;
                }
            }
            if (check) break;
        }
        if (!check) {
            v.push_back(vehicles->getVehicleIndex(i));
            s.push_back(vehicles->getVehicleIndex(i)->showVehicle());
        }
    }
    if (v.empty()) {
        cout << "ERROR: There is no vehicle without owner. If you want a vehicle you have to create in Manage Vehicles." << endl;
        utils->waitForInput();
    }
    int index = utils->ShowMenu(s) -1;
    if (index < 0) {
        owners->addOwner(o1);
        utils->waitForInput();
        return;
    }
    o1.addVehicle(v[index]);
    cout << "Vehicle added with success!" << endl;
    owners->addOwner(o1);
    utils->waitForInput();
}



void SystemNetwork::readVehiclesOwner(Owner &o1) {

    for (Vehicle* vehicle : o1.getVehicles())
        cout << vehicle->showVehicle() << endl;
    utils->waitForInput();
}



void SystemNetwork::deleteVehicleOwner(Owner &o1) {
    owners->deleteOwner(o1);
    int index = utils->ShowMenu(o1.showVehicles()) -1;
    if (index < 0)
        owners->addOwner(o1);
    if (o1.deleteVehicle(index)) {
        owners->addOwner(o1);
        cout << "Vehicle deleted with success!" << endl;
    }
    utils->waitForInput();
}



void SystemNetwork::ownerMoreVehicles() {
    auto u = owners->getOwners();
    if (u.empty()) {
        cout << "ERROR: There are no owners" << endl;
        return;
    }
    Owner owner = *u.begin();
    for (const Owner& o: u) {
        if (o.getNumVehicles() > owner.getNumVehicles())
            owner = o;
    }
    cout << "Name: " << owner.getName() << "\nVehicles: ";
    vector<Vehicle*> v = owner.getVehicles();
    for (Vehicle* vv: v)
        cout << vv->showVehicle() << endl;
    utils->waitForInput();
}
