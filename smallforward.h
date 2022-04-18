#pragma once
#include "forward.h"

using namespace std;

class SmallForward:public Forward
{
    public:
    
    SmallForward():Forward(){};
    SmallForward(char* name, int jerseynumber, float height, float shoesize, int blocks, int assists, int fouls, int twopoints, int threepoints, int points):
    Forward(name, jerseynumber, height, shoesize, blocks, assists, fouls, twopoints, threepoints, points)
    {
        if (height > 1.95)
        cout << "The player is not matching the expected height requirment" << endl;
    };
    SmallForward(SmallForward &CopySmallForward);
    SmallForward& operator = (const SmallForward& AssignSmallForward);
    virtual ~SmallForward();
    virtual void print(ostream& out) const;
    };
    ostream& operator << (ostream& out, SmallForward SF); 