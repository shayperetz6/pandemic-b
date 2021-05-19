#pragma once
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
namespace pandemic {
    class Board {
    public:
        static std::map<City, std::set<City>> connections; //connections between cities
        std::map<City, int> infection_level;             // number disease levels in a specific city
        std::set<City> research_stations;           // research stations by city
        std::set<Color> cure_discoverd;                       //The color of a city where there is medicine
    
        int& operator[](City city);
        friend std::ostream& operator<<(std::ostream &os, const Board &board);
        bool is_clean();
        void remove_cures(){cure_discoverd.clear();}; 
        void remove_stations(){research_stations.clear();};
        //help function
        bool has_research_station(City city){ return (research_stations.count(city) != 0);};
        bool is_cure_discoverd(Color color){return (cure_discoverd.count(color) != 0);};
        void build_research_station(City city){ research_stations.insert(city);};
        static bool is_connected(City& city1, City& city2){return connections.at(city1).count(city2) != 0; };
        void add_discovered_cure(Color color){cure_discoverd.insert(color);};
        static Color get_city_color(City city){return color_of_city.at(city);};
    };
}