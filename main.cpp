#pragma once
#include "player.h"
#include "smallforward.h"
#include "shootingguard.h"
#include "powerforward.h"
#include "pointguard.h"
#include "teammanagement.h"

int main()
{
    PowerForward p1((char*)"ilai",10,1.7,42.5,0,0,0,0,0,0);
    ShootingGuard p2((char*)"benjamin",9,1.7,42,0,0,0,0,0,0);
    PointGuard p3((char*)"avi",7,1.9,46,0,0,0,0,0,0);
    PowerForward p4((char*)"yossi",6,1.9,46,0,0,0,0,0,0);
    SmallForward p5((char*)"david",5,1.9,46,0,0,0,0,0,0);
    SmallForward p6((char*)"ron",3,1.9,46,0,0,0,0,0,0);
    TeamManagement manage; 

    manage.AddPlayer(&p1);
    manage.AddPlayer(&p2); 
    manage.AddPlayer(&p3);
    manage.AddPlayer(&p4); 
    manage.AddPlayer(&p6);

    manage.print();
    cout << "1" << endl; 
    manage.Assist(10);
    manage.Foul(9);
    manage.Shot(8,ThreePointers,1);
    
}