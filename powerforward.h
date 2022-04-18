#pragma once
#include "forward.h"

using namespace std;

class PowerForward:public Forward
{
    public:
    
    PowerForward():Forward(){};
    PowerForward(char* name, int jerseynumber, float height, float shoesize, int blocks, int assists, int fouls, int twopoints, int threepoints, int points):
    Forward(name, jerseynumber, height, shoesize, blocks, assists, fouls, twopoints, threepoints, points){SetBlockPoint(0);};
    PowerForward(PowerForward &CopyPowerForward);
    PowerForward& operator = (const PowerForward& AssignPowerForward);
    virtual ~PowerForward();
    virtual void print(ostream& out) const;

    void BlockPointStatistics(int points, int blocks);
    void SetBlockPoint(float statistic);
    float GetBlockPoint() const;
    void Shoot(ShootType shootype, bool Success);
    void Block();

    private:

    float BlockPoint;

};

ostream& operator << (ostream& out, PowerForward& PF); 