#include "Scientist.hpp"
using namespace pandemic;
using namespace std;
#include <string>
#include <stdexcept>
Player& Scientist::discover_cure(Color c)
{
     if(!board.has_research_station(city)){
        throw invalid_argument{"illegal action: the city doesnt have research station!"};
     }
    if (!board.is_cure_discoverd(c))
    {
        int count=0;
        for(const auto &cd : cards)
        {
            if(Board::get_city_color(cd)==c)
            {
                count++;
            }
        }
        if(count<this->number)
        {
            throw invalid_argument{"There are not enough cards"};
        }
        count = 1;
        for(auto cd = cards.begin(); cd != cards.end(); count++){
            if(count == number) { break; }
            if(Board::get_city_color(*cd) == c) {
                cd = cards.erase(cd);
            }
            else {
                ++cd;
            }
        }
      board.add_discovered_cure(c);     
    }
    return *this;
}
string Scientist::role()
{
     return "Scientist"; 
}