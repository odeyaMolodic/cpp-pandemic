#include "Player.hpp"

namespace pandemic{

    Player& Player::drive(City city){return *this;}
    Player& Player::fly_direct(City city){return *this;}
    Player& Player::fly_charter(City city){return *this;}
    Player& Player::fly_shuttle(City city){return *this;}
    Player& Player::build(){return *this;}
    bool Player::discover_cure(Color color){return false;}
    Player& Player::treat(City city){return *this;}
    
    std::string Player::role() const{return "";}
    Player& Player::take_card(City city){return *this;}
}