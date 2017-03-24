#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <time.h>
#include "Project2/const.h"
#include "Project2/asm.h"
#include "Project2/matrix.h"
#include "Project2/graph.h"
#include "Project2/draws.h"
#include "Project2/image.h"

void main ()
{
    char keydown;

    if(!setVideoMode(v800x600x256, 800, 600)){
      printf("\r\nError couldn't initialize SVGA.\r\n");
      return;
    }

    drawHelp();
    while(keydown != '1') {
        if (kbhit()) {
            keydown = getch();
        }
    }

    /* Set blank and draw house and tree */
    drawFilledRectangle(0, 0, 800, 600, WHITE);
    initHouse();
    initTree();
    //showPalette();
    keydown = 0;
    // Exit with x
    while(keydown != 'x') {
        if (kbhit()) {
            keydown = getch();
            switch(keydown) {
                /* Move the house 
                    Up: w
                    Down: s
                    left: a
                    Right: d

                    House transformations
                    Rotate: q
                    Scale: e, r
                */
                // Move Up
                case 'w':
                    eraseHouse();
                    houseTranslation(MOVE_UP);
                    drawTree();
                    drawHouse();
                    break;            
                // Move Down
                case 's':
                    eraseHouse();
                    houseTranslation(MOVE_DOWN);
                    drawTree();
                    drawHouse();
                    break;

                // Move to the left
                case 'a':
                    eraseHouse();
                    houseTranslation(MOVE_LEFT);
                    drawTree();
                    drawHouse();
                    break;
                // Move to the Right
                case 'd':
                    eraseHouse();
                    houseTranslation(MOVE_RIGHT);
                    drawTree();
                    drawHouse();
                    break;

                // Rotate
                case 'q':
                    eraseHouse();
                    houseRotation();
                    drawTree();
                    drawHouse();
                    break;
                // Scale in
                case 'e':
                    eraseHouse();
                    houseScale(IN);                    
                    drawTree();
                    drawHouse();
                    break;
                // Scale out
                case 'r':
                    eraseHouse();
                    houseScale(OUT);                    
                    drawTree();
                    drawHouse();
                    break;
                // Shear Up
                case 't':
                    eraseHouse();
                    houseShear(MOVE_UP);
                    drawTree();
                    drawHouse();
                    break;
                // Shear Down
                case 'g':
                    eraseHouse();
                    houseShear(MOVE_DOWN);
                    drawTree();
                    drawHouse();
                    break;
                // Shear Left
                case 'f':
                    eraseHouse();
                    houseShear(MOVE_LEFT);
                    drawTree();
                    drawHouse();
                    break;
                // Move to the Shear Right
                case 'h':
                    eraseHouse();
                    houseShear(MOVE_RIGHT);
                    drawTree();
                    drawHouse();
                    break;

                /* Move the tree 
                    Up: i
                    Down: k
                    left: j
                    Right: l

                    House transformations
                    Rotate: o
                    Scale in: u
                    Scale out: y
                */

                // Tree Up
                case 'i':
                    eraseTree();
                    treeTranslation(MOVE_UP);
                    drawHouse();
                    drawTree();
                    break;
                // Tree Down
                case 'k':
                    eraseTree();
                    treeTranslation(MOVE_DOWN);
                    drawHouse();
                    drawTree();
                    break;
                // Move to the Left
                case 'j':
                    eraseTree();
                    treeTranslation(MOVE_LEFT);
                    drawHouse();
                    drawTree();
                    break;
                // Move to the Right
                case 'l':
                    eraseTree();
                    treeTranslation(MOVE_RIGHT);
                    drawHouse();
                    drawTree();
                    break;  

                // Rotate tree
                case 'o':
                    eraseTree();
                    treeRotation();
                    drawHouse();
                    drawTree();
                    break;
                // Scale tree in
                case 'u':
                    eraseTree();
		            treeScale(IN);
                    drawHouse();
                    drawTree();
                    break;
                // Scale tree out
                case 'y':
                    eraseTree();
		            treeScale(OUT);
                    drawHouse();
                    drawTree();
                    break;

                // Shear up
                case 'p':
                    eraseTree();
                    treeShear(MOVE_UP);
                    drawHouse();
                    drawTree();
                    break;
                // Shear down
                case ';':
                    eraseTree();
                    treeShear(MOVE_DOWN);
                    drawHouse();
                    drawTree();
                    break;
                // Shear left
                case ',':
                    eraseTree();
                    treeShear(MOVE_LEFT);
                    drawHouse();
                    drawTree();
                    break;
                // Shear right
                case '.':
                    eraseTree();
                    treeShear(MOVE_RIGHT);
                    drawHouse();
                    drawTree();
                    break;
                case '1':
                    drawHelp();
                    while(keydown != '2') {
                        if (kbhit()) {
                            keydown = getch();
                        }
                    }

                    /* Set blank and draw house and tree */
                    drawFilledRectangle(0, 0, 800, 600, WHITE);
                    drawHouse();
                    drawTree();
                    break;
            };
        }
    }

    unsetVideoMode();
}
