#include "powerforward.h"

using namespace std;

PowerForward::PowerForward(PowerForward &CopyPowerForward)
{
    *this = CopyPowerForward;
};

PowerForward& PowerForward::operator = (const PowerForward& AssignPowerForward)
{
    SetName(AssignPowerForward.GetName());
    SetJerseyNumber(AssignPowerForward.GetJerseyNumber());
    SetHeight(AssignPowerForward.GetHeight());
    SetShoeSize(AssignPowerForward.GetShoeSize());
    SetBlocks(AssignPowerForward.GetBlocks());
    SetAssists(AssignPowerForward.GetAssists());
    SetFouls(AssignPowerForward.GetFouls());
    SetTwoPoints(AssignPowerForward.GetTwoPoints());
    SetThreePoints(AssignPowerForward.GetThreePoints());
    SetPoints(AssignPowerForward.GetPoints());
    SetBlockPoint(AssignPowerForward.GetBlockPoint());
    return *this;
};

PowerForward::~PowerForward(){};

void PowerForward::BlockPointStatistics(int points, int blocks)
{
    if (points == 0)
    {
        SetBlockPoint(1);
    }else
    {
        SetBlockPoint((float)(blocks*1.0f/points*1.0f) * 100.0f);
        if (GetBlockPoint() < 25)
        {
            cout << "The block point ratio is too low" << endl;
        }
        
    }
};

void PowerForward::SetBlockPoint(float statistic)
{
    this->BlockPoint = statistic;
};

float PowerForward::GetBlockPoint() const
{
    return BlockPoint;
}

void PowerForward::Shoot(ShootType shootype, bool Success)
{
    if (Success = 0)
        return;
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

    BlockPointStatistics(GetPoints(), GetBlocks());
};

void PowerForward::Block()
{
    SetBlocks(GetBlocks() + 1);
    if (GetBlocks() > 10)
    {
        cout << "Well done" << endl;
    }
    BlockPointStatistics(GetPoints(), GetBlocks());
};

void PowerForward::print(ostream& out) const
{
	Forward::print(out);
	cout << "Block Point ratio: " << GetBlockPoint() << "%" << endl;
}



ostream& operator << (ostream& out, PowerForward& PF)
{
    PF.print(out); 
    return out; 
}