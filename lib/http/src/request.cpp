#include "request.hpp"
#include <iostream>
#include <boost/beast/version.hpp>
#include <boost/beast/http.hpp>
#include "mine_types.hpp"

namespace ott
{

namespace http
{
// Append an HTTP rel-path to a local filesystem path.
// The returned path is normalized for the platform.
std::string
pathCat(
    boost::beast::string_view base,
    boost::beast::string_view path)
{
    if(base.empty())
        return std::string(path);
    std::string result(base);
#ifdef BOOST_MSVC
    char constexpr path_separator = '\\';
    if(result.back() == path_separator)
        result.resize(result.size() - 1);
    result.append(path.data(), path.size());
    for(auto& c : result)
        if(c == '/')
            c = path_separator;
#else
    char constexpr path_separator = '/';
    if(result.back() == path_separator)
        result.resize(result.size() - 1);
    result.append(path.data(), path.size());
#endif
    return result;
}


void fail(boost::beast::error_code ec, char const* what)
{
    std::cerr << what << ": " << ec.message() << "\n";
}

} // http namespace
} // ott namespace
