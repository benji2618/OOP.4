#include "forward.h"

using namespace std;

Forward::Forward(Forward &CopyForward)
{
    *this = CopyForward;
};

Forward& Forward::operator = (const Forward& AssignForward)
{
    SetName(AssignForward.GetName());
    SetJerseyNumber(AssignForward.GetJerseyNumber());
    SetHeight(AssignForward.GetHeight());
    SetShoeSize(AssignForward.GetShoeSize());
    SetBlocks(AssignForward.GetBlocks());
    SetAssists(AssignForward.GetAssists());
    SetFouls(AssignForward.GetFouls());
    SetTwoPoints(AssignForward.GetTwoPoints());
    SetThreePoints(AssignForward.GetThreePoints());
    SetPoints(AssignForward.GetPoints());
    return *this;
};

Forward::~Forward(){};

void Forward::print(ostream& out) const
{
    Player::print(out);
};


ostream& operator << (ostream& out, const Forward FW)
{
    FW.print(out); 
    return out; 
}