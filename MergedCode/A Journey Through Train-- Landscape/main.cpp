#include<iostream>
#include "alavi.h"
#include "pranto.h"
#include "diganta.h"

int currentVariable = 1;

void adisplay2();
void adisplay1();

void displayd();
//a13
//A8
void handleKeypressa(unsigned char key, int x, int y) {


        switch (key) {

case 27:
            exit(0);
            break;
        case 'h':
        case 'H':
            PlaySound("train.wav", NULL, SND_FILENAME | SND_ASYNC);
            break;
case '2':
    glutDisplayFunc(adisplay2);
    currentVariable = 1;
    day=false;
    glutPostRedisplay();
    break;
case '1':
    glutDisplayFunc(adisplay1);
    currentVariable = 1;
    day=true;
    glutPostRedisplay();
    break;
case '3':
    glutDisplayFunc(display);
    currentVariable = 2;
    glutPostRedisplay();
    break;
case '4':
    glutDisplayFunc(display2);
    currentVariable = 2;
    glutPostRedisplay();
    break;
case '5':
    glutDisplayFunc(displayd);
    currentVariable = 3;
    glutPostRedisplay();
    break;
//if (currentVariable == 2) {
case 'l':
case 'L':
    // Toggle window lights ON/OFF (only meaningful in night mode)
    lightsOn = !lightsOn;
    glutPostRedisplay();
    break;
//}
case 's': // Stop bus and freeze signboard
case 'S':
    bus1_speed = 0.0f;
    signboardToggleEnabled = false;
    isRed = true; // Force red
    glutPostRedisplay();
    break;

case 'm': // Resume bus and signboard
case 'M':
    bus1_speed = 5.0f; // Or any speed you want
    signboardToggleEnabled = true;
    glutPostRedisplay();
    break;

case 'q':
case 'Q':
    manualCar2Control = !manualCar2Control;
    break;

case 'd':
    car2_movea += car2_speeda;
    if (car2_movea > 1200) { // adjust based on your screen width
        car2_movea = -1700;   // re-enter from left side
    }
    break;


case 'a':
case 'A':
    if (manualCar2Control) car2_movea -= car2_speeda;
    break;

case 'w':
case 'W':
    if (manualCar2Control && car2_y < car2_y_max)
        car2_y += car2_speeda;
    break;

case 'x':
case 'X':
    if (manualCar2Control && car2_y > car2_y_min)
        car2_y -= car2_speeda;
    break;

case 'f':  // Pause both
            paused = true;
            break;

        case 'g':  // Resume both
            paused = false;
            break;

        case 'j':  // Slow down both
            speed -= speed_step;
            if (speed < speed_min) speed = speed_min;
            break;

        case 'k':  // Speed up both
            speed += speed_step;
            if (speed > speed_max) speed = speed_max;
            break;

case 't':  // Speed up bus2
            bus2_speed += 1.0f;
            if (bus2_speed > bus2_max_speed)
                bus2_speed = bus2_max_speed;
            break;

        case 'y':  // Slow down bus2
            bus2_speed -= 1.0f;
            if (bus2_speed < bus2_min_speed)
                bus2_speed = bus2_min_speed;
            break;

    // Add other cases if needed
}
//PRANTO
if (currentVariable == 2){

 if (key == 'B' || key == 'b') {
        isBusMoving = !isBusMoving;
    }
glutPostRedisplay();

}


//DIGANTA
if (currentVariable == 3){
     if (key == 'w') {
        rainActive = 1; // Start rain
    }
    else if (key == 's') {
        rainActive = 0; // Stop rain and CLEAR everything
        dropCount = 0;  // Remove all drops
        bubbleCount = 0; // Remove all bubbles
    }

    //cloud keys
    if (key == 'i') {
        cloudDirection = 1; // Move right
    }
    else if (key == 'p') {
        cloudDirection = -1; // Move left
    }

    //bird keys
    if (key == 'd' || key == 'D') {
        birdDirection = 1;  // Fly right
    }
    else if (key == 'a' || key == 'A') {
        birdDirection = -1; // Fly left
    }

    //shipSpeed key
    if (key == 'c' || key == 'C') {
        shipSpeed += 1.5;
    }
    else if (key == 'z' || key == 'Z') {
        shipSpeed -= 1.5;
    }

    //boatSpeed key
    if (key == 'e' || key == 'E') {
        boatSpeed += 1.5;
    }
    else if (key == 'q' || key == 'Q') {
        boatSpeed -= 1.5;
    }

    //day night keys
    if (key == 'n' || key == 'N') {
        isNight = true;
    } else if (key == 'B' || key == 'b') {
        isNight = false;
    }

    glutPostRedisplay();


}
}

//a14
void handleSpecialKey(int key, int x, int y) {
    if (currentVariable==1){
    if (key == GLUT_KEY_UP) {
        if (plane_y_offset < 90.0f)
            plane_y_offset += 10.0f;
    } else if (key == GLUT_KEY_DOWN) {
        if (plane_y_offset > -50.0f)
            plane_y_offset -= 10.0f;
    } else if (key == GLUT_KEY_RIGHT) {
        plane_speed += 1.0f;
        if (plane_speed > plane_max_speed)
            plane_speed = plane_max_speed;
    } else if (key == GLUT_KEY_LEFT) {
        plane_speed -= 1.0f;
        if (plane_speed < plane_min_speed)
            plane_speed = plane_min_speed;
    }

    glutPostRedisplay();
    }
    else if(currentVariable==2){
        switch (key) {
        case GLUT_KEY_UP:
            busY += 5.0f;
            break;
        case GLUT_KEY_DOWN:
            busY -= 5.0f;
            break;
    }
    glutPostRedisplay();
    }
}

//a15
//A9

void unifiedMouseHandler(int button, int state, int x, int y) {
    if (state != GLUT_DOWN) return;

    if (currentVariable == 1) {
        // For adisplay1 / adisplay2
        if (button == GLUT_LEFT_BUTTON) {
            if (train_speeda < MAX_SPEED)
                train_speeda += 1.0f;
        } else if (button == GLUT_RIGHT_BUTTON) {
            if (train_speeda > MIN_SPEED)
                train_speeda -= 1.0f;
        } else if (button == GLUT_MIDDLE_BUTTON) {
            train_speeda = 5.0f;
        }
        if (button == 3) {  // Scroll up
            if (boat1_speeda < boat1_max_speeda)
                boat1_speeda += 0.5f;
        } else if (button == 4) {  // Scroll down
            if (boat1_speeda > boat1_min_speeda)
                boat1_speeda -= 0.5f;
        }
    } else if (currentVariable == 2) {
        // For display / display2
        if (button == GLUT_LEFT_BUTTON) {
            train_speed += 1.0f;
        } else if (button == GLUT_RIGHT_BUTTON) {
            train_speed -= 1.0f;
            if (train_speed < 0.0f) train_speed = 0.0f;


        }
    }

    else if (currentVariable == 3) {
        // For display / display2
         if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        trainSpeed += 1.5f; // Increase speed
    }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        trainSpeed -= 1.5f; // Decrease speed
        if (trainSpeed < 0.5f) {
            trainSpeed = 0.5f; // Prevent stopping or reversing accidentally
        }
    }
    }
}




int main(int argc, char** argv) {
	// PlaySound("D:\\PRO\pro\\train.wav", NULL, SND_FILENAME | SND_SYNC); // test

	glutInit(&argc, argv);          // Initialize GLUT
	 // Create window with the given title
	 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	//glutInitWindowPosition(50, 50); // Position the window's initial top-left corner

	glutCreateWindow("PROJECT");
	loadImageAndStore("E:/SEM 8/COMPUTER GRAPHICS/PROJECT/Images/fifth.bmp");
		loadImageAndStore("E:/SEM 8/COMPUTER GRAPHICS/PROJECT/Images/main.bmp");

	 glutTimerFunc(0, updateBird, 0);


glutFullScreen();       // Register callback handler for window re-paint event
     glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 1900, 0, 1000);
	                  // Our own OpenGL initialization

	glMatrixMode(GL_MODELVIEW);  // Switch back for rendering
glLoadIdentity();
glutTimerFunc(16, update, 0);
glutTimerFunc(16, update1, 0);
glutTimerFunc(16, update2, 0);
glutTimerFunc(16, update3, 0);
glutTimerFunc(16, update4, 0);    //plane
glutTimerFunc(16, update5, 0);   //bus1
glutTimerFunc(16, update6, 0);    //car2
glutTimerFunc(16, update7, 0);    //bus2
glutTimerFunc(16, update8, 0);    //pickup
glutTimerFunc(16, update9, 0);    //car1
glutTimerFunc(500, toggleColor, 0); //signboard
    glutTimerFunc(16, updateBirda, 0);  // ~60 FPS



glutTimerFunc(0, updateBird, 0);
   glutTimerFunc(25, updateCloud, 0);
   glutTimerFunc(0, updateRain, 0);
    glutTimerFunc(0, updatep, 0);
   glutTimerFunc(0, updateClockTick, 0);
   glutTimerFunc(0, updatewave, 0);
   glutTimerFunc(0, updateboat2, 0);

    glutTimerFunc(0, updatecar, 0);
     glutTimerFunc(0, updatemicro, 0);
     glutTimerFunc(0, updateBridgeLight, 0);
     glutTimerFunc(0, updatecargo, 0);
     glutTimerFunc(0, updateCar777, 0);  // Start car animation
     glutTimerFunc(0, updateCar88, 0);




      glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 glutDisplayFunc(displayd);
 glutDisplayFunc(display2);
    glutDisplayFunc(display);

    glutDisplayFunc(adisplay2);

	glutDisplayFunc(adisplay1);

glutKeyboardFunc(handleKeypressa);
glutSpecialFunc(handleSpecialKey);

glutMouseFunc(unifiedMouseHandler);





init();
    // Register the display callback handler for window re-paint
    glutTimerFunc(20, updateTrain, 0);
    glutTimerFunc(20, updateboat, 0);
    glutTimerFunc(20, updateShip, 0);
    glutTimerFunc(20, updateCloud1, 0);
    glutTimerFunc(20, updateCloud2, 0);
    glutTimerFunc(20, updated, 0);
    glutTimerFunc(20, updateWaveD, 0);
    glutTimerFunc(1000, blinkLight, 0);
    glutIdleFunc(birdFrameUpdate);





   // glutTimerFunc(0, updateFlood, 0);

		loadImageAndStore("E:/SEM 8/COMPUTER GRAPHICS/PROJECT/Images/prantoday.bmp");

loadImageAndStore("E:/SEM 8/COMPUTER GRAPHICS/PROJECT/Images/prantorain.bmp");
    // register your display callback


//       glutKeyboardFunc(handleKeypress);






	glutMainLoop();                 // Enter the event-processing loop
	return 0;

}



