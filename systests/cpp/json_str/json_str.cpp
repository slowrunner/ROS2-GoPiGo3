/*
    FILE: json_str.cpp

    PURPOSE: demonstrate reading GoPiGo3 config file to populate variables
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;


int main()
{


    // extract value from json object
    float wheel_diameter, wheel_base_width;
    int ticks, motor_gear_ratio;

    string keys[4] = {"wheel-diameter", "wheel-base-width", "ticks", "motor_gear_ratio"};

    // Choose test case
    //string fpath = "/home/pi/Dexter/gpg3_config.json";  // gpg3_config.json exists test
    string fpath = "dummy.json";     // no gpg3_config.json file test


    // Choose test case
    string serial = "CE43EA875152415447202020FF192608";  // serial in file
    // string serial = "Dummy";  // serial not in file
    string serials;

    // create a JSON string object from the file
    /*
        /home/pi/Dexter/gpg3_config.json
        {"wheel-diameter": 66.1, "wheel-base-width": 105.59, "ticks": 16, "motor_gear_ratio": 120}

    */



    // Read file into string
    string gpg3_config;
    ifstream input(fpath);
    stringstream buffer;
    input >> buffer.rdbuf();
    gpg3_config = buffer.str();

    cout << "gpg3_config: " << '"'+gpg3_config+'"' << endl;


    // Read serials file into string
    string fname = "/home/pi/Dexter/.list_of_serial_numbers.pkl";

    ifstream file(fname);
    if(file.is_open()) {

        stringstream buffer;
        buffer << file.rdbuf();
        serials = buffer.str();
        // cout << test << endl;
    }


    // replace a occurances of close-brace with comma to make value extraction consistent for last key:value
    replace(gpg3_config.begin(), gpg3_config.end(), '}', ',');

    // print string
    // cout << gpg3_config << '\n';
    // count elements
    // auto n_keys = count(gpg3_config.cbegin(), gpg3_config.cend(), ':');
    // cout << "n_keys in gpg3_config: " << n_keys << endl;

    string value_string;
    // test if key found in string
    for (auto &&key: keys){
        cout << "\nprocessing key: " << key << endl;
        auto pos_key = gpg3_config.find(key);
        // cout << boolalpha << "key: " << '"'+key+'"' << " found: " << (pos_key != string::npos) << endl;
        if (pos_key != string::npos){
            auto key_string = gpg3_config.substr(pos_key);
            // cout << "key_string: " << '"'+key_string+'"' << endl;
            auto pos_colon = key_string.find(':');
            // cout << boolalpha << "colon found:" << (pos_colon != string::npos) << endl;
            // cout << "pos_colon: " << pos_colon << endl;
            value_string = key_string.substr(pos_colon+1);
            auto pos_comma = value_string.find(',');
            // cout << boolalpha << "comma found:" << (pos_comma != string::npos) << endl;
            // cout << "pos_comma: " << pos_comma << endl;

            value_string = value_string.substr(0, pos_comma);
            // cout << key << ": value_string: " << '"'+value_string+'"' << endl;
        }
        if (key == keys[0]) { // "wheel-diameter":
            if (pos_key == string::npos)
              wheel_diameter = 66.5;
            else
              wheel_diameter = stof(value_string);
            cout << fixed << setprecision(3) << "wheel_diameter: " << wheel_diameter << endl;
        }
        else if (key == keys[1]) {  // "wheel-base-width"
            if (pos_key == string::npos)
              wheel_base_width = 115.0;
            else
              wheel_base_width = stof(value_string);
            cout << fixed << setprecision(3) << "wheel_base_width: " << wheel_base_width << endl;
        }
        else if (key == keys[2]) { // "ticks"
            if (pos_key == string::npos) {
                bool key_found = (serials.find(serial) != string::npos);
                cout << boolalpha << serial << " found: " << key_found << endl;

                if (key_found){
                    ticks = 16;
                }
                else {
                    ticks = 6;
                }
            }

            else
              ticks = stoi(value_string);
            cout << "ticks: " << ticks << endl;
        }
        else if (key == keys[3]) { //"motor_gear_ratio"
            if (pos_key == string::npos)
              motor_gear_ratio = 120;
            else
              motor_gear_ratio = stoi(value_string);
            cout << "motor_gear_ratio: " << motor_gear_ratio << endl;
        }

   }  // end for



}  // end main
