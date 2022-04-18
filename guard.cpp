#include "guard.h"

using namespace std;

Guard::Guard(Guard &CopyGuard)
{
    *this = CopyGuard;
};

Guard& Guard::operator = (const Guard& AssignGuard)
{
    SetName(AssignGuard.GetName());
    SetJerseyNumber(AssignGuard.GetJerseyNumber());
    SetHeight(AssignGuard.GetHeight());
    SetShoeSize(AssignGuard.GetShoeSize());
    SetBlocks(AssignGuard.GetBlocks());
    SetAssists(AssignGuard.GetAssists());
    SetFouls(AssignGuard.GetFouls());
    SetTwoPoints(AssignGuard.GetTwoPoints());
    SetThreePoints(AssignGuard.GetThreePoints());
    SetPoints(AssignGuard.GetPoints());
    return *this;
};

Guard::~Guard(){};

void Guard::print(ostream& out) const
{
    Player::print(out);
};

ostream& operator << (ostream& out, const Guard& g)
{
    g.print(out); 
    return out; 
}