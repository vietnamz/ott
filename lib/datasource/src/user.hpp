#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace ott
{
namespace datasource
{

struct User
{
    std::string name;
    std::string address;
    int age;
};

void to_json(nlohmann::json& j, const User& u);
void from_json(const nlohmann::json& j, User& u);

} // namespace datasource
} // namespace ott
