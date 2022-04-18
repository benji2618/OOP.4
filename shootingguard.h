#pragma once
#include "guard.h"

using namespace std;

class ShootingGuard:public Guard
{
    public:
    
    ShootingGuard():Guard(){};
    ShootingGuard(char* name, int jerseynumber, float height, float shoesize, int blocks, int assists, int fouls, int twopoints, int threepoints, int points):
    Guard(name, jerseynumber, height, shoesize, blocks, assists, fouls, twopoints, threepoints, points){SetShotsSuccessStatistic(0.0f);SetSuccessfulShots(0);SetShots(0);}
    ShootingGuard(ShootingGuard &CopyShootingGuard);
    ShootingGuard& operator = (const ShootingGuard& AssignShootingGuard);
    virtual ~ShootingGuard();
    virtual void print(ostream& out) const;

    void ShotsSuccessStatistics(int shots, int success);    
    void SetShotsSuccessStatistic(float statistic);
    float GetShotsSuccessStatistic() const;

    void SetSuccessfulShots(int successfulshots);
    int GetSuccessfulShots() const;

    void SetShots(int shots);
    int GetShots() const;

    void Shoot(ShootType shootype, bool Success);


    private:

    int TotallShots;
    int SuccessfulShots;
    float ShotsSuccessStatistic;
};
ostream& operator << (ostream& out, const ShootingGuard& SG); 