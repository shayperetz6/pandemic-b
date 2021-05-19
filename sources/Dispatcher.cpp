#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;
#include <string>
#include<stdexcept>
Player& Dispatcher:: fly_direct(City c){
    if (this->city == c)
    {
        throw invalid_argument{"Illegal action::It is not possible to fly to the city where you are already "};
    }
    if (board.has_research_station(city))
    {
        city = c;
    }
    else
    {
        return Player::fly_direct(c);
    }
    return *this;
}
std::string Dispatcher::role() {
     return "Dispatcher"; 
}

