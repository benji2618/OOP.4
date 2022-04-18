#pragma once
#include "player.h"
#include "smallforward.h"
#include "shootingguard.h"
#include "powerforward.h"
#include "pointguard.h"

using namespace std;

class TeamManagement
{
    public:

    TeamManagement();
    TeamManagement(const TeamManagement& CopyTeam);
    virtual ~TeamManagement();

    TeamManagement* AddPlayer(Player* NewPlayer);
    void UpdateAllTeam(Player players[], int NumOfPlayers);
    void print() const;

    void doublePlayerSpace(); // add space

    Player*	createNewPlayer(Player* e); // for deep copy

    void Foul(int JerseyNumber);
    void ChooseStartingTeam();
    void Assist(int JerseyNumber);
    void Shot(int JerseyNumber,ShootType shootype, bool Success);
    void Block(int JerseyNumber);
    void substitute(int StartingTeamJerseyNum, int TeamJerseyNum);
    void TeamStatistic();
    void TeamPoints();


    private:

    int CurrNumOfPlayers;
    int MaxNumOfPlayers;
    Player **Players;
    Player **StartingTeam;
};

// ostream& operator << (ostream& out , const TeamManagement& TM); 