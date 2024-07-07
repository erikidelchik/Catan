//erikidelchik@gmail.com

#include <iostream>
using namespace std;

namespace ariel{

    class Card{
        string name;
        int amount = 0;
    public:



        explicit Card(string name): name(name) {}
        Card(string name,int amount): name(name),amount(amount) {}

        string getName() const{
            return name;
        };

        int getAmount() const{
            return amount;
        }

        void addAmount(){
            amount++;
        }

        void subAmount(){
            amount--;
        }


    };


}
