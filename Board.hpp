#pragma once
#include <iostream>
#include "City.hpp"

namespace pandemic{
    class Board{
        private:
            int map;

        public:
            Board(){ };

            int& operator[](City city);
            friend std::ostream& operator<< (std::ostream& os,const Board& board);
            bool is_clean() const;
            void remove_cures();
    };
}