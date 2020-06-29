
// LIBERARIES
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include <windows.h>
void usleep(__int64 usec) 
{ 
    HANDLE timer; 
    LARGE_INTEGER ft; 

    ft.QuadPart = -(10*usec); // Convert to 100 nanosecond interval, negative value indicates relative time

    timer = CreateWaitableTimer(NULL, TRUE, NULL); 
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0); 
    WaitForSingleObject(timer, INFINITE); 
    CloseHandle(timer); 
}

void clrscr()
{
  system("cls");
}

using namespace std;

	// :::ALL GAME EFFECTING VARIABLES:::

    //TILE SET VARIABLES
// Solid TileSet variables
string _floor = "@";
string wall = "[";
string roof = "∞";
string plPassWall = "/";
string spikes = "#";

// Spike properties
int spikeHitDelay = 0;
int spikeMaxHitDelay = 25;

// NotSolid TileSet variables
string _empty = " ";
string door = "Π";
string shop = "§";
string powInd = _empty;
string entrRoom = "o";
string grave = "↑";
const int totalNotSolid = 6;
string notSolid[totalNotSolid] = { _empty, door, shop, powInd, entrRoom, grave };

// Grave variables
const int totalGravesUsed = 3;
int maxEnemyRegenDelay = 500;
int enemyRegenDelay[totalGravesUsed];
int gravePosW[totalGravesUsed];
int gravePosH[totalGravesUsed];
//Define position in notSolid function
int grave_eType = 1;

// TileSet Settlement Vars
bool isTileDone = false;

// Power Indicator properties
string slowPowGInd = "S";
int emerSlowPow = 5;
string regenerateGInd = "+";
int emerRegenerate = 6;

  //ZERO POSITION (Void for dead entities)
string zeroShow = roof;
const int zeroPosH = 0;
const int zeroPosW = 2;

 // LEVEL VARIABLES
int lvStart = 0;
int lv = lvStart;
const int maxLv = 10;

//Connected Rooms Variables
bool roomSet = false;
const int maxNoOfRooms= 10;
int maxRooms[maxLv] = { 0,0,0,0,0,0,1,2,2,2 };
int initRoom[maxLv] = { 0,0,0,0,0,0,0,1,0,0 };
int room[maxLv] = { 0,0,0,0,0,0,0,1,0,0 };
bool isRoom_eSet[maxNoOfRooms];
int prevRoom;
int doorRoom[maxLv] = { 0,0,0,0,0,0,0,1,0,2 };
int shopRoom[maxLv] = { 0,0,0,0,0,0,1,1,2,0 };
int wallEntr_r = 51;
int wallEntr_l = 1;
int entrW_r = wallEntr_r - 1;
int entrW_l = wallEntr_l + 1;
int entrH;
int entrW;

//Starting from initial level values
int initScore = 0;
int initGold = 0;
int initStBullet = 20;
int initOtherBullet = 0;
int initSlowPow = 6;
int initRegen = 0;
int initNuke = 0;

//Door positions
int doorlv_w[maxLv] = { 27,27,37,27,6,4,8,20,6,43 };
int doorlv_h[maxLv] = { 18,14,6,9,2,13,12,3,5,15 };

//Shop positions
int shoplv_w[maxLv] = { zeroPosW, zeroPosW, zeroPosW, zeroPosW,19,zeroPosW,7,32,34,zeroPosW };
int shoplv_h[maxLv] = { zeroPosH,zeroPosH,zeroPosH,zeroPosH,2,zeroPosH,2,3,13,zeroPosH };

bool lvSet = true;

// INITIALIZE VALUES FOR NEW GAME

// -GAME FRAME RUNNER SPEED FACTOR-
 // To set speed and stability of Frames
 // More number, less speed, more stability.
 // 1 second = 100000 units of FrameDelay
int defaultFrameDelay = 30000;
int FrameDelay = defaultFrameDelay;	
// Default: 30000

    //PLAYER VARIABLES
    
	// Default Player Display and Position
string plDis = "¡";
string pl = plDis;
int plH = 0;
int plW = 0;

 // Player HP
int hpSet = 15;
int hp = hpSet;
int hpTempForLv = hpSet;

  // Player Shop Related
int gold = 0;

 // Player Score Related
int score = 0;

	// Player Jump
bool jump = false;
int jumpTime = 0;
int setJumpTime = 4;
bool jumpForce = false;
int jumpDelay = 0;
int maxJumpDelay = 1;
int jumpMove = 2;

  // Player Gravity
int gravityDelay = 0;
int maxGravityDelay = maxJumpDelay;

	// Player Direction 
string dir_hor = "r";
string dir_ver = "u";

  // Player notSolid
bool pl_notSolid = false;
bool pl_notSolid_u = false;
bool pl_notSolid_d = false;
bool pl_notSolid_r = false;
bool pl_notSolid_l = false;
bool pl_notSolid_sh_r[20];
bool pl_notSolid_sh_l[20];

  // Player _emptyAt
bool emptyAt = false;
bool emptyAt_r = false;
bool emptyAt_l = false;
bool emptyAt_u = false;
bool emptyAt_d = false;
bool emptyAt_forE = true;

  // Player Stabbing
int stabCollect = 0;
int maxStabCollect = 2;
int eHpLoss_jumpStab = 5; //Jump Assassination Health Loss to Enemy

	// Player Shoot
string shDir[20];
const int plShTypes = 4;
bool shoot[20];
string plSh[plShTypes] = { "-","^","=","'"};
int plShW[20];
int plShH[20];
int shCount = 0;
bool shootEff[20];
string plShEff[plShTypes] = { "*", plSh[1] ,"0",";" };
int eHpLoss[plShTypes] = { 1,5,15,10 };
bool is_plSh[plShTypes] = { true, false, false, false };
int plShMaxValForType[plShTypes] = { 60,30,10,10 };
int plShValForType[plShTypes] = { 0,0,0,0 };
int plShVal = plShValForType[0];
int plShDuringDelay[20];
int plShMaxDuringDelay = 1000;
int plShDuringDelaySub[plShTypes] = {500, 1000, 400, 500};
int plShAgainDelay = 0;
int plShMaxAgainDelay = 1000;
int plShAgainDelaySub[plShTypes] = {250,200,20,100};

// Player Vulnerable
double maxVul = 4;
double plVul = maxVul;
double VulSub = 0.05;
string vulShow = notSolid[0];
bool plDamage = false;
int eDamageWhenClose = 0;

// Player Powers
const int totalPow = 4;

// Player Power Type: SlowPow
int slowFactor = 4;
int slowPow = FrameDelay * slowFactor;
int slowPowDelay = 0;
int slowPowSub_wait = 0;
int slowPowSub_waitMax = slowFactor;
bool isSlowPow = false;
bool selectedSlowPow = true;

// Player Power Type: Regeneration
int regenFactor = 0;
int maxRegenFactor = 20;
int regenerate = 1;
int regenCost = 0;
int regenCostMax = 3;
int regenDelay = 0;
bool isRegenerate = false;
bool selectedRegenerate = false;

// Player Power Type: Invulnerability
bool isInvulnerable = false;
bool selectedInvulnerable = false;

// Player Power Type: Nuke
string nukeParticle = "©";
string nukeDamageFactor = plSh[3];
int nukeCount = 0;
int nukeEffDelay = 0;
int maxNukeEffDelay = 10;
bool isNuke = false;
bool selectedNuke = false;

    //SHOP_PLACE VARIABLES
int slowPow_GetForGold = 3;
int slowPow_RequireGold = 10;
int regenerate_GetForGold = 3;
int regenerate_RequireGold = 10;
int invulnerable_GetForGold = 3;
int invulnerable_RequireGold = 2;
int nuke_GetForGold = 1;
int nuke_RequireGold = 50;
int plShType_GetForGold[plShTypes] = { 6,3,1,2 };
int plShType_RequireGold[plShTypes] = { 6,10,5,8 };

  	// ENEMY VARIABLES
  	
	// Variables depending upon TYPES
const int eTypes = 4;

   // Enemy Display
string enem[eTypes] = { "÷", "%", "$", "¢" };

   // Enemy Hp
int eHpSet[eTypes] = { 2, 5, 7, 12 };

	// Enemy Movement
int eMaxMoveTimesType[eTypes] = { 1,1,2,2 };
int eRateOfDelay[eTypes] = { 250, 100, 100, 100 };

  // Enemy ConstantMovement
int eRateOfConstDelay[eTypes] = { 0,100,0,0};
int isE_ConstMoveType[eTypes] = { false,true,false,false };

  // Enemy PlatformMovement
int eRateOfPlatDelay[eTypes] = { 100,0,0,0 };
int isE_PlatMoveType[eTypes] = { true,false,false,false };

	// Enemy Jump
int set_eJumpTimeType[eTypes] = { 2,3,1,1 };
int eJumpMoveType[eTypes] = { 1,1,1,1 };

	// Enemy Shoot
string eShType[eTypes] = { "°", "°", "•", "•" };
int eEyeRangeType[eTypes] = { 30,30,38,42 };
int eShAgainDelaySubType[eTypes] = { 6, 9, 12, 16 };
int eShDuringDelaySubType[eTypes] = { 400, 400, 200, 200 };
int hpLossType[eTypes] = { 2, 2, 3, 3};
int eDamageDelaySub[eTypes] = { 10,10,20,25 };

   // Enemy Loot
int e_giveVal_goldType[eTypes] = { 2,4,10,5 };
bool e_give_slowPowType[eTypes] = { true,true,false,true };
int e_giveVal_slowPowType[eTypes] = { 1,1,0,3 };
bool e_give_regenerateType[eTypes] = { false,false,true,true };
int e_giveVal_regenerateType[eTypes] = { 0,0,3,6 };
bool e_give_invulnerableType[eTypes] = { false,true,false,true };
int e_giveVal_invulnerableType[eTypes] = { 0,1,0,4 };
bool e_give_nukeType[eTypes] = { false,false,false,false };
int e_giveVal_nukeType[eTypes] = { 0,0,0,0 };
bool e_give_plShType[plShTypes][eTypes] = {
{true,true,false,false }, //eTypes for plShTypes = 0
{false,false,false,true }, //eTypes for plShTypes = 1
{false,false,true,false }, //eTypes for plShTypes = 2
{false,false,false,false }  //eTypes for plShTypes = 3
};
int e_giveVal_plShType[eTypes] = { 5,6,1,1 };

   // Variables depending upon NUMBERS/QUANTITY
const int eNumb = 20;

	// Enemy Hp
int eHp[eNumb];

	// Enemy Position
int eH[eNumb];
int eW[eNumb];

  // Enemy Display Delay
int eDisplayDelay = 0;
int max_eDisplayDelay = 10;
  
  // Enemy - Connected Rooms System Variables
int totalDefaultEnemies[maxNoOfRooms];
int temp_eW[maxNoOfRooms][eNumb];
int temp_eH[maxNoOfRooms][eNumb];
int temp_eHp[maxNoOfRooms][eNumb];
bool temp_eGraved[maxNoOfRooms][eNumb];

  // Enemy notSolid
bool e_notSolid = false;
bool e_notSolid_u[eNumb];
bool e_notSolid_d[eNumb];
bool e_notSolid_r[eNumb];
bool e_notSolid_l[eNumb];
bool e_notSolid_d_r[eNumb];
bool e_notSolid_d_l[eNumb];
bool e_notSolid_wall_r[eNumb];
bool e_notSolid_wall_l[eNumb];
bool e_notSolid_upAbove[eNumb];

  // Enemy _emptyAt
bool e_emptyAt = false;
bool e_emptyAt_r[eNumb];
bool e_emptyAt_l[eNumb];
bool e_emptyAt_u[eNumb];
bool e_emptyAt_d[eNumb];
bool e_emptyAt_d_r[eNumb];
bool e_emptyAt_d_l[eNumb];
bool e_emptyAt_wall_r[eNumb];
bool e_emptyAt_wall_l[eNumb];
bool e_emptyAt_upAbove[eNumb];
bool e_emptyAt_forP[eNumb];
bool e_emptyAt_r_forE[eNumb];
bool e_emptyAt_l_forE[eNumb];

  // Enemy Active/Inactive Status
bool eRun[eNumb];

	// Enemy Random Move Factor
int eRand[eNumb];

  // Enemy Grave Generation Factor
bool eFromGrave[eNumb];
bool eFromGraveDisplay[eNumb];

	// Enemy Direction
string eDir[eNumb];

	// Enemy Movement
int eMaxMoveTimesNumb[eNumb];
int eMoveTimes[eNumb];
int eDelay[eNumb];
int eDelaySub[eNumb];

  // Enemy ConstantMovement
bool isE_ConstMoveNumb[eNumb];
int eConstDelay[eNumb];
int eConstDelaySub[eNumb];
int constRand[eNumb];

  // Enemy PlatformMovement
bool isE_PlatMoveNumb[eNumb];
int ePlatDelay[eNumb];
int ePlatDelaySub[eNumb];
int platRand[eNumb];
bool doPatrol[eNumb];

	// Enemy Jump
int set_eJumpTimeNumb[eNumb];
int eJumpMoveNumb[eNumb];
bool eJump[eNumb];
int eJumpTime[eNumb];
int eJumpDelay[eNumb];
int eJumpForce[eNumb];

  // Enemy Gravity
int eGravityDelay[eNumb];

	// Enemy Shoot
const int eShLimit = 10;
bool eShoot[eNumb][eShLimit];
string eShDir[eNumb][eShLimit];
int eShW[eNumb][eShLimit];
int eShH[eNumb][eShLimit];
int eShAgainDelay[eNumb];
int eShDuringDelay[eNumb][eShLimit];
int eShAgainDelaySubNumb[eNumb];
int eShDuringDelaySubNumb[eNumb];
string eShNumb[eNumb];
int eEyeRangeNumb[eNumb];
int hpLossNumb[eNumb];

    //Enemy notSolid related to shoot
bool e_notSolid_sh_r[eNumb][eShLimit];
bool e_notSolid_sh_l[eNumb][eShLimit];

   // Enemy Loot
int e_giveVal_goldNumb[eNumb];
bool eLoot[eNumb];
bool e_give_slowPowNumb[eNumb];
int e_giveVal_slowPowNumb[eNumb];
bool e_give_regenerateNumb[eNumb];
int e_giveVal_regenerateNumb[eNumb];
bool e_give_invulnerableNumb[eNumb];
int e_giveVal_invulnerableNumb[eNumb];
bool e_give_nukeNumb[eNumb];
int e_giveVal_nukeNumb[eNumb];
bool e_give_plShNumb[plShTypes][eNumb];
int e_giveVal_plShNumb[eNumb];

  // NON-ARRAY Variables for Enemy
  
   // Enemy Hp
bool eHpSetted = false;

   // Enemy Movement
const int eMaxDelay = 1000;

  // Enemy ConstantMovement
const int eMaxConstDelay = 1000;

  // Enemy PlatformMovement
const int eMaxPlatDelay = 1000;

	// Enemy Shoot
const int eMaxShAgainDelay = 1000;
const int eMaxShDuringDelay = 1000;
const int eMaxDamageDelay = 1000;

 //UI VARIABLES
 
 //Start UI
 int UI_frameDelay = 20000;
 bool startUI = true;
 bool goBackToMenu = false;
 
 //Pointer for Menu
string menuPointer = "»";
  
  //Upper Line UI Component
string upperLine = roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof + roof;

  //Lower Line UI Component
string lowerLine = _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor + _floor;
 
   //BOTTOM BAR / STATUS BAR VARIABLES
   
   //Status Delay
int intendedStatDelayA = 3; //0 causes error
int intendedStatDelayB = 3; //0 causes error
int maxStatDelay = 80;
int statDelay = 0;
int stabShowDelay = 0;
int maxStabShowDelay = 20;

   //Status Display
string beginDiv = "(";
string endDiv = ")";
string statDiv = endDiv + _empty + beginDiv;
string valDiv = " ";
string lvInd = "Lv.";
string hpInd = "♥";
string plShInd;
string stabInd = "STAB";
string slowPowInd = "SlPw";
string regenerateInd = "Regn";
string invulnerableInd = "Invl";
string nukeInd = "Nuke";
string powActivInd = "ACTV";
string goldInd = "$";
string scoreInd = "Sc";

	// BUG TRACKING VARIABLES
bool checkBool = false;
int check0 = 0;
int check1 = 0;
int check2 = 0;
int check3 = 0;
int check4 = 0;
int check5 = 0;
int check6 = 0;
int check7 = 0;
int check8 = 0;
int check9 = 0;

	// :::END OF GAME EFFECTING VARIABLES:::

// :::WORTH MENTIONING FUNCTIONS:::
void loadFrame();
void setForNew();
void startUp();
void e_emptyAt_forE(int n);
void notSolidTileSet();
void plSet();
void eSet();
void eDisplay();
void eSetNumb(int n);
void eSetNumbFromType();
void defaultTileSet();
void customTileSet();
void roomCheck();
void plHpCheck();
void eGetLoot();
void plGetDamage();
void eGetDamage();
void emptyTileSet();
void keyboardCont();
void plDamageFactor();
void showPlShoot();
void plPropSet();
void plShEffect();
void bounderyLimit();
void plJump();
void plPow();
void eShNoMoveThrough();
void eMoveAIRunner();
void e_Jump();
void tileProperties();
void eShootAI();
void jumpForceFactor();
void pl_notSolidCheck();
void e_notSolidCheck();
void gravityFactor();
void emptyAtFactor();
void e_emptyAtFactor();
void plShoot();
void eShootSet();
// :::END OF WORTH MENTIONING FUNCTIONS:::

// include FrameRunner which further include all other files:
#include "FrameRunner.cpp"

int main()
{
	srand(time(NULL));
	FrameRunner();
	return 0;
}