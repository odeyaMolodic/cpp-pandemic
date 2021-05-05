#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "OperationsExpert.hpp"
#include "doctest.h"
using namespace pandemic;

Board board;
OperationsExpert player {board, City::Atlanta};

TEST_CASE("board") {

    CHECK(board.is_clean() == true);
    
    board[City::Kinshasa] = 3;     
	CHECK(board[Kinshasa] == 3);
    
    board[City::Kinshasa] = 2;    
	CHECK(board[Kinshasa] == 2);
    
    board[City::MexicoCity] = 3;   
	CHECK(board[MexicoCity] == 3);
    
    board[City::HoChiMinhCity] = 1;
	CHECK(board[HoChiMinhCity] == 1);
    
    board[City::Chicago] = 1;
    CHECK(board[Chicago] == 1); 

    CHECK(board.is_clean() == false);

}

TEST_CASE("player") {
    CHECK_NOTHROW();
    CHECK_THROWS();

    player.take_card(City::Johannesburg)
	 .take_card(City::Khartoum)
	 .take_card(City::SaoPaulo)
	 .take_card(City::BuenosAires)
	 .take_card(City::HoChiMinhCity);
    
    player.build();

    /* drive action */
    CHECK_NOTHROW(player.drive(City::Washington));
	CHECK_THROWS(player.drive(City::Madrid));

    /* fly_direct action */
    CHECK_NOTHROW(player.fly_direct(City::Johannesburg));
	CHECK_THROWS(player.fly_direct(City::Taipei));

    /* treat action */
    player.drive(City::Kinshasa);

	player.treat(City::Kinshasa);
	CHECK(board[Kinshasa] == 1);
	player.treat(City::Kinshasa);
	CHECK(board[Kinshasa] == 0);
	CHECK_THROWS(player.treat(City::Kinshasa));
    CHECK_THROWS(player.treat(City::Washington));

    /* fly_charter action */
	CHECK_NOTHROW(player.drive(City::Khartoum)
	 .fly_charter(City::Sydney));  
    CHECK_THROWS(player.fly_charter(City::Seoul));

    /* fly_shuttle action */
    player.drive(City::LosAngeles);
	player.build();

	CHECK_NOTHROW(player.fly_shuttle(City::Atlanta));
	CHECK_NOTHROW(player.fly_shuttle(City::LosAngeles));
	CHECK_THROWS(player.fly_shuttle(City::Chicago));

    /* discover_cure action */
    CHECK_THROWS(player.discover_cure(Color::Yellow));
	
	player.take_card(City::Miami)
	 .take_card(City::Bogota)
	 .take_card(City::Lima);

	CHECK_NOTHROW(player.discover_cure(Color::Yellow));
	CHECK_THROWS(player.fly_direct(City::Miami));

	/* treat action after discovering a cure */
	player.drive(City::MexicoCity); 
	player.treat(City::MexicoCity);
	
    CHECK(board[MexicoCity] == 0);


	/* clean the board */
	player.drive(City::Chicago)
	 .treat(City::Chicago)        
     .fly_direct(City::HoChiMinhCity)
	 .treat(City::HoChiMinhCity);     

	CHECK(board.is_clean() == true);

}

