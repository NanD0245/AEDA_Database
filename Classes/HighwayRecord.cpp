#include "HighwayRecord.h"

HighwayRecord::HighwayRecord() {highways.clear();}

int HighwayRecord::getNumHighways() const {return highways.size();}

Highway * HighwayRecord::getHighway(string name) {
    for (size_t i = 0; i < highways.size(); i++) {
        if (name == highways[i]->getInfo())
            return highways[i];
    }
    return nullptr;
}

Highway * HighwayRecord::getHighwayIndex(int id) {
    string query = "select * from highways where id = " + to_string(id);
    sqlite3_prepare(db,query.c_str(),-1,&stmt, nullptr);
    sqlite3_step(stmt);
    auto* h = new Highway(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,1))));
    return h;
}

bool HighwayRecord::checkHighwayName(string name) {
    string query = "select * from highways";
    sqlite3_prepare(db,query.c_str(),-1,&stmt, nullptr);
    while (sqlite3_step(stmt) != SQLITE_DONE)
        if (name == string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,1))))
            return true;
    return false;
}

bool HighwayRecord::addHighway(string name) {
    if (checkHighwayName(name)) return false;
    string query = "insert into highways (name) values ('" + name + "')";
    int rc = sqlite3_exec(db,query.c_str(),NULL,NULL,&err);
    if (rc != SQLITE_OK) {
        Utils::checkDbErr(rc);
        return false;
    }
    return true;
}

void HighwayRecord::addHighway(Highway * h){
    highways.push_back(h);
}

bool HighwayRecord::removeHighway(int id) {
    string query = "delete from highways where id = " + to_string(id);
    int rc = sqlite3_exec(db,query.c_str(),NULL,NULL,&err);
    if (rc == SQLITE_OK) return true;
    Utils::checkDbErr(rc);
    return false;
}

bool HighwayRecord::checkTechnicianName(string name) {
    for (Highway* h :highways) {
        if (!h->checkTechnicianName(name))
            return false;
    }
    return true;
}