#include <iostream>
#include "player.hpp"
namespace ariel {

    class Catan {
    private:
        Player *p1;
        Player *p2;
        Player *p3;

    public:

        Catan(Player &p1,Player &p2, Player &p3):p1(&p1),p2(&p2),p3(&p3){}


    };


}
