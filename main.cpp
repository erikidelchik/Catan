#include <iostream>
#include "catan.hpp"

using namespace std;
using namespace ariel;

int main() {


    Player p1("moshe");
    Player p2("haim");
    Player p3("amit");
    Catan catan(p1,p2,p3);
    Board b = catan.getBoard();

    p1.placeSettlement(b,"Pasture",11,2);
    p2.upgradeSettlement(b,"Pasture",11,2);
    p2.placeSettlement(b,"Forest",11,4);
    p1.rollDice(b,catan.getPlayers());
    p1.placeRoad(b,"Fields",4,3);

    for(int i=0;i<30;i++){
        p1.buyCard(catan);
    }
    p1.printCards();

    p1.printResources();
    catan.printStats();




}
