
/*

FUNCTIONS FOR FRAMERUNNER;
plSet();
plPropSet();

FUNCTIONS FOR INTERNAL USE:
* None *

*/

using namespace std;

    //Player Position Set for each level
void plSet()
{
	if(lvSet == true)
	{
		
		//Destroying all player bullets from previous level:::
		for( int n = 0; n < 19; n++)
		{
			shoot[n] = false;
		}
		
		//Player Position for Level's INITIAL ROOM
		if( lv == 0)
		{
			
		plW = 26;
		plH = 3;
		
		}
		else if( lv == 1)
		{
			
		plW = 25;
		plH = 18;
		
		}
		else if( lv == 2)
		{
			
		plW = 4;
		plH = 18;
			
		}
		else if( lv == 3)
		{
			
			plW = 27;
			plH = 18;
			
		}
		else if( lv == 4)
		{
			
	   plH = 18;
 		plW = 47;
			
		}
		else if( lv == 5)
		{
			
			plH = 6;
			plW = 48;
			
		}
		else if( lv == 6)
		{
			
			plH = 18;
			plW = 4;
			
		}
		else if( lv == 7)
		{
			
			plH = 18;
			plW = 26;
			
		}
		else if( lv == 8)
		{
			
			plH = 18;
			plW = 6;
			
		}
		else if( lv == 9)
		{
			
			plH = 18;
			plW = 6;
			
		}
		
	}
	
	if(roomSet == true)
	{
		//Destroying all player bullets from previous room:::
		for( int n = 0; n < 19; n++)
		{
			shoot[n] = false;
		}
		
		plH = entrH;
		plW = entrW;
	}
	
	//To display player:
	px[plW][plH] = pl;
	
	//For Bullets exceeding limit
for(int type = 0; type < plShTypes; type++)
{
	
if(
(plShVal > plShMaxValForType[type])
&& (is_plSh[type] == true)
)
{
	plShVal--;
}
else if( plShValForType[type] > plShMaxValForType[type])
{
	plShValForType[type]--;
}

}
	
}

    //Player Properties Set for definate actions
void plPropSet()
{
	
	for( int type = 0; type < plShTypes; type++)
	{
	
	if(is_plSh[type] == true)
	{
		
		for(int n = 0; n < 19; n++)
		{
	if(plShDuringDelay[n] > 0)
	{
		plShDuringDelay[n] = plShDuringDelay[n] - plShDuringDelaySub[type];
	}
		}
	
	if(plShAgainDelay > 0)
	{
		plShAgainDelay = plShAgainDelay - plShAgainDelaySub[type];
	}
	
}

while(plShValForType[type] > plShMaxValForType[type])
{
	plShValForType[type]--;
}

	}

//Particular properties: For plSh[1]
	if(plSh[1] == "^")
	{
		plSh[1] = "<";
	}
	else if(plSh[1] == "<")
	{
		plSh[1] = ">";
	}
	else if(plSh[1] == ">")
	{
		plSh[1] = "^";
	}

}