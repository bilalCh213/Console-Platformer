
/*
FUNCTIONS FOR FRAMERUNNER:
eSet();
eSetNumbFromType();

FUNCTIONS FOR INTERNAL USE:
* None *
*/

using namespace std;

void eSet()
{
	//Set enemy and player intial position here as well as all enemies' variable positions
	
	//Level Initial Enemy Positions
	if( lvSet == true)
	{
		e_emptyAt = false;
		
		//Setting Room
		room[lv] = initRoom[lv];
		prevRoom = room[lv];
		
		//Redeploying enemy looting
		for( int n = 0; n < eNumb; n++)
		{
			eLoot[n] = true;
		}
		
		//Kill all enemies
		for( int n = 0; n < eNumb; n++ )
		{
		eHp[n] = 0;
		eW[n] = zeroPosW;
		eH[n] = zeroPosH;
		px[eW[n]][eH[n]] = zeroShow;
		eRun[n] = false;
		}
		
		//Destroying all enemy bullets
		for( int n = 0; n < eNumb; n++)
		{
		for( int b = 0; b < eShLimit; b++)
		{
			eShoot[n][b] = false;
		}
		}
		
		//Setting Rooms to 'not setted'
		for( int n = 0; n < maxNoOfRooms; n++)
		{
			isRoom_eSet[n] = false;
		}
		
		//Setting Enemy Display Delay
		eDisplayDelay = max_eDisplayDelay;
		
		//MAX enemy numbers = eNumb
		
		//Setting Enemy Position for level's INITIAL ROOM
	if( lv == 0)
	{
		
		eH[0] = 9;
	 eW[0] = 41;
	 eRun[0] = true;
	 
	 eH[1] = 9;
	 eW[1] = 11;
	 eRun[1] = true;
	
	totalDefaultEnemies[0] = 2;
	
	}
	else if( lv == 1)
	{
		
		eH[0] = 11;
		eW[0] = 41;
		eRun[0] = true;
		
		eH[1] = 13;
		eW[1] = 41;
		eRun[1] = true;
		
		eH[2] = 11;
		eW[2] = 11;
		eRun[2] = true;
		
		eH[3] = 13;
		eW[3] = 11;
		eRun[3] = true;
		
		totalDefaultEnemies[0] = 4;
		
	}
	else if(lv == 2)
	{
		
 	 eH[0] = 12;
		eW[0] = 46;
		eRun[0] = true;
		
		eH[1] = 15;
		eW[1] = 4;
		eRun[1] = true;
		
		eH[2] = 15;
		eW[2] = 48;
		eRun[2] = true;
		
		eH[3] = 6;
		eW[3] = 39;
		eRun[3] = true;
		
		totalDefaultEnemies[0] = 4;
		
	}
	else if(lv == 3)
	{
		
		eH[0] = 9;
		eW[0] = 24;
		eRun[0] = true;
		
		eH[1] = 9;
		eW[1] = 29;
		eRun[1] = true;
		
		eH[2] = 8;
		eW[2] = 34;
		eRun[2] = true;
		
		eH[3] = 8;
		eW[3] = 19;
		eRun[3] = true;
		
		eH[4] = 14;
		eW[4] = 4;
		eRun[4] = true;
		
		eH[5] = 8;
		eW[5] = 5;
		eRun[5] = true;
		
		eH[6] = 14;
		eW[6] = 49;
		eRun[6] = true;
		
		eH[7] = 8;
		eW[7] = 48;
		eRun[7] = true;
		
		totalDefaultEnemies[0] = 8;
		
	}
	else if(lv == 4)
	{
		
		eH[0] = 18;
		eW[0] = 10;
		eRun[0] = true;
		
		eH[1] = 14;
		eW[1] = 8;
		eRun[1] = true;
		
		eH[2] = 11;
		eW[2] = 7;
		eRun[2] = true;
		
		eH[3] = 8;
		eW[3] = 20;
		eRun[3] = true;
		
		eH[4] = 8;
		eW[4] = 35;
		eRun[4] = true;
		
		eH[5] = 8;
		eW[5] = 4;
		eRun[5] = true;
		
		eH[6] = 2;
		eW[6] = 8;
		eRun[6] = true;
		
		eH[7] = 4;
		eW[7] = 49;
		eRun[7] = true;
		
		totalDefaultEnemies[0] = 8;
		
	}
	else if(lv == 5)
	{
		
		eH[0] = 18;
		eW[0] = 7;
		eRun[0] = true;
		
		eH[1] = 18;
		eW[1] = 12;
		eRun[1] = true;
		
		eH[2] = 18;
		eW[2] = 17;
		eRun[2] = true;
		
		totalDefaultEnemies[0] = 3;
		
	}
	else if(lv == 6)
	{
		
		eH[0] = 6;
		eW[0] = 18;
		eRun[0] = true;
			
		eH[1] = 6;
		eW[1] = 27;
		eRun[1] = true;
		
		eH[2] = 6;
		eW[2] = 36;
		eRun[2] = true;
		
		eH[3] = 6;
		eW[3] = 46;
		eRun[3] = true;
		
		eH[4] = 12;
		eW[4] = 4;
		eRun[4] = true;
		
		eH[5] = 17;
		eW[5] = 38;
		eRun[5] = true;
		
		eH[6] = 17;
		eW[6] = 40;
		eRun[6] = true;
		
		eH[7] = 17;
		eW[7] = 42;
		eRun[7] = true;
		
		totalDefaultEnemies[0] = 8;
		totalDefaultEnemies[1] = 7;
		
	}
	else if(lv == 7)
	{
		
		eH[0] = 17;
		eW[0] = 42;
		eRun[0] = true;
			
		eH[1] = 17;
		eW[1] = 12;
		eRun[1] = true;
		
    eH[2] = 6;
			eW[2] = 18;
			eRun[2] = true;
			
			eH[3] = 6;
			eW[3] = 34;
			eRun[3] = true;
			
			eH[4] = 3;
			eW[4] = 18;
			eRun[4] = true;
			
			eH[5] = 3;
			eW[5] = 34;
			eRun[5] = true;
			
			eH[6] = 9;
			eW[6] = 18;
			eRun[6] = true;
			
			eH[7] = 9;
			eW[7] = 34;
			eRun[7] = true;
			
			totalDefaultEnemies[0] = 5;
  		totalDefaultEnemies[1] = 8;
  		totalDefaultEnemies[2] = 1;
			
	}
	else if(lv == 8)
	{
		
   		eH[0] = 13;
  			eW[0] = 30;
  			eRun[0] = true;
  			
  			eH[1] = 7;
  			eW[1] = 35;
  			eRun[1] = true;
  			
  			eH[2] = 6;
  			eW[2] = 27;
  			eRun[2] = true;
  			
  			eH[3] = 5;
  			eW[3] = 19;
  			eRun[3] = true;
  			
  			eH[4] = 3;
  			eW[4] = 6;
  			eRun[4] = true;
  			
  			totalDefaultEnemies[0] = 5;
    		totalDefaultEnemies[1] = 6;
    		totalDefaultEnemies[2] = 8;
  			
	}
	else if(lv == 9)
	{
		
		eH[0] = 15;
			eW[0] = 27;
			eRun[0] = true;
			
			eH[1] = 9;
			eW[1] = 27;
			eRun[1] = true;
			
			eH[2] = 3;
			eW[2] = 27;
			eRun[2] = true;
			
			eH[3] = 6;
			eW[3] = 27;
			eRun[3] = true;
			
			eH[4] = 12;
			eW[4] = 27;
			eRun[4] = true;
			
			totalDefaultEnemies[0] = 5;
    	totalDefaultEnemies[1] = 5;
    	totalDefaultEnemies[2] = 5;
		
	}
	
	//Enemy avoidal to got to void
	for(int n = 0; n < totalDefaultEnemies[room[lv]]; n++)
	{
		eHp[n] = 1;
	}
	
	}
	
	//Room Initial Enemy Positions
	if( roomSet == true)
	{
		e_emptyAt = false;
		
		//Storing Previous Room's Enemy Position
		for( int n = 0; n < eNumb; n++ )
		{
			temp_eW[prevRoom][n] = eW[n];
			temp_eH[prevRoom][n] = eH[n];
			temp_eHp[prevRoom][n] = eHp[n];
			temp_eGraved[prevRoom][n] = eFromGraveDisplay[n];
		}
		
		//Setting Room
		prevRoom = room[lv];
		
		//Redeploying enemy looting
		for( int n = 0; n < eNumb; n++)
		{
			eLoot[n] = true;
		}
		
		//Disappear all enemies
		for( int n = 0; n < eNumb; n++ )
		{
			eHp[n] = 0;
		eW[n] = zeroPosW;
		eH[n] = zeroPosH;
		px[eW[n]][eH[n]] = zeroShow;
		eRun[n] = false;
		}
		
		//Destroying all enemy bullets
		for( int n = 0; n < eNumb; n++)
		{
		for( int b = 0; b < eShLimit; b++)
		{
			eShoot[n][b] = false;
		}
		}
		
		//Converting all grave enemies to default
		for( int n = 0; n < eNumb; n++)
		{
			eFromGrave[n] = false;
			eFromGraveDisplay[n] = false;
		}
		
		//Setting Enemy Display Delay
		eDisplayDelay = max_eDisplayDelay;
		
		//Enemy Position for ALL ROOMS
		if(lv == 6)
		{
		  if(room[lv] == 0)
  		{
		eH[0] = 6;
		eW[0] = 18;
		eRun[0] = true;
			
		eH[1] = 6;
		eW[1] = 27;
		eRun[1] = true;
		
		eH[2] = 6;
		eW[2] = 36;
		eRun[2] = true;
		
		eH[3] = 6;
		eW[3] = 46;
		eRun[3] = true;
		
		eH[4] = 12;
		eW[4] = 4;
		eRun[4] = true;
		
		eH[5] = 17;
		eW[5] = 38;
		eRun[5] = true;
		
		eH[6] = 17;
		eW[6] = 40;
		eRun[6] = true;
		
		eH[7] = 17;
		eW[7] = 42;
		eRun[7] = true;
	  	}
	  	else if(room[lv] == 1)
	  	{
			eH[0] = 5;
			eW[0] = 45;
			eRun[0] = true;
			
			eH[1] = 8;
			eW[1] = 46;
			eRun[1] = true;
			
			eH[2] = 11;
			eW[2] = 47;
			eRun[2] = true;
			
			eH[3] = 14;
			eW[3] = 48;
			eRun[3] = true;
			
			eH[4] = 11;
			eW[4] = 4;
			eRun[4] = true;
			
			eH[5] = 2;
			eW[5] = 14;
			eRun[5] = true;
			
			eH[6] = 9;
			eW[6] = 6;
			eRun[6] = true;
  		}
		}
  	if(lv == 7)
		{
		  if(room[lv] == 0)
  		{
  			eH[0] = 3;
  			eW[0] = 37;
  			eRun[0] = true;
  			
  			eH[1] = 6;
  			eW[1] = 37;
  			eRun[1] = true;
  			
  			eH[2] = 9;
  			eW[2] = 20;
  			eRun[2] = true;
  			
  			eH[3] = 12;
  			eW[3] = 3;
  			eRun[3] = true;
  			
  			eH[4] = 15;
  			eW[4] = 3;
  			eRun[4] = true;
	  	}
  		else if(room[lv] == 1)
  		{
			eH[0] = 17;
		eW[0] = 42;
		eRun[0] = true;
			
		eH[1] = 17;
		eW[1] = 12;
		eRun[1] = true;
		
    eH[2] = 6;
			eW[2] = 18;
			eRun[2] = true;
			
			eH[3] = 6;
			eW[3] = 34;
			eRun[3] = true;
			
			eH[4] = 3;
			eW[4] = 18;
			eRun[4] = true;
			
			eH[5] = 3;
			eW[5] = 34;
			eRun[5] = true;
			
			eH[6] = 9;
			eW[6] = 18;
			eRun[6] = true;
			
			eH[7] = 9;
			eW[7] = 34;
			eRun[7] = true;
  		}
	  	else if(room[lv] == 2)
  		{
  			eH[0] = 3;
  			eW[0] = 15;
  			eRun[0] = true;
  		}
		}
		else if(lv == 8)
		{
	  	if(room[lv] == 0)
  		{
  			eH[0] = 13;
  			eW[0] = 30;
  			eRun[0] = true;
  			
  			eH[1] = 7;
  			eW[1] = 35;
  			eRun[1] = true;
  			
  			eH[2] = 6;
  			eW[2] = 27;
  			eRun[2] = true;
  			
  			eH[3] = 5;
  			eW[3] = 19;
  			eRun[3] = true;
  			
  			eH[4] = 3;
  			eW[4] = 6;
  			eRun[4] = true;
  		}
  		else if(room[lv] == 1)
  		{
  			eH[0] = 2;
  			eW[0] = 4;
  			eRun[0] = true;
  			
  			eH[1] = 13;
  			eW[1] = 27;
  			eRun[1] = true;
  			
  			eH[2] = 4;
  			eW[2] = 46;
  			eRun[2] = true;
  			
  			eH[3] = 6;
  			eW[3] = 38;
  			eRun[3] = true;
  			
  			eH[4] = 5;
  			eW[4] = 32;
  			eRun[4] = true;
  			
  			eH[5] = 6;
  			eW[5] = 22;
  			eRun[5] = true;
  		}
  		else if(room[lv] == 2)
  		{
  			eH[0] = 13;
  			eW[0] = 27;
  			eRun[0] = true;
  			
  			eH[1] = 3;
  			eW[1] = 40;
  			eRun[1] = true;
  			
  			eH[2] = 6;
  			eW[2] = 41;
  			eRun[2] = true;
  			
  			eH[3] = 9;
  			eW[3] = 42;
  			eRun[3] = true;
  			
  			eH[4] = 12;
  			eW[4] = 43;
  			eRun[4] = true;
  			
  			eH[5] = 15;
  			eW[5] = 44;
  			eRun[5] = true;
  			
  			eH[6] = 4;
  			eW[6] = 29;
  			eRun[6] = true;
  			
  			eH[7] = 4;
  			eW[7] = 15;
  			eRun[7] = true;
  		}
		}
	else if( lv == 9)
	{
		if( room[lv] == 0)
		{
			eH[0] = 15;
			eW[0] = 27;
			eRun[0] = true;
			
			eH[1] = 9;
			eW[1] = 27;
			eRun[1] = true;
			
			eH[2] = 3;
			eW[2] = 27;
			eRun[2] = true;
			
			eH[3] = 6;
			eW[3] = 27;
			eRun[3] = true;
			
			eH[4] = 12;
			eW[4] = 27;
			eRun[4] = true;
		}
		else if( room[lv] == 1)
		{
			eH[0] = 15;
			eW[0] = 27;
			eRun[0] = true;
			
			eH[1] = 9;
			eW[1] = 27;
			eRun[1] = true;
			
			eH[2] = 3;
			eW[2] = 27;
			eRun[2] = true;
			
			eH[3] = 6;
			eW[3] = 27;
			eRun[3] = true;
			
			eH[4] = 12;
			eW[4] = 27;
			eRun[4] = true;
		}
		else if( room[lv] == 2)
		{
			eH[0] = 15;
			eW[0] = 27;
			eRun[0] = true;
			
			eH[1] = 9;
			eW[1] = 27;
			eRun[1] = true;
			
			eH[2] = 3;
			eW[2] = 27;
			eRun[2] = true;
			
			eH[3] = 6;
			eW[3] = 27;
			eRun[3] = true;
			
			eH[4] = 12;
			eW[4] = 27;
			eRun[4] = true;
		}
	}
	
	//Setting Enemies to their temporary positions as in the corresponding Room
	for(int n = 0; n < eNumb; n++)
	{
		if(temp_eW[room[lv]][n] != zeroPosW && temp_eH[room[lv]][n] != zeroPosH && temp_eHp[room[lv]][n] > 0)
		{
			eDisplay();
			eSetNumb(n);
			emptyTileSet();
			
			eH[n] = temp_eH[room[lv]][n];
			eW[n] = temp_eW[room[lv]][n];
			eHp[n] = temp_eHp[room[lv]][n];
			eFromGraveDisplay[n] = temp_eGraved[room[lv]][n];
			eRun[n] = true;
			
			temp_eH[room[lv]][n] = zeroPosH;
			temp_eW[room[lv]][n] = zeroPosW;
			temp_eHp[room[lv]][n] = 0;
		}
	}
	
	}
	
}

void eDisplay()
{
	if( lv == 0)
	{
		px[eW[0]][eH[0]] = enem[1];
		px[eW[1]][eH[1]] = enem[1];
	}
	else if( lv == 1)
	{
		px[eW[0]][eH[0]] = enem[0];
		px[eW[1]][eH[1]] = enem[1];
		px[eW[2]][eH[2]] = enem[0];
		px[eW[3]][eH[3]] = enem[1];
	}
	else if( lv == 2)
	{
		px[eW[0]][eH[0]] = enem[1];
		px[eW[1]][eH[1]] = enem[2];
		px[eW[2]][eH[2]] = enem[2];
		px[eW[3]][eH[3]] = enem[0];
	}
	else if(lv == 3)
	{
		px[eW[0]][eH[0]] = enem[0];
		px[eW[1]][eH[1]] = enem[0];
		px[eW[2]][eH[2]] = enem[0];
		px[eW[3]][eH[3]] = enem[0];
		px[eW[4]][eH[4]] = enem[0];
		px[eW[5]][eH[5]] = enem[0];
		px[eW[6]][eH[6]] = enem[0];
		px[eW[7]][eH[7]] = enem[0];
	}
	else if(lv == 4)
	{
		px[eW[0]][eH[0]] = enem[1];
		px[eW[1]][eH[1]] = enem[0];
		px[eW[2]][eH[2]] = enem[0];
		px[eW[3]][eH[3]] = enem[0];
		px[eW[4]][eH[4]] = enem[0];
		px[eW[5]][eH[5]] = enem[1];
		px[eW[6]][eH[6]] = enem[3];
		px[eW[7]][eH[7]] = enem[1];
	}
	else if(lv == 5)
	{
		px[eW[0]][eH[0]] = enem[1];
		px[eW[1]][eH[1]] = enem[1];
		px[eW[2]][eH[2]] = enem[1];
	}
	else if(lv == 6)
	{
		if(room[lv] == 0)
		{
 	 	px[eW[0]][eH[0]] = enem[0];
  		px[eW[1]][eH[1]] = enem[0];
  		px[eW[2]][eH[2]] = enem[0];
  		px[eW[3]][eH[3]] = enem[0];
  		px[eW[4]][eH[4]] = enem[1];
  		px[eW[5]][eH[5]] = enem[0];
  		px[eW[6]][eH[6]] = enem[0];
  		px[eW[7]][eH[7]] = enem[0];
		}
		else if(room[lv] == 1)
		{
			px[eW[0]][eH[0]] = enem[0];
			px[eW[1]][eH[1]] = enem[0];
			px[eW[2]][eH[2]] = enem[0];
			px[eW[3]][eH[3]] = enem[0];
			px[eW[4]][eH[4]] = enem[1];
			px[eW[5]][eH[5]] = enem[3];
			px[eW[6]][eH[6]] = enem[3];
		}
	}
	else if(lv == 7)
	{
		if(room[lv] == 0)
		{
			px[eW[0]][eH[0]] = enem[3];
			px[eW[1]][eH[1]] = enem[0];
			px[eW[2]][eH[2]] = enem[1];
			px[eW[3]][eH[3]] = enem[0];
			px[eW[4]][eH[4]] = enem[0];
		}
		else if(room[lv] == 1)
		{
			px[eW[0]][eH[0]] = enem[0];
			px[eW[1]][eH[1]] = enem[0];
			px[eW[2]][eH[2]] = enem[1];
  		px[eW[3]][eH[3]] = enem[1];
  		px[eW[4]][eH[4]] = enem[1];
  		px[eW[5]][eH[5]] = enem[1];
  		px[eW[6]][eH[6]] = enem[2];
  		px[eW[7]][eH[7]] = enem[2];
  		check2++;
		}
		else if(room[lv] == 2)
		{
			px[eW[0]][eH[0]] = enem[3];
		}
	}
	else if(lv == 8)
	{
		if(room[lv] == 0)
		{
			px[eW[0]][eH[0]] = enem[0];
  		px[eW[1]][eH[1]] = enem[0];
  		px[eW[2]][eH[2]] = enem[0];
  		px[eW[3]][eH[3]] = enem[0];
  		px[eW[4]][eH[4]] = enem[1];
		}
		else if(room[lv] == 1)
		{
			px[eW[0]][eH[0]] = enem[1];
  		px[eW[1]][eH[1]] = enem[2];
  		px[eW[2]][eH[2]] = enem[0];
  		px[eW[3]][eH[3]] = enem[0];
			px[eW[4]][eH[4]] = enem[0];
			px[eW[5]][eH[5]] = enem[0];
		}
		else if(room[lv] == 2)
		{
			px[eW[0]][eH[0]] = enem[2];
			px[eW[1]][eH[1]] = enem[0];
			px[eW[2]][eH[2]] = enem[0];
			px[eW[3]][eH[3]] = enem[0];
			px[eW[4]][eH[4]] = enem[0];
			px[eW[5]][eH[5]] = enem[0];
			px[eW[6]][eH[6]] = enem[0];
			px[eW[7]][eH[7]] = enem[0];
		}
	}
	else if( lv == 9)
	{
		if( room[lv] == 0)
		{
			px[eW[0]][eH[0]] = enem[0];
  		px[eW[1]][eH[1]] = enem[0];
  		px[eW[2]][eH[2]] = enem[0];
  		px[eW[3]][eH[3]] = enem[0];
  		px[eW[4]][eH[4]] = enem[0];
		}
		else if( room[lv] == 1)
		{
			px[eW[0]][eH[0]] = enem[0];
  		px[eW[1]][eH[1]] = enem[0];
  		px[eW[2]][eH[2]] = enem[0];
  		px[eW[3]][eH[3]] = enem[0];
  		px[eW[4]][eH[4]] = enem[0];
		}
		else if( room[lv] == 2)
		{
			px[eW[0]][eH[0]] = enem[0];
  		px[eW[1]][eH[1]] = enem[0];
  		px[eW[2]][eH[2]] = enem[0];
  		px[eW[3]][eH[3]] = enem[0];
  		px[eW[4]][eH[4]] = enem[0];
		}
	}
	
	if(eDisplayDelay > 0)
	{
		eDisplayDelay--;
	}
	
}

  //Enemy Set Properties into Numb
  void eSetNumb(int n)
  {
      	int type = 0;
      	
				for( type = 0; type < eTypes; type++)
				{
					if( px[eW[n]][eH[n]] == enem[type] )
					{
						
						eHp[n] = eHpSet[type];
						
				eDelaySub[n] = eRateOfDelay[type];
				
				eMaxMoveTimesNumb[n] = eMaxMoveTimesType[type];
				
				isE_ConstMoveNumb[n] = isE_ConstMoveType[type];
				
				eConstDelaySub[n] = eRateOfConstDelay[type];
				
				isE_PlatMoveNumb[n] = isE_PlatMoveType[type];
				
				ePlatDelaySub[n] = eRateOfPlatDelay[type];
				
				set_eJumpTimeNumb[n] = set_eJumpTimeType[type];
				
				eJumpMoveNumb[n] = eJumpMoveType[type];
				
				eShNumb[n] = eShType[type];
				
				eEyeRangeNumb[n] = eEyeRangeType[type];
				
				eShAgainDelaySubNumb[n] = eShAgainDelaySubType[type];
				
				eShDuringDelaySubNumb[n] = eShDuringDelaySubType[type];
				
				hpLossNumb[n] = hpLossType[type];
				
				e_giveVal_goldNumb[n] = e_giveVal_goldType[type];
				
				e_give_slowPowNumb[n] = e_give_slowPowType[type];
				
				e_giveVal_slowPowNumb[n] = e_giveVal_slowPowType[type];
				
				e_give_regenerateNumb[n] = e_give_regenerateType[type];
				
				e_giveVal_regenerateNumb[n] = e_giveVal_regenerateType[type];
				
				e_give_invulnerableNumb[n] = e_give_invulnerableType[type];
				
				e_giveVal_invulnerableNumb[n] = e_giveVal_invulnerableType[type];
				
				e_give_nukeNumb[n] = e_give_nukeType[type];
				
				e_giveVal_nukeNumb[n] = e_giveVal_nukeType[type];
				
				for( int shType = 0; shType < plShTypes; shType++ )
				{
					e_give_plShNumb[shType][n] = e_give_plShType[shType][type];
					
					e_giveVal_plShNumb[n] = e_giveVal_plShType[type];
				}
				
			}
			}
			
  }

  //Enemy Set from Type to Numb
		void eSetNumbFromType()
		{
				
			if(
			(lvSet == true)
			|| (
			(roomSet == true)
			&& (isRoom_eSet[room[lv]] == false)
			)
			)
			{
				
				for(int n = 0; n < eNumb; n++)
				{
				eSetNumb(n);
				}
				
 			eHpSetted = true;
 			isRoom_eSet[room[lv]] = true;
			}
			
		}