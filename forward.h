#pragma once
#include "player.h"

using namespace std;

class Forward:public Player
{
    public:
    
    Forward():Player(){};
    Forward(char* name, int jerseynumber, float height, float shoesize, int blocks, int assists, int fouls, int twopoints, int threepoints, int points):
    Player(name, jerseynumber, height, shoesize, blocks, assists, fouls, twopoints, threepoints, points){};
    Forward(Forward &CopyGuard);
    Forward& operator = (const Forward& AssignGuard);
    virtual ~Forward();
    virtual void print(ostream& out) const;

    private:

};

ostream& operator << (ostream& out, const Forward FW); 