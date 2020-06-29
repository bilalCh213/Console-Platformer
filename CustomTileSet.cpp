
/*
FUNCTIONS FOR FRAMERUNNER:
customTileSet();
notSolidTileSet();
tileProperties();

FUNCTIONS FOR INTERNAL USE:
DrawTileLine(int, int, int, int, string, string);
*/

using namespace std;

string h = "h";
string v = "v";

string r = "r";
string l = "l";

int maxL = 2;
int maxR = 50;

//Draw TileSet Line
void DrawTileLine(int w1, int w2, int h1, int h2, string tile, string is_h_or_v)
{
	
	if(is_h_or_v == h)
	{
	for (int lineFactor = w1; lineFactor < w2; lineFactor++)
		{
			h2 = h1;
			px[lineFactor][h1] = tile;
		}
}
else if(is_h_or_v == v)
{
		for (int lineFactor = h1; lineFactor < h2; lineFactor++)
		{
			w2 = w1;
			px[w1][lineFactor] = tile;
		}
}

}

void EntranceToRoom(int height, string R_or_L)
{
	if(R_or_L == r)
	{
		px[wallEntr_r][height - 1] = entrRoom;
		px[wallEntr_r][height] = entrRoom;
		px[wallEntr_r][height + 1] = entrRoom;
	}
	else if(R_or_L == l)
	{
		px[wallEntr_l][height - 1] = entrRoom;
		px[wallEntr_l][height] = entrRoom;
		px[wallEntr_l][height + 1] = entrRoom;
	}
}

//Custom TileSet Arrangements for each level
void customTileSet() //Only for Solid blocks
{
	/*
	To spot a tile:
	px[ width ][ height ] = name of tile;
	
	To draw a line:
	DrawTileLine( width1, width2, height1, height2, name of tile, if want horizontal line type 'h' else for vertical type 'v')
	First point in DrawTileLine is not rendered
	width2 must be greater than width1
	height2 must be greater than height1
	width2 = width1 for vertical line
	height2 = height1 for horizon line
	Max height = 22, Max Width = 53
	*/
	
	if( lv == 0)
	{
		if( room[0] == 0)
		{
  	DrawTileLine(25,29,4,4,roof,h);
  	DrawTileLine(10,13,10,10,_floor,h);
  	DrawTileLine(40,43,10,10,_floor,h);
		}
	}
	else if( lv == 1 )
	{
		if( room[1] == 0)
		{
		DrawTileLine(22,32,15,15,roof,h);
		DrawTileLine(22,32,11,11,roof,h);
		DrawTileLine(12,41,9,9,roof,h);
		DrawTileLine(7,13,12,12,_floor,h);
		DrawTileLine(9,13,15,15,_floor,h);
		DrawTileLine(40,46,12,12,_floor,h);
		DrawTileLine(40,44,15,15,_floor,h);
		DrawTileLine(22,22,11,15,wall,v);
		DrawTileLine(31,31,11,15,wall,v);
		}
	}
	else if( lv == 2 )
	{
		if( room[2] == 0)
		{
		DrawTileLine(19,30,10,10,_floor,h);
		DrawTileLine(35,46,10,10,_floor,h);
		DrawTileLine(29,44,7,7,roof,h);
		DrawTileLine(2,32,16,16,roof,h);
		DrawTileLine(31,51,16,16,_floor,h);
		DrawTileLine(2,32,13,13,_floor,h);
		DrawTileLine(31,51,13,13,roof,h);
		}
	}
	else if( lv == 3 )
	{
		if( room[3] == 0)
		{
		DrawTileLine(2,8,15,15,_floor,h);
		DrawTileLine(2,8,12,12,_floor,h);
		DrawTileLine(2,8,9,9,_floor,h);
		DrawTileLine(2,8,6,6,_floor,h);
		DrawTileLine(45,51,15,15,_floor,h);
		DrawTileLine(45,51,12,12,_floor,h);
		DrawTileLine(45,51,9,9,_floor,h);
		DrawTileLine(45,51,6,6,_floor,h);
		DrawTileLine(21,33,10,10,roof,h);
		DrawTileLine(13,22,11,11,_floor,h);
		DrawTileLine(32,41,11,11,_floor,h);
		}
	}
	else if( lv == 4 )
	{
		if( room[4] == 0)
		{
		DrawTileLine(2,10,15,15,_floor,h);
		DrawTileLine(2,9,12,12,_floor,h);
		DrawTileLine(2,51,9,9,_floor,h);
		DrawTileLine(39,51,6,6,_floor,h);
		DrawTileLine(2,51,3,3,_floor,h);
		DrawTileLine(10,43,9,9,roof,h);
		px[16][2] = plPassWall;
		px[22][2] = plPassWall;
		}
	}
	else if( lv == 5 )
	{
		if( room[5] == 0)
		{
		px[4][14] = _floor;
		px[5][14] = _floor;
		px[6][14] = _floor;
		px[9][13] = _floor;
		px[12][14] = _floor;
		px[15][15] = _floor;
		px[16][15] = _floor;
		px[18][13] = _floor;
		px[21][14] = _floor;
		px[24][12] = _floor;
		px[27][13] = _floor;
		px[30][12] = _floor;
		px[33][11] = _floor;
		px[36][13] = _floor;
		px[39][11] = _floor;
		px[41][10] = _floor;
		px[42][9] = _floor;
		px[43][9] = _floor;
		px[47][7] = _floor;
		px[48][7] = _floor;
		px[49][7] = _floor;
		px[50][7] = _floor;
		px[50][11] = _floor;
		px[50][15] = _floor;
		DrawTileLine(2,51,19,19,spikes,h);
		px[50][19] = _floor;
		}
	}
	
	/*
	From level 5 onwards, there is used Connected Room System to make levels more bigger!
	
	It must be set in proper order else it will not work i.e the room number increases from left to right. The entrances must be made according to the room number order:
	
	[ 0 ][ 1 ][ 2 ][ 3 ][ 4 ][ 5 ] << Proper order of room numbers
	[ 0 ][ 3 ][ 1 ][ 2 ][ 5 ][ 4 ] << Wrong way!
	[ 5 ][ 4 ][ 3 ][ 2 ][ 1 ][ 0 ] << Wrong way!
	
	Entrance should not be at left side of 0-room and at right side of 5-room.
	
	Tile used for entrance to other rooms:
	  entrRoom
	  
	  Function for wall to enter other rooms:
	  
	  EntranceToRoom( height {mid of point}, at right or left side);
	  
	  IMP. NOTE:
	  Right Side means Increase in Room Number.
	  Left Side means Decrease in Room Number.
	*/
	
	else if( lv == 6)
	{
		if( room[6] == 0)
		{
       EntranceToRoom(17,r);
       EntranceToRoom(8,r);
 			DrawTileLine(maxL,(maxR + 1),10,10,_floor,h);
 			DrawTileLine(6,12,10,10,roof,h);
 			DrawTileLine(15,21,7,7,_floor,h);
 			DrawTileLine(24,30,7,7,_floor,h);
 			DrawTileLine(33,39,7,7,_floor,h);
 			DrawTileLine(42,48,7,7,_floor,h);
 			DrawTileLine(maxL,(maxL + 10),13,13,_floor,h);
 			DrawTileLine(13,(maxR - 4),10,10,spikes,h);
 			DrawTileLine(35,45,18,18,_floor,h);
		}
		else if( room[6] == 1)
		{
			EntranceToRoom(17,l);
			EntranceToRoom(8,l);
			DrawTileLine(maxL,37,10,10,roof,h);
			DrawTileLine(maxL,(maxL + 10),13,13,_floor,h);
			DrawTileLine(40,(maxR + 1),15,15,_floor,h);
			DrawTileLine(40,(maxR + 1),12,12,_floor,h);
			DrawTileLine(40,(maxR + 1),9,9,_floor,h);
			DrawTileLine(40,(maxR + 1),6,6,_floor,h);
			DrawTileLine(maxL,(maxR + 1),3,3,_floor,h);
			DrawTileLine(maxL,(maxL + 4),3,3,roof,h);
			DrawTileLine(10,10,1,3,plPassWall,v);
		}
	}
	else if( lv ==  7)
	{
		if( room[7] == 0)
		{
			EntranceToRoom(17,r);
			EntranceToRoom(8,r);
			DrawTileLine(maxL,(maxR + 1),10,10,_floor,h);
			DrawTileLine(maxL,(maxL + 16),13,13,_floor,h);
			DrawTileLine(maxL,(maxL + 8),16,16,_floor,h);
			DrawTileLine((maxL + 36),(maxL + 36),4,10,wall,v);
			DrawTileLine((maxL + 36),(maxL + 36),1,4,plPassWall,v);
			DrawTileLine((maxL + 20),(maxL + 36),7,7,_floor,h);
			DrawTileLine((maxL + 28),(maxL + 36),4,4,_floor,h);
		}
		else if( room[7] == 1)
		{
			EntranceToRoom(17,r);
			EntranceToRoom(17,l);
			EntranceToRoom(8,r);
			EntranceToRoom(8,l);
			DrawTileLine(maxL,(maxR + 1),10,10,_floor,h);
			DrawTileLine(26,26,1,10,wall,v);
			DrawTileLine(16,37,7,7,_floor,h);
			DrawTileLine(16,37,4,4,_floor,h);
			DrawTileLine(24,29,10,10,roof,h);
			DrawTileLine(40,45,18,18,_floor,h);
			DrawTileLine(10,15,18,18,_floor,h);
		}
		else if( room[7] == 2)
		{
			EntranceToRoom(17,l);
			EntranceToRoom(8,l);
			DrawTileLine(maxL,(maxR + 1),10,10,_floor,h);
			DrawTileLine((maxR - 16),(maxR + 1),13,13,_floor,h);
			DrawTileLine((maxR - 8),(maxR + 1),16,16,_floor,h);
			DrawTileLine((maxR - 36),(maxR - 36),4,10,wall,v);
			DrawTileLine((maxR - 36),(maxR - 36),1,4,plPassWall,v);
			DrawTileLine((maxR - 35),(maxR - 20),7,7,_floor,h);
			DrawTileLine((maxR - 35),(maxR - 27),4,4,_floor,h);
		}
	}
	else if( lv == 8)
	{
		if( room[8] == 0)
		{
			EntranceToRoom(7,r);
			EntranceToRoom(12,r);
			EntranceToRoom(17,r);
			//DrawTileLine(maxL,(maxR + 1),10,10,roof,h);
			DrawTileLine((maxL + 26),(maxR + 1),14,14,_floor,h);
			DrawTileLine(28,32,16,16,_floor,h);
			DrawTileLine((maxR - 12),(maxR + 1),9,9,roof,h);
			DrawTileLine((maxR - 20),(maxR - 13),8,8,roof,h);
			DrawTileLine((maxR - 28),(maxR - 21),7,7,roof,h);
			DrawTileLine((maxR - 36),(maxR - 29),6,6,roof,h);
			DrawTileLine((maxL),(maxR - 39),6,6,_floor,h);
		}
		else if( room[8] == 1)
		{
			EntranceToRoom(7,l);
			EntranceToRoom(3,r);
			EntranceToRoom(17,r);
			EntranceToRoom(17,l);
			EntranceToRoom(12,l);
			EntranceToRoom(12,r);
			//DrawTileLine(maxL,(maxR + 1),10,10,roof,h);
			DrawTileLine((maxL),6,4,4,_floor,h);
			DrawTileLine(maxL,(maxR + 1),14,14,_floor,h);
			DrawTileLine((maxR - 6), (maxR + 1), 5,5,_floor,h);
			DrawTileLine((maxR - 14), (maxR - 8), 7,7,_floor,h);
			DrawTileLine((maxR - 20), (maxR - 15),6,6,_floor,h);
			DrawTileLine((maxR - 28), (maxR - 22),7,7,_floor,h);
			DrawTileLine((maxR - 36), (maxR - 30),7,7,_floor,h);
			DrawTileLine((maxL), (maxR - 40),9,9,roof,h);
			DrawTileLine(24,29,14,14,roof,h);
		}
		else if( room[8] == 2)
		{
			EntranceToRoom(12,l);
			EntranceToRoom(17,l);
			EntranceToRoom(3,l);
			//DrawTileLine(maxL,(maxR - 11),10,10,roof,h);
			DrawTileLine(maxL,(maxR - 12),14,14,_floor,h);
			DrawTileLine((maxR - 11), (maxR + 1),10,10,_floor,h);
			DrawTileLine((maxR - 11), (maxR + 1),13,13,_floor,h);
			DrawTileLine((maxR - 11), (maxR + 1),16,16,_floor,h);
			DrawTileLine((maxR - 11), (maxR + 1),7,7,_floor,h);
			DrawTileLine((maxR - 11), (maxR + 1),4,4,_floor,h);
			DrawTileLine((maxR - 12), (maxR - 11),4,17,wall,v);
			DrawTileLine((maxR - 18), (maxR - 12),4,4,_floor,h);
			DrawTileLine((maxR - 25), (maxR - 19),5,5,_floor,h);
			DrawTileLine((maxR - 32), (maxR - 26),4,4,_floor,h);
			DrawTileLine((maxR - 39), (maxR - 33),5,5,_floor,h);
			DrawTileLine((maxR - 46), (maxR - 40),4,4,_floor,h);
			px[maxL][5] = _floor;
			px[(maxL + 1)][5] = _floor;
		}
	}
	else if( lv == 9)
	{
		if( room[9] == 0)
		{
			EntranceToRoom(2,r);
			DrawTileLine(21,(maxR + 1),16,16,_floor,h);
			DrawTileLine(21,33,13,13,_floor,h);
			DrawTileLine((maxL),33,10,10,_floor,h);
			DrawTileLine(21,33,7,7,_floor,h);
			DrawTileLine(21,(maxR + 1),4,4,_floor,h);
		}
		else if( room[9] == 1)
		{
			EntranceToRoom(8,r);
			EntranceToRoom(2,l);
			DrawTileLine((maxL),33,16,16,_floor,h);
			DrawTileLine(21,33,13,13,_floor,h);
			DrawTileLine(21,(maxR + 1),10,10,_floor,h);
			DrawTileLine(21,33,7,7,_floor,h);
			DrawTileLine((maxL),33,4,4,_floor,h);
		}
		else if( room[9] == 2)
		{
			EntranceToRoom(8,l);
			DrawTileLine(21,(maxR + 1),16,16,_floor,h);
			DrawTileLine(21,33,13,13,_floor,h);
			DrawTileLine((maxL),33,10,10,_floor,h);
			DrawTileLine(21,33,7,7,_floor,h);
			DrawTileLine(21,(maxR + 1),4,4,_floor,h);
		}
	}
	else if( lv == maxLv)
	{
		run = false;
	}
	
	isTileDone = true;
}

//notSolid TileSet arrangements for each level
void notSolidTileSet() //Only for NotSolid blocks
{
	  if(lvSet == true)
	  {
	  	
	  	//Resetting all grave position values
	  	for(int n = 0; n < totalGravesUsed; n++)
	  	{
	  		gravePosW[n] = zeroPosW;
	  		gravePosH[n] = zeroPosH;
	  	}
	  	
	  	//Resetting grave enemy generation delay
	  	for(int i = 0; i < totalGravesUsed; i++)
	  	{
  	  	enemyRegenDelay[i] = maxEnemyRegenDelay;
	  	}
	  	
	  }
	  
	  //Power Indicator
	  if(plH != zeroPosH)
	  {
	      px[plW][plH - 1] = powInd;
	  }
	
  	//All doors rendered by this
  	if(room[lv] == doorRoom[lv])
  	{
		px[doorlv_w[lv]][doorlv_h[lv]] = door;
  	}
		
		//All shops(shopPlaces) rendered by this
		if(room[lv] == shopRoom[lv])
		{
		px[shoplv_w[lv]][shoplv_h[lv]] = shop;
  	}
  	
  	//Specific lv and room notSolid TileSets
  	//For Grave, mention position:gravePosW[](gPW),gravePosH[](gPH, and then, mention display: px[gPW][gPH] = grave;
		
		//Other notSolid TileSets
		if(lv == 9)
		{
			if(room[9] == 0)
			{
				gravePosW[0] = (maxR - 3);
				gravePosH[0] = 15;
				px[gravePosW[0]][gravePosH[0]] = grave;
				
				gravePosW[1] = (maxL + 3);
				gravePosH[1] = 9;
				px[gravePosW[1]][gravePosH[1]] = grave;
				
				gravePosW[2] = (maxR - 3);
				gravePosH[2] = 3;
				px[gravePosW[2]][gravePosH[2]] = grave;
			}
			else if(room[9] == 1)
			{
				gravePosW[0] = (maxL + 3);
				gravePosH[0] = 15;
				px[gravePosW[0]][gravePosH[0]] = grave;
				
				gravePosW[1] = (maxR - 3);
				gravePosH[1] = 9;
				px[gravePosW[1]][gravePosH[1]] = grave;
				
				gravePosW[2] = (maxL + 3);
				gravePosH[2] = 3;
				px[gravePosW[2]][gravePosH[2]] = grave;
			}
			else if(room[9] == 2)
			{
				gravePosW[0] = (maxR - 3);
				gravePosH[0] = 15;
				px[gravePosW[0]][gravePosH[0]] = grave;
				
				gravePosW[1] = (maxL + 3);
				gravePosH[1] = 9;
				px[gravePosW[1]][gravePosH[1]] = grave;
				
				gravePosW[2] = (maxR - 3);
				gravePosH[2] = 3;
				px[gravePosW[2]][gravePosH[2]] = grave;
			}
		}
		
}

//Particular TileSet properties
void tileProperties()
{
	// FOR SOLID TILES
	
	//For Permeable Wall
	if(px[plW][plH] == plPassWall)
		{
			px[plW][plH] = pl;
		}
		
	 // FOR NOT SOLID TILES
	 
	 // For Grave
	 for(int i = 0; i < totalGravesUsed; i++)
	 {
	 if(
	 (gravePosW[i] != zeroPosW)
	 && (gravePosH[i] != zeroPosH)
	 && (enemyRegenDelay[i] <= 0)
	 )
	 {
	 	
	 	for(int n = totalDefaultEnemies[room[lv]]; n < eNumb; n++)
	 	{
	 		if(eRun[n] == false)
	 		{
	 		eH[n] = gravePosH[i];
	 		eW[n] = gravePosW[i];
	 		eRun[n] = true;
	 		eLoot[n] = true;
	 		
	 		eFromGrave[n] = true;
	 		
	 		goto oneEonly;
  	 	}
	 	}
	 	
	 	oneEonly:
	 	
	 	enemyRegenDelay[i] = maxEnemyRegenDelay;
	 }
	 else if(enemyRegenDelay[i] > 0)
	 {
	 	enemyRegenDelay[i]--;
	 }
	 }
	 for(int eG = totalDefaultEnemies[room[lv]]; eG < eNumb; eG++)
	 {
	 	if(eFromGrave[eG] == true)
	 	{
	 		px[eW[eG]][eH[eG]] = enem[grave_eType];
	   	eSetNumb(eG);
	   	eFromGrave[eG] = false;
	   	eFromGraveDisplay[eG] = true;
	 	}
	 	else if(eFromGraveDisplay[eG] == true && eHp[eG] > 0)
	 	{
	 		px[eW[eG]][eH[eG]] = enem[grave_eType];
	 	}
	 }
	 
	 // For Power Indicator
	 
	 //SlowPow
	 if(isSlowPow == true)
	 {
	 	
	 	if(slowPowDelay > 0)
	 	{
	 		if(slowPowDelay > emerSlowPow)
	 		{
	 			powInd = slowPowGInd;
	 		}
	 		else if(slowPowDelay <= emerSlowPow && slowPowDelay > 0)
	 		{
	 			if(powInd == slowPowGInd)
	 			{
	 				powInd = _empty;
	 			}
	 			else if(powInd == _empty)
	 			{
	 				powInd = slowPowGInd;
	 			}
	 		}
	 	}
	 	else if(slowPowDelay <= 0)
	 	{
	 		powInd = _empty;
	 	}
	 	
	 }
	 
	 //Regenerate
	 else if(isRegenerate == true)
	 {
	 	
	 	if(regenDelay > 0)
	 	{
	 		if(regenDelay > emerRegenerate)
	 		{
	 			powInd = regenerateGInd;
	 		}
	 		else if(regenDelay <= emerRegenerate && regenDelay > 0)
	 		{
	 			if(powInd == regenerateGInd)
	 			{
	 				powInd = _empty;
	 			}
	 			else if(powInd == _empty)
	 			{
	 				powInd = regenerateGInd;
	 			}
	 		}
	 	}
	 	else if(regenDelay <= 0)
	 	{
	 		powInd = _empty;
	 	}
	 	
	 }
	 //Add Power here
	 
	 else
	 {
	 	powInd = _empty;
	 }
	 notSolid[3] = powInd;
	
}