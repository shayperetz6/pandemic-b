#include "Virologist.hpp"
using namespace pandemic; 
using namespace std;
#include <string>
#include<stdexcept>
Player& Virologist::treat(City c)
{
    if (city != c)
    {
        if (cards.count(c) == 0)
        {
            throw invalid_argument{"Illegal action:you dont have this card"};
        }
        cards.erase(c);
    }
    else if (board[c] == 0) {
        throw invalid_argument{"Illegal action: no more cubes remain in city "};
    }
    else if (board.is_cure_discoverd(Board::get_city_color(c)))
    {
        board[c] = 0;
        return *this;
    }
    board[c]--;
    return *this;
}
string Virologist::role()
{
     return "Virologist"; 
}