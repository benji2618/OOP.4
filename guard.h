#pragma once
#include "player.h"

using namespace std;

class Guard:public Player
{
    public:
    
    Guard():Player(){};
    Guard(char* name, int jerseynumber, float height, float shoesize, int blocks, int assists, int fouls, int twopoints, int threepoints, int points):
    Player(name, jerseynumber, height, shoesize, blocks, assists, fouls, twopoints, threepoints, points){};
    Guard(Guard &CopyGuard);
    Guard& operator = (const Guard& AssignGuard);
    virtual ~Guard();
    virtual void print(ostream& out) const;

    private:
};

ostream& operator << (ostream& out, const Guard& g); 