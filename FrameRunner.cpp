
using namespace std;

bool run = true;
bool isRunAgain = false;
char input;

const int width = 54; 		// +1 for fixing bugs
// MAX limit is 54
const int height = 22;			// +1 for fixing bugs
// MAX limit is 22
string px[width][height];
	// Static game screen have: 53 width, 22 height.
	// So, total text pixels are 1166.

// include all other game files here
// (except Main.cpp)
#include "GameMenus.cpp"
#include "StartUI.cpp"
#include "PlayerActions.cpp"
#include "EnemyActions.cpp"
#include "PlayerSet.cpp"
#include "EnemySet.cpp"
#include "KeyboardCont.cpp"
#include "GameCont.cpp"
#include "DefaultTileSet.cpp"
#include "StatusBar.cpp"
#include "CustomTileSet.cpp"

/* 
   Layer0 is the least dominating and last Layer is the highest dominating i.e 
   higher dominating will over-ride lesser dominating one.

   MOST IMPORTANT: Cont_IMP1 = semi solid/entity changer which may disturb the 
   frames when on down

   Layer0 = basic empty framework Cont0 = basic input control Layer1 =
   non-solid framework Cont1 = non-solid limitations Layer2 = semi
   solid/entity framework Cont2 = semi solid/entity limitations Layer3 = solid 
   framework Cont3 = solid limitations

   MOST IMPORTANT: Cont_IMP2 = semi solid/entity limitations that depends on
   solid/non-solid framework

 */
 
 void loadFrame()
 {
 	// <<<<< Cont_IMP1 >>>>>
		roomCheck();      // From 'GameCont'
		plHpCheck();			// From 'GameCont'
		eGetLoot();      // From 'EnemyActions'
		plGetDamage();			// From 'PlayerActions'
		eGetDamage();			// From 'EnemyActions'

		// <<<<< Layer0 >>>>>
		emptyTileSet();			// From 'DefaultTileSet'

		// <<<<< Cont0 >>>>>
		keyboardCont();			// From 'KeyboardCont'

		// <<<<< Layer1 >>>>>
		notSolidTileSet();		// From 'CustomTileSet'

		// <<<<< Cont1 >>>>>


		// <<<<< Layer2 >>>>>
		plDamageFactor();		// From 'GameCont'
		showPlShoot();			// From 'PlayerActions'
		plSet();        //From 'PlayerSet'
		plPropSet();      //From 'PlayerSet'
		eSet();					// From 'EnemySet'
		eDisplay();      // From 'EnemySet'
		eSetNumbFromType();		// From 'EnemySet'
		plShEffect();			// From 'PlayerActions'

		// <<<<< Cont2 >>>>>
		bounderyLimit();		// From 'GameCont'
		plJump();				// From 'PlayerActions'
		plPow();    // From 'PlayerActions'
		eShNoMoveThrough();		// From 'GameCont'
		eMoveAIRunner();    // From 'EnemyActions'
		e_Jump();				// From 'EnemyActions'

		// <<<<< Layer3 >>>>>
		defaultTileSet();		// From 'DefaultTileSet'
		customTileSet();		// From 'CustomTileSet'
		tileProperties();     // From 'CustomTileSet'

		// <<<<< Cont3 >>>>>
		eShootAI();				// From 'EnemyActions'
		jumpForceFactor();		// From 'GameCont'
		pl_notSolidCheck();    //From 'GameCont'
		e_notSolidCheck();    // From 'GameCont'
		gravityFactor();		// From 'GameCont'
		emptyAtFactor();		// From 'GameCont'
		e_emptyAtFactor();		// From 'GameCont'

		// <<<<< Cont_IMP2 >>>>>
		plShoot();				// From 'PlayerActions'
		eShootSet();			// From 'EnemyActions'
    
		lvSet = false;
		roomSet = false;
		isTileDone = false;
 }

void FrameRunner()
{
	
	menuAgain:
	startUp();

  runAgain:
	isRunAgain = false;
	while (run)
	{

		loadFrame();

		// Display all code:-
	  frame:
	  
	  if(eDisplayDelay <= 0)
	  {
		usleep(FrameDelay);

		clrscr();				// Must be at start

		for (int y = 0; y < height - 1; y++)
		{
			for (int x = 0; x < width - 1; x++)
			{
				cout << px[x][y];
			}
			cout << "\n";
		}
		
		statusBar();			// From 'StatusBar.cpp'
		
	  }

		// Code end for display all
		
		// Bug fixing vars
		check1 = eDisplayDelay;
		check4 = eH[0];
		check5 = eW[0];
		// End of Bug fixing vars

	}

	clrscr();

	hpOver();

if(hp > 0)
{
	endGame();
}

	if (isRunAgain == true)
	{
		goto runAgain;
	}
	else if(goBackToMenu == true)
	{
		goto menuAgain;
	}

}