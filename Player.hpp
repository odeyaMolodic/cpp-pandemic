#pragma once
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"

namespace pandemic{

    class Player{ 
        public:
            Player(){ };
            Player(Board &board, City city){ };

            Player& drive(City city);
            Player& fly_direct(City city);
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            Player& build();
            bool discover_cure(Color color);
            Player& treat(City city);
            
            std::string role() const;
            Player& take_card(City city);
    };
}