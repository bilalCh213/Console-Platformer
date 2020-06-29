
/*
FUNCTIONS FOR FRAMERUNNER;
plJump();
plShoot();
showPlShoot();
plShEffect();
plGetDamage();
plPow();

FUNCTIONS FOR INTERNAL USE:
moveRight();
moveLeft();
moveUp();
moveDown();
*/

		using namespace std;
		
		//Player Movements
		void moveRight()
		{
			if(emptyAt_r == true)
			{
				plW++;
				
				emptyAt_r = false;
			}
		}
		
		void moveLeft()
		{
			if(emptyAt_l == true)
			{
				plW--;
				
				emptyAt_l = false;
			}
		}
		
		void moveUp()
		{
			if(emptyAt_u == true)
			{
				plH--;
				
				emptyAt_u = false;
			}
		}
		
		void moveDown()
		{
			if(emptyAt_d == true)
			{
				plH++;
				
				emptyAt_d = false;
			}
		}
		
		//Player Jump
		void plJump()
		{
			
			if(jumpDelay <= 0)
			{
				
			if(jump == true && emptyAt_u == true)
		{
			if(jumpTime <= 0)
			{
				jump = false;
				dir_ver = "d";
			}
			else if(jumpTime < jumpMove)
			{
				moveUp();
				
				if( dir_hor == "r")
				{
				moveRight();
				}
				else if(dir_hor == "l")
				{
				moveLeft();
				}
				
			}
			else
			{
				moveUp();
			}
			
			jumpTime = jumpTime - 1;
		}
		else if(emptyAt_u == false)
		{
			jumpTime = 0;
			jumpDelay = 0;
			jump = false;
		}
		
		jumpDelay = maxJumpDelay;
		}
		else if( jumpDelay > 0)
		{
			jumpDelay--;
		}
		
		}
		
		//Player Stabbing Action
		void plStab()
		{
			if(plDamage == true)
			{
			
			for(int n = 0; n < eNumb; n++)
			{
				
				if(
				(
				(plW + 1 == eW[n])
				|| (plW == eW[n])
				)
				&& (plH == eH[n])
				&& (dir_hor == "r")
				)
				{
					eHp[n]--;
					stabCollect = maxStabCollect;
				}
				else if(
				(
				(plW - 1 == eW[n])
				|| (plW == eW[n])
				)
				&& (plH == eH[n])
				&& (dir_hor == "l")
				)
				{
					eHp[n]--;
					stabCollect = maxStabCollect;
				}
				
			}
			
			}
			
		}
		
		//Player Shoot
		void plShoot()
		{
		
	 for (int n = 0; n < 19; n++)
	 {
	 	
	 	if(px[plShW[n]][plShH[n]] == notSolid[0])
	 	{
	 		plShW[n] = zeroPosW;
	 		plShH[n] = zeroPosH;
	 		px[plShW[n]][plShH[n]] = zeroShow;
	 	}
			
			if(shoot[n] == true)
		{
			if(plShDuringDelay[n] <= 0)
			{
		 
		 if(
		 (shDir[n] == "r")
		 && (pl_notSolid_sh_r[n] == true)
		 )
		 {
		 	plShW[n]++;
		 
		 plShDuringDelay[n] = plShMaxDuringDelay;
		 }
		 else if(
		 (shDir[n] == "l")
		 && (pl_notSolid_sh_l[n] == true)
		 )
		 {
		 	plShW[n]--;
		 	
		 	plShDuringDelay[n] = plShMaxDuringDelay;
		 }
		 
			}
		 
		 if(
			(
		 (shDir[n] == "r")
		 && (pl_notSolid_sh_r[n] == false)
		 )
		 || (
		 (shDir[n] == "l")
		 && (pl_notSolid_sh_l[n] == false)
		 )
		 )
		 {
		 	shoot[n] = false;
		 	shootEff[n] = true;
		}
			
			}
			else
			{
				shoot[n] = false;
			}
			
		}
			
		}
	 	
	 	//Player Show Shoots
	 	void showPlShoot()
	 	{
	 		
	 		for( int n = 0; n < 19; n++)
	 		{
	 			
	 			if(shoot[n] == true)
	 			{
	 				
	 				for(int i = 0; i < plShTypes; i++)
	 				{
	 					if(
	 					(is_plSh[i] == true)
	 					)
	 					{
	 	   			px[plShW[n]][plShH[n]] = plSh[i];
	 					}
	 				}
	 				
	 			}
	 		
	 		}
	 		
	 	}
		
		//Player Shoot Popping Effect
		void plShEffect()
		{
			
			for( int n = 0; n < 19; n++)
			{
				 	if(shootEff[n] == true && shoot[n] == false )
	 				{
	 					
	 					for(int eT = 0; eT < eTypes; eT++)
	 					{
	 						
	 						if( px[plShW[n] + 1][plShH[n]] == enem[eT] || px[plShW[n]][plShH[n]] == enem[eT] || px[plShW[n] - 1][plShH[n]] == enem[eT] )
	 						{
	 							goto skipIfEnemy;
	 						}
	 						
	 					}
	 						
	 						if( shDir[n] == "r")
	 						{
	 						for(int i = 0; i < plShTypes; i++)
	 						{
	 						if(is_plSh[i] == true)
	 						{
	 					px[plShW[n]][plShH[n]] = plShEff[i];
	 						}
	 						}
	 						}
	 					else if( shDir[n] == "l")
	 					{
	 					for(int i = 0; i < plShTypes; i++)
	 						{
	 						if(is_plSh[i] == true)
	 						{
	 					px[plShW[n]][plShH[n]] = plShEff[i];
	 						}
	 						}
	 					}
	 					
	 					skipIfEnemy:
	 					shootEff[n] = false;
	 				}
			}
		}
		
		//Player Damage
		void plGetDamage()
		{
			
			if( plDamage == true)
			{
				
				for( int n = 0; n < eTypes; n++ )
				{
					
					if(px[plW + 1][plH] == eShType[n])
					{
						hp = hp - hpLossType[n];
						intendedStatDelayA = maxStatDelay;
						
						px[plW + 1][plH] = notSolid[0];
						
						for( int nb = 0; nb < eNumb; nb++)
						{
							for( int b = 0; b < eShLimit; b++)
							{
						if(px[eShW[nb][b]][eShH[nb][b]] == notSolid[0])
				{
					eShoot[nb][b] = false;
				}
							}
						}
						
					}
					else if(px[plW - 1][plH] == eShType[n])
					{
						hp = hp - hpLossType[n];
						intendedStatDelayA = maxStatDelay;
						
						px[plW - 1][plH] = notSolid[0];
						
						for( int nb = 0; nb < eNumb; nb++)
						{
							for( int b = 0; b < eShLimit; b++)
							{
						if(px[eShW[nb][b]][eShH[nb][b]] == notSolid[0])
				{
					eShoot[nb][b] = false;
				}
							}
						}
						
					}
					
					if(
					(eDamageWhenClose <= 0)
					&& (isRegenerate == false)
					)
					{
					
					if(
					(px[plW][plH] == enem[n])
					|| (px[plW + 1][plH] == enem[n])
					|| (px[plW - 1][plH] == enem[n])
					)
					{
						hp--;
						intendedStatDelayA = maxStatDelay;
						
						if(eDamageWhenClose <= 0)
						{
						eDamageWhenClose = eMaxDamageDelay;
						}
						
					}
					
					}
					
					eDamageWhenClose = eDamageWhenClose - eDamageDelaySub[n];
					
				}
				
				//For Spikes tile set
	if(spikeHitDelay <= 0)
	{
		
	if(
	(px[plW][plH + 1] == spikes)
	&& (isRegenerate == false)
	)
	{
		hp--;
		intendedStatDelayA = maxStatDelay;
	}
	
	}
	
	//Spike Damage
	if(spikeHitDelay <= 0)
	{
		spikeHitDelay = spikeMaxHitDelay;
	}
	else if(spikeHitDelay > 0)
	{
		spikeHitDelay--;
	}
				
			}
			
		}
		
		// Player Powers
		void plPow()
		{
			
			//Power type: SlowPow
			if(isSlowPow == true && slowPowDelay > 0)
			{
				FrameDelay = slowPow;
				
				if(slowPowSub_wait <= 0)
				{
					slowPowSub_wait = slowPowSub_waitMax;
					slowPowDelay = slowPowDelay - 1;
				}
				else if(slowPowSub_wait > 0)
				{
					slowPowSub_wait = slowPowSub_wait - 1;
				}
				
			}
			else if(slowPowDelay <= 0)
			{
				isSlowPow = false;
				FrameDelay = defaultFrameDelay;
			}
			else if(isSlowPow == false)
			{
				FrameDelay = defaultFrameDelay;
			}
			if( slowPowDelay >= 1000)
			{
				slowPowDelay--;
			}
			
			// Power type: Regeneration
			if(isRegenerate == true && regenDelay > 0 && hp < 100)
			{
				
				if( regenFactor <= 0)
				{
					
					if( regenCost < (regenCostMax - 1) )
					{
					regenDelay = regenDelay - 1;
					regenCost++;
					}
					else if( regenCost >= (regenCostMax - 1) )
					{
						regenDelay = regenDelay - 1;
						hp = hp + regenerate;
						regenCost = 0;
					}
					
					regenFactor = maxRegenFactor;
				}
				else if( regenFactor > 0)
				{
					regenFactor--;
				}
				
			}
			else if(regenDelay <= 0)
			{
				isRegenerate = false;
				regenFactor = maxRegenFactor;
			}
			if( regenDelay >= 1000)
			{
				regenDelay--;
			}
			
			// Power Type: Nuke
			if(isNuke == true && nukeCount > 0 && notSolid[0] != nukeParticle && notSolid[0] != nukeDamageFactor)
			{
				nukeEffDelay = maxNukeEffDelay;
				notSolid[0] = nukeDamageFactor;
				nukeCount--;
			}
			else if(nukeEffDelay > 0)
			{
				notSolid[0] = nukeParticle;
				FrameDelay = slowPow;
				nukeEffDelay--;
			}
			else if(nukeEffDelay <= 0)
			{
				notSolid[0] = _empty;
				
				if(isSlowPow == false)
				{
				FrameDelay = defaultFrameDelay;
				}
				
				isNuke = false;
			}
			
		}