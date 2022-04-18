#include "pointguard.h"

using namespace std;

PointGuard::PointGuard(PointGuard &CopyPointGuard)
{
    *this = CopyPointGuard;
};

PointGuard& PointGuard::operator = (const PointGuard& AssignPointGuard)
{
    SetName(AssignPointGuard.GetName());
    SetJerseyNumber(AssignPointGuard.GetJerseyNumber());
    SetHeight(AssignPointGuard.GetHeight());
    SetShoeSize(AssignPointGuard.GetShoeSize());
    SetBlocks(AssignPointGuard.GetBlocks());
    SetAssists(AssignPointGuard.GetAssists());
    SetFouls(AssignPointGuard.GetFouls());
    SetTwoPoints(AssignPointGuard.GetTwoPoints());
    SetThreePoints(AssignPointGuard.GetThreePoints());
    SetPoints(AssignPointGuard.GetPoints());
    SetAssitPoint(AssignPointGuard.GetAssistPoint());
    return *this;
};

PointGuard::~PointGuard(){};

void PointGuard::AssistPointStatistics(int points, int assists)
{
    if (points == 0)
    {
        SetAssitPoint(1);
    }else
    {
        SetAssitPoint(((float)assists*1.0f/(float)points*1.0) * 100.0f);
        if (GetAssistPoint() < 30)
        {
            cout << "The assist point ratio is too low" << endl;
        }
        
    }
};

void PointGuard::SetAssitPoint(float statistic)
{
    AssistPoint = statistic;
};

float PointGuard::GetAssistPoint() const 
{
    return AssistPoint;
}

void PointGuard::Shoot(ShootType shootype, bool Success)
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

    AssistPointStatistics(GetPoints(), GetAssists());
};

void PointGuard::Assist()
{
    SetAssists(GetAssists() + 1);
    if (GetAssists() > 10)
    {
        cout << "Well done" << endl;
    };

    AssistPointStatistics(GetPoints(), GetAssists());
};

void PointGuard::print(ostream& out) const
{
	Guard::print(out);
	cout << "Assist Point ratio: " << GetAssistPoint() << "%" << endl; 
}


ostream& operator << (ostream& out, const PointGuard& PG)
{
    PG.print(out); 
    return out; 
}