#include "player.h"

using namespace std;


Player::Player(char* name, int jerseynumber, float height, float shoesize, int blocks, int assists, int fouls, int twopoints, int threepoints, int points)
{
    while (jerseynumber < 0)
    {
        cout << "Jersey Number, Must be a positive number, enter again" << endl;
        cin >> jerseynumber;
    }
    while (height < 0)
    {
        cout << "height, Must be a positive number, enter again" << endl;
        cin >> height;
    }
    while (shoesize < 0)
    {
        cout << "shoesize, Must be a positive number, enter again" << endl;
        cin >> shoesize;
    }
    while (blocks < 0)
    {
        cout << "Number of blocks, Must be a positive number, enter again" << endl;
        cin >> blocks;
    }
    while (assists < 0)
    {
        cout << "Number of assists, Must be a positive number, enter again" << endl;
        cin >> assists;
    }
    while (fouls < 0)
    {
        cout << "Number of fouls, Must be a positive number, enter again" << endl;
        cin >> fouls;
    }
    while (twopoints < 0)
    {
        cout << "Number of twopoints, Must be a positive number, enter again" << endl;
        cin >> twopoints;
    }
    while (threepoints < 0)
    {
        cout << "Number of threepoints, Must be a positive number, enter again" << endl;
        cin >> threepoints;
    }
    while (points < 0)
    {
        cout << "Number of points, Must be a positive number, enter again" << endl;
        cin >> points;
    }
    
    SetName(name);
    SetJerseyNumber(jerseynumber);
    SetHeight(height);
    SetShoeSize(shoesize);
    SetBlocks(blocks);
    SetAssists(assists);
    SetFouls(fouls);
    SetTwoPoints(twopoints);
    SetThreePoints(threepoints);
    SetPoints(points);
};

Player::Player(Player &CopyPlayer)
{
    *this = CopyPlayer;
};

Player& Player::operator = (const Player& AssignPlayer)
{
    SetName(AssignPlayer.GetName());
    SetJerseyNumber(AssignPlayer.GetJerseyNumber());
    SetHeight(AssignPlayer.GetHeight());
    SetShoeSize(AssignPlayer.GetShoeSize());
    SetBlocks(AssignPlayer.GetBlocks());
    SetAssists(AssignPlayer.GetAssists());
    SetFouls(AssignPlayer.GetFouls());
    SetTwoPoints(AssignPlayer.GetTwoPoints());
    SetThreePoints(AssignPlayer.GetThreePoints());
    SetPoints(AssignPlayer.GetPoints());
    return *this;
};

Player::~Player()
{
    delete Name;
};

void Player::SetName(char* name)
{
    Name = name;
};

char* Player::GetName() const
{
    return Name;
};

void Player::SetJerseyNumber(int jerseynumber)
{
    JerseyNumber = jerseynumber;
};

int Player::GetJerseyNumber() const
{
    return JerseyNumber;
};

void Player::SetHeight(float height)
{
    Height = height;
};

float Player::GetHeight() const
{
    return Height;
};

void Player::SetShoeSize(float shoesize)
{
    ShoeSize = shoesize;
};

float Player::GetShoeSize() const
{
    return ShoeSize;
};

void Player::SetBlocks(int blocks)
{
    Blocks = blocks;
};

int Player::GetBlocks() const
{
    return Blocks;
};

void Player::SetAssists(int assists)
{
    Assists = assists;
};

int Player::GetAssists() const
{
    return Assists;
};

void Player::SetFouls(int fouls)
{
    if (fouls >= 5)
    {
        cout << "player is banned from this game" << endl;
        fouls = 5;
    }
    Fouls = fouls;
};

int Player::GetFouls() const
{
    return Fouls;
};

void Player::SetTwoPoints(int twopoints)
{
    TwoPoints = twopoints;
};

int Player::GetTwoPoints() const
{
    return TwoPoints;
};

void Player::SetThreePoints(int threepoints)
{
    ThreePoints = threepoints;
};

int Player::GetThreePoints() const
{  
    return ThreePoints;
};

void Player::SetPoints(int points)
{
    Points = points;
};

int Player::GetPoints() const
{
    return Points;
};

void Player::Foul()
{
    int NewFoulsNumber;
    NewFoulsNumber = GetFouls() + 1;
    SetFouls(NewFoulsNumber);
};

void Player::Shoot(ShootType shootype, bool Success)
{
    if (Success = 0)
        return;
    if (shootype == TwoPointers)
    {
        SetPoints(GetPoints() + 2);
        SetTwoPoints(GetTwoPoints() + 1);
        return;
    }
    if (shootype == ThreePointers)
    {
        SetPoints(GetPoints() + 3);
        SetThreePoints(GetThreePoints() + 1);
        return;
    }
};

void Player::Assist()
{
    SetAssists(GetAssists() + 1);
    if (GetAssists() > 10)
    {
        cout << "Well done" << endl;
    };
    return;
};

void Player::Block()
{
    SetBlocks(GetBlocks() + 1);
    if (GetBlocks() > 10)
    {
        cout << "Well done" << endl;
    }
    return;
};

void Player::print(ostream& out) const
{
    if (Name == NULL)
    {
        cout << endl << "Name: " << endl << "Jersey number: " << GetJerseyNumber() << endl <<  "Height: " << GetHeight() << endl << "Shoe size: " << GetShoeSize() << endl << "Blocks: " << GetBlocks() << endl << "Assists: " << GetAssists() << endl << "Fouls: " << GetFouls() << endl << "Two points: " << GetTwoPoints() << endl << "Three points: " << GetThreePoints() << endl << "Points: " << GetPoints() << endl;
    }else
    {
	    cout << endl << "Name: " << GetName() << endl << "Jersey number: " << GetJerseyNumber() << endl <<  "Height: " << GetHeight() << endl << "Shoe size: " << GetShoeSize() << endl << "Blocks: " << GetBlocks() << endl << "Assists: " << GetAssists() << endl << "Fouls: " << GetFouls() << endl << "Two points: " << GetTwoPoints() << endl << "Three points: " << GetThreePoints() << endl << "Points: " << GetPoints() << endl;
    }
}

ostream& operator<< (ostream& out, const Player& p)
{
    p.print(out); 
    return out; 
}