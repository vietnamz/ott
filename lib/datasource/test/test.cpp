#include <nlohmann/json.hpp>
#include <iostream>
#include "datasource/src/user.hpp"

using namespace std;
using json = nlohmann::json;
int main()
{
    // create a person
    ott::datasource::User p {"Ned Flanders", "744 Evergreen Terrace", 60};

    // conversion: person -> json
    json j = p;

    std::cout << j << std::endl;
    // {"address":"744 Evergreen Terrace","age":60,"name":"Ned Flanders"}

    // conversion: json -> person
    auto p2 = j.get<ott::datasource::User>();

    // that's it
    //assert(p == p2);
}
