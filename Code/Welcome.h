#ifndef Welcome_H
#define Welcome_H

#include "simulator_libraries/FEHUtility.h"
#include "simulator_libraries/FEHLCD.h"
#include "simulator_libraries/FEHImages.h"
#include <Text.h>
#include <sstream>
#include <cstdio> 
#include <iostream> 

using namespace std;

//welcome screen with touch evaluation
void welcome(void screen1(), void screen2(), void screen3(), void screen4())
{
    
    int x1=-150,x2=-100,x3=-50,x4=0;
    // Make racers move across the screen
    while (x1<-70 && x2<-20 && x3<30,x4<80) 
    {
    FEHImage titlePage("TitlePage.png");
    titlePage.Draw(0,0);
    FEHImage start;
    start.Open("start.png");
    start.Draw(x1,80);
    
    FEHImage stats;
    stats.Open("stats.png");
    stats.Draw(x2,105);

    FEHImage rules;
    rules.Open("rules.png");
    rules.Draw(x3,54);

    FEHImage credit;
    credit.Open("credit.png");
    credit.Draw(x4,29);

    x1+=5;
    x2+=5;
    x3+=5;
    x4+=5;

    Sleep (0.1);
    LCD.Update();
    }

    int x_coord, y_coord;
    while(true)
    {
        // Waits for click
        while(!LCD.Touch(&x_coord, &y_coord)){}

        // Waits for release
        while(LCD.Touch(&x_coord, &y_coord)){}

        // If the click coordinates are within the button, (does stuff)
        if(x_coord>=67 && x_coord<=104 && y_coord<=191 && y_coord>=179)
        {
            screen1();
        }
        else if (x_coord>=117 && x_coord<=154 && y_coord<=191 && y_coord>=179)
        {
            screen2();
        }
        else if (x_coord>=167 && x_coord<=204 && y_coord<=191 && y_coord>=179)
        {
            screen3();
        }
        else if (x_coord>=217 && x_coord<=254 && y_coord<=191 && y_coord>=179)
        {
            screen4();
        }

        LCD.Update();
    }
}

//goes back to welcome screen
void goBackWelcome(void screen1(),void screen2(),void screen3(),void screen4())
{
    int x_coord, y_coord;

    while(true)
    {
        // Waits for click
        while(!LCD.Touch(&x_coord, &y_coord)){}

        // Waits for release
        while(LCD.Touch(&x_coord, &y_coord)){}

        // If the click coordinates are within x button, goes back
        if(x_coord>=250 && x_coord<=280 && y_coord<=60 && y_coord>=30)
        {
            welcome(screen1, screen2, screen3, screen4);   
        }
        LCD.Update();
    }
}



#endif
