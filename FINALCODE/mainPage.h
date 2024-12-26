//header file to make the main page where the game takes place

#ifndef mainPage_H
#define mainPage_H

#include <Text.h>
#include "simulator_libraries/FEHUtility.h"
#include "simulator_libraries/FEHLCD.h"
#include "simulator_libraries/FEHImages.h"
#include <Welcome.h>

bool isPlantScreenActive = false;

//makes tool bar with touch evaluation
void toolBar(void screen1(), void screen2())
{
    FEHImage plant("potplantTR.png");
    plant.Draw(115,213);

    FEHImage about("aboutIcon.png");
    about.Draw(155,211);

    int x_coord, y_coord;
    //while(true)
    //{
        if (LCD.Touch(&x_coord, &y_coord))//check for clicks
        {
            // If the click coordinates are within the button, goes to plant screen
            if (x_coord>=115 && x_coord<=145 && y_coord<=243 && y_coord>=213)
            {
                screen1();
            }
            else if (x_coord>=155 && x_coord<=185 && y_coord<=243 && y_coord>=213)
            {
                screen2();
            }
            LCD.Update();
        }
    //}
}

//goes back to the main screen
void goBackStart(void screen1())
{
    int x_coord, y_coord;

    while(true)
    {
        // Waits for click
        while(!LCD.Touch(&x_coord, &y_coord)){}

        // Waits for release
        while(LCD.Touch(&x_coord, &y_coord)){}

        // If the click coordinates are within the button, goes back ot main screen
        if(x_coord>=250 && x_coord<=280 && y_coord<=60 && y_coord>=30)
        {
            screen1();
        }
        
        LCD.Update();
    }
}


//creates different screens
void createScreen(const char* imageFilename)
{
    FEHImage screen(imageFilename);  // Load the screen image from the given file
    screen.Draw(0,0);  // Draw the image at the specified position
}

#endif
