#include "FieldDoctor.hpp"
using namespace pandemic;
using namespace std;
#include<string>
#include <stdexcept>
Player& FieldDoctor::treat(City c) 
{
    if (!Board::is_connected(city, c) && city != c)
    {
        throw std::invalid_argument{"It is not possible to reach this city,they are not connected"};
    }
    if (board[c] == 0)
    {
        throw std::invalid_argument{"no more cubes remain in city "};
    }

    if (board.is_cure_discoverd(Board::get_city_color(c)))
    {
        board[c] = 0;
    }
    else
    {
        board[c]--;
    }
    return *this;
}
 string FieldDoctor::role()
 {
    return "FieldDoctor"; 
 }