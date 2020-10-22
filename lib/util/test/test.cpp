#include <lest/lest.hpp>
#include "../src/process.hpp"
#include "../src/tree_dir.hpp"
#include "../src/logging.hpp"
#include <iostream>

const lest::test specification[] =
{
    CASE("process ls -la")
    {
        ott::util::Process p("ls");
        p << "-la";
        p.invokes();
        std::cout << "Test" << std::endl;
        const std::string r = p.result();
        EXPECT(r.size() != 0 );
    },
    CASE("list the /tmp folder")
    {
        ott::util::DirWaker tmp("/tmp");
        auto it = tmp.iterator();
        std::cout << "test iterator() \n";
        for( it->first(); !it->isDone(); it->next() )
        {
            std::cout << "why" << std::endl;

            std::cout << it->current() << std::endl;
        }
    },
    CASE("Test logger")
    {

    },
};

int main( int argc, char * argv[] )
{
    ott::util::initLogging("test.log");
    return lest::run( specification, argc, argv );
}
