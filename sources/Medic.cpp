#include "Medic.hpp"
using namespace pandemic;
using namespace std;
#include <string>
#include <stdexcept>
Player& Medic::treat(City c)
{
     if (city != c) {
        throw invalid_argument{"illegal action: you are not in the right city!"};
    }
    if (board[c] == 0) {
        throw invalid_argument{"illegal action: no more cubes remain in city "};
    }

    board[c] = 0;
    return *this;
}

void Medic::treat_cure_discoverd()
{

    if(board.is_cure_discoverd(Board::get_city_color(city)))
    {
        board[city]=0;
    }
}
string Medic::role()
{ 
    return "Medic";
}