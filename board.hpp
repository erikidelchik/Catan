#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include "places.hpp"


using namespace std;
using ariel::Place;

namespace ariel{


    class Board{


        vector<vector<Place>> myBoard = {
                         {Mountains(10),Pasture(2),Forest(9)},
                     {Fields(12),Hills(6),Pasture(4),Hills(10)},
                {Fields(9),Forest(11),Desert(),Forest(3),Mountains(8)},
                    {Forest(8),Mountains(3),Fields(4),Pasture(5)},
                          {Hills(5),Fields(6),Pasture(11)}
        };

	//matrix of places you can build a road at
        vector<vector<Buildable>> roadMap;
        //create the road map
        vector<vector<Buildable>> setRoadMap();
        //matrix of places you can build settlemets/cities at
        vector<vector<Buildable>> settlementMap;
        //init the settlemets matrix
        vector<vector<Buildable>> setSettlementMap();
        
        //loop through myBoard, and initiate the pointers to roads and settlements that around this place, to point to the
        //right index in the roadMap or the settlementMap. 
        void initBoard();


    public:

        Board();

        vector<vector<Buildable>> &getSettlementMap(){return settlementMap;}
        vector<vector<Buildable>> &getRoadMap(){return roadMap;}

        vector<vector<Place>> &getBoard(){return myBoard;}

        void printBoard() const{

            for(int i=0;i<5;i++) {
                if(i==0||i==4)
                    cout<<"     ";
                if(i==1||i==3)
                    cout<<"   ";
                for (Place p: myBoard[i]) {
                    if(p.getNum()!=0)
                        cout << p.getName() << " "<<p.getNum()<<" ";
                    else cout<<p.getName()<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }





    };




}

#endif
