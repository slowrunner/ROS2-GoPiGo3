#include <iostream>
#include <iomanip>
//#include <nlohmann/json.hpp>
#include <json.hpp>

using json = nlohmann::json;

int main()
{
    // create a JSON object
    /*
        /home/pi/Dexter/gpg3_config.json 
        {"wheel-diameter": 66.1, "wheel-base-width": 105.59, "ticks": 16, "motor_gear_ratio": 120}

    */


    json j =
    {
        {"wheel-diameter", 66.1},
        {"wheel-base-width", 105.59},
        {"ticks", 16},
        {"motor_gear_ratio", 120}
    };

    // add new values
    // j["new"]["key"]["value"] = {"another", "list"};

    // pretty print with indent of 4 spaces
    std::cout << std::setw(4) << j << '\n';
    // count elements
    auto s = j.size();
    // j["size"] = s;
    std::cout << "j.size(): " << s << '\n';


    // extract value from json object
    float wheel_diameter, wheel_base_width;
    int ticks, motor_gear_ratio;

    // use explicit conversion
    j["wheel-diameter"].get_to(wheel_diameter);
    j["wheel-base-width"].get_to(wheel_base_width);
    j["ticks"].get_to(ticks);
    j["motor_gear_ratio"].get_to(motor_gear_ratio);


    std::cout << "wheel_diameter: " << wheel_diameter << std::endl;
    std::cout << "wheel_base_width: " << wheel_base_width << std::endl;
    std::cout << "ticks: " << ticks << std::endl;
    std::cout << "motor_gear_ratio: " << motor_gear_ratio << std::endl;


    // create a JSON object from values
    json json_gpg3_config = { };

    json_gpg3_config["wheel-diameter"] = wheel_diameter;
    json_gpg3_config["wheel-base-width"] = wheel_base_width;
    json_gpg3_config["ticks"] = ticks;
    json_gpg3_config["motor_gear_ratio"] = motor_gear_ratio;

    // print json_gpg_config with indent of 4 spaces
    std::cout << "json_gpg3_config:" << std::endl;
    std::cout << std::setw(4) << json_gpg3_config << std::endl;


    auto not_found = json_gpg3_config.find("last-docking");
    std::cout << std::boolalpha << "last-docking in json_gpg3_config: " << (not_found != json_gpg3_config.end()) << '\n';
    auto is_found = json_gpg3_config.find("ticks");
    std::cout << std::boolalpha << "ticks in json_gpg3_config: " << (is_found != json_gpg3_config.end()) << '\n';
    std::cout << "ticks: " << *is_found << '\n';
    // std::cout << "typeid(is_found).name(): " << typeid(is_found).name() << '\n';
    
}
