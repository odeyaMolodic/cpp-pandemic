#include "Board.hpp"

namespace pandemic{
    int& Board::operator[](City city){return map;}
    std::ostream& operator<< (std::ostream& os,const Board& board){return os;}
    bool Board::is_clean() const{return false;}
    void Board::remove_cures(){}

}