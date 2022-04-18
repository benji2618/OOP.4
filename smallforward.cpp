#include "smallforward.h"

using namespace std;

SmallForward::SmallForward(SmallForward &CopySmallForward)
{
    *this = CopySmallForward;
};

SmallForward& SmallForward::operator = (const SmallForward& AssignSmallForward)
{
    SetName(AssignSmallForward.GetName());
    SetJerseyNumber(AssignSmallForward.GetJerseyNumber());
    SetHeight(AssignSmallForward.GetHeight());
    SetShoeSize(AssignSmallForward.GetShoeSize());
    SetBlocks(AssignSmallForward.GetBlocks());
    SetAssists(AssignSmallForward.GetAssists());
    SetFouls(AssignSmallForward.GetFouls());
    SetTwoPoints(AssignSmallForward.GetTwoPoints());
    SetThreePoints(AssignSmallForward.GetThreePoints());
    SetPoints(AssignSmallForward.GetPoints());
    return *this;
};

SmallForward::~SmallForward(){};

void SmallForward::print(ostream& out) const
{
    Forward::print(out);
};


  ostream& operator << (ostream& out, SmallForward SF)
  {
      SF.print(out); 
      return out; 
  }