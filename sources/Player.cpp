#include "Player.hpp"
using namespace std;
using namespace pandemic;
#include <string>
#include <stdexcept>
const int num_of_cards = 5;
Player& Player::drive(City c)
{
     if(city==c){
        throw invalid_argument{"Illegal action:Is not possible to drive to the city where you are already in "};
    }
    if (!Board::is_connected(city, c))
    {
        throw invalid_argument{"Illegal action:The Cities are not connected"};
    }
    city = c;
    treat_cure_discoverd();
    return *this;
}
Player& Player::fly_direct(City c)
{
    if(city==c){
        throw invalid_argument{"Illegal action:Is not possible to fly to the city where you already in "};
    }
    if (cards.count(c) == 0)
    {
        throw invalid_argument{"Illegal action:You dont have this card"};
    }
    cards.erase(c);
    this->city = c;
    treat_cure_discoverd();
    return *this;
}
Player& Player::fly_charter(City c)
{
    if(city==c){
        throw invalid_argument{"Illegal action:Is not possible to fly to the city where you are already in "};
    }
    if (cards.count(city) == 0)
    {
        throw invalid_argument{"Illegal action:you dont have this card "};
    }
    cards.erase(this->city);
    this->city = c;
    treat_cure_discoverd();
    return *this;
}
Player& Player::fly_shuttle(City c)
{
     if(city==c){
        throw invalid_argument{"Illegal action:Is not possible to fly to the city where you are already in "};
    }
    if (!board.has_research_station(this->city) || !board.has_research_station(c))
    {
        throw invalid_argument{"Illegal action:both cities must heve research station "};
    }
    this->city = c;
    treat_cure_discoverd();
    return *this;
}
Player& Player::build()
{
    if (cards.count(city) == 0)
    {
        throw invalid_argument{"Illegal action:you cant build research station, you dont have this city card"};
    }
    if (!board.has_research_station(city))
    {
        board.build_research_station(city);
        cards.erase(city);
    }
    return *this;
}

Player& Player::discover_cure(Color c)
{
    if (board.is_cure_discoverd(c))
    {
        return *this;
    }
    if(!board.has_research_station(city)){
        throw invalid_argument{"illegal action:the city dont have research station"};
    }
    int count = 0;
    for(const auto& it : cards){
        if(Board::get_city_color(it) == c) {
            count++;
        }
    }
    if(count < num_of_cards){
        throw invalid_argument{"illegal action: you dont have enough cards" };
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

Player& Player::treat(City c)
{
    if (city != c) {
        throw invalid_argument{"illegal action: you are not in the city "};
    }
    if (board[c] == 0) {
        throw invalid_argument{"illegal action: no more cubes remain in city"};
    }
    if (board.is_cure_discoverd(Board::get_city_color(c))) {
        board[c] = 0;
    }
    else {
        board[c]--;
    }
    return *this;
}
Player &Player::take_card(City c)
{
    cards.insert(c);
    return *this;
}
 string Player::role() 
{
      return "Player"; 
}
