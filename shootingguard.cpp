#include "shootingguard.h"

using namespace std;

ShootingGuard::ShootingGuard(ShootingGuard &CopyShootingGuard)
{
    *this = CopyShootingGuard;
};

ShootingGuard& ShootingGuard::operator = (const ShootingGuard& AssignShootingGuard)
{
    SetName(AssignShootingGuard.GetName());
    SetJerseyNumber(AssignShootingGuard.GetJerseyNumber());
    SetHeight(AssignShootingGuard.GetHeight());
    SetShoeSize(AssignShootingGuard.GetShoeSize());
    SetBlocks(AssignShootingGuard.GetBlocks());
    SetAssists(AssignShootingGuard.GetAssists());
    SetFouls(AssignShootingGuard.GetFouls());
    SetTwoPoints(AssignShootingGuard.GetTwoPoints());
    SetThreePoints(AssignShootingGuard.GetThreePoints());
    SetPoints(AssignShootingGuard.GetPoints());
    return *this;
};

ShootingGuard::~ShootingGuard(){};

void ShootingGuard::ShotsSuccessStatistics(int shots, int success)
{
    if (shots == 0)
    {
        SetShotsSuccessStatistic(1);
    }else
    {
        SetShotsSuccessStatistic((float)((success*1.0f/shots*1.0f) * 100.0f));
        if (GetShotsSuccessStatistic() < 30)
        {
            cout << "The shots success ratio is too low" << endl;
        }
        
    }
};

void ShootingGuard::SetShotsSuccessStatistic(float statistic)
{
    ShotsSuccessStatistic = statistic;
};

float ShootingGuard::GetShotsSuccessStatistic() const
{
    return ShotsSuccessStatistic;
}

void ShootingGuard::SetShots(int shots)
{
    TotallShots = shots;
};

int ShootingGuard::GetShots() const
{
    return TotallShots;
}

void ShootingGuard::SetSuccessfulShots(int successfulshots)
{
    SuccessfulShots = successfulshots;
};

int ShootingGuard::GetSuccessfulShots() const
{
    return SuccessfulShots;
}

void ShootingGuard::Shoot(ShootType shootype, bool Success)
{   
    SetShots(GetShots() + 1);
    if (Success = 0)
    {
        ShotsSuccessStatistics(GetShots(), GetSuccessfulShots());
        return;
    }
    if (shootype == TwoPointers)
    {
        SetPoints(GetPoints() + 2);
        SetTwoPoints(GetTwoPoints() + 1);
    }
    if (shootype == ThreePointers)
    {
        SetPoints(GetPoints() + 3);
        SetThreePoints(GetThreePoints() + 1);
    }

    SetSuccessfulShots(GetSuccessfulShots() + 1);
    ShotsSuccessStatistics(GetShots(), GetSuccessfulShots());
};

void ShootingGuard::print(ostream& out) const
{
	Guard::print(out);
	cout << "Shot Success ratio: " << GetShotsSuccessStatistic() << "%" << endl;
}

ostream& operator << (ostream& out, const ShootingGuard& SG)
{
    SG.print(out); 
    return out; 
}