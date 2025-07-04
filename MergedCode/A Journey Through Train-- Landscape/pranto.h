#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include "glutil.h";
#define MAX_DROPS 1000


void bogi(float x,float y , float z);
void train_tier(float x,float y , float z);
void train_door(float x,float y,float z);
void windowline(float a , float b , float c);
void bridge_blinkinglight();
void bridge_blinkinglight2();
void cargo_design(float a , float b , float c);
void car1wheels(float x,float y , float z);
void Cloud3(float x, float y, float z);

bool LightOn = true;



float dropX[MAX_DROPS], dropY[MAX_DROPS];
int totalDrops = 0;




float cloudX = 0.0f;
float train_pos = 0.0f;
void display2();
float secondAngle = 0.0f;
float minuteAngle = 0.0f;
float hourAngle   = 0.0f;
float train_speed = 5.0f;


bool isBusMoving = true;
float busY = 0.0f;
float microPosition3= 0.0;
float microSpeed3 = -5;

float bridgeLightOn;

float carPosition3= 0.0;
float carSpeed3 = 30;

float wavePosition3= 250.0;
float waveSpeed3 = -5;




//Car_An1
float car2_move = 0.0f;
float car2_speed = 4.0f;


float cargoPosition3= 0.0;
float cargoSpeed3 = -4;


float boat2Position2 = 900.0f;
float boat2Speed2 = -5;

float car3_move = 0.0f;
float car3_speed = 6.0f;





//Train
//OB1
void Train()
{


    glPushMatrix();
    glTranslatef(train_pos, 0.0f, 0.0f);




    //Train_tier
   train_tier(0,0,0);
   train_tier(-100,0,0);
   train_tier(-200,0,0);
   train_tier(-300,0,0);
   train_tier(-400,0,0);
   train_tier(-500,0,0);



   //Train_Body

   glBegin(GL_QUADS);
   glColor3ub(215, 221, 194);
   glVertex2f(50, 540);
   glVertex2f(600, 540);
   glVertex2f(600, 590);
   glVertex2f(50, 590);
   glEnd();



   glBegin(GL_POLYGON);
   glColor3ub(215, 221, 194);
   glVertex2f(600, 590);
   glVertex2f(613, 590);
   glVertex2f(624, 589.5);
   glVertex2f(640.0210948756483, 589.0083972864444);
   glVertex2f(658.5801152029717, 588.576792162553);
   glVertex2f(673.0388868533283, 587.0661742289335);
   glVertex2f(684.9080277603375, 583.593714823081);
   glVertex2f(694.1286826798322, 579.2776635841681);
   glVertex2f(701.3238103212586, 575.2041253981939);
   glVertex2f(707.469204691016, 571.4302976952355);
   glVertex2f(713.7470974021613, 566.3295098674294);//r
   glVertex2f(718.4555169355203, 560.8363537451766);
   glVertex2f(721.1174538130114, 557.3465490273076);
   glVertex2f(722.5049629669018, 555.1456724383777);
   glVertex2f(723.4948290144855, 553.3687160404326);
   glVertex2f(723.7240957927945, 552.1880071945446);
   glVertex2f(723.6491044430956, 550.5568550135995);
   glVertex2f(723.2888336840056, 549.1016031504043);
   glVertex2f(722.3791998799861, 547.4958317339913);
   glVertex2f(720.8768789592982, 546.0226980027991);
   glVertex2f(718.7710216964994, 544.6904209589874);
   glVertex2f(716.2353976453743, 543.4870739516736);
   glVertex2f(713.3547291077148, 542.395043906185);
   glVertex2f(711.0723636975662, 541.7381937023827);
   glVertex2f(707.5732779782544, 540.9401566085044);
   glVertex2f(703.5455217465502, 540.4332024339519);
   glVertex2f(700.7295324466199, 540.0881033259554);
    glVertex2f(697.2003735459166, 539.8057706138992);
   glVertex2f(694.1286826798322, 539.6484658450587);
   glVertex2f(691.1533856724357, 539.519721729334);
   glVertex2f(687.2236441691808, 539.519721729334);
   glVertex2f(682.0135512789659, 539.3718537552201);
   glVertex2f(660.2801265620756, 539.3718537552201);
   glVertex2f(631.438930180753, 539.4701166203104);
   glVertex2f(600, 540);//f
   glVertex2f(600, 590);



  glEnd();


  //Windows
  glBegin(GL_QUADS);
   glColor3ub(58, 59, 53);
   glVertex2f(660, 560);
   glVertex2f(705, 560);
   glVertex2f(680, 580);
   glVertex2f(660, 580);


   glVertex2f(630, 560);
   glVertex2f(650, 560);
   glVertex2f(650, 580);
   glVertex2f(630, 580);

   //design_1
   glColor3ub(104, 212, 169);
   glVertex2f(50, 542);
   glVertex2f(660, 542);
   glVertex2f(705, 548);
   glVertex2f(50, 548);

   //design_2
   glColor3ub(104, 212, 169);
   glVertex2f(50, 550);
   glVertex2f(705, 550);
   glVertex2f(660, 556);
   glVertex2f(50, 556);

   glEnd();


   bogi(0,0,0);
    bogi(-105,0,0);
    bogi(-205,0,0);
    bogi(-310,0,0);
    bogi(-410,0,0);
    bogi(-515,0,0);


   train_door(10,0,0);
   train_door(-94,0,0);
   train_door(-194,0,0);
   train_door(-298,0,0);
   train_door(-398,0,0);


   glPopMatrix();

}




//Train_timer
//TM1
void updatep(int value) {
        train_pos += train_speed;


    if (train_pos > 1900)
        train_pos = -700;

    glutPostRedisplay();
    glutTimerFunc(16, updatep, 0);
}











//Train_Door
//OB2
void train_door(float x,float y , float z)
{
    glPushMatrix();
   glTranslatef(x,y,z);

   glBegin(GL_QUADS);

   glColor3ub(215, 221, 194);

   glVertex2f(576, 540);
   glVertex2f(590, 540);
   glVertex2f(590, 575);
   glVertex2f(576, 575);
   glEnd();


   glBegin(GL_LINES);
   glColor3ub(0,0,0);

    glVertex2f(576, 540);
   glVertex2f(576, 575);

   glVertex2f(576, 575);
   glVertex2f(590, 575);

   glVertex2f(590, 575);
   glVertex2f(590, 540);

   glEnd();
   //door_window
   glBegin(GL_QUADS);
    glColor3ub(64, 114, 89);
    glVertex2f(578, 560);
    glVertex2f(588, 560);
    glVertex2f(588, 572);
    glVertex2f(578, 572);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(58, 59, 53);
    glVertex2f(510, 560);
    glVertex2f(570, 560);
    glVertex2f(570, 580);
    glVertex2f(510, 580);

     glEnd();
   glPopMatrix();
}

//bogi
//OB3
void bogi(float x,float y , float z)
{

   glPushMatrix();
   glTranslatef(x,y,z);
   glBegin(GL_QUADS);
   glColor3ub(99, 101, 100);
   glVertex2f(605, 540);
   glVertex2f(610, 540);
   glVertex2f(610, 590);
   glVertex2f(605, 590);

   glEnd();
   glPopMatrix();



}



//traintier
//OB4
void train_tier(float x,float y , float z)
{
    //Train_Tier

    glPushMatrix();
   glTranslatef(x,y,z);

   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.13;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+627.3872299289397,y+ 540.118203258706);
        }



        for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.13;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+650,y+  540);
        }
glEnd();
 glBegin(GL_POLYGON);
         for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.13;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+673,y+540);
        }



        glEnd();


        glPopMatrix();




}

//OB5
void pilar_Shadow()
{
   glBegin(GL_QUADS);
   glColor3ub(54, 138, 161);

   glVertex2f(560, 100);
   glVertex2f(600, 100);
   glVertex2f(540, 290);
   glVertex2f(500, 290);



   glVertex2f(900, 100);
   glVertex2f(940, 100);
   glVertex2f(860, 290);
   glVertex2f(820, 290);


   glEnd();





}





//OB6
void Land() {
    glColor3ub(93, 199, 101);
    glBegin(GL_POLYGON);
        glVertex2f(0,50);
        glVertex2f(99.5,136.2);
        glVertex2f(140.3,181.5);
        glVertex2f(200,200);
        glVertex2f(255,195.9);
        glVertex2f(290.6,263.8);
        glVertex2f(350.4,327.7);
        glVertex2f(350,350);
        glVertex2f(378.4,359);
        glVertex2f(396.03,385.5);
        glVertex2f(427.1,398.5);
        glVertex2f(0,400);
        glVertex2f(0,50);

        glColor3ub(206, 171, 85);
        glVertex2f(0,83);
        glVertex2f(72.5,155.8);
        glVertex2f(150,200);
        glVertex2f(210,170);
        glVertex2f(280,250);
        glVertex2f(300,300);
        glVertex2f(300,350);
        glVertex2f(360,360);
         glVertex2f(380,380);

    glEnd();
}

//OB7
void river()
{
    glColor3ub(67, 172, 217);
    glBegin(GL_QUADS);
    glVertex2f(820,600);
    glVertex2f(820,0);
    glVertex2f(1900,0);
    glVertex2f(1900,600);

    glVertex2f(820,600);
    glVertex2f(820,530);
    glVertex2f(760,560);
    glVertex2f(740,620);

    glVertex2f(820, 300);
    glVertex2f(820, 430);
    glVertex2f(600, 360);
    glVertex2f(620, 280);


    glVertex2f(800, 0);
    glVertex2f(820, 0);
    glVertex2f(820, 280);
    glVertex2f(800, 280);


    glVertex2f(600, 0);
    glVertex2f(800, 0);
    glVertex2f(800, 300);
    glVertex2f(600, 280);


    glVertex2f(150,0);
    glVertex2f(600, 0);
    glVertex2f(800, 360);
    glVertex2f(450, 350);


    glVertex2f(800, 280);
    glVertex2f(820, 280);
    glVertex2f(820, 290);
    glVertex2f(800, 290);

    glEnd();

}

//OB8
void Cloud1(float x,float y , float z)
{
    glPushMatrix();
   glTranslatef(x,y,z);

   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(255, 255, 255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=15;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+730,y+960);
        }

        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255, 255, 255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=21.91;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+700,y+960);
        }

        glEnd();



          glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255, 255, 255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=17.69;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+682,y+980);
        }
        glEnd();

  glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255, 255, 255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=21.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+660,y+960);
        }

         glEnd();



         glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);

        for(int i=0;i<200;i++)
        {
            glColor3ub(255, 255, 255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=13.86;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+640,y+980);
        }



         glEnd();

         glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);

        for(int i=0;i<200;i++)
        {
            glColor3ub(255, 255, 255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=21.66;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+620,y+960);
        }


        glEnd();



        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        for(int i=0;i<200;i++)
        {
            glColor3ub(255, 255, 255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=16.95;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+590,y+960);
        }






   glEnd();

    glPopMatrix();




}

//cloud_An2
//OB9
void Cloud2(float x,float y , float z)
{

    glPushMatrix();
   glTranslatef(x,y,z);

   glColor3ub( 213, 229, 243);
   glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=19.54;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+780,y+920);
        }



        for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=21.87;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+760.13,y+932.23);
        }



        for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=20.46;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+760,y+920);
        }


        for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=20;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+740,y+920);
        }

        for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=15;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+715,y+920);
        }


        for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=12.71;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+802,y+920);
        }


     glEnd();

    glPopMatrix();

}



//cloud_An3
//OB10
void Cloud3(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.8f, 0.8f, 1.0f); // Smaller cloud
    Cloud2(0, 0, 0); // Reuse existing cloud shape
    glPopMatrix();
}



////cloudanime
//TM2
void updateCloud(int value) {
    cloudX += 1.0f;
    if (cloudX > 1900)
        cloudX = -1900;

    glutPostRedisplay();
    glutTimerFunc(25, updateCloud, 0);
}





//OB11
void Tress(float x, float y, float z)
{




    glPushMatrix();
    glTranslatef(x,y,z);
    glColor3ub(58, 176, 89);
    glBegin(GL_TRIANGLES);

    glVertex2f(280,380);
    glVertex2f(300,460);
    glVertex2f(320,380);

    glVertex2f(315,400);
    glVertex2f(326,462);
    glVertex2f(340,400);

    glVertex2f(340,380);
    glVertex2f(360,460);
    glVertex2f(380,380);

    glVertex2f(380,400);
    glVertex2f(400,460);
    glVertex2f(420,400);

    glVertex2f(368,440);
    glVertex2f(380,480);
    glVertex2f(392,440);

    glEnd();

    glPopMatrix();

}
//OB12
void tree2(float a, float b, float c,float sx, float sy, float sz)
{
   glPushMatrix();
   glTranslatef(a,b,c);
   glScalef(sx, sy, sz);

   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(58, 176, 89);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=35;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+45.02,y+640.33);
        }


   glEnd();

   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(58, 176, 89);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=35;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+98.65498528917,y+640.5215088246986);
        }


   glEnd();



   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(58, 176, 89);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=35;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+70.7470193767515,y+689.3604491714192);
        }


   glEnd();



   glBegin(GL_QUADS);
   glColor3ub(41, 159, 76);

   glVertex2f(66, 620);
   glVertex2f(70, 620);
   glVertex2f(70, 704);
   glVertex2f(66, 694);




   glVertex2f(70, 632);
   glVertex2f(96, 658);
   glVertex2f(88, 653);
   glVertex2f(70, 635);




    glVertex2f(66, 644);
   glVertex2f(44, 666);
   glVertex2f(48, 658);
   glVertex2f(66, 640);






   glEnd();










    glPopMatrix();


}

//OB13
void tree3(float p,float r,float t)
{
    glColor3ub(7, 56, 87);
    glPushMatrix();
    glTranslatef(p,r,t);
    glBegin(GL_TRIANGLES);
    glVertex2f(700,650);
    glVertex2f(715,677);
    glVertex2f(726,650);


    glVertex2f(725,655);
    glVertex2f(735,690);
    glVertex2f(745,655);


    glVertex2f(745,650);
    glVertex2f(755,685);
    glVertex2f(765,650);




    glEnd();

    glPopMatrix();
}

//OB14
void tree3detailing(float p,float r,float t)
{

    glColor3ub(61, 67, 60);
    glPushMatrix();
    glTranslatef(p,r,t);
    glBegin(GL_QUADS);

    glVertex2f(715, 645);
    glVertex2f(715, 643);
    glVertex2f(765, 643);
    glVertex2f(765, 645);



     glEnd();

    glPopMatrix();


}

//OB15
void Mountain()
{



   glColor3ub(93, 199, 101);
   glBegin(GL_POLYGON);

   glVertex2f(0,700);
   glVertex2f(31.4,746.8);
   glVertex2f(46.3,778.8);
   glVertex2f(77.5,843.2);
   glVertex2f(103.9,874.1);
   glVertex2f(137.3,900.9);
   glVertex2f(170.5,923.3);
   glVertex2f(199.7,941.7);
   glVertex2f(231.6,947.8);
   glVertex2f(256.8,949.1);
   glVertex2f(305.6,943);
   glVertex2f(354.5,924.7);
   glVertex2f(378.2,877.1);
   //I7
   glVertex2f(400,837.2);
   glVertex2f(437.3,769);
   glVertex2f(469.6,673.9);
   glVertex2f(494.2,638.5);
   glVertex2f(509.3,598.9);
   glVertex2f(533.4,563.00);
   glVertex2f(559.9,530.4);
   glVertex2f(600,480);
   glVertex2f(614.2,462.2);
   glVertex2f(650.8,400);
   glVertex2f(0,400);



  // 2nd mountain
  glColor3ub(81, 172, 56);
glVertex2f(650.8,400);
glVertex2f(614.2,462.2);
glVertex2f(600,480);
glVertex2f(559.9,530.4);
glVertex2f(533.4,563.00);
glVertex2f(509.3,598.9);
glVertex2f(494.2,638.5);
glVertex2f(469.6,673.9);
glVertex2f(437.3,769);
glVertex2f(400,837.2);
glVertex2f(440,882.4);
glVertex2f(483.6,893.9);
glVertex2f(527.2,880.04);
glVertex2f(576.9,846.9);
glVertex2f(600,800);
glVertex2f(614.3,768.1);
glVertex2f(638.7,724.5);
glVertex2f(653.3,694.2);
//v7
glVertex2f(668.6,662.7);
glVertex2f(714.9,609.1);
glVertex2f(740.1,529.8);
glVertex2f(805.4,442.4);
glVertex2f(790.8,437.6);
glVertex2f(762.9,429.7);
glVertex2f(722.7,427.8);
glVertex2f(680,420);
glVertex2f(643.2,414);
glVertex2f(614.2,462.2);
glVertex2f(600,480);
glVertex2f(559.9,530.4);
glVertex2f(533.4,563.00);
glVertex2f(509.3,598.9);
glVertex2f(494.2,638.5);
glVertex2f(469.6,673.9);
glVertex2f(437.3,769);
glVertex2f(400,837.2);







     glEnd();



}



//OB16
void backgroundmountain()
{

glColor3ub(67, 128, 153);
glBegin(GL_TRIANGLES);
glVertex2f(300,750);
glVertex2f(400,950);
glVertex2f(500,750);


glVertex2f(80,800);
glVertex2f(150,950);
glVertex2f(250,800);



glVertex2f(20,700);
glVertex2f(110,970);
glVertex2f(250,700);




glColor3ub(70, 116, 135);
//////
glVertex2f(900,650);
glVertex2f(1040,770);
glVertex2f(1180,650);



glVertex2f(1250,650);
glVertex2f(1400,750);
glVertex2f(1550,650);


glVertex2f(1180,650);
glVertex2f(1180,650);
glVertex2f(1180,650);



glVertex2f(600,650);
glVertex2f(700,750);
glVertex2f(800,650);


glVertex2f(650,650);
glVertex2f(750,750);
glVertex2f(850,650);


glVertex2f(1600,650);
glVertex2f(1697,697);
glVertex2f(1770,650);


glEnd();
//round mountain

glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(70, 116, 135);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=15.044;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1740,y+667);
        }


    for(int i=0;i<200;i++)
        {
            glColor3ub(70, 116, 135);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=22.74;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1660,y+675);
        }



    for(int i=0;i<200;i++)
        {
            glColor3ub(70, 116, 135);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=44;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1470.14,y+695.67);
        }




    for(int i=0;i<200;i++)
        {
            glColor3ub(70, 116, 135);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=46;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1330,y+700);
        }





    for(int i=0;i<200;i++)
        {
            glColor3ub(70, 116, 135);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=51.68;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1112.07,y+704.65);
        }






    for(int i=0;i<200;i++)
        {
            glColor3ub(70, 116, 135);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=50.14;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+977.37,y+709.95);
        }






glEnd();





//////









glColor3ub(67, 128, 153);
glBegin(GL_TRIANGLES);
glColor3ub(67, 128, 153);
glVertex2f(682.189,646.974);
glVertex2f(860,820);
glVertex2f(1050,650);


glVertex2f(1050,650);
glVertex2f(1210,800);
glVertex2f(1400,650);


glVertex2f(1400,650);
glVertex2f(1550,760);
glVertex2f(1700,650);


glVertex2f(1700,650);
glVertex2f(1800,700);
glVertex2f(1900,650);



///////



glEnd();

}
//OB17
void sky()
{

    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(1900,650);
    glVertex2f(1900,1000);
    glVertex2f(0, 1000);
    glVertex2f(0, 650);
    glEnd();

    ApplyTexture(0, 650,1900,650,1900,1000,0,1000,textures[2].textureID);
    //ApplyTexture(0, 650,1900,650,1900,1000,0,1000,textures[1].textureID);



}
//OB18
void sky2()
{

    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(1900,650);
    glVertex2f(1900,1000);
    glVertex2f(0, 1000);
    glVertex2f(0, 650);
    glEnd();

   // ApplyTexture(0, 650,1900,650,1900,1000,0,1000,textures[0].textureID);
        ApplyTexture(0, 650,1900,650,1900,1000,0,1000,textures[3].textureID);



}
//OB19
void sun()
{
      //glLineWidth(10);

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(232, 232, 71);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=25;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1400,y+900);
        }





        glEnd();



      //  glLineWidth(10);
       /* glBegin(GL_LINES);

        glColor3ub(232, 232, 71);
        glVertex2f(0, 500);
        glVertex2f(1400.09,944.29);

        glEnd();*/



}


//Right-side-Land
//OB20
void Land2()
{
    glBegin(GL_POLYGON);
    glColor3ub(103, 201, 93);

    glVertex2f(1143.90,0);
    glVertex2f(1152.7237927948174, 27.0344574388035);
    glVertex2f(1208.474897889481, 60.1723777565807);
    glVertex2f(1289.2284229293941, 117.4813310107123);
    glVertex2f(1400, 200);
    glVertex2f(1508.0444262633519, 211.2596181538367);
    glVertex2f(1600, 200);
    glVertex2f(1685.1811908670318, 255.5438093047565);
    glVertex2f(1697.4814499427823, 286.3387025047113);
    glVertex2f(1719.106888060049, 303.4758421448046);
    glVertex2f(1747.2607603259241, 349.9909354536293);
    glVertex2f(1758.6855200859895, 387.1214046738315);
    glVertex2f(1840, 420);
    glVertex2f(1860, 420);
    glVertex2f(1873.6455573721416, 428.2477037326754);
    glVertex2f(1900,446.55555);
    glVertex2f(1900,0);
    glVertex2f(1143.90,0);





    glEnd();
}
//OB21
void Bridge()
{




    glBegin(GL_QUADS);

    //Bridge_Road
    glColor3ub(87, 111, 126);
    glVertex2f(1900,500);
    glVertex2f(1900,530);
    glVertex2f(0,530);
    glVertex2f(0,500);


    //Bridge_pillers
    //1
    glColor3ub(87, 111, 126);
    glVertex2f(1780,500);
    glVertex2f(1820,500);
    glVertex2f(1820,300);
    glVertex2f(1780,300);

    //3
    glVertex2f(1460,500);
    glVertex2f(1500,500);
    glVertex2f(1500,300);
    glVertex2f(1460,300);
    /*
    //4
    glVertex2f(1300,500);
    glVertex2f(1340,500);
    glVertex2f(1340,300);
    glVertex2f(1300,300);*/
    //5
    glVertex2f(1140,500);
    glVertex2f(1180,500);
    glVertex2f(1180,300);
    glVertex2f(1140,300);
    /*
    //6
    glVertex2f(980,500);
    glVertex2f(1020,500);
    glVertex2f(1020,300);
    glVertex2f(980,300);*/
    //7
    glVertex2f(820,500);
    glVertex2f(860,500);
    glVertex2f(860,300);
    glVertex2f(820,300);
    /*
    //8
    glVertex2f(660,500);
    glVertex2f(700,500);
    glVertex2f(700,300);
    glVertex2f(660,300);*/
    //9
    glVertex2f(500,500);
    glVertex2f(540,500);
    glVertex2f(540,300);
    glVertex2f(500,300);
    /*
    //10
    glVertex2f(340,500);
    glVertex2f(380,500);
    glVertex2f(380,300);
    glVertex2f(340,300);*/
    //11
    glVertex2f(180,500);
    glVertex2f(220,500);
    glVertex2f(220,300);
    glVertex2f(180,300);

    //12
    /*glVertex2f(0,500);
    glVertex2f(20,500);
    glVertex2f(20,300);
    glVertex2f(0,300);*/

    //pillar_1_design
    glVertex2f(1760, 300);
    glVertex2f(1760, 280);
    glVertex2f(1840,280);
    glVertex2f(1840, 300);

    glVertex2f(1820,460);
    glVertex2f(1860,500);
    glVertex2f(1880,500);
    glVertex2f(1820,440);

    glVertex2f(1740,500);
    glVertex2f(1780,460);
    glVertex2f(1780,440);
    glVertex2f(1720,500);

     //pillar_2_design
    glVertex2f(1440,300);
    glVertex2f(1520,300);
    glVertex2f(1520,290);
    glVertex2f(1440,290);

    glVertex2f(1500,460);
    glVertex2f(1540,500);
    glVertex2f(1560,500);
    glVertex2f(1500,440);

    glVertex2f(1420,500);
    glVertex2f(1460,460);
    glVertex2f(1460,440);
    glVertex2f(1400,500);

    //pillar_3_design
    glVertex2f(1120,300);
    glVertex2f(1200,300);
    glVertex2f(1200,290);
    glVertex2f(1120,290);

    glVertex2f(1180,460);
    glVertex2f(1220,500);
    glVertex2f(1240,500);
    glVertex2f(1180,440);

    glVertex2f(1100,500);
    glVertex2f(1140,460);
    glVertex2f(1140,440);
    glVertex2f(1080,500);

    //pillar_4_design
    glVertex2f(800,300);
    glVertex2f(880,300);
    glVertex2f(880,290);
    glVertex2f(800,290);

    glVertex2f(860,460);
    glVertex2f(900,500);
    glVertex2f(920,500);
    glVertex2f(860,440);

    glVertex2f(780,500);
    glVertex2f(820,460);
    glVertex2f(820,440);
    glVertex2f(760,500);

    //pillar_5_design
    glVertex2f(480,300);
    glVertex2f(560,300);
    glVertex2f(560,290);
    glVertex2f(480,290);

    glVertex2f(540,460);
    glVertex2f(580,500);
    glVertex2f(600,500);
    glVertex2f(540,440);

    glVertex2f(460,500);
    glVertex2f(500,460);
    glVertex2f(500,440);
    glVertex2f(440,500);


    //piller_6
    glVertex2f(160, 300);
    glVertex2f(160, 280);
    glVertex2f(240, 280);
    glVertex2f(240, 300);



    glVertex2f(180, 440);
    glVertex2f(120, 500);
    glVertex2f(140, 500);
    glVertex2f(180, 460);



    glVertex2f(220, 440);
    glVertex2f(280, 500);
    glVertex2f(260, 500);
    glVertex2f(220, 460);






    //design

    glColor3ub(169, 66, 40);
    glVertex2f(1900,520);
    glVertex2f(1900,530);
    glVertex2f(0,530);
    glVertex2f(0,520);



    glColor3ub(114, 44, 26);
    glVertex2f(0,520);
    glVertex2f(1900,520);
    glVertex2f(1900,524);
    glVertex2f(0,524);


    glEnd();





}





//bridge_struc
//OB22
void bridge_structure(float a, float b, float c)
{


    glPushMatrix();
    glTranslatef(a,b,c);



    glBegin(GL_QUADS);
    glColor3ub(169, 66, 40);
    glVertex2f(120, 530);
    glVertex2f(140,530);
    glVertex2f(240, 620);
    glVertex2f(240, 640);



    glColor3ub(169, 66, 40);
    glVertex2f(600, 530);
    glVertex2f(580,530);
    glVertex2f(480, 620);
    glVertex2f(480, 640);




    glVertex2f(240, 625);
    glVertex2f(480, 625);
    glVertex2f(480, 640);
    glVertex2f(240, 640);



    glVertex2f(380, 530);
    glVertex2f(486, 624);
    glVertex2f(475, 630);
    glVertex2f(360,530);




    glVertex2f(230, 620);
    glVertex2f(240, 630);
    glVertex2f(360, 530);
    glVertex2f(340,530);



    glVertex2f(354, 530);
    glVertex2f(366, 530);
    glVertex2f(366, 640);
    glVertex2f(354,640);



      glVertex2f(235, 530);
    glVertex2f(245, 530);
    glVertex2f(245, 635);
    glVertex2f(235, 635);





    glVertex2f(475, 530);
    glVertex2f(488, 530);
    glVertex2f(488, 635);
    glVertex2f(475, 635);



    glEnd();



    bridge_blinkinglight();
    bridge_blinkinglight2();

    glPopMatrix();







}











//TM3
void updateBridgeLight(int value) {
    bridgeLightOn = !bridgeLightOn;  // Toggle the light
    glutPostRedisplay();
    glutTimerFunc(100, updateBridgeLight, 0); // Blink every 500ms
}


//bridge_lights
//OB23
void bridge_blinkinglight()
{

  glBegin(GL_QUADS);

  glColor3ub(99, 99, 89);

  glVertex2f(240, 640);
  glVertex2f(255,640);
  glVertex2f(255, 645);
  glVertex2f(240, 645);




   if (train_speed == 0) {
        glColor3ub(0, 255, 0);
    } else if (bridgeLightOn) {
        glColor3ub(237, 42, 14);
    } else {
        glColor3ub(72, 68, 67);
    }



  glVertex2f(242, 645);
  glVertex2f(253, 645);
  glVertex2f(253, 654);
  glVertex2f(242, 654);
  glEnd();


}



//OB24
void bridge_blinkinglight2()
{

  glBegin(GL_QUADS);

  glColor3ub(99, 99, 89);

  glVertex2f(480, 640);
  glVertex2f(480, 645);
  glVertex2f(465, 645);
  glVertex2f(465, 640);




   if (train_speed == 0) {
        glColor3ub(0, 255, 0);
    } else if (bridgeLightOn) {
        glColor3ub(237, 42, 14);
    } else {
        glColor3ub(72, 68, 67);
    }



  glVertex2f(467, 645);
  glVertex2f(478, 645);
  glVertex2f(478, 654);
  glVertex2f(467, 654);
  glEnd();


}






//Highway road
//OB25
void roadp(){

glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(111,111,111);

	glVertex2f(0,180);

    glVertex2f(0,0);

    glVertex2f(1900,0);

	glVertex2f(1900,180);

	glColor3ub(255,255,255);

	glVertex2f(0,92);

    glVertex2f(0,88);

    glVertex2f(1900,88);

	glVertex2f(1900,92);




	glColor3ub(11, 11, 11 );

	glVertex2f(0,188);
	glVertex2f(1900,188);
	glVertex2f(1900,200);
	glVertex2f(0,200);


	glEnd();


}

//OB26
void road_piller(float a, float b, float c)
{

    glPushMatrix();
    glTranslatef(a,b,c);

    glColor3ub(232, 229, 44);
    glBegin(GL_QUADS);
    glVertex2f(4, 188);
    glVertex2f(16, 188);
    glVertex2f(28, 200);
    glVertex2f(16, 200);




    glEnd();

    glPopMatrix();






}

//OB27
void road_piller2(float a, float b, float c)
{

    glPushMatrix();
    glTranslatef(a,b,c);

    //95, 95, 88


    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(8, 180);
    glVertex2f(16, 180);
    glVertex2f(16, 188);
    glVertex2f(8, 188);




    glEnd();

    glPopMatrix();






}






//OB28
void Clock_Tower()
{
    glBegin(GL_QUADS);
    glColor3ub(195, 89, 38);

    glVertex2f(1550,180);
    glVertex2f(1660,180);
    glVertex2f(1660, 700);
    glVertex2f(1550, 700);



     glVertex2f(1540, 700);
     glVertex2f(1675, 700);
     glVertex2f(1675, 710);
     glVertex2f(1540, 710);


     glVertex2f(1530, 710);
     glVertex2f(1685, 710);
     glVertex2f(1685, 720);
     glVertex2f(1530, 720);





     //design
     glColor3ub(100, 45, 18);
     glVertex2f(1550,698);
     glVertex2f(1660,698);
     glVertex2f(1660, 700);
     glVertex2f(1550, 700);


     glVertex2f(1540, 708);
     glVertex2f(1670, 708);
     glVertex2f(1670, 710);
     glVertex2f(1540, 710);


     //detail_design
     glColor3ub(106, 64, 41);
     glVertex2f(1660, 180);
     glVertex2f(1670, 190);
     glVertex2f(1670, 700);
     glVertex2f(1660, 700);



    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3ub(59, 75, 87);

    glVertex2f(1535, 720);
    glVertex2f(1675, 720);
    glVertex2f(1602, 824);


    glColor3ub(96, 111, 119);
    glVertex2f(1535, 720);
    glVertex2f(1660, 720);
    glVertex2f(1602, 824);
    glEnd();

    //clock

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(255,255,255);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=35.617;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1605,y+640);
        }

        glEnd();



        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=3.605;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1605,y+640);
        }


        glEnd();


        glBegin(GL_LINES);

        glColor3ub(0,0,0);

        glVertex2f(1604, 674);
        glVertex2f(1604, 669);


        glVertex2f(1638, 640);
        glVertex2f(1632, 640);


        glVertex2f(1604, 606);
        glVertex2f(1604, 612);


        glVertex2f(1574, 640);
        glVertex2f(1582, 640);


        //1
          glVertex2f(1622, 666);
        glVertex2f(1617, 661);

        //2
          glVertex2f(1631, 655);
        glVertex2f(1624.5, 651.5);

        //4
          glVertex2f(1634.5, 625.5);
        glVertex2f(1628, 628.5);


        //5
         glVertex2f(1623, 612);
        glVertex2f(1617, 617);


        //7
        glVertex2f(1590, 610);
        glVertex2f(1595, 615);



        //8
        glVertex2f(1578, 622);
        glVertex2f(1584, 626);



        //10
        glVertex2f(1575.5, 654);
        glVertex2f(1584, 651);


        //11
        glVertex2f(1586, 668);
        glVertex2f(1592, 662);












    glEnd();
}

//OB29
void clk_tower_Detail(float a, float b, float c)
{

    glPushMatrix();
    glTranslatef(a,b,c);


    glBegin(GL_QUADS);

     //detailing_underclock
     glColor3ub(171, 96, 28);
      glVertex2f(1540, 570);
     glVertex2f(1680, 570);
     glVertex2f(1680, 580);
     glVertex2f(1540, 580);


     //1
     glVertex2f(1560, 470);
     glVertex2f(1570, 470);
     glVertex2f(1570, 568);
     glVertex2f(1560, 568);


     //2
     glVertex2f(1580, 470);
     glVertex2f(1590, 470);
     glVertex2f(1590, 568);
     glVertex2f(1580, 568);


      //3
     glVertex2f(1600, 470);
     glVertex2f(1610, 470);
     glVertex2f(1610, 568);
     glVertex2f(1600, 568);


     //4
     glVertex2f(1620, 470);
     glVertex2f(1630, 470);
     glVertex2f(1630, 568);
     glVertex2f(1620, 568);



     //5
     glVertex2f(1640, 470);
     glVertex2f(1650, 470);
     glVertex2f(1650, 568);
     glVertex2f(1640, 568);







     glColor3ub(106, 64, 41);
      glVertex2f(1550, 568);
     glVertex2f(1660, 568);
     glVertex2f(1660, 570);
     glVertex2f(1550, 570);



     //1
     glVertex2f(1558, 470);
     glVertex2f(1560, 470);
     glVertex2f(1560, 568);
     glVertex2f(1558, 568);


     //2
     glVertex2f(1578, 470);
     glVertex2f(1580, 470);
     glVertex2f(1580, 568);
     glVertex2f(1578, 568);



     //3
     glVertex2f(1598, 470);
     glVertex2f(1600, 470);
     glVertex2f(1600, 568);
     glVertex2f(1598, 568);


     //4
     glVertex2f(1618, 470);
     glVertex2f(1620, 470);
     glVertex2f(1620, 568);
     glVertex2f(1618, 568);


      //5
     glVertex2f(1637, 470);
     glVertex2f(1640, 470);
     glVertex2f(1640, 568);
     glVertex2f(1637, 568);


    glEnd();
    glPopMatrix();


}



//OB30
void Left_tree(float x, float y, float z)
{


    glPushMatrix();
    glTranslatef(x,y,z);

     glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(83, 148, 40);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=51.264;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1700,y+ 250);
        }

        glEnd();





         glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(
83, 148, 40);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=49.75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1751,y+250);
        }

        glEnd();






         glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(
83, 148, 40);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=50.999;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1800,y+240);
        }

        glEnd();




         glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            glColor3ub(
83, 148, 40);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=53.203;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1750.0067018,y+299.735);
        }

        glEnd();



        glBegin(GL_QUADS);
        glColor3ub(43, 83, 16);
        glVertex2f(1745, 180);
        glVertex2f(1750, 180);
        glVertex2f(1750, 335);

        glVertex2f(1745, 330);




        glVertex2f(1750, 225);
        glVertex2f(1800, 275);
        glVertex2f(1800, 280);

        glVertex2f(1750, 230);




        glVertex2f(1745, 225);
        glVertex2f(1745, 230);
        glVertex2f(1690, 285);
        glVertex2f(1688, 282);



        glVertex2f(1745, 270);
        glVertex2f(1745, 275);
        glVertex2f(1705, 315);
        glVertex2f(1705, 310);



        glVertex2f(1750, 250);
        glVertex2f(1750, 255);
        glVertex2f(1785, 290);
        glVertex2f(1785, 285);



        glVertex2f(1750, 305);
        glVertex2f(1750, 310);
        glVertex2f(1770, 330);
        glVertex2f(1770, 325);









      glEnd();




    glPopMatrix();




}

//0B31
void left_tree2(float a, float b, float c) {
    glPushMatrix();
    glTranslatef(a, b, c);

    const float pi = 3.1416f;

    // === Left Leaf Cluster 1 ===
    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = 21.346;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1280, y + 280);
    }
    glEnd();

    // === Middle Leaf Cluster 2 ===
    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = 21.346;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1310, y + 280);
    }
    glEnd();


    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = 21.346;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1340, y + 280);
    }
    glEnd();



    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = 21.346;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1370, y + 280);
    }
    glEnd();




    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = 21.5;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1309.1705724952164, y + 94.1404763441744);
    }
    glEnd();




    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * pi) / 200;
        float r = 21.5;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1340.272465162276, y +294.2203932665632);
    }
    glEnd();



    glPopMatrix();
}





//OB32
void Draw_Clock_Hands() {
    glPushMatrix();
    glTranslatef(1605, 640, 0);  // Clock center

    // === Second Hand (Thinner Red) ===
    glPushMatrix();
    glRotatef(-secondAngle, 0, 0, 1); // rotate clockwise
    glColor3ub(0, 0, 0);  // Red
    glBegin(GL_QUADS);
    glVertex2f(-0.8, 0);
    glVertex2f(0.8, 0);
    glVertex2f(0.8, 32);   // Slightly shorter
    glVertex2f(-0.8, 32);
    glEnd();
    glPopMatrix();

    // === Minute Hand (Medium Black) ===
    glPushMatrix();
    glRotatef(-minuteAngle, 0, 0, 1);
    glColor3ub(0, 0, 0);  // Black
    glBegin(GL_QUADS);
    glVertex2f(-1.5, 0);
    glVertex2f(1.5, 0);
    glVertex2f(1.5, 25);  // Shorter
    glVertex2f(-1.5, 25);
    glEnd();
    glPopMatrix();

    // === Hour Hand (Short Blue) ===
    glPushMatrix();
    glRotatef(-hourAngle, 0, 0, 1);
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-1.2, 0);
    glVertex2f(1.2, 0);
    glVertex2f(1.2, 18);
    glVertex2f(-1.2, 18);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}


//TM4
void updateClockTick(int value) {
    secondAngle += 50.0f;   // 360/60
    if (secondAngle >= 360.0f) {
        secondAngle -= 360.0f;
        minuteAngle += 6.0f;

        if (minuteAngle >= 360.0f) {
            minuteAngle -= 360.0f;
            hourAngle += 30.0f; // 360/12
            if (hourAngle >= 360.0f) hourAngle -= 360.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(1000, updateClockTick, 0); // update every 1 sec
}


//-----------------------------------------------------------------------------------------------





//OB33
void wave7(){
glPushMatrix();
    glTranslatef(1200, wavePosition3 , 0.0f); // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 150;
        float x = r * cos(A);
        float y = 5* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(700.0f, wavePosition3 , 0.0f); // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 100;
        float x = r * cos(A);
        float y = 4* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(900.0f, wavePosition3 , 0.0f); // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 50;
        float x = r * cos(A);
        float y = 2* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(0, wavePosition3 , 0.0f); // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 50;
        float x = r * cos(A);
        float y = 2* sin(A);
        glVertex2f(x+988.2592696557696, y+300);
    }
    glEnd();
    glPopMatrix();




     glPushMatrix();
    glTranslatef(0, wavePosition3 , 0.0f); // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 50;
        float x = r * cos(A);
        float y = 2* sin(A);
        glVertex2f(x+900, y+200);
    }
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0, wavePosition3 , 0.0f); // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 100;
        float x = r * cos(A);
        float y = 2* sin(A);
        glVertex2f(x+1200, y+300);
    }
    glEnd();
    glPopMatrix();






}
//TM5
 void updatewave(int value) {
    wavePosition3 += waveSpeed3;
    if (wavePosition3<-80.0) {
        wavePosition3 = 250.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatewave, 0); // Match the  boat's speed
}





//------------------------------------------------------------------------------------------------------------------


//34
void boat27() {
    glPushMatrix();
   glTranslatef(boat2Position2, 490, 0.0f); // Apply translation for the second boat

   glColor3f(0.0f, 0.0f, 0.0f); // Blue color for the boat body

    /////body
    glBegin(GL_QUADS);

    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(700,50);
    glVertex2f(950,50);
    glVertex2f(947,55);
    glVertex2f(710,55);
    glEnd();

     glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(710,55);
    glVertex2f(947,55);
    glVertex2f(960,75);
    glVertex2f(690,75);
    glEnd();
   // container

    glBegin(GL_QUADS);

    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(720,75);
    glVertex2f(760,75);
    glVertex2f(760,95);
    glVertex2f(720,95);
    glEnd();



    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.4f, 0.8f);
    glVertex2f(760,75);
    glVertex2f(800,75);
    glVertex2f(800,95);
    glVertex2f(760,95);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.6f, 0.2f);
    glVertex2f(800,75);
    glVertex2f(840,75);
    glVertex2f(840,95);
    glVertex2f(800,95);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(840,75);
    glVertex2f(880,75);
    glVertex2f(880,95);
    glVertex2f(840,95);
    glEnd();


     glBegin(GL_QUADS);

    glColor3f(0.0f, 0.4f, 0.8f);
    glVertex2f(735,95);
    glVertex2f(775,95);
    glVertex2f(775,115);
    glVertex2f(735,115);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.6f, 0.2f);
    glVertex2f(780,95);
    glVertex2f(820,95);
    glVertex2f(820,115);
    glVertex2f(780,115);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(825,95);
    glVertex2f(865,95);
    glVertex2f(865,115);
    glVertex2f(825,115);
    glEnd();

   //body

    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(710,75);
    glVertex2f(710,135);
     glEnd();

     glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(704 ,125);
    glVertex2f(715,125);
     glEnd();

      glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(700,115);
    glVertex2f(720,115);
     glEnd();

   glBegin(GL_QUADS);

  glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(690,75);
    glVertex2f(760,75);
    glVertex2f(755,85);
    glVertex2f(685,85);
    glEnd();


    glLineWidth(2);
    for (int i = 686; i <= 756; i+=10) {
    glBegin(GL_LINES);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(i,85);
    glVertex2f(i,90);

    glEnd();
    }
    glBegin(GL_LINES);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(685,90);
    glVertex2f(755,90);

    glEnd();


    glBegin(GL_QUADS);

  glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(890,75);
    glVertex2f(950,75);
    glVertex2f(945,130);
    glVertex2f(895,130);
    glEnd();

     for (int i = 900; i <=935; i+=5) {
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(i,115);
    glVertex2f(i+4,115);
    glVertex2f(i+4,120);
    glVertex2f(i,120);
    glEnd();
    }

    for (int i = 900; i <=935; i+=5) {
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(i,105);
    glVertex2f(i+4,105);
    glVertex2f(i+4,110);
    glVertex2f(i,110);
    glEnd();
    }
    for (int i = 900; i <=935; i+=5) {
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(i,95);
    glVertex2f(i+4,95);
    glVertex2f(i+4,100);
    glVertex2f(i,100);
    glEnd();
    }

    glBegin(GL_QUADS);

  glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(910,130);
    glVertex2f(930,130);
    glVertex2f(927,140);
    glVertex2f(913,140);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(920,140);
    glVertex2f(920,170);
     glEnd();

     glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(914 ,165);
    glVertex2f(925,165);
     glEnd();

      glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(910,155);
    glVertex2f(930,155);
     glEnd();

   glBegin(GL_QUADS);
      glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(900,75);
    glVertex2f(960,75);
    glVertex2f(963,85);
    glVertex2f(903,85);
    glEnd();

    glLineWidth(2);
    for (int i = 903; i <= 963; i+=10) {
    glBegin(GL_LINES);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(i,85);
    glVertex2f(i,90);

    glEnd();
    }

    glBegin(GL_LINES);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(903,90);
    glVertex2f(963,90);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(756,82);
    glVertex2f(903,82);

    glEnd();

glPopMatrix();




}




//TM6
void updateboat2(int value) {
    boat2Position2 += boat2Speed2;
    if (boat2Position2 < -1800.0f) {
        boat2Position2 = 2000.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(80, updateboat2, 0); // Match the  boat's speed
}

//-----------------------------------------------------------------------------------------------------




 //float microPosition3= 0.0;
//float microSpeed3 = -5;
//updated func
//TM7
void updatemicro(int value) {
    if (isBusMoving) {
        microPosition3 += microSpeed3; // Move right
       if (microPosition3 < -1900.0f) {
        microPosition3 = 1900.0f; // Wrap from left again
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updatemicro, 0);
}



//OB35
 void bus7(){
    glPushMatrix();
    glTranslatef(microPosition3,busY, 0.0f);


    glColor3ub(184, 184, 155);
    glBegin(GL_POLYGON);
    glVertex2f(293.2196882808259, 245.9414998523724);
    glVertex2f(290.1360700549508, 244.1785483912489);
    glVertex2f(287.9150887013691, 242.5074109985556);
    glVertex2f(286.4627446426588, 241.2259309467524);
    glVertex2f(285.6084246081234, 239.2609948673208);
    glVertex2f(284.9541551042008, 237.2180912428628);
    glVertex2f(284.5705456704102, 235.9123580061443);
    glVertex2f(284.3269445563203, 233.0244586152117);
    glVertex2f(284.1250713856748, 222.8801505117827);
    glVertex2f(283.6810938087068, 207.7048513645968);
    glVertex2f(282.4489127153978, 191.5136314738558);
    glVertex2f(280.8507844378561, 181.924861808605);
    glVertex2f(279.8519542643925, 172.1363261086616);
    //E_1
    glVertex2f(279.1918997751287, 163.6784872875481);
    glVertex2f(278.8197647781487, 157.3521923388886);
    glVertex2f(278.2225562124638, 146.1372694103335);
    glVertex2f(278.7402379486613, 140.2702097334286);

    glVertex2f(279.6567386855583, 137.3444270459453);
    glVertex2f(280.9113149475691, 135.3729500627852);
    glVertex2f(282.3451163898671, 133.8495360303434);
    glVertex2f(284.0477556025961, 132.3261219979015);
    glVertex2f(285.9296199956123, 131.0715457358905);
    glVertex2f(288.2595473393466, 130.1754198344541);
    glVertex2f(290.8583124535119, 129.6377442935923);

    glVertex2f(294.737546725494, 129.4049774265173);
    glVertex2f(317.9610923664113, 129.2922443196746);
    glVertex2f(270.75327551,129.24241026);
    glVertex2f(527.3220793121917, 128.9339672041073);
    glVertex2f(596.783473233727, 129.0780637917456);
    glVertex2f(624.4234475826452, 129.4942318943237);
    glVertex2f(631.3954995646527, 130.4843634026661);
    glVertex2f(635.5858322650652, 131.1459948816786);
    glVertex2f(640.2172526181528, 131.5870825343536);
    glVertex2f(644.052855245998, 132.3167532597233);
    glVertex2f(648.2753890982393, 133.1563855923162);
    //L_2
    glVertex2f(648.7334642506796, 182.2973830057418);
    glVertex2f(648.5362318042933, 238.4897020954715);
    glVertex2f(648.3511004426362, 240.0941738964999);
    glVertex2f(647.8574168115505, 241.328382974214);
    glVertex2f(646.9317600032649, 242.5008815980424);
    glVertex2f(645.9443927410937, 243.3648279524423);
    glVertex2f(644.8336045711511, 244.1053533990707);
    glVertex2f(643.5272004334358, 245.1202805499473);
    glVertex2f(641.8495600899967, 245.6500617110334);
    glVertex2f(638.8510193300478, 245.8736097977383);
    glVertex2f(293.2196882808259, 245.9414998523724);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(68, 131, 168);
    glVertex2f(280.8507844378561, 181.924861808605);
    glVertex2f(279.8519542643925, 172.1363261086616);
    glVertex2f(279.1918997751287, 163.6784872875481);

    glVertex2f(280.5931734315271, 163.0558412054765);

    glVertex2f(281.6889709498011, 162.3209836698938);

    glVertex2f(283.1149910317125, 161.7949324053838);

    glVertex2f(284.4497134729927, 161.5029858852443);
    glVertex2f(287.0832961028051, 161.3274137099234);
    glVertex2f(289.5998306157368, 161.6200340021248);
    glVertex2f(292.2334132455491, 161.9711783527665);
    glVertex2f(295.1010921091225, 162.4393708202887);
    glVertex2f(297.4420544467334, 162.7319911124901);
    glVertex2f(299.6659686674638, 163.2001835800124);
    glVertex2f(301.421690420672, 163.6098519890943);
    glVertex2f(303.1774121738802, 164.0780444566165);
    glVertex2f(305.0501820439689, 164.3121406903777);
    glVertex2f(307.1570481478187, 164.6047609825791);
    glVertex2f(308.6786736672658, 164.8973812747805);
    glVertex2f(310, 165);
    glVertex2f(311.4878284723989, 165.2485256254221);
    glVertex2f(313.009453991846, 165.424097800743);
    glVertex2f(314.8048058712338, 165.6789302284238);
    glVertex2f(316.7024534405552, 166.0715469669042);
    glVertex2f(318.8945635637367, 166.4314456438445);
    glVertex2f(321.2829820561584, 166.6931901361647);
    glVertex2f(323.4750921793399, 166.8567804438648);
    glVertex2f(326.7872165378002, 167.1217503925414);
    glVertex2f(331.5566756139833, 167.6516902898952);
    glVertex2f(336.8107917710806, 167.6662091211863);
    glVertex2f(342.817898432749, 168.1816301872489);
    glVertex2f(348.1027656201716, 168.2747586100595);
    glVertex2f(352.971161531157, 168.2747586100595);
    glVertex2f(357.8395574421423, 168.4776084396839);
    glVertex2f(362.9784197926269, 168.4099918298091);
    glVertex2f(367.8468157036123, 168.6128416594335);
    glVertex2f(374.3803635580623, 168.1934187367058);
    glVertex2f(412.8090528767715, 169.4602986043557);
    glVertex2f(476.3051144170423, 170.3572035801235);
    glVertex2f(496.4593743341977, 171.0864482165499);
    glVertex2f(505.1534982216732, 171.9015223310008);
    glVertex2f(509.7722515368943, 172.7165964454515);
    glVertex2f(513.0284780399352, 173.3497515988207);
    glVertex2f(517.3701133773232, 174.0733574883854);
    glVertex2f(521.6212979785154, 174.4351604331678);
    glVertex2f(525.6906536832734, 174.6941362948168);
    glVertex2f(529.9405059104903, 175.2464683114943);
    glVertex2f(536.9768326068195, 176.1642500544938);
    glVertex2f(582.4416481159291, 177.6807536620541);
    glVertex2f(593.1281276731935, 177.951297448314);
    glVertex2f(602.1913445128988, 178.6276569139637);
    glVertex2f(612.0661927113836, 179.0334725933536);
    glVertex2f(632.0061350464532, 180.4082148949601);
    glVertex2f(648.7334642506796, 182.2973830057418);
    //////
    glVertex2f(648.2753890982393, 133.1563855923162);
glVertex2f(644.052855245998, 132.3167532597233);
glVertex2f(640.2172526181528, 131.5870825343536);
glVertex2f(635.5858322650652, 131.1459948816786);
glVertex2f(631.3954995646527, 130.4843634026661);
glVertex2f(624.4234475826452, 129.4942318943237);
glVertex2f(596.783473233727, 129.0780637917456);
glVertex2f(527.3220793121917, 128.9339672041073);
glVertex2f(270.75327551,129.24241026);
glVertex2f(317.9610923664113, 129.2922443196746);
glVertex2f(294.737546725494, 129.4049774265173);
glVertex2f(290.8583124535119, 129.6377442935923);
glVertex2f(288.2595473393466, 130.1754198344541);
glVertex2f(285.9296199956123, 131.0715457358905);
glVertex2f(284.0477556025961, 132.3261219979015);
glVertex2f(282.3451163898671, 133.8495360303434);
glVertex2f(280.9113149475691, 135.3729500627852);
glVertex2f(279.6567386855583, 137.3444270459453);
glVertex2f(278.7402379486613, 140.2702097334286);
glVertex2f(278.2225562124638, 146.1372694103335);
glVertex2f(278.8197647781487, 157.3521923388886);
glVertex2f(279.1918997751287, 163.6784872875481);
glVertex2f(279.8519542643925, 172.1363261086616);
glVertex2f(280.8507844378561, 181.924861808605);





    glEnd();


    //Bus light
    glBegin(GL_POLYGON);
    glColor3ub(242, 238, 13);
    glVertex2f(279.3880021579443, 161.7574683416311);
    glVertex2f(280.7024248649635, 161.4401938951092);
    glVertex2f(281.6089232835974, 161.0775945276556);
    glVertex2f(282.560746623163, 160.7603200811337);
    glVertex2f(283.4219201208652, 160.4430456346118);
    glVertex2f(284, 160);
    glVertex2f(284.3737434604308, 159.355247532251);
    glVertex2f(284.3737434604308, 158.3580992717536);
    glVertex2f(284.4643933022942, 157.542250694983);
    glVertex2f(284.2377686976357, 156.635752276349);
      glVertex2f(283.8298444092505, 155.729253857715);
    glVertex2f(283.4219201208652, 154.7321055972176);
    glVertex2f(282.8326961487531, 153.8709320995153);
    glVertex2f(282.3341220185045, 152.9191087599496);
    glVertex2f(281.7448980463925, 151.9219604994522);
    glVertex2f(281.1103491533488, 151.0154620808182);
    glVertex2f(280.3851504184416, 149.7916892156623);
    glVertex2f(279.433327078876, 148.5679163505064);
    glVertex2f(279.3880021579443, 161.7574683416311);


    glEnd();


    //bus window

    glBegin(GL_QUADS);
    glColor3ub(37, 36, 28);
    glVertex2f(292, 186);
    glVertex2f(640, 186);
    glVertex2f(640, 230);
    glVertex2f(292, 230);



    glVertex2f(292, 170);
    glVertex2f(334, 170);
    glVertex2f(334, 186);
    glVertex2f(292, 186);


    glColor3ub(75, 74, 59);
    glVertex2f(296, 190);
    glVertex2f(636, 190);
    glVertex2f(636, 226);
    glVertex2f(296, 226);


    glVertex2f(295, 172);
    glVertex2f(332, 172);
    glVertex2f(332, 186);
    glVertex2f(295, 186);



    glEnd();





//Tier_1

     glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i++) {
        float pi = 3.1416f;
        float A = (i  * pi)/180;
        float r = 30.59467;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+344.4811931299393, y+128.3698554974698);
    }
    glEnd();

      glColor3ub(71, 71, 61);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 24.5619;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+344.4811931299393, y+128.3698554974698);
    }
    glEnd();



      glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 13.6464;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+344.4811931299393, y+128.3698554974698);
    }
    glEnd();



      glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 2.898989;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+344.4811931299393, y+128.3698554974698);
    }
    glEnd();

//tier_2

  glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i++) {
        float pi = 3.1416f;
        float A = (i  * pi)/180;
        float r = 30.59467;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+554.1837922334446, y+128.3698554974698);
    }
    glEnd();

      glColor3ub(71, 71, 61);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 24.5619;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+554.1837922334446, y+128.3698554974698);
    }
    glEnd();



      glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 13.6464;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+554.1837922334446, y+128.3698554974698);
    }
    glEnd();



      glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 2.898989;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+554.1837922334446, y+128.3698554974698);
    }
    glEnd();


  windowline(0,0,0);
  windowline(10,0,0);
  windowline(90,0,0);
  windowline(170,0,0);
  windowline(250,0,0);


    glPopMatrix();
}
//TM8
void updatecar(int value) {
    carPosition3 += carSpeed3;
    if (carPosition3 > 1300.0f) {
        carPosition3 = -800.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatecar, 0); // Match the  boat's speed
}


//OB36
void windowline(float a,float b,float c)
{

    glPushMatrix();
    glTranslatef(a,b,c);
    glColor3ub(37, 36, 28);
    glBegin(GL_QUADS);
    glVertex2f(330, 186);
    glVertex2f(334, 186);
    glVertex2f(334, 230);
    glVertex2f(330, 230);


    glEnd();
    glPopMatrix();




}



//Cargo
//OB37
void cargo_Truck(float a, float b, float c)

{

   glPushMatrix();
    glTranslatef(a,b,c);


    glColor3ub(184, 184, 155);
    glBegin(GL_POLYGON);

    glVertex2f(1416.3478318479406, 211.2074167866959);
    glVertex2f(1418.103832166352, 213.7536172483928);
    glVertex2f(1419.1267453713285, 215.2751710252012);
    glVertex2f(1419.8598324847637, 216.2998177100898);
    glVertex2f(1421.3476490837627, 217.4153146026379);
    glVertex2f(1422.4060329464605, 218.4070180921839);
    glVertex2f(1423.689692998693, 219.3131777750817);
    glVertex2f(1425, 220);
    glVertex2f(1426.3547774536141, 220.1207791250578);
    glVertex2f(1427.4854193435806, 220.2419193275542);
    glVertex2f(1428.8987217060387, 220.3630595300506);
    glVertex2f(1431.337748335297, 220.562264503412);
    glVertex2f(1435.9278007875755, 220.4788090042797);
    glVertex2f(1496.6194991389016, 220.7225507647267);
    glVertex2f(1498.4729914019088, 220.4107722880759);
    glVertex2f(1499.939596315875, 219.6831529442048);
    glVertex2f(1501.1681530437002, 218.9743702166134);
    glVertex2f(1501.829683589452, 218.3128396708613);
    glVertex2f(1502.491214135204, 217.6985613069487);
    glVertex2f(1503.1527446809562, 216.8007698519995);
    glVertex2f(1504, 216);
    glVertex2f(1504.695215332897, 215.0904746211566);
    glVertex2f(1505.164969785406, 213.9341559688266);
    glVertex2f(1505.6012395071966, 212.4446931960381);
    glVertex2f(1505.8454340299916, 207.9677936114649);
    glVertex2f(1505.8746452187925, 128.0308219831911);//G12
    glVertex2f(1505.662111340404, 98.9667428780445);
    glVertex2f(1437.641251025874, 99.0271087850153);
    glVertex2f(1437.5687932247324, 95.7665077336737);
    glVertex2f(1397.5382342898386, 95.397337088145);
    glVertex2f(1396.590481314157, 95.8408725246947);
    glVertex2f(1395.8121229877909, 96.3597780756054);
    glVertex2f(1395.3144293434655, 96.7158263205975);
    glVertex2f(1394.817436565195, 97.0981284577285);
    glVertex2f(1394.2439833594988, 97.6333514497119);
    glVertex2f(1393.7469905812284, 98.1685744416952);
    glVertex2f(1393.135307161819, 98.8184880748179);
    glVertex2f(1392.7630403162984, 99.600301403512);
    glVertex2f(1392.3974584448029, 100.6450971692826);
    glVertex2f(1392.1993611514547, 101.6851079593554);
    glVertex2f(1391.9593883368395, 147.8285282229797);
    glVertex2f(1392.4002836340808, 149.2089534820164);
    glVertex2f(1392.8294008193286, 150.3675698821862);
    glVertex2f(1393.3014297231016, 151.5690980008807);
    glVertex2f(1393.8163703453993, 152.7277144010504);
    glVertex2f(1394.3742226862216, 154.0579776753193);
    glVertex2f(1394.974986745569, 155.3882409495883);
    glVertex2f(1395.5328390863913, 156.761415942382);
    glVertex2f(1397.245933718825, 160.1598689365257);
    glVertex2f(1416.3478318479406, 211.2074167866959);






    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(85, 85, 76);
    glVertex2f(1505.8746452187925, 128.0308219831911);
    glVertex2f(1505.662111340404, 98.9667428780445);
    glVertex2f(1437.641251025874, 99.0271087850153);
    glVertex2f(1437.5408807531264, 101.874890439603);
    glVertex2f(1437.3488501781844, 105.1874178573535);
    glVertex2f(1437.5408807531264, 107.4437771129227);
    glVertex2f(1437.876934259275, 109.5561134372853);
    glVertex2f(1438.3090030528947, 110.9963427493508);
    glVertex2f(1438.7612701964479, 112.0929076113974);
    glVertex2f(1439.2552878433467, 113.2527751302032);
    glVertex2f(1439.6204313214891, 114.3052475083788);
    glVertex2f(1440.0070538277578, 115.1429296052941);
    glVertex2f(1440.6299456434128, 116.2598390678479);
    glVertex2f(1441.240580889169, 117.1745426721021);
    glVertex2f(1442.057344039589, 118.2978974342417);
    glVertex2f(1442.7326892351048, 119.1733449099102);
    glVertex2f(1443.3580088605822, 119.9237284604833);
    glVertex2f(1444.1334051961742, 120.6991247960754);
    glVertex2f(1444.9088015317664, 121.3994827766102);
    glVertex2f(1445.809261792454, 122.2749302522788);
    glVertex2f(1447.048566413197, 123.2066855996915);
    glVertex2f(1447.6298324045626, 123.5699768442951);
    glVertex2f(1448.3927440182301, 124.1149137112004);
    glVertex2f(1449.7369216232632, 125.0231418227093);
    glVertex2f(1451.0810992282964, 125.8223825608372);
    glVertex2f(1452.1346438376468, 126.2946611788218);
    glVertex2f(1453.3335049448383, 126.8032689212668);
    glVertex2f(1455.2226194167768, 127.3118766637118);
    glVertex2f(1456.9664173908739, 127.747826157236);
    glVertex2f(1458.528569742669, 127.8931426550775);
    glVertex2f(1505.8746452187925, 128.0308219831911);


    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(62, 74, 76);

    glVertex2f(1506.6954956079746, 105.2986022513748);
    glVertex2f(1506.5517116398253, 124.9970058878235);
    glVertex2f(1867.4551461201995, 125.0912066079358);
    glVertex2f(1867.4551461201995, 106.7161401194707);
    glVertex2f(1506.6954956079746, 105.2986022513748);

    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(68, 131, 168);

    glVertex2f(1867.4551461201995, 125.0912066079358);
    glVertex2f(1867.4551461201995, 245.6329081355784);
    glVertex2f(1517.0097818190761, 247.7297237078259);
    glVertex2f(1517.3687072631194, 125.6858649571181);
    glVertex2f(1867.4551461201995, 125.0912066079358);

    glEnd();


      glColor3ub(77, 78, 57);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i++) {
        float pi = 3.1416f;
        float A = (i  * pi)/180;
        float r = 27;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1471.6119970872421, y+100.4636886787952);
    }
    glEnd();



     glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 25.787;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1471.6119970872421, y+100.4636886787952);
    }
    glEnd();



     glColor3ub(122, 123, 100);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 16;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1471.6119970872421, y+100.4636886787952);
    }
    glEnd();




    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1471.6119970872421, y+100.4636886787952);
    }
    glEnd();




    //2nd
    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 25.787;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1614.9954282917631, y+100.4636886787952);
    }
    glEnd();



    glColor3ub(122, 123, 100);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 16;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1614.9954282917631, y+100.4636886787952);
    }
    glEnd();


    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1614.9954282917631, y+100.4636886787952);
    }
    glEnd();



    //3rd

    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 25.787;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1670, y+100.4636886787952);
    }
    glEnd();


    glColor3ub(122, 123, 100);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 16;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1670, y+100.4636886787952);
    }
    glEnd();



    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1670, y+100.4636886787952);
    }
    glEnd();

//4th

 glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 25.787;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1820, y+100.4636886787952);
    }
    glEnd();


    glColor3ub(122, 123, 100);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 16;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1820, y+100.4636886787952);
    }
    glEnd();



    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416f;
        float A = (i *2 * pi)/180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1820, y+100.4636886787952);
    }
    glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(57, 79, 78);

    glVertex2f(1427.7236020448165, 201.4632575200066);
    glVertex2f(1428.220789392821, 202.6878670558897);
    glVertex2f(1428.8940484192724, 203.715472938368);
    glVertex2f(1429.6027421313265, 204.7076441352437);
    glVertex2f(1430.5594786425995, 205.6998153321193);
     glVertex2f(1431.693388581886, 206.5502477865841);
    glVertex2f(1432.7918638355698, 207.2589414986382);
    glVertex2f(1472.1366699261596, 206.7418199666927);
    glVertex2f(1473.5385500165112, 206.4379457842937);
    glVertex2f(1474.6598656432618, 205.8942776016267);
     glVertex2f(1475.3734301330123, 205.4185679417931);
    glVertex2f(1475.849139792846, 204.9428582819595);
    glVertex2f(1476.290870191263, 204.3312315764591);
    glVertex2f(1476.7665798510966, 203.8555219166255);
    glVertex2f(1477.1063724652636, 203.3458329953752);
     glVertex2f(1477.4121858180138, 202.7681855512916);
    glVertex2f(1477.6160613865138, 202.0886003229578);
    glVertex2f(1477.7859576935973, 201.4090150946241);
    glVertex2f(1477.833851641767, 162.7471230055758);
    glVertex2f(1477.27353493353, 161.8137039142078);
    glVertex2f(1476.8252815669402, 160.9732288518516);
     glVertex2f(1476.3770282003502, 160.1887854603193);
    glVertex2f(1475.7046481504651, 159.5724370812581);
    glVertex2f(1474.9274567746775, 158.8146352461552);
    glVertex2f(1474, 158);
    glVertex2f(1473.316617939604, 157.5755284499449);
    glVertex2f(1472.4905467421304, 157.1624928512082);
     glVertex2f(1471.9536004637725, 156.8320643722188);
    glVertex2f(1471.375350625541, 156.5842430129767);
    glVertex2f(1470.4253687484463, 156.3364216537347);
    glVertex2f(1468.4427978745098, 156.2538145339873);
    glVertex2f(1426.7225327050603, 154.4973028486219);
    glVertex2f(1425.9202206643076, 154.4973028486219);
     glVertex2f(1425.342555994966, 154.4652103669918);
    glVertex2f(1424.7969838072543, 154.529395330252);
    glVertex2f(1424.30139231451, 154.8267502258964);
    glVertex2f(1423.880421877956, 155.6686910990034);
    glVertex2f(1423.760144610369, 157.7735432817724);
     glVertex2f(1423.6985403717197, 159.6792839611967);
    glVertex2f(1427.7236020448165, 201.4632575200066);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(57, 79, 78);

    glVertex2f(1415.1768705551851, 206.6410986769221);
    glVertex2f(1416.6683085910524, 206.8896716828999);
    glVertex2f(1417.9111736209416, 206.942905676951);
    glVertex2f(1418.867265038707, 206.7741836620513);
    glVertex2f(1419.710875113206, 206.3242582889853);
    glVertex2f(1420.385763172805, 205.7618515726528);
    glVertex2f(1421.0044105607708, 205.0869635130538);
    glVertex2f(1421.4543359338368, 204.3558347818216);
    glVertex2f(1421.6230579487367, 203.0060586626236);
    glVertex2f(1421.285613918937, 201.4875605285259);
    glVertex2f(1405.7821663116506, 159.9340316041417);
    glVertex2f(1405.0018629750657, 159.1762195201007);
    glVertex2f(1404.0756890255827, 159.0787275254183);
    glVertex2f(1403.247007070782, 159.0787275254183);
    glVertex2f(1402.1745951292755, 159.2249655174419);

    glVertex2f(1400.8097072037215, 159.4686955041479);
    glVertex2f(1399.2010892914616, 159.8099174855364);
    glVertex2f(1397.245933718825, 160.1598689365257);
    glVertex2f(1415.1768705551851, 206.6410986769221);


    glEnd();




    glBegin(GL_POLYGON);
    glColor3ub(241, 234, 28);

    glVertex2f(1392.6193914373703, 126.581021808021);
    glVertex2f(1401.8745869730228, 126.8183345140634);
    glVertex2f(1403.4162543294024, 125.6818820783787);
    glVertex2f(1403.7546544573945, 124.5990016688041);
    glVertex2f(1403.4162543294024, 123.583801284828);
    glVertex2f(1402.6040940222215, 122.5009208752535);
    glVertex2f(1401.3181735358517, 122.2302007728599);
    glVertex2f(1392.5810823478832, 122.2507601602716);
    glVertex2f(1392.6193914373703, 126.581021808021);


    glEnd();




    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(1486.6525348548382, 129.2086633522481);
    glVertex2f(1486.8252786284745, 206.4251301676146);



    glVertex2f(1486.8252786284745, 206.4251301676146);
    glVertex2f(1505.7159706419352, 205.7897166163279);


    glEnd();




    glBegin(GL_POLYGON);
    glColor3ub(52, 52, 50);

    glVertex2f(1523.1124745323111, 112.5624418865387);
    glVertex2f(1523.3937115355948, 113.4998985641507);
    glVertex2f(1523.6749485388784, 114.2029910723597);
    glVertex2f(1524.0968040438038, 114.9060835805687);
    glVertex2f(1524.5655323826097, 115.6560489226583);
    glVertex2f(1525.1748792230576, 116.2185229292255);
    glVertex2f(1525.690480395744, 116.7809969357927);
    glVertex2f(1526.3125810068966, 117.2040086210724);
    glVertex2f(1577.7003378133325, 117.293115461337);
    glVertex2f(1578.9625221473716, 117.0082839328178);
    glVertex2f(1580.1336180720618, 116.6442407256758);
     glVertex2f(1581.3502582014266, 115.7520379641416);
    glVertex2f(1582.1613516210032, 114.7787258606498);
    glVertex2f(1582.2424609629609, 113.562085731285);
    glVertex2f(1582.2424609629609, 112.183226918005);
    glVertex2f(1582.6723150302164, 103.758152020036);
    glVertex2f(1582.4583585669695, 102.5599958258528);
    glVertex2f(1581.6025327139814, 101.404630924319);
    glVertex2f(1580.9606633242406, 100.5060137786816);
    glVertex2f(1580, 100);
     glVertex2f(1579.3246753557291, 99.5975297073834);
    glVertex2f(1578.8244222817736, 99.4132259432946);
    glVertex2f(1578.1661945528847, 99.3079095066723);
    glVertex2f(1527.0954797599147, 99.3930619899087);

     glVertex2f(1525, 100);
    glVertex2f(1524.1283577396132, 100.9707668474999);
    glVertex2f(1523.574828734149, 101.9671190573353);
    glVertex2f(1523.1320055297776, 102.742059664985);

     glVertex2f(1522.7998881264994, 103.959823477006);
    glVertex2f(1522.63382942486, 105.3436459906663);
    glVertex2f(1523.1124745323111, 112.5624418865387);




    glEnd();



     glBegin(GL_LINES);
    glColor3ub(115, 115, 109);

    glVertex2f(1534.4897018972124, 99.1432773227808);
    glVertex2f(1534.1443402051266, 117.5337874263493);



    glVertex2f(1552.0168077705698, 99.4886390148666);
    glVertex2f(1551.5851056554625, 117.7928086954136);


     glVertex2f(1569.338480351273, 99.7081349053607);
    glVertex2f(1569.4619634772212, 117.3662219159706);



    glEnd();




     glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(1468.5303467639903, 148.1948863767132);
    glVertex2f(1481.9959230097734, 148.1948863767132);
    glVertex2f(1481.6368409765525, 153.2220348418047);
    glVertex2f(1468.1712647307693, 152.6834117919735);
    glVertex2f(1468.5303467639903, 148.1948863767132);



    glEnd();



    cargo_design(0,0,0);
    cargo_design(17,0,0);
    cargo_design(34,0,0);
    cargo_design(51,0,0);
    cargo_design(68,0,0);
    cargo_design(85,0,0);
    cargo_design(102,0,0);
    cargo_design(119, 0, 0);
cargo_design(136, 0, 0);
cargo_design(153, 0, 0);
cargo_design(170, 0, 0);
cargo_design(187, 0, 0);
cargo_design(204, 0, 0);
cargo_design(221, 0, 0);
cargo_design(238, 0, 0);
cargo_design(255, 0, 0);
cargo_design(272, 0, 0);
cargo_design(289, 0, 0);
cargo_design(306, 0, 0);
cargo_design(323, 0, 0);






    glPopMatrix();



}




//TM9
void updatecargo(int value) {
    cargoPosition3 += cargoSpeed3;
    if ( cargoPosition3 < -1900.0f) {
         cargoPosition3 = 1900.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(16, updatecargo, 0);

}
//OB38
void cargo_design(float a, float b, float c)
{

    glPushMatrix();
    glTranslatef(a,b,c);


    glBegin(GL_POLYGON);
    glColor3ub(84, 124, 144);
    glVertex2f(1526.1819928254556, 132.465352720328);
    glVertex2f(1539.5511814570696, 132.3318714310318);
    glVertex2f(1539.5511814570696, 239.5467277508209);
    glVertex2f(1526.210253846322, 239.630458631985);
    glVertex2f(1526.1819928254556, 132.465352720328);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(29, 111, 150);
    glVertex2f(1530, 135);
    glVertex2f(1536.2796369555647, 134.9557017994453);
    glVertex2f(1536.3954588235447, 235.5194732375784);
    glVertex2f(1529.8612879839807, 235.5194732375784);
    glVertex2f(1530, 135);

    glEnd();


    glPopMatrix();



}


//OB39
void car7777777(){

glPushMatrix();
glScalef(0.7f, 0.7f, 1.0f);
glTranslatef(car2_move,-50,0);

glTranslatef(0, 55, 0);
// Step 1: Translate to pivot point (midpoint of car’s X range)
glTranslatef(1000, 0, 0);  // approx center of car's X-range

// Step 2: Mirror across Y-axis to flip horizontally
glScalef(-1, 1, 1);

// Step 3: Translate back after flipping
glTranslatef(-1600, 0, 0);





glBegin(GL_POLYGON);     //carbody
glColor3ub(62, 74, 76);

glVertex2f(1445.3914501733782, 68.2694392845542);
glVertex2f(1417.8347698810774, 68.6233942201061);
glVertex2f(1412.5848265311313, 68.9172722026063);
glVertex2f(1407.5287533023597, 70.7476562692573);

glVertex2f(1404, 74);
glVertex2f(1401.4815281513606, 77.1782374353524);
glVertex2f(1399.0765104056989, 80.3284719472784);
glVertex2f(1397.135542428811, 83.2077912637028);
glVertex2f(1395.4248936800652, 86.9401158064242);
glVertex2f(1394.57284243499, 89.1202643590344);
glVertex2f(1394.3063251723167, 91.7528308634571);
glVertex2f(1394.1753733798755, 95.5993247188406);

glVertex2f(1394.3605267467328, 99.8505046212322);
glVertex2f(1395.3894466352883, 103.8975895162202);
glVertex2f(1397.4909277367262, 108.6098400246408);
glVertex2f(1399.544320048372, 113.4489827551592);
glVertex2f(1403.0627876823619, 119.8216498046152);
glVertex2f(1407.8025325521214, 126.1026792285339);
glVertex2f(1412.7273184863648, 131.3792355866571);



glVertex2f(1420.231754195688, 135.4832238651974);
glVertex2f(1429.846812448258, 138.531900872113);
glVertex2f(1439.968795646134, 141.291273842492);
glVertex2f(1449.9807616397675, 143.218293283439);
glVertex2f(1459.4897344309513, 144.2988583733473);
glVertex2f(1471.8773448160798, 146.0344145199286);
glVertex2f(1486.3958051696413, 146.5680450621549);


glVertex2f(1498.8773107433544, 147.2870340296344);
glVertex2f(1502.883304948859, 148.6145071443052);
glVertex2f(1532.318165735683, 163.7917417584851);
glVertex2f(1559.4790431030087, 177.070362371119);
glVertex2f(1564.0732027144431, 180.8724254978272);
glVertex2f(1568.3505237319857, 182.9318763581275);
glVertex2f(1574.5771546949857, 185.3093168880597);

glVertex2f(1582.9689798153718, 186.8585769102864);
glVertex2f(1661.0775059358884, 187.1167869139908);
glVertex2f(1675.5525210180344, 184.8647460558638);
glVertex2f(1690, 180);
glVertex2f(1697.2701263961007, 173.57674175902);
glVertex2f(1749.2432643645523, 147.6555269619759);
glVertex2f(1755.8351739670582, 152.1211742596365);


glVertex2f(1782.5729083578212, 152.2029942764171);
glVertex2f(1788.51523598853, 149.3968951174685);
glVertex2f(1792.146658429519, 146.2606666457024);
glVertex2f(1794.4575636192392, 141.9689855790752);
glVertex2f(1793.7973049936047, 136.6869165739955);
glVertex2f(1794.127434306422, 132.560300163777);
glVertex2f(1792.8069170551532, 116.3839638357204);

glVertex2f(1795.3251842333177, 111.5987988449264);
glVertex2f(1797.2898412806421, 105.5537002377684);
glVertex2f(1798.4988610020725, 98.6018368395367);
glVertex2f(1798.196606071715, 91.6499734413049);
glVertex2f(1797.3714042762872, 84.1274081644645);
glVertex2f(1793.1215589523954, 77.044332624638);

glVertex2f(1787.7384215421325, 74.6360869410969);
glVertex2f(1777.3507011244442, 71.2476085707634);
glVertex2f(1765.7553343992636, 69.0598035282744);
glVertex2f(1750.2219185976066, 68.2694392845542);
glVertex2f(1445.3914501733782, 68.2694392845542);


glEnd();


glBegin(GL_POLYGON);     //car1window
glColor3ub(1,1,1);

glVertex2f(1498.8773107433544, 147.2870340296344);
glVertex2f(1499.6518848551293, 144.1870506571307);
glVertex2f(1502.5451355171451, 142.0314249301202);
glVertex2f(1511.089669110188, 140.322557292427);

glVertex2f(1520, 140);
glVertex2f(1574.466435014054, 173.3993479651365);
glVertex2f(1567.8791907763243, 176.0862502200024);
glVertex2f(1559.4790431030087, 177.070362371119);
glVertex2f(1532.318165735683, 163.7917417584851);
glVertex2f(1502.883304948859, 148.6145071443052);

glEnd();


glBegin(GL_POLYGON);     //car1window
glColor3ub(71, 79, 83);

glVertex2f(1502.883304948859, 148.6145071443052);
glVertex2f(1501.5288554246495, 147.4286306316465);
glVertex2f(1500.5011668760699, 146.0155654949025);
glVertex2f(1502.6060801592628, 144.568437612706);

glVertex2f(1506.3554569449502, 143.1870882706093);
glVertex2f(1510.1371093465286, 142.552056656911);
glVertex2f(1516.6209930098469, 142.2214253229734);
glVertex2f(1520.2620272609333, 142.0133662229111);
glVertex2f(1570.2352295596447, 173.1837594400908);
glVertex2f(1556.0078707457812, 175.0145864297436);
glVertex2f(1532.318165735683, 163.7917417584851);


glEnd();


glBegin(GL_POLYGON);     //car1window
glColor3ub(1,1,1);

glVertex2f(1524.1483347907554, 133.994360190737);
glVertex2f(1535.4110606622778, 143.2772036416665);
glVertex2f(1547.689697981596, 150.9513519662475);
glVertex2f(1560, 160);

glVertex2f(1569.2791803415869, 164.3031251611475);
glVertex2f(1581.8339033668685, 169.6388824468972);
glVertex2f(1595.6440986946784, 173.2483653166691);
glVertex2f(1602.7978916125548, 174.3440730354614);
glVertex2f(1656.9707398075304, 174.5248232454774);
glVertex2f(1669.4081774477581, 172.1557875044794);
glVertex2f(1682.4378740232348, 167.6151356675665);

glVertex2f(1693.4933741478817, 162.4822248954042);
glVertex2f(1704.5488742725286, 155.7699569625765);
glVertex2f(1708.1595958205676, 151.0768028803541);
glVertex2f(1702.5592961417688, 133.994360190737);



glEnd();


glBegin(GL_POLYGON);     //car1window
glColor3ub(71, 79, 83
);

glVertex2f(1529.118748398073, 136.2659465428214);
glVertex2f(1536.1150746958594, 141.7566021428575);
glVertex2f(1548.6417152247784, 149.8192961769936);
glVertex2f(1561.4319036445743, 157.9414627780736);

glVertex2f(1570.1899305015477, 162.738660496958);
glVertex2f(1582.8322230975498, 167.0752625710467);
glVertex2f(1588.9156372093396, 168.5791526531986);
glVertex2f(1617.1455110206016, 168.5811748936898);
glVertex2f(1617.1455110206016, 136.2659465428214);

glEnd();

glBegin(GL_POLYGON);     //car1window
glColor3ub(71, 79, 83
);

glVertex2f(1623.5754616901531, 136.2659465428214);
glVertex2f(1623.5754616901531, 168.5791526531986);
glVertex2f(1665.1643591615732, 168.5791526531986);
glVertex2f(1665.1643591615732, 136.2659465428214);


glEnd();

glBegin(GL_POLYGON);     //car1window
glColor3ub(71, 79, 83
);

glVertex2f(1671.1860706412433, 168.5791526531986);
glVertex2f(1680.1631308221351, 164.3727953642939);
glVertex2f(1688.9166527416528, 159.6977028434082);
glVertex2f(1696.0796547827226, 155.4957621912506);

glVertex2f(1702.7011529347023, 150.7553714688049);
glVertex2f(1700.1151217748984, 136.2659465428214);
glVertex2f(1671.1860706412433, 136.2659465428214);



glEnd();

glBegin(GL_POLYGON);     //car1window
glColor3ub(71, 79, 83);

glVertex2f(1690, 180);
glVertex2f(1710.7855424140707, 172.1947626717054);
glVertex2f(1755.8351739670582, 152.1211742596365);
glVertex2f(1749.2432643645523, 147.6555269619759);

glVertex2f(1697.2701263961007, 173.57674175902);
glVertex2f(1690, 180);





glEnd();


glBegin(GL_POLYGON);    //lights
glColor3ub(246, 241, 233);

glVertex2f(1397.4909277367262, 108.6098400246408);
glVertex2f(1399.544320048372, 113.4489827551592);
glVertex2f(1403.0627876823619, 119.8216498046152);
glVertex2f(1409.0700478732963, 119.3096427225466);

glVertex2f(1408.042232157768, 111.7551972134043);
glVertex2f(1403.57123379522, 106.2049923495446);
glVertex2f(1399.716924861989, 106.7702909930859);


glEnd();

glBegin(GL_POLYGON);    //lights
glColor3ub(246, 241, 233);

glVertex2f(1409.0700478732963, 119.3096427225466);
glVertex2f(1415.3855076255454, 121.4067857224794);
glVertex2f(1425.5962390394982, 122.4070792806691);
glVertex2f(1447.5622578880725, 123.0784816663039);

glVertex2f(1448.6530649384088, 119.6969798102579);
glVertex2f(1447.2350157729718, 115.9882358391107);

glVertex2f(1443.4171910967955, 113.6975410334022);
glVertex2f(1437.6359137300144, 111.6250076377611);
glVertex2f(1431.8889935900922, 111.0033055295769);
glVertex2f(1408.042232157768, 111.7551972134043);



glEnd();


glBegin(GL_POLYGON);    //lights
glColor3ub(246, 33, 4);

glVertex2f(1769.9933727601763, 130.6568686206931);
glVertex2f(1776.7801484960298, 116.0168238190482);
glVertex2f(1792.983752010349, 115.636075046198);
glVertex2f(1794.127434306422, 132.560300163777);

glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);

glVertex2f(1592.4750086040583, 125.0013707315354);
glVertex2f(1606.6307709094756, 125.0013707315354);
glVertex2f(1609.3675516218561, 123.3026792548834);
glVertex2f(1608.5182058835312,118.9615788145503);

glVertex2f(1593.135610844978, 118.9615788145503);
glVertex2f(1591.2481758709223, 122.0758465217458);


glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);

glVertex2f(1676.1522173517546, 118.9615788145503);
glVertex2f(1691.732813267159, 118.9615788145503);
glVertex2f(1694.167281378941, 124.0776407984034);
glVertex2f(1691.61108986157, 125.0013707315354);

glVertex2f(1676.5173875685218, 125.0013707315354);
glVertex2f(1674.204642862329, 124.0776407984034);
glVertex2f(1676.1522173517546, 118.9615788145503);



glEnd();

glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(147,171,139);

glVertex2f(1524.803558586959, 131.5142331552398);
glVertex2f(1525.4458107735977, 73.6250267323157);

glVertex2f(1525.4458107735977, 73.6250267323157);
glVertex2f(1667.24603273276, 73.6250267323157);

glVertex2f(1667.24603273276, 73.6250267323157);
glVertex2f(1707.582886131696, 131.5142331552398);

glVertex2f(1615.1843923056524, 131.5142331552398);
glVertex2f(1615.1843923056524, 73.6250267323157);


glEnd();

car1wheels(0,0,0);
car1wheels(237.14,0,0);

glPopMatrix();

}




//TM10
void updateCar88(int value) {
    car3_move += car3_speed;

    // Reset position if car moves out of screen (adjust limit based on your scene width)
    if (car3_move > 1920) {
        car3_move = -1900; // Reset from left side
    }

    glutPostRedisplay(); // Request redraw
    glutTimerFunc(16, updateCar88, 0); // ~60 FPS (1000ms / 60 = ~16ms)
}

//car_An2
//OB40
void car888(float r, float g, float b){

glPushMatrix();
glScalef(0.7f, 0.7f, 1.0f);
glTranslatef(car3_move,-70,0);

glTranslatef(0, 55, 0);
// Step 1: Translate to pivot point (midpoint of car’s X range)
glTranslatef(1600, 0, 0);  // approx center of car's X-range

// Step 2: Mirror across Y-axis to flip horizontally
glScalef(-1, 1, 1);

// Step 3: Translate back after flipping
glTranslatef(-1600, 0, 0);





glBegin(GL_POLYGON);     //carbody
glColor3ub(r,g,b);

glVertex2f(1445.3914501733782, 68.2694392845542);
glVertex2f(1417.8347698810774, 68.6233942201061);
glVertex2f(1412.5848265311313, 68.9172722026063);
glVertex2f(1407.5287533023597, 70.7476562692573);

glVertex2f(1404, 74);
glVertex2f(1401.4815281513606, 77.1782374353524);
glVertex2f(1399.0765104056989, 80.3284719472784);
glVertex2f(1397.135542428811, 83.2077912637028);
glVertex2f(1395.4248936800652, 86.9401158064242);
glVertex2f(1394.57284243499, 89.1202643590344);
glVertex2f(1394.3063251723167, 91.7528308634571);
glVertex2f(1394.1753733798755, 95.5993247188406);

glVertex2f(1394.3605267467328, 99.8505046212322);
glVertex2f(1395.3894466352883, 103.8975895162202);
glVertex2f(1397.4909277367262, 108.6098400246408);
glVertex2f(1399.544320048372, 113.4489827551592);
glVertex2f(1403.0627876823619, 119.8216498046152);
glVertex2f(1407.8025325521214, 126.1026792285339);
glVertex2f(1412.7273184863648, 131.3792355866571);



glVertex2f(1420.231754195688, 135.4832238651974);
glVertex2f(1429.846812448258, 138.531900872113);
glVertex2f(1439.968795646134, 141.291273842492);
glVertex2f(1449.9807616397675, 143.218293283439);
glVertex2f(1459.4897344309513, 144.2988583733473);
glVertex2f(1471.8773448160798, 146.0344145199286);
glVertex2f(1486.3958051696413, 146.5680450621549);


glVertex2f(1498.8773107433544, 147.2870340296344);
glVertex2f(1502.883304948859, 148.6145071443052);
glVertex2f(1532.318165735683, 163.7917417584851);
glVertex2f(1559.4790431030087, 177.070362371119);
glVertex2f(1564.0732027144431, 180.8724254978272);
glVertex2f(1568.3505237319857, 182.9318763581275);
glVertex2f(1574.5771546949857, 185.3093168880597);

glVertex2f(1582.9689798153718, 186.8585769102864);
glVertex2f(1661.0775059358884, 187.1167869139908);
glVertex2f(1675.5525210180344, 184.8647460558638);
glVertex2f(1690, 180);
glVertex2f(1697.2701263961007, 173.57674175902);
glVertex2f(1749.2432643645523, 147.6555269619759);
glVertex2f(1755.8351739670582, 152.1211742596365);


glVertex2f(1782.5729083578212, 152.2029942764171);
glVertex2f(1788.51523598853, 149.3968951174685);
glVertex2f(1792.146658429519, 146.2606666457024);
glVertex2f(1794.4575636192392, 141.9689855790752);
glVertex2f(1793.7973049936047, 136.6869165739955);
glVertex2f(1794.127434306422, 132.560300163777);
glVertex2f(1792.8069170551532, 116.3839638357204);

glVertex2f(1795.3251842333177, 111.5987988449264);
glVertex2f(1797.2898412806421, 105.5537002377684);
glVertex2f(1798.4988610020725, 98.6018368395367);
glVertex2f(1798.196606071715, 91.6499734413049);
glVertex2f(1797.3714042762872, 84.1274081644645);
glVertex2f(1793.1215589523954, 77.044332624638);

glVertex2f(1787.7384215421325, 74.6360869410969);
glVertex2f(1777.3507011244442, 71.2476085707634);
glVertex2f(1765.7553343992636, 69.0598035282744);
glVertex2f(1750.2219185976066, 68.2694392845542);
glVertex2f(1445.3914501733782, 68.2694392845542);


glEnd();


glBegin(GL_POLYGON);     //car1window
glColor3ub(1,1,1);

glVertex2f(1498.8773107433544, 147.2870340296344);
glVertex2f(1499.6518848551293, 144.1870506571307);
glVertex2f(1502.5451355171451, 142.0314249301202);
glVertex2f(1511.089669110188, 140.322557292427);

glVertex2f(1520, 140);
glVertex2f(1574.466435014054, 173.3993479651365);
glVertex2f(1567.8791907763243, 176.0862502200024);
glVertex2f(1559.4790431030087, 177.070362371119);
glVertex2f(1532.318165735683, 163.7917417584851);
glVertex2f(1502.883304948859, 148.6145071443052);

glEnd();


glBegin(GL_POLYGON);     //car1window
glColor3ub(71, 79, 83);

glVertex2f(1502.883304948859, 148.6145071443052);
glVertex2f(1501.5288554246495, 147.4286306316465);
glVertex2f(1500.5011668760699, 146.0155654949025);
glVertex2f(1502.6060801592628, 144.568437612706);

glVertex2f(1506.3554569449502, 143.1870882706093);
glVertex2f(1510.1371093465286, 142.552056656911);
glVertex2f(1516.6209930098469, 142.2214253229734);
glVertex2f(1520.2620272609333, 142.0133662229111);
glVertex2f(1570.2352295596447, 173.1837594400908);
glVertex2f(1556.0078707457812, 175.0145864297436);
glVertex2f(1532.318165735683, 163.7917417584851);


glEnd();


glBegin(GL_POLYGON);     //car1window
glColor3ub(1,1,1);

glVertex2f(1524.1483347907554, 133.994360190737);
glVertex2f(1535.4110606622778, 143.2772036416665);
glVertex2f(1547.689697981596, 150.9513519662475);
glVertex2f(1560, 160);

glVertex2f(1569.2791803415869, 164.3031251611475);
glVertex2f(1581.8339033668685, 169.6388824468972);
glVertex2f(1595.6440986946784, 173.2483653166691);
glVertex2f(1602.7978916125548, 174.3440730354614);
glVertex2f(1656.9707398075304, 174.5248232454774);
glVertex2f(1669.4081774477581, 172.1557875044794);
glVertex2f(1682.4378740232348, 167.6151356675665);

glVertex2f(1693.4933741478817, 162.4822248954042);
glVertex2f(1704.5488742725286, 155.7699569625765);
glVertex2f(1708.1595958205676, 151.0768028803541);
glVertex2f(1702.5592961417688, 133.994360190737);



glEnd();


glBegin(GL_POLYGON);     //car1window
glColor3ub(71, 79, 83
);

glVertex2f(1529.118748398073, 136.2659465428214);
glVertex2f(1536.1150746958594, 141.7566021428575);
glVertex2f(1548.6417152247784, 149.8192961769936);
glVertex2f(1561.4319036445743, 157.9414627780736);

glVertex2f(1570.1899305015477, 162.738660496958);
glVertex2f(1582.8322230975498, 167.0752625710467);
glVertex2f(1588.9156372093396, 168.5791526531986);
glVertex2f(1617.1455110206016, 168.5811748936898);
glVertex2f(1617.1455110206016, 136.2659465428214);

glEnd();

glBegin(GL_POLYGON);     //car1window
glColor3ub(71, 79, 83
);

glVertex2f(1623.5754616901531, 136.2659465428214);
glVertex2f(1623.5754616901531, 168.5791526531986);
glVertex2f(1665.1643591615732, 168.5791526531986);
glVertex2f(1665.1643591615732, 136.2659465428214);


glEnd();

glBegin(GL_POLYGON);     //car1window
glColor3ub(71, 79, 83
);

glVertex2f(1671.1860706412433, 168.5791526531986);
glVertex2f(1680.1631308221351, 164.3727953642939);
glVertex2f(1688.9166527416528, 159.6977028434082);
glVertex2f(1696.0796547827226, 155.4957621912506);

glVertex2f(1702.7011529347023, 150.7553714688049);
glVertex2f(1700.1151217748984, 136.2659465428214);
glVertex2f(1671.1860706412433, 136.2659465428214);



glEnd();

glBegin(GL_POLYGON);     //car1window
glColor3ub(71, 79, 83);

glVertex2f(1690, 180);
glVertex2f(1710.7855424140707, 172.1947626717054);
glVertex2f(1755.8351739670582, 152.1211742596365);
glVertex2f(1749.2432643645523, 147.6555269619759);

glVertex2f(1697.2701263961007, 173.57674175902);
glVertex2f(1690, 180);





glEnd();


glBegin(GL_POLYGON);    //lights
glColor3ub(246, 241, 233);

glVertex2f(1397.4909277367262, 108.6098400246408);
glVertex2f(1399.544320048372, 113.4489827551592);
glVertex2f(1403.0627876823619, 119.8216498046152);
glVertex2f(1409.0700478732963, 119.3096427225466);

glVertex2f(1408.042232157768, 111.7551972134043);
glVertex2f(1403.57123379522, 106.2049923495446);
glVertex2f(1399.716924861989, 106.7702909930859);


glEnd();

glBegin(GL_POLYGON);    //lights
glColor3ub(246, 241, 233);

glVertex2f(1409.0700478732963, 119.3096427225466);
glVertex2f(1415.3855076255454, 121.4067857224794);
glVertex2f(1425.5962390394982, 122.4070792806691);
glVertex2f(1447.5622578880725, 123.0784816663039);

glVertex2f(1448.6530649384088, 119.6969798102579);
glVertex2f(1447.2350157729718, 115.9882358391107);

glVertex2f(1443.4171910967955, 113.6975410334022);
glVertex2f(1437.6359137300144, 111.6250076377611);
glVertex2f(1431.8889935900922, 111.0033055295769);
glVertex2f(1408.042232157768, 111.7551972134043);



glEnd();


glBegin(GL_POLYGON);    //lights
glColor3ub(246, 33, 4 );

glVertex2f(1769.9933727601763, 130.6568686206931);
glVertex2f(1776.7801484960298, 116.0168238190482);
glVertex2f(1792.983752010349, 115.636075046198);
glVertex2f(1794.127434306422, 132.560300163777);

glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);

glVertex2f(1592.4750086040583, 125.0013707315354);
glVertex2f(1606.6307709094756, 125.0013707315354);
glVertex2f(1609.3675516218561, 123.3026792548834);
glVertex2f(1608.5182058835312,118.9615788145503);

glVertex2f(1593.135610844978, 118.9615788145503);
glVertex2f(1591.2481758709223, 122.0758465217458);


glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);

glVertex2f(1676.1522173517546, 118.9615788145503);
glVertex2f(1691.732813267159, 118.9615788145503);
glVertex2f(1694.167281378941, 124.0776407984034);
glVertex2f(1691.61108986157, 125.0013707315354);

glVertex2f(1676.5173875685218, 125.0013707315354);
glVertex2f(1674.204642862329, 124.0776407984034);
glVertex2f(1676.1522173517546, 118.9615788145503);



glEnd();

glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(147,171,139);

glVertex2f(1524.803558586959, 131.5142331552398);
glVertex2f(1525.4458107735977, 73.6250267323157);

glVertex2f(1525.4458107735977, 73.6250267323157);
glVertex2f(1667.24603273276, 73.6250267323157);

glVertex2f(1667.24603273276, 73.6250267323157);
glVertex2f(1707.582886131696, 131.5142331552398);

glVertex2f(1615.1843923056524, 131.5142331552398);
glVertex2f(1615.1843923056524, 73.6250267323157);


glEnd();

car1wheels(0,0,0);
car1wheels(237.14,0,0);

glPopMatrix();

}










//OB41
void car1wheels(float x,float y,float z)

{
glPushMatrix();
glTranslatef(x,y,z);

glBegin(GL_POLYGON);      //PICKUPWHEELS
	for(int i=0;i<200;i++)
        {
            glColor3ub(56, 59, 61);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=32.35;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1478.6931354112655,y+80.2590875832457);
        }

glEnd();

glBegin(GL_POLYGON);      //PICKUPWHEELS
	for(int i=0;i<200;i++)
        {
            glColor3ub(215,223,193);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=21.43;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1478.6931354112655,y+80.2590875832457);
        }

glEnd();


glPopMatrix();


}


 // Speed of the car (pixels per frame)
//TM11
void updateCar777(int value) {
    car2_move += car2_speed;

    // Reset position if car moves out of screen (adjust limit based on your scene width)
    if (car2_move > 1920) {
        car2_move = -1900; // Reset from left side
    }

    glutPostRedisplay(); // Request redraw
    glutTimerFunc(16, updateCar777, 0); // ~60 FPS (1000ms / 60 = ~16ms)
}









//-----------------------------------------------------------------------------------------------------

#define NUM_BIRDS 7

float birdX[NUM_BIRDS] = {50,100, 150, 200, 250, 300,375};
float birdY[NUM_BIRDS] = {910,900, 920, 910, 930, 905, 925};
float wingAngle[NUM_BIRDS] = {0};
bool flapUp[NUM_BIRDS] = {true};



//OB42
void AnimatedBird(float x, float y, float scale, float wing) {
    glColor3ub(0, 0, 0);  // Black bird

    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);

    // Left wing
    glPushMatrix();
    glRotatef(wing, 0, 0, 1);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(-15, 10);
    glEnd();
    glPopMatrix();

    // Right wing
    glPushMatrix();
    glRotatef(-wing, 0, 0, 1);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(15, 10);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}

//TM12
void updateBird(int value) {
    for (int i = 0; i < NUM_BIRDS; i++) {
        // Flap logic
        if (flapUp[i]) {
            wingAngle[i] += 2;
            if (wingAngle[i] >= 20) flapUp[i] = false;
        } else {
            wingAngle[i] -= 2;
            if (wingAngle[i] <= -20) flapUp[i] = true;
        }

        // Move birds horizontally
        birdX[i] += 1;
        if (birdX[i] > 2000) birdX[i] = -100;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateBird, 0);  // ~60 FPS
}


//Rainfall

void addDrop() {
    if (totalDrops < MAX_DROPS) {
        dropX[totalDrops] = rand() % 1900;   // random X from 0 to 1899
        dropY[totalDrops] = 1000;            // start at top of screen
        totalDrops++;
    }
}
//TM13
void updateRain(int value) {
    for (int i = 0; i < totalDrops; i++) {
        dropY[i] -= 15; // Speed of fall

        if (dropY[i] < 0) { // Reset drop
            dropY[i] = 1000;
            dropX[i] = rand() % 1900;
        }
    }

    for (int i = 0; i < 10; i++) addDrop(); // add new drops

    glutPostRedisplay();
    glutTimerFunc(16, updateRain, 0); // ~60 FPS
}

//OB43
void drawRainfall() {
    glColor3f(0.3f, 0.4f, 0.3f); // Rain color (light blue)
    glBegin(GL_LINES);
    for (int i = 0; i < totalDrops; i++) {
        glVertex2f(dropX[i], dropY[i]);
        glVertex2f(dropX[i], dropY[i] - 20); // Line length
    }
    glEnd();
}










void display() {

    //loadImageAndStore("C:/Users/LAP AID D/Pictures/bg.bmp");

    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);

glClearColor(0.4f, 0.7f, 0.9f, 1.0f);



    Land();


    sky();
    sun();

   backgroundmountain();
   tree3(0,0,0);
   tree3(-30,0,0);
   tree3(60,0,0);
   tree3(60,25,0);
   tree3(120,0,0);
   tree3(120,30,0);
   tree3(180,0,0);
   tree3(180,20,0);
   tree3(240,0,0);
   tree3(300,0,0);
   tree3(360,0,0);
   tree3(420,0,0);
   tree3(480,0,0);
   tree3(540,0,0);
   tree3(600,0,0);
   tree3(660,0,0);
   tree3(720,0,0);
   tree3(780,0,0);
   tree3(840,0,0);
   tree3(900,0,0);
   tree3(960,0,0);
   tree3(1020,0,0);
   tree3(1080,0,0);
   tree3(1120,0,0);

   tree3detailing(0,0,0);
   tree3detailing(3,-3,0);
   tree3detailing(6,-6,0);
   tree3detailing(50,0,0);
   tree3detailing(50,-3,0);
   tree3detailing(50,-6,0);
   tree3detailing(50,-9,0);
   tree3detailing(50,-12,0);
   tree3detailing(100,0,0);
   tree3detailing(100,-3,0);
   tree3detailing(100,-6,0);
   tree3detailing(150,0,0);
   tree3detailing(150,-3,0);
   tree3detailing(200,0,0);
   tree3detailing(200,-3,0);
   tree3detailing(200,-6,0);
   tree3detailing(250,0,0);
   tree3detailing(250,-3,0);
   tree3detailing(250,-6,0);
   tree3detailing(250,-9,0);
   tree3detailing(300,0,0);
   tree3detailing(300,-3,0);
   tree3detailing(300,-6,0);
   tree3detailing(350,0,0);
   tree3detailing(350,-3,0);
   tree3detailing(350,-6,0);
   tree3detailing(400,0,0);
   tree3detailing(400,-3,0);
   tree3detailing(400,-6,0);
   tree3detailing(400,-9,0);
   tree3detailing(400,3,0);
   tree3detailing(450,0,0);
   tree3detailing(450,-3,0);
   tree3detailing(450,-6,0);
   tree3detailing(500,0,0);
   tree3detailing(500,-3,0);
   tree3detailing(500,-6,0);
   tree3detailing(500,-9,0);
   tree3detailing(500,-12,0);
   tree3detailing(550,0,0);
   tree3detailing(550,3,0);
   tree3detailing(550,-3,0);
   tree3detailing(550,-6,0);
   tree3detailing(550,-9,0);
   tree3detailing(550,-12,0);
   tree3detailing(550,-15,0);
   tree3detailing(600,0,0);
   tree3detailing(600,-3,0);
   tree3detailing(600, -6, 0);
tree3detailing(650, 0, 0);
tree3detailing(650, -3, 0);
tree3detailing(650, -6, 0);
tree3detailing(700, 0, 0);
tree3detailing(700, -3, 0);
tree3detailing(700, -9, 0);
tree3detailing(750, 0, 0);
tree3detailing(750, -3, 0);
tree3detailing(750, -6, 0);
tree3detailing(800, 0, 0);
tree3detailing(800, -3, 0);
tree3detailing(800, -6, 0);
tree3detailing(800, -9, 0);
tree3detailing(850, 0, 0);
tree3detailing(850, -3, 0);
tree3detailing(850, -6, 0);
tree3detailing(850, -9, 0);
tree3detailing(850, -12, 0);
tree3detailing(900, 0, 0);
tree3detailing(900, -3, 0);
tree3detailing(900, -6, 0);
tree3detailing(900, -9, 0);
tree3detailing(950, 0, 0);
tree3detailing(950, -3, 0);
tree3detailing(950, -6, 0);
tree3detailing(1000, 0, 0);
tree3detailing(1000, -3, 0);
tree3detailing(1000, -6, 0);
tree3detailing(1000, -9, 0);
tree3detailing(1050, 0, 0);
tree3detailing(1050, -3, 0);
tree3detailing(1050, -6, 0);
tree3detailing(1050, -9, 0);
tree3detailing(1050, -12, 0);
tree3detailing(1100, 0, 0);
tree3detailing(1100, -3, 0);
tree3detailing(1100, -6, 0);
tree3detailing(1150, 0, 0);
tree3detailing(1150, 3, 0);
tree3detailing(1150, -3, 0);
tree3detailing(1200, 0, 0);
tree3detailing(1250, 0, 0);






   Cloud2(cloudX,0,0);
   Cloud2(-cloudX,-60,0);

   Cloud3(cloudX - 300, 70, 0);
   Cloud3(cloudX +200, 100, 0);
   Cloud3(cloudX +400, 150, 0);
   Cloud3(cloudX +470, 150, 0);
   Cloud3(cloudX +450, 170, 0);



   river();
   wave7();
   boat27();
   Mountain();

    glPopMatrix();
   Tress(0,0,0);
   Tress(50,0,0);
   Tress(-50,0,0);
   Tress(-100,0,0);

   Tress(-200,0,0);
   Tress(-200,-100,0);
   Tress(200,20,0);
   Tress(-300,0,0);
   Tress(-300,100,0);

    Tress(-300,150,0);
    Tress(-150,150,0);
    Tress(-150,180,0);
    Tress(-150,210,0);
    Tress(-150,260,0);
    Tress(-300,300,0);
    Tress(-250,370,0);


   tree2(0,0,0,1,1,1);
   tree2(30,-240,0,1,1,1);
   tree2(200,-200,0,1,1,1);
   tree2(350,-200,0,1,1,1);
   tree2(320,-100,0,1,1,1);

   tree2(150,300,0,0.7,0.7,1);
   tree2(200,300,0,0.7,0.7,1);
   tree2(250,400,0,0.6,0.6,1);
   tree2(300,500,0,0.5,0.5,1);
   tree2(250,250,0,0.7,0.7,1);
   tree2(320,250,0,0.7,0.7,1);
   tree2(250,200,0,0.7,0.7,1);
   tree2(350,200,0,0.7,0.7,1);

   /*tree2(20,0,0);
   tree2(40,0,0);
   tree2(20,20,0);

   tree2(60,60,0);
   tree2(80,60,0);
   tree2(100,60,0);
   tree2(80,80,0);

   tree2(120,120,0);
   tree2(140,120,0);
   tree2(160,120,0);
   tree2(140,140,0);


   tree2(200,200,0);*/


   Cloud1(0,0,0);
   Cloud1(180,0,0);
    Cloud1(360,0,0);
    Cloud1(300,-20,0);
     Cloud1(540,0,0);






  for (int i = 0; i < NUM_BIRDS; i++) {
    AnimatedBird(birdX[i], birdY[i], 0.6, wingAngle[i]);  // Smaller birds
}



  /* river();
   wave7();
   boat27();*/
   pilar_Shadow();

   /*train_tier(0,0,0);
   train_tier(-100,0,0);
   train_tier(-200,0,0);
   train_tier(-300,0,0);
   train_tier(-400,0,0);
   train_tier(-500,0,0);*/



    Land2();
    Left_tree(0,100,0);

    Left_tree(100,120,0);
    Left_tree(100,200,0);
    Left_tree(100,280,0);


    //Right_side







    Train();

  /*  bogi(0,0,0);
    bogi(-105,0,0);
    bogi(-205,0,0);
    bogi(-310,0,0);
    bogi(-410,0,0);
    bogi(-515,0,0);*/





    Bridge();
    bridge_structure(0,0,0);
    bridge_structure(640,0,0);
    bridge_structure(1280,0,0);




    Left_tree(-1700,30,0);
    Left_tree(-1600,0,0);

    left_tree2(-1100,-110,0);
    left_tree2(-1300,-100,0);
    left_tree2(-1200,-105,0);

    Clock_Tower();
    Draw_Clock_Hands();
    clk_tower_Detail(0,0,0);
    clk_tower_Detail(0,-110,0);
    clk_tower_Detail(0,-220,0);
    Left_tree(0,0,0);

left_tree2(150,-90,0);



    left_tree2(200,-90,0);

    left_tree2(300,-100,0);
    left_tree2(400,-110,0);
    left_tree2(480,-110,0);

    left_tree2(50,-105,0);



    roadp();
    road_piller(0,0,0);
    road_piller(25,0,0);
    road_piller(50,0,0);
    road_piller(75,0,0);
    road_piller(100,0,0);

    road_piller(125,0,0);
    road_piller(150,0,0);
    road_piller(175,0,0);
    road_piller(200,0,0);
    road_piller(225,0,0);
    road_piller(250,0,0);
    road_piller(275,0,0);
    road_piller(300,0,0);
    road_piller(325,0,0);
    road_piller(350,0,0);
    road_piller(375,0,0);
    road_piller(400,0,0);
    road_piller(425,0,0);
    road_piller(450,0,0);
    road_piller(475,0,0);
    road_piller(500,0,0);
    road_piller(525,0,0);
    road_piller(550,0,0);
    road_piller(575,0,0);
    road_piller(600,0,0);
    road_piller(625,0,0);
    road_piller(650,0,0);
    road_piller(675,0,0);
    road_piller(700,0,0);
    road_piller(725,0,0);
    road_piller(750,0,0);
    road_piller(775,0,0);
    road_piller(800,0,0);
    road_piller(825,0,0);
    road_piller(850, 0, 0);
road_piller(875, 0, 0);
road_piller(900, 0, 0);
road_piller(925, 0, 0);
road_piller(950, 0, 0);
road_piller(975, 0, 0);
road_piller(1000, 0, 0);
road_piller(1025, 0, 0);
road_piller(1050, 0, 0);
road_piller(1075, 0, 0);
road_piller(1100, 0, 0);
road_piller(1125, 0, 0);
road_piller(1150, 0, 0);
road_piller(1175, 0, 0);
road_piller(1200, 0, 0);
road_piller(1225, 0, 0);
road_piller(1250, 0, 0);
road_piller(1275, 0, 0);
road_piller(1300, 0, 0);
road_piller(1325, 0, 0);
road_piller(1350, 0, 0);
road_piller(1375, 0, 0);
road_piller(1400, 0, 0);
road_piller(1425, 0, 0);
road_piller(1450, 0, 0);
road_piller(1475, 0, 0);
road_piller(1500, 0, 0);
road_piller(1525, 0, 0);
road_piller(1550, 0, 0);
road_piller(1575, 0, 0);
road_piller(1600, 0, 0);
road_piller(1625, 0, 0);
road_piller(1650, 0, 0);
road_piller(1675, 0, 0);
road_piller(1700, 0, 0);
road_piller(1725, 0, 0);
road_piller(1750, 0, 0);
road_piller(1775, 0, 0);
road_piller(1800, 0, 0);
road_piller(1825, 0, 0);
road_piller(1850, 0, 0);
road_piller(1875, 0, 0);
road_piller(1900, 0, 0);

road_piller2(0,0,0);
road_piller2(100, 0, 0);
road_piller2(200, 0, 0);
road_piller2(300, 0, 0);
road_piller2(400, 0, 0);
road_piller2(500, 0, 0);
road_piller2(600, 0, 0);
road_piller2(700, 0, 0);
road_piller2(800, 0, 0);
road_piller2(900, 0, 0);
road_piller2(1000, 0, 0);
road_piller2(1100, 0, 0);
road_piller2(1200, 0, 0);
road_piller2(1300, 0, 0);
road_piller2(1400, 0, 0);
road_piller2(1500, 0, 0);
road_piller2(1600, 0, 0);
road_piller2(1700, 0, 0);
road_piller2(1800, 0, 0);
road_piller2(1880,0,0);

bus7();
cargo_Truck(cargoPosition3,20,0);
car7777777();
car888(213, 154, 8);

    //car7();
    //micro7();







    //drawRainfall();

    glutSwapBuffers();
}





void display2(){

     glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);


glClearColor(0.4f, 0.7f, 0.9f, 1.0f);


    Land();


    sky2();


   backgroundmountain();
   tree3(0,0,0);
   tree3(-30,0,0);
   tree3(60,0,0);
   tree3(60,25,0);
   tree3(120,0,0);
   tree3(120,30,0);
   tree3(180,0,0);
   tree3(180,20,0);
   tree3(240,0,0);
   tree3(300,0,0);
   tree3(360,0,0);
   tree3(420,0,0);
   tree3(480,0,0);
   tree3(540,0,0);
   tree3(600,0,0);
   tree3(660,0,0);
   tree3(720,0,0);
   tree3(780,0,0);
   tree3(840,0,0);
   tree3(900,0,0);
   tree3(960,0,0);
   tree3(1020,0,0);
   tree3(1080,0,0);
   tree3(1120,0,0);

   tree3detailing(0,0,0);
   tree3detailing(3,-3,0);
   tree3detailing(6,-6,0);
   tree3detailing(50,0,0);
   tree3detailing(50,-3,0);
   tree3detailing(50,-6,0);
   tree3detailing(50,-9,0);
   tree3detailing(50,-12,0);
   tree3detailing(100,0,0);
   tree3detailing(100,-3,0);
   tree3detailing(100,-6,0);
   tree3detailing(150,0,0);
   tree3detailing(150,-3,0);
   tree3detailing(200,0,0);
   tree3detailing(200,-3,0);
   tree3detailing(200,-6,0);
   tree3detailing(250,0,0);
   tree3detailing(250,-3,0);
   tree3detailing(250,-6,0);
   tree3detailing(250,-9,0);
   tree3detailing(300,0,0);
   tree3detailing(300,-3,0);
   tree3detailing(300,-6,0);
   tree3detailing(350,0,0);
   tree3detailing(350,-3,0);
   tree3detailing(350,-6,0);
   tree3detailing(400,0,0);
   tree3detailing(400,-3,0);
   tree3detailing(400,-6,0);
   tree3detailing(400,-9,0);
   tree3detailing(400,3,0);
   tree3detailing(450,0,0);
   tree3detailing(450,-3,0);
   tree3detailing(450,-6,0);
   tree3detailing(500,0,0);
   tree3detailing(500,-3,0);
   tree3detailing(500,-6,0);
   tree3detailing(500,-9,0);
   tree3detailing(500,-12,0);
   tree3detailing(550,0,0);
   tree3detailing(550,3,0);
   tree3detailing(550,-3,0);
   tree3detailing(550,-6,0);
   tree3detailing(550,-9,0);
   tree3detailing(550,-12,0);
   tree3detailing(550,-15,0);
   tree3detailing(600,0,0);
   tree3detailing(600,-3,0);
   tree3detailing(600, -6, 0);
tree3detailing(650, 0, 0);
tree3detailing(650, -3, 0);
tree3detailing(650, -6, 0);
tree3detailing(700, 0, 0);
tree3detailing(700, -3, 0);
tree3detailing(700, -9, 0);
tree3detailing(750, 0, 0);
tree3detailing(750, -3, 0);
tree3detailing(750, -6, 0);
tree3detailing(800, 0, 0);
tree3detailing(800, -3, 0);
tree3detailing(800, -6, 0);
tree3detailing(800, -9, 0);
tree3detailing(850, 0, 0);
tree3detailing(850, -3, 0);
tree3detailing(850, -6, 0);
tree3detailing(850, -9, 0);
tree3detailing(850, -12, 0);
tree3detailing(900, 0, 0);
tree3detailing(900, -3, 0);
tree3detailing(900, -6, 0);
tree3detailing(900, -9, 0);
tree3detailing(950, 0, 0);
tree3detailing(950, -3, 0);
tree3detailing(950, -6, 0);
tree3detailing(1000, 0, 0);
tree3detailing(1000, -3, 0);
tree3detailing(1000, -6, 0);
tree3detailing(1000, -9, 0);
tree3detailing(1050, 0, 0);
tree3detailing(1050, -3, 0);
tree3detailing(1050, -6, 0);
tree3detailing(1050, -9, 0);
tree3detailing(1050, -12, 0);
tree3detailing(1100, 0, 0);
tree3detailing(1100, -3, 0);
tree3detailing(1100, -6, 0);
tree3detailing(1150, 0, 0);
tree3detailing(1150, 3, 0);
tree3detailing(1150, -3, 0);
tree3detailing(1200, 0, 0);
tree3detailing(1250, 0, 0);










   river();
   wave7();
   boat27();
   Mountain();

    glPopMatrix();
   Tress(0,0,0);
   Tress(50,0,0);
   Tress(-50,0,0);
   Tress(-100,0,0);

   Tress(-200,0,0);
   Tress(-200,-100,0);
   Tress(200,20,0);
   Tress(-300,0,0);
   Tress(-300,100,0);

    Tress(-300,150,0);
    Tress(-150,150,0);
    Tress(-150,180,0);
    Tress(-150,210,0);
    Tress(-150,260,0);
    Tress(-300,300,0);
    Tress(-250,370,0);


   tree2(0,0,0,1,1,1);
   tree2(30,-240,0,1,1,1);
   tree2(200,-200,0,1,1,1);
   tree2(350,-200,0,1,1,1);
   tree2(320,-100,0,1,1,1);

   tree2(150,300,0,0.7,0.7,1);
   tree2(200,300,0,0.7,0.7,1);
   tree2(250,400,0,0.6,0.6,1);
   tree2(300,500,0,0.5,0.5,1);
   tree2(250,250,0,0.7,0.7,1);
   tree2(320,250,0,0.7,0.7,1);
   tree2(250,200,0,0.7,0.7,1);
   tree2(350,200,0,0.7,0.7,1);

   /*tree2(20,0,0);
   tree2(40,0,0);
   tree2(20,20,0);

   tree2(60,60,0);
   tree2(80,60,0);
   tree2(100,60,0);
   tree2(80,80,0);

   tree2(120,120,0);
   tree2(140,120,0);
   tree2(160,120,0);
   tree2(140,140,0);


   tree2(200,200,0);*/









  for (int i = 0; i < NUM_BIRDS; i++) {
    AnimatedBird(birdX[i], birdY[i], 0.6, wingAngle[i]);  // Smaller birds
}



  /* river();
   wave7();
   boat27();*/
   pilar_Shadow();

   /*train_tier(0,0,0);
   train_tier(-100,0,0);
   train_tier(-200,0,0);
   train_tier(-300,0,0);
   train_tier(-400,0,0);
   train_tier(-500,0,0);*/



    Land2();
    Left_tree(0,100,0);

    Left_tree(100,120,0);
    Left_tree(100,200,0);
    Left_tree(100,280,0);


    //Right_side







    Train();

  /*  bogi(0,0,0);
    bogi(-105,0,0);
    bogi(-205,0,0);
    bogi(-310,0,0);
    bogi(-410,0,0);
    bogi(-515,0,0);*/





    Bridge();
    bridge_structure(0,0,0);
    bridge_structure(640,0,0);
    bridge_structure(1280,0,0);




    Left_tree(-1700,30,0);
    Left_tree(-1600,0,0);

    left_tree2(-1100,-110,0);
    left_tree2(-1300,-100,0);
    left_tree2(-1200,-105,0);

    Clock_Tower();
    Draw_Clock_Hands();
    clk_tower_Detail(0,0,0);
    clk_tower_Detail(0,-110,0);
    clk_tower_Detail(0,-220,0);
    Left_tree(0,0,0);

left_tree2(150,-90,0);



    left_tree2(200,-90,0);

    left_tree2(300,-100,0);
    left_tree2(400,-110,0);
    left_tree2(480,-110,0);

    left_tree2(50,-105,0);



    roadp();
    road_piller(0,0,0);
    road_piller(25,0,0);
    road_piller(50,0,0);
    road_piller(75,0,0);
    road_piller(100,0,0);

    road_piller(125,0,0);
    road_piller(150,0,0);
    road_piller(175,0,0);
    road_piller(200,0,0);
    road_piller(225,0,0);
    road_piller(250,0,0);
    road_piller(275,0,0);
    road_piller(300,0,0);
    road_piller(325,0,0);
    road_piller(350,0,0);
    road_piller(375,0,0);
    road_piller(400,0,0);
    road_piller(425,0,0);
    road_piller(450,0,0);
    road_piller(475,0,0);
    road_piller(500,0,0);
    road_piller(525,0,0);
    road_piller(550,0,0);
    road_piller(575,0,0);
    road_piller(600,0,0);
    road_piller(625,0,0);
    road_piller(650,0,0);
    road_piller(675,0,0);
    road_piller(700,0,0);
    road_piller(725,0,0);
    road_piller(750,0,0);
    road_piller(775,0,0);
    road_piller(800,0,0);
    road_piller(825,0,0);
    road_piller(850, 0, 0);
road_piller(875, 0, 0);
road_piller(900, 0, 0);
road_piller(925, 0, 0);
road_piller(950, 0, 0);
road_piller(975, 0, 0);
road_piller(1000, 0, 0);
road_piller(1025, 0, 0);
road_piller(1050, 0, 0);
road_piller(1075, 0, 0);
road_piller(1100, 0, 0);
road_piller(1125, 0, 0);
road_piller(1150, 0, 0);
road_piller(1175, 0, 0);
road_piller(1200, 0, 0);
road_piller(1225, 0, 0);
road_piller(1250, 0, 0);
road_piller(1275, 0, 0);
road_piller(1300, 0, 0);
road_piller(1325, 0, 0);
road_piller(1350, 0, 0);
road_piller(1375, 0, 0);
road_piller(1400, 0, 0);
road_piller(1425, 0, 0);
road_piller(1450, 0, 0);
road_piller(1475, 0, 0);
road_piller(1500, 0, 0);
road_piller(1525, 0, 0);
road_piller(1550, 0, 0);
road_piller(1575, 0, 0);
road_piller(1600, 0, 0);
road_piller(1625, 0, 0);
road_piller(1650, 0, 0);
road_piller(1675, 0, 0);
road_piller(1700, 0, 0);
road_piller(1725, 0, 0);
road_piller(1750, 0, 0);
road_piller(1775, 0, 0);
road_piller(1800, 0, 0);
road_piller(1825, 0, 0);
road_piller(1850, 0, 0);
road_piller(1875, 0, 0);
road_piller(1900, 0, 0);

road_piller2(0,0,0);
road_piller2(100, 0, 0);
road_piller2(200, 0, 0);
road_piller2(300, 0, 0);
road_piller2(400, 0, 0);
road_piller2(500, 0, 0);
road_piller2(600, 0, 0);
road_piller2(700, 0, 0);
road_piller2(800, 0, 0);
road_piller2(900, 0, 0);
road_piller2(1000, 0, 0);
road_piller2(1100, 0, 0);
road_piller2(1200, 0, 0);
road_piller2(1300, 0, 0);
road_piller2(1400, 0, 0);
road_piller2(1500, 0, 0);
road_piller2(1600, 0, 0);
road_piller2(1700, 0, 0);
road_piller2(1800, 0, 0);
road_piller2(1880,0,0);

bus7();
cargo_Truck(cargoPosition3,20,0);
car7777777();
car888(213, 154, 8);



    drawRainfall();

    //--------------------------------------------------------------------------------

// Enable blending for transparency
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

// Switch to 2D projection
glMatrixMode(GL_PROJECTION);
glPushMatrix();
glLoadIdentity();
gluOrtho2D(0, 1900, 0, 1000);  // Match your window's coordinate system

glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glLoadIdentity();

// Draw semi-transparent dark overlay
glColor4f(0.0f, 0.0f, 0.0f, 0.3f);  // 25% opacity black for rain shadow
glBegin(GL_QUADS);
glVertex2f(0, 0);
glVertex2f(1900, 0);
glVertex2f(1900, 1000);
glVertex2f(0, 1000);
glEnd();

// Restore matrices
glPopMatrix();
glMatrixMode(GL_PROJECTION);
glPopMatrix();
glMatrixMode(GL_MODELVIEW);

glDisable(GL_BLEND);












    //----------------------------------------------------------------------------------

    glutSwapBuffers();

}
/*

//mouse
void handleMouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            train_speed += 1.0f; // Increase speed
        } else if (button == GLUT_RIGHT_BUTTON) {
            train_speed -= 1.0f; // Decrease speed
            if (train_speed < 0) train_speed = 0; // Prevent negative speed
        }
    }
}


//keyboard

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'a':
    glutDisplayFunc(display);
    glutPostRedisplay();
    break;
case 'r':
    glutDisplayFunc(display2);
    glutPostRedisplay();
break;

case 'b':
case 'B':
            isBusMoving = !isBusMoving;
    break;
	}}





	//new

void specialKeys(int key, int x, int y) {
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








int main(int argc, char** argv) {
    glutInit(&argc, argv);
    // enable doublebuffering and RGB
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1900, 1000);
    glutCreateWindow("Train view");

    // set up orthographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1900,0,1000);
//loadImageAndStore("C:/Users/LAP AID D/Pictures/bg.bmp");
       // loadImageAndStore("C:/Users/LAP AID D/Pictures/bg.bmp");


    // optional: choose a background color (light blue sky)
    glClearColor(0.4f, 0.7f, 0.9f, 1.0f);

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

   // glutTimerFunc(0, updateFlood, 0);



loadImageAndStore("C:/Users/LAP AID D/Pictures/bg.bmp");

loadImageAndStore("C:/Users/LAP AID D/Pictures/bg6.bmp");

    // register your display callback
    glutDisplayFunc(display2);
    glutDisplayFunc(display);

       glutKeyboardFunc(handleKeypress);
       glutMouseFunc(handleMouse);

       glutSpecialFunc(specialKeys);



    glutMainLoop();
    return 0;
}

*/








