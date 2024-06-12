#include <iostream>
#include "board.hpp"

using namespace std;
using namespace ariel;

int main() {
    Board b;
    b.printBoard();
    Player p1("dudi");

    p1.placeSettlement(b,"Pasture",11,4);
    p1.rollDice(b);


    p1.printResources();


}
