#pragma once
#include "guard.h"

using namespace std;

class PointGuard:public Guard
{
    public:
    
    PointGuard():Guard(){};
    PointGuard(char* name, int jerseynumber, float height, float shoesize, int blocks, int assists, int fouls, int twopoints, int threepoints, int points):
    Guard(name, jerseynumber, height, shoesize, blocks, assists, fouls, twopoints, threepoints, points){} //SetAssitPoint(0);
    PointGuard(PointGuard &CopyPointGuard);
    PointGuard& operator = (const PointGuard& AssignPointGuard);
    virtual ~PointGuard();
    virtual void print(ostream& out) const;


    void AssistPointStatistics(int points, int assists);
    void SetAssitPoint(float statistic);
    float GetAssistPoint() const;
    void Shoot(ShootType shootype, bool Success);
    void Assist();


    private:

    float AssistPoint;

};

ostream& operator << (ostream& out, const PointGuard& PG); 