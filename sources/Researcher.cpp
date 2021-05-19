#include "Researcher.hpp"
using namespace std;
#include<string>
#include <stdexcept>
const int num_of_cards = 5;
namespace pandemic{
    Player& Researcher::discover_cure(Color c)
    {
        int count=0;
        for (const auto &t : cards)
        {
            if (Board::get_city_color(t) == c)
            {
                count++;
            }
        }
        if (count < num_of_cards)
        {
            throw invalid_argument{"There are not enough cards"};
        }
        count = 1;
        for(auto it = cards.begin(); it != cards.end(); count++){
            if(count == num_of_cards) { break; }
            if(Board::get_city_color(*it) == c) {
                it = cards.erase(it);
            }
            else {
                ++it;
            }
        }
        board.add_discovered_cure(c);
        return *this;
    }
    string Researcher::role()
    { 
        return "Researcher"; 
    }
}
