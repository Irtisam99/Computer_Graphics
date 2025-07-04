#include<windows.h>
#include<iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <cmath>
#include<cstdio>
#include "glutil.h"
#include <mmsystem.h> // for sound functions
bool lightsOn = true;  // initially ON in night mode

bool isRed = true;
bool signboardToggleEnabled = true;
bool day=true;

float _move=0.0f;
float train_move=0.0f;
float train_speeda = 5.0f;  // initial speed
const float MAX_SPEED = 20.0f;
const float MIN_SPEED = 0.0f;

float boat_move1=0.0f;
float boat1_speeda = 2.5f;
const float boat1_min_speeda = 0.0f;
const float boat1_max_speeda = 16.0f;
float boat_move2=150.0f;

float plane_move=-800.0f;
float plane_y_offset = 0.0f;
float plane_speed = 4.0f;
float plane_min_speed = 4.0f;
float plane_max_speed = 15.0f;




float bus1_move=100.0f;
float bus1_speed = 7.0f;  // Initial movement speed

float car2_movea=-1800.0f;
bool manualCar2Control = false;
//float car2_movea = 0.0f;  // Already exists
float car2_y = 0.0f;      // For vertical manual movement
float car2_speeda = 7.0f; // Speed used only for car2 manual/auto motion
float car2_y_min = -22.0f;  // Lower limit (not below road)
float car2_y_max = 60.0f;  // Upper limit (enough to go slightly above normal)

float bus2_move=1000.0f;

float bus2_speed = 5.0f;       // Initial speed
float bus2_min_speed = 0.0f;
float bus2_max_speed = 20.0f;



//float pickup_move=900.0f;
//float car1_move=900.0f;



float pickup_move = 800.0f;
float car1_move = 1000.0f;

bool paused = false;

float speed = 5.0f;
const float speed_step = 1.0f;
const float speed_min = 1.0f;
const float speed_max = 15.0f;





//83
void renderText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);  // Render each character
    }
}





void trainwindowdoor(float x,float y,float z);
void trainwindowdoor1(float x,float y,float z);
void trainwindowdoor2(float x,float y,float z);
void trainwindowdoor3(float x,float y,float z);
void trainwindowdoor4(float x,float y,float z);
void trainwheels(float x,float y,float z);
void bus1allwindows(float x,float y,float z);
void bus1wheels(float x,float y,float z);
void pickupwheels(float x,float y,float z);
void roadlines(float x,float y,float z,float a,float b,float c);
void car1wheelsa(float x,float y,float z);
void planewindows(float x,float y,float z);
void callinglightposts(float x,float y,float z);
void callingtrees(float x, float y, float z);
void callingbenches(float x,float y,float z);
void callsmalllights(float x,float y,float z);
void b2windows(float x,float y,float z);
void b2windows2(float x,float y,float z);
void b13windows(float x,float y,float z);
void b12windows(float x,float y,float z);
void b12windows1(float x,float y,float z);
void b12windows2(float x,float y,float z);
void b12windows3(float x,float y,float z);
void b11windows(float x,float y,float z);
void b10windows(float x,float y,float z);
void b10windows1(float x,float y,float z);
void b9windows(float x,float y,float z);
void b9windows1(float x,float y,float z);
void b8windows(float x,float y,float z);
void b7windows(float x,float y,float z);
void b7windows1(float x,float y,float z);
void b7windows2(float x,float y,float z);
void b6windows(float x,float y,float z);
void b6windows1(float x,float y,float z);
void b6windows2(float x,float y,float z);
void b5windows(float x,float y,float z);
void b4windows(float x,float y,float z);
void b4windows1(float x,float y,float z);
void b3windows(float x,float y,float z);
void b3windows1(float x,float y,float z);
void b3windows2(float x,float y,float z);
void b1windows(float x,float y,float z);
void b1windows1(float x,float y,float z);

























//1
void background(){
glColor3d(1.0,1.0,1.0);
glBegin(GL_QUADS);            // These vertices form a closed polygon

	glVertex2f(0,1000);
	glVertex2f(0,400);
	glVertex2f(1900,400);
	glVertex2f(1900,1000);

	glEnd();
	ApplyTexture(0,400,1900,400,1900,1000,0,1000,textures[0].textureID);


}
//2
void background1(){
glColor3d(1.0,1.0,1.0);
glBegin(GL_QUADS);            // These vertices form a closed polygon

	glVertex2f(0,1000);
	glVertex2f(0,400);
	glVertex2f(1900,400);
	glVertex2f(1900,1000);

	glEnd();
	ApplyTexture(0,400,1900,400,1900,1000,0,1000,textures[1].textureID);


}
//3
void greenfeild(){

    glBegin(GL_POLYGON);            // These vertices form a closed polygon

	glColor3ub(57,125,78);
		glVertex2f(0, 370);

	glVertex2f(0,331.68048659);
    glVertex2f(13.6547616887508, 331.1108076889794);
    glVertex2f(33.4341969523194, 330.3426742806844);
	glVertex2f(50.1724713762071, 330.6720718182807);
	glVertex2f(648.1480906841022, 329.1412297976434);
    glVertex2f(772.7683285435631, 328.8709268261624);
    glVertex2f(939.9132133969543, 332.4831664434845);
	glVertex2f(1021.2496484931572, 335.7303121428853);

	glVertex2f(1045.8724166362651, 337.9341684189154);
    glVertex2f(1069.434241062542, 339.6649442843227);
    glVertex2f(1089.1533412040985, 342.4905890616166);
	glVertex2f(1104.0199134989048, 345.1986518741493);
	glVertex2f(1118.2000391978136, 349.0030758421551);
    glVertex2f(1128.7179856660528, 352.7187657840127);
    glVertex2f(1136.4338468646727, 358.060515844604);
	glVertex2f(1140.1774220484788, 363.8259147870796);
glVertex2f(1140, 370);
	glVertex2f(0, 370);



glEnd();




glBegin(GL_POLYGON);            // These vertices form a closed polygon

	glColor3ub(128, 165, 83);
	glVertex2f(0,476.1049);
    glVertex2f(1191.0495227353013, 478.2668855212197);
    glVertex2f(1261.548943036393, 474.4490371649501);
	glVertex2f(1291.7222393219977, 470.3650586960553);
	glVertex2f(1308.218719687307, 464.4538198984862);
    glVertex2f(1317.154313218516, 455.3807556975661);
    glVertex2f(1317.8416665670707, 446.445162166357);
	glVertex2f(1301.0702448623397, 437.6470393048588);

    	glVertex2f(1282.8758045920458, 434.523821081577);
	glVertex2f(1254.3084052453858, 432.6636183334223);
	glVertex2f(1222.4831719413023, 429.5352319605888);
	glVertex2f(1192.5567304510653, 427.7485787372911);
	glVertex2f(1159.0569825142327, 426.8552521256422);
	glVertex2f(1073.3622417507256, 424.2776767211595);
	glVertex2f(1070.4854821007405, 424.2019725198441);
		glVertex2f(1068.1561237655553, 423.2047716256266);
		glVertex2f(1066.0946384244476, 421.7794380777514);
	glVertex2f(1064.5153865035352, 419.7662975448297);
		glVertex2f(1064.7822882846401, 417.1131225344239);
		glVertex2f(1065.6765213007304, 415.287476745107);
	glVertex2f(1066.7402814969919, 413.4961389269061);
	glVertex2f(1068.5412449226571, 411.8381156493178);
	glVertex2f(1070, 410);
	glVertex2f(1071.9906060184464, 407.6287258375073);
	glVertex2f(1074.4262823834788, 404.7988221343024);
	glVertex2f(1076.9015607988922, 402.7177710570616);
	glVertex2f(1080.1170669051364, 400.7884673933152);
	glVertex2f(1083.9172104852432, 399.1514824664999);
	glVertex2f(1087.6588903179638, 398.1575987609335);
	glVertex2f(1090.8096000625694, 397.1128212478154);
	glVertex2f(1095.1360646015412, 395.6938523406421);
	glVertex2f(1100.2953015678315, 393.9104124016776);
	glVertex2f(1106.7979121188307, 391.5438458445761);
	glVertex2f(1112.8254901256507, 389.3182785805195);
	glVertex2f(1119.2239960098132, 386.3508555617773);
	glVertex2f(1124.416986292612, 383.3834325430352);
	glVertex2f(1129.2578481709756, 380.8510152883143);
	glVertex2f(1133.487131300694, 378.1000822128212);
	glVertex2f(1136.9940060019335, 375.1171571312515);
	glVertex2f(1139.0631562270191, 372.4367658370506);
	glVertex2f(1140, 370);
	glVertex2f(1136.7841648722203, 366.1424087618925);
	glVertex2f(1132.423313750889, 362.8934948149096);
	glVertex2f(1127.7422839974995, 360.1507494744251);
	glVertex2f(1121.6711538673408, 358.0528219166013);
	glVertex2f(1116.2919400471299, 355.9928081332088);
	glVertex2f(1107.4756127717405, 354.4948101438403);
	glVertex2f(1098.3715265025412, 353.0297847671875);

		glVertex2f(1088.1502960994007, 351.462322752029);
		glVertex2f(1075.3214485194057, 349.3716743049707);
		glVertex2f(1060.057365276139, 347.5060641307937);
		glVertex2f(1046.5753021672747, 345.6503233369143);
	glVertex2f(1000.0971780760502, 343.6062824822878);
	glVertex2f(874.5837777890549, 339.9555962938081);
	glVertex2f(712.8943717422402, 338.5289155374646);

		glVertex2f(639.4388696923827, 337.2246754723528);

			glVertex2f(58.6550463498257, 336.9315884545731);
	glVertex2f(0,340.681605);
	glVertex2f(0,476.1049);

glEnd();


glBegin(GL_POLYGON);
glColor3ub(128, 165, 83);
    glVertex2f(1900,420);
    glVertex2f(1722.834918709402, 420);
	glVertex2f(1717.4029036079994, 430);
	glVertex2f(1711.5652881018495, 437.7580866377043);
	glVertex2f(1716.8228879283113, 444.6744125909142);
	glVertex2f(1728.2377715336197, 447.150013392611);
glVertex2f(1741.468537320611, 447.6646064565069);
glVertex2f(1900,447.8143278);


	glEnd();

glBegin(GL_POLYGON);
glColor3ub(48, 117, 77);
    glVertex2f(1900,420);
    glVertex2f(1722.834918709402, 420);
	glVertex2f(1717.4029036079994, 430);
	glVertex2f(1900, 430);
	glEnd();
glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(128, 165, 83);
	glVertex2f(0,500);
	glVertex2f(0,476.1049894518171);
	glVertex2f(1191.0495227353013,476.1049894518171);
    glVertex2f(1200.4489388488616, 500);

    glEnd();


    glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(128, 165, 83);
	glVertex2f(1197.8913873064766, 498.9282375703421);
	glVertex2f(1190.0524632686322, 478.5397397762544);
	glVertex2f(1900, 478.5397397762544);
    glVertex2f(1900, 498.9282375703421);

    glEnd();

    glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(128, 165, 83);
	glVertex2f(1740.1414068665922, 447.1329584264258);
	glVertex2f(1713.3954605185438, 499.3533247846097);
	glVertex2f(1900, 499.3533247846097);
    glVertex2f(1900, 447.1329584264258);

    glEnd();



}
//4
void lake(){
glBegin(GL_POLYGON);            // These vertices form a closed polygon

	glColor3ub(84, 172, 151);
	glVertex2f(1263.3997098297214, 478.6178071424956);
    glVertex2f(1261.548943036393, 474.4490371649501);
	glVertex2f(1291.7222393219977, 470.3650586960553);
	glVertex2f(1308.218719687307, 464.4538198984862);
    glVertex2f(1317.154313218516, 455.3807556975661);
    glVertex2f(1317.8416665670707, 446.445162166357);
	glVertex2f(1301.0702448623397, 437.6470393048588);

    	glVertex2f(1282.8758045920458, 434.523821081577);
	glVertex2f(1254.3084052453858, 432.6636183334223);
	glVertex2f(1222.4831719413023, 429.5352319605888);
	glVertex2f(1192.5567304510653, 427.7485787372911);
	glVertex2f(1159.0569825142327, 426.8552521256422);
		glVertex2f(1068.1561237655553, 423.2047716256266);
	glVertex2f(1064.5153865035352, 419.7662975448297);



		glVertex2f(1064.7822882846401, 417.1131225344239);
	glVertex2f(1066.7402814969919, 413.4961389269061);
	glVertex2f(1074.4262823834788, 404.7988221343024);
	glVertex2f(1090.8096000625694, 397.1128212478154);
	glVertex2f(1133.487131300694, 378.1000822128212);
	glVertex2f(1140, 370);
	glVertex2f(1132.423313750889, 362.8934948149096);

		glVertex2f(1088.1502960994007, 351.462322752029);
	glVertex2f(1000.0971780760502, 343.6062824822878);
	glVertex2f(874.5837777890549, 339.9555962938081);
	glVertex2f(712.8943717422402, 338.5289155374646);

		glVertex2f(639.4388696923827, 337.2246754723528);

			glVertex2f(58.6550463498257, 336.9315884545731);
	glVertex2f(0,340.681605);
	glVertex2f(0,250);
	glVertex2f(1900,250);
	glVertex2f(1900,430);
	glVertex2f(1717.4029036079994, 430);
	glVertex2f(1711.5652881018495, 437.7580866377043);
	glVertex2f(1716.8228879283113, 444.6744125909142);
	glVertex2f(1728.2377715336197, 447.150013392611);
	glVertex2f(1741.468537320611, 447.6646064565069);
	glVertex2f(1729.1723029469736, 478.6178071424956);
	glVertex2f(1263.3997098297214, 478.6178071424956);



	glEnd();
}
//5
void road(){

glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(111,111,111);
	glVertex2f(0,180);
    glVertex2f(0,0);
    glVertex2f(1900,0);
	glVertex2f(1900,180);
glEnd();

roadlines(0,0,0,0,0,0);
roadlines(0,-80,0,0,0,0);
roadlines(0,83,0,0,0,0);



roadlines(0,0,0,233.04,0,0);
roadlines(0,0,0,466.08,0,0);
roadlines(0,0,0,699.12,0,0);
roadlines(0,0,0,932.16,0,0);
roadlines(0,0,0,1165.2,0,0);
roadlines(0,0,0,1398.24,0,0);
roadlines(0,0,0,1631.28,0,0);
roadlines(0,0,0,1864.32,0,0);



roadlines(0,0,0,0,-88.27,0);
roadlines(0,0,0,233.04,-88.27,0);
roadlines(0,0,0,466.08,-88.27,0);
roadlines(0,0,0,699.12,-88.27,0);
roadlines(0,0,0,932.16,-88.27,0);
roadlines(0,0,0,1165.2,-88.27,0);
roadlines(0,0,0,1398.24,-88.27,0);
roadlines(0,0,0,1631.28,-88.27,0);
roadlines(0,0,0,1864.32,-88.27,0);






}
//6
void roadlines(float x,float y,float z,float a,float b,float c)
{
glPushMatrix();
glTranslatef(x,y,z);
glBegin(GL_QUADS);

    glColor3ub(244,243,231);     //roadlines
	glVertex2f(0,92);
    glVertex2f(0,88);
    glVertex2f(1900,88);
	glVertex2f(1900,92);

glEnd();
	glPopMatrix();


	glPushMatrix();
glTranslatef(a,b,c);
glBegin(GL_QUADS);

    glColor3ub(244,243,231);     //roadlines
	glVertex2f(19.1674266358325, 136.1179622699692);
    glVertex2f(22.6868311908954, 142.085648254648);
    glVertex2f(154.2522573686498,  142.085648254648);
	glVertex2f(149.3266101325186, 136.1179622699692);

glEnd();
	glPopMatrix();




}
//7
void walkway(){

glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(250,234,187);
	glVertex2f(0,250);
    glVertex2f(0,193.16);
    glVertex2f(1900,193.16);
	glVertex2f(1900,250);

	glColor3ub(155,148,126);
	glVertex2f(1900,193.16);
    glVertex2f(1900,180);
    glVertex2f(0,180);
	glVertex2f(0,193.16);


	glEnd();


}
//8
void railing(float x,float y, float z){
glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(1,1,1);
	glVertex2f(0,280.35);
    glVertex2f(0,274.53);
    glVertex2f(1900,274.53);
    glVertex2f(1900,280.35);
glEnd();
 glPushMatrix();

glTranslatef(x,y,z);
glLineWidth(3);
    glBegin(GL_LINES);
	glColor3ub(1,1,1);
	glVertex2f(25.31,274.53);
	glVertex2f(25.31,249);

	glEnd();
glPopMatrix();
}

//56
void train(){

glLineWidth(3);
glBegin(GL_LINES);

glColor3ub(1,1,1);
	glVertex2f(0,476.1049894518171);
	glVertex2f(1206.0052936061404,476.1049894518171);

glEnd();
glLineWidth(2);
glBegin(GL_LINES);

glColor3ub(1,1,1);
	glVertex2f(0,485.786338554622);
	glVertex2f(1212.4906847548127, 486.2713795993388);

glEnd();

glPushMatrix();
glTranslatef(train_move,0,0);
trainwheels(0,0,0);
trainwheels(-37,0,0);
trainwheels(-74,0,0);
trainwheels(-301,0,0);
trainwheels(-338,0,0);
trainwheels(-517,0,0);
trainwheels(-554,0,0);
trainwheels(-668,0,0);
trainwheels(-705,0,0);
trainwheels(-791,0,0);
trainwheels(-828,0,0);








glBegin(GL_POLYGON);            // These vertices form a closed polygon

	glColor3ub(234, 229, 192);
	glVertex2f(63.0889231158984, 576.5262587226963);
    glVertex2f(71.6058664810465, 585.5552384331085);
    glVertex2f(1007.7314620062818, 585.5552384331085);
	glVertex2f(1016.0554146262817, 584.2141519372802);
	glVertex2f(1025.5553270957337, 577.8177659772488);
    glVertex2f(1058.4472058771455, 535.8992394026249);
    glVertex2f(1064.4772105094373, 527.1993905018567);
	glVertex2f(1067.0793978790912, 522.6455626049624);

	glVertex2f(1069.0310384063316, 517.0074899707123);
	glVertex2f(1066.4288510366778, 510.6104460203131);
	glVertex2f(1059.6767118182413, 501.3515889033258);

	glVertex2f(67.3440706461844,501.3515889033258);
	glVertex2f(62.184689814061, 506.598883380606);
    glVertex2f(62.184689814061, 576.5262587226963);
	glEnd();

glBegin(GL_POLYGON);
glColor3ub(74,152,139);
    glVertex2f(67.3440706461844,501.3515889033258);
    glVertex2f(62.184689814061, 506.598883380606);
    glVertex2f(62.184689814061,  510.6104460203131);
    glVertex2f(1066.4288510366778, 510.6104460203131);
     glVertex2f(1059.6767118182413, 501.3515889033258);
      glVertex2f(67.3440706461844,501.3515889033258);

glEnd();

glBegin(GL_QUADS);
glColor3ub(74,152,139);
    glVertex2f(62.184689814061, 515.2214378887326);
    glVertex2f(62.184689814061,  524.6396126830397);
    glVertex2f(1007.8777178734812, 524.6396126830397);
    glVertex2f(1037.198973687438, 515.2214378887326);

glEnd();
	glBegin(GL_QUADS);
	glColor3ub(29,102,97);
    glVertex2f(336.9489473671455, 500.9077975098783);
    glVertex2f(336.9489473671455, 577.2224375858912);
    glVertex2f(345.4397819954216, 577.2224375858912);
    glVertex2f(345.4397819954216, 500.9077975098783);



	glVertex2f(343.1270301026402, 586.9834319192508);
    glVertex2f(350.523387085394, 586.9834319192508);
    glVertex2f(345.4397819954216, 577.2224375858912);
   glVertex2f(336.9489473671455, 577.2224375858912);



	glEnd();

	glBegin(GL_POLYGON);

	glColor3ub(29,102,97);
    glVertex2f(1059.6767118182413, 501.3515889033258);
    glVertex2f(1056.4161363450962, 496.7406571163878);
    glVertex2f(1051.808353227804, 493.1644672343106);
    glVertex2f(1046.5128412870354, 490.4135519404051);
	glVertex2f(1041.767512405048, 488.5566841170189);
    glVertex2f(1036.74709199367, 486.9749078230233);
    glVertex2f(1031.0114095664956, 485.3475172790344);
   glVertex2f(1025.9657594897437, 484.6934515283444);
   glVertex2f(1021.37088987565, 484.5709694009948);
   glVertex2f(1003.1867538881661,484.5709694009948);
   glVertex2f(1002.0862467429291, 486.8431976597684);
   glVertex2f(1000.8471898459941, 488.4831259057121);
   glVertex2f(999.2904097819899, 490.3306584660019);
   glVertex2f(997.228018683875, 492.27226138683);
   glVertex2f(992.9874540826726, 495.1179034218473);
   glVertex2f(987.7190400594892, 497.812344336944);
   glVertex2f(983.2968533206101,501.3515889033258);




	glEnd();





glBegin(GL_QUADS);

if (day) {
    glColor3ub(29, 102, 97); // Day window color
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
        glColor3ub(29, 102, 97); // Lights OFF (dark window)
    }
}
	//glColor3ub(29,102,97);
    glVertex2f(1058.4472058771455, 535.8992394026249);
	glVertex2f(1051.6844418313622, 535.61930548691);
    glVertex2f(1028.395675963158, 566.6649245264849);
    glVertex2f(1034.374632448507, 567.4790434968871);



	glEnd();


	glBegin(GL_POLYGON);
	if (day) {
    glColor3ub(29, 102, 97); // Day window color
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
        glColor3ub(29, 102, 97); // Lights OFF (dark window)
    }
}
	//glColor3ub(29,102,97);
    glVertex2f(994.6477029700881, 537.3371106391808);
	glVertex2f(989.7275075885512, 542.5554996802044);
    glVertex2f(989.7275075885512, 563.2609216275648);
    glVertex2f(991.875122276107, 566.8596150722612);
     glVertex2f(1015.9369893794765,  566.8596150722612);
      glVertex2f(1035.8899234775492, 542.4316361407715);
       glVertex2f(1037.3193137917249, 540.4638761648694);
        glVertex2f(1037.757040475782, 538.6691967602355);
         glVertex2f(1035.8899234775492, 542.4316361407715);
          glVertex2f(1036.1720499679045,537.3371106391808);
          glVertex2f(994.6477029700881, 537.3371106391808);



	glEnd();

	glBegin(GL_POLYGON);
	if (day) {
    glColor3ub(29, 102, 97); // Day window color
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
        glColor3ub(29, 102, 97); // Lights OFF (dark window)
    }
}
	//glColor3ub(29,102,97);
    glVertex2f(938.1093305653335, 536.0730611963578);
	glVertex2f(933.1004568738157, 539.6475980420407);
    glVertex2f(933.1004568738157, 563.7666027098329);
    glVertex2f(935.9551818593536, 566.7053982872585);
     glVertex2f(968.8478586673685, 566.7053982872585);
      glVertex2f(972.2908056189817,  563.7666027098329);
       glVertex2f(972.2908056189817,  539.6475980420407);
        glVertex2f(970.1826138800703,536.0730611963578);

glEnd();
trainwindowdoor(0,0,0);
trainwindowdoor(-221,0,0);
trainwindowdoor1(-442,0,0);

trainwindowdoor2(-540,0,0);
trainwindowdoor3(-744,0,0);
trainwindowdoor4(-857,0,0);


glPopMatrix();

}



//9
void trainwindowdoor(float x,float y,float z){

glPushMatrix();
glTranslatef(x,y,z);
	glBegin(GL_POLYGON);              //door
	glColor3ub(74,152,139);
    glVertex2f(862.1835580419975, 501.0017907236453);
	glVertex2f(862.1835580419975, 566.0868767544748);
    glVertex2f(867.0213051222455, 570.9254961319955);
    glVertex2f(888.653465334353, 570.9254961319955);
     glVertex2f(892.8084351084885, 568.5606468965784);
      glVertex2f(896.9878872652338,570.9254961319955);
       glVertex2f(919.8801145417474, 570.9254961319955);
        glVertex2f(924.0425571351784, 566.0868767544748);
 glVertex2f(924.311588390152,501.0017907236453);


	glEnd();

	glBegin(GL_POLYGON);              //door
	glColor3ub(227,221,185);
    glVertex2f(864.7935434626104, 503.7678594582875);
	glVertex2f(864.7935434626104, 565.7054377136777);
    glVertex2f(866.7480943607897, 567.3792632844082);
    glVertex2f(887.9465381638403,  567.3792632844082);
     glVertex2f(890.5467291262173, 565.7054377136777);
      glVertex2f(890.5467291262173, 503.7678594582875);



	glEnd();


	glBegin(GL_POLYGON);              //door
	glColor3ub(227,221,185);
    glVertex2f(894.8051806805096, 503.7678594582875);
	glVertex2f(894.8051806805096,565.7054377136777);
    glVertex2f(896.8752315018976, 567.3792632844082);
    glVertex2f(917.871537430087,  567.3792632844082);
     glVertex2f(920.3987827229516, 565.7054377136777);
      glVertex2f(920.3987827229516, 503.7678594582875);



	glEnd();


	glBegin(GL_QUADS);              //door-window
	if (day) {
    glColor3ub(29, 102, 97); // Day window color
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
        glColor3ub(29, 102, 97); // Lights OFF (dark window)
    }
}
    glVertex2f(869.2553640036308, 536.54086121956);
	glVertex2f(869.2553640036308, 564.6445763991416);
    glVertex2f(888.6823161174715,  564.6445763991416);
    glVertex2f(888.6823161174715,  536.54086121956);

    glVertex2f(898.8142162805184, 536.54086121956);
	glVertex2f(898.8142162805184, 564.6445763991416);
    glVertex2f(917.4479414287955,  564.6445763991416);
    glVertex2f(917.4479414287955,  536.54086121956);




	glEnd();



	glBegin(GL_POLYGON);              //long window


	glColor3ub(1,1,1);
    glVertex2f(739.2124612009289, 533.5978848836136);
	glVertex2f(734.0201090817338, 538.6748514001595);
    glVertex2f(734.0201090817338, 565.7904680226208);
    glVertex2f(739.2124612009289, 569.4828073073814);
     glVertex2f(845, 569.4828073073814);
      glVertex2f(851.0915304407513, 565.7904680226208);
        glVertex2f(851.0915304407513, 538.6748514001595);
        glVertex2f(845, 533.5978848836136);



	glEnd();
	glBegin(GL_QUADS);              //long window

	if (day) {
    glColor3ub(29, 102, 97); // Day window color
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
        glColor3ub(29, 102, 97); // Lights OFF (dark window)
    }
}
    glVertex2f(738.1095308511241, 538.0511335546357);
	glVertex2f(738.1095308511241, 564.6348283682764);
    glVertex2f(785.7662083219979, 564.6348283682764);
    glVertex2f(785.7662083219979,  538.0511335546357);

    glVertex2f(796.9492069992125, 538.0511335546357);
	glVertex2f(796.9492069992125, 564.6348283682764);
    glVertex2f(844.397054412659, 564.6348283682764);
    glVertex2f(844.397054412659,  538.0511335546357);


	glEnd();

//glPopMatrix();
	glPopMatrix();


}

//10
void trainwindowdoor1(float x,float y,float z){

glPushMatrix();
glTranslatef(x,y,z);
	glBegin(GL_POLYGON);              //door
	glColor3ub(74,152,139);
    glVertex2f(862.1835580419975, 501.0017907236453);
	glVertex2f(862.1835580419975, 566.0868767544748);
    glVertex2f(867.0213051222455, 570.9254961319955);
    glVertex2f(888.653465334353, 570.9254961319955);
     glVertex2f(892.8084351084885, 568.5606468965784);
      glVertex2f(896.9878872652338,570.9254961319955);
       glVertex2f(919.8801145417474, 570.9254961319955);
        glVertex2f(924.0425571351784, 566.0868767544748);
 glVertex2f(924.311588390152,501.0017907236453);


	glEnd();

	glBegin(GL_POLYGON);              //door
	glColor3ub(227,221,185);
    glVertex2f(864.7935434626104, 503.7678594582875);
	glVertex2f(864.7935434626104, 565.7054377136777);
    glVertex2f(866.7480943607897, 567.3792632844082);
    glVertex2f(887.9465381638403,  567.3792632844082);
     glVertex2f(890.5467291262173, 565.7054377136777);
      glVertex2f(890.5467291262173, 503.7678594582875);



	glEnd();


	glBegin(GL_POLYGON);              //door
	glColor3ub(227,221,185);
    glVertex2f(894.8051806805096, 503.7678594582875);
	glVertex2f(894.8051806805096,565.7054377136777);
    glVertex2f(896.8752315018976, 567.3792632844082);
    glVertex2f(917.871537430087,  567.3792632844082);
     glVertex2f(920.3987827229516, 565.7054377136777);
      glVertex2f(920.3987827229516, 503.7678594582875);



	glEnd();


	glBegin(GL_QUADS);              //door-window

	if (day) {
    glColor3ub(29, 102, 97); // Day window color
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
        glColor3ub(29, 102, 97); // Lights OFF (dark window)
    }
}

    glVertex2f(869.2553640036308, 536.54086121956);
	glVertex2f(869.2553640036308, 564.6445763991416);
    glVertex2f(888.6823161174715,  564.6445763991416);
    glVertex2f(888.6823161174715,  536.54086121956);

    glVertex2f(898.8142162805184, 536.54086121956);
	glVertex2f(898.8142162805184, 564.6445763991416);
    glVertex2f(917.4479414287955,  564.6445763991416);
    glVertex2f(917.4479414287955,  536.54086121956);




	glEnd();



glPopMatrix();

trainwindowdoor4(-575,0,0);
}

//11
void trainwindowdoor2(float x,float y,float z){

glPushMatrix();
glTranslatef(x,y,z);

	glBegin(GL_POLYGON);              //long window
	glColor3ub(1,1,1);
    glVertex2f(739.2124612009289, 533.5978848836136);
	glVertex2f(734.0201090817338, 538.6748514001595);
    glVertex2f(734.0201090817338, 565.7904680226208);
    glVertex2f(739.2124612009289, 569.4828073073814);
     glVertex2f(845, 569.4828073073814);
      glVertex2f(851.0915304407513, 565.7904680226208);
        glVertex2f(851.0915304407513, 538.6748514001595);
        glVertex2f(845, 533.5978848836136);



	glEnd();
	glBegin(GL_QUADS);              //long window
	if (day) {
    glColor3ub(29, 102, 97); // Day window color
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
        glColor3ub(29, 102, 97); // Lights OFF (dark window)
    }
}
	//glColor3ub(29,102,97);
    glVertex2f(738.1095308511241, 538.0511335546357);
	glVertex2f(738.1095308511241, 564.6348283682764);
    glVertex2f(785.7662083219979, 564.6348283682764);
    glVertex2f(785.7662083219979,  538.0511335546357);

    glVertex2f(796.9492069992125, 538.0511335546357);
	glVertex2f(796.9492069992125, 564.6348283682764);
    glVertex2f(844.397054412659, 564.6348283682764);
    glVertex2f(844.397054412659,  538.0511335546357);


	glEnd();
glPopMatrix();
}


//12
void trainwindowdoor3(float x,float y,float z){

glPushMatrix();
glTranslatef(x,y,z);
	glBegin(GL_POLYGON);              //door
	glColor3ub(74,152,139);
    glVertex2f(862.1835580419975, 501.0017907236453);
	glVertex2f(862.1835580419975, 566.0868767544748);
    glVertex2f(867.0213051222455, 570.9254961319955);
    glVertex2f(888.653465334353, 570.9254961319955);
     glVertex2f(892.8084351084885, 568.5606468965784);
      glVertex2f(896.9878872652338,570.9254961319955);
       glVertex2f(919.8801145417474, 570.9254961319955);
        glVertex2f(924.0425571351784, 566.0868767544748);
 glVertex2f(924.311588390152,501.0017907236453);


	glEnd();

	glBegin(GL_POLYGON);              //door
	glColor3ub(227,221,185);
    glVertex2f(864.7935434626104, 503.7678594582875);
	glVertex2f(864.7935434626104, 565.7054377136777);
    glVertex2f(866.7480943607897, 567.3792632844082);
    glVertex2f(887.9465381638403,  567.3792632844082);
     glVertex2f(890.5467291262173, 565.7054377136777);
      glVertex2f(890.5467291262173, 503.7678594582875);



	glEnd();


	glBegin(GL_POLYGON);              //door
	glColor3ub(227,221,185);
    glVertex2f(894.8051806805096, 503.7678594582875);
	glVertex2f(894.8051806805096,565.7054377136777);
    glVertex2f(896.8752315018976, 567.3792632844082);
    glVertex2f(917.871537430087,  567.3792632844082);
     glVertex2f(920.3987827229516, 565.7054377136777);
      glVertex2f(920.3987827229516, 503.7678594582875);



	glEnd();


	glBegin(GL_QUADS);              //door-window

if (day) {
    glColor3ub(29, 102, 97); // Day window color
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
        glColor3ub(29, 102, 97); // Lights OFF (dark window)
    }
}

    glVertex2f(869.2553640036308, 536.54086121956);
	glVertex2f(869.2553640036308, 564.6445763991416);
    glVertex2f(888.6823161174715,  564.6445763991416);
    glVertex2f(888.6823161174715,  536.54086121956);

    glVertex2f(898.8142162805184, 536.54086121956);
	glVertex2f(898.8142162805184, 564.6445763991416);
    glVertex2f(917.4479414287955,  564.6445763991416);
    glVertex2f(917.4479414287955,  536.54086121956);




	glEnd();


glPopMatrix();
}

//13
void trainwindowdoor4(float x,float y,float z){

glPushMatrix();
glTranslatef(x,y,z);
	glBegin(GL_POLYGON);
	if (day) {
    glColor3ub(29, 102, 97); // Day window color
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
        glColor3ub(29, 102, 97); // Lights OFF (dark window)
    }
}
	//glColor3ub(29,102,97);
    glVertex2f(938.1093305653335, 536.0730611963578);
	glVertex2f(933.1004568738157, 539.6475980420407);
    glVertex2f(933.1004568738157, 563.7666027098329);
    glVertex2f(935.9551818593536, 566.7053982872585);
     glVertex2f(968.8478586673685, 566.7053982872585);
      glVertex2f(972.2908056189817,  563.7666027098329);
       glVertex2f(972.2908056189817,  539.6475980420407);
        glVertex2f(970.1826138800703,536.0730611963578);

glEnd();
glPopMatrix();
}

//14
void trainwheels(float x,float y,float z){
glPushMatrix();
glTranslatef(x,y,z);
glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(8,66,66);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=18.45;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+950,y+495 );
        }

glEnd();
glPopMatrix();
}



//15

void building1(){
glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(82, 168, 153);
	glVertex2f(0,660);
    glVertex2f(0,641.3737085081417);
    glVertex2f(75.6637340170925, 644.0073196653109);
	glVertex2f(75.6637340170925, 661.4896920068476);
glColor3ub(116,187,172);
	glVertex2f(75.6637340170925, 661.4896920068476);
	glVertex2f(75.6637340170925, 644.0073196653109);
	glVertex2f(173.1586116264867, 640.4807456731745);
    glVertex2f(173.1586116264867, 657.4938432198802);

glColor3ub(117, 183, 161);
    glVertex2f(0,641.3737085081417);
    glVertex2f(0,634.4955021783092);
    glVertex2f(75.6637340170925,  637.025901514284);
	glVertex2f(75.6637340170925, 644.0073196653109);
glColor3ub(179, 205, 178);
	glVertex2f(75.6637340170925,  637.025901514284);
	glVertex2f(75.6637340170925, 644.0073196653109);
	glVertex2f(209.6114325756994, 637.8814533230415);
	glVertex2f(209.6114325756994, 632.3240865790602);
glColor3ub(117, 183, 161);
    glVertex2f(0,634.4955021783092);
    glVertex2f(0,500);
    glVertex2f(75.6637340170925,500);
    glVertex2f(75.6637340170925,  637.025901514284);
glColor3ub(179, 205, 178);
    glVertex2f(75.6637340170925,500);
    glVertex2f(75.6637340170925,  637.025901514284);
    glVertex2f(202.4831071824877,  633.0853221740026);
    glVertex2f(202.4831071824877, 500);



	glEnd();
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(99, 177, 158);

    glVertex2f(0,634.4955021783092);
    glVertex2f(75.6637340170925,  637.025901514284);

    glVertex2f(75.6637340170925,  637.025901514284);
    glVertex2f(209.6114325756994, 632.3240865790602);

    glVertex2f(75.6637340170925,  637.025901514284);
	glVertex2f(75.6637340170925,  500);
glEnd();



for(int y = 0; y <= 120; y += 19) {
    b1windows(0,-y,0);
}
for(int y = 0; y <= 120; y += 30) {
    for(int x = 0; x <= 50; x += 23) {
        b1windows1(-x, -y, 0);
    }
}
}
//16
void b1windows(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z); // Move this individual window

    glBegin(GL_QUADS);

    if (day)
    {
       glColor3ub(99, 177, 158);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow


    }

    glVertex2f(87.7949069054109, 625.1814363029188);
    glVertex2f(100.2602575284162, 625.1814363029188);
    glVertex2f(100.531243411525, 612.8515786214683);
    glVertex2f(87.7949069054109, 612.8515786214683);

    glVertex2f(111.0220049178617, 625.1899507792652);
    glVertex2f(123.9206721601528, 625.1899507792652);
    glVertex2f(123.92067216015281, 612.4524459845522);
    glVertex2f(111.0220049178617,612.4524459845522);

    glVertex2f(133.8690188281499, 623.1113888431373);
    glVertex2f(147.2282272108889,623.1113888431373);
    glVertex2f(147.2282272108889, 610.3206574128353);
    glVertex2f(133.8690188281499, 610.3206574128353);

    glVertex2f(157.3600233178877, 623.2348133648713);
    glVertex2f(170.6357598816784,  623.2348133648713);
    glVertex2f(170.6357598816784, 610);
    glVertex2f(157.3600233178877,610);

    glVertex2f(180.549400062848, 621.5932720324022);
    glVertex2f(192.0425964953521, 621.5932720324022);
    glVertex2f(192.0425964953521, 610.264690528356);
    glVertex2f(180.549400062848, 610.264690528356);

    glEnd();

    glPopMatrix();
}
//17
void b1windows1(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z); // Move this individual window

    glBegin(GL_QUADS);

if (day)
    {
glColor3ub(81,168,150);    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow


    }

    glVertex2f(61.5273269427019, 626.579591648286);
    glVertex2f(61.5273269427019, 612.653440425803);
    glVertex2f(48.8966316479114,612.653440425803);
    glVertex2f(48.8966316479114, 626.579591648286);



    glEnd();

    glPopMatrix();
}
//18
void building2(){

glBegin(GL_TRIANGLES);            // These vertices form a closed polygon

	glColor3ub(46,137,129);
	glVertex2f(106.972073513764, 778.205635368736);
    glVertex2f(110.964379909539, 778.205635368736);
    glVertex2f(108.4601589844464, 805.9713545539153);

glEnd();
glBegin(GL_QUADS);            // These vertices form a closed polygon

glColor3ub(64,152,142);
	glVertex2f(61.4725617406649, 773.3474227912019);
    glVertex2f(61.4725617406649, 757.7473534936222);
    glVertex2f(110.964379909539, 759.5199836774502);
	glVertex2f(110.964379909539, 778.485797221071);
glColor3ub(113,184,170);
	 glVertex2f(112.1590114252406, 760.192178492771);
	glVertex2f(110.964379909539, 778.485797221071);
	glVertex2f(163.0680275151478, 776.8682793310991);
    glVertex2f(162.7664464819068, 758.9949789206474);



    glColor3ub(113,184,170);
	glVertex2f(127.950571118705, 634.5171759456537);
	glVertex2f(127.950571118705, 760.7371039608537);
	glVertex2f(190.2668443275244, 761.2745176813431);
    glVertex2f(190.2668443275244,634.5171759456537);



	glColor3ub(64,152,142);
	glVertex2f(39.4120639176526, 756.9252264165168);
    glVertex2f(39.4120639176526, 634.5171759456537);
    glVertex2f(127.950571118705, 634.5171759456537);
	glVertex2f(127.950571118705, 760.7371039608537);


glEnd();


b2windows(0,0,0);
b2windows(0,-15,0);
b2windows(0,-30,0);
b2windows(0,-45,0);
b2windows(0,-60,0);
b2windows(0,-75,0);
b2windows(0,-90,0);



b2windows2(0,0,0);
b2windows2(0,-15,0);
b2windows2(0,-30,0);
b2windows2(0,-45,0);
b2windows2(0,-60,0);
b2windows2(0,-75,0);
b2windows2(0,-90,0);



}
//19
void b2windows(float x,float y,float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glLineWidth(4);
glBegin(GL_LINES);            // These vertices form a closed polygon

	glColor3ub(52,143,135);
	glVertex2f(127.950571118705, 752.11575430271);
    glVertex2f(39.4120639176526, 748.4238237921471);

glEnd();

    glPopMatrix();
}

//20
void b2windows2(float x,float y,float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glLineWidth(4);
glBegin(GL_LINES);            // These vertices form a closed polygon

	glColor3ub(90,161,151);
	glVertex2f(127.950571118705, 752.11575430271);
    glVertex2f(190.2668443275244, 748.1290778642513);

glEnd();

    glPopMatrix();
}
//21
void building3(){
glBegin(GL_TRIANGLES);            // These vertices form a closed polygon

	glColor3ub(182, 219, 195);
	glVertex2f(277.7904689525043,  893.8700803912909);
    glVertex2f(285.8143102946589,  893.8700803912909);
    glVertex2f(281.4108935782737, 961.0055537792693);

glEnd();
glBegin(GL_QUADS);            // These vertices form a closed polygon

	 glColor3ub(68, 153, 143);
	glVertex2f(256.2547339115405, 893.9373701044177);
    glVertex2f(256.2547339115405, 872.5755108017474);
    glVertex2f(269.6971876174824, 874.2979757681093);
	glVertex2f(269.6971876174824, 895.6430698966461);

  glColor3ub(182, 219, 195);
	glVertex2f(269.6971876174824, 874.2979757681093);
	glVertex2f(269.6971876174824, 895.6430698966461);
	glVertex2f(314.2847590811361, 891.4152902617957);
    glVertex2f(314.2847590811361, 868.981696464383);




glColor3ub(68, 153, 143);
	glVertex2f(233.8905523068304, 869.917546681419);
    glVertex2f(233.8905523068304, 850.927841181545);
    glVertex2f(265.7323750963757, 854.0179698284038);
	glVertex2f(265.7323750963757, 874.8388169357596);

  glColor3ub(182, 219, 195);
	glVertex2f(265.7323750963757, 854.0179698284038);
	glVertex2f(265.7323750963757, 874.8388169357596);
	glVertex2f(336.125484962348, 866.881109533664);
    glVertex2f(335.3637784358659, 845.6588780092977);

glEnd();


glBegin(GL_QUADS);            // These vertices form a closed polygon

glColor3ub(86, 173, 158);
	glVertex2f(212.014591332448, 847.9689557891672);
    glVertex2f(212.014591332448, 500);
    glVertex2f(261.725505049688, 500);
	glVertex2f(261.725505049688, 853.9027724510862);
glColor3ub(182, 219, 195);
	glVertex2f(261.725505049688, 500);
	glVertex2f(261.725505049688, 853.9027724510862);
	glVertex2f(353.8166379535475, 845.0181332754455);
    glVertex2f(353.8166379535475, 500);


glEnd();





for(int y = 0; y <= 300; y += 18) {
    b3windows(0,-y,0);
}
for(int y = 0; y <= 70; y += 13) {
    b3windows1(y,0,0);
}
for(int y = 0; y <= 350; y += 30) {
    b3windows2(0,-y,0);
}
}
//22
void b3windows(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_QUADS);            // These vertices form a closed polygon

     glColor3ub(61,154,140);
	glVertex2f(261.725505049688, 841.3106657086819);
	glVertex2f(261.725505049688, 833.5910454555615);
	glVertex2f(212.014591332448, 829.0615601912157);
	glVertex2f(212.014591332448, 836.8596487696218);



glEnd();
glPopMatrix();
}
//23
void b3windows1(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_QUADS);            // These vertices form a closed polygon

    if (day)
    {
     glColor3ub(115,188,171);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(270.6969553453444, 841.1890897012177);
	glVertex2f(278.6037939609736, 840.9268034398445);
	glVertex2f(278.6037939609736, 500);
	glVertex2f(270.6969553453444, 500);



glEnd();
glPopMatrix();
}
//24
void b3windows2(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_QUADS);            // These vertices form a closed polygon

  glColor3ub(182, 219, 195);
	glVertex2f(270.6969553453444, 821.1034373625145);
	glVertex2f(270.6969553453444, 816.109706406656);
	glVertex2f(350.2034938005373, 816.109706406656);
	glVertex2f(350.2034938005373, 821.1034373625145);



glEnd();
glPopMatrix();
}

//25
void building4(){
glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(76, 155, 142);
	glVertex2f(364.000077627959, 705.8397325139076);
    glVertex2f(364.000077627959, 694.3155659604745);
    glVertex2f(452.692771940378, 699.0201296204895);
	glVertex2f(452.692771940378, 710.8798721367044);
  glColor3ub(131, 184, 160);
    glVertex2f(452.692771940378, 699.0201296204895);
	glVertex2f(452.692771940378, 710.8798721367044);
	glVertex2f(538.1118204516217, 704.8649198985014);
    glVertex2f(538.1118204516217, 693.9552738605997);



    glColor3ub(113, 181, 159);
	glVertex2f(355.2423548899528, 694.3153127607846);
    glVertex2f(355.2423548899528,500);
    glVertex2f(453.8553637554959,500);
    glVertex2f(452.692771940378, 699.0201296204895);
  glColor3ub(185, 208, 181);
   glVertex2f(453.8553637554959,500);
    glVertex2f(452.692771940378, 699.0201296204895);
	glVertex2f(558.9029981229212, 693.4092372413071);
    glVertex2f(558.9029981229212, 500);

for(int y = 0; y <= 150; y += 30) {
    b4windows(0,-y,0);
}
for(int y = 0; y <= 150; y += 30) {
    for(int x = 0; x <= 80; x += 18) {
        b4windows1(-x, -y, 0);
    }
}

glEnd();
}

//26
void b4windows(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_QUADS);            // These vertices form a closed polygon
 if (day)
    {
     glColor3ub(118,190,170);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(464.8483347811319, 682.837893207248);
	glVertex2f(476.7980394741169, 682.837893207248);
	glVertex2f(476.7980394741169, 664.4148617335907);
	glVertex2f(464.8483347811319, 664.4148617335907);

    glVertex2f(482.2561763133871, 682.3287772692768);
	glVertex2f(494.3914094181875, 682.3287772692768);
	glVertex2f(494.3914094181875, 664.420879126867);
	glVertex2f(482.2561763133871, 664.420879126867);

	glVertex2f(499.4628554525905, 681.6344359949217);
	glVertex2f(512.5664437311787,  681.6344359949217);
	glVertex2f(512.5664437311787, 662.6937947558416);
	glVertex2f(499.4628554525905, 662.6937947558416);

	glVertex2f(518.1148486595503, 680.4029561993417);
	glVertex2f(530, 680.4029561993417);
	glVertex2f(530, 662.4707502151725);
	glVertex2f(518.1148486595503, 662.4707502151725);

	glVertex2f(536.5660165871069, 679.4371861376495);
	glVertex2f(548.6775124848148, 679.4371861376495);
	glVertex2f(548.6775124848148, 660.9815733411132);
	glVertex2f(536.5660165871069, 660.9815733411132);





glEnd();
glPopMatrix();
}
//27
void b4windows1(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_QUADS);            // These vertices form a closed polygon

 if (day)
    {
     glColor3ub(79,166,149);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(446.6882690235788, 683.5583833451275);
	glVertex2f(435.2555646409932, 683.5583833451275);
	glVertex2f(435.2555646409932, 664.7399495826114);
	glVertex2f(446.6882690235788, 664.7399495826114);


glEnd();
glPopMatrix();
}
//28
void building5(){
    glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(99,189,168);
	glVertex2f(387.2416674224169, 766.8582158441396);
    glVertex2f(387.2416674224169, 500);
    glVertex2f(452.7869698768899, 500);
	glVertex2f(452.7869698768899, 773.0921440667116);
  glColor3ub(142, 211, 188);
   glVertex2f(452.7869698768899, 500);
	glVertex2f(452.7869698768899, 773.0921440667116);
	glVertex2f(520.5016228604017, 768.4202986668889);
    glVertex2f(520.5016228604017,500);
glEnd();


for(int y = 0; y <= 200; y += 10) {
    b5windows(0,-y,0);
}

}

//29
void b5windows(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);
glLineWidth(4);
glBegin(GL_LINES);            // These vertices form a closed polygon

     glColor3ub(92,187,162);
	glVertex2f(452.7869698768899, 748.3620733438644);
	glVertex2f(520.5016228604017, 743.5595161962613);
     glColor3ub(79,177,154);

	glVertex2f(452.7869698768899, 748.3620733438644);
	glVertex2f(387.2416674224169, 743.9761534283429);





glEnd();
glPopMatrix();
}
//30
void building6(){
 glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(89,169,156);
	glVertex2f(550.0037899589379, 822.7653915294845);
    glVertex2f(550.0037899589379, 500);
    glVertex2f(593.9581459900146, 500);
	glVertex2f(593.9581459900146, 827.6445782393024);
  glColor3ub(146, 206, 187);
  glVertex2f(593.9581459900146, 500);
	glVertex2f(593.9581459900146, 827.6445782393024);
	glVertex2f(690.7653842379314, 820.5255985795935);
    glVertex2f(690.7653842379314, 500);

  glEnd();



  glBegin(GL_QUADS);            // These vertices form a closed polygon
if (day)
    {
  glColor3ub(146, 206, 187);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(605.9776561700055, 810.7186786930578);
    glVertex2f(690.7653842379314, 805.3415195641014);
    glVertex2f(690.7653842379314, 500);
	glVertex2f(605.9776561700055, 500);
if (day)
    {
	glColor3ub(89,169,156);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
  glVertex2f(584.4524250581972, 810.7186786930578);
	glVertex2f(550.0037899589379, 807.305784097753);
	glVertex2f(550.0037899589379, 500);
    glVertex2f(584.4524250581972, 500);

  glEnd();


  for(int y = 0; y <= 85; y += 13) {
    b6windows(y,0,0);
}

for(int y = 0; y <= 35; y += 13) {
    b6windows1(-y,0,0);
}

for(int y = 0; y <= 300; y += 15) {
    b6windows2(0,-y,0);
}
}

//31
void b6windows(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);
glLineWidth(2);
glBegin(GL_LINES);            // These vertices form a closed polygon

     glColor3ub(62,141,134);
	glVertex2f(605.9776561700055, 808.7186786930578);
	glVertex2f(605.9776561700055, 500);




glEnd();
glPopMatrix();
}
//32
void b6windows1(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);
glLineWidth(2);
glBegin(GL_LINES);            // These vertices form a closed polygon

     glColor3ub(62,141,134);
	glVertex2f(584.4524250581972, 808.7186786930578);
	glVertex2f(584.4524250581972, 500);



glEnd();
glPopMatrix();
}
//33
void b6windows2(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);
glLineWidth(2);
glBegin(GL_LINES);            // These vertices form a closed polygon

     glColor3ub(62,141,134);
	glVertex2f(605.9776561700055, 810.7186786930578);
    glVertex2f(690.7653842379314, 805.3415195641014);

  glVertex2f(584.4524250581972, 810.7186786930578);
	glVertex2f(550.0037899589379, 807.305784097753);

glEnd();
glPopMatrix();
}
//34
void building7(){
glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(69,146,138);
	glVertex2f(667.5106803010602, 751.185093325026);
    glVertex2f(665.8804689888732, 739.2785102255637);
    glVertex2f(755.350499536877, 743.3265015205969);
	glVertex2f(755.350499536877, 756.1438531080473);
  glColor3ub(126, 179, 160);
   glVertex2f(755.350499536877, 743.3265015205969);
	glVertex2f(755.350499536877, 756.1438531080473);
	glVertex2f(838.8408255964054, 751.4179842758799);
    glVertex2f(853.4770130256203, 737.3085007668102);

    glColor3ub(90,165,162);
	glVertex2f(637.7700846285308, 738.7847081975327);
    glVertex2f(637.7700846285308, 500);
    glVertex2f(747.435253793088,500);
	glVertex2f(747.435253793088, 743.6998530473444);
  glColor3ub(199, 213, 185);
  glVertex2f(747.435253793088,500);
	glVertex2f(747.435253793088, 743.6998530473444);
	glVertex2f(860.0173641426518, 737.2085029077809);
    glVertex2f(860.0173641426518, 500);
    glEnd();


glBegin(GL_QUADS);            // These vertices form a closed polygon
if (day)
    {
	glColor3ub(117,192,174);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(755.350499536877, 728.8186640284473);
    glVertex2f(851.9930710415581, 724.1761048120493);
    glVertex2f(851.9930710415581, 500);
	glVertex2f(755.350499536877, 500);
if (day)
    {
	glColor3ub(74,156,145);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }

	glVertex2f(738.9940905302096, 727.8348828225004);
    glVertex2f(738.9940905302096, 500);
    glVertex2f(642.1535683295436, 500);
	glVertex2f(642.1535683295436, 724.0201365809259);


	glEnd();
for(int y = 0; y <= 81; y += 16) {
    b7windows(y,0,0);
}

for(int y = 0; y <= 81; y += 16) {
    b7windows1(-y,0,0);
}

for(int y = 0; y <= 200; y += 20) {
    b7windows2(0,-y,0);
}
}
//35
void b7windows(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);
glLineWidth(2);
glBegin(GL_LINES);            // These vertices form a closed polygon

     glColor3ub(59,127,119);
	glVertex2f(770.0511308172461, 726.3946729300944);
    glVertex2f(770.0511308172461,500);




glEnd();
glPopMatrix();
}
//36
void b7windows1(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);
glLineWidth(2);
glBegin(GL_LINES);            // These vertices form a closed polygon

     glColor3ub(59,127,119);


    glVertex2f(723.6845826672319, 726.0215930319082);
    glVertex2f(723.6845826672319,500);


glEnd();
glPopMatrix();
}
//37
void b7windows2(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);
glLineWidth(3);
glBegin(GL_LINES);            // These vertices form a closed polygon

     glColor3ub(59,127,119);


    glVertex2f(738.9940905302096, 727.8348828225004);
    glVertex2f(642.1535683295436, 724.0201365809259);

    glVertex2f(756.5122882596389, 728.8186640284473);
    glVertex2f(851.9930710415581, 724.1761048120493);



glEnd();
glPopMatrix();
}

//38
void building8(){
glBegin(GL_QUADS);            // These vertices form a closed polygon

glColor3ub(69,152,143);
	glVertex2f(917.165560688084, 825.2273446204922);
    glVertex2f(917.165560688084, 809.1932463893095);
    glVertex2f(963.81460199355, 811.9727837185949);
	glVertex2f(963.81460199355, 827.5901393364936);
glColor3ub(120, 178, 158);
    glVertex2f(963.81460199355, 811.9727837185949);
	glVertex2f(963.81460199355, 827.5901393364936);
	glVertex2f(1021.6842903044206, 823.4581463968644);
    glVertex2f(1021.2569104611747, 806.1492627454064);

glColor3ub(77,158,148);
	glVertex2f(901.5140622325899, 808.4306300934356);
    glVertex2f(901.5140622325899, 795.4625940649169);
    glVertex2f(963.81460199355, 798.2327209899291);
     glVertex2f(963.81460199355, 811.9727837185949);

glColor3ub(175, 200, 174);
   glVertex2f(963.81460199355, 798.2327209899291);
     glVertex2f(963.81460199355, 811.9727837185949);
	glVertex2f(1045.440218323786, 804.1725301639555);
    glVertex2f(1045.8840199408198, 789.6612006807023);



    glColor3ub(108,178,156);
	glVertex2f(880.8706907317239, 794.0561288579869);
    glVertex2f(880.8706907317239, 500);
    glVertex2f(958.7699141621111, 500);
	glVertex2f(958.7699141621111, 799);
glColor3ub(232,224,190);
    glVertex2f(958.7699141621111, 500);
	glVertex2f(958.7699141621111, 799);
	glVertex2f(1059.6890726427494, 789.0619716273483);
    glVertex2f(1059.6890726427494, 500);


    glEnd();

for(int y = 0; y <= 220; y += 23) {
    b8windows(0,-y,0);
}



}
//39
void b8windows(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_QUADS); // These vertices form a closed polygon
if (day)
    {
     glColor3ub(136,192,171);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(969.1520774990715, 786.7579507007322);
    glVertex2f(982.7800544508088, 786.7579507007322);
    glVertex2f(982.7800544508088, 771.2727974735476);
    glVertex2f(969.1520774990715, 771.2727974735476);

    glVertex2f(987.2191247857811, 786.7106415721598);
    glVertex2f(1001.3198781260987, 786.7106415721598);
    glVertex2f(1001.30797817171, 768.8425203259496);
    glVertex2f(987.2191247857811, 768.8425203259496);


    glVertex2f(1004.6766915755103, 784.920470662293);
    glVertex2f(1018.4122630274532, 784.920470662293);
    glVertex2f(1018.4122630274532, 767.4644102971201);
    glVertex2f(1004.6766915755103, 767.7706569701934);


    glVertex2f(1022.1327519406568, 782.7767439507805);
    glVertex2f(1036.6794689116123, 782.7767439507805);
    glVertex2f(1036.8325922481488, 765.7800535952175);
    glVertex2f(1022.1327519406568, 765.7800535952175);

    glVertex2f(1039.90741690908, 781.2167108924588);
    glVertex2f(1052.4342440945984, 781.2167108924588);
    glVertex2f(1052.494381570315, 765.5447787603462);
    glVertex2f(1039.90741690908, 765.5447787603462);
if (day)
    {
     glColor3ub(84,166,150);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }

     glVertex2f(950.7705617772859, 786.5728253827089);
    glVertex2f(950.7705617772859, 771.861167887132);
    glVertex2f(892.5558203651387, 770.1658959360758);
    glVertex2f(892.5558203651387, 784.022934893049);







glEnd();
glPopMatrix();
}
//40
void building9(){

glBegin(GL_QUADS);            // These vertices form a closed polygon

glColor3ub(114,181,164);
	glVertex2f(1081.2464913217939, 728.0668417971544);
    glVertex2f(1061.4137907075408, 706.4189394720312);
    glVertex2f(1149.3019803102734, 709.3639150251665);
	glVertex2f(1142.1055762830374, 730.0870913683855);
glColor3ub(140,200,182);
     glVertex2f(1149.3019803102734, 709.3639150251665);
	glVertex2f(1142.1055762830374, 730.0870913683855);
	glVertex2f(1177.8089139399267, 728.0064119208852);
    glVertex2f(1194.4620547737547, 706.7518138395485);

glColor3ub(79,162,148);
	glVertex2f(1061.4137907075408, 706.4189394720312);
    glVertex2f(1061.458456045077, 694.8698418524166);
    glVertex2f(1149.9044019766022, 695.28501390588);
     glVertex2f(1149.3019803102734, 709.3639150251665);

glColor3ub(118,180,163);
  glVertex2f(1149.9044019766022, 695.28501390588);
     glVertex2f(1149.3019803102734, 709.3639150251665);
	glVertex2f(1210.8137274923217, 705.7665387223376);
    glVertex2f(1210.8137274923217, 690.8220383364406);



glColor3ub(110,177,156);
	glVertex2f(1061.458456045077, 694.8698418524166);
    glVertex2f(1061.458456045077, 500);
    glVertex2f(1149.9044019766022, 500);
     glVertex2f(1149.9044019766022, 695.28501390588);

glColor3ub(187,207,179);
  glVertex2f(1149.9044019766022, 500);
     glVertex2f(1149.9044019766022, 695.28501390588);
	glVertex2f(1225.588175119739, 690.7584254775013);
    glVertex2f(1225.588175119739, 500);
    glEnd();
for(int y = 0; y <= 200; y += 30) {
    b9windows(0,-y,0);
}
for(int y = 0; y <= 150; y += 30) {
    for(int x = 0; x <= 50; x += 20) {
        b9windows1(-x, -y, 0);
    }
}

}



//41
void b9windows(float x,float y,float z)
{


     glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_QUADS);            // These vertices form a closed polygon
if (day)
    {
     glColor3ub(132,196,175);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(1161.5819969028196, 681.411283284973);
    glVertex2f(1172.1712746483595, 681.411283284973);
    glVertex2f(1172.1712746483595, 666.3441697860326);
    glVertex2f(1161.5819969028196, 666.3441697860326);

    glVertex2f(1183.3235033314845, 679.7709698479841);
    glVertex2f(1192.7312186651334,679.7709698479841);
    glVertex2f(1192.7312186651334, 664.7381774758386);
    glVertex2f(1183.3235033314845, 664.8793253242591);


    glVertex2f(1204.5349360145217, 678.5261061113122);
    glVertex2f(1214.3137704320065,  678.5261061113122);
    glVertex2f(1214.3137704320065, 662.8799710433142);
    glVertex2f(1204.5349360145217, 663.2059321905641);






glEnd();
glPopMatrix();
}
//42
void b9windows1(float x,float y,float z)
{
     glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_QUADS);            // These vertices form a closed polygon
if (day)
    {
     glColor3ub(86,168,150);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(1128.0858613433966, 681.3389032599216);
    glVertex2f(1128.0858613433966, 666.7054396780552);
    glVertex2f(1118.9714920775725,  666.7054396780552);
    glVertex2f(1118.9714920775725, 681.3389032599216);



glEnd();
glPopMatrix();
}
//43
void building10(){
glBegin(GL_TRIANGLES);            // These vertices form a closed polygon

glColor3ub(46,129,124);
	glVertex2f(1272.267839365933, 786.8606861409068);
    glVertex2f(1274.651502325415, 786.8606861409068);
    glVertex2f(1273.3796508076043, 826.4629415780644);

glEnd();



glBegin(GL_QUADS);
glColor3ub(95,167,154);
     glVertex2f(1216.6560114520787, 784.2714633568637);
	glVertex2f(1216.5175343620158, 768.9033332050913);
	glVertex2f(1272.267839365933, 771.2224892539608);
    glVertex2f(1272.267839365933, 786.8606861409068);

glColor3ub(132,193,176);
	glVertex2f(1272.267839365933, 771.2224892539608);
    glVertex2f(1272.267839365933, 786.8606861409068);
    glVertex2f(1328.5835495299682, 780.7346587757025);
     glVertex2f(1328.5835495299682, 765.0051482327319);



     glColor3ub(95,167,154);
     glVertex2f(1195.2714882324556, 768.6853714263085);
	glVertex2f(1195.2714882324556, 500);
	glVertex2f(1275.7523480528866,500);
    glVertex2f(1275.7523480528866, 771.608511297276);

glColor3ub(168,205,181);
	glVertex2f(1275.7523480528866,500);
    glVertex2f(1275.7523480528866, 771.608511297276);
    glVertex2f(1349.3416711254392, 764.7780420482123);
     glVertex2f(1349.3416711254392, 500);

b10windows(0,0,0);
b10windows(0,-20,0);
b10windows(0,-40,0);
b10windows(0,-60,0);
b10windows(0,-80,0);

b10windows(0,-100,0);
b10windows(0,-120,0);
b10windows(0,-140,0);
b10windows(0,-160,0);
b10windows(0,-180,0);

for(int y = 0; y <= 200; y += 14) {
    for(int x = 0; x <= 60; x += 14) {
        b10windows1(-x, -y, 0);
    }
}





glEnd();
}
//44
void b10windows(float x,float y,float z)
{
     glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_QUADS);            // These vertices form a closed polygon
if (day)
    {
     glColor3ub(123,189,168);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(1284.328814510427, 749.6659341350521);
    glVertex2f(1289.6224812090084, 749.6659341350521);
    glVertex2f(1289.6224812090084, 740);
    glVertex2f(1284.328814510427, 740);

    glVertex2f(1298, 748);
    glVertex2f(1303.0457417859714,748);
    glVertex2f(1303.0457417859714, 738.4371683921472);
    glVertex2f(1298, 738.4371683921472);


    glVertex2f(1309.500460861811, 746.5061357019597);
    glVertex2f(1314.8739571468402, 746.5061357019597);
    glVertex2f(1314.8739571468402, 736.2825321746055);
    glVertex2f(1309.500460861811,  736.2825321746055);




	glVertex2f(1321.6813432900203, 745.907431597339);
    glVertex2f(1327.6337134777687, 745.907431597339);
    glVertex2f(1327.6337134777687, 734.6583027170516);
    glVertex2f(1321.6813432900203, 734.6583027170516);

    glVertex2f(1335.2518770115591, 744.0329994955749);
    glVertex2f(1341.096171921758, 743.9211469614082);
    glVertex2f(1341.0155755964959, 734.8820259515174);
    glVertex2f(1335.2518770115591, 734.8820259515174);



glEnd();
glPopMatrix();
}
//45
void b10windows1(float x,float y,float z)
{
     glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_QUADS);            // These vertices form a closed polygon
if (day)
    {
     glColor3ub(77,161,144);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(1266.6612166924733, 749.6078221671189);
    glVertex2f(1266.6612166924733, 743.2332439266593);
    glVertex2f(1261.6647838744743, 743.2332439266593);
    glVertex2f(1261.6647838744743, 749.6078221671189);


glEnd();
glPopMatrix();
}

//46
void building11(){

glBegin(GL_QUADS);            // These vertices form a closed polygon

glColor3ub(111,176,160);
	glVertex2f(1420.7344627506873, 807.4512498240417);
    glVertex2f(1420.1754986456797, 778.0216254959748);
    glVertex2f(1490.0830131035125, 780.6590230462494);
	glVertex2f(1490.0830131035125, 810);
glColor3ub(161,207,186);
    glVertex2f(1490.0830131035125, 780.6590230462494);
	glVertex2f(1490.0830131035125, 810);
	glVertex2f(1550.1878375474246, 803.881225371407);
    glVertex2f(1550.3967251269341, 777.0391714044188);

glColor3ub(126,182,160);
	glVertex2f(1389.631479118019, 777.4923853133929);
    glVertex2f(1389.6565604464117, 761.9431019862327);
    glVertex2f(1495.525370492521, 764.2280083752332);
     glVertex2f(1495.7599871128784, 781.037512132321);

glColor3ub(212,213,179);
  glVertex2f(1495.525370492521, 764.2280083752332);
     glVertex2f(1495.7599871128784, 781.037512132321);
	glVertex2f(1581.7197248209943, 774.5758602494922);
    glVertex2f(1581.7197248209943, 758.5048446354198);


    glColor3ub(126,182,160);
	glVertex2f(1393.8363502819116, 762.0931221056044);
    glVertex2f(1393.8363502819116, 500);
    glVertex2f(1495.525370492521, 500);
     glVertex2f(1495.525370492521, 764.2280083752332);

glColor3ub(212,213,179);
  glVertex2f(1495.525370492521, 500);
     glVertex2f(1495.525370492521, 764.2280083752332);
	glVertex2f(1577.0991745014214, 758.4980738609961);
    glVertex2f(1577.0991745014214,500);



glEnd();
glLineWidth(2);
glBegin(GL_LINES);            // These vertices form a closed polygon

glColor3ub(111,176,160);
	glVertex2f(1393.8363502819116, 762.0931221056044);
    glVertex2f(1495.525370492521, 764.2280083752332);

    glVertex2f(1495.525370492521, 764.2280083752332);
	glVertex2f(1577.0991745014214, 758.4980738609961);
glEnd();

b11windows(0,0,0);
b11windows(0,-30,0);
b11windows(0,-60,0);
b11windows(0,-90,0);
b11windows(0,-120,0);
b11windows(0,-150,0);
b11windows(0,-180,0);


}
//47
void b11windows(float x,float y,float z)
{
     glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_QUADS);            // These vertices form a closed polygon
if (day)
    {
     glColor3ub(125,190,169);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(1507.734972036926, 753.1960417743818);
    glVertex2f(1518.34945501917, 753.2122827867338);
    glVertex2f(1518.34945501917, 736.6076788128511);
    glVertex2f(1507.734972036926, 736.6076788128511);

    glVertex2f(1531.3938744793652, 751.7766372532584);
    glVertex2f(1542.0054361771802, 751.5554344485162);
    glVertex2f(1542.2612890242501, 734.9683694238113);
    glVertex2f(1531.6149231133795, 735.3316508927334);


    glVertex2f(1554.4954822818395, 749.3744036371162);
    glVertex2f(1565.1214123710429, 749.3212739866701);
    glVertex2f(1565.026952204497, 732.8446680644605);
    glVertex2f(1554.6635826380507, 733.1173883162096);

if (day)
    {
    glColor3ub(85,167,149);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }

	glVertex2f(1473.494666651048, 753.0615159423756);
    glVertex2f(1473.494666651048, 736.7005996660715);
    glVertex2f(1461.6545298721614, 736.7005996660715);
    glVertex2f(1461.6545298721614, 753.0615159423756);

    glVertex2f(1443.1408614542659, 751.7698646574042);
    glVertex2f(1443.1408614542659, 736.9280284032925);
    glVertex2f(1430.5545029483585, 736.9280284032925);
    glVertex2f(1430.5545029483585, 751.3549765267641);


    glVertex2f(1417.3078357548766, 751.5545894432424);
    glVertex2f(1417.3078357548766, 736.5400291643031);
    glVertex2f(1406.7593502609593, 736.4853244519096);
    glVertex2f(1406.7593502609593, 751.3658320691688);

glEnd();
glPopMatrix();
}
//48
void building12(){
glBegin(GL_TRIANGLES);            // These vertices form a closed polygon

glColor3ub(39,126,123);
	glVertex2f(1688.9442009187787, 888.6898061486734);
    glVertex2f(1694.0236311572503, 888.6898061486734);
    glVertex2f(1691.1097028393876, 935.6333227060782);

glEnd();



glBegin(GL_QUADS);
glColor3ub(62,146,141);
     glVertex2f(1649.8387616562109, 887.7154816919079);
	glVertex2f(1649.8387616562109, 869.20509282019);
	glVertex2f(1720, 871.7491093651292);
    glVertex2f(1720, 890);

glColor3ub(95,174,161);
	glVertex2f(1720, 871.7491093651292);
    glVertex2f(1720, 890);
    glVertex2f(1754.6076821080385, 885.639301697342);
     glVertex2f(1754.3431141529813,  867.9846069044869);



     glColor3ub(62,146,141);
     glVertex2f(1638.0153596518096, 869.30374826004);
	glVertex2f(1638.0153596518096, 856.1185837168481);
	glVertex2f(1724.4576946084635, 858.3181648714695);
    glVertex2f(1724.9019078468918, 872.0829089364864);

glColor3ub(95,174,161);
	glVertex2f(1724.4576946084635, 858.3181648714695);
    glVertex2f(1724.9019078468918, 872.0829089364864);
    glVertex2f(1771.9174578507298, 866.393038787638);
     glVertex2f(1771.0140346327357, 852.9395665491968);


     glColor3ub(72,152,144);
	glVertex2f(1618.8238431137643, 855.875334652148);
    glVertex2f(1618.8238431137643, 500);
    glVertex2f(1726.5728139426787, 500);
     glVertex2f(1726.5728139426787, 858.7430859629859);

     glColor3ub(121,189,174);
	glVertex2f(1726.5728139426787, 500);
     glVertex2f(1726.5728139426787, 858.7430859629859);
    glVertex2f(1788.5433903057174, 852.8334184057992);
     glVertex2f(1788.5433903057174, 500);



glEnd();

/*glLineWidth(2);
glBegin(GL_LINES);            // These vertices form a closed polygon

glColor3ub(39,126,123);
	glVertex2f(1625.2668454495615, 847.8927109212275);
    glVertex2f(1722.2702478560523, 851.9394275505355);

    glVertex2f(1731.172393250053, 851.6446926714979);
	glVertex2f(1782.1009854162717, 844.8185559152038);

	glVertex2f(1782.1009854162717, 844.8185559152038);
	glVertex2f(1782.1009854162717, 500);
glEnd();
*/

glBegin(GL_POLYGON);            // These vertices form a closed polygon
if (day)
    {
glColor3ub(99,177,159);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }
	glVertex2f(1722.1084409206546, 852.0506658298315);
    glVertex2f(1625.1746397180746, 848.1851655845973);

    glVertex2f(1625.1746397180746, 500);
	glVertex2f(1722.1084409206546, 500);


glEnd();

glBegin(GL_POLYGON);            // These vertices form a closed polygon
if (day)
    {
glColor3ub(141,210,189);
    }
    else{
        glColor3ub(255, 217, 102);  // Warm indoor yellow
    }


	glVertex2f(1731.1994612669273, 852.1772957883386);
    glVertex2f(1783.3421310848123, 846.9860009725688);

    glVertex2f(1783.3421310848123, 500);
	glVertex2f(1731.1994612669273, 500);


glEnd();

b12windows(0,0,0);
b12windows(15,0,0);
b12windows(30,0,0);
b12windows(45,0,0);
b12windows(60,0,0);
b12windows(75,0,0);






b12windows1(0,0,0);
b12windows1(15,0,0);
b12windows1(30,0,0);
b12windows1(45,0,0);

b12windows2(0,0,0);
b12windows2(0,-35,0);
b12windows2(0,-70,0);
b12windows2(0,-105,0);
b12windows2(0,-140,0);
b12windows2(0,-175,0);
b12windows2(0,-210,0);
b12windows2(0,-245,0);
b12windows2(0,-280,0);





b12windows3(0,0,0);
b12windows3(0,-35,0);
b12windows3(0,-70,0);
b12windows3(0,-105,0);
b12windows3(0,-140,0);
b12windows3(0,-175,0);
b12windows3(0,-210,0);
b12windows3(0,-245,0);
b12windows3(0,-280,0);









}
//49
void b12windows(float x,float y,float z)
{
     glPushMatrix();
    glTranslatef(x,y,z);
    glLineWidth(3);
glBegin(GL_LINES);            // These vertices form a closed polygon

     glColor3ub(72,152,144);
	glVertex2f(1636.5617762114744, 849.8020370199961);
    glVertex2f(1636.5617762114744, 500);
glEnd();
glPopMatrix();
}
//50
void b12windows1(float x,float y,float z)
{
     glPushMatrix();
    glTranslatef(x,y,z);
    glLineWidth(3);
glColor3ub(95,174,161);

glBegin(GL_LINES);            // These vertices form a closed polygon

	glVertex2f(1743.268903131137, 851.1717581422821);
    glVertex2f(1743.268903131137, 500);
glEnd();
glPopMatrix();
}
//51
void b12windows2(float x,float y,float z)
{
     glPushMatrix();
    glTranslatef(x,y,z);
    glLineWidth(5);
     glColor3ub(72,152,144);

glBegin(GL_LINES);            // These vertices form a closed polygon

	glVertex2f(1722.1084409206546, 824.6006971249511);
    glVertex2f(1625.1746397180746, 821.4431242137986);
glEnd();
glPopMatrix();
}
//52
void b12windows3(float x,float y,float z)
{
     glPushMatrix();
    glTranslatef(x,y,z);
    glLineWidth(5);
glColor3ub(95,174,161);

glBegin(GL_LINES);            // These vertices form a closed polygon

	glVertex2f(1731.1994612669273, 824.4325244811106);
    glVertex2f(1783.3421310848123, 820.8244935152201);
glEnd();
glPopMatrix();
}
//53
void building13(){
glBegin(GL_QUADS);            // These vertices form a closed polygon

glColor3ub(70,156,143);
	glVertex2f(1766.3509414314312, 716.4473740656556);
    glVertex2f(1760.3529111101038, 702.7667934440288);
    glVertex2f(1868.9740773175918, 702.3840757835121);
	glVertex2f(1868.7422987234793, 724.0233898720235);
glColor3ub(104,178,162);
   glVertex2f(1868.9740773175918, 702.3840757835121);
	glVertex2f(1868.7422987234793, 724.0233898720235);
	glVertex2f(1900, 722.1581795888602);
    glVertex2f(1900, 701.3379283231908);

glColor3ub(83,166,151);
	glVertex2f(1751.3373225398689, 702.0938681359517);
    glVertex2f(1751.3373225398689, 500);
    glVertex2f(1868.9740773175918, 500);
     glVertex2f(1868.9740773175918, 702.3840757835121);

glColor3ub(134,197,177);
 glVertex2f(1868.9740773175918, 500);
     glVertex2f(1868.9740773175918, 702.3840757835121);
	glVertex2f(1900, 701.3379283231908);
    glVertex2f(1900,500);



glEnd();

b13windows(0,0,0);
b13windows(0,-20,0);
b13windows(0,-40,0);
b13windows(0,-60,0);
b13windows(0,-80,0);
b13windows(0,-100,0);
b13windows(0,-120,0);



}
//54
void b13windows(float x,float y,float z)
{

     glPushMatrix();
    glTranslatef(x,y,z);
    glLineWidth(6);
glBegin(GL_LINES);            // These vertices form a closed polygon

	glColor3ub(72,157,142);
	glVertex2f(1868.9740773175918, 684.8319948020925);
    glVertex2f(1900, 682.95247448);
	glColor3ub(63,153,138);

	glVertex2f(1868.9740773175918, 684.8319948020925);
    glVertex2f(1764.693030305737, 684.0974848668756);

glEnd();
glPopMatrix();
}
//55
void backbuildings(){

glBegin(GL_QUADS);            // These vertices form a closed polygon

glColor3ub(150,200,176);
	glVertex2f(0,690);
    glVertex2f(0,660);
    glVertex2f(39.4120639176526,660);
	glVertex2f(39.4120639176526,690);

	glVertex2f(190.2668443275244,677.3578883941343);
    glVertex2f(212.014591332448, 677.9140306256936);
    glVertex2f(212.014591332448, 500);
   glVertex2f(190.2668443275244, 500);

   glVertex2f(858.1745611482783, 678.230184400296);
    glVertex2f(890, 680);
   glVertex2f(890, 500);
   glVertex2f(858.1745611482783, 500);

   glVertex2f(1349.4839541909462, 694.93951920975);
    glVertex2f(1400.21713998978, 693.7845682422139);
   glVertex2f(1400.21713998978, 500);
   glVertex2f(1349.4839541909462, 500);

   glVertex2f(1577.0951068570143, 706.7721123648147);
    glVertex2f(1640.0000403381214, 706.7721123648147);
   glVertex2f(1640.0000403381214, 500);
   glVertex2f(1577.0951068570143, 500);

glColor3ub(162,208,185);
   glVertex2f(1811.775219857878, 761.1473530915996);
    glVertex2f(1811.775219857878, 500);
   glVertex2f(1868.7397177127818, 500);
   glVertex2f(1868.8187795300191, 764.3272960266688);
glColor3ub(189,220,198);
    glVertex2f(1868.7397177127818, 500);
   glVertex2f(1868.8187795300191, 764.3272960266688);
   glVertex2f(1900, 761.2791611595416);
   glVertex2f(1900, 500);


glEnd();
}

#define NUM_BIRDS 7

float birdXa[NUM_BIRDS] = {50,100, 150, 200, 250, 300,375};
float birdYa[NUM_BIRDS] = {910,900, 920, 910, 930, 905, 925};
float wingAnglea[NUM_BIRDS] = {0};
bool flapUpa[NUM_BIRDS] = {true};



//57
void AnimatedBirda(float x, float y, float scale, float wing) {
    glColor3ub(255, 255, 255);  // Black bird

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
 //glColor3ub(1, 1, 1);
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
//a1
void updateBirda(int value) {
    for (int i = 0; i < NUM_BIRDS; i++) {
        // Flap logic
        if (flapUpa[i]) {
            wingAnglea[i] += 2;
            if (wingAnglea[i] >= 20) flapUpa[i] = false;
        } else {
            wingAnglea[i] -= 2;
            if (wingAnglea[i] <= -20) flapUpa[i] = true;
        }

        // Move birds horizontally
        birdXa[i] += 1;
        if (birdXa[i] > 2000) birdXa[i] = -100;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateBirda, 0);  // ~60 FPS
}
//58
void bridge(float x,float y, float z) {

    glBegin(GL_QUADS);
glColor3f(0.0f, 0.4f, 0.5f);

glVertex2f(1221.7805146789606, 474.0814693293047);
glVertex2f(1232.1494481411928, 487.477436496731);
glVertex2f(1900, 487.477436496731);
glVertex2f(1900, 474.0814693293047);

glEnd();

glLineWidth(3);
glBegin(GL_LINES);
glColor3f(0.0f, 0.4f, 0.5f);

glVertex2f(1241.599563670873, 499.8312208310168);
glVertex2f(1900, 499.6594544400052);



glEnd();
glPushMatrix();
glTranslatef(x,y,z);
glBegin(GL_LINES);
glColor3f(0.0f, 0.4f, 0.5f);

glVertex2f(1309.1582538, 499.8312208310168);
glVertex2f(1309.1582538, 487.477436496731);

glEnd();
glPopMatrix();


   // Setup arch control points based on your earlier inputs
    GLfloat archCtrl[3][2];

    GLfloat leftStart[2]  = {1181.676575f, 450.176443f};
    GLfloat leftEnd[2]    = {1207.372016f, 449.178562f};
    GLfloat rightStart[2] = {1741.704903f, 447.023386f};
    GLfloat rightEnd[2]   = {1771.311806f, 447.369171f};

    // Average left and right pairs to get start and end points
    archCtrl[0][0] = (leftStart[0] + leftEnd[0]) / 2.0f;
    archCtrl[0][1] = (leftStart[1] + leftEnd[1]) / 2.0f;
    archCtrl[2][0] = (rightStart[0] + rightEnd[0]) / 2.0f;
    archCtrl[2][1] = (rightStart[1] + rightEnd[1]) / 2.0f;

    // Set middle control point with adjustable height
    GLfloat archHeight = 400.0f; // Increase this for a higher arch
    archCtrl[1][0] = (archCtrl[0][0] + archCtrl[2][0]) / 2.0f;
    archCtrl[1][1] = ((archCtrl[0][1] + archCtrl[2][1]) / 2.0f) + archHeight;

    // Thickness and resolution settings
    GLfloat resolution = 0.01f;
    GLfloat archThickness = 25.0f;

    // Draw the filled arch
    glColor3f(0.0f, 0.4f, 0.5f);  // Arch color
    glBegin(GL_QUAD_STRIP);
    for (GLfloat t = 0.0f; t <= 1.0f; t += resolution) {
        GLfloat x = (1 - t) * (1 - t) * archCtrl[0][0]
                  + 2 * (1 - t) * t * archCtrl[1][0]
                  + t * t * archCtrl[2][0];
        GLfloat y = (1 - t) * (1 - t) * archCtrl[0][1]
                  + 2 * (1 - t) * t * archCtrl[1][1]
                  + t * t * archCtrl[2][1];

        glVertex2f(x, y + archThickness / 2.0f);
        glVertex2f(x, y - archThickness / 2.0f);
    }
    glEnd();

/*glTranslatef(0,-10,0);
//float centerX = (900.6401f + 1206.2070f + 1218.4676f + 1500.0495f) / 4.0f;
//float centerY = (448.6333f + 448.6333f + 473.1798f + 478.2669f) / 4.0f;

//glPushMatrix();


// Step 1: Move the quad center to origin
glTranslatef(centerX, centerY, 0);

// Step 2: Scale around the origin (which is now quad center)
glScalef(0.9f, 0.9f, 1.0f);

// Step 3: Move back to original position
glTranslatef(-centerX, -centerY, 0);
glTranslatef(0, -13, 0);*/
glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.4f, 0.5f);

glVertex2f(1195.270461039821, 438.706985478647);
glVertex2f(1177.7593191550984,438.706985478647);
glVertex2f(1195.7039051458785, 464.020121272328);


glVertex2f(1756.0783908544845, 435.4415152859334);
glVertex2f(1769.5409034805077, 435.4415152859334);
glVertex2f(1755.6553581320043, 459.9657341248509);
glEnd();


glLineWidth(5);
glBegin(GL_LINES);
glColor3f(0.0f, 0.4f, 0.5f);

glVertex2f(1280.00070445,543.054062277);
glVertex2f(1280.00070445, 487.477436496731);

glVertex2f(1340.61721330,591.824667335);
glVertex2f(1340.61721330, 487.477436496731);

glVertex2f(1402.6117873,623.5543985);
glVertex2f(1402.6117873, 487.477436496731);


glVertex2f(1469.4937157700922, 635.5883501459688);
glVertex2f(1469.4937157700922, 487.477436496731);

glVertex2f(1538.2407845, 626.810922244);
glVertex2f(1538.2407845, 487.477436496731);

glVertex2f(1611.689816467, 590.85546782);
glVertex2f(1611.689816467, 487.477436496731);

glVertex2f(1678.5548807, 534.17623329);
glVertex2f(1678.5548807, 487.477436496731);

glEnd();


//glPopMatrix();

}
//59
void bushes(float x,float y,float z){
glPushMatrix();
glTranslatef(x,y,z);
glBegin(GL_POLYGON);
glColor3ub(92,151,89);
glVertex2f(1029.5435700688265, 487.7008728771939);
glVertex2f(1029.5435700688265, 574.6838532523994);
glVertex2f(1037.827854651075, 577.7592896081736);
glVertex2f(1047.240026055702, 578.1897549101767);
glVertex2f(1048.4086599416275, 587.2049306016039);
glVertex2f(1052.8066567255103, 596.2491188287817);
glVertex2f(1059.9895111118672, 603.1168144455884);
glVertex2f(1071.9470577471523, 609.7089626232931);
glVertex2f(1081.288135958985, 612.0248099627037);
glVertex2f(1092.5434283247516, 613.872693783949);
glVertex2f(1102.7907840607484, 613.3687254690639);
glVertex2f(1112.0302031669748, 610.0089367031633);
glVertex2f(1117.9098335073006, 605.9771901840826);
glVertex2f(1123.9574532859215, 601.1054964735268);
glVertex2f(1129.5011047496575, 593.3779823119555);
glVertex2f(1131.8529568857878, 587.3303625333346);
glVertex2f(1132.3569252006728, 581.9547005078936);
glVertex2f(1140, 580);
glVertex2f(1147.4779843767424, 573.5871008215162);
glVertex2f(1152.4928124597736, 569.3251613513817);
glVertex2f(1156.4080035509808, 574.762926755836);
glVertex2f(1164.3471410414838, 580.3094474683793);
glVertex2f(1175.9405511771265, 580.832915100943);
glVertex2f(1187.16371363999, 586.7939158339328);
glVertex2f(1200.5063625669736, 586.3769580549646);
glVertex2f(1213.432053714989, 583.4582536021869);
glVertex2f(1222.5158571859417, 576.8166588733061);
glVertex2f(1228.658056403061, 567.8280746531316);
glVertex2f(1234.7407793012649, 570.6902620316878);
glVertex2f(1242.1651520779708, 568.4302917995426);
glVertex2f(1249.4308593870214, 568.4277402728098);
glVertex2f(1257.7371393406993, 572.6034216836613);
glVertex2f(1264.5908589404598, 572.4460848591659);
glVertex2f(1284.0476284861936, 563.2753130337354);
glVertex2f(1309.4082600296767, 553.1935866324238);
glVertex2f(1309.4082600296767, 487.7008728771939);

glEnd();



glBegin(GL_POLYGON);
glColor3ub(92,151,89);
glVertex2f(1309.4082600296767, 487.7008728771939);
glVertex2f(1309.4082600296767, 553.1935866324238);
glVertex2f(1314.3197223996124, 559.5698251665114);
glVertex2f(1320, 565);
glVertex2f(1326.5918347941322, 565.0340503932683);
glVertex2f(1333.2205670364276, 561.0030645702509);

glVertex2f(1338.0577500240486, 556.7033463590323);
glVertex2f(1342.805355548936, 554.8222196416242);
glVertex2f(1347.9890498726547, 555.1888554150863);
glVertex2f(1349.1251148350757, 560.3210410898081);
glVertex2f(1350.6568462437056, 564.1567002976498);
glVertex2f(1352.3691085100786, 567.6185535585059);
glVertex2f(1355.1385051738278, 567.9100689967953);
glVertex2f(1358.00507365034, 566.8897649627826);
glVertex2f(1360.9300877628864, 565.3911256164959);
glVertex2f(1364.0636528415043, 563.8676316658737);
glVertex2f(1367.6106309613913, 565.2260488181709);
glVertex2f(1369.9501271681254, 569.2258326554902);
glVertex2f(1373.8285869843946, 572.9081179455478);
glVertex2f(1378.9903962501764, 575.2124970820576);
glVertex2f(1385.1661323360224, 576.5951245639634);
glVertex2f(1390.2357664363437, 577.3325258876465);
glVertex2f(1393.7559189050514, 578.3425070756642);
glVertex2f(1398.3661864355115, 578.9264185889754);
glVertex2f(1403.7928455147442, 579.5648490688851);
glVertex2f(1410, 580);
glVertex2f(1414.431229177917, 578.3341177527893);
//glVertex2f(1414.431229177917, 489.7008728771939);

glVertex2f(1418.9790536567189, 576.5786514986246);
glVertex2f(1422.9637688741125, 574.2635483564393);
glVertex2f(1425.8580904071734, 571.8162414406174);
glVertex2f(1429.7309319173855, 568.3760646561228);
glVertex2f(1432.9920615297613, 564.7422345166184);
glVertex2f(1436.1678206861338, 561.2590433834205);
glVertex2f(1440.6376638923423, 561.3953136963096);
glVertex2f(1444.434451012717, 561.9475736410914);
glVertex2f(1447.2647832297237, 561.533378682505);
glVertex2f(1450.7854403777078, 558.9791764378895);


glVertex2f(1454.444162511887, 556.7701366587626);
glVertex2f(1457.2930422534796, 554.6478138656441);
glVertex2f(1460.687629757872, 554.9887107619393);
glVertex2f(1463.8346632867315, 554.9887107619393);
glVertex2f(1465.7001348693086, 553.1605006491691);
glVertex2f(1467.6247342843706, 551.4527575062269);
glVertex2f(1470.2937835794812, 551.5033200945836);
glVertex2f(1472.1659094547183, 550.9335426542941);
glVertex2f(1473.5215264028852, 549.3865244838734);
glVertex2f(1475.4924736127546, 549.4724790632522);
glVertex2f(1476.9174481696111, 551.418069088114);
glVertex2f(1478.693983290468, 553.2647179598008);
glVertex2f(1480.0651851604562, 554.988149428145);
glVertex2f(1481.4824713516641, 556.3539253217143);
glVertex2f(1482.5352845816697, 557.2714364844875);
glVertex2f(1484.187382585615, 558.63582389076);
glVertex2f(1486, 560);
glVertex2f(1488.1624012175294, 561.0064675326851);
glVertex2f(1489.9822892658758, 561.5093313355177);
glVertex2f(1492.536168025753, 561.520161580968);
glVertex2f(1494.9039180443287, 561.5741831503892);
glVertex2f(1497.0627086146476, 562.2735286546505);
glVertex2f(1498.9194180511756, 562.303939950835);
glVertex2f(1501.5867468223546, 562.7572501875957);


glVertex2f(1504.7962609165415, 562.8877978818351);
glVertex2f(1507.6303910656977, 563.8058963808573);
glVertex2f(1510.4564061867907, 563.6949769879977);
glVertex2f(1513.2814113087193, 564.1324404923901);
glVertex2f(1515.9637329803018, 564.9446309072183);
glVertex2f(1518.3664343674102, 564.5894489630371);
glVertex2f(1520.5623476239746, 563.6659942170429);
glVertex2f(1523.339889634324, 563.0850743185518);
glVertex2f(1525.5661731557655, 562.7288689551212);
glVertex2f(1527.725741240229, 561.9066183629751);
glVertex2f(1529.5799101191662, 560.8557387258921);
glVertex2f(1530.8498860466527, 559.8792260476761);
glVertex2f(1531.7107156749432, 558.6325072756688);
glVertex2f(1510.4564061867907, 563.6949769879977);
glVertex2f(1520.1319077610888, 564.150700524539);
glVertex2f(1527.725741240229, 561.9066183629751);
glVertex2f(1531.7241270986474, 559.3571850578987);
glVertex2f(1531.7107156749432, 558.6325072756688);
glVertex2f(1531.8139078153836, 556.9728379681812);
glVertex2f(1532.1862407647532, 554.7920306933025);
glVertex2f(1532.9568767263797, 553.3988951905256);
glVertex2f(1534.6763922195153, 553.8611080177583);
glVertex2f(1536.1395903577434, 553.5418647875994);
glVertex2f(1537.5516146792022, 554.9112614456535);
glVertex2f(1539.3345535661326, 556.6517494067043);
glVertex2f(1541.5861241205066, 557.5080606163002);
glVertex2f(1543.7380050510317, 558.860004703636);
glVertex2f(1546.0326449780198, 559.1299623421053);
glVertex2f(1547.724389789729, 559.1375747176597);
glVertex2f(1550.3017122757844, 560.5787351301279);
glVertex2f(1553.4082973565191, 561.088743605822);
glVertex2f(1555.7344402401236, 561.2748350365104);
glVertex2f(1558.3527356403226, 561.195821559059);
glVertex2f(1560.44796112892, 561.0825661272429);
glVertex2f(1562.4210343663913, 560.4031254828811);
glVertex2f(1564.4119012424828, 558.7608297750135);
glVertex2f(1566.850663150382, 558.3022614247627);
glVertex2f(1569.2433128153516, 558.3022614247627);
glVertex2f(1571.5094795754485, 557.5151955219244);
glVertex2f(1573.1532525117655, 555.9096117597933);
glVertex2f(1575, 555);
glVertex2f(1577.8233547010284, 554.3718148119476);
glVertex2f(1579.7109137131083, 553.44945154444);
glVertex2f(1581.961287757605, 552.0429677666295);
glVertex2f(1585, 550);
glVertex2f(1586.349517144374, 548.7799254021095);
glVertex2f(1587.8932334666895, 547.3026156213218);
glVertex2f(1589.3135369908096, 547.1343705074319);
glVertex2f(1590.6959788432312, 547.6710832266074);


glVertex2f(1591.5905000418568, 548.5005483380604);
glVertex2f(1592.273588957171, 549.4438616020659);
glVertex2f(1593.444598526281, 550.5660791057965);
glVertex2f(1594.696928204357, 551.6720325877338);
glVertex2f(1595.601883253539, 552.6292342311272);
glVertex2f(1596.8627259513257, 553.6480803605767);
glVertex2f(1597.9275194557483, 554.0034738051597);
glVertex2f(1600, 555);
glVertex2f(1603.040742377254, 556.848171765862);
glVertex2f(1607.0396410927594, 557.9387805064543);
glVertex2f(1611.6201978032475, 558.7385602495553);
glVertex2f(1614.489108793444, 559.1375747176597);
glVertex2f(1617.00032615353, 559.3387046902113);
glVertex2f(1620.01621539932, 559.1950909166023);
glVertex2f(1623.319332192328, 558.6206358221663);

glVertex2f(1626.4788352117266, 557.7589531805121);
glVertex2f(1628.7048487026668, 556.3946223312264);
glVertex2f(1631.218089740825, 557.3999187464896);
glVertex2f(1633.369761394154, 556.0926126074618);
glVertex2f(1635.8524243593395, 555.0703396217973);
glVertex2f(1638.9192433163332, 555.4354371166775);
glVertex2f(1641.7174495826416, 554.29989486442);
glVertex2f(1644.0694989581652, 552.7971966522803);
glVertex2f(1646.0295401044348, 550.445147276757);
glVertex2f(1648.1202506604557, 549.0077837694928);
glVertex2f(1649.4922794628442, 547.1130773280992);
glVertex2f(1651.6730408327526, 547.707440167104);
glVertex2f(1654.2944934550505, 549.2459981617438);
glVertex2f(1656.9189632048083, 549.6122032431053);
glVertex2f(1658.688954431389, 549.4901348826515);
glVertex2f(1661.0082532800122, 548.8797930803823);
glVertex2f(1662.6561761461392, 547.2318702142555);


glVertex2f(1664.9144408145353, 547.2929043944824);
glVertex2f(1666.867534581797, 549.4901348826515);
glVertex2f(1670, 550);
glVertex2f(1673.091039885347, 549.6886491235535);
glVertex2f(1675.9831065170429, 549.2320070238122);
glVertex2f(1677.5756694946426, 549.4694936999912);
glVertex2f(1679.6362433149743, 548.394829840953);
glVertex2f(1682.8327380131645, 546.4921544253639);
glVertex2f(1685.953125694731, 544.8178000596455);
//glVertex2f(1685.953125694731, 487.7008728771939);

glVertex2f(1690.0477687661191, 545.5475194622205);
glVertex2f(1693.1409793554285, 546.6586550664267);
glVertex2f(1695.2272359503756, 547.3061625215445);
glVertex2f(1698.3430762938951, 547.9774965437844);
glVertex2f(1703.2520973485045, 548.4171103695702);
glVertex2f(1706.109587216113, 548.124034485713);
glVertex2f(1710.6522634159007, 547.6844206599271);
glVertex2f(1714.7249659871575, 547.4445614513018);
glVertex2f(1719.9829890786666, 547.122641670189);
glVertex2f(1725.0832931573766, 547.3061625215445);


glVertex2f(1728.2455967938952, 548.3030142009358);

glVertex2f(1732.3232473546573, 549.5906933253868);
glVertex2f(1735, 550);
glVertex2f(1737.7099357741354, 550.0340684236525);
glVertex2f(1740, 550);

glVertex2f(1740, 487.7008728771939);



glEnd();
glBegin(GL_POLYGON);
glVertex2f(1740, 487.7008728771939);
glVertex2f(1740, 550);


//glVertex2f(1741.9793883832706, 487.7008728771939);
glVertex2f(1742.9793883832706, 551.8762769632872);
glVertex2f(1745.0399792570222, 553.9288208617851);
glVertex2f(1746.7792793201488, 556.0790663229795);
glVertex2f(1748.8059582464361, 558.1057452492669);
glVertex2f(1751.1093863444764, 559.7910578349373);
glVertex2f(1754.1634037375359, 559.7307952430438);
glVertex2f(1756.6456256592467, 561.3463554359927);
glVertex2f(1759.4420144553278, 562.9603370667027);
glVertex2f(1761.7561309436378, 563.6409595632643);
glVertex2f(1764, 564);


glVertex2f(1764.8869944278222, 565.9097012184702);
glVertex2f(1765.5208395704758, 567.2656289495751);
glVertex2f(1766.701987751987, 569.7211871992159);
glVertex2f(1768.4134000737413, 571.9806432814024);
glVertex2f(1770.6714872336795, 573.2709788013669);
glVertex2f(1772.3515956451054, 573.437028669373);

glVertex2f(1774.396974999581, 574.332854599755);
glVertex2f(1776.8797887142832, 574.5410320291248);
glVertex2f(1780.0822391663312, 574.3688372843542);

glVertex2f(1782.4596356376596, 574.9010221532136);
glVertex2f(1786.0595368785475, 574.7210270911692);
glVertex2f(1790.113219800033, 574.7977769464786);
glVertex2f(1793.370850210336, 576.5596574416688);
glVertex2f(1796.594171699982, 578.9903588928771);
glVertex2f(1800.5572718921699, 581.7909496953562);
glVertex2f(1804.4146894125658, 583.5875551158144);
glVertex2f(1806.8732381291095, 585.1808462475575);
glVertex2f(1809.7319324564105, 586.2008810693512);
glVertex2f(1814.0361100124803, 586.3382484381619);
glVertex2f(1818.0256797195104, 586.50111486317);

glVertex2f(1821.9308638784987, 586.5895239440592);
glVertex2f(1825.3437918832683, 585.7709102980682);
glVertex2f(1828.6198515967042, 584.4124424523659);
glVertex2f(1831.5555905115918, 582.9219903878844);
glVertex2f(1834.7171554968554, 580.4379036137489);
glVertex2f(1837.2348994464714, 578.0350698707284);
glVertex2f(1840, 575);
glVertex2f(1842.3424274039444, 571.0740709322217);
glVertex2f(1844.023031945101, 567.8540881979428);
glVertex2f(1846.441069366128, 566.3288544670747);

glVertex2f(1848.9596172523961, 566.8734053614029);
glVertex2f(1851.3040015636905, 566.6242580652846);
glVertex2f(1853.9553668819199, 565.3841033196613);
glVertex2f(1857.2085878685489, 563.1394378271458);
glVertex2f(1860, 560);
glVertex2f(1862.9056059482573, 556.951671813453);
glVertex2f(1864.9343524548085, 553.599829759151);
glVertex2f(1867.8241297865588, 550.547012063954);

glVertex2f(1870.8361213409253, 552.4304835464146);
glVertex2f(1873.5138339702273, 554.7626848687099);
glVertex2f(1876.3692241177325, 556.5327107216988);
glVertex2f(1880, 558);
glVertex2f(1883.6967735711494, 558.5489831456072);
glVertex2f(1887.4100526071, 558.4826745913938);
glVertex2f(1890.9907145346235, 558.4163660371803);
glVertex2f(1894.1735251368668, 557.8858976034732);
glVertex2f(1897.4889528475371, 557.2228120613393);
glVertex2f(1900, 556.35902);
glVertex2f(1900, 556.35902);

glVertex2f(1900,487.7008728771939);





glEnd();
glPopMatrix();

}
//60
void waves(float x,float y,float z){
glPushMatrix();
glTranslatef(_move, 0, 0);


glTranslatef(x, y, z);
//glTranslatef(x,y,z);
glLineWidth(2);

glBegin(GL_LINES);
glColor3ub(152,201,175);

glVertex2f(1580.9485359739483, 368.6038588945257);
glVertex2f(1642.0312881629854,368.6038588945257);


glEnd();
glPopMatrix();


}
//61
void boat1(){
glPushMatrix();
glTranslatef(boat_move1,0,0);
    glBegin(GL_POLYGON);               //boat waves
glColor3ub(186,215,185);

glVertex2f(1317.0820663825375,293.9251614146244);
glVertex2f(1525.253664291376, 293.9251614146244);
glVertex2f(1525.253664291376, 291.4239570740714);
glVertex2f(1547.1968489090789,  291.4239570740714);
glVertex2f(1548.59110256947, 292.4700648373619);

glVertex2f(1549.9658151845565, 292.9099728741896);
glVertex2f(1552.6877461624276, 293.0474441356982);
glVertex2f(1648.624991777439, 293.0474441356982);
glVertex2f(1648,  291.7094197809329);
glVertex2f(1585.0070451190338, 291.7094197809329);
glVertex2f(1583.896508967472, 291.5459305030535);
glVertex2f(1582.7843081169901, 291.153735530422);
glVertex2f(1582.1881867675352, 290.4668720009444);
glVertex2f(1582.9711402256646, 289.9231543216877);
glVertex2f(1634.1405897534398,289.9231543216877);
glVertex2f(1632.8160612224644, 287.4593878195439);
glVertex2f(1583.9328397334696,287.4593878195439);
glVertex2f(1583.9328397334696, 285.3819806013965);
glVertex2f(1505.2569958423007,285.3819806013965);
glVertex2f(1497.0968458631505, 283.9389606168097);
glVertex2f(1486.3070306666114,  283.9389606168097);
glVertex2f(1478.5284033899804, 283.2868501454884);
glVertex2f(1445.0968712442896, 283.2868501454884);

glVertex2f(1441.53810876694,  282.3119979831747);
glVertex2f(1336.4281638237312, 282.3119979831747);
glVertex2f(1334.4154363366647, 284.1498276793825);
glVertex2f(1318.7880532686117,  284.1498276793825);
glVertex2f(1318.7880532686117, 286.3006413771472);
glVertex2f(1309.9896396429306,286.3006413771472);
glVertex2f(1308.6305700583787, 286.8831417439415);
glVertex2f(1307.3826758652817, 287.5830953778383);
glVertex2f(1306.7364424757664, 288.2404707223456);
glVertex2f(1307.171821956464, 288.8999023555921);
glVertex2f(1307.7961297119996, 289.4324001470783);
glVertex2f(1308.563723094396, 289.8671961511261);

glVertex2f(1309.5605915209558, 290.30744666014);
glVertex2f(1310.8551855418646, 290.8828217805441);
glVertex2f(1312.8148564959035, 291.5290762668891);
glVertex2f(1314.9307593113926, 292.0575459847025);
glVertex2f(1317.0820663825375,293.9251614146244);





glEnd();



glBegin(GL_QUADS);               //boat waves
glColor3ub(186,215,185);

//glColor3ub(152,201,175);

glVertex2f(1674.184429876447, 298.4067511137134);
glVertex2f(1656.7740954458716, 295.1944670672174);
glVertex2f(1526.3811212565772, 295.1944670672174);
glVertex2f(1525.461437895182,  298.4067511137134);



glEnd();


 glBegin(GL_QUADS);
glColor3ub(34,102,97);

glVertex2f(1529.6782052163942, 316.6834609416158);
glVertex2f(1529.6782052163942, 312.3628318220033);
glVertex2f(1289.3209409590618, 312.3628318220033);
glVertex2f(1284.982946462528, 317.1891793102082);
glVertex2f(1281.7216401616183, 317.4812830793558);


glEnd();


glBegin(GL_POLYGON);
glColor3ub(154,181,152);

glVertex2f(1289.3209409590618, 312.3628318220033);
glVertex2f(1529.6782052163942, 312.3628318220033);
glVertex2f(1530, 308);
glVertex2f(1529.4696416795714, 304.3456186038159);
glVertex2f(1528.4715957882572, 300.8369601538029);

glVertex2f(1527.461437895182, 297.9140951906034);
glVertex2f(1526.3811212565772, 295.706491624758);
glVertex2f(1525.253664291376, 293.9251614146244);
glVertex2f(1317.0820663825375,293.9251614146244);
glVertex2f(1311.9102107867334, 295.0129434090741);
glVertex2f(1307.2757541365174, 297.5544196366132);
glVertex2f(1303.0150439903512, 300.619140969822);
glVertex2f(1299.5018268522842, 303.085867896551);
glVertex2f(1295.6896125109774, 306.1505892297598);
glVertex2f(1292.77438977939, 308.8415640589188);
glVertex2f(1289.3209409590618, 312.3628318220033);



glEnd();


glBegin(GL_POLYGON);
glColor3ub(1,1,1);

glVertex2f(1317.0820663825375,293.9251614146244);
glVertex2f(1525.253664291376, 293.9251614146244);
glVertex2f(1525.253664291376, 290.2564169024448);
glVertex2f(1505.996583606524, 290.2564169024448);
glVertex2f(1505, 290);

glVertex2f(1503.7233172580152, 289.4461586644683);
glVertex2f(1502.3287212246435, 288.9339545528492);
glVertex2f(1465.6811993777087, 288.9339545528492);
glVertex2f(1464.0260657846702, 286.7562432345291);
glVertex2f(1420.6942000278837,286.7562432345291);
glVertex2f(1420.6942000278837, 284.7249401134718);
glVertex2f(1382.2282634767137, 284.7249401134718);
glVertex2f(1382.2282634767137, 286.2715259428549);
glVertex2f(1360.2281951308776,286.2715259428549);
glVertex2f(1360.2281951308776, 288);
glVertex2f(1339.7300032256576, 288);
glVertex2f(1339.7300032256576, 289.7134238940928);
glVertex2f(1325.3931440031106,  289.7134238940928);
glVertex2f(1325.3931440031106,293.9251614146244);
glVertex2f(1317.0820663825375,293.9251614146244);




glEnd();



glBegin(GL_POLYGON);
glColor3ub(234,227,189);

glVertex2f(1298.4998156089316, 316.6834609416158);
glVertex2f(1293.3051493352996, 316.6854669554193);
glVertex2f(1288.5194015480924, 316.9155128338068);
glVertex2f(1284.982946462528, 317.1891793102082);
glVertex2f(1281.7216401616183, 317.4812830793558);
glVertex2f(1278.338782135107, 318.3560039696043);
glVertex2f(1275.9943170571723, 319.5747799962153);
glVertex2f(1274.9595974082474, 321.5019571489278);
glVertex2f(1275.8202809039583, 323.5776115201389);
glVertex2f(1278.2878415180799, 324.8841540537463);
glVertex2f(1281.5565294246867, 326.0326119668785);
glVertex2f(1285.733536688338, 327.2766649302298);
glVertex2f(1289.5601587945696, 328.2816363924724);
glVertex2f(1293.4175853772774, 329.112341067553);
glVertex2f(1297.4018290903987, 329.6518740703716);
glVertex2f(1301.5935854969116, 330.2329096118685);
glVertex2f(1305.5736326321035, 330.4811949524409);
glVertex2f(1309.5065053902656, 330.772518860453);

glVertex2f(1313.7056387752343, 330.7293938946372);
glVertex2f(1318.2108151013451, 330.8401173385902);
glVertex2f(1322.764035725498, 330.8401173385902);
glVertex2f(1326.9873128261615, 330.7411342815433);
glVertex2f(1330.825227823426, 330.6557302524226);
glVertex2f(1333.99208812582, 330.5803288166513);
glVertex2f(1335.0115555327686, 330.6387336174543);
glVertex2f(1335.7325026195756, 330.9710536232091);
glVertex2f(1337.5207592100664, 332.5419000352281);
glVertex2f(1347.4311520684225, 342.98588278689);
glVertex2f(1360.4438278996536, 351.6834815388939);
glVertex2f(1361.4945167031547, 352.7375042012943);
glVertex2f(1362.6207580836042, 353.4955512842893);
glVertex2f(1365, 355);
glVertex2f(1366.350542101835, 355.9086586056661);
glVertex2f(1369.3648196879717, 357.4915086166502);
glVertex2f(1371.0316230401638, 358.1793890086762);
glVertex2f(1372.034120719138, 358.4021662706705);

glVertex2f(1373.3640414716597, 358.5062325605974);
glVertex2f(1467.1116155594777,358.5062325605974);
glVertex2f(1471.0788330124744, 358.0235801577994);
glVertex2f(1475.74065941963, 356.0577497451425);
glVertex2f(1479.9224119466112, 353.4694846390621);
glVertex2f(1484.3341466520974, 351.0027572554535);
glVertex2f(1488.7736961198982, 347.3651507264502);
glVertex2f(1492.1310797718345, 343.5499420310678);
glVertex2f(1496.4041135106627, 339.2769082922395);
glVertex2f(1500.6045860400895, 336.2035023923557);
glVertex2f(1505.6746303543987, 332.2008358284275);
glVertex2f(1510.9019065531156, 328.1364989017229);
glVertex2f(1517.921890552619, 324.7791152497863);
glVertex2f(1525.3996995955683, 321.2691232500345);
glVertex2f(1529.6782052163942, 319.0073664228602);
glVertex2f(1529.6782052163942, 316.6834609416158);
glVertex2f(1298.4998156089316, 316.6834609416158);



glEnd();



glBegin(GL_POLYGON);         //boat window 1
glColor3ub(1,1,1);

glVertex2f(1334.2050131079639, 328.9267600345627);
glVertex2f(1337.5207592100664, 332.5419000352281);
glVertex2f(1347.4311520684225, 342.98588278689);
glVertex2f(1360.4438278996536, 351.6834815388939);
glVertex2f(1422.927244607474, 351.6834815388939);

glVertex2f(1423.1673911660419, 351.6834815388939);
glVertex2f(1423.1673911660419, 341.9208697019043);
glVertex2f(1423.095924360698, 340.6326805355802);
glVertex2f(1422.500452951942, 339.6970094426574);
glVertex2f(1421.752067146047, 338.2536939598595);
glVertex2f(1420, 336);
glVertex2f(1418, 334);
glVertex2f(1416, 332);
glVertex2f(1414.1433210972177, 330.3217215155975);
glVertex2f(1412.2183783335474, 328.9267600345627);
glVertex2f(1334.2050131079639, 328.9267600345627);

glEnd();

glBegin(GL_POLYGON);         //boat window 2
glColor3ub(1,1,1);

glVertex2f(1432.0650619789437, 328.6302156073583);
glVertex2f(1432.0650619789437, 340.1499335558651);
glVertex2f(1434.0529045616274, 344.4201139186705);
glVertex2f(1436.0407471443114, 347.2178182943016);
glVertex2f(1438.0723288514343, 348.988541145783);

glVertex2f(1439.941132999359, 350.3234012514445);
glVertex2f(1441.9035914361207, 351.4699556824062);
glVertex2f(1469.498005476233,351.4699556824062);
glVertex2f(1473.840296358033, 349.8378741663859);
glVertex2f(1477.3771879331277, 347.8304492183577);
glVertex2f(1481.5832211575646, 344.4847409716442);
glVertex2f(1485.9804377103849, 340.8522577323551);
glVertex2f(1489.326145957096, 337.1241828288742);
glVertex2f(1492.767445867999, 332.6313746118588);
glVertex2f(1494.1057291666834, 330.7195413280224);
glVertex2f(1494.1057291666834, 328.6302156073583);
glVertex2f(1432.0650619789437, 328.6302156073583);


glEnd();

glBegin(GL_POLYGON);         //boat INSIDE window 1

if (day) {
glColor3ub(37,102,98);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(37,102,98);
    }
}
//glColor3ub(37,102,98);

glVertex2f(1344.9516788571511, 331.3962645352612);
glVertex2f(1353.8841463258748, 343.3206894781454);
glVertex2f(1362.3719762393948, 348.6797619260805);
glVertex2f(1390.2948791755337, 348.6797619260805);
glVertex2f(1372.1477669585568, 331.3962645352612);


glEnd();

glBegin(GL_POLYGON);         //boat INSIDE window 2
if (day) {
glColor3ub(37,102,98);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(37,102,98);
    }
}
//glColor3ub(37,102,98);

glVertex2f(1375.2173781094561, 331.3962645352612);
glVertex2f(1394.645421967333, 348.6797619260805);
glVertex2f(1421.471653151256, 348.6797619260805);
glVertex2f(1421.471653151256, 341.9325817595175);
glVertex2f(1421.0365326703, 340.2798840520771);

glVertex2f(1420.2101838165802, 338.7543169375168);
glVertex2f(1419.002443184221, 337.0062712854163);
glVertex2f(1417.5722240143216, 335.734965356616);
glVertex2f(1416, 334);
glVertex2f(1414.3303938958832, 332.6520484792752);
glVertex2f(1412.2963044098042, 331.3962645352612);

glEnd();


glBegin(GL_POLYGON);         //boat INSIDE window 3
if (day) {
glColor3ub(37,102,98);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(37,102,98);
    }
}
//glColor3ub(37,102,98);

glVertex2f(1434.6392725921164, 331.2746036211219);
glVertex2f(1434.6392725921164, 340.0965158525731);
glVertex2f(1436.1827131012215, 342.8413308437175);
glVertex2f(1437.7529723634564, 345.0396938108482);
glVertex2f(1439.7419674289542, 347.4997666550184);

glVertex2f(1441.5739365682284, 348.5989481385838);
glVertex2f(1451.0505036682448, 348.5989481385838);
glVertex2f(1451.0505036682448, 331.2746036211219);

glEnd();

glBegin(GL_POLYGON);         //boat INSIDE window 4

if (day) {
glColor3ub(37,102,98);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(37,102,98);
    }
}
//glColor3ub(37,102,98);

glVertex2f(1455.7062699283435, 331.2746036211219);
glVertex2f(1455.7062699283435, 348.5989481385838);
glVertex2f(1469.4429902851518, 348.5989481385838);
glVertex2f(1473.115268770571, 347.3101426595171);
glVertex2f(1477.4604986154343, 344.5866162010854);

glVertex2f(1481.9515535526705, 341.2191114019487);
glVertex2f(1486.0814705116854, 337.5247562435127);
glVertex2f(1489.1538381555622, 334.5899573001059);
glVertex2f(1491.1866216648746, 331.2746036211219);
glEnd();

glPopMatrix();
}

//62
void boat2(){

glPushMatrix();
glTranslatef(boat_move2,0,0);
glTranslatef(1400, 300, 0);
    // 2. Scale
    glScalef(0.8f, 0.8f, 1.0f);
    // 3. Move back to its original place
    glTranslatef(-1400, -300, 0);
//glScalef(0.5f, 0.5f, 1.0f);
glTranslatef(300,103,0);
    glBegin(GL_POLYGON);               //boat waves
glColor3ub(186,215,185);

glVertex2f(1317.0820663825375,293.9251614146244);
glVertex2f(1525.253664291376, 293.9251614146244);
glVertex2f(1525.253664291376, 291.4239570740714);
glVertex2f(1547.1968489090789,  291.4239570740714);
glVertex2f(1548.59110256947, 292.4700648373619);

glVertex2f(1549.9658151845565, 292.9099728741896);
glVertex2f(1552.6877461624276, 293.0474441356982);
glVertex2f(1648.624991777439, 293.0474441356982);
glVertex2f(1648,  291.7094197809329);
glVertex2f(1585.0070451190338, 291.7094197809329);
glVertex2f(1583.896508967472, 291.5459305030535);
glVertex2f(1582.7843081169901, 291.153735530422);
glVertex2f(1582.1881867675352, 290.4668720009444);
glVertex2f(1582.9711402256646, 289.9231543216877);
glVertex2f(1634.1405897534398,289.9231543216877);
glVertex2f(1632.8160612224644, 287.4593878195439);
glVertex2f(1583.9328397334696,287.4593878195439);
glVertex2f(1583.9328397334696, 285.3819806013965);
glVertex2f(1505.2569958423007,285.3819806013965);
glVertex2f(1497.0968458631505, 283.9389606168097);
glVertex2f(1486.3070306666114,  283.9389606168097);
glVertex2f(1478.5284033899804, 283.2868501454884);
glVertex2f(1445.0968712442896, 283.2868501454884);

glVertex2f(1441.53810876694,  282.3119979831747);
glVertex2f(1336.4281638237312, 282.3119979831747);
glVertex2f(1334.4154363366647, 284.1498276793825);
glVertex2f(1318.7880532686117,  284.1498276793825);
glVertex2f(1318.7880532686117, 286.3006413771472);
glVertex2f(1309.9896396429306,286.3006413771472);
glVertex2f(1308.6305700583787, 286.8831417439415);
glVertex2f(1307.3826758652817, 287.5830953778383);
glVertex2f(1306.7364424757664, 288.2404707223456);
glVertex2f(1307.171821956464, 288.8999023555921);
glVertex2f(1307.7961297119996, 289.4324001470783);
glVertex2f(1308.563723094396, 289.8671961511261);

glVertex2f(1309.5605915209558, 290.30744666014);
glVertex2f(1310.8551855418646, 290.8828217805441);
glVertex2f(1312.8148564959035, 291.5290762668891);
glVertex2f(1314.9307593113926, 292.0575459847025);
glVertex2f(1317.0820663825375,293.9251614146244);





glEnd();



glBegin(GL_QUADS);               //boat waves
glColor3ub(186,215,185);

//glColor3ub(152,201,175);

glVertex2f(1674.184429876447, 298.4067511137134);
glVertex2f(1656.7740954458716, 295.1944670672174);
glVertex2f(1526.3811212565772, 295.1944670672174);
glVertex2f(1525.461437895182,  298.4067511137134);



glEnd();


 glBegin(GL_QUADS);
glColor3ub(34,102,97);

glVertex2f(1529.6782052163942, 316.6834609416158);
glVertex2f(1529.6782052163942, 312.3628318220033);
glVertex2f(1289.3209409590618, 312.3628318220033);
glVertex2f(1284.982946462528, 317.1891793102082);
glVertex2f(1281.7216401616183, 317.4812830793558);


glEnd();


glBegin(GL_POLYGON);
glColor3ub(154,181,152);

glVertex2f(1289.3209409590618, 312.3628318220033);
glVertex2f(1529.6782052163942, 312.3628318220033);
glVertex2f(1530, 308);
glVertex2f(1529.4696416795714, 304.3456186038159);
glVertex2f(1528.4715957882572, 300.8369601538029);

glVertex2f(1527.461437895182, 297.9140951906034);
glVertex2f(1526.3811212565772, 295.706491624758);
glVertex2f(1525.253664291376, 293.9251614146244);
glVertex2f(1317.0820663825375,293.9251614146244);
glVertex2f(1311.9102107867334, 295.0129434090741);
glVertex2f(1307.2757541365174, 297.5544196366132);
glVertex2f(1303.0150439903512, 300.619140969822);
glVertex2f(1299.5018268522842, 303.085867896551);
glVertex2f(1295.6896125109774, 306.1505892297598);
glVertex2f(1292.77438977939, 308.8415640589188);
glVertex2f(1289.3209409590618, 312.3628318220033);



glEnd();


glBegin(GL_POLYGON);
glColor3ub(1,1,1);

glVertex2f(1317.0820663825375,293.9251614146244);
glVertex2f(1525.253664291376, 293.9251614146244);
glVertex2f(1525.253664291376, 290.2564169024448);
glVertex2f(1505.996583606524, 290.2564169024448);
glVertex2f(1505, 290);

glVertex2f(1503.7233172580152, 289.4461586644683);
glVertex2f(1502.3287212246435, 288.9339545528492);
glVertex2f(1465.6811993777087, 288.9339545528492);
glVertex2f(1464.0260657846702, 286.7562432345291);
glVertex2f(1420.6942000278837,286.7562432345291);
glVertex2f(1420.6942000278837, 284.7249401134718);
glVertex2f(1382.2282634767137, 284.7249401134718);
glVertex2f(1382.2282634767137, 286.2715259428549);
glVertex2f(1360.2281951308776,286.2715259428549);
glVertex2f(1360.2281951308776, 288);
glVertex2f(1339.7300032256576, 288);
glVertex2f(1339.7300032256576, 289.7134238940928);
glVertex2f(1325.3931440031106,  289.7134238940928);
glVertex2f(1325.3931440031106,293.9251614146244);
glVertex2f(1317.0820663825375,293.9251614146244);




glEnd();



glBegin(GL_POLYGON);
glColor3ub(234,227,189);

glVertex2f(1298.4998156089316, 316.6834609416158);
glVertex2f(1293.3051493352996, 316.6854669554193);
glVertex2f(1288.5194015480924, 316.9155128338068);
glVertex2f(1284.982946462528, 317.1891793102082);
glVertex2f(1281.7216401616183, 317.4812830793558);
glVertex2f(1278.338782135107, 318.3560039696043);
glVertex2f(1275.9943170571723, 319.5747799962153);
glVertex2f(1274.9595974082474, 321.5019571489278);
glVertex2f(1275.8202809039583, 323.5776115201389);
glVertex2f(1278.2878415180799, 324.8841540537463);
glVertex2f(1281.5565294246867, 326.0326119668785);
glVertex2f(1285.733536688338, 327.2766649302298);
glVertex2f(1289.5601587945696, 328.2816363924724);
glVertex2f(1293.4175853772774, 329.112341067553);
glVertex2f(1297.4018290903987, 329.6518740703716);
glVertex2f(1301.5935854969116, 330.2329096118685);
glVertex2f(1305.5736326321035, 330.4811949524409);
glVertex2f(1309.5065053902656, 330.772518860453);

glVertex2f(1313.7056387752343, 330.7293938946372);
glVertex2f(1318.2108151013451, 330.8401173385902);
glVertex2f(1322.764035725498, 330.8401173385902);
glVertex2f(1326.9873128261615, 330.7411342815433);
glVertex2f(1330.825227823426, 330.6557302524226);
glVertex2f(1333.99208812582, 330.5803288166513);
glVertex2f(1335.0115555327686, 330.6387336174543);
glVertex2f(1335.7325026195756, 330.9710536232091);
glVertex2f(1337.5207592100664, 332.5419000352281);
glVertex2f(1347.4311520684225, 342.98588278689);
glVertex2f(1360.4438278996536, 351.6834815388939);
glVertex2f(1361.4945167031547, 352.7375042012943);
glVertex2f(1362.6207580836042, 353.4955512842893);
glVertex2f(1365, 355);
glVertex2f(1366.350542101835, 355.9086586056661);
glVertex2f(1369.3648196879717, 357.4915086166502);
glVertex2f(1371.0316230401638, 358.1793890086762);
glVertex2f(1372.034120719138, 358.4021662706705);

glVertex2f(1373.3640414716597, 358.5062325605974);
glVertex2f(1467.1116155594777,358.5062325605974);
glVertex2f(1471.0788330124744, 358.0235801577994);
glVertex2f(1475.74065941963, 356.0577497451425);
glVertex2f(1479.9224119466112, 353.4694846390621);
glVertex2f(1484.3341466520974, 351.0027572554535);
glVertex2f(1488.7736961198982, 347.3651507264502);
glVertex2f(1492.1310797718345, 343.5499420310678);
glVertex2f(1496.4041135106627, 339.2769082922395);
glVertex2f(1500.6045860400895, 336.2035023923557);
glVertex2f(1505.6746303543987, 332.2008358284275);
glVertex2f(1510.9019065531156, 328.1364989017229);
glVertex2f(1517.921890552619, 324.7791152497863);
glVertex2f(1525.3996995955683, 321.2691232500345);
glVertex2f(1529.6782052163942, 319.0073664228602);
glVertex2f(1529.6782052163942, 316.6834609416158);
glVertex2f(1298.4998156089316, 316.6834609416158);



glEnd();



glBegin(GL_POLYGON);         //boat window 1
glColor3ub(1,1,1);

glVertex2f(1334.2050131079639, 328.9267600345627);
glVertex2f(1337.5207592100664, 332.5419000352281);
glVertex2f(1347.4311520684225, 342.98588278689);
glVertex2f(1360.4438278996536, 351.6834815388939);
glVertex2f(1422.927244607474, 351.6834815388939);

glVertex2f(1423.1673911660419, 351.6834815388939);
glVertex2f(1423.1673911660419, 341.9208697019043);
glVertex2f(1423.095924360698, 340.6326805355802);
glVertex2f(1422.500452951942, 339.6970094426574);
glVertex2f(1421.752067146047, 338.2536939598595);
glVertex2f(1420, 336);
glVertex2f(1418, 334);
glVertex2f(1416, 332);
glVertex2f(1414.1433210972177, 330.3217215155975);
glVertex2f(1412.2183783335474, 328.9267600345627);
glVertex2f(1334.2050131079639, 328.9267600345627);

glEnd();

glBegin(GL_POLYGON);         //boat window 2
glColor3ub(1,1,1);

glVertex2f(1432.0650619789437, 328.6302156073583);
glVertex2f(1432.0650619789437, 340.1499335558651);
glVertex2f(1434.0529045616274, 344.4201139186705);
glVertex2f(1436.0407471443114, 347.2178182943016);
glVertex2f(1438.0723288514343, 348.988541145783);

glVertex2f(1439.941132999359, 350.3234012514445);
glVertex2f(1441.9035914361207, 351.4699556824062);
glVertex2f(1469.498005476233,351.4699556824062);
glVertex2f(1473.840296358033, 349.8378741663859);
glVertex2f(1477.3771879331277, 347.8304492183577);
glVertex2f(1481.5832211575646, 344.4847409716442);
glVertex2f(1485.9804377103849, 340.8522577323551);
glVertex2f(1489.326145957096, 337.1241828288742);
glVertex2f(1492.767445867999, 332.6313746118588);
glVertex2f(1494.1057291666834, 330.7195413280224);
glVertex2f(1494.1057291666834, 328.6302156073583);
glVertex2f(1432.0650619789437, 328.6302156073583);


glEnd();

glBegin(GL_POLYGON);         //boat INSIDE window 1
if (day) {
glColor3ub(37,102,98);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(37,102,98);
    }
}
//glColor3ub(37,102,98);

glVertex2f(1344.9516788571511, 331.3962645352612);
glVertex2f(1353.8841463258748, 343.3206894781454);
glVertex2f(1362.3719762393948, 348.6797619260805);
glVertex2f(1390.2948791755337, 348.6797619260805);
glVertex2f(1372.1477669585568, 331.3962645352612);


glEnd();

glBegin(GL_POLYGON);         //boat INSIDE window 2
if (day) {
glColor3ub(37,102,98);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(37,102,98);
    }
}
//glColor3ub(37,102,98);

glVertex2f(1375.2173781094561, 331.3962645352612);
glVertex2f(1394.645421967333, 348.6797619260805);
glVertex2f(1421.471653151256, 348.6797619260805);
glVertex2f(1421.471653151256, 341.9325817595175);
glVertex2f(1421.0365326703, 340.2798840520771);

glVertex2f(1420.2101838165802, 338.7543169375168);
glVertex2f(1419.002443184221, 337.0062712854163);
glVertex2f(1417.5722240143216, 335.734965356616);
glVertex2f(1416, 334);
glVertex2f(1414.3303938958832, 332.6520484792752);
glVertex2f(1412.2963044098042, 331.3962645352612);

glEnd();


glBegin(GL_POLYGON);         //boat INSIDE window 3
if (day) {
glColor3ub(37,102,98);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(37,102,98);
    }
}
//glColor3ub(37,102,98);

glVertex2f(1434.6392725921164, 331.2746036211219);
glVertex2f(1434.6392725921164, 340.0965158525731);
glVertex2f(1436.1827131012215, 342.8413308437175);
glVertex2f(1437.7529723634564, 345.0396938108482);
glVertex2f(1439.7419674289542, 347.4997666550184);

glVertex2f(1441.5739365682284, 348.5989481385838);
glVertex2f(1451.0505036682448, 348.5989481385838);
glVertex2f(1451.0505036682448, 331.2746036211219);

glEnd();

glBegin(GL_POLYGON);         //boat INSIDE window 4
if (day) {
glColor3ub(37,102,98);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(37,102,98);
    }
}
//glColor3ub(37,102,98);

glVertex2f(1455.7062699283435, 331.2746036211219);
glVertex2f(1455.7062699283435, 348.5989481385838);
glVertex2f(1469.4429902851518, 348.5989481385838);
glVertex2f(1473.115268770571, 347.3101426595171);
glVertex2f(1477.4604986154343, 344.5866162010854);

glVertex2f(1481.9515535526705, 341.2191114019487);
glVertex2f(1486.0814705116854, 337.5247562435127);
glVertex2f(1489.1538381555622, 334.5899573001059);
glVertex2f(1491.1866216648746, 331.2746036211219);
glEnd();

glPopMatrix();

}

//63

void bus1()     //abus1
{
glPushMatrix();
glTranslatef(bus1_move,0,0);


glTranslatef(0,-50,0);
glBegin(GL_POLYGON);
glColor3ub(243,237,199);

glVertex2f(629.0935441883316, 342.0873330261104);
glVertex2f(635.4769259007104, 338.8541916393183);
glVertex2f(640.119385327895, 335.703951313726);
glVertex2f(643.7670320206829, 332.3050078045343);
glVertex2f(646.4198659790741, 328.9889653565423);

glVertex2f(650.8702194360997, 324.9194962964103);
glVertex2f(650.8702194360997, 192.5439865376979);
glVertex2f(647.1921407596275, 188.8659078612225);
glVertex2f(67.6861492024638, 188.8659078612225);

glVertex2f(64.0850812085371, 189.8696777147329);
glVertex2f(58.792255925709, 194.6201939792589);
glVertex2f(55.2755430243184, 198.8402494609315);
glVertex2f(53.165515283484, 204.2911544580919);

glVertex2f(53.165515283484, 323.9572647201411);
glVertex2f(54.6448799393844, 331.2253144625564);
glVertex2f(58.6550463498257, 336.9315884545731);
glVertex2f(65.9639285021324, 342.0873330261104);
glVertex2f(629.0935441883316, 342.0873330261104);




glEnd();




glBegin(GL_POLYGON);
glColor3ub(226,220,181);

glVertex2f(645.231744153337,  331.2253144625564);
glVertex2f(646.4198659790741, 328.9889653565423);

glVertex2f(650.8702194360997, 324.9194962964103);
glVertex2f(650.8702194360997, 192.5439865376979);
glVertex2f(647.1921407596275, 188.8659078612225);
glVertex2f(67.6861492024638, 188.8659078612225);

glVertex2f(64.0850812085371, 189.8696777147329);
glVertex2f(58.792255925709, 194.6201939792589);
glVertex2f(55.2755430243184, 198.8402494609315);
glVertex2f(53.165515283484, 204.2911544580919);

glVertex2f(53.165515283484, 323.9572647201411);
glVertex2f(54.6448799393844, 331.2253144625564);





glEnd();


glBegin(GL_POLYGON);
glColor3ub(219,77,20);

glVertex2f(53.165515283484, 324.9194962964103);
glVertex2f(53.165515283484, 319.9978339159135);

glVertex2f(650.8702194360997, 319.9978339159135);
glVertex2f(650.8702194360997, 324.9194962964103);


glEnd();


glBegin(GL_POLYGON);
glColor3ub(219,77,20);


glVertex2f(53.165515283484, 239.1153779286777);
glVertex2f(53.165515283484, 204.2911544580919);
glVertex2f(55.2755430243184, 198.8402494609315);
glVertex2f(58.792255925709, 194.6201939792589);
glVertex2f(64.0850812085371, 189.8696777147329);
glVertex2f(67.6861492024638, 188.8659078612225);


glVertex2f(647.1921407596275,  188.8659078612225);
glVertex2f(650.8702194360997, 192.5439865376979);
glVertex2f(650.8702194360997, 204.9423475989735);
glVertex2f(638.8677382837051,  204.9423475989735);

glVertex2f(638.8677382837051, 219.9008538008977);
glVertex2f(524.1851508668057, 219.9008538008977);

glVertex2f(524.1851508668057,239.1153779286777);



glEnd();

glBegin(GL_POLYGON);       //bus1windows
glColor3ub(19,75,73);

glVertex2f(80.61699068295, 256.9914116107497);
glVertex2f(75.7603001925914, 261.5612517977838);

glVertex2f(75.7603001925914, 308.4556013308637);
glVertex2f(82.643643994853, 314.5483656688505);
glVertex2f(524.1851508668057, 314.5483656688505);
glVertex2f(524.1851508668057,256.9914116107497);





glEnd();

glBegin(GL_POLYGON);       //bus1door
glColor3ub(19,75,73);

glVertex2f(524.1851508668057, 314.5483656688505);
glVertex2f(524.1851508668057, 195.3758971603217);
glVertex2f(626.1856892338876, 195.3758971603217);
glVertex2f(626.1856892338876, 314.8624184013362);

glEnd();


bus1allwindows(0,0,0);
bus1allwindows(50,0,0);

bus1allwindows(100,0,0);
bus1allwindows(150,0,0);
bus1allwindows(200,0,0);

bus1allwindows(250,0,0);
bus1allwindows(300,0,0);
bus1allwindows(350,0,0);
bus1allwindows(400,0,0);



glBegin(GL_QUADS);       //bus1doors
if (day) {
glColor3ub(28,102,96);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(28,102,96);
    }
}
//glColor3ub(28,102,96);

glVertex2f(528.0253116585077, 308.3227639160899);
glVertex2f(570.9076710826583, 308.3227639160899);
glVertex2f(570.9076710826583, 199.95059699209);
glVertex2f(528.0253116585077, 199.95059699209);\


glVertex2f(580.9864846899295, 308.3227639160899);
glVertex2f(618.9477225567298, 308.3227639160899);
glVertex2f(618.9477225567298,199.95059699209);
glVertex2f(580.9864846899295, 199.95059699209);

glEnd();

glBegin(GL_QUADS);       //frontwindow
if (day) {
glColor3ub(28,102,96);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(28,102,96);
    }
}
//glColor3ub(28,102,96);

glVertex2f(632.3866311415579, 237.4287859829439);
glVertex2f(632.3866311415579,314.5483656688505);
glVertex2f(650.8702194360997, 314.5483656688505);
glVertex2f(650.8702194360997, 233.3496302422375);
glVertex2f(640.5056075578234, 233.3496302422375);
glVertex2f(632.3866311415579, 237.4287859829439);

glEnd();

glBegin(GL_QUADS);       //lookingglass
glColor3ub(12,65,65);

glVertex2f(650.8702194360997, 303.013768949541);
glVertex2f(661.7123178183143,303.013768949541);

glVertex2f(656.9419436027664, 298.9372767831159);
glVertex2f(650.8702194360997, 298.9372767831159);
glEnd();


glBegin(GL_POLYGON);       //lookingglass
glColor3ub(12,65,65);

glVertex2f(661.7123178183143,303.013768949541);
glVertex2f(664.380834764079, 300.751917281134);
glVertex2f(664.380834764079, 284.8520038126045);
glVertex2f(661.9591647306695, 279.8091212329674);
glVertex2f(657.7781471240836,279.8091212329674);
glVertex2f(656.9419436027664, 298.9372767831159);

glEnd();


glBegin(GL_POLYGON);       //buslights
if (day) {
glColor3ub(28,102,96);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(28,102,96);
    }
}
glVertex2f(650.8702194360997,  205.3466251349961);
glVertex2f(638.8677382837051, 205.3466251349961);
glVertex2f(638.8677382837051, 220.1960047858407);
glVertex2f(650.8702194360997,220.1960047858407);


glEnd();

glBegin(GL_POLYGON);       //buslights

if (day) {
glColor3ub(28,102,96);
} else {
    if (lightsOn) {
glColor3ub(255, 140, 0); // Bright yellow-orange
    } else {
glColor3ub(28,102,96);
    }
}
glVertex2f(58.792255925709, 194.6201939792589);
glVertex2f(55.2755430243184, 198.8402494609315);
glVertex2f(55.2755430243184, 198.8402494609315);
glVertex2f(53.165515283484, 204.2911544580919);

glVertex2f(53.165515283484, 217.1916759370306);
glVertex2f(73.5453204696783, 217.1916759370306);
glVertex2f(73.5453204696783, 194.6201939792589);



glEnd();

bus1wheels(0,0,0);
bus1wheels(-280,0,0);
glPopMatrix();
}
//64
void bus1allwindows(float x,float y,float z){
glPushMatrix();
glTranslatef(x,y,z);

glBegin(GL_POLYGON);       //bus1windows

if (day) {
glColor3ub(28,102,96);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(28,102,96);
    }
}
//glColor3ub(28,102,96);

glVertex2f(81.2351707719732, 308.2750115248121);
glVertex2f(125.5530734538975, 308.2750115248121);
glVertex2f(125.5530734538975, 260.5774431174854);
glVertex2f(81.2351707719732, 260.5774431174854);

glEnd();
glPopMatrix();

}
//65
void bus1wheels(float x,float y,float z)
{
glPushMatrix();
glTranslatef(x,y,z);

glBegin(GL_POLYGON);       //bus1wheels
glColor3ub(16,72,73);

glVertex2f(445.1492063546363, 188.8659078612225);
glVertex2f(445.1492063546363, 200.0728384518344);
glVertex2f(445.8161154853149, 207.1304268010633);
glVertex2f(449.933275660078, 213.4777154038292);

glVertex2f(456.6236609440681, 219.5676814956722);
glVertex2f(466.0171391243375, 224.0373031809333);
glVertex2f(472.1760828772751, 225.7732840942423);
glVertex2f(477.460844191593, 226.8645714916697);
glVertex2f(482.6716693391618, 227.3564191283736);
glVertex2f(488.1051201236995, 227.0837967484167);
glVertex2f(493.6388551698109, 225.7925919043228);
glVertex2f(499.4492769682279, 223.2562966748526);

glVertex2f(504.0087906889504, 220.5747266716651);
glVertex2f(508.1569001367018, 217.3057119648942);
glVertex2f(511.3816083882917, 213.5197028386679);
glVertex2f(514.3499640554519, 209.3624343299682);
glVertex2f(515.6752796682587, 205.8666748101885);
glVertex2f(516.3694414202616, 201.6884203436837);
glVertex2f(516.3694414202616, 188.8659078612225);

glEnd();


glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(16,72,73);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=26.81;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+481.7134284090157,y+197.9965306460128 );
        }

glEnd();


glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(205,216,170);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=16.46;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+481.7134284090157,y+197.9965306460128 );
        }

glEnd();
glPopMatrix();

}
//66
void bus2(){

  glPushMatrix();
glTranslatef(bus2_move,0,0);

glTranslatef(0,-135,0);


glTranslatef(352, 265, 0);
glRotatef(180, 0, 0, 1);
glScalef(1, -1, 1);


glTranslatef(-352, -265, 0);



glBegin(GL_POLYGON);
glColor3ub(243,237,199);

glVertex2f(629.0935441883316, 342.0873330261104);
glVertex2f(635.4769259007104, 338.8541916393183);
glVertex2f(640.119385327895, 335.703951313726);
glVertex2f(643.7670320206829, 332.3050078045343);
glVertex2f(646.4198659790741, 328.9889653565423);

glVertex2f(650.8702194360997, 324.9194962964103);
glVertex2f(650.8702194360997, 192.5439865376979);
glVertex2f(647.1921407596275, 188.8659078612225);
glVertex2f(67.6861492024638, 188.8659078612225);

glVertex2f(64.0850812085371, 189.8696777147329);
glVertex2f(58.792255925709, 194.6201939792589);
glVertex2f(55.2755430243184, 198.8402494609315);
glVertex2f(53.165515283484, 204.2911544580919);

glVertex2f(53.165515283484, 323.9572647201411);
glVertex2f(54.6448799393844, 331.2253144625564);
glVertex2f(58.6550463498257, 336.9315884545731);
glVertex2f(65.9639285021324, 342.0873330261104);
glVertex2f(629.0935441883316, 342.0873330261104);




glEnd();




glBegin(GL_POLYGON);
glColor3ub(226,220,181);

glVertex2f(645.231744153337,  331.2253144625564);
glVertex2f(646.4198659790741, 328.9889653565423);

glVertex2f(650.8702194360997, 324.9194962964103);
glVertex2f(650.8702194360997, 192.5439865376979);
glVertex2f(647.1921407596275, 188.8659078612225);
glVertex2f(67.6861492024638, 188.8659078612225);

glVertex2f(64.0850812085371, 189.8696777147329);
glVertex2f(58.792255925709, 194.6201939792589);
glVertex2f(55.2755430243184, 198.8402494609315);
glVertex2f(53.165515283484, 204.2911544580919);

glVertex2f(53.165515283484, 323.9572647201411);
glVertex2f(54.6448799393844, 331.2253144625564);





glEnd();


glBegin(GL_POLYGON);
glColor3ub(219,77,20);

glVertex2f(53.165515283484, 324.9194962964103);
glVertex2f(53.165515283484, 319.9978339159135);

glVertex2f(650.8702194360997, 319.9978339159135);
glVertex2f(650.8702194360997, 324.9194962964103);


glEnd();


glBegin(GL_POLYGON);
glColor3ub(219,77,20);


glVertex2f(53.165515283484, 239.1153779286777);
glVertex2f(53.165515283484, 204.2911544580919);
glVertex2f(55.2755430243184, 198.8402494609315);
glVertex2f(58.792255925709, 194.6201939792589);
glVertex2f(64.0850812085371, 189.8696777147329);
glVertex2f(67.6861492024638, 188.8659078612225);


glVertex2f(647.1921407596275,  188.8659078612225);
glVertex2f(650.8702194360997, 192.5439865376979);
glVertex2f(650.8702194360997, 204.9423475989735);
glVertex2f(638.8677382837051,  204.9423475989735);

glVertex2f(638.8677382837051, 219.9008538008977);
glVertex2f(524.1851508668057, 219.9008538008977);

glVertex2f(524.1851508668057,239.1153779286777);



glEnd();

glBegin(GL_POLYGON);       //bus1windows
glColor3ub(19,75,73);

glVertex2f(80.61699068295, 256.9914116107497);
glVertex2f(75.7603001925914, 261.5612517977838);

glVertex2f(75.7603001925914, 308.4556013308637);
glVertex2f(82.643643994853, 314.5483656688505);
glVertex2f(524.1851508668057, 314.5483656688505);
glVertex2f(524.1851508668057,256.9914116107497);





glEnd();

glBegin(GL_POLYGON);       //bus1door
glColor3ub(19,75,73);

glVertex2f(524.1851508668057, 314.5483656688505);
glVertex2f(524.1851508668057, 195.3758971603217);
glVertex2f(626.1856892338876, 195.3758971603217);
glVertex2f(626.1856892338876, 314.8624184013362);

glEnd();


bus1allwindows(0,0,0);
bus1allwindows(50,0,0);

bus1allwindows(100,0,0);
bus1allwindows(150,0,0);
bus1allwindows(200,0,0);

bus1allwindows(250,0,0);
bus1allwindows(300,0,0);
bus1allwindows(350,0,0);
bus1allwindows(400,0,0);



glBegin(GL_QUADS);       //bus1doors
if (day) {
glColor3ub(28,102,96);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(28,102,96);
    }
}
//glColor3ub(28,102,96);

glVertex2f(528.0253116585077, 308.3227639160899);
glVertex2f(570.9076710826583, 308.3227639160899);
glVertex2f(570.9076710826583, 199.95059699209);
glVertex2f(528.0253116585077, 199.95059699209);\


glVertex2f(580.9864846899295, 308.3227639160899);
glVertex2f(618.9477225567298, 308.3227639160899);
glVertex2f(618.9477225567298,199.95059699209);
glVertex2f(580.9864846899295, 199.95059699209);

glEnd();

glBegin(GL_QUADS);       //frontwindow
if (day) {
glColor3ub(28,102,96);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(28,102,96);
    }
}
//glColor3ub(28,102,96);

glVertex2f(632.3866311415579, 237.4287859829439);
glVertex2f(632.3866311415579,314.5483656688505);
glVertex2f(650.8702194360997, 314.5483656688505);
glVertex2f(650.8702194360997, 233.3496302422375);
glVertex2f(640.5056075578234, 233.3496302422375);
glVertex2f(632.3866311415579, 237.4287859829439);

glEnd();

glBegin(GL_QUADS);       //lookingglass
glColor3ub(12,65,65);

glVertex2f(650.8702194360997, 303.013768949541);
glVertex2f(661.7123178183143,303.013768949541);

glVertex2f(656.9419436027664, 298.9372767831159);
glVertex2f(650.8702194360997, 298.9372767831159);
glEnd();


glBegin(GL_POLYGON);       //lookingglass
glColor3ub(12,65,65);

glVertex2f(661.7123178183143,303.013768949541);
glVertex2f(664.380834764079, 300.751917281134);
glVertex2f(664.380834764079, 284.8520038126045);
glVertex2f(661.9591647306695, 279.8091212329674);
glVertex2f(657.7781471240836,279.8091212329674);
glVertex2f(656.9419436027664, 298.9372767831159);

glEnd();

glBegin(GL_POLYGON);       //buslights
if (day) {
glColor3ub(28,102,96);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(28,102,96);
    }
}
glVertex2f(650.8702194360997,  205.3466251349961);
glVertex2f(638.8677382837051, 205.3466251349961);
glVertex2f(638.8677382837051, 220.1960047858407);
glVertex2f(650.8702194360997,220.1960047858407);


glEnd();

glBegin(GL_POLYGON);       //buslights

if (day) {
glColor3ub(28,102,96);
} else {
    if (lightsOn) {
glColor3ub(255, 140, 0); // Bright yellow-orange
    } else {
glColor3ub(28,102,96);
    }
}
glVertex2f(58.792255925709, 194.6201939792589);
glVertex2f(55.2755430243184, 198.8402494609315);
glVertex2f(55.2755430243184, 198.8402494609315);
glVertex2f(53.165515283484, 204.2911544580919);

glVertex2f(53.165515283484, 217.1916759370306);
glVertex2f(73.5453204696783, 217.1916759370306);
glVertex2f(73.5453204696783, 194.6201939792589);



glEnd();


bus1wheels(0,0,0);
bus1wheels(-280,0,0);
glPopMatrix();



}
//67
void car1()   //acar1
{
glPushMatrix();
glTranslatef(car1_move,0,0);

glTranslatef(0,-40,0);
glBegin(GL_POLYGON);     //carbody
glColor3ub(240,233,195);

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
if (day) {
glColor3ub(38,101,99);
} else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(38,101,99);
    }
}

//glColor3ub(38,101,99);

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
if (day) {
glColor3ub(40,109,105);}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(40,109,105);
    }
}
//glColor3ub(40,109,105);

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
glBegin(GL_POLYGON);
if (day) {
glColor3ub(40,109,105);}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(40,109,105);
    }
}
//glColor3ub(40,109,105);

glVertex2f(1623.5754616901531, 136.2659465428214);
glVertex2f(1623.5754616901531, 168.5791526531986);
glVertex2f(1665.1643591615732, 168.5791526531986);
glVertex2f(1665.1643591615732, 136.2659465428214);


glEnd();

glBegin(GL_POLYGON);     //car1window
if (day) {
glColor3ub(40,109,105);}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(40,109,105);
    }
}
//glColor3ub(40,109,105);

glVertex2f(1671.1860706412433, 168.5791526531986);
glVertex2f(1680.1631308221351, 164.3727953642939);
glVertex2f(1688.9166527416528, 159.6977028434082);
glVertex2f(1696.0796547827226, 155.4957621912506);

glVertex2f(1702.7011529347023, 150.7553714688049);
glVertex2f(1700.1151217748984, 136.2659465428214);
glVertex2f(1671.1860706412433, 136.2659465428214);



glEnd();

glBegin(GL_POLYGON);     //car1window
if (day) {
glColor3ub(40,109,105);}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(40,109,105);
    }
}
//glColor3ub(40,109,105);

glVertex2f(1690, 180);
glVertex2f(1710.7855424140707, 172.1947626717054);
glVertex2f(1755.8351739670582, 152.1211742596365);
glVertex2f(1749.2432643645523, 147.6555269619759);

glVertex2f(1697.2701263961007, 173.57674175902);
glVertex2f(1690, 180);





glEnd();


glBegin(GL_POLYGON);    //lights
glColor3ub(24,79,74);

glVertex2f(1397.4909277367262, 108.6098400246408);
glVertex2f(1399.544320048372, 113.4489827551592);
glVertex2f(1403.0627876823619, 119.8216498046152);
glVertex2f(1409.0700478732963, 119.3096427225466);

glVertex2f(1408.042232157768, 111.7551972134043);
glVertex2f(1403.57123379522, 106.2049923495446);
glVertex2f(1399.716924861989, 106.7702909930859);


glEnd();

glBegin(GL_POLYGON);    //lights

if (day) {
glColor3ub(147,171,139);}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(147,171,139);
    }
}
//glColor3ub(147,171,139);

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
if (day) {
glColor3ub(147,171,139);}
else {
    if (lightsOn) {
        glColor3ub(255, 0, 0); // Warm glow when light is ON
    } else {
glColor3ub(147,171,139);
    }
}
//glColor3ub(147,171,139);

glVertex2f(1769.9933727601763, 130.6568686206931);
glVertex2f(1776.7801484960298, 116.0168238190482);
glVertex2f(1792.983752010349, 115.636075046198);
glVertex2f(1794.127434306422, 132.560300163777);

glEnd();

glBegin(GL_POLYGON);
glColor3ub(147,171,139);

glVertex2f(1592.4750086040583, 125.0013707315354);
glVertex2f(1606.6307709094756, 125.0013707315354);
glVertex2f(1609.3675516218561, 123.3026792548834);
glVertex2f(1608.5182058835312,118.9615788145503);

glVertex2f(1593.135610844978, 118.9615788145503);
glVertex2f(1591.2481758709223, 122.0758465217458);


glEnd();

glBegin(GL_POLYGON);
glColor3ub(147,171,139);

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

car1wheelsa(0,0,0);
car1wheelsa(237.14,0,0);

glPopMatrix();
}
//68
void car1wheelsa(float x,float y,float z)

{
glPushMatrix();
glTranslatef(x,y,z);

glBegin(GL_POLYGON);      //PICKUPWHEELS
	for(int i=0;i<200;i++)
        {
            glColor3ub(12,75,75);
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
//69
void car2(){

glPushMatrix();
glTranslatef(car2_movea,car2_y,0);

glTranslatef(0, 45, 0);
// Step 1: Translate to pivot point (midpoint of car’s X range)
glTranslatef(1600, 0, 0);  // approx center of car's X-range

// Step 2: Mirror across Y-axis to flip horizontally
glScalef(-1, 1, 1);

// Step 3: Translate back after flipping
glTranslatef(-1600, 0, 0);





glBegin(GL_POLYGON);     //carbody
glColor3ub(255,255,0);

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

if (day) {
glColor3ub(38,101,99);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(38,101,99);
    }
}
//glColor3ub(38,101,99);

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

if (day) {
glColor3ub(40,109,105);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(40,109,105);
    }
}
//glColor3ub(40,109,105);

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
if (day) {
glColor3ub(40,109,105);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(40,109,105);
    }
}
//glColor3ub(40,109,105);

glVertex2f(1623.5754616901531, 136.2659465428214);
glVertex2f(1623.5754616901531, 168.5791526531986);
glVertex2f(1665.1643591615732, 168.5791526531986);
glVertex2f(1665.1643591615732, 136.2659465428214);


glEnd();

glBegin(GL_POLYGON);     //car1window
if (day) {
glColor3ub(40,109,105);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(40,109,105);
    }
}
//glColor3ub(40,109,105);

glVertex2f(1671.1860706412433, 168.5791526531986);
glVertex2f(1680.1631308221351, 164.3727953642939);
glVertex2f(1688.9166527416528, 159.6977028434082);
glVertex2f(1696.0796547827226, 155.4957621912506);

glVertex2f(1702.7011529347023, 150.7553714688049);
glVertex2f(1700.1151217748984, 136.2659465428214);
glVertex2f(1671.1860706412433, 136.2659465428214);



glEnd();

glBegin(GL_POLYGON);     //car1window
if (day) {
glColor3ub(40,109,105);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(40,109,105);
    }
}
//glColor3ub(40,109,105);

glVertex2f(1690, 180);
glVertex2f(1710.7855424140707, 172.1947626717054);
glVertex2f(1755.8351739670582, 152.1211742596365);
glVertex2f(1749.2432643645523, 147.6555269619759);

glVertex2f(1697.2701263961007, 173.57674175902);
glVertex2f(1690, 180);





glEnd();


glBegin(GL_POLYGON);    //lights
glColor3ub(24,79,74);

glVertex2f(1397.4909277367262, 108.6098400246408);
glVertex2f(1399.544320048372, 113.4489827551592);
glVertex2f(1403.0627876823619, 119.8216498046152);
glVertex2f(1409.0700478732963, 119.3096427225466);

glVertex2f(1408.042232157768, 111.7551972134043);
glVertex2f(1403.57123379522, 106.2049923495446);
glVertex2f(1399.716924861989, 106.7702909930859);


glEnd();

glBegin(GL_POLYGON);    //lights

if (day) {
glColor3ub(147,171,139);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(147,171,139);
    }
}
//glColor3ub(147,171,139);

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

if (day) {
glColor3ub(147,171,139);
}
else {
    if (lightsOn) {
        glColor3ub(255, 0, 0); // Warm glow when light is ON
    } else {
glColor3ub(147,171,139);
    }
}
//glColor3ub(147,171,139);

glVertex2f(1769.9933727601763, 130.6568686206931);
glVertex2f(1776.7801484960298, 116.0168238190482);
glVertex2f(1792.983752010349, 115.636075046198);
glVertex2f(1794.127434306422, 132.560300163777);

glEnd();

glBegin(GL_POLYGON);
glColor3ub(147,171,139);

glVertex2f(1592.4750086040583, 125.0013707315354);
glVertex2f(1606.6307709094756, 125.0013707315354);
glVertex2f(1609.3675516218561, 123.3026792548834);
glVertex2f(1608.5182058835312,118.9615788145503);

glVertex2f(1593.135610844978, 118.9615788145503);
glVertex2f(1591.2481758709223, 122.0758465217458);


glEnd();

glBegin(GL_POLYGON);
glColor3ub(147,171,139);

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

car1wheelsa(0,0,0);
car1wheelsa(237.14,0,0);

glPopMatrix();

}
//70
void pickup(){
glPushMatrix();

glTranslatef(pickup_move,0,0);

glTranslatef(0,-25,0);
glBegin(GL_POLYGON);     //pickupbody
glColor3ub(210,121,23);

glVertex2f(883.6047324807096, 62.8952956197518);
glVertex2f(868.2075224622689, 64.0173810866169);
glVertex2f(861.9282131359881, 71.5646924326348);
glVertex2f(856.1492381319583, 72.6736318482727);

glVertex2f(850.7015989950992, 79.6728026455063);
glVertex2f(850.7015989950992, 87.7809128583778);
glVertex2f(851.9110744377454, 92.388338246795);

glVertex2f(853.1964021375189, 96.5127238568549);
glVertex2f(855.7587901078922, 102.1402218604907);
glVertex2f(854.4923969972543, 117.4952383269894);
glVertex2f(857.6583797738491, 132.6919556546582);
glVertex2f(860, 140);
glVertex2f(865.8899349929957, 145.197587622219);

glVertex2f(879.6619600711832, 147.4137755658374);
glVertex2f(893.7505834270303, 149.313365231796);
glVertex2f(907.5226085052178, 150.4214592036052);
glVertex2f(923.1942232493622, 152.3210488695638);
glVertex2f(935.973961964582, 154.8209767995817);
glVertex2f(948.9841111535071, 156.8617845154934);
glVertex2f(957.019791534902, 163.2393086277172);



glVertex2f(966.3309767387404, 170.3821356334079);
glVertex2f(975.7697124248233, 176.7596597456318);
glVertex2f(983.8053928062182, 181.7341285531664);
glVertex2f(996.1777895839213, 189.132056523346);
glVertex2f(1008.2444442772669, 195.9347951236291);
glVertex2f(1010.5197248188009, 197.2559257606501);
glVertex2f(1016.0889234411716, 199.3533177608169);


glVertex2f(1020.1572860534624, 200.8703343281132);
glVertex2f(1023.3303070318478, 201.7621605480868);
glVertex2f(1092.9040295842988, 201.7621605480868);
glVertex2f(1092.9040295842988, 148.6064768704136);
glVertex2f(1254.435189279341,148.6064768704136);
glVertex2f(1254.435189279341, 89.5038671321421);
glVertex2f(1258.669079055077, 86.1669070253492);

glVertex2f(1260, 80);
glVertex2f(1258.493449575772, 72.9946960774824);
glVertex2f(1250, 70);
glVertex2f(1241.1016088828108,70);
glVertex2f(1221.9625178803878, 64.5644810708477);
glVertex2f(1208.614677453228, 62.9838157571037);
glVertex2f(1130.2839296833174, 62.8952956197518);
glVertex2f(883.6047324807096, 62.8952956197518);




glEnd();



glBegin(GL_POLYGON);     //pickupbody
glColor3ub(1,73,64);

glVertex2f(883.6047324807096, 62.8952956197518);
glVertex2f(868.2075224622689, 64.0173810866169);
glVertex2f(861.9282131359881, 71.5646924326348);
glVertex2f(856.1492381319583, 72.6736318482727);
glVertex2f(850.7015989950992, 79.6728026455063);
glVertex2f(850.7015989950992, 87.7809128583778);
glVertex2f(851.9110744377454, 92.388338246795);

glVertex2f(889.8912970273666, 92.388338246795);
glVertex2f(897.3611693152994, 101.8392859216616);
glVertex2f(905.2472435198061, 108.7992373004209);
glVertex2f(915.0305444038049, 112.5637834072626);
glVertex2f(926.1507991480961, 113.3708986709618);
glVertex2f(938.5265665248072, 110.1424376161649);
glVertex2f(947.9395318314546, 103.8152520211863);

glVertex2f(955, 95);
glVertex2f(959.4409573070916, 85.6662270048826);
glVertex2f(961.1630287551072, 76.1907805524926);
glVertex2f(961.6305735632027, 69.0141369661128);
glVertex2f(1130, 69.0141369661128);
glVertex2f(1130.2839296833174, 62.8952956197518);
glVertex2f(883.6047324807096, 62.8952956197518);




glEnd();



glBegin(GL_POLYGON);     //pickupbody
glColor3ub(1,73,64);

glVertex2f(1130.2839296833174, 62.8952956197518);
glVertex2f(1130, 69.0141369661128);
glVertex2f(1132.2560928343357, 78.6069560169132);
glVertex2f(1135.3690940198817, 87.57195008132);


glVertex2f(1141.129166971197, 96.7720666007901);
glVertex2f(1148.6361876787014, 104.1343765536093);
glVertex2f(1159.9107984157324, 110.5162316877833);
glVertex2f(1168.5803967350262, 112.0327581567071);
glVertex2f(1176.7163502690426, 112.0053312190906);
glVertex2f(1186.8322237821951, 109.2947190912639);
glVertex2f(1193.902737987464, 104.7326237415833);


glVertex2f(1200.2602777171826, 98.5694770755465);
glVertex2f(1205.438584842062, 87.7608592556129);
glVertex2f(1207.769657862899, 77.2604449477589);
glVertex2f(1208.6071552261271,  69.0141369661128);

/*
glVertex2f(1241.1016088828108,70);

glVertex2f(1241.1016088828108, 89.5038671321421);
glVertex2f(1254.435189279341, 89.5038671321421);
glVertex2f(1258.669079055077, 86.1669070253492);

glVertex2f(1260, 80);
glVertex2f(1258.493449575772, 72.9946960774824);
glVertex2f(1250, 70);
glVertex2f(1241.1016088828108,70);


glVertex2f(1221.9625178803878, 64.5644810708477);
*/
glVertex2f(1208.614677453228, 62.9838157571037);

glVertex2f(1130.2839296833174, 62.8952956197518);





glEnd();




glBegin(GL_POLYGON);     //pickupwindow

if (day) {
glColor3ub(0,106,92);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(0,106,92);
    }
}
//glColor3ub(0,106,92);


glVertex2f(948.9841111535071, 156.8617845154934);
glVertex2f(957.019791534902, 163.2393086277172);
glVertex2f(966.3309767387404, 170.3821356334079);
glVertex2f(975.7697124248233, 176.7596597456318);
glVertex2f(983.8053928062182, 181.7341285531664);
glVertex2f(996.1777895839213, 189.132056523346);
glVertex2f(1008.2444442772669, 195.9347951236291);
glVertex2f(1010.5197248188009, 197.2559257606501);
glVertex2f(1017.3458918667541, 191.8249612535366);
glVertex2f(974.5620551439084, 154.7605364997077);


glEnd();

glBegin(GL_POLYGON);     //window
glColor3ub(1,73,64);

glVertex2f(984.2885908335247, 146.2809600065397);
glVertex2f(984.2885908335247, 151.7447211244776);
glVertex2f(1014.4588542456802, 180.8663839180655);
glVertex2f(1022.708707497919, 187.3123741461921);
glVertex2f(1030, 190);
glVertex2f(1040.8423124778021, 191.5097389393213);
glVertex2f(1081.2682118625808, 191.5097389393213);

glVertex2f(1081.2682118625808,146.2809600065397);




glEnd();



glBegin(GL_POLYGON);     //window
if (day) {
glColor3ub(0,106,92);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(0,106,92);
    }
}
//glColor3ub(0,106,92);

glVertex2f(989.8732650910163, 148.466230022994);
glVertex2f(996.4914129901609, 157.4991075610257);
glVertex2f(1004.191882900235, 166.1336201983788);
glVertex2f(1012.3496446208903, 174.5428733865358);
glVertex2f(1021.6310245261116, 181.6524949630167);
glVertex2f(1030.5470344502626, 185.6480394255407);
glVertex2f(1040.435903958067, 187.0313558316982);

glVertex2f(1048.6071467833237, 187.255100910427);
glVertex2f(1048.6071467833237, 148.466230022994);




glEnd();



glBegin(GL_POLYGON);     //window
if (day) {
glColor3ub(0,106,92);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(0,106,92);
    }
}
//glColor3ub(0,106,92);

glVertex2f(1054.8176500748893, 148.466230022994);
glVertex2f(1054.8176500748893, 187.0313558316982);
glVertex2f(1078.3022573005524, 187.0313558316982);
glVertex2f(1078.3022573005524, 148.466230022994);



glEnd();




glBegin(GL_POLYGON);     //doorhandle
glColor3ub(1,73,64);

glVertex2f(1047.1928216169915, 136.8438529953707);
glVertex2f(1045.8605495487352, 135.0070500948425);
glVertex2f(1048.0673677319983, 131.8544526901776);
glVertex2f(1069.3269902609613, 131.8544526901776);
glVertex2f(1071.1674907607626, 135.0070500948425);
glVertex2f(1070.1449904830954, 136.8438529953707);


glEnd();


glLineWidth(1);
glBegin(GL_LINES);     //lines
glColor3ub(1,73,64);

glVertex2f(980, 160);
glVertex2f(980, 68.5886155326416);

glVertex2f(1081.054191777389, 146.8328550689578);
glVertex2f(1081.054191777389, 67.8993743478862);

glVertex2f(1094.0986033324573, 148.6064768704136);
glVertex2f(1094.0986033324573, 68.2984673081244);


glEnd();


glBegin(GL_POLYGON);     //TRUNK
glColor3ub(1,73,64);
glVertex2f(1094.0986033324573, 148.6064768704136);

glVertex2f(1094.0986033324573, 157.374835693647);
glVertex2f(1248.3739945999148, 157.374835693647);

glVertex2f(1252.1574166443634, 154.1734785791107);
glVertex2f(1253.9046222587986, 148.6064768704136);


glEnd();


glBegin(GL_POLYGON);     //LIGHTS

if (day) {
glColor3ub(220,216,180);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(220,216,180);
    }
}
//glColor3ub(220,216,180);
glVertex2f(855.7587901078922, 102.1402218604907);

glVertex2f(854.4923969972543, 117.4952383269894);
glVertex2f(857.6583797738491, 132.6919556546582);

glVertex2f(879.4198767611939, 132.6919556546582);
glVertex2f(880.0851750000302, 125.6155998111586);

glVertex2f(879.0172805556701, 115.6841814785999);
glVertex2f(877.0950705558222, 107.461394257019);

glVertex2f(874.732888044898,102.1402218604907);



glEnd();


glBegin(GL_POLYGON);     //LIGHTS

if (day) {
glColor3ub(220,216,180);
}
else {
    if (lightsOn) {
        glColor3ub(255,0,0); // Warm glow when light is ON
    } else {
glColor3ub(220,216,180);
    }
}
//glColor3ub(220,216,180);
glVertex2f(1243.8181742829918, 124.4202099089833);

glVertex2f(1253.9046222587986, 124.4202099089833);
glVertex2f(1253.9046222587986, 136.43778666255);

glVertex2f(1243.8181742829918, 136.43778666255);


glEnd();



pickupwheels(0,0,0);
pickupwheels(246.84,0,0);


glPopMatrix();

}
//71
void pickupwheels(float x,float y,float z)
{
   glPushMatrix();
  glTranslatef(x,y,z);
glBegin(GL_POLYGON);      //PICKUPWHEELS
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,80,68);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=34.29;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+923.7955525205713,y+69.038778149435);
        }

glEnd();

glBegin(GL_POLYGON);      //PICKUPWHEELS
	for(int i=0;i<200;i++)
        {
            glColor3ub(159,187,145);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=23.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+923.7955525205713,y+69.038778149435);
        }

glEnd();

glBegin(GL_POLYGON);      //PICKUPWHEELS
	for(int i=0;i<200;i++)
        {
            glColor3ub(0,80,68);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=15.03;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+923.7955525205713,y+69.038778149435);
        }

glEnd();

glPopMatrix();
}
//72
void plane()
{

    glPushMatrix();
    glTranslatef(plane_move,plane_y_offset,0);

glBegin(GL_POLYGON);     //planebody
glColor3ub(242,240,211);

glVertex2f(909.0857917050264, 912.9728408815571);
glVertex2f(915.7175168864089, 910.583782340249);
glVertex2f(922.4732626552583, 907.7914074224556);
glVertex2f(930.1343196668847, 903.8404975851596);

glVertex2f(935.7034130914751, 900.4203717608249);
glVertex2f(940.6931718885148, 896.6361974661488);
glVertex2f(942.638658591538, 892.0815646714566);
glVertex2f(940.0792227522292, 887.5406301178402);
glVertex2f(935.3439594240612, 885.2083344739067);
glVertex2f(864.9404711002328,885.2083344739067);
glVertex2f(821.0653295016415,885.2083344739067);
glVertex2f(769.6178638846052, 885.2083344739067);

glVertex2f(730.7924451671984, 887.545383670819);
glVertex2f(723.0000402942247, 888.569320003973);
glVertex2f(714.3172060156661, 889.9733136510469);
glVertex2f(704.6054860947627, 892.4012436312747);
glVertex2f(697.7902967980953, 895.4204673605911);
glVertex2f(693.8278027295651, 897.8125319889642);
glVertex2f(690.8945462956922, 901.3743433729558);



glVertex2f(691.8373787208657, 906.0885054988267);
glVertex2f(697.1800957968483, 909.5455577244655);
glVertex2f(703.7771828836441, 911.728336831332);
glVertex2f(710.8187935261515, 912.612388531075);
glVertex2f(719.4347015087961,912.9728408815571);
glVertex2f(909.0857917050264, 912.9728408815571);


glEnd();



glBegin(GL_POLYGON);     //planewindows

if (day){
glColor3ub(30,127,137);
}
else {
glColor3ub(255, 200, 120);  // Warm soft glow, realistic from far


}


glVertex2f(918.5282800263501, 903.6064047006784);
glVertex2f(924, 903.6064047006784);
glVertex2f(926.8602747895104, 901.593372671392);
glVertex2f(926.8602747895104, 897.8439750279649);
glVertex2f(926.5269949989839, 897.0618718698764);
glVertex2f(918.5282800263501, 897.0618718698764);



glEnd();



for(int i=0;i<138;i=i+8){
planewindows(i,0,0);

}
planewindows(172,0,0);




glBegin(GL_POLYGON);     //planewing
glColor3ub(242,240,211);

glVertex2f(666.8564192945557, 940.6783049576104);
glVertex2f(677.1465672899338, 943.7224963903004);
glVertex2f(709.4676334717012, 916.7290619839719);
glVertex2f(714.7764713759159, 916.1785742304461);

glVertex2f(719.4347015087961, 912.7129301045244);
glVertex2f(691.8373787208657, 906.0885054988267);



glEnd();


glBegin(GL_POLYGON);     //planewing
glColor3ub(110,172,156);

glVertex2f(709.7495219820294, 902.0330521964237);
glVertex2f(709.0427807732987, 899.6583816460753);
glVertex2f(706.7778408214946, 897.7670019578793);

glVertex2f(702.7899679161094, 896.8333160531021);
glVertex2f(698.6988875393381, 896.8787725017329);
glVertex2f(694.5168942653052, 897.0151418476255);


glVertex2f(690.7482240203341, 897.4851055043524);
glVertex2f(685.5794783592588, 898.3896359950413);
glVertex2f(679.441592886732, 899.3587758064937);

glVertex2f(673.1645193703594, 900.4650786489603);
glVertex2f(667.0255477365394, 901.9552947089737);
glVertex2f(662.7142062266045, 903.7611955926551);
glVertex2f(659.5450662717262, 905.6253955661152);




glEnd();

glBegin(GL_POLYGON);     //planewing
glColor3ub(242,240,211);

glVertex2f(691.8373787208657, 906.0885054988267);
glVertex2f(640.6384830399691, 906.8596086863672);
glVertex2f(709.7495219820294, 902.0330521964237);

glEnd();


glBegin(GL_POLYGON);     //planewing
glColor3ub(242,240,211);

glVertex2f(736.6989229871031, 923.3628069946546);
glVertex2f(766.6006207726585, 922.6528217250827);
glVertex2f(820.2984478663025, 903.0612421585362);

glVertex2f(829.8185862616566, 892.2595690861411);


glEnd();


glBegin(GL_POLYGON);     //planewing
glColor3ub(110,172,156);

glVertex2f(736.6989229871031, 923.3628069946546);
glVertex2f(738.9019155874153, 920.6761302375885);
glVertex2f(743.5473327633376, 918.4756694700434);

glVertex2f(750.1586125696987, 915.9390151934228);
glVertex2f(758.1264919746609, 912.7347327768122);
glVertex2f(764.2359090773439, 910.3017241769659);


glVertex2f(772.0850350168342, 907.1412283790576);
glVertex2f(781.8150582758408, 902.3652954038922);
glVertex2f(789.2765312959034, 897.0800853480102);

glVertex2f(797.0488990251353, 891.0176385192044);
glVertex2f(799.9116256649384, 888.1260867272451);

glVertex2f(832.7237477611928, 891.5817145160745);
glVertex2f(736.6989229871031, 923.3628069946546);





glEnd();


glBegin(GL_POLYGON);     //planewing
glColor3ub(110,172,156);


glVertex2f(799.9116256649384, 888.1260867272451);
glVertex2f(771.8247991936412, 884.6528147447148);
glVertex2f(773.1655633426699, 881.3179981361222);

glVertex2f(824.7361101072131, 882.8595557952134);
glVertex2f(821.0653295016415, 884.9651884527952);
glVertex2f(827.4598341005344, 885.250128462642);
glVertex2f(832.7237477611928, 891.5817145160745);
glVertex2f(799.9116256649384, 888.1260867272451);


glEnd();


glBegin(GL_POLYGON);     //planewing
glColor3ub(110,172,156);




glVertex2f(824.7361101072131, 882.8595557952134);
glVertex2f(786.052302461581, 870.3764271861032);
glVertex2f(819.9982791155085, 868.6414152407848);
glVertex2f(833.222630557218, 876.9413697561146);



glEnd();


glBegin(GL_POLYGON);     //planeengine
glColor3ub(242,240,211);




glVertex2f(824.7361101072131, 882.8595557952134);
glVertex2f(832.7237477611928, 891.5817145160745);
glVertex2f(854.6355915746576,  891.5817145160745);
glVertex2f(854.6355915746576, 876.2313251871873);
glVertex2f(832.7237477611928, 876.9413697561146);




glEnd();


glBegin(GL_POLYGON);     //planeengine
glColor3ub(110,172,156);


glVertex2f(854.6355915746576,  891.5817145160745);
glVertex2f(854.6355915746576, 876.2313251871873);
glVertex2f(865.106783157892, 881.8346853193079);

glVertex2f(865.106783157892, 885.1366406743712);

glEnd();

glBegin(GL_POLYGON);     //planeengine
glColor3ub(110,172,156);



glVertex2f(865.106783157892, 881.8346853193079);
glVertex2f(927.575809236786, 884.6619732853009);
glVertex2f(865.106783157892, 885.1366406743712);

glEnd();



glPopMatrix();
}
//73
void planewindows(float x,float y, float z)

{
glPushMatrix();
glTranslatef(x,y,z);

glBegin(GL_POLYGON); //planewindows

if (day){
    glColor3ub(30,127,137);

}
else {
glColor3ub(255, 200, 120);  // Warm soft glow, realistic from far

}



glVertex2f(738.0034555159144, 903.6064047006784);
glVertex2f(744.2057131330224, 903.6064047006784);
glVertex2f(744.2057131330224, 897.0618718698764);
glVertex2f(738.0034555159144,897.0618718698764);


glEnd();

glPopMatrix();



}
//74
void busstop()
{
glBegin(GL_POLYGON);
glColor3ub(29,74,74);



glVertex2f(803.291692736092, 197.0352648632997);
glVertex2f(803.291692736092, 199.2118046640024);
glVertex2f(813.207544491456, 206.8188430864894);
glVertex2f(821.4715388011291, 206.8188430864894);

glVertex2f(834.2425999384857, 199.2118046640024);
glVertex2f(834.2425999384857, 197.0352648632997);


glEnd();


glBegin(GL_POLYGON);
glColor3ub(29,74,74);


glVertex2f(813.207544491456, 206.8188430864894);
glVertex2f(821.4715388011291, 206.8188430864894);
glVertex2f(821.4715388011291, 289.7648911141924);
glVertex2f(813.207544491456, 289.7648911141924);



glEnd();

glBegin(GL_POLYGON);
glColor3ub(239,228,184);


glVertex2f(776.7403906758012, 289.7648911141924);
glVertex2f(774.8509698325194, 292.5991807473344);
glVertex2f(774.8509698325194, 362.7354433054008);
glVertex2f(776.7403906758012, 364.7734474946672);

glVertex2f(856.300495718282, 364.7734474946672);
glVertex2f(859.6648104238571, 362.7354433054008);
glVertex2f(859.6648104238571, 292.5991807473344);
glVertex2f(856.300495718282, 289.7648911141924);




glEnd();


glBegin(GL_POLYGON);
glColor3ub(29,74,74);


glVertex2f(778.4568879172261, 292.6662667636034);
glVertex2f(778.4568879172261, 361.842600328581);
glVertex2f(856.1607497562582,  361.842600328581);
glVertex2f(856.1607497562582,  292.6662667636034);



glEnd();

}

//75
void lightpost()
{


callinglightposts(0,0,0);
callinglightposts(772,0,0);
callinglightposts(-730,0,0);





}
//76
void callinglightposts(float x,float y,float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);

glBegin(GL_POLYGON);
glColor3ub(29,74,74);



glVertex2f(1010.8900094638265, 197.2217729769726);
glVertex2f(1010.8900094638265, 199.2063826384082);
glVertex2f(1020.4707429696393, 206.5568334063476);
glVertex2f(1034.7110950626015, 206.5568334063476);

glVertex2f(1044.7497016705847, 199.2623932603429);
glVertex2f(1044.7497016705847, 197.2217729769726);


glEnd();


glBegin(GL_POLYGON);
glColor3ub(29,74,74);

glVertex2f(1020.4707429696393, 206.5568334063476);
glVertex2f(1034.7110950626015, 206.5568334063476);


glVertex2f(1034.7110950626015, 247.3475077030153);

glVertex2f(1020.4707429696393, 247.3475077030153);


glEnd();



glBegin(GL_POLYGON);
glColor3ub(29,74,74);


glVertex2f(1036.60833923574, 247.3475077030153);

glVertex2f(1036.60833923574, 251.7991232874709);
glVertex2f(1018.9063782986715, 251.7991232874709);

glVertex2f(1018.9063782986715, 247.3475077030153);



glEnd();


glBegin(GL_POLYGON);
glColor3ub(29,74,74);

glVertex2f(1036.60833923574, 251.7991232874709);
glVertex2f(1018.9063782986715, 251.7991232874709);

glVertex2f(1022.4977419614133, 255.1258802679503);
glVertex2f(1029.0896607107497,255.1258802679503);


glEnd();

glBegin(GL_POLYGON);
glColor3ub(29,74,74);



glVertex2f(1022.4977419614133, 255.1258802679503);
glVertex2f(1029.0896607107497,255.1258802679503);

glVertex2f(1029.0896607107497, 402.682186883316);
glVertex2f(1022.4977419614133, 402.682186883316);


glEnd();

glBegin(GL_POLYGON);
glColor3ub(29,74,74);



glVertex2f(1021.08330138751, 377.200363846169);
glVertex2f(1031.9533443894918, 377.200363846169);

glVertex2f(1031.9533443894918, 383.9992588266499);
glVertex2f(1021.08330138751, 383.9992588266499);


glEnd();

glBegin(GL_POLYGON);
glColor3ub(29,74,74);



glVertex2f(1029.0896607107497, 389.1206059719028);
glVertex2f(1043.676503912777, 402.8782338883655);

glVertex2f(1041.1348013383924, 405.1268014497558);
glVertex2f(1029.0896607107497, 396.4841952324461);


glEnd();


glBegin(GL_POLYGON);
glColor3ub(29,74,74);



glVertex2f(1022.4977419614133, 389.1206059719028);
glVertex2f(1008.364899846135, 402.8332240504913);

glVertex2f(1010.8451763302693, 406.2197554038342);
glVertex2f(1022.4977419614133, 396.4841952324461);


glEnd();


glBegin(GL_POLYGON);
glColor3ub(29,74,74);



glVertex2f(1043.676503912777, 402.8782338883655);
glVertex2f(1041.1348013383924, 405.1268014497558);

glVertex2f(1043.749307059747, 408.0934143928674);
glVertex2f(1045.748631067097, 410.5708376193705);
glVertex2f(1046.9334729760828, 411.6752770650774);
glVertex2f(1048.602678746848, 412.6319280401763);
glVertex2f(1050.9193748174416, 413.6126148820143);
glVertex2f(1053.7842523834122, 414.3299676526478);
glVertex2f(1055.74916592885, 414.7229503617361);
glVertex2f(1058.2380564197383, 414.9521902753709);
glVertex2f(1061.0369462754697, 415.4102470019726);
glVertex2f(1063.7561304225167, 415.2460247775279);
glVertex2f(1066.0142046631358, 415.1232896674933);
glVertex2f(1068.1716677279835, 414.7962941260444);
glVertex2f(1070.9153445498437, 413.9091166426895);
glVertex2f(1073.5356748951278, 412.5653574912597);
glVertex2f(1076.7606968585546, 410.4153428489719);
glVertex2f(1078.507583755411, 408.5340800369702);
glVertex2f(1079.1794633311247, 406.5184413098255);
glVertex2f(1079.1794633311247,402.8782338883655);



glEnd();


glBegin(GL_POLYGON);
glColor3ub(29,74,74);




glVertex2f(1008.364899846135, 402.8332240504913);
glVertex2f(1010.8451763302693, 406.2197554038342);

glVertex2f(1009.0295652616428, 408.9796613527321);
glVertex2f(1006.8174804034438, 411.1623352199339);
glVertex2f(1002.0868886410487, 413.6386869557131);
glVertex2f(996.8912675801857, 415.4817541926784);
glVertex2f(992.6847585167507, 416.3408964457562);
glVertex2f(988.4142537202071, 416.2354518828785);
glVertex2f(984.0294446650372, 415.7237436038033);
glVertex2f(980, 415);
glVertex2f(976.2500602855187, 412.8918294507552);
glVertex2f(972.3059338301745, 410.1660063548301);
glVertex2f(970.9041766475043, 406.9894927346591);
glVertex2f(970.1226802539186, 402.8332240504913);



glEnd();




glBegin(GL_POLYGON);

if (day) {
glColor3ub(230,224,187);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(230,224,187);
    }
}
//glColor3ub(230,224,187);




glVertex2f(1008.364899846135, 402.8332240504913);
glVertex2f(970.1226802539186, 402.8332240504913);


glVertex2f(970.5889342220217, 400.839323772417);
glVertex2f(971.6414653504444, 398.7751181308697);
glVertex2f(974.4891874064302, 395.6426238692805);
glVertex2f(978.9506186274748, 391.9405851964934);
glVertex2f(981.3867765155451, 390.4318522262992);
glVertex2f(984.4562146023808, 389.0928631405033);
glVertex2f(988.7063134556239, 388.6341654836666);
glVertex2f(993.6042820312216, 388.6753248834615);
glVertex2f(997.6379032111255, 389.7043098783366);
glVertex2f(1000.5933062529674, 390.8014963740973);
glVertex2f(1003.401554891477, 392.8440766436409);
glVertex2f(1005, 395);
glVertex2f(1007.2135324143362, 397.909307050736);
glVertex2f(1008.364899846135, 402.8332240504913);




glEnd();


glBegin(GL_POLYGON);
if (day) {
glColor3ub(230,224,187);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(230,224,187);
    }
}
//glColor3ub(230,224,187);



glVertex2f(1043.676503912777, 402.8782338883655);
glVertex2f(1079.1794633311247,402.8782338883655);

glVertex2f(1078.6815874734368, 400.6777450918949);
glVertex2f(1077.835704179697, 397.851194783103);
glVertex2f(1076.4896026453116, 395.5370187687829);
glVertex2f(1074.8794340465558, 393.3496016258131);
glVertex2f(1072.4200335576015, 391.7216895354019);
glVertex2f(1070, 390);
glVertex2f(1067.3019676102747, 388.9471552366586);
glVertex2f(1064.1838451781261, 388.3071795631323);
glVertex2f(1057.8136928234226, 388.5120686806658);
glVertex2f(1053.4656481420973, 389.5874254816436);
glVertex2f(1050.1542656602842, 391.1995869835254);
glVertex2f(1047.1422558235238, 393.2544725545671);
glVertex2f(1043.569845818288, 398.3215104861035);
glVertex2f(1042.9651542001454, 400.6059010435342);
glVertex2f(1043.676503912777, 402.8782338883655);





glEnd();

    glPopMatrix();
}
//77
void trees()
{
  callingtrees(0,0,0);
    callingtrees(190,0,0);
  callingtrees(465,0,0);
  callingtrees(639,0,0);
    callingtrees(-187,0,0);



}
//78
void callingtrees(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(72,135,78);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=25;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+269.5557533825555,y+446.2212872059691);
        }

glEnd();

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(72,135,78);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=29.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+257.2821602822069,y+ 430.0237405045797);
        }

glEnd();

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(72,135,78);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=28.22;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+286.9593879253919,y+427.3453703386981);
        }

glEnd();


glBegin(GL_POLYGON);
            glColor3ub(72,135,78);



glVertex2f(239.9334954741806, 373.0468921921411);
glVertex2f(242.2300480686073, 374.7693066379641);
glVertex2f(247.9005771290935, 375.5994364629332);
glVertex2f(255.342440147126, 376.3487322046316);

glVertex2f(262.6134708379841, 376.8665189717901);
glVertex2f(270.7418537690931, 376.8132241104713);
glVertex2f(276.0383816856148, 376.7028797788769);
glVertex2f(283.3109672344639, 376.3214338960614);

glVertex2f(286.7918178993061, 375.8770699813999);
glVertex2f(290.3831447928609, 374.7166818101782);
glVertex2f(291.1396905845463, 373.0468921921411);
glVertex2f(239.9334954741806, 373.0468921921411);




glEnd();


glBegin(GL_POLYGON);
            glColor3ub(72,135,78);



glVertex2f(239.9334954741806, 373.0468921921411);
glVertex2f(242.4852205790992, 370.7503395977104);
glVertex2f(246.4411988195984, 369.6675599313251);
glVertex2f(252.7483195215722, 368.2438089797832);

glVertex2f(256.5781291094916, 367.6401738733434);
glVertex2f(264.3015045684577, 366.9643785206829);
glVertex2f(270.4802049356307, 366.6747519409712);
glVertex2f(278.8793757472565, 367.447089486869);

glVertex2f(285.4442448873777, 368.9917645786646);
glVertex2f(290, 370);
glVertex2f(291.1396905845463, 373.0468921921411);





glEnd();


glBegin(GL_QUADS);
glColor3ub(17,73,70);



glVertex2f(264.1474347936718, 371.0266987522459);
glVertex2f(269.9897629279264, 371.0266987522459);
glVertex2f(269.4007175170522, 442.8584265754076);
glVertex2f(264.1474347936718, 442.8584265754076);

glVertex2f(269.9897629279264, 418.5443994694379);
glVertex2f(282.6039756606606, 428.7927067536757);
glVertex2f(285.7169279482381, 425.8725262921775);
glVertex2f(269.9897629279264, 411.5977674406212);


glVertex2f(264.1474347936718, 426.4161332908462);
glVertex2f(255.4077320018481, 435.3611716573191);
glVertex2f(251.0058867467713, 434.6935235056268);
glVertex2f(264.1474347936718, 419.6244284992313);





glEnd();






    glPopMatrix();


}

//79
void benches()
{
callingbenches(0,0,0);
callingbenches(-210,0,0);
callingbenches(-420,10,0);



}
//80
void callingbenches(float x,float y,float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
      glBegin(GL_QUADS);
glColor3ub(5,59,70);



glVertex2f(632.1847456231078, 348.913774770731);
glVertex2f(637.1296716500384, 348.913774770731);
glVertex2f(637.1296716500384, 368.7108989752135);
glVertex2f(632.1847456231078, 368.7108989752135);

glVertex2f(621.9416845673231, 349.4082673734248);
glVertex2f(626.9572523946383, 348.913774770731);
glVertex2f(626.9572523946383, 368.7108989752135);
glVertex2f(621.9416845673231, 368.7108989752135);


glVertex2f(533.1938308686734, 348.913774770731);
glVertex2f(537.4443126463423, 348.913774770731);
glVertex2f(537.4443126463423, 368.7108989752135);
glVertex2f(533.1938308686734, 368.7108989752135);


glVertex2f(521.1977069488976, 349.4082673734248);
glVertex2f(525.7109332083243, 348.913774770731);
glVertex2f(525.7109332083243, 368.7108989752135);
glVertex2f(521.1977069488976, 368.7108989752135);


glEnd();



   glBegin(GL_POLYGON);
glColor3ub(200,92,40);



glVertex2f(509.0827927241643, 374.6977267178743);
glVertex2f(509.0827927241643, 370.7645846133611);
glVertex2f(511.3335186607346, 367.6959857823626);
glVertex2f(643.0785234376133, 367.6959857823626);

glVertex2f(644.7446846284769, 370.7645846133611);
glVertex2f(644.7446846284769,  374.6977267178743);


glEnd();

glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(5,59,70);
glVertex2f(509.0827927241643, 370.7645846133611);
glVertex2f(644.7446846284769, 370.7645846133611);


glEnd();



 glBegin(GL_POLYGON);
glColor3ub(200,92,40);



glVertex2f(519.2419065417337, 401.4535343160748);
glVertex2f(518.6806769258509, 400.3613194608954);
glVertex2f(518.6806769258509, 398.8524472135018);
glVertex2f(519.2349565269334, 397.128021787909);

glVertex2f(634.7933206589313,397.128021787909);
glVertex2f(635.1105222697026, 398.8524472135018);
glVertex2f(634.7504187123631, 400.3613194608954);
glVertex2f(634.0886467247159, 401.4535343160748);


glEnd();

 glBegin(GL_POLYGON);
glColor3ub(200,92,40);



glVertex2f(519.2349565269334, 397.128021787909);
glVertex2f(518.6806769258509, 395.6499428516866);
glVertex2f(518.6806769258509, 394.048690670779);
glVertex2f(519.2349565269334, 392.8835391579862);

glVertex2f(634.7933206589313,392.8835391579862);
glVertex2f(635.1105222697026, 394.048690670779);
glVertex2f(634.7504187123631,  395.6499428516866);
glVertex2f(634.0886467247159, 397.128021787909);


glEnd();



glBegin(GL_QUADS);
glColor3ub(200,92,40);



glVertex2f(634.7933206589313,390.6822450682889);
glVertex2f(633.7482449943419, 384.7004446348747);
glVertex2f(520.3797699631242, 384.7004446348747);
glVertex2f(518.6806769258509, 390.6822450682889);

glVertex2f(634.7933206589313,383.2877852117356);
glVertex2f(634.7933206589313, 377.6834438018615);
glVertex2f(518.6806769258509, 377.6834438018615);
glVertex2f(518.6806769258509, 383.2877852117356);


glEnd();

glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(5,59,70);
glVertex2f(519.2349565269334, 397.128021787909);
glVertex2f(634.0886467247159, 397.128021787909);


glVertex2f(633.7482449943419, 384.7004446348747);
glVertex2f(520.3797699631242, 384.7004446348747);


glVertex2f(634.7933206589313, 377.6834438018615);
glVertex2f(518.6806769258509, 377.6834438018615);

glEnd();


    glPopMatrix();
}



//81
void smalllights()
{
 callsmalllights(0,0,0);
  callsmalllights(160,0,0);
    callsmalllights(320,0,0);
        callsmalllights(-160,0,0);
            callsmalllights(-320,0,0);
                callsmalllights(-500,0,0);
                    callsmalllights(-660,0,0);







}
//82
void callsmalllights(float x,float y,float z)
{
glPushMatrix();
glTranslatef(x,y,z);
   glBegin(GL_POLYGON);
glColor3ub(19,68,66);





glVertex2f(682.5522867090851, 378.4892814371102);
glVertex2f(682.5522867090851, 426.4164539915121);
glVertex2f(678.0699432258281,426.4164539915121);
glVertex2f(678.0699432258281, 378.4892814371102);


glEnd();


   glBegin(GL_POLYGON);
glColor3ub(19,68,66);



glVertex2f(675.8295771269818, 373.1005688148449);
glVertex2f(684.693822089938,  373.1005688148449);
glVertex2f(685.4076672168889, 376.347746056254);
glVertex2f(682.5522867090851, 378.4892814371102);


glVertex2f(678.0699432258281, 378.4892814371102);
glVertex2f(674.4476647681364, 375.86439353254);
glVertex2f(675.708966287769, 373.1005688148449);

glEnd();


glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {


	if (day) {
glColor3ub(215,223,193);
}
else {
    if (lightsOn) {
        glColor3ub(255, 200, 120); // Warm glow when light is ON
    } else {
glColor3ub(215,223,193);
    }
}
            //glColor3ub(215,223,193);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7.32;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+679.5847147415702,y+433.2443148916606);
        }

glEnd();
 glPopMatrix();
}

//a2
void update(int value) {
    _move -= 1.5;
    if (_move < -1900) {
        _move = 0;  // reset to 0 for seamless looping
    }
    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}
//a3
void update1(int value) {
    train_move += train_speeda;

    if (train_move > 1900) {
        train_move = -1500;
    }

    glutPostRedisplay();
    glutTimerFunc(20, update1, 0);
}





//a4
void update2(int value) {
    boat_move1 -= boat1_speeda;
    if (boat_move1 < -1600) {
        boat_move1 = 1200;  // reset for seamless looping
    }
    glutPostRedisplay();
    glutTimerFunc(20, update2, 0);
}
//a5
void update3(int value) {
    boat_move2 -= 0.6;

    // Stop when it reaches a certain point, say -1000
    if (boat_move2 < -430) {
        boat_move2 = -430; // Stop here
    }
    else {
        // Keep updating if we haven't reached the limit
        glutTimerFunc(20, update3, 0);
    }

    glutPostRedisplay();
}

/*void update4(int value) {
     plane_move += 4;
    if ( plane_move >1900) {
         plane_move = -1000;  // reset to 0 for seamless looping
    }
    glutPostRedisplay();
    glutTimerFunc(20, update4, 0);
}*/
//a6
void update4(int value) {
    plane_move += plane_speed;
    if (plane_move > 1900) {
        plane_move = -1000;
    }
    glutPostRedisplay();
    glutTimerFunc(20, update4, 0);
}


/*void handleSpecialKey(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        if (plane_y_offset < 90.0f)
            plane_y_offset += 10.0f;
    } else if (key == GLUT_KEY_DOWN) {
        if (plane_y_offset > -50.0f)
            plane_y_offset -= 10.0f;
    }
    glutPostRedisplay();
}*/


//a7
void update5(int value) {
    bus1_move += bus1_speed;

    if (bus1_move > 1900) {
        bus1_move = -1700;  // reset position for seamless looping
    }

    glutPostRedisplay();
    glutTimerFunc(20, update5, 0);
}


//a8
void update6(int value) {
    if (!manualCar2Control) {
        car2_movea += car2_speeda;
        if (car2_movea > 1900) {
            car2_movea = -1700;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, update6, 0);
}


/*void update7(int value) {
     bus2_move -= 5;
    if (  bus2_move <-700) {
          bus2_move = 2800;  // reset to 0 for seamless looping
    }
    glutPostRedisplay();
    glutTimerFunc(20, update7, 0);
}*/
//a9
void update7(int value) {
    if (bus2_speed > 0) {
        bus2_move -= bus2_speed;
    }

    if (bus2_move < -700) {
        bus2_move = 2800;
    }

    glutPostRedisplay();
    glutTimerFunc(20, update7, 0);
}

/*
void update8(int value) {
     pickup_move -= 5;
    if (  pickup_move <-1200) {
          pickup_move = 2600;  // reset to 0 for seamless looping
    }
    glutPostRedisplay();
    glutTimerFunc(20, update8, 0);
}
*/



/*void update9(int value) {
     car1_move -= 5;
    if (  car1_move <-1900) {
          car1_move = 2000;  // reset to 0 for seamless looping
    }
    glutPostRedisplay();
    glutTimerFunc(20, update9, 0);
}
*/
//a10
void update8(int value) {
    if (!paused) {
        pickup_move -= speed;
    }

    if (pickup_move < -1200) {
        pickup_move = 2600;  // reset for seamless looping
    }

    glutPostRedisplay();
    glutTimerFunc(20, update8, 0);
}
//a11
void update9(int value) {
    if (!paused) {
        car1_move -= speed;
    }

    if (car1_move < -1800) {
        car1_move = 2000;  // reset for seamless looping
    }

    glutPostRedisplay();
    glutTimerFunc(20, update9, 0);
}
//a12
void toggleColor(int value) {
    if (signboardToggleEnabled) {
        isRed = !isRed;  // Toggle only if allowed
        glutPostRedisplay();
    }
    glutTimerFunc(500, toggleColor, 0); // Keep calling
}

void adisplay2();  // Declaration

void adisplay1();  // Declaration







void adisplay1() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
  // Clear the color buffer with current clearing color
background();

lake();


waves(-1000,-70,0);
waves(-1200,-80,0);
waves(-1400,-65,0);
waves(-1600,-60,0);
waves(-1100,-55,0);
waves(-900,-60,0);


waves(0,0,0);
waves(-80,-20,0);
waves(50,60,0);
waves(-280,-50,0);
waves(-300,-60,0);

waves(-850,-72,0);

waves(-600,-70,0);
waves(-500,-80,0);
waves(-450,-55,0);
waves(-200,10,0);
waves(-300,50,0);
waves(-150,20,0);
waves(100,-70,0);
waves(50,80,0);
waves(200,20,0);
waves(50,45,0);
waves(-20,25,0);
waves(-100,80,0);
waves(-100,-100,0);
waves(-120,-85,0);












waves(0 + 1900, 0, 0);
waves(-80 + 1900, -20, 0);
waves(50 + 1900, 60, 0);
waves(-280 + 1900, -50, 0);
waves(-300 + 1900, -60, 0);
waves(-1000 + 1900, -70, 0);
waves(-1200 + 1900, -80, 0);
waves(-1400 + 1900, -65, 0);
waves(-1600 + 1900, -60, 0);
waves(-900 + 1900, -60, 0);
waves(-850 + 1900, -72, 0);
waves(-1100 + 1900, -55, 0);
waves(-600 + 1900, -70, 0);
waves(-500 + 1900, -80, 0);
waves(-450 + 1900, -55, 0);
waves(-200 + 1900, 10, 0);
waves(-300 + 1900, 50, 0);
waves(-150 + 1900, 20, 0);
waves(100 + 1900, -70, 0);
waves(50 + 1900, 80, 0);
waves(200 + 1900, 20, 0);
waves(50 + 1900, 45, 0);
waves(-20 + 1900, 25, 0);
waves(-100 + 1900, 80, 0);
waves(-100 + 1900, -100, 0);
waves(-120 + 1900, -85, 0);



waves(300, 0, 0);
waves(750, 0, 0);       // -1150 + 1900
waves(900, 10, 0);      // -1000 + 1900
waves(700, 20, 0);      // -1200 + 1900
waves(500, 35, 0);      // -1400 + 1900
waves(300, -20, 0);     // -1600 + 1900
waves(800, 20, 0);      // -1100 + 1900
waves(1000, 60, 0);     // -900 + 1900
waves(1620, 50, 0);     // -280 + 1900
waves(1600, 60, 0);     // -300 + 1900
waves(1050, 72, 0);     // -850 + 1900
waves(1300, 70, 0);     // -600 + 1900
waves(1400, 80, 0);     // -500 + 1900
waves(1450, 55, 0);     // -450 + 1900
waves(2000, 70, 0);     // 100 + 1900
waves(1800, 100, 0);    // -100 + 1900
waves(300,100, 0);
waves(1780, 85, 0);     // -120 + 1900
waves(300, 85, 0);



greenfeild();
trees();
smalllights();

benches();


road();
walkway();


 for (int i = 0; i < NUM_BIRDS; i++) {
    AnimatedBirda(birdXa[i], birdYa[i], 0.6, wingAnglea[i]);  // Smaller birds
}

plane();

backbuildings();
building2();
building1();
building3();
building5();
building6();
building4();
building7();
building8();
building10();
building9();
building11();
building12();
building13();

bushes(0,0,0);
bushes(-850,0,0);
bushes(-1500,0,0);


train();
bridge(0,0,0);
bridge(60,0,0);
bridge(130,0,0);
bridge(195,0,0);
bridge(265,0,0);
bridge(335,0,0);
//bridge(380,0,0);
bridge(440,0,0);
bridge(480,0,0);
bridge(520,0,0);
bridge(560,0,0);
bridge(600,0,0);

boat1();
boat2();


//train(-221,0,0);

for(int i=0;i<1900;i=i+60){
railing(i,0,0);

}
busstop();

   // glColor3ub(239,228,184);


    if (isRed)
    glColor3ub(255, 0, 0);     // Red
  else
    glColor3ub(255, 255, 0);   // Yellow

    renderText(794.6318599264304, 340.9608711812609, "BUS");//add text and change position
        renderText(787.8653453126237, 311.8268041882976, "STOP");//add text and change position


lightpost();
bus1();
car2();
bus2();
car1();
pickup();



glutSwapBuffers();

	  // Render now
}


void adisplay2() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
  // Clear the color buffer with current clearing color
background1();

lake();


waves(-1000,-70,0);
waves(-1200,-80,0);
waves(-1400,-65,0);
waves(-1600,-60,0);
waves(-1100,-55,0);
waves(-900,-60,0);


waves(0,0,0);
waves(-80,-20,0);
waves(50,60,0);
waves(-280,-50,0);
waves(-300,-60,0);

waves(-850,-72,0);

waves(-600,-70,0);
waves(-500,-80,0);
waves(-450,-55,0);
waves(-200,10,0);
waves(-300,50,0);
waves(-150,20,0);
waves(100,-70,0);
waves(50,80,0);
waves(200,20,0);
waves(50,45,0);
waves(-20,25,0);
waves(-100,80,0);
waves(-100,-100,0);
waves(-120,-85,0);












waves(0 + 1900, 0, 0);
waves(-80 + 1900, -20, 0);
waves(50 + 1900, 60, 0);
waves(-280 + 1900, -50, 0);
waves(-300 + 1900, -60, 0);
waves(-1000 + 1900, -70, 0);
waves(-1200 + 1900, -80, 0);
waves(-1400 + 1900, -65, 0);
waves(-1600 + 1900, -60, 0);
waves(-900 + 1900, -60, 0);
waves(-850 + 1900, -72, 0);
waves(-1100 + 1900, -55, 0);
waves(-600 + 1900, -70, 0);
waves(-500 + 1900, -80, 0);
waves(-450 + 1900, -55, 0);
waves(-200 + 1900, 10, 0);
waves(-300 + 1900, 50, 0);
waves(-150 + 1900, 20, 0);
waves(100 + 1900, -70, 0);
waves(50 + 1900, 80, 0);
waves(200 + 1900, 20, 0);
waves(50 + 1900, 45, 0);
waves(-20 + 1900, 25, 0);
waves(-100 + 1900, 80, 0);
waves(-100 + 1900, -100, 0);
waves(-120 + 1900, -85, 0);



waves(300, 0, 0);
waves(750, 0, 0);       // -1150 + 1900
waves(900, 10, 0);      // -1000 + 1900
waves(700, 20, 0);      // -1200 + 1900
waves(500, 35, 0);      // -1400 + 1900
waves(300, -20, 0);     // -1600 + 1900
waves(800, 20, 0);      // -1100 + 1900
waves(1000, 60, 0);     // -900 + 1900
waves(1620, 50, 0);     // -280 + 1900
waves(1600, 60, 0);     // -300 + 1900
waves(1050, 72, 0);     // -850 + 1900
waves(1300, 70, 0);     // -600 + 1900
waves(1400, 80, 0);     // -500 + 1900
waves(1450, 55, 0);     // -450 + 1900
waves(2000, 70, 0);     // 100 + 1900
waves(1800, 100, 0);    // -100 + 1900
waves(300,100, 0);
waves(1780, 85, 0);     // -120 + 1900
waves(300, 85, 0);



greenfeild();
trees();
smalllights();

benches();


road();
walkway();


 for (int i = 0; i < NUM_BIRDS; i++) {
    AnimatedBirda(birdXa[i], birdYa[i], 0.6, wingAnglea[i]);  // Smaller birds
}

plane();

backbuildings();
building2();
building1();
building3();
building5();
building6();
building4();
building7();
building8();
building10();
building9();
building11();
building12();
building13();

bushes(0,0,0);
bushes(-850,0,0);
bushes(-1500,0,0);


train();
bridge(0,0,0);
bridge(60,0,0);
bridge(130,0,0);
bridge(195,0,0);
bridge(265,0,0);
bridge(335,0,0);
//bridge(380,0,0);
bridge(440,0,0);
bridge(480,0,0);
bridge(520,0,0);
bridge(560,0,0);
bridge(600,0,0);

boat1();
boat2();


//train(-221,0,0);

for(int i=0;i<1900;i=i+60){
railing(i,0,0);

}
busstop();

   // glColor3ub(239,228,184);


    if (isRed)
    glColor3ub(255, 0, 0);     // Red
  else
    glColor3ub(255, 255, 0);   // Yellow

    renderText(794.6318599264304, 340.9608711812609, "BUS");//add text and change position
        renderText(787.8653453126237, 311.8268041882976, "STOP");//add text and change position


lightpost();
bus1();
car2();
bus2();
car1();
pickup();

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
glColor4f(0.0f, 0.0f, 0.0f, 0.3f);
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

glutSwapBuffers();

	  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */

