#include "OperationsExpert.hpp"
using namespace pandemic;
using namespace std;
#include <string>
Player& OperationsExpert::build()
{
    board.build_research_station(city);
    return *this;
}
string OperationsExpert::role()
{
    return "OperationsExpert";
}