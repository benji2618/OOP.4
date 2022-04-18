#include <iostream>
#include <cstring>
#include <string>
#pragma once

using namespace std;

enum ShootType{TwoPointers, ThreePointers};

class Player
{
    public:

    Player():Name(NULL), JerseyNumber(0), Height(0), ShoeSize(0), Blocks(0), Assists(0), Fouls(0), TwoPoints(0), ThreePoints(0), Points(0){};
    Player(char* name, int jerseynumber, float height, float shoesize, int blocks, int assists, int fouls, int twopoints, int threepoints, int points);
    Player(Player &CopyPlayer);
    Player& operator = (const Player& AssignPlayer);
    virtual ~Player();
    virtual void print(ostream& out) const;

    void SetName(char* name);
    char* GetName() const;
    void SetJerseyNumber(int jerseynumber);
    int GetJerseyNumber() const;
    void SetHeight(float height);
    float GetHeight() const;
    void SetShoeSize(float shoesize);
    float GetShoeSize() const;
    void SetBlocks(int blocks);
    int GetBlocks() const;
    void SetAssists(int assists);
    int GetAssists() const;
    void SetFouls(int fouls);
    int GetFouls() const;
    void SetTwoPoints(int twopoints);
    int GetTwoPoints() const;
    void SetThreePoints(int threepoints);
    int GetThreePoints() const;
    void SetPoints(int points);
    int GetPoints() const;

    void Foul();
    virtual void Shoot(ShootType shootype, bool Success);
    virtual void Assist();
    virtual void Block();

    
    private:

    char* Name;
    int JerseyNumber;
    float Height;
    float ShoeSize;
    int Blocks;
    int Assists;
    int Fouls;
    int TwoPoints;
    int ThreePoints;
    int Points;

};

ostream& operator<< (ostream& out, const Player& p); 