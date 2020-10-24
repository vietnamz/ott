#include "user.hpp"

#include <nlohmann/json.hpp>

namespace ott
{

namespace datasource
{

void to_json(nlohmann::json& j, const User& u)
{
    j = nlohmann::json{{"name", u.name}, {"address", u.address}, {"age", u.age}};
}
void from_json(const nlohmann::json& j, User& u)
{
    j.at("name").get_to(u.name);
    j.at("address").get_to(u.address);
    j.at("age").get_to(u.age);
}

} // namespace datasource
} // namespace ott
