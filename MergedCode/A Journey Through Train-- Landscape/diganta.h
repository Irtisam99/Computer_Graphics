#include <windows.h>  // for MS Windows
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

#define MAX_DROPS 100
#define MAX_BUBBLES 100

bool isNight = false;
float _moveTrain = 0.0f;
float _moveBoat = 0.0f;
float _moveShip = 0.0f;
const float groundY = 100.0f;
int rainActive = 0;
float trainSpeed = 3.5f;  // Initial train speed
float shipSpeed = 1.0f;
float boatSpeed = 4.0f;
int cloudDirection = 1;
float _moveCloud = 0.0f;
float _moveCloud2 = 0.0f;
float _moveWave = 0.0f;
bool lightOn = true;   // Light blinking flag


//bird
float birdXd = 0, birdYd = 900, birdWingY = -1, birdDirection = 1;
unsigned long long lastFrameTime = 0;

struct RGB {
    int red;
    int green;
    int blue;
};

RGB skyTop = {147, 236, 244};
RGB skyBottom = {243, 240, 189};

// Raindrop data
float dropXd[MAX_DROPS];
float dropYd[MAX_DROPS];
float dropSpeed[MAX_DROPS];
int dropCount = 0;

// Bubble data
float bubbleX[MAX_BUBBLES];
float bubbleY[MAX_BUBBLES];
float bubbleRadius[MAX_BUBBLES];
float bubbleAlpha[MAX_BUBBLES];
int bubbleActive[MAX_BUBBLES];
int bubbleCount = 0;

//D1
void skyD()
{
    if (isNight)
        glColor3ub(10, 15, 35);  // Dark sky
    else
        glColor3ub(167, 196, 245);  // Day sky
glBegin(GL_POLYGON);
glVertex2f(0.000, 520.397);
glVertex2f(1900.358, 529.558);
glVertex2f(1900.000, 1000.000);
glVertex2f(0.000, 1000.000);
glEnd();

}

//D2
void grassD()
{
    if (isNight)
        glColor3ub(30, 60, 30);
    else
        glColor3ub(76, 249, 102);
glBegin(GL_POLYGON);
glVertex2f(1900.358, 529.558);
glVertex2f(1900.961, 364.664);
glVertex2f(0.000, 370.303);
glVertex2f(0.000, 520.397);
glEnd();

}

//D3
void seaD() {

    if (isNight)
        glColor3ub(40, 49, 101);
    else
        glColor3ub(0, 119, 190);

    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0, 200);
    glVertex2f(200, 200);
    glVertex2f(348.97207, 206.83838);
    glVertex2f(449.32002, 215.09485);
    glVertex2f(474.08945, 222.71621);
    glVertex2f(472.81922, 232.24292);
    glVertex2f(447.41468, 238.59405);
    glVertex2f(299.43321, 267.17417);
    glVertex2f(254.34014, 287.49780);
    glVertex2f(256.88059, 304.01076);
    glVertex2f(298.16298, 318.61837);
    glVertex2f(366.12014, 325.60462);
    glVertex2f(465.19786, 328.14507);
    glVertex2f(583.32899, 327.50996);
    glVertex2f(748.45853, 326.87485);
    glVertex2f(1100.51765, 322.98867);
    glVertex2f(1239.49799, 322.89829);
    glVertex2f(1325.21690, 324.66553);
    glVertex2f(1331.92435, 311.25065);
    glVertex2f(1898.70305, 310.41222);
    glVertex2f(1900, 0);
    glVertex2f(0, 0);
    glEnd();
}

//D4
void sandD()
{

    if (isNight)
        glColor3ub(106, 109, 78);
    else
        glColor3ub(194, 178, 128);
    glBegin(GL_POLYGON);
    glVertex2f(0, 200);
    glVertex2f(200, 200);
    glVertex2f(348.97207, 206.83838);
    glVertex2f(449.32002, 215.09485);
    glVertex2f(474.08945, 222.71621);
    glVertex2f(472.81922, 232.24292);
    glVertex2f(447.41468, 238.59405);
    glVertex2f(299.43321, 267.17417);
    glVertex2f(254.34014, 287.49780);
    glVertex2f(256.88059, 304.01076);
    glVertex2f(298.16298, 318.61837);
    glVertex2f(366.12014, 325.60462);
    glVertex2f(465.19786, 328.14507);
    glVertex2f(583.32899, 327.50996);
    glVertex2f(748.45853, 326.87485);
    glVertex2f(1100.51765, 322.98867);
    glVertex2f(1102.19451, 336.40355);
    glVertex2f(1116.88792, 344.03499);
    glVertex2f(1140.57159, 348.85201);
    glVertex2f(1162.24817, 342.83074);
    glVertex2f(1176.29780, 351.26052);
    glVertex2f(1193.55878, 362.50023);
    glVertex2f(1209.61550, 369.32433);
    glVertex2f(0, 370.303);
glEnd();
}

//D5
void upperMountainD()
{

    glColor3ub(34, 85, 34);
    glBegin(GL_POLYGON);      //upper mountain
    glVertex2f(0, 520.397);
    glVertex2f(1350.21492, 523.02251);
    glVertex2f(1357.13561, 569.60940);
    glVertex2f(1266.58142, 604.23306);
    glVertex2f(1178.29338, 651.61263);
    glVertex2f(1060.58239, 731.65611);
    glVertex2f(1029.97753, 741.07299);
    glVertex2f(1002.51164, 734.79507);
    glVertex2f(955.42724, 706.54443);
    glVertex2f(766.30492, 854.07554);
    glVertex2f(737.26954, 858.78397);
    glVertex2f(700, 850);
    glVertex2f(512.99727, 730.09142);
    glVertex2f(434.90888, 790.28455);
    glVertex2f(413.95669, 797.57426);
    glVertex2f(400, 800);
    glVertex2f(363.32786, 785.40403);
    glVertex2f(2.16906, 583.67569);
    glVertex2f(0, 520.397);
    glEnd();


    glColor3ub(144, 238, 144);
    glBegin(GL_POLYGON);               //upper mountain shade
    glVertex2f(413.95669, 797.57426);
    glVertex2f(434.90888, 790.28455);
    glVertex2f(512.99727, 730.09142);
    glVertex2f(655.65659, 621.79252);
    glVertex2f(593.66213, 621.79252);
    glVertex2f(536.37612, 660.24477);
    glVertex2f(490.07646, 696.34281);
    glVertex2f(453.19368, 715.17657);
    glVertex2f(427.29727, 731.65611);
    glVertex2f(408.46351, 760.69148);
    glVertex2f(403.75507, 781.87946);
    glVertex2f(413.95669, 797.57426);
    glEnd();

    glColor3ub(144, 238, 144);
    glBegin(GL_POLYGON);               //upper mountain shade
    glVertex2f(752.0242312886954, 857.6335145961175);
    glVertex2f(740.7566093735469, 842.8380312325363);
    glVertex2f(741.5601893790899, 833.195071166021);
    glVertex2f(752.8103094566923, 823.150321096734);
    glVertex2f(893.8386004294935, 703.0151102680633);
    glVertex2f(937.7373123855926, 681.071931353679);
    glVertex2f(972.0943869197199, 667.3291015400293);
    glVertex2f(1006.4353347839744, 661.814252293014);
    glVertex2f(955.4272392846966, 706.5444283462256);
    glVertex2f(766.3049159719892, 854.0755353287481);
    glVertex2f(752.0242312886954, 857.6335145961175);
    glEnd();

     glColor3ub(144, 238, 144);
    glBegin(GL_POLYGON);               //upper mountain shade
    glVertex2f(1041.989246543474, 736.9560305077761);
    glVertex2f(1044.8228531057034, 715.2317135306864);
    glVertex2f(1057.101814875364, 698.7023419176835);
    glVertex2f(1092.5218969032308, 672.2553473368787);
    glVertex2f(1143.9990827837303, 640.6134073919872);
    glVertex2f(1211.0611047564914, 606.1378608848667);
    glVertex2f(1289.9298207385414, 580.1631340644334);
    glVertex2f(1357.1356089756844, 569.6093953070555);
    glVertex2f(1266.5814198900184, 604.233055839809);
    glVertex2f(1178.2933796200032, 651.6126331931587);
    glVertex2f(1060.5823900062849, 731.6561061304848);
    glVertex2f(1041.989246543474, 736.9560305077761);
    glEnd();
}


void lowerMountainD()
{

    glColor3ub(34, 85, 34); // Green color lower mountain
    glBegin(GL_POLYGON);
    glVertex2f(1100.517653024287, 322.9886711803332);
    glVertex2f(1102.1945131121886, 336.4035518835449);
    glVertex2f(1116.8879245424214, 344.0349944619284);
    glVertex2f(1127.7378213502996, 346.2553323128579);
    glVertex2f(1140.5715918341173, 348.8520115382054);
    glVertex2f(1162.2481686773644, 342.8307401928591);
    glVertex2f(1176.297801816506, 351.2605200763439);
    glVertex2f(1193.5587796731656, 362.500226587657);
    glVertex2f(1209.6155032607562, 369.3243341123828);
    glVertex2f(1217.382867709596, 371.9731868997726);
    glVertex2f(1226.8764811174158, 372.1342607402111);
    glVertex2f(1226.475063027726, 385.3810576999729);
    glVertex2f(1231.094532446617, 395.4137088072368);
    glVertex2f(1234.904842911211, 404.649126005081);
    glVertex2f(1243.2089456834497, 414.493909655247);
    glVertex2f(1248.9544760503527, 421.1072676823609);
    glVertex2f(1262.5920068623816, 431.7569485177324);
    glVertex2f(1275.0466518801873, 440.375335987469);
    glVertex2f(1291.6665986307794, 446.8999650637723);
    glVertex2f(1307.1600990553682, 450.4107882297129);
    glVertex2f(1320.4383300682564, 453.260032013109);
    glVertex2f(1331.896348084552, 453.1821382086485);
    glVertex2f(1357.2455506347699, 471.9719365622368);
    glVertex2f(1380.852705507236, 487.2846856687006);
    glVertex2f(1419.7726094861662, 506.4256220517804);
    glVertex2f(1447.8459828480177, 513.443965392243);
    glVertex2f(1472.4220642190985, 516.574830721526);
    glVertex2f(1491.2321053163337, 526.2045896476294);
    glVertex2f(1515.2895900064052, 525.1483358789872);
    glVertex2f(1535.2562589974189, 520.4623087327054);
    glVertex2f(1550.8083970873165, 501.8773933087357);
    glVertex2f(1585.1024177171619, 510.4508984661968);
    glVertex2f(1620.6212247980732, 488.4047423470111);
    glVertex2f(1645.1169538193915, 489.629528798077);
    glVertex2f(1657.120220636365, 510.8918405411656);
    glVertex2f(1669.6126828407096, 522.6987629768554);
    glVertex2f(1690.2978437003715, 530.6708081370147);
    glVertex2f(1712.4802086280163, 525.1483358789872);
    glVertex2f(1717.7331858494535, 551.087806945633);
    glVertex2f(1729.627218942939, 564.3415023130949);
    glVertex2f(1765.1460260238505, 559.4423565088314);
    glVertex2f(1781.0682498877072, 543.5201326449751);
    glVertex2f(1809.2383382622231, 568.0158616662925);
    glVertex2f(1834.9588537346071, 564.3415023130949);
    glVertex2f(1849.656291147398, 552.0936378024362);
    glVertex2f(1899.1342724540682, 544.3237746385254);
    glVertex2f(1900, 500);
    glVertex2f(1898.7030548653986, 310.4122205210723);
    glVertex2f(1331.9243451546924, 311.250650565023);
    glVertex2f(1325.2169048030864, 324.6655312682346);
    glVertex2f(1239.497986510722, 322.8982889075618);
    glVertex2f(1100.517653024287, 322.9886711803332);
glEnd();


}

//D6
void lightHouseD()
{

    glColor3f(1.0, 1.0, 0.0); // Yellow color
glBegin(GL_POLYGON);
glVertex2f(1380.000, 720.000);
glVertex2f(1447.832, 719.994);
glVertex2f(1447.947, 763.572);
glVertex2f(1377.582, 764.035);
glEnd();

     glColor3ub(86, 83, 82);
    glBegin(GL_POLYGON);
glVertex2f(1361.165, 720.217);
glVertex2f(1369.789, 702.172);
glVertex2f(1456.670, 701.508);
glVertex2f(1466.253, 718.994);
glEnd();


    glColor3ub(246, 213, 202);
    glBegin(GL_POLYGON);
glVertex2f(1367.704, 660.626);
glVertex2f(1457.754, 660.626);
glVertex2f(1456.670, 701.172);
glVertex2f(1361.165, 702.175);
glEnd();

    glColor3ub(223, 87, 14);
    glBegin(GL_POLYGON);
glVertex2f(1362.190, 606.106);
glVertex2f(1460.817, 606.106);
glVertex2f(1457.754, 660.626);
glVertex2f(1367.704, 660.626);
glEnd();

    glColor3ub(246, 213, 202);
    glBegin(GL_POLYGON);
glVertex2f(1356.889, 546.469);
glVertex2f(1468.662, 548.189);
glVertex2f(1460.817, 606.106);
glVertex2f(1362.190, 606.106);
glEnd();

    glColor3ub(223, 87, 14); // orange colour
    glBegin(GL_POLYGON);
    glVertex2f(1344.3572, 480.5113);  // M2 - updated top-left corner
    glVertex2f(1475.240, 477.343);    // top-right corner
    glVertex2f(1468.662, 548.189);    // bottom-right
    glVertex2f(1356.889, 546.469);    // bottom-left
    glEnd();


    glColor3ub(90, 84, 72);
    glBegin(GL_POLYGON);
    glVertex2f(1331.89635, 453.18214);  // M1
glVertex2f(1501.97, 449.66);  // Q1
glVertex2f(1498.92820, 484.40969);  // N2
glVertex2f(1332.44944, 484.12991);  // N1
glVertex2f(1331.89635, 453.18214);
glEnd();


glColor3ub(90, 84, 72);
glBegin(GL_POLYGON);
glVertex2f(1393.6774, 523.6162);
glVertex2f(1406.6313, 523.6162);
glVertex2f(1407.1296, 506.6765);
glVertex2f(1394.1756, 505.6800);
glVertex2f(1393.6774, 523.6162);
glEnd();

glColor3ub(90, 84, 72);
glBegin(GL_POLYGON);
glVertex2f(1392.679, 638.850);
glVertex2f(1402.949, 639.199);
glVertex2f(1402.775, 625.622);
glVertex2f(1392.505, 625.448);
glEnd();

glColor3ub(90, 84, 72);
glBegin(GL_POLYGON);
glVertex2f(1392.989, 752.702);
glVertex2f(1401.851, 752.386);
glVertex2f(1402.168, 742.575);
glVertex2f(1392.989, 742.733);
glEnd();

  glColor3ub(90, 84, 72);
glBegin(GL_POLYGON);
glVertex2f(1363.702, 758.284);
glVertex2f(1463.432, 758.284);
glVertex2f(1411.605, 801.232);
glEnd();


}

//D7
void trainD()
{
    glColor3ub(225, 225, 192);
    glBegin(GL_POLYGON);
    glVertex2f(243.60,621.47);
    glVertex2f(243.63,544.16);
    glVertex2f(882.80,542.27);
    glVertex2f(884.31,546.58);
    glVertex2f(889.54,553.91);
    glVertex2f(890.067,561.76);
    glVertex2f(852.38,610.44);
    glVertex2f(842.50,618.02);
    glVertex2f(824.77,621.90);
    glVertex2f(243.60,621.47);
    glEnd();

    glColor3ub(48, 179, 172);
    glBegin(GL_POLYGON);
    glVertex2f(882.7955595554978, 542.2770068030924);
    glVertex2f(884.3099378921394, 546.5842991150913);
    glVertex2f(244.0712991997618, 552.4856808906419);
    glVertex2f(243.6032330107257, 544.1553459846156);
    glVertex2f(882.7955595554978, 542.2770068030924);

    glEnd();

     glColor3ub(48, 179, 172);
    glBegin(GL_POLYGON);
    glVertex2f(864.0677725736643, 555.0164617704327);
    glVertex2f(834.6405385441908, 563.7994402126949);
    glVertex2f(244.0952591964318, 566.4527347571105);
    glVertex2f(243.8988973841013, 557.8301371761182);
    glVertex2f(864.0677725736643, 555.0164617704327);

    glEnd();

}
void trainDoorD(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glColor3ub(225, 225, 192);
    glBegin(GL_POLYGON);
    glVertex2f(760.0126784360516, 545.2929315287196);
    glVertex2f(760.4725880938887, 603.2415484161943);
    glVertex2f(733.3379182814988, 603.7014580740314);
    glVertex2f(732.9993474307444, 545.2996548292754);
    glVertex2f(760.0126784360516, 545.2929315287196);
    glEnd();

    glLineWidth(3);
    glColor3ub(48, 179, 172);
    glBegin(GL_LINES);
    glVertex2f(760.0126784360516, 545.2929315287196);
    glVertex2f(760.4725880938887, 603.2415484161943);
    glVertex2f(760.4725880938887, 603.2415484161943);
    glVertex2f(733.3379182814988, 603.7014580740314);
    glVertex2f(733.3379182814988, 603.7014580740314);
    glVertex2f(732.9993474307444, 545.2996548292754);
    glEnd();

    glColor3ub(48, 179, 172);
    glBegin(GL_POLYGON);
    glVertex2f(739.6144257778703, 575.7346478931541);
    glVertex2f(754.5517112125503, 575.5699527950503);
    glVertex2f(755.6716317052657, 597.1442557963471);
    glVertex2f(739.1278437800705, 597.1442557963471);
    glVertex2f(739.6144257778703, 575.7346478931541);
    glEnd();


    glPopMatrix();
}

void trainWindowD(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glColor3ub(50, 50, 48);
    glBegin(GL_POLYGON);
    glVertex2f(769.8693119143255, 574.7289621588014);
    glVertex2f(802.6270123912508, 575.0092591465637);
    glVertex2f(803.5092714309268, 599.8889640654254);
    glVertex2f(770, 600);
    glVertex2f(769.8693119143255, 574.7289621588014);
    glEnd();
    glPopMatrix();

    glColor3ub(50, 50, 48);
    glBegin(GL_POLYGON);
    glVertex2f(820.0023850140296, 574.521483893623);
    glVertex2f(862.4653962858492, 574.9547799270089);
    glVertex2f(850.7664033844295, 595.3196934961459);
    glVertex2f(844.7002589170268, 600.5192458967765);
    glVertex2f(820, 600);
    glVertex2f(820.0023850140296, 574.521483893623);
    glEnd();

}

void trainWheelsD(float x, float y, float z) {
    glPushMatrix();

    glTranslatef(x,y,z);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(0, 0, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 10.315;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x +784.568, y + 532.225);
    }
    glEnd();
    glPopMatrix();
}
//D8
void building1D(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glColor3ub(247, 171, 66);
    glBegin(GL_POLYGON);
    glVertex2f(1729.1232366231184, 607.4523301254872);
    glVertex2f(1801.8960871779161, 607.4523301254872);
    glVertex2f(1803.4227903364085, 542.3129953631541);
    glVertex2f(1731.1588408344414, 543.8396985216463);
    glVertex2f(1729.1232366231184, 607.4523301254872);
    glEnd();

    glColor3ub(151, 105, 43);
    glBegin(GL_POLYGON);
    glVertex2f(1869.0710261515758, 607.9612311783179);
    glVertex2f(1801.8960871779161, 607.4523301254872);
    glVertex2f(1803.4227903364085, 542.3129953631541);
    glVertex2f(1870.088828257237, 543.8396985216463);
    glVertex2f(1869.0710261515758, 607.9612311783179);
    glEnd();

    glColor3ub(132, 113, 24);
    glBegin(GL_POLYGON);
    glVertex2f(1801.8960871779161, 607.4523301254872);
    glVertex2f(1869.0710261515758, 607.9612311783179);
    glVertex2f(1840, 640);
    glVertex2f(1801.8960871779161, 607.4523301254872);
    glEnd();

    glColor3ub(225, 103, 35);
    glBegin(GL_POLYGON);
    glVertex2f(1801.8960871779161, 607.4523301254872);
    glVertex2f(1840, 640);
    glVertex2f(1760, 640);
    glVertex2f(1729.1232366231184, 607.4523301254872);
    glVertex2f(1801.8960871779161, 607.4523301254872);
    glEnd();

    if (isNight)
        glColor3ub(232, 255, 0);  // Dark sky
    else
        glColor3ub(62, 72, 53);  // Day sky
    glBegin(GL_POLYGON);
    glVertex2f(1846.2825119048873, 590.5218120978496);
    glVertex2f(1857.537555670051, 590.0889257991895);
    glVertex2f(1857.1046693713909, 574.5050190474252);
    glVertex2f(1846.2825119048873, 574.9379053460854);
    glVertex2f(1846.2825119048873, 590.5218120978496);
    glEnd();

    if (isNight)
        glColor3ub(232, 255, 0);  // Dark sky
    else
        glColor3ub(62, 72, 53);  // Day sky
    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glVertex2f(1821.681774961267, 591.1982558649668);
    glVertex2f(1831.4971098527171, 590.891526649609);
    glVertex2f(1831.4971098527171, 575.5550658817191);
    glVertex2f(1821.681774961267, 575.5550658817191);
    glEnd();

    if (isNight)
        glColor3ub(232, 255, 0);  // Dark sky
    else
        glColor3ub(62, 72, 53);  // Day sky
    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glVertex2f(1775.0589342268786, 589.9713390035355);
    glVertex2f(1784.5675399029708, 589.9713390035355);
    glVertex2f(1784.260810687613, 574.3281490202879);
    glVertex2f(1775.0589342268786, 575.2483366663613);
    glEnd();

    if (isNight)
        glColor3ub(232, 255, 0);  // Dark sky
    else
        glColor3ub(62, 72, 53);  // Day sky
    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glVertex2f(1745.612929552528, 590.891526649609);
    glVertex2f(1755.4282644439782, 590.5847974342511);
    glVertex2f(1755.4282644439782, 575.2483366663613);
    glVertex2f(1745.612929552528, 575.2483366663613);
    glEnd();
    glPopMatrix();
}
//D9
void building2D()
{
    glColor3ub(247, 171, 66);
    glBegin(GL_POLYGON);
    glVertex2f(1644.0461328245904, 730.0599165783477);
    glVertex2f(1721.721086594705, 730.5453850394108);
    glVertex2f(1724.1694038679316, 545.6985000263609);
    glVertex2f(1644.653391885514, 519.7991410272093);
    glVertex2f(1644.0461328245904, 730.0599165783477);
    glEnd();

     glColor3ub(151, 105, 43);
    glBegin(GL_POLYGON);
    glVertex2f(1721.721086594705, 730.5453850394108);
    glVertex2f(1724.1694038679316, 545.6985000263609);
    glVertex2f(1788.7157342214286, 548.0092436796518);
    glVertex2f(1788.2302657603652, 730.0599165783477);
     glVertex2f(1721.721086594705, 730.5453850394108);
    glEnd();
}
void building2winD(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    if (isNight)
        glColor3ub(232, 255, 0);  // Dark sky
    else
        glColor3ub(62, 72, 53);  // Day sky
    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glVertex2f(1689.7257251666185, 666.6921594584261);
    glVertex2f(1702.3023481521761, 666.6921594584261);
    glVertex2f(1702.2509106143198, 645.8168503789252);
    glVertex2f(1689.6801681645327, 646.073872814416);
    glVertex2f(1689.7257251666185, 666.6921594584261);
    glEnd();
    glPopMatrix();
}
//D11
void bush1D()
{
     glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(34, 85, 34);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 73.19;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x +1590.9521871861896, y + 507.8551864426779);
    }
    glEnd();
}
//D10
void building3D()
{
    glColor3ub(247, 171, 66);
    glBegin(GL_POLYGON);
    glVertex2f(1589.1710534884503, 694.811423980415);
    glVertex2f(1589.9435542081349, 542.7871287166124);
    glVertex2f(1539.1993164584776, 545.0592587651045);
    glVertex2f(1540.5422165454638, 694.9277058374737);
    glVertex2f(1589.1710534884503, 694.811423980415);
    glEnd();

     glColor3ub(151, 105, 43);
    glBegin(GL_POLYGON);
    glVertex2f(1589.1710534884503, 694.811423980415);
    glVertex2f(1589.9435542081349, 542.7871287166124);
    glVertex2f(1642.9599220062844, 543.9231937408584);
    glVertex2f(1642.7811231439264, 694.3012881624217);
    glVertex2f(1589.1710534884503, 694.811423980415);
    glEnd();
}

void building3winD(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    if (isNight)
        glColor3ub(232, 255, 0);  // Dark sky
    else
        glColor3ub(62, 72, 53);  // Day sky
    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glVertex2f(1560.8102242985608, 677.8650034880872);
    glVertex2f(1572.6684790613413, 677.6931447234091);
    glVertex2f(1572.4966202966634, 666.0067487253075);
    glVertex2f(1560.466506769205, 666.0067487253075);
    glVertex2f(1560.8102242985608, 677.8650034880872);
    glEnd();
    glPopMatrix();
}

//D12
void cloudD(float x, float y, float z)
{
     glPushMatrix();

    glTranslatef(x,y,z);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        if (isNight)
        glColor3ub(180, 180, 200);
    else
        glColor3ub(230, 247, 249);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 36.188;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x +100, y + 850);
    }
    glEnd();

     glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        if (isNight)
        glColor3ub(180, 180, 200);
    else
        glColor3ub(230, 247, 249);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 54.389;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x +175.4764697827818, y + 862.5580932744411);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        if (isNight)
        glColor3ub(180, 180, 200);
    else
        glColor3ub(230, 247, 249);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 37.263;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x +240.3526658669513, y + 844.4997706530764);
    }
    glEnd();

    glPopMatrix();
}
//D13, D14
void sunD()
{
     glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        if (isNight)
            glColor3ub(252, 253, 225 ); // White moon
        else
            glColor3ub(237, 244, 5);   // Yellow sun
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 71.46;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x +1116.569, y + 851.539);
    }
    glEnd();
}
//D15
void railLineD()
{
    glLineWidth(5);
     glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(0,520.397);
    glVertex2f(1900,529.558);

    glEnd();

}
//D16
void shipD()
{
    glColor3ub(155, 55, 23);
    glBegin(GL_POLYGON);
    glVertex2f(813.010865367539, 136.6557965998779);
    glVertex2f(1301.5550420590237, 133.9060169937348);
    glVertex2f(1290.7279633405656, 105.3829119883058);
    glVertex2f(822.3361357681424, 105.6396633183591);
    glVertex2f(813.010865367539, 136.6557965998779);
    glEnd();

     glColor3ub(89, 87, 115);
    glBegin(GL_POLYGON);
    glVertex2f(813.010865367539, 136.6557965998779);
    glVertex2f(1301.5550420590237, 133.9060169937348);
    glVertex2f(1310.2514888743106, 150.560082390695);
    glVertex2f(1322.5882363156186, 167.3829198106586);
    glVertex2f(1337.406450671036, 181.4032840208142);
    glVertex2f(1354.717447777797, 192.5679819247876);
    glVertex2f(1192.480451015334, 193.4845751268352);
    glVertex2f(1158.912989393981, 177.1311963882301);

    glVertex2f(799.2619673368218, 176.069304287929);
    glVertex2f(813.010865367539, 136.6557965998779);
    glEnd();

    glColor3ub(204, 195, 181);
    glBegin(GL_POLYGON);
    glVertex2f(915.4889600525066, 194.8338259034296);
    glVertex2f(1354.717447777797, 192.5679819247876);
    glVertex2f(1373.435542142705, 211.3378598149307);
    glVertex2f(879.1021476124525, 211.5111149384527);
    glVertex2f(868.496485354238, 177.2112322749999);
    glVertex2f(911.6522723990437, 176.5412151917475);
    glEnd();

    glColor3ub(155, 55, 23);
    glBegin(GL_POLYGON);
    glVertex2f(1159.2624814416797, 176.1300517473163);
    glVertex2f(1192.480451015334, 193.4845751268352);
    glVertex2f(915.4889600525066, 194.8338259034296);
    glVertex2f(911.6522723990437, 176.5412151917475);
    glVertex2f(1159.2624814416797, 176.1300517473163);
    glEnd();

    glColor3ub(225, 225, 192);
    glBegin(GL_POLYGON);
    glVertex2f(928.0598564759312, 212.2275497002559);
    glVertex2f(937.4745926016113, 249.3634533071017);
    glVertex2f(1200, 250);
    glVertex2f(1220.8984302199613, 211.8218845310452);
    glVertex2f(928.0598564759312, 212.2275497002559);
    glEnd();

    glColor3ub(89, 87, 115);
    glBegin(GL_POLYGON);
    glVertex2f(1080, 300);
    glVertex2f(1131.30804729733, 300.14570898349);
    glVertex2f(1139.4178567803326, 249.4593997147287);
    glVertex2f(1081.6593755751146, 249.1698487679239);
    glEnd();

    glColor3ub(89, 87, 115);
    glBegin(GL_POLYGON);
    glVertex2f(992.5722552835526, 250.348383565225);
    glVertex2f(1055.1039287410904, 249.6708949346035);
    glVertex2f(1044.080913074137, 300.2765577692478);
    glVertex2f(993.2247271561477, 299.7755116025682);
    glEnd();

    glColor3ub(50, 50, 48);
    glBegin(GL_POLYGON);
    glVertex2f(1155.7210246935829, 228.9277250655231);
    glVertex2f(1156.2718274901222, 212.1282397710766);
    glVertex2f(1220.8984302199613, 211.8218845310452);
    glVertex2f(1212.1969283030232, 228.8651127713266);
    glEnd();
}
void shipWinD(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    if (isNight)
        glColor3ub(232, 255, 0);  // Dark sky
    else
        glColor3ub(62, 72, 53);  // Day sky
    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glVertex2f(1124.1741142777948, 213.1736727269599);
    glVertex2f(1139.389586838905, 213.1736727269599);
    glVertex2f(1139.3222685837256, 230.1528941428578);
    glVertex2f(1123.4372472965326, 230.4982206925794);
    glEnd();
    glPopMatrix();
}
//D17
void treeD(float x, float y, float z)
{
     glPushMatrix();

    glTranslatef(x,y,z);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(43, 115, 26);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 51.76;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x +1013.072, y + 521.71);
    }
    glEnd();

     glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(43, 115, 26);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 50;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x +1000, y + 500);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(43, 115, 26);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 51.57;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x +1022.02, y + 500.66);
    }
    glEnd();

    glLineWidth(8);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(1013.0721341476412, 521.7085121818801);
    glVertex2f(1012.6188084131871, 409.6149795440739);
    glEnd();

    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(985.1792483347281, 491.7105029113909);
    glVertex2f(1007.2830446393008, 474.8695152507654);
    glEnd();

     glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(1018.8612236559818, 474.8695152507654);
    glVertex2f(1043.0701434181328, 491.7105029113909);
    glEnd();


    glPopMatrix();
}

//D18
void beachSeatD(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glColor3ub(101, 86, 80);
    glBegin(GL_POLYGON);
    glVertex2f(102.5111162857733, 381.8469406902606);
    glVertex2f(114.5885192104503, 386.968217629384);
    glVertex2f(127.6327483035699, 389.7676457048432);
    glVertex2f(139.1060167051698, 392.0676288552773);
    glVertex2f(151.5040935522527, 391.9834187453934);
    glVertex2f(139.1751637490918, 386.2217054685069);
    glVertex2f(125.2467506958835, 382.5737877640955);
    glVertex2f(112.9764820537715, 381.2472722352187);
    glVertex2f(102.5111162857733, 381.8469406902606);
    glEnd();

    glColor3ub(43, 41, 191);
    glBegin(GL_POLYGON);
    glVertex2f(102.5111162857733, 381.8469406902606);
    glVertex2f(108.8183910698938, 397.8920272375662);
    glVertex2f(122.8781526610648, 407.1147288734074);
    glVertex2f(141.3159172007889, 404.306012658137);
    glVertex2f(151.5040935522527, 391.9834187453934);
    glVertex2f(102.5111162857733, 381.8469406902606);
    glEnd();

    glLineWidth(3);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(134.4743327521794, 352.5665302655325);
    glVertex2f(126.447759354038, 389.4737416226809);
    glEnd();

     glLineWidth(2.5);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(137.2742090353612, 380.5611211285572);
    glVertex2f(144.8169490976954, 347.9619985293708);
    glEnd();

    glLineWidth(2.5);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(155.6172535089776, 381.3873843931344);
    glVertex2f(163.6855695079691, 348.6571582286966);
    glEnd();

    glLineWidth(2.5);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(139.1,369.89);
    glVertex2f(137.9646606329117, 355.1122125795792);
    glEnd();

    glLineWidth(2.5);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(142.7275465815715, 355.9384758441555);
    glVertex2f(149.5029053511055, 354.4512019679164);
    glEnd();

    glLineWidth(2.5);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(161.2358437081033, 357.0952444145636);
    glVertex2f(164.8714020722435, 355.4427178854091);
    glEnd();

     glColor3ub(43, 41, 191);
    glBegin(GL_POLYGON);
    glVertex2f(138.7591288607127, 375.8676950308785);
    glVertex2f(156.2374298723347, 377.5559400149554);
    glVertex2f(164.8714020722435, 355.4427178854091);
    glVertex2f(149.5029053511055, 354.4512019679164);

    glEnd();


    glPopMatrix();
}
//D19
void boatD()
{
    glColor3ub(54, 54, 49);
    glBegin(GL_POLYGON);
    glVertex2f(451.4097389506023, 99.7643893674091);
    glVertex2f(600, 100);
    glVertex2f(637.9911244052324, 150.5722170918528);
    glVertex2f(597.5083283073392, 137.0796134888246);
    glVertex2f(583.5334124868825, 136.2513846488444);
    glVertex2f(569.8473507695666, 135.2645577968854);
    glVertex2f(545.6464913928265, 134.2335370727844);
    glVertex2f(493.1521930525271, 132.6523835083177);
    glVertex2f(442.2390482766946, 132.6523835083177);
    glVertex2f(451.4097389506023, 99.7643893674091);
    glEnd();

     glColor3ub(246, 246, 235);
    glBegin(GL_POLYGON);
    glVertex2f(545.6464913928265, 134.2335370727844);
    glVertex2f(569.8473507695666, 135.2645577968854);
    glVertex2f(568.9281068826015, 156.6667360451695);
    glVertex2f(543.7491071154664, 157.3183791139991);
    glEnd();


    glColor3ub(132, 106, 241);
    glBegin(GL_POLYGON);
    glVertex2f(132.748161613176, 312.7846186894648);
    glVertex2f(140.7528773882249, 353.9685818714021);
    glVertex2f(161.3402479362114, 382.4741718609201);
    glVertex2f(194.5967695906513, 415.7306935153577);
    glVertex2f(234.9796887424711, 433.9425982308831);
    glVertex2f(283.2808273358242, 437.1098860074962);
    glVertex2f(331.7705405050651, 416.3933277008236);
    glVertex2f(308.6191295487308, 470.3664076619338);
    glVertex2f(261.1098128995309, 502.8311073722182);
    glVertex2f(215.9759620827912, 509.1656829254444);

    glVertex2f(171.6339332102047, 499.6638195956051);
    glVertex2f(139.1692334999182, 476.70098321516);
    glVertex2f(116.2063971194716, 445.0281054490289);
    glVertex2f(100, 400);
    glVertex2f(105.120889901325, 357.1358696480152);
    glEnd();

     glColor3ub(101, 86, 80);
    glBegin(GL_POLYGON);
    glVertex2f(132.748161613176, 312.7846186894648);
    glVertex2f(171.3731474250149, 324.8235714454419);
    glVertex2f(212.2202227065193, 340.807209599073);
    glVertex2f(258.3951773725678, 363.8946869320957);
    glVertex2f(301.0182124489202, 390.5340838548141);
    glVertex2f(331.7705405050651, 416.3933277008236);
    glVertex2f(285.922554192712, 421.6133802646523);
    glVertex2f(244.1874990137837, 417.1734807775326);
    glVertex2f(200, 400);
    glVertex2f(166.0452680404709, 374.550445701183);

    glVertex2f(150, 350);
    glVertex2f(132.748161613176, 312.7846186894648);
    glEnd();

     glLineWidth(3);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(311.6739712180083, 274.2087172922769);
    glVertex2f(331.7705405050651, 416.3933277008236);
    glEnd();

    glLineWidth(3);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(311.6739712180083, 274.2087172922769);
    glVertex2f(285.922554192712, 421.6133802646523);
    glEnd();

    glLineWidth(3);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(311.6739712180083, 274.2087172922769);
    glVertex2f(244.1874990137837, 417.1734807775326);
    glEnd();

    glLineWidth(3);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(311.6739712180083, 274.2087172922769);
    glVertex2f(166.0452680404709, 374.550445701183);
    glEnd();

    glLineWidth(3);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(311.6739712180083, 274.2087172922769);
    glVertex2f(132.748161613176, 312.7846186894648);
    glEnd();

    glLineWidth(3);
    glColor3ub(175, 104, 51);
    glBegin(GL_LINES);
    glVertex2f(311.6739712180083, 274.2087172922769);
    glVertex2f(442.2390482766946, 132.6523835083177);
    glEnd();

}
//D21
void stoneD(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glColor3ub(126, 126, 125);
    glBegin(GL_POLYGON);
    glVertex2f(563.8790766335122, 445.0654073777664);
    glVertex2f(560.7062387593596, 436.81602890497);
    glVertex2f(555.3124143733002, 408.5777718250133);
    glVertex2f(569.2729010195718, 401.597528501878);
    glVertex2f(599.0975770366067, 405.0876501634456);
    glVertex2f(606.712387934573, 411.4333259117505);
    glVertex2f(603.8568338478357, 440.9407181413682);
    glVertex2f(586.0889417525808, 458.0740426617913);
    glVertex2f(563.8790766335122, 445.0654073777664);
    glEnd();

    glColor3ub(176, 176, 175);
    glBegin(GL_POLYGON);
    glVertex2f(563.8790766335122, 445.0654073777664);
    glVertex2f(560.7062387593596, 436.81602890497);
    glVertex2f(577.2049957049534, 442.5271370784444);
    glVertex2f(595.6074553750387, 431.7394883063261);
    glVertex2f(603.8568338478357, 440.9407181413682);
    glVertex2f(586.0889417525808, 458.0740426617913);
    glEnd();

    glLineWidth(0.5);
    glColor3ub(110, 111, 106);
    glBegin(GL_LINES);
    glVertex2f(577.2049957049534, 442.5271370784444);
    glVertex2f(569.2729010195718, 401.597528501878);
    glEnd();

    glLineWidth(0.5);
    glColor3ub(110, 111, 106);
    glBegin(GL_LINES);
    glVertex2f(595.6074553750387, 431.7394883063261);
    glVertex2f(599.0975770366067, 405.0876501634456);
    glEnd();


    glPopMatrix();
}
//D22
void bush2D(float x, float y, float z)
{
    glPushMatrix();
     glTranslatef(x,y,z);
     glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        glColor3ub(3, 65, 15);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 400;
        float r = 47.71;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x +1385.14, y + 310.205);
    }
    glEnd();
    glPopMatrix();
}


void drawDrops()
{
    glColor3f(0.2f, 0.4f, 1.0f);
    for (int i = 0; i < dropCount; ++i) {
        glBegin(GL_LINES);
        glVertex2f(dropX[i], dropY[i]);
        glVertex2f(dropX[i], dropY[i] - 20); // Raindrop length in your scale
        glEnd();
    }
}

void drawCircle(float x, float y, float radius, float alpha)
{
    int segments = 32;
    glColor4f(0.5f, 0.7f, 1.0f, alpha);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; ++i) {
        float angle = 2.0f * 3.1416f * i / segments;
        glVertex2f(x + cosf(angle) * radius, y + sinf(angle) * radius);
    }
    glEnd();
}

void drawBubbles()
{
    for (int i = 0; i < bubbleCount; ++i) {
        if (bubbleActive[i]) {
            drawCircle(bubbleX[i], bubbleY[i], bubbleRadius[i], bubbleAlpha[i]);
        }
    }
}
//A10
void updated(int value)
{
    if (rainActive) { // Only when rain is active

        // Add new drops randomly
        if (dropCount < MAX_DROPS && (rand() % 5) == 0) {
            dropX[dropCount] = (rand() % 1900); // 0 to 1900
            dropY[dropCount] = 1000.0f; // Start from the top
            dropSpeed[dropCount] = 4.0f + (rand() % 5); // Random speed
            dropCount++;
        }

        // Update drops
        for (int i = 0; i < dropCount; ) {
            dropY[i] -= dropSpeed[i];
            if (dropY[i] <= groundY + 10) {
                if (bubbleCount < MAX_BUBBLES) {
                    bubbleX[bubbleCount] = dropX[i];
                    bubbleY[bubbleCount] = groundY + 10;
                    bubbleRadius[bubbleCount] = 5.0f;
                    bubbleAlpha[bubbleCount] = 1.0f;
                    bubbleActive[bubbleCount] = 1;
                    bubbleCount++;
                }

                dropX[i] = dropX[dropCount - 1];
                dropY[i] = dropY[dropCount - 1];
                dropSpeed[i] = dropSpeed[dropCount - 1];
                dropCount--;
            } else {
                i++;
            }
        }

        // Update bubbles
        for (int i = 0; i < bubbleCount; ++i) {
            if (bubbleActive[i]) {
                bubbleRadius[i] += 1.0f;
                bubbleAlpha[i] -= 0.02f;
                if (bubbleAlpha[i] <= 0.0f) {
                    bubbleActive[i] = 0;
                }
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, updated, 0); // ~60 FPS
}

// Bird Drawing
void polygon(vector<pair<float, float>> coord, RGB rgb = {0, 0, 0}, float Tx = 0, float Ty = 0, float s = 1) {
    glColor3ub(rgb.red, rgb.green, rgb.blue);
    glBegin(GL_POLYGON);
    for (int i = 0; i < coord.size(); i++)
        glVertex2d(Tx + s * coord[i].first, Ty + s * coord[i].second);
    glEnd();
}

void bird(float Tx, float Ty, float direction, float birdWingY, RGB rgb = {0, 0, 0}, float s = 1) {
    polygon({
        {28.65 * direction, 2.99}, {31.98 * direction, 1.74}, {31.6 * direction, 0.23},
        {31.93 * direction, -1.29}, {30.43 * direction, -0.38}, {28.77 * direction, -1.12},
        {24.29 * direction, -4.59}, {16.47 * direction, -5.28}, {10.7 * direction, -4.96},
        {2.95 * direction, -10.29}, {8.55 * direction, -3.22}, {0.18 * direction, 1.29},
        {9.57 * direction, -0.31}, {11.02 * direction, 0.27}, {22.82 * direction, 1.86},
        {28.65 * direction, 2.99}
    }, rgb, Tx, Ty, s);

    polygon({
        {22.82 * direction, birdWingY * 1.86}, {23.38 * direction, birdWingY * 8.57},
        {9.98 * direction, birdWingY * 25.45}, {11.02 * direction, birdWingY * 0.27}
    }, rgb, Tx, Ty, s);
}

// Bird Animation
void birdAnimation() {
    birdXd += 4 * birdDirection;
    birdWingY += 0.5;
    if (birdWingY > 1) birdWingY = -1;
    if (birdDirection == 1 && birdXd > 2200)
        birdXd = -500;  // Re-enter from left when flying right

    if (birdDirection == -1 && birdXd < -500)
        birdXd = 2200;  // Re-enter from right when flying left
}

// Bird Frame Control
void birdFrameUpdate() {
    float frameTime = 1000 / 60.0, currentTime = GetTickCount();
    if (currentTime - lastFrameTime >= frameTime) {
        lastFrameTime = currentTime;
        birdAnimation();
    }
    glutPostRedisplay();
}

//D24
void waveD(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(246, 248, 250);
	glVertex2f(1820, 20);
	glVertex2f(1860, 20);
    glEnd();
    glPopMatrix();
}


//D25
void lightD()
{
    if (!lightOn) return;
    glBegin(GL_POLYGON);
    glColor4f(232, 255, 0,0.7);
	glVertex2f(1415.9929409981783, 748.9136734498842);
	glVertex2f(1199.848283389232, 730.0656161056456);
	glVertex2f(1200.152284314139, 770.8017400431936);
	glEnd();

	glBegin(GL_POLYGON);
    glColor4f(232, 255, 0,0.7);
	glVertex2f(1402.1675061420829, 742.5749638056484);
	glVertex2f(1593.1164033486386, 726.3139719071834);
	glVertex2f(1591.2918553784255, 768.8867578788237);
	glEnd();
}
//A7
void blinkLight(int value) {
    lightOn = !lightOn;
    glutPostRedisplay();
    glutTimerFunc(1000, blinkLight, 0);
}
//A1
void updateTrain(int value) {
    _moveTrain += trainSpeed;
    if (_moveTrain > 1900.0f) {
        _moveTrain = -1800.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateTrain, 0);
}
//A2
void updateboat(int value) {
    _moveBoat += boatSpeed;
    if (_moveBoat > 1800.0f) {
        _moveBoat = -1800.0f;
    }
    if (_moveBoat < -1800.0f) {
        _moveBoat = 1800.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateboat, 0);
}
//A3
void updateShip(int value) {
    _moveShip += shipSpeed;
    if (_moveShip > 1400.0f) {
        _moveShip = -1400.0f;
    }

    if (_moveShip < -1400.0f) {
        _moveShip = 1400.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateShip, 0);
}
//A4
void updateCloud2(int value) {
    _moveCloud += -0.2 * cloudDirection;

    if (_moveCloud > 1200.0f) {
        _moveCloud = -1200.0f;
    }
    if (_moveCloud < -1200.0f) {
        _moveCloud = 1200.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(20, updateCloud2, 0);
}
//A5
void updateCloud1(int value) {
    _moveCloud2 += 0.5;

    if (_moveCloud2 > 1200.0f) {
        _moveCloud2 = -1200.0f;
    }
    if (_moveCloud2 < -1200.0f) {
        _moveCloud2 = 1200.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(20, updateCloud1, 0);
}
//A6
void updateWaveD(int value) {
    _moveWave += 1.5;

    if (_moveWave > 300.0f) {
        _moveWave = -300.0f;
    }
    if (_moveWave < -300.0f) {
        _moveWave = 300.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(20, updateWaveD, 0);
}




void init()
{
    srand((unsigned int)time(0));
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void displayd() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Set background color to black

    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer (background)


    glLoadIdentity();  // Reset the modelview matrix
    skyD();

    sunD();

    // Birds
    bird(birdXd - 10, birdYd - -50, birdDirection, birdWingY, {0, 0, 0}, 1.2);
    bird(birdXd - 20, birdYd - -10, birdDirection, -birdWingY, {0, 0, 0}, 0.8);
    bird(birdXd - 30, birdYd - 30, birdDirection, birdWingY, {0, 0, 0}, 0.6);
    bird(birdXd - 40, birdYd - 70, birdDirection, birdWingY, {0, 0, 0}, 0.4);
    bird(birdXd - 50, birdYd - 110, birdDirection, birdWingY, {0, 0, 0}, 0.2);

     glPushMatrix();
    glTranslatef(_moveCloud2,0,0);
    cloudD(339.032,36.587,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_moveCloud,0,0);
    cloudD(0,0,0);
    cloudD(1551.998,-25,0);
    glPopMatrix();
    cloudD(20,15,0);


    seaD();

    glPushMatrix();
    glTranslatef(_moveWave,0,0);
    waveD(0,0,0);
    waveD(-500,100,0);
    waveD(-70,0,0);
    waveD(-0,80,0);
    waveD(-145,80,0);
    waveD(-145,160,0);
    waveD(-0,160,0);
    waveD(-70,80,0);
    waveD(-220,230,0);
    waveD(-300,300,0);
    waveD(-380,320,0);
    waveD(-460,155,0);
    waveD(-560,214,0);
    waveD(-600,80,0);
    waveD(-680,230,0);
    waveD(-770,0,0);
    waveD(-770,80,0);
    waveD(-850,155,0);
    waveD(-888,277,0);
    waveD(-989,130,0);
    waveD(-920,222,0);
    waveD(-444,340,0);
    waveD(-666,265,0);
    waveD(-1050,160,0);
    waveD(-1100,80,0);
    waveD(-1180,230,0);
    waveD(-1260,300,0);
    waveD(-1320,320,0);
    waveD(-1400,155,0);
    waveD(-1560,214,0);
    waveD(-1600,80,0);
    waveD(-1680,230,0);
    waveD(-1770,0,0);
    waveD(-1770,80,0);
    waveD(-1850,155,0);
    waveD(-1888,277,0);
    waveD(-1989,130,0);
    waveD(-1920,222,0);
    waveD(-1444,340,0);
    waveD(-1666,265,0);
    glPopMatrix();



    sandD();
    upperMountainD();

    glPushMatrix();
    glTranslatef(_moveTrain,0,0);
    trainD();
    trainDoorD(0,0,0);
    trainDoorD(-26.796,0,0);
    trainDoorD(-196.33,0,0);
    trainDoorD(-222.969,0,0);
    trainDoorD(-387.316,0,0);
    trainDoorD(-413.32,0,0);
    trainWindowD(0,0,0);
    trainWindowD(-112.9222,0,0);
    trainWindowD(-154.431,0,0);
    trainWindowD(-315.974,0,0);
    trainWindowD(-357.483,0,0);
    trainWindowD(-496.445,0,0);
    trainWheelsD(0,0,0);
    trainWheelsD(-20.63,0,0);
    trainWheelsD(-41.26,0,0);
    trainWheelsD(-268.545,0,0);
    trainWheelsD(-289.175,0,0);
    trainWheelsD(-462.192,0,0);
    trainWheelsD(-482.822,0,0);
    glPopMatrix();

    building3D();
    building3winD(0,0,0);
    building3winD(48.71,0,0);
    building3winD(0,-27.74,0);
    building3winD(48.71,-27.74,0);
    building3winD(0,-55.48,0);
    building3winD(48.71,-55.48,0);
    building3winD(0,-83.22,0);
    building3winD(48.71,-83.22,0);

    bush1D();
    grassD();
    stoneD(0,0,0);
    stoneD(225,15,0);
    stoneD(200,-10,0);
    stoneD(250,0,0);
    stoneD(-545.55,-60,0);
    stoneD(-510,-90,0);
    stoneD(-503,-130,0);
    stoneD(-540,-140,0);
    stoneD(-523,-170,0);

    railLineD();
    building2D();
    building2winD(0,0,0);
    building2winD(-27.43,0,0);
    building2winD(-27.43,41.06,0);
    building2winD(0,41.06,0);
    building2winD(0,-41.93,0);
    building2winD(-27.43,-41.93,0);
    building2winD(57.055,0,0);
    building2winD(57.055,43.41,0);

    building1D(0,0,0);
    lowerMountainD();
    bush2D(0,0,0);
    bush2D(80,0,0);
    bush2D(160,0,0);
    bush2D(220,0,0);
    bush2D(280,0,0);
    bush2D(360,0,0);
    bush2D(420,0,0);
    bush2D(480,0,0);
    bush2D(-80,0,0);
    bush2D(-160,0,0);
    bush2D(-220,0,0);
    bush2D(160,141.18,0);
    bush2D(220,141.18,0);
    bush2D(280,141.18,0);
    bush2D(360,141.18,0);
    bush2D(420,141.18,0);
    bush2D(480,141.18,0);

    treeD(340.79,60,0);
    lightHouseD();

    glPushMatrix();
    glTranslatef(_moveShip,0,0);
    shipD();
    shipWinD(0,0,0);
    shipWinD(-40.69,0,0);
    shipWinD(-81.38,0,0);
    shipWinD(-122.07,0,0);
    shipWinD(-162.76,0,0);
    glPopMatrix();


    treeD(0,0,0);
    treeD(-877.7,59.26,0);
    treeD(-946.94,75,0);
    building1D(-1375.066,-90,0);
    building1D(-1465.066,-100,0);

    beachSeatD(0,0,0);
    beachSeatD(50,0,0);
    beachSeatD(100,0,0);
    beachSeatD(150,0,0);
    beachSeatD(400,0,0);
    beachSeatD(450,0,0);
    beachSeatD(500,0,0);
    beachSeatD(800,0,0);
    beachSeatD(850,0,0);

    glPushMatrix();
    glTranslatef(_moveBoat,0,0);
    boatD();
    glPopMatrix();

    //rain
    drawDrops();
    drawBubbles();

    if(isNight)
    lightD();

    glutSwapBuffers();
    glFlush();

}



/* Main function: GLUT runs as a console application starting at main()  */

