#include "teammanagement.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

TeamManagement::TeamManagement()
{
    CurrNumOfPlayers = 0;
    MaxNumOfPlayers = 100;
    Players = new Player *[MaxNumOfPlayers];
    memset(Players, 0, sizeof(Player *) * MaxNumOfPlayers);
    StartingTeam = new Player *[5];
    memset(Players, 0, sizeof(Player *) * 5);
};

void TeamManagement::UpdateAllTeam(Player players[], int NumOfPlayers)
{
    for (int i = 0; i < CurrNumOfPlayers; ++i)
        delete Players[i];

    delete[] Players;

    CurrNumOfPlayers = 0;
    MaxNumOfPlayers = NumOfPlayers + 3;
    Players = new Player *[MaxNumOfPlayers];
    memset(Players, 0, sizeof(Player *) * MaxNumOfPlayers);

    for (int i = 0; i < NumOfPlayers; i++)
    {
        Player *NewPlayer = &players[i];
        AddPlayer(NewPlayer);
    }
};

TeamManagement *TeamManagement::AddPlayer(Player *NewPlayer)
{
    if (CurrNumOfPlayers == MaxNumOfPlayers)
        doublePlayerSpace();

    Players[CurrNumOfPlayers] = createNewPlayer(NewPlayer);
    ++CurrNumOfPlayers;
    return this;
}

Player *TeamManagement::createNewPlayer(Player *NewPlayer)
{
    PointGuard *pointguard = dynamic_cast<PointGuard *>(NewPlayer);
    if (nullptr != pointguard)
        return (pointguard);

    PowerForward *powerforward = dynamic_cast<PowerForward *>(NewPlayer);
    if (nullptr != powerforward)
        return powerforward;

    ShootingGuard *shootingguard = dynamic_cast<ShootingGuard *>(NewPlayer);
    if (nullptr != shootingguard)
        return shootingguard;

    SmallForward *smallforward = dynamic_cast<SmallForward *>(NewPlayer);
    if (nullptr != smallforward)
        return smallforward;

    Guard *guard = dynamic_cast<PointGuard *>(NewPlayer);
    if (nullptr != guard)
        return guard;

    Forward *forward = dynamic_cast<Forward *>(NewPlayer);
    if (nullptr != forward)
        return forward;

    return nullptr;
}

void TeamManagement::doublePlayerSpace()
{
    MaxNumOfPlayers = CurrNumOfPlayers * 2;
    Player **tempPlayer = new Player *[MaxNumOfPlayers];
    memcpy(tempPlayer, Players, CurrNumOfPlayers * sizeof(Player *));
    delete[] Players;
    Players = tempPlayer;
}

void TeamManagement::print() const
{

    for (int i = 0; i < CurrNumOfPlayers; ++i)
    {
        PointGuard *pointguard = dynamic_cast<PointGuard *>(Players[i]);
        if (nullptr != pointguard)
        { 
            cout << *pointguard << endl;
            continue; 
        }

        PowerForward *powerforward = dynamic_cast<PowerForward *>(Players[i]);
        if (nullptr != powerforward)
        {   
            cout << *powerforward << endl;
            continue; 
        }

        ShootingGuard *shootingguard = dynamic_cast<ShootingGuard *>(Players[i]);
        if (nullptr != shootingguard)
        {
            cout << *shootingguard << endl;
            continue;
        }

        SmallForward *smaillforward = dynamic_cast<SmallForward *>(Players[i]);
        if (nullptr != smaillforward)
        {
            cout << *smaillforward << endl;
            continue;
        }

            Guard *guard = dynamic_cast<Guard *>(Players[i]);
            if (nullptr != guard)
            {
                cout << *guard << endl;
                continue;
            }
            Forward *forward = dynamic_cast<Forward *>(Players[i]);
            if (nullptr != forward)
            {
                cout << *forward << endl;
                continue;
            }
            cout << "------------------------------" << std::endl;
        }
    cout << "********************************************" << std::endl;
}

TeamManagement::~TeamManagement()
{
    for (int i = 0; i < CurrNumOfPlayers; ++i)
        delete Players[i];

    delete[] Players;

    for (int i = 0; i < 5; i++)
        delete[] StartingTeam[i];

    delete[] StartingTeam;
}

TeamManagement::TeamManagement(const TeamManagement &CopyTeam)
{
    MaxNumOfPlayers = CopyTeam.CurrNumOfPlayers;
    CurrNumOfPlayers = CopyTeam.CurrNumOfPlayers;
    Players = new Player *[CurrNumOfPlayers];

    memcpy(Players, CopyTeam.Players, CurrNumOfPlayers * sizeof(Player *));

    StartingTeam = new Player *[5];
    memcpy(StartingTeam, CopyTeam.StartingTeam, 5 * sizeof(Player *));
}

void TeamManagement::ChooseStartingTeam()
{
    for (int i = 0; i < CurrNumOfPlayers; ++i)
    {
        cout << "Name: " << Players[i]->GetName() << endl
             << "Jersey number: " << Players[i]->GetJerseyNumber() << endl;
        std::cout << "------------------------------" << std::endl;
    }
    cout << "choose 5 players from the list by inset their jersey numbers" << endl;

    int count = 0;

    while (count < 5)
    {
        int choose;
        cout << count + 1 << " player " << endl;
        cin >> choose;

        int i = 0;
        for (i; i < CurrNumOfPlayers; ++i)
        {
            if (Players[i]->GetJerseyNumber() == choose)
            {
                StartingTeam[count] = Players[i];
                count++;
            }
            if (i == CurrNumOfPlayers)
            {
                cout << "Wrong input enter Jersey number again" << endl;
            }
        }
    }
}

void TeamManagement::Foul(int JerseyNumber)
{
    cout << "Select the jersey number of the player you want to commit foul" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << StartingTeam[i]->GetJerseyNumber() << endl;
    }

    int choose;
    cin >> choose;
    int found = 0;
    while (found == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            if (StartingTeam[i]->GetJerseyNumber() == choose)
            {
                found++;
                StartingTeam[i]->Foul();
                if (StartingTeam[i]->GetFouls() >= 5)
                {
                    cout << "This player commited 5 fouls" << endl;
                }
            }
        }
        if (found == 0)
        {
            cout << "Wrong input choose again" << endl;
            cin >> choose;
        }
    }
}

void TeamManagement::Assist(int JerseyNumber)
{
    cout << "Select the jersey number of the player you want to commit foul" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << StartingTeam[i]->GetJerseyNumber() << endl;
    }

    int choose;
    cin >> choose;
    int found = 0;
    while (found == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            if (StartingTeam[i]->GetJerseyNumber() == choose)
            {
                found++;
                StartingTeam[i]->Assist();
            }
        }
        if (found == 0)
        {
            cout << "Wrong input choose again" << endl;
            cin >> choose;
        }
    }
}

void TeamManagement::Shot(int JerseyNumber, ShootType shootype, bool Success)
{
    cout << "Select the jersey number of the player you want to commit foul" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << StartingTeam[i]->GetJerseyNumber() << endl;
    }

    int choose;
    cin >> choose;
    int found = 0;
    while (found == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            if (StartingTeam[i]->GetJerseyNumber() == choose)
            {
                found++;
                StartingTeam[i]->Shoot(shootype, Success);
            }
        }
        if (found == 0)
        {
            cout << "Wrong input choose again" << endl;
            cin >> choose;
        }
    }
}

void TeamManagement::Block(int JerseyNumber)
{
    cout << "Select the jersey number of the player you want to commit foul" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << StartingTeam[i]->GetJerseyNumber() << endl;
    }

    int choose;
    cin >> choose;
    int found = 0;
    while (found == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            if (StartingTeam[i]->GetJerseyNumber() == choose)
            {
                found++;
                StartingTeam[i]->Block();
            }
        }
        if (found == 0)
        {
            cout << "Wrong input choose again" << endl;
            cin >> choose;
        }
    }
}

void TeamManagement::substitute(int StartingTeamJerseyNum, int TeamJerseyNum)
{
    int choose;
    int found = 0;
    while (found == 0) // check the StartingTeamJerseyNum
    {
        for (int i = 0; i < 5; i++)
        {
            if (StartingTeam[i]->GetJerseyNumber() == StartingTeamJerseyNum)
            {
                found++;
            }
        }
        if (found == 0)
        {
            cout << "No player in starting team has this jersey number, try again  " << endl;
            cin >> choose;
        }
    }

    int NotFound = 0;
    while (NotFound == 0) // check the TeamJerseyNum
    {
        for (int i = 0; i < 5; i++)
        {
            if (StartingTeam[i]->GetJerseyNumber() == TeamJerseyNum)
            {
                cout << "This player already in the starting team, try again " << endl;
                cin >> TeamJerseyNum;
                NotFound--;
            }
        }
        NotFound++;
    }

    int PlayerIndex;
    int StartingTeamIndex;

    for (int TmpPlayersIndex = 0; TmpPlayersIndex < CurrNumOfPlayers; TmpPlayersIndex++)
    {
        if (Players[TmpPlayersIndex]->GetJerseyNumber() == TeamJerseyNum)
        {
            PlayerIndex = TmpPlayersIndex;
            break;
        }
    }

    for (int TmpStartingTeamIndex = 0; TmpStartingTeamIndex < 5; TmpStartingTeamIndex++)
    {
        if (StartingTeam[TmpStartingTeamIndex]->GetJerseyNumber() == StartingTeamJerseyNum)
        {
            StartingTeamIndex = TmpStartingTeamIndex;
            break;
        }
    }

    StartingTeam[StartingTeamIndex] = Players[PlayerIndex];
}

void TeamManagement::TeamStatistic()
{
    int TeamBlocks = 0;
    int TeamAssists = 0;
    int TeamTwoPoints = 0;
    int TeamThreePoints = 0;
    int TeamPoints = 0;

    for (int i = 0; i < CurrNumOfPlayers; i++)
    {
        TeamBlocks += Players[i]->GetBlocks();
        TeamAssists += Players[i]->GetAssists();
        TeamTwoPoints += Players[i]->GetTwoPoints();
        TeamThreePoints += Players[i]->GetThreePoints();
        TeamPoints += Players[i]->GetPoints();
    }

    cout << "Team statistics" << endl
         << endl;
    cout << "Blocks: " << TeamBlocks << endl;
    cout << "Assists: " << TeamAssists << endl;
    cout << "Two points: " << TeamTwoPoints << endl;
    cout << "Three points: " << TeamThreePoints << endl;
    cout << "Points: " << TeamPoints << endl;
}

void TeamManagement::TeamPoints()
{
    int TeamPoints = 0;

    for (int i = 0; i < CurrNumOfPlayers; i++)
    {

        TeamPoints += Players[i]->GetPoints();
    }

    cout << "Team Points: " << TeamPoints << endl;
}
