#include "GeneSplicer.hpp"
using namespace pandemic;
using namespace std;
#include <string>
#include <stdexcept>
const int num_of_cards=5;
Player& GeneSplicer::discover_cure(Color c)
{
    if(!board.has_research_station(city)){
        throw invalid_argument{"illegal action:There is no research station in this city!"};
    }
    if (board.is_cure_discoverd(c))
    {
        return *this;
    }
    if(cards.size() < num_of_cards){
        throw invalid_argument{"illegal action: you dont have enough cards!" };
    }
    int count2=num_of_cards;
        auto it = cards.begin();
        while (it != cards.end() && count2 > 0)
        {
            it = cards.erase(it);
            count2--;
            it++;
        }
        board.add_discovered_cure(c);
        return *this;  
}

string GeneSplicer::role()
{ 
    return "GeneSplicer";
}