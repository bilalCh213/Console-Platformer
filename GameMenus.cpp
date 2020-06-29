
/*
FUNCTIONS FOR FRAMERUNNER;
hpOver();
endGame();

FUNCTIONS FOR INTERNAL USE:
lvShow();
escMenu();
nextLv();
shopMenu();
devNumbers();
*/

using namespace std;

void gameHelp()
{
	clrscr();
	cout << "No help for now! :/";
	clrscr();
	cout << "No help for now! :/";
	cout << "\nNo help for now! :/";
	usleep(90000);
	usleep(90000);
	usleep(90000);
	usleep(90000);
}

 void lvShow()
 {
 				clrscr();
 				cout << upperLine;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "~~~~~~~~~~~~~~~~~~";
			cout << " " << door << door << door <<  " LEVEL " << lv << " " << door << door << door << " " ;
			cout << "~~~~~~~~~~~~~~~~~~";
			run = true;
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			cout << "\n\n ...................................................";
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			cout << "\n ...................................................";
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			cout << "\n ...................................................";
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			cout << "\n ...................................................";
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			cout << "\n ...................................................";
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			cout << "\n ...................................................";
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			cout << "\n ..................................Loading..........";
			
    	loadFrame;
   	 
   	 usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			cout << "\n ...................................................";
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			usleep(50000);
			cout << "\n ...................................................";
			usleep(50000);
			usleep(50000);
			usleep(50000);
			clrscr();
 }
 
	void escMenu()
	{
		char ex;
	
	cout << upperLine;
	cout << "\n\n >>> Are you sure\n  that you want to\n  terminate the game? <<< \n\n  (Enter 'y' to terminate or\n  'n' to play game) \n";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << lowerLine;
	
	while(run == false)
	{
		ex = getch();
		
		if(ex == 121)
		{
			run = true;
			isRunAgain = false;
			goBackToMenu = false;
			
			clrscr();
	cout << upperLine;
	cout << "\n\n\t  - Terminated! - \n";
	cout << "\n    ~*~ Thank you for playing ~*~ \n";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << lowerLine;
		
		}
		else if(ex == 110)
		{
			run = true;
			isRunAgain = true;
			
			if(goBackToMenu == true)
			{
				startUI = true;
				run = true;
		  	isRunAgain = false;
			}
			
		}
		
	}
	
	}
	
	void hpOver()
	{
		char i;
		
		if(hp <= 0)
		{
			cout << upperLine;
			cout << "\n\n\n\t --------++-------- \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t -------×  ×------- \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t ------+    +------ \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t -----×      ×----- \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t ----+        +---- \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t ---×    G     ×--- \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t --+   Ga       +-- \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t -×   Gam       ×- \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t +   Game        + \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t ×  Game O       × \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t + Game Ov       + \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t ×   Game Ove    × \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t +    Game Over  + \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t ×     Game Over × \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t +    Game Over  + \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t ×   Game Over   × \n\n";
			clrscr();
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t +  Game Over    + \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t × Game Over     × \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t + Game Over     + \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t ×  Game Over    × \n\n";
			usleep(40000);
			usleep(40000);
			usleep(40000);
			usleep(40000);
			clrscr();
			cout << upperLine;
			cout << "\n\n\n\t ×  Game Over !  × \n\n";
			cout << "\n\n\t Want to play again?\n\t (y for yes, n for no)\n";
			
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
			
			while(run == false)
			{
				i = getch();
				
			if(i == 121)
		{
			run = true;
			isRunAgain = true;
			goBackToMenu = false;
			
			setForNew();
		  lvShow();
		  setForNew();
		}
		else if(i == 110)
		{
			run = true;
			isRunAgain = false;
			startUI = true;
			goBackToMenu = true;
		}
				
			}
			
			
		}
		
	}
	
	void nextLv()
	{
		char i;
		run = false;
		clrscr();
		cout << upperLine;
		cout << "\n";
		cout << upperLine;
		cout << "\n\t\t Level " << lv - 1 << " completed!\n";
		cout << lowerLine;
		cout << "\n";
		cout << lowerLine;
		cout << "\n\n";
		cout << "\t *** Time to go to next level! ***";
		cout << "\n\n( y to play next level )";
		cout << "\n( n to play previous one again )";
		cout << "\n\n(To exit in the level, press ESC and then, y)";
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << lowerLine;
		
		while(run == false)
		{
			i = getch();
			
			if(i == 121)
		{
      lvSet = true;
			isRunAgain = true;
			hp = hp + ((int)(hpSet/2));
			hpTempForLv = hp;
			
			if( is_plSh[0] == true )
			{
				plShVal = plShVal + 10;
			}
			else
			{
			plShValForType[0] = plShValForType[0] + 10;
			}
			
			lvShow();
		}
		else if(i == 110)
		{
			lv = lv - 1;
			lvSet = true;
			isRunAgain = true;
			hp = hpTempForLv;
		  lvShow();
		}
		
		}
		
	}
	
	void shopMenu()
	{
		
		run = false;
		char ex;
		
		bool main = true;
		bool buy = false;
		bool sell = false;
		
		//For Main Menu
		int mainShopPointerSel;
		int maxMainShopPointerSel = 3;
		string pointerSMain[3];
		
		//For Buy Menu
		int shopPointerSel;
		int maxShopPointerSel = totalPow + plShTypes;
		string pointer[totalPow + plShTypes];
		
		//For Sell Menu
		int sellShopPointerSel;
		int maxSellShopPointerSel = totalPow + plShTypes;
		string pointerSSell[totalPow + plShTypes];
	 
	 shopBegin:
	 
	 for(int n = 0; n < maxShopPointerSel; n++)
	 {
	 	
	 	if(shopPointerSel == n)
	 	{
	 		pointer[n] = menuPointer;
	 	}
	 	else
	 	{
	 		pointer[n] = _empty;
	 	}
	 	
	 }
	 
	 for(int n = 0; n < maxMainShopPointerSel; n++)
	 {
	 	
	 	if(mainShopPointerSel == n)
	 	{
	 		pointerSMain[n] = menuPointer;
	 	}
	 	else
	 	{
	 		pointerSMain[n] = _empty;
	 	}
	 	
	 }
	 
	 for(int n = 0; n < maxSellShopPointerSel; n++)
	 {
	 	
	 	if(sellShopPointerSel == n)
	 	{
	 		pointerSSell[n] = menuPointer;
	 	}
	 	else
	 	{
	 		pointerSSell[n] = _empty;
	 	}
	 	
	 }
		
		clrscr();
		
		cout << upperLine;
		
		cout << "\n" << "|||||||||||||~~÷~~×~~ SHOP PLACE ~~×~~÷~~||||||||||||";
		cout << "\n" << wall;
		cout << "\n" << wall << "---------------------------------" << "Your Money:- " << goldInd << gold;
		cout << "\n" << wall;
		
		if(main == true)
		{
			cout << "\n" << wall << "  Want to do some business?";
		cout << "\n" << wall << "  Then, you come to the very right place!";
			int sMsN = 0;
		cout << "\n" << wall;
		cout << "\n" << wall << "\t " << pointerSMain[sMsN] << _empty << "BUY";
		sMsN++;
		cout << "\n" << wall;
		cout << "\n" << wall << "\t " << pointerSMain[sMsN] << _empty << "SELL";
		sMsN++;
		cout << "\n" << wall;
		cout << "\n" << wall << "\t " << pointerSMain[sMsN] << _empty << "EXIT";
		
		cout << "\n" << wall;
		}
		else if(buy == true)
		{
			int sN = 0;
			cout << "\n" << wall << "  [ BUY ] ";
			cout << "\n" << wall;
		cout << "\n" << wall << "\t\tPowers:-";
		cout << "\n" << wall;
		cout << "\n" << wall << "    " << pointer[sN] << _empty << slowPowInd << "  >>    " << slowPow_GetForGold << " for " << goldInd << slowPow_RequireGold;
		sN++;
		cout << "\t " << "~ You have " << slowPowDelay << " ~";
		
		cout << "\n" << wall << "    " << pointer[sN] << _empty << regenerateInd << "  >>    " << regenerate_GetForGold << " for " << goldInd << regenerate_RequireGold;
		sN++;
		cout << "\t " << "~ You have " << regenDelay << " ~";
		
		cout << "\n" << wall << "    " << pointer[sN] << _empty << invulnerableInd << "  >>    " << invulnerable_GetForGold << " for " << goldInd << invulnerable_RequireGold;
		sN++;
		cout << "\t " << "~ You have " << ((int)plVul) << " ~";
		
		cout << "\n" << wall << "    " << pointer[sN] << _empty << nukeInd << "  >>    " << nuke_GetForGold << " for " << goldInd << nuke_RequireGold;
		sN++;
		cout << "\t " << "~ You have " << nukeCount << " ~";
		
		cout << "\n" << wall;
		
		cout << "\n" << wall;
		
		cout << "\n" << wall << "\t\tBullets:-";
		cout << "\n" << wall;
		for(int n = 0; n < plShTypes; n++)
		{
		cout << "\n" << wall << "    " << pointer[sN] << _empty << plSh[n] << "  >>    " << plShType_GetForGold[n] << " for " << goldInd << plShType_RequireGold[n];
		sN++;
		cout << "\t " << "~ You have ";
		
		if(is_plSh[n] == true)
		{
			cout << plShVal;
		}
		else
		{
			cout << plShValForType[n];
		}
		
		cout << " ~";
		}
		cout << "\n" << wall;
		
		cout << "\n" << wall << " (Press ESC to return to the main shop menu)";
		}
		else if(sell == true)
		{
			int SsN = 0;
			cout << "\n" << wall << "  [ SELL ] ";
			cout << "\n" << wall;
		cout << "\n" << wall << "\t\tPowers:-";
		cout << "\n" << wall;
		cout << "\n" << wall << "    " << pointerSSell[SsN] << _empty << slowPowInd << "  >>    " << goldInd << ((int)(slowPow_RequireGold/2)) << " for " << slowPow_GetForGold;
		SsN++;
		cout << "\t " << "~ You have " << slowPowDelay << " ~";
		
		cout << "\n" << wall << "    " << pointerSSell[SsN] << _empty << regenerateInd << "  >>    " << goldInd << ((int)(regenerate_RequireGold/2)) << " for " << regenerate_GetForGold;
		SsN++;
		cout << "\t " << "~ You have " << regenDelay << " ~";
		
		cout << "\n" << wall << "    " << pointerSSell[SsN] << _empty << invulnerableInd << "  >>    " << goldInd << ((int)(invulnerable_RequireGold/2)) << " for " << invulnerable_GetForGold;
		SsN++;
		cout << "\t " << "~ You have " << ((int)plVul) << " ~";
		
		cout << "\n" << wall << "    " << pointerSSell[SsN] << _empty << nukeInd << "  >>    " << goldInd << ((int)(nuke_RequireGold/2)) << " for " << nuke_GetForGold;
		SsN++;
		cout << "\t " << "~ You have " << nukeCount << " ~";
		
		cout << "\n" << wall;
		
		cout << "\n" << wall;
		
		cout << "\n" << wall << "\t\tBullets:-";
		cout << "\n" << wall;
		for(int n = 0; n < plShTypes; n++)
		{
		cout << "\n" << wall << "    " << pointerSSell[SsN] << _empty << plSh[n] << "  >>    " << goldInd << ((int)(plShType_RequireGold[n]/2)) << " for " << plShType_GetForGold[n];
		SsN++;
		cout << "\t " << "~ You have ";
		
		if(is_plSh[n] == true)
		{
			cout << plShVal;
		}
		else
		{
			cout << plShValForType[n];
		}
		
		cout << " ~";
		}
		
		cout << "\n" << wall;
		
		cout << "\n" << wall << " (Press ESC to return to the main shop menu)";
		
		}
		
		cout << "\n" << wall << "\n";
		cout << lowerLine;
		
		cout << "\n";
		
		if(main == true)
		{
			while(run == false)
	{
		ex = getch();
		
		if(ex == 27)
		{
			run = true;
			isRunAgain = true;
		}
		else if(ex == 115)
		{
			
			if(mainShopPointerSel < maxMainShopPointerSel - 1)
			{
			  mainShopPointerSel++;
			}
			else if(mainShopPointerSel >= maxMainShopPointerSel - 1)
			{
				mainShopPointerSel = 0;
			}
			
			clrscr();
			goto shopBegin;
		}
		else if(ex == 119)
		{
			
			if(mainShopPointerSel > 0)
			{
			  mainShopPointerSel--;
			}
			else if(mainShopPointerSel <= 0)
			{
				mainShopPointerSel = maxMainShopPointerSel -1;
			}
			
			clrscr();
			goto shopBegin;
		}
		else if( ex == 111)
		{
			
			if(mainShopPointerSel == 0)
			{
			main = false;
			buy = true;
			sell = false;
			}
			else if(mainShopPointerSel == 1)
			{
			main = false;
			buy = false;
			sell = true;
			}
			else if(mainShopPointerSel == 2)
			{
	 	 run = true;
	 	 isRunAgain = true;
			}
			
			clrscr();
			goto shopBegin;
		}
		
	}
		}
		else if(buy == true)
		{
		while(run == false)
	{
		ex = getch();
		
		if(ex == 111)
		{
			
			if(shopPointerSel == 0 && gold >= slowPow_RequireGold)
			{
				slowPowDelay = slowPowDelay + slowPow_GetForGold;
				
				gold = gold - slowPow_RequireGold;
			}
			else if(shopPointerSel == 1 && gold >= regenerate_RequireGold)
			{
				regenDelay = regenDelay + regenerate_GetForGold;
				
				gold = gold - regenerate_RequireGold;
			}
			else if(shopPointerSel == 2 && gold >= invulnerable_RequireGold)
			{
				((int)(plVul = plVul + invulnerable_GetForGold)) ;
				
				gold = gold - invulnerable_RequireGold;
			}
			else if(shopPointerSel == 3 && gold >= nuke_RequireGold)
			{
				nukeCount = nukeCount + nuke_GetForGold;
				
				gold = gold - nuke_RequireGold;
			}
			
			for(int n = 0; n < plShTypes; n++)
			{
				
				if(
				(shopPointerSel == (n + totalPow))
				&& (gold >= plShType_RequireGold[n])
				&& (plShValForType[n] < plShMaxValForType[n])
				)
				{
					
					if(is_plSh[n] == false)
					{
					plShValForType[n] = plShValForType[n] + plShType_GetForGold[n];
					
					gold = gold - plShType_RequireGold[n];
					
					if(plShValForType[n] > plShMaxValForType[n])
					{
						plShValForType[n] = plShMaxValForType[n];
					}
					
					}
					else if(is_plSh[n] == true)
					{
						plShVal = plShVal + plShType_GetForGold[n];
						
						gold = gold - plShType_RequireGold[n];
						
						if(plShVal > plShMaxValForType[n])
						{
							plShVal = plShMaxValForType[n];
						}
						
						plShValForType[n] = plShVal;
					}
					
				}
				
			}
			
			clrscr();
			goto shopBegin;
		}
		else if(ex == 27)
		{
			clrscr();
			main = true;
			buy = false;
			sell = false;
			
			clrscr();
			goto shopBegin;
		}
		else if(ex == 115)
		{
			
			if(shopPointerSel < maxShopPointerSel - 1)
			{
			  shopPointerSel++;
			}
			else if(shopPointerSel >= maxShopPointerSel - 1)
			{
				shopPointerSel = 0;
			}
			
			clrscr();
			goto shopBegin;
		}
		else if(ex == 119)
		{
			
			if(shopPointerSel > 0)
			{
			  shopPointerSel--;
			}
			else if(shopPointerSel <= 0)
			{
				shopPointerSel = maxShopPointerSel -1;
			}
			
			clrscr();
			goto shopBegin;
		}
		
	}
		}
		else if( sell == true)
		{
			
			while(run == false)
	{
		ex = getch();
		
		if(ex == 111)
		{
			
			if(sellShopPointerSel == 0 && slowPowDelay >= slowPow_GetForGold)
			{
				gold = gold + ((int)(slowPow_RequireGold/2));
				
				slowPowDelay = slowPowDelay - slowPow_GetForGold;
			}
			else if(sellShopPointerSel == 1 && regenDelay >= regenerate_GetForGold)
			{
				gold = gold + ((int)(regenerate_RequireGold/2));
				
				regenDelay = regenDelay - regenerate_GetForGold;
			}
			else if(sellShopPointerSel == 2 && ((int)plVul) >= invulnerable_GetForGold)
			{
				gold = gold + ((int)(invulnerable_RequireGold/2));
				
				((int)(plVul = plVul - invulnerable_GetForGold)) ;
			}
			else if(sellShopPointerSel == 3 && nukeCount >= nuke_GetForGold)
			{
				gold = gold + ((int)(nuke_RequireGold/2));
				
				nukeCount = nukeCount - nuke_GetForGold;
			}
			
			for(int n = 0; n < plShTypes; n++)
			{
				
				if(
				(sellShopPointerSel == (n + totalPow))
				&& (plShValForType[n] >= plShType_GetForGold[n])
				&& (is_plSh[n] == false)
				)
				{
					
					plShValForType[n] = plShValForType[n] - plShType_GetForGold[n];
					
					gold = gold + ((int)(plShType_RequireGold[n]/2));
					
					}
					else if(
				(sellShopPointerSel == (n + totalPow))
				&& (plShVal >= plShType_GetForGold[n])
				&& (is_plSh[n] == true)
				)
					{
						plShVal = plShVal - plShType_GetForGold[n];
						
						gold = gold + ((int)(plShType_RequireGold[n]/2));
						
						plShValForType[n] = plShVal;
					}
					
				}
			
			clrscr();
			goto shopBegin;
		}
		else if(ex == 27)
		{
			main = true;
			buy = false;
			sell = false;
			
			clrscr();
			goto shopBegin;
		}
		else if(ex == 115)
		{
			
			if(sellShopPointerSel < maxSellShopPointerSel - 1)
			{
			  sellShopPointerSel++;
			}
			else if(sellShopPointerSel >= maxSellShopPointerSel - 1)
			{
				sellShopPointerSel = 0;
			}
			
			clrscr();
			goto shopBegin;
		}
		else if(ex == 119)
		{
			
			if(sellShopPointerSel > 0)
			{
			  sellShopPointerSel--;
			}
			else if(sellShopPointerSel <= 0)
			{
				sellShopPointerSel = maxSellShopPointerSel -1;
			}
			
			clrscr();
			goto shopBegin;
		}
		
	}
		}
		
	}
	
	void endGame()
	{
	if(lv == maxLv)
{
	cout << upperLine;
	cout << "\n\n\n\n\n\n\n\n";
	cout << "\n\n * * * * * CONGRATULATIONS * * * * * \n\n";
	for( int again = 0; again < 40; again++)
	{
	usleep(40000);
	}
	cout << " + + + You completed the game + + + \n\n";
	for( int again = 0; again < 40; again++)
	{
	usleep(40000);
	}
	clrscr();
	cout << upperLine;
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~Credits~~~~~~~~~~~~~~~~~~~~~~~";
	for( int again = 0; again < 40; again++)
	{
	usleep(40000);
	}
	clrscr();
	cout << upperLine;
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	cout << " PROGRAMMER\n";
	cout << "\tBilal Cheema\n";
	for( int again = 0; again < 40; again++)
	{
	usleep(40000);
	}
	clrscr();
	cout << upperLine;
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\n Special thanks to:\n\n";
	for( int again = 0; again < 40; again++)
	{
	usleep(40000);
	}
	clrscr();
	cout << upperLine;
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	cout << " TEACHERS\n";
	cout << "\tJohn Purcell\n";
	cout << "\tLazy Foo'\n";
	for( int again = 0; again < 40; again++)
	{
	usleep(40000);
	}
	clrscr();
	cout << upperLine;
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	cout << " INSPIRED BY\n";
	cout << "\tChilliTomatoSauce YouTube\n";
	for( int again = 0; again < 40; again++)
	{
	usleep(40000);
	}
	clrscr();
	cout << upperLine;
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t• I hope you enjoyed it! •";
	cout << "\n\n\n - Terminated - \n";
	usleep(100000);
}
else
{
 escMenu();
	
}

	}
	
	void devNumbers()
	{
		run = false;
		char ex;
		
			cout << "\n DEV ONLY: \n";
cout << "\n  checkBool: ";
if( checkBool == false)
{
	cout << "false";
}
else if( checkBool == true)
{
	cout << "true";
}

cout << "\n check0: " << check0;
cout << "\n check1: " << check1;
cout << "\n check2: " << check2;
cout << "\n check3: " << check3;
cout << "\n check4: " << check4;
cout << "\n check5: " << check5;
cout << "\n check6: " << check6;
cout << "\n check7: " << check7;
cout << "\n check8: " << check8;
cout << "\n check9: " << check9;

 cout << "\n\n   (Enter 'n' again, to resume) \n\n";
			
	while(run == false)
	{
		ex = getch();
	 
	 if(ex == 110)
		{
			run = true;
			isRunAgain = true;
		}
		
	}
	
	}