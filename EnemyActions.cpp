
/*
FUNCTIONS FOR FRAMERUNNER:
eShootAI();
eShootSet();
eGetDamage();
eMoveAIRunner();

FUNCTIONS FOR INTERNAL USE:
eMoveRight(int);
eMoveLeft(int);
eMoveUp(int);
eMoveDown(int);
eJump();
eRandMove(int);
Right_Up_ConstMove(int);
Left_Up_ConstMove(int);
eConstMove(int);
ePlatMove(int);
eGetLoot(int);
*/

using namespace std;

		//Enemy Movements
		void eMoveRight(int n)
		{
			if(
			(e_emptyAt_r[n] == true)
			&& (e_emptyAt_r_forE[n] == true)
			)
			{
				eW[n]++;
				
				e_emptyAt_r[n] = false;
				e_emptyAt_wall_r[n] = false;
				e_emptyAt_upAbove[n] = false;
				e_emptyAt_r_forE[n] = false;
				e_emptyAt_l_forE[n] = false;
			}
		}
		void eMoveLeft(int n)
		{
			if(
			(e_emptyAt_l[n] == true)
			&& (e_emptyAt_l_forE[n] == true)
			)
			{
				eW[n]--;
				
				e_emptyAt_l[n] = false;
				e_emptyAt_wall_l[n] = false;
				e_emptyAt_upAbove[n] = false;
				e_emptyAt_l_forE[n] = false;
				e_emptyAt_r_forE[n] = false;
			}
		}
		void eMoveUp(int n)
		{
			if(e_emptyAt_u[n] == true)
			{
				eH[n]--;
				
				e_emptyAt_u[n] = false;
				e_emptyAt_upAbove[n] = false;
			}
		}
		void eMoveDown(int n)
		{
			if(e_emptyAt_d[n] == true)
			{
				eH[n]++;
				
				e_emptyAt_d[n] = false;
			}
		}
		
		//Enemy Jump
		void e_Jump()
		{
				
			for( int n = 0; n < eNumb; n++)
			{
				
				if(eJumpDelay[n] <= 0)
				{
			if(eJump[n] == true && e_emptyAt_u[n] == true)
		{
			
			if(eJumpTime[n] <= 0)
			{
				eJump[n] = false;
			}
			else if(eJumpTime[n] <= eJumpMoveNumb[n] && eJumpTime[n] != 0)
			{
				eMoveUp(n);
				
				if( eDir[n] == "r")
				{
				eMoveRight(n);
				}
				else if( eDir[n] == "l")
				{
				eMoveLeft(n);
				}
				
			}
			else if( eJumpTime[n] > eJumpMoveNumb[n] )
			{
				eMoveUp(n);
			}
			
			eJumpTime[n] = eJumpTime[n] - 1;
		}
		else if(e_emptyAt_u[n] == false)
		{
			eJumpTime[n] = 0;
			eJump[n] = false;
		}
		
		eJumpDelay[n] = maxJumpDelay;
		}
		else if(eJumpDelay[n] > 0)
		{
			eJumpDelay[n]--;
		}
		
			}
		
		}
		
		//Enemy Random Move
		void eRandMove(int n)
		{
			 
  	if(eHp[n] > 0)
  	{
  		
  	//eRand[n]:
  	//0 for right, 6 for left, 5 for jump, -1 for down.
  	eRand[n] = rand() % 10;
  	
  	if(
  	(e_emptyAt_d_r[n] == true)
  	)
  	{
  		
  		if(eRand[n] >= 0 && eRand[n] <= 4)
  		{
  			eRand[n] = 6;
  		}
  		else if(eRand[n] >= 5 && eRand[n] <= 9)
  		{
  			eDir[n] = "r";
  			eRand[n] = 5;
  		}
  		
  	}
  	else if(
  	(e_emptyAt_d_l[n] == true)
  	)
  	{
  		
  		if(eRand[n] >= 0 && eRand[n] <= 4)
  		{
  			eRand[n] = 0;
  		}
  		else if(eRand[n] >= 5 && eRand[n] <= 9)
  		{
  			eDir[n] = "l";
  			eRand[n] = 5;
  		}
  		
  	}
  	else if(
  	(e_emptyAt_r[n] == false)
  	&& (e_emptyAt_l[n] == false)
  	&& (e_emptyAt_u[n] == false)
  	&& (e_emptyAt_d[n] == true)
  	)
  	{
  		eRand[n] = -1;
  	}
  	else if(
  	(e_emptyAt_r[n] == false)
  	&& (e_emptyAt_l[n] == false)
  	&& (e_emptyAt_u[n] == true)
  	&& (e_emptyAt_d[n] == false)
  	)
  	{
  		
  		if(eRand[n] >= 0 && eRand[n] <= 4)
  		{
  			eDir[n] = "r";
  		}
  		else if(eRand[n] >= 5 && eRand[n] <= 9)
  		{
  			eDir[n] = "l";
  		}
  		
  		eRand[n] = 5;
  	}
  	else if(
  	(e_emptyAt_r[n] == false)
  	&& (e_emptyAt_l[n] == true)
  	)
  	{
  		
  		if(eRand[n] >= 0 && eRand[n] <= 5)
  		{
  			eRand[n] = 6;
  		}
  		else if(eRand[n] >= 6 && eRand[n] <= 9)
  		{
  			
  			if(eRand[n] == 6 || eRand[n] == 8)
  			{
  			eDir[n] = "l";
  			}
  			else if(eRand[n] == 7 || eRand[n] == 9)
  			{
  				eDir[n] = "r";
  			}
  			
  			eRand[n] = 5;
  		}
  		
  	}
  	else if(
  	(e_emptyAt_r[n] == true)
  	&& (e_emptyAt_l[n] == false)
  	)
  	{
  		
  		if(eRand[n] >= 0 && eRand[n] <= 5)
  		{
  			eRand[n] = 0;
  		}
  		else if(eRand[n] >= 6 && eRand[n] <= 9)
  		{
  			
  			if(eRand[n] == 6 || eRand[n] == 8)
  			{
  			eDir[n] = "l";
  			}
  			else if(eRand[n] == 7 || eRand[n] == 9)
  			{
  				eDir[n] = "r";
  			}
  			
  			eRand[n] = 5;
  		}
  		
  	}
  	
  	for( int w = 0; w < eEyeRangeNumb[n]; w++ )
  		{
  			
  			if(
  			( eH[n] == plH )
  			&& ( eW[n] + w == plW )
  			&& ( e_emptyAt_wall_r[n] == true )
  			)
  			{
  				eRand[n] = 0;
  			}
  			else if(
  			( eH[n] == plH )
  			&& ( eW[n] - w == plW )
  			&& ( e_emptyAt_wall_l[n] == true )
  			)
  			{
  				eRand[n] = 6;
  			}
  			
  		}	
  
   if(eMoveTimes[n] > 0)
  {
  	
  	if( eDir[n] == "r" )
  	{
  	eMoveRight(n);
  	}
  	else if( eDir[n] == "l" )
  	{
  		eMoveLeft(n);
  	}
  	eMoveTimes[n] = eMoveTimes[n] - 1;
  	
  		eDelay[n] = eMaxDelay;
  	
  }
  else if( eDelay[n] > 0)
  {
  	//Do nothing
  	eDelay[n] = eDelay[n] - eDelaySub[n];
  	
  }
  else if( eMoveTimes[n] == 0 && eDelay[n] <= 0 )
  {
  	
  if(
  (eRand[n] >= 0 && eRand[n] <= 4)
  )
  {
  	eMoveTimes[n] = eMaxMoveTimesNumb[n];
  	eDir[n] = "r";
  }
  else if(
  (eRand[n] >= 6 && eRand[n] <= 9)
  )
  {
  	eMoveTimes[n] = eMaxMoveTimesNumb[n];
  	eDir[n] = "l";
  }
  else if(
  (eRand[n] == 5)
  )
  {
  	
  	if(eJumpForce[n] == true)
  	{
  	eJump[n] = true;
  	eJumpTime[n] = set_eJumpTimeNumb[n];
  	}
  	
  }
  else if(
  (eRand[n] == -1)
  )
  {
  	eMoveDown(n);
  }
  
  eDelay[n] = 0;
  }
  
  }
  
				}
		
		void Right_Up_ConstMove(int n)
		{
			eDir[n] = "r";
			
					if(
					(e_emptyAt_wall_r[n] == true)
					&& (e_emptyAt_r[n] == true)
					)
					{
						 eMoveRight(n);
					}
					else if(
					(e_emptyAt_r[n] == false)
					&& (eH[n] >= plH)
					)
						 {
						 	
						 	if(eJumpForce[n] == true)
						 	{
						 	eJump[n] = true;
             	eJumpTime[n] = set_eJumpTimeNumb[n];
						 }
             	
						 }
						 
		}
		
		void Left_Up_ConstMove(int n)
		{
			eDir[n] = "l";
			
					if(
					(e_emptyAt_wall_l[n] == true)
					&& (e_emptyAt_l[n] == true)
					)
					{
						 eMoveLeft(n);
					}
					else if (
					(e_emptyAt_l[n] == false)
					&& (eH[n] >= plH)
					)
						 {
						 	
						 	if(eJumpForce[n] == true)
						 	{
						 	eJump[n] = true;
             	eJumpTime[n] = set_eJumpTimeNumb[n];
						 }
						 
					}
				
		}
		
    void eConstMove(int n)
    {
    	
					if( eConstDelay[n] <= 0)
		{
				
				constRand[n] = rand() % 10;
				
				for (int ih = height; ih > 0; ih--)
				{
				for (int iw = width; iw > 0; iw--)
				{
					
				if(
				(eW[n] + iw == plW)
				&& (eH[n] + ih == plH)
				//Down-Right Player
				)
				{
					eDir[n] = "r";
					
						if(e_emptyAt_d[n] == true)
						{
							eMoveDown(n);
						}
						else if(e_emptyAt_d[n] == false)
						{
						Right_Up_ConstMove(n);
						}
					
				}
				else if(
				(eW[n] - iw == plW)
				&& (eH[n] - ih == plH)
				//Up-Left Player
				)
				{
					eDir[n] = "l";
					
				if(e_emptyAt_upAbove[n] == true)
				{
					
					if(eJumpForce[n] == true)
						 	{
						 	eJump[n] = true;
             	eJumpTime[n] = set_eJumpTimeNumb[n];
						 }
						 
				}
				else
				{
				Left_Up_ConstMove(n);
				}
				
				}
				else if(
				(eW[n] + iw == plW)
				&& (eH[n] - ih == plH)
				//Up-Right Player
				)
				{
					eDir[n] = "r";
					
					if(e_emptyAt_upAbove[n] == true)
				{
					
					if(eJumpForce[n] == true)
						 	{
						 	eJump[n] = true;
             	eJumpTime[n] = set_eJumpTimeNumb[n];
						 }
						 
				}
				else
				{
				Right_Up_ConstMove(n);
				}
				
				}
				else if(
				(eW[n] - iw == plW)
				&& (eH[n] + ih == plH)
				//Down-Left Player
				)
				{
					eDir[n] = "l";
					
				    for( int i = eW[n]; i > plW; i-- )
				{
				
						if(e_emptyAt_d[n] == true)
						{
							eMoveDown(n);
						}
						else if(e_emptyAt_d[n] == false)
						{
						Left_Up_ConstMove(n);
						}
						
					}
					
				}
				
				}
				
			}
		
					for( int i = 0; i < height; i++)
			{
				
				if(
				(eH[n] + i == plH)
				&& (eW[n] == plW)
				//Down Player
				)
				{
					
					  if(e_emptyAt_d[n] == true)
				{
					eMoveDown(n);
				}
				else
				{
					
					if(
					(e_emptyAt_r[n] == true)
					&& (constRand[n] >= 0 && constRand[n] <=4)
					)
					{
					Right_Up_ConstMove(n);
					}
					else if(
					(e_emptyAt_l[n] == true)
					&& (constRand[n] >= 5 && constRand[n] <=9)
					)
					{
						Left_Up_ConstMove(n);
					}
					
				}
				
				}
				else if(
				(eH[n] - i == plH)
				&& (eW[n] == plW)
				//Up Player
				)
				{
					
					  if(e_emptyAt_u[n] == true)
				{
					if(eJumpForce[n] == true)
						 	{
						 	eJump[n] = true;
             	eJumpTime[n] = set_eJumpTimeNumb[n];
						 }
				}
				else
				{
					if(
					(e_emptyAt_r[n] == true)
					&& (constRand[n] >= 0 && constRand[n] <=4)
					)
					{
					Right_Up_ConstMove(n);
					}
					else if(
					(e_emptyAt_l[n] == true)
					&& (constRand[n] >= 5 && constRand[n] <=9)
					)
					{
						Left_Up_ConstMove(n);
					}
				}
				
				}
				
			}
				
				for( int i = 0; i < width; i++)
				{
					
				if(
				(eH[n] == plH)
				&& (eW[n] + i == plW)
				//Right Player
				)
				{
		       Right_Up_ConstMove(n);
				}
				else if(
				(eH[n] == plH)
				&& (eW[n] - i == plW)
				//Left Player
				)
				{
					 Left_Up_ConstMove(n);
				}
				
				}
		
		eConstDelay[n] = eMaxConstDelay;
		}
		else if( eConstDelay[n] > 0)
		{
			eConstDelay[n] = eConstDelay[n] - eConstDelaySub[n];
		}

		}
		
		void ePlatMove(int n)
		{
			
			if( ePlatDelay[n] <= 0 )
			{
				
				if(
				(e_emptyAt_d_r[n] == true)
				|| (e_emptyAt_r[n] == false)
				)
				{
					doPatrol[n] = false;
				}
				else if(
				(e_emptyAt_d_l[n] == true)
				|| (e_emptyAt_l[n] == false)
				)
				{
					doPatrol[n] = true;
				}
				
				for(int i = 0; i < width; i++)
				{
					
					if(doPatrol[n] == false)
				{
					
				if(
				(eW[n] + i == plW)
				&& (eH[n] == plH)
				&& (e_emptyAt_wall_r[n] == true)
				&& (
				(e_emptyAt_d_r[n] == false)
				|| (e_emptyAt_r[n] == true)
				)
				)
				{
					eDir[n] = "r";
					eMoveRight(n);
				}
				if(
				(eW[n] - i == plW)
				&& (eH[n] == plH)
				&& (e_emptyAt_wall_l[n] == true)
				&& (
				(e_emptyAt_d_l[n] == false)
				|| (e_emptyAt_l[n] == true)
				)
				)
				{
					eDir[n] = "l";
					eMoveLeft(n);
				}
					else if(e_emptyAt_l[n] == true)
					{
						eDir[n] = "l";
						eMoveLeft(n);
					}
					
				}
				else if(doPatrol[n] == true)
				{
					
				if(
				(eW[n] - i == plW)
				&& (eH[n] == plH)
				&& (e_emptyAt_wall_l[n] == true)
				&& (
				(e_emptyAt_d_l[n] == false)
				|| (e_emptyAt_l[n] == true)
				)
				)
				{
					eDir[n] = "l";
					eMoveLeft(n);
				}
				else if(
				(eW[n] + i == plW)
				&& (eH[n] == plH)
				&& (e_emptyAt_wall_r[n] == true)
				&& (
				(e_emptyAt_d_r[n] == false)
				|| (e_emptyAt_r[n] == true)
				)
				)
				{
					eDir[n] = "r";
					eMoveRight(n);
				}
					else if(e_emptyAt_r[n] == true)
					{
						eDir[n] = "r";
						eMoveRight(n);
					}
				 
				}
				
				}
				
				ePlatDelay[n] = eMaxPlatDelay;
				
			}
			else if( ePlatDelay[n] > 0 )
			{
				ePlatDelay[n] = ePlatDelay[n] - ePlatDelaySub[n];
			}
			
		}
		
		// Enemy Looting
		void eGetLoot()
		{
			for(int n = 0; n < eNumb; n++)
			{
				
			if( eHp[n] <= 0 && px[eW[n]][eH[n]] == zeroShow )
			{
				
			if(eLoot[n] == false)
			{
				
			if(e_give_slowPowNumb[n] == true)
			{
				slowPowDelay = slowPowDelay + e_giveVal_slowPowNumb[n];
			}
			
			if(e_give_regenerateNumb[n] == true)
			{
				regenDelay = regenDelay + e_giveVal_regenerateNumb[n];
			}
			
			if(e_give_invulnerableNumb[n] == true)
			{
				plVul = plVul + e_giveVal_invulnerableNumb[n];
			}
			
			if(e_give_nukeNumb[n] == true)
			{
				nukeCount = nukeCount + e_giveVal_nukeNumb[n];
			}
			
			gold = gold + e_giveVal_goldNumb[n];
			
			for(int type = 0; type < plShTypes; type++)
			{
			
			if(e_give_plShNumb[type][n] == true)
			{
				
				if(is_plSh[type] == true)
				{
					plShVal = plShVal + e_giveVal_plShNumb[n];
				}
				else
				{
				plShValForType[type] = plShValForType[type] + e_giveVal_plShNumb[n];
  			}
  			
			}
			
			}
			
			eLoot[n] = true;
			
			}
			
			}
			
		}
		
		}
		
		//Enemy Shoot AI
		void eShootAI()
		{
			
			for( int n = 0; n < eNumb; n++)
			{
				for( int b = 0; b < eShLimit; b++)
				{
				
				if(eShAgainDelay[n] <= 0 && eShoot[n][b] == false)
				{
					
			for( int inc = 0; inc < eEyeRangeNumb[n]; inc++)
			{
				
			if(
			(eW[n] + inc == plW)
			&& (eH[n] == plH)
			&& (e_emptyAt_wall_r[n] == true)
			&& (eDir[n] == "r")
			&& (eShoot[n][b] == false)
			&& (e_notSolid_r[n] == true)
			&& (px[eW[n]][eH[n]] != zeroShow)
			&& (px[eW[n]][eH[n]] != notSolid[0])
			&& (eRun[n] == true)
			&& (eDisplayDelay <= 0)
			)
		{
			eShoot[n][b] = true;
			
			eShDir[n][b] = eDir[n];
			eShW[n][b] = eW[n] + 1;
			eShH[n][b] = eH[n];
			
			eShAgainDelay[n] = eMaxShAgainDelay;
			
			goto noMoreEShoots;
		}
		else if(
		(eW[n] - inc == plW)
		&& (eH[n] == plH)
		&& (e_emptyAt_wall_l[n] == true)
		&& (eDir[n] == "l")
		&& (eShoot[n][b] == false)
		&& (e_notSolid_l[n] == true)
		&& (px[eW[n]][eH[n]] != zeroShow)
		&& (px[eW[n]][eH[n]] != notSolid[0])
		&& (eRun[n] == true)
		&& (eDisplayDelay <= 0)
		)
		{
			eShoot[n][b] = true;
			
			eShDir[n][b] = eDir[n];
		  eShW[n][b] = eW[n] - 1;
			eShH[n][b] = eH[n];
			
			eShAgainDelay[n] = eMaxShAgainDelay;
			
			goto noMoreEShoots;
		}
		
		}
		
				}
				noMoreEShoots:
		
		string go;
		
				}
				
		if(eShAgainDelay[n] > 0)
		{
			eShAgainDelay[n] = eShAgainDelay[n] - eShAgainDelaySubNumb[n];
		}
		
				}
		
}
		
		//Enemy Shoot Setup
		void eShootSet()
		{
			
			for(int n = 0; n < eNumb; n++)
			{
				
			for(int b = 0; b < eShLimit; b++)
			{
				
				if(eShoot[n][b] == false)
			{
				eShW[n][b] = zeroPosW;
				eShH[n][b] = zeroPosH;
				px[eShW[n][b]][eShH[n][b]] = zeroShow;
				eShDuringDelay[n][b] = 0;
			}
			else if(eShoot[n][b] == true && eShDuringDelay[n][b] <= 0)
			{
				
				if(
				(eShDir[n][b] == "r")
				&& (e_notSolid_sh_r[n][b] == true)
				)
				{
					eShW[n][b]++;
					eShDuringDelay[n][b] = eMaxShDuringDelay;
				}
				else if(
			 (eShDir[n][b] == "l")
			 && (e_notSolid_sh_l[n][b] == true)
				)
				{
					eShW[n][b]--;
					eShDuringDelay[n][b] = eMaxShDuringDelay;
				}
				else
				{
					eShoot[n][b] = false;
					eShDuringDelay[n][b] = 0;
				}
				
				}
				
				if(eShoot[n][b] == true)
				{
					
					if(eShW[n][b] >= width - 2)
			{
				eShoot[n][b] = false;
			}
			else if(eShW[n][b] <= 2)
			{
				eShoot[n][b] = false;
			}
					
					px[eShW[n][b]][eShH[n][b]] = eShNumb[n];
				}
		
		if(eShDuringDelay[n][b] > 0)
			{
				eShDuringDelay[n][b] = eShDuringDelay[n][b] - eShDuringDelaySubNumb[n];
			}
			
			}
		
			}
			
		}
		
		//Enemy Hit to bullets
		void eGetDamage()
		{
			
			/*When enemy killed by player actions, always use:
			
			if(eHp[n] <= 0)
				{
					temp_eHp[room[lv]][n] = 0;
 	 			temp_eW[room[lv]][n] = zeroPosW;
  				temp_eH[room[lv]][n] = zeroPosH;
					eLoot[n] = false;
				}
				*/
			if(eHpSetted == true && eDisplayDelay <= 0)
			{
			
			for( int n = 0; n < eNumb; n++)
	   {
	   				
	   	//Player Shoot Damage Factor
			for( int plShTy = 0; plShTy < plShTypes; plShTy++ )
			{
				
			if(px[eW[n] + 1][eH[n]] == plSh[plShTy])
			{
				eHp[n] = eHp[n] - eHpLoss[plShTy];
				px[eW[n] + 1][eH[n]] = notSolid[0];
				if(eHp[n] <= 0)
				{
					temp_eHp[room[lv]][n] = 0;
 	 			temp_eW[room[lv]][n] = zeroPosW;
  				temp_eH[room[lv]][n] = zeroPosH;
					eLoot[n] = false;
				}
			}
			else if(px[eW[n] - 1][eH[n]] == plSh[plShTy])
			{
				eHp[n] = eHp[n] - eHpLoss[plShTy];
				px[eW[n] - 1][eH[n]] = notSolid[0];
				if(eHp[n] <= 0)
				{
					temp_eHp[room[lv]][n] = 0;
 	 			temp_eW[room[lv]][n] = zeroPosW;
  				temp_eH[room[lv]][n] = zeroPosH;
					eLoot[n] = false;
				}
			}
			else	if(px[eW[n]][eH[n]] == plSh[plShTy])
			{
				eHp[n] = eHp[n] - eHpLoss[plShTy];
				px[eW[n]][eH[n]] = notSolid[0];
				if(eHp[n] <= 0)
				{
					temp_eHp[room[lv]][n] = 0;
 	 			temp_eW[room[lv]][n] = zeroPosW;
  				temp_eH[room[lv]][n] = zeroPosH;
					eLoot[n] = false;
				}
			}
			
			}
			
			//Player Jump-Assasination
			if(
			(jumpForce == false)
			&& ((eH[n] + 1) == plH)
			&& (eW[n] == plW)
			&& (e_notSolid_d[n] == false)
			)
			{
				eHp[n] = eHp[n] - eHpLoss_jumpStab;
				jumpForce = true;
				if(eHp[n] <= 0)
				{
					temp_eHp[room[lv]][n] = 0;
 	 			temp_eW[room[lv]][n] = zeroPosW;
  				temp_eH[room[lv]][n] = zeroPosH;
					eLoot[n] = false;
				}
			}
			
			//Enemy Death Factor
			if( eHp[n] <= 0 )
			{
				eW[n] = zeroPosW;
				eH[n] = zeroPosH;
				px[eW[n]][eH[n]] = zeroShow;
				eRun[n] = false;
			}
			
			}
			
		}
		
		}
		
		//Enemy Movement AI Runner
		void eMoveAIRunner()
		{
			if(emptyAt == true && eDisplayDelay <= 0)
			{
			
			for (int n = 0; n < eNumb; n++)
			{
				if(eRun[n] == true)
				{
				
				for(int i = 0; i < eNumb; i++)
				{
					e_emptyAt_forE(i);
				}
				
				if(e_emptyAt_forP[n] == true)
				{
				
			if(isE_ConstMoveNumb[n] == true)
			{
				eConstMove(n);
	  	}
	  	else if(isE_PlatMoveNumb[n] == true)
	  	{
	  		ePlatMove(n);
	  	}
	 	else
 		{
		 	eRandMove(n);
 		}
 		
				}
		
			}
			
			}
			
		}
		
		}