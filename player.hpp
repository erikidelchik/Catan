#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>


using namespace std;

namespace ariel{

    class Board;

    class Player{
        string name;

        int points;
        int freeSettlements = 2;

        int wood;
        int brick;
        int sheep;
        int wheat;
        int ore;

        int* resources[5] = {&wood, &brick,&sheep,&wheat,&ore};
        string resourcesNames[5] = {"wood","brick","sheep","wheat","ore"};

    public:

        string getName() const{
            return name;
        }


        explicit Player(string name): name(name),points(0),wood(0),brick(0),sheep(0),wheat(0),ore(0){}

        void printResources() const{
            cout<<"wood: "<<wood<<",";
            cout<<"brick: "<<brick<<",";
            cout<<"sheep: "<<sheep<<",";
            cout<<"wheat: "<<wheat<<",";
            cout<<"ore: "<<ore<<endl;
        }

        void printPoints() const{
            cout<<name<<" has "<<points<<" points\n";
        }

        void rollDice(Board &board);

        void placeSettlement(Board &board,string place, int num,int side);
        void placeRoad(Board &board,string& place,int num,int side);



    };

}

#endif