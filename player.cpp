#include <iostream>
#include "buildable.hpp"
#include "board.hpp"
#include <random>

namespace ariel{

    void Player::placeSettlement(Board &board, string place, int num,int side) {

        if((brick>=1 && wood>=1 && sheep>=1 && wheat>=1) || freeSettlements>0){
            if(freeSettlements>0)
                freeSettlements--;
            else {
                brick -= 1;
                wood -= 1;
                sheep -= 1;
                wheat -= 1;
            }
            Settlement settlement(*this);

            for(int i=0;i<5;i++){
                int k=0;
                for(Place& j: board.getBoard()[i]){
                    if(j.getName()==place && j.getNum()==num){
                        if(j.getSettlements()[side]->getOwner()=="none"){

                            *j.getSettlements()[side] = settlement;
                            return;

                        }
                        else{
                            cout<<j.getSettlements()[side]->getOwner()<<" already have a settlement here";
                            return;
                        }
                    }
                    k++;
                }
            }
            cout<<"Place does not exist\n";

        }
        else{
            cout<<this->getName()<<" does not have enough resources to build a settlement\n";
        }

    }

    void Player::placeRoad(Board &board,string place,int num,int side){
        if(1){
            brick-=1;
            wood-=1;
            Road road(*this);
            for(int i=0;i<5;i++){
                for(Place& j:board.getBoard()[i]){
                    if(j.getName()==place && j.getNum()==num){
                        //check if can no one have a road there
                        if(j.getRoads()[side]->getOwner()=="none"){
                            *j.getRoads()[side] = road;
                            return;
                        }
                        else{
                            cout<<j.getRoads()[side]->getOwner()<<" already have a road here\n";
                            return;
                        }
                    }
                }
            }
            cout<<"Place does not exist\n";

        }
        else{
            cout<<this->getName()<<" does not have enough resources to build a road\n";
        }
    }


    void Player::rollDice(Board &board) {
        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> dist(2, 12);
        int result =  dist(gen);


        cout<<this->getName()<<" rolled "<<result<<endl;

        for(int i=0;i<5;i++) {
            for (Place place: board.getBoard()[i]){
                if(result==place.getNum()){
                    for(Buildable* b: place.getSettlements()){
                        if(b->getOwner()==this->getName() && b->getName()=="Settlement") {
                            for (int r = 0; r < 5; r++) {
                                if (place.getResourceName() == resourcesNames[r]) {
                                    (*resources[r])++;
                                    cout << this->getName() << " got +1 "<<place.getResourceName()<<endl;
                                }
                            }
                        }

                        else if(b->getOwner()==this->getName() && b->getName()=="City") {
                            for (int r = 0; r < 5; r++) {
                                if (place.getResourceName() == resourcesNames[r]) {
                                    (*resources[r])+=2;
                                    cout << this->getName() << " got +2 "<<place.getResourceName()<<endl;
                                }
                            }
                        }


                    }
                }
            }
        }
    }


}
