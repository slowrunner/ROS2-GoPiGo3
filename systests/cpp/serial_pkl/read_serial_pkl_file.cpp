/*
    FILE: read_serial_pkl_file.cpp
    PURPOSE:  see if possible to read Python pkl file with C++
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>


int main() {

    using namespace std;

    string key = "CE43EA875152415447202020FF192608";
    // string fname = "serials.pkl";
    string fname = "/home/pi/Dexter/.list_of_serial_numbers.pkl";

    ifstream file(fname);
    if(file.is_open()) {

        stringstream buffer;
        buffer << file.rdbuf();
        string test = buffer.str();
        // cout << test << endl;
        bool key_found = (test.find(key) != string::npos);
        // cout << boolalpha << key << " found: " << key_found << endl;

        cout << key;
        if (key_found){
            cout << " found" << endl;
        }
        else {
            cout << "not found" << endl;
        }
    }
}
