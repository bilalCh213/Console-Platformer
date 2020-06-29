
void startUp()
{
	
	//all temporary start UI variables
	
	string pxUI[width][height];
	
	char in;
	
	bool showMenu = false;
	int delayToMenu = 250;
	
	int bacW = 18;
	int bacH = 11;
	
	string bl0 = _floor;
	string bl1 = roof;
	string block = bl0;
	int blChDelay = 0;
	int blChMaxDelay = 10;
	
	string animEnt = plDis;
	int anEnW = 5;
	int LMax = width - 5;
	bool toR = false;
	int RMax = 5;
	bool toL = true;
	int anEnH = height - 3;
	int animEntDelay = 0;
	int animEntMaxDelay = 10;
	
	int showRandW = 0;
	int showRandH = 0;
	int showRandDelay = 0;
	int maxShowRandDelay = 100;
	int tileChoose = 0;
	
	int optW = 24;
	int optH = 12;
	int optPointerOn = 0;
	int maxOptPointerOn = 2;
	
	int tParts_move = 1;
	int tParts = 15;
	int wAlp = 11;
	int hAlp = 10;
	
	int c_posCont = 4;
	
	int r_w[tParts] = { 12,11,10,9,8,0,0,0,0,8,9,10,11,12,52 };
	int r_h[tParts]= { 0,0,0,0,0,8,9,10,11,21,21,21,21,21,12 };
	int r_w_des[tParts] = { 12,11,10,9,8,7,7,7,7,8,9,10,11,12,13 };
	int r_h_des[tParts] = { 8,7,7,7,7,8,9,10,11,12,13,13,13,13,12 };
	
	for(int n = 0; n < tParts; n++)
	{
		
		if(
		(r_w[n] != 0)
		&& (r_w[n] != 52)
		)
		{
		r_w[n] = r_w[n] + c_posCont;
		}
		
		r_w_des[n] = r_w_des[n] + c_posCont;
		
	}
	
	wAlp = wAlp + c_posCont;
	
	int tPParts_move = 1;
	int tPParts = 15;
	int wPAlp = 37;
	int hPAlp = 10;
	
	int p_posCont = 3;
	
	int p_w[tPParts] = { 32,33,34,52,52,34,33,32,0,0,0,0,0,0,0 };
	int p_h[tPParts] = { 21,21,21,9,8,0,0,0,7,8,9,10,11,12,13 };
	int p_w_des[tPParts] = { 32,33,34,35,35,34,33,32,31,31,31,31,31,31,30 };
	int p_h_des[tPParts] = { 10,10,10,9,8,7,7,7,7,8,9,10,11,12,13 };
	
	for(int n = 0; n < tPParts; n++)
	{
		
		if(
		(p_w[n] != 0)
		&& (p_w[n] != 52)
		)
		{
		p_w[n] = p_w[n] - p_posCont;
		}
		
		p_w_des[n] = p_w_des[n] - p_posCont;
		
	}
	
	wPAlp = wPAlp - p_posCont;
	
	int doMoreUI = 0;
	int moreUI = 100;
	bool runMoreUI = false;
	bool runInhibitor = false;
	bool runMainMenu = false;
	
	int deterUp = - 5;
	
	//end of variables
	
	while(startUI)
	{
		
		if(goBackToMenu == true)
		{
			
		    runMoreUI = true;
				runMainMenu = true;
				showMenu = true;
				
				for(int n = 0; n < tParts; n++)
				{
					r_w[n] = r_w_des[n];
					r_h[n] = r_h_des[n];
				}
				
				for(int n = 0; n < tPParts; n++)
				{
					p_w[n] = p_w_des[n];
					p_h[n] = p_h_des[n];
				}
				
				goBackToMenu = false;
		}
		
  int pointerW = optW - 2;
	int pointerH = optH + (optPointerOn * 2);
		
		for (int yEmp = 0; yEmp < height -1; yEmp++)
		{
			for (int xEmp = 0; xEmp < width - 1; xEmp++)
			{
				pxUI[xEmp][yEmp] = notSolid[0];
			}
		} 
		
		if(showMenu == false)
		{
		pxUI[bacW - 2][bacH] = "~";
		
		pxUI[bacW][bacH] = "B";
		pxUI[bacW + 1][bacH] = "A";
		pxUI[bacW + 2][bacH] = "C";
		
		pxUI[bacW + 4][bacH] = "D";
		pxUI[bacW + 5][bacH] = "e";
		pxUI[bacW + 6][bacH] = "v";
		pxUI[bacW + 7][bacH] = "e";
		pxUI[bacW + 8][bacH] = "l";
		pxUI[bacW + 9][bacH] = "o";
		pxUI[bacW + 10][bacH] = "p";
		pxUI[bacW + 11][bacH] = "m";
		pxUI[bacW + 12][bacH] = "e";
		pxUI[bacW + 13][bacH] = "n";
		pxUI[bacW + 14][bacH] = "t";
		
		pxUI[bacW + 16][bacH] = "~";
		
		delayToMenu--;
		
		if(delayToMenu <= 0)
		{
			showMenu = true;
		}
		
		}
		else if(showMenu == true)
		{
			
		if(blChDelay <= 0)
		{
			
		if( block == bl0 )
		{
			block = bl1;
		}
		else if( block == bl1 )
		{
			block = bl0;
		}
		
		blChDelay = blChMaxDelay;
		}
		else if(blChDelay > 0)
		{
			blChDelay--;
		}
		
		for(int n = 0; n < tParts_move; n++)
		{
			
		if(r_w[n] < r_w_des[n])
		{
			r_w[n]++;
		}
		else if(r_w[n] > r_w_des[n])
		{
			r_w[n]--;
		}
	  else if(r_h[n] < r_h_des[n])
		{
			r_h[n]++;
		}
		else if(r_h[n] > r_h_des[n])
		{
			r_h[n]--;
		}
		
		}
	
	pxUI[r_w[0]][r_h[0]] = block;
	
	for(int no = 0; no < tParts - 1; no++)
	{
		
	if(r_w[no] == r_w_des[no] && r_h[no] == r_h_des[no])
	{
		pxUI[r_w[no + 1]][r_h[no + 1]] = block;
		tParts_move = no + 2;
	}

	}
	
	if(pxUI[r_w_des[tParts - 1]][r_h_des[tParts - 1]] == block)
	{
		
	    pxUI[wAlp][hAlp] = "o";
			pxUI[wAlp + 1][hAlp] = "n";
			pxUI[wAlp + 2][hAlp] = "s";
			pxUI[wAlp + 3][hAlp] = "o";
			pxUI[wAlp + 4][hAlp] = "l";
			pxUI[wAlp + 5][hAlp] = "e";
		
	}
	
	if(pxUI[wAlp + 5][hAlp] == "e")
	{
		
		for(int n = 0; n < tPParts_move; n++)
		{
			
		if(p_w[n] < p_w_des[n])
		{
			p_w[n]++;
		}
		else if(p_w[n] > p_w_des[n])
		{
			p_w[n]--;
		}
	  else if(p_h[n] < p_h_des[n])
		{
			p_h[n]++;
		}
		else if(p_h[n] > p_h_des[n])
		{
			p_h[n]--;
		}
		
		}
		
		pxUI[p_w[0]][p_h[0]] = block;
	
	for(int no = 0; no < tPParts - 1; no++)
	{
		
	if(p_w[no] == p_w_des[no] && p_h[no] == p_h_des[no])
	{
		pxUI[p_w[no + 1]][p_h[no + 1]] = block;
		tPParts_move = no + 2;
	}

	}
	
	if(pxUI[p_w_des[tPParts - 1]][p_h_des[tPParts - 1]] == block)
	{
		
	    pxUI[wPAlp][hPAlp] = "l";
			pxUI[wPAlp + 1][hPAlp] = "a";
			pxUI[wPAlp + 2][hPAlp] = "t";
			pxUI[wPAlp + 3][hPAlp] = "f";
			pxUI[wPAlp + 4][hPAlp] = "o";
			pxUI[wPAlp + 5][hPAlp] = "r";
			pxUI[wPAlp + 6][hPAlp] = "m";
			pxUI[wPAlp + 7][hPAlp] = "e";
			pxUI[wPAlp + 8][hPAlp] = "r";
		
	}
		
	}
	
	if(
	(pxUI[wPAlp + 8][hAlp] == "r")
	&& (runInhibitor == false)
	)
	{
		
		if(doMoreUI < moreUI)
		{
			doMoreUI++;
		}
		else if(doMoreUI >= moreUI)
		{
			runMoreUI = true;
			runMainMenu = true;
		}
		
	}
	
	if(runMoreUI == true)
	{
		
		for(int n = 0; n < tParts; n++)
		{
			
			r_h_des[n] = r_h_des[n] + deterUp;
			
		}
		
		hAlp = hAlp + deterUp;
		
		for(int n = 0; n < tPParts; n++)
		{
			
			p_h_des[n] = p_h_des[n] + deterUp;
			
		}
		
		hPAlp = hPAlp + deterUp;
		
		runInhibitor = true;
		runMoreUI = false;
	}
	
	if(runMainMenu)
	{
		
		pxUI[anEnW][anEnH] = animEnt;
		
		if(animEntDelay <= 0)
		{
			
		if( toR == true)
		{
			anEnW--;
			
			if(anEnW == RMax)
			{
				toR = false;
				toL = true;
			}
			
		}
		else if( toL == true)
		{
			anEnW++;
			
			if(anEnW == LMax)
			{
				toL = false;
				toR = true;
			}
			
		}
		
		animEntDelay = animEntMaxDelay;
		
		}
		else if(animEntDelay > 0)
		{
			animEntDelay--;
		}
		
		pxUI[optW][optH] = "P";
		pxUI[optW + 1][optH] = "L";
		pxUI[optW + 2][optH] = "A";
		pxUI[optW + 3][optH] = "Y";
		
		pxUI[optW][optH + 2] = "H";
		pxUI[optW + 1][optH + 2] = "E";
		pxUI[optW + 2][optH + 2] = "L";
		pxUI[optW + 3][optH + 2] = "P";
		
		pxUI[optW][optH + 4] = "Q";
		pxUI[optW + 1][optH + 4] = "U";
		pxUI[optW + 2][optH + 4] = "I";
		pxUI[optW + 3][optH + 4] = "T";
		
		pxUI[pointerW][pointerH] = menuPointer;
		
		int showW = showRandW;
		int showH = showRandH;
		
		if(showRandDelay <= 12)
		{
		int showW = showRandW;
		int showH = showRandH;
		
		if(showRandDelay <= 4)
		{
		pxUI[showW + 2][showH] = "*";
  	pxUI[showW + 1][showH + 1] = "*";
  	pxUI[showW][showH + 2] = "*";
		}
		else if(showRandDelay <= 12)
		{
  		pxUI[showW + 2][showH] = "/";
  		pxUI[showW + 1][showH + 1] = "/";
  		pxUI[showW][showH + 2] = "/";
		}
		
		showRandDelay--;
		
		if(showRandDelay <= 0)
		{
		showRandDelay = maxShowRandDelay;
		}
		
		}
		else if(showRandDelay > 0)
		{
		showRandW = rand() % (width - 10);
		showRandH = rand() % (height - 3);
		
		showRandDelay--;
		}
		
		for(int n = -1; n < 6; n++)
		{
			pxUI[optW - 4][optH + n] = wall;
			pxUI[optW + 7][optH + n] = wall;
		}
		
		for (int plat2 = 0; plat2 < width; plat2++)
		{
			pxUI[plat2][0] = roof;
		}
		
		for (int plat1 = 0; plat1 < width; plat1++)
		{
		 pxUI[plat1][height - 2] = _floor;
		}
		
	}
	
		}
		
		if(kbhit())
		{
			in = getch();
			
			if(in == 27)  //ESC
			{
				
				runMoreUI = true;
				runMainMenu = true;
				showMenu = true;
				
				for(int n = 0; n < tParts; n++)
				{
					r_w[n] = r_w_des[n];
					r_h[n] = r_h_des[n];
				}
				
				for(int n = 0; n < tPParts; n++)
				{
					p_w[n] = p_w_des[n];
					p_h[n] = p_h_des[n];
				}
				
			}
			else if( in == 111 && runMainMenu == true )
			{
				
				if(optPointerOn == 0)
				{
					goBackToMenu = false;
					startUI = false;
					
					setForNew();
					lvShow();
					setForNew();
				}
				else if(optPointerOn == 1)
				{
					startUI = false;
					gameHelp();
					startUI = true;
				}
				else if(optPointerOn == 2)
				{
					startUI = false;
					run = false;
					isRunAgain = false;
					goBackToMenu = true;
					hp = 1;
				}
				
			}
			else if( in == 119 && runMainMenu == true )
			{
				
				if(optPointerOn > 0)
				{
				optPointerOn--;
				}
				else if(optPointerOn <= 1)
				{
					optPointerOn = maxOptPointerOn;
				}
				
			}
			else if(in == 115 && runMainMenu == true )
			{
				
				if(optPointerOn < maxOptPointerOn)
				{
					optPointerOn++;
				}
				else if(optPointerOn >= maxOptPointerOn - 1)
				{
					optPointerOn = 0;
				}
				
			}
			else
			{
				
				if(delayToMenu > 0)
				{
				delayToMenu = 0;
				}
				else if(doMoreUI < moreUI)
				{
					doMoreUI = moreUI;
					
					for(int n = 0; n < tParts; n++)
				{
					r_w[n] = r_w_des[n];
					r_h[n] = r_h_des[n];
				}
				
				for(int n = 0; n < tPParts; n++)
				{
					p_w[n] = p_w_des[n];
					p_h[n] = p_h_des[n];
				}
				
				}
				
			}
			
		}
	
	usleep(UI_frameDelay);

		clrscr();				// Must be at start

		for (int y = 0; y < height - 1; y++)
		{
			for (int x = 0; x < width - 1; x++)
			{
				cout << pxUI[x][y];
			}
			cout << "\n";
		}
		
	}
}