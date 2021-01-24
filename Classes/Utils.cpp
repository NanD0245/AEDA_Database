#include "Utils.h"

#include <iostream>

using namespace std;

void Utils::clrScreen() {
    cout << "\033[2J\033[H";
}

int Utils::getNumber(int max) {
    string s_index;
    int index;
    while (true) {
        bool check = false;
        do {
            getline(cin, s_index);
        } while(s_index.empty());
        if (s_index == "EXIT") return -1;
        for (size_t i = 0; i < s_index.size(); i++) {
            if (s_index[i] < 48 || s_index[i] > 57) {
                cout << "Error: Invalid input." << endl;
                check = true;
                break;
            }
        }
        if (check)
            continue;
        index = stoi(s_index);
        if (index > max) {
            cout << "Error: Invalid input, please choose one of above." << endl;
            continue;
        }
        break;
    }
    return index;
}

int Utils::ShowMenu(vector<string> menu) {
    //clrScreen();
    cout << "TOLL MANAGEMENT SYSTEM" << endl << endl;
    cout << "Please choose one of the options below: " << endl << endl;
    for (size_t i = 0; i < menu.size(); i++) {
        cout << (i+1) << " - " << menu[i] << endl;
    }
    cout << "0 - Exit" << endl << endl;
    int index = getNumber(menu.size());
    if (index != 0)
        clrScreen();
    return index;
}

int Utils::ShowMenu(vector<string> menu, int lane_index) {
    //clrScreen();
    cout << "TOLL MANAGEMENT SYSTEM" << endl << endl;
    cout << "Please choose one of the options below: " << endl << endl;
    for (size_t i = 0; i < menu.size(); i++) {
        cout << (i+1) << " - " << menu[i] << endl;
    }
    cout << "0 - Exit" << endl << endl;
    cout << "Our advice: Lane " << lane_index << ". (Lane with less traffic)" << endl;
    int index = getNumber(menu.size());
    clrScreen();
    return index;
}



float Utils::getFloat() {
    string s_index;
    float index;
    while (s_index != "EXIT") {
        bool check = false;
        getline(cin, s_index);
        if (s_index == "EXIT")
            return -1;
        for (size_t i = 0; i < s_index.size(); i++) {
            if ((s_index[i] < 48 || s_index[i] > 57) && s_index[i] != 46) {
                cout << "Error: Invalid input. Example: 2 or 2.5" << endl;
                check = true;
                break;
            }
        }
        if (check)
            continue;
        index = stof(s_index);
        if (index < 0) {
            cout << "Error: Invalid input. Input a positive number" << endl;
            continue;
        }
        break;
    }
    return index;
}

string Utils::getPlate() {
    string plate;
    while (true) {
        bool check = false;
        cout << "Input the vehicle plate: (if you want to exit without creating a vehicle please input EXIT)" << endl;
        getline(cin, plate);
        for (auto ch: plate) {
            if (ch == ' ') {
                check = true;
                break;
            }
        }
        if (plate.empty())
            check = true;
        if (!check)
            break;
        else cout << "ERROR: Invalid Input." << endl;
    }
    return plate;
}

void Utils::waitForInput() {
    string a;
    cout << '\n' << "Press enter to continue...";
    getline(cin, a);
    cout << "\x1b[A";
}


Date * Utils::getDate() {
    time_t timer = time(0);
    tm *now = localtime(&timer);
    string s_date =
            to_string(now->tm_mday) + "/" + to_string(now->tm_mon+1) + "/" + to_string(now->tm_year + 1900) + " " +
            to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
    Date *date = new Date(s_date);
    return date;
}


