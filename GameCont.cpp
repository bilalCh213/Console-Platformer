
/* 
FUNCTIONS FOR FRAMERUNNER: plHpCheck();
plDamageFactor();
boundaryLimit();
pl_notSolidCheck();
e_notSolidCheck();
gravityFactor();
jumpForceFactor();
emptyAtFactor();
e_emptyAtFactor();
eShNoMoveThrough();

FUNCTIONS FOR INTERNAL USE:
* None *
 */

using namespace std;

		// Player HP Check
void plHpCheck()
{

	if (hp <= 0)
	{
		run = false;
	}
	//HP Limiter
	else if (hp > 999)
	{
		hp--;
	}

}

	// Set Values for New Game
void setForNew()
{
	lv = lvStart;
	lvSet = true;
	hp = hpSet;
	
	isSlowPow = false;
	isRegenerate = false;
	isInvulnerable = true;
	isNuke = false;
	//Add Power here
	
	// Setting Values to Initial Values for New Game
		score = initScore;
		gold = initGold;

		for (int n = 0; n < plShTypes; n++)
		{
			is_plSh[n] = false;
			plShValForType[n] = initOtherBullet;
		}
		is_plSh[0] = true;
		plShVal = initStBullet;
		
		selectedSlowPow = true;
		selectedRegenerate = false;
		selectedInvulnerable = false;
		selectedNuke = false;
		// Add Power here

		slowPowDelay = initSlowPow;
		regenDelay = initRegen;
		plVul = maxVul;
		nukeCount = initNuke;
		// Add Power here
		
		stabShowDelay = 0;
		// Such values ends here
}

void roomCheck()
{
		for(int n = 0; n <= maxRooms[lv]; n++)
		{
		if(room[lv] == n)
	{
	  if(plW == wallEntr_r)
			{
				entrH = plH;
				entrW = entrW_l;
				
				room[lv] = (n + 1);
				
				roomSet = true;
				
				goto roomDone;
			}
  else if(plW == wallEntr_l)
			{
				entrH = plH;
				entrW = entrW_r;
				
				room[lv] = (n - 1);
				
				roomSet = true;
				
				goto roomDone;
			}
  }
		}
		roomDone:
		
		int nothiling;
}

		// Player Damaging Factor
void plDamageFactor()
{
	if(lvSet == true)
	{
		stabShowDelay = 0;
		plVul = maxVul;
		isInvulnerable = true;
	}
	
// Player Invulnerabililty (Power)
if(isInvulnerable == true)
{
	
	if (plVul > 0)
	{
		plVul = plVul - VulSub;

		if (pl == plDis)
		{
			pl = vulShow;
		}
		else if (pl == vulShow)
		{
			pl = plDis;
		}

		plDamage = false;
	}
	else if (plVul <= 0)
	{
		pl = plDis;
		
		plDamage = true;
		isInvulnerable = false;
	}
	
}
else if(isInvulnerable == false)
{
	plDamage = true;
	pl = plDis;
}

}

		// Boundary Limitations
void bounderyLimit()
{
	while (plH > height - 1)
	{
		plH--;
	}
	while (plH < 1)
	{
		plH++;
	}
	while (plW > width - 1)
	{
		plW--;
	}
	while (plW < 1)
	{
		plW++;
	}

	for (int n = 0; n < eNumb; n++)
	{
		if (px[eW[n]][eH[n]] != zeroShow && eHp[n] > 0)
		{

			while (eH[n] > height - 3)
			{
				eH[n]--;
			}
			while (eH[n] < 1)
			{
				eH[n]++;
			}
			while (eW[n] > wallEntr_r)
			{
				eW[n]--;
			}
			while (eW[n] < wallEntr_l)
			{
				eW[n]++;
			}

		}

	}

}

	// Player notSolid Checking
void pl_notSolidCheck()
{

  nS0:
	for (int n = 0; n < totalNotSolid; n++)
	{
		if (px[plW + 1][plH] == notSolid[n])
		{
			pl_notSolid_r = true;
			goto nS1;
		}
		else
		{
			pl_notSolid_r = false;
		}
	}

  nS1:
	for (int n = 0; n < totalNotSolid; n++)
	{
		if (px[plW - 1][plH] == notSolid[n])
		{
			pl_notSolid_l = true;
			goto nS2;
		}
		else
		{
			pl_notSolid_l = false;
		}
	}

  nS2:
	for (int n = 0; n < totalNotSolid; n++)
	{
		if (px[plW][plH + 1] == notSolid[n])
		{
			pl_notSolid_d = true;
			goto nS3;
		}
		else
		{
			pl_notSolid_d = false;
		}
	}

  nS3:
	for (int n = 0; n < totalNotSolid; n++)
	{
		if (px[plW][plH - 1] == notSolid[n])
		{
			pl_notSolid_u = true;
			goto nS4;
		}
		else
		{
			pl_notSolid_u = false;
		}
	}

  nS4:
	for (int shT = 0; shT < 19; shT++)
	{
		for (int n = 0; n < totalNotSolid; n++)
		{
			if (px[plShW[shT] + 1][plShH[shT]] == notSolid[n])
			{
				pl_notSolid_sh_r[shT] = true;
				goto nS5;
			}
			else
			{
				pl_notSolid_sh_r[shT] = false;
			}
		}
	  nS5:
		int nothin;
	}

	for (int shT = 0; shT < 19; shT++)
	{
		for (int n = 0; n < totalNotSolid; n++)
		{
			if (px[plShW[shT] - 1][plShH[shT]] == notSolid[n])
			{
				pl_notSolid_sh_l[shT] = true;
				goto nSFin;
			}
			else
			{
				pl_notSolid_sh_l[shT] = false;
			}
		}
	  nSFin:
		int nothing;
	}

	pl_notSolid = true;

}

	// Enemy notSolid Checking
void e_notSolidCheck()
{

	for (int eN = 0; eN < eNumb; eN++)
	{

	  e_nS0:
		for (int n = 0; n < totalNotSolid; n++)
		{
			if (px[eW[eN] + 1][eH[eN]] == notSolid[n])
			{
				e_notSolid_r[eN] = true;
				goto e_nS1;
			}
			else
			{
				e_notSolid_r[eN] = false;
			}
		}

	  e_nS1:
		for (int n = 0; n < totalNotSolid; n++)
		{
			if (px[eW[eN] - 1][eH[eN]] == notSolid[n])
			{
				e_notSolid_l[eN] = true;
				goto e_nS2;
			}
			else
			{
				e_notSolid_l[eN] = false;
			}
		}

	  e_nS2:
		for (int n = 0; n < totalNotSolid; n++)
		{
			if (px[eW[eN]][eH[eN] + 1] == notSolid[n])
			{
				e_notSolid_d[eN] = true;
				goto e_nS3;
			}
			else
			{
				e_notSolid_d[eN] = false;
			}
		}

	  e_nS3:
		for (int n = 0; n < totalNotSolid; n++)
		{
			if (px[eW[eN]][eH[eN] - 1] == notSolid[n])
			{
				e_notSolid_u[eN] = true;
				goto e_nS4;
			}
			else
			{
				e_notSolid_u[eN] = false;
			}
		}

	  e_nS4:
		for (int n = 0; n < totalNotSolid; n++)
		{
			if (px[eW[eN] + 1][eH[eN] + 1] == notSolid[n])
			{
				e_notSolid_d_r[eN] = true;
				goto e_nS5;
			}
			else
			{
				e_notSolid_d_r[eN] = false;
			}
		}

	  e_nS5:
		for (int n = 0; n < totalNotSolid; n++)
		{
			if (px[eW[eN] - 1][eH[eN] + 1] == notSolid[n])
			{
				e_notSolid_d_l[eN] = true;
				goto e_nS6;
			}
			else
			{
				e_notSolid_d_l[eN] = false;
			}
		}

	  e_nS6:
		for (int n = 0; n < totalNotSolid; n++)
		{
			if (
			(px[eW[eN]][eH[eN] - 1] == notSolid[n])
				&& (px[eW[eN]][eH[eN] - 2] == notSolid[n])
				&& (px[eW[eN]][eH[eN] - 3] == notSolid[n])
				)
			{
				e_notSolid_upAbove[eN] = true;
				goto nSWall0;
			}
			else
			{
				e_notSolid_upAbove[eN] = false;
			}
		}

	  nSWall0:
		// Check for notSolid[0] contrast wall checking only
		for (int i = 1; i <= (plW - eW[eN]); i++)
		{

			if (
			(px[eW[eN] + i][eH[eN]] != notSolid[0])
				&& (px[eW[eN] + i][eH[eN] - 1] != notSolid[0])
				&& (px[eW[eN] + i][eH[eN] - 2] != notSolid[0])
				)
			{
				e_notSolid_wall_r[eN] = false;
				goto nSWall1;
			}
			else
			{
				e_notSolid_wall_r[eN] = true;
			}

		}

	  nSWall1:
		// Check for notSolid[0] contrast wall checking only
		for (int i = 1; i <= (eW[eN] - plW); i++)
		{
			if (
			(px[eW[eN] - i][eH[eN]] != notSolid[0])
				&& (px[eW[eN] - i][eH[eN] - 1] != notSolid[0])
				&& (px[eW[eN] - i][eH[eN] - 2] != notSolid[0])
				)
			{
				e_notSolid_wall_l[eN] = false;
				goto nS_sh0;
			}
			else
			{
				e_notSolid_wall_l[eN] = true;
			}
		}

	  nS_sh0:
		for (int b = 0; b < eShLimit; b++)
		{
			for (int n = 0; n < totalNotSolid; n++)
			{
				for (int pST = 0; pST < plShTypes; pST++)
				{
					if (
					(px[eShW[eN][b] + 1][eShH[eN][b]] == notSolid[n])
						|| (px[eShW[eN][b] + 1][eShH[eN][b]] == plSh[pST])
						)
					{
						e_notSolid_sh_r[eN][b] = true;
						goto nS_sh1;
					}
					else
					{
						e_notSolid_sh_r[eN][b] = false;
					}
				}
			}
		  nS_sh1:
			int nothing;
		}

		for (int b = 0; b < eShLimit; b++)
		{
			for (int n = 0; n < totalNotSolid; n++)
			{
				for (int pST = 0; pST < plShTypes; pST++)
				{
					if (
					(px[eShW[eN][b] - 1][eShH[eN][b]] == notSolid[n])
						|| (px[eShW[eN][b] - 1][eShH[eN][b]] == plSh[pST])
						)
					{
						e_notSolid_sh_l[eN][b] = true;
						goto nS_Fin;
					}
					else
					{
						e_notSolid_sh_l[eN][b] = false;
					}
				}
			}
		  nS_Fin:
			int nothing;
		}

		e_notSolid = true;

	}

}

	// Gravity Causing Factor
void gravityFactor()
{

	if (
	(jump == false)
	&& (gravityDelay <= 0)
	&& (emptyAt == true)
	&& (isTileDone == true)
	)
	{
		if(pl_notSolid_d == true)
		{
		plH++;
		}
		gravityDelay = maxGravityDelay;
	}
	else if (gravityDelay > 0)
	{
		gravityDelay--;
	}

	for (int n = 0; n < eNumb; n++)
	{

		if (
		(eJump[n] == false)
		&& (eGravityDelay[n] <= 0)
		&& (e_emptyAt == true)
		&& (eRun[n] == true)
		&& (isTileDone == true)
		&& (eDisplayDelay <= 0)
		)
		{
			if(e_notSolid_d[n] == true)
			{
			eH[n]++;
			}
			eGravityDelay[n] = maxGravityDelay;
		}
		else if (eGravityDelay[n] > 0)
		{
			eGravityDelay[n]--;
		}

	}

}

	// Factor for proper non-fly jump
void jumpForceFactor()
{
	if (pl_notSolid_d == true)
	{
		jumpForce = false;
	}
	else
	{
		jumpForce = true;
	}

	for (int n = 0; n < eNumb; n++)
	{

		if (e_notSolid_d[n] == true)
		{
			eJumpForce[n] = false;
		}
		else
		{
			eJumpForce[n] = true;
		}

	}
}

	// Player emptyAt Factor
void emptyAtFactor()
{
	if (pl_notSolid == true)
	{

		if (
		(pl_notSolid_r == true)
		|| (px[plW + 1][plH] == plPassWall)
		)
		{
			emptyAt_r = true;
		}
		else
		{
			emptyAt_r = false;
		}
		if (
		(pl_notSolid_l == true)
		|| (px[plW - 1][plH] == plPassWall)
		)
		{
			emptyAt_l = true;
		}
		else
		{
			emptyAt_l = false;
		}
		if (
		(pl_notSolid_d == true)
		|| (px[plW][plH + 1] == roof)
		)
		{
			emptyAt_d = true;
		}
		else
		{
			emptyAt_d = false;
		}
		if (
		(pl_notSolid_u == true)
			|| (px[plW][plH - 1] == _floor)
			|| (px[plW][plH - 1] == spikes)
			)
		{
			emptyAt_u = true;
		}
		else
		{
			emptyAt_u = false;
		}
		
		for(int n = 0; n < eNumb; n++)
		{
			
		if (
		(
		((plW - 1) == eW[n])
		|| (plW == eW[n])
		|| ((plW + 1) == eW[n])
		)
		&& (plH == eH[n])
		)
		{
			emptyAt_forE = false;
			goto enemyIsAside;
		}
		else
		{
			emptyAt_forE = true;
		}
		
		}
		enemyIsAside:

		emptyAt = true;
	}

}

void e_emptyAt_forE(int n)
{
	for(int eN = 0; eN < eNumb; eN++)
			{
				
				if(
				((eW[n] + 1) == eW[eN])
				&& (
				(eH[n] == eH[eN])
				|| ((eH[n] + 1) == eH[eN])
				|| ((eH[n] - 1) == eH[eN])
				)
				)
				{
					e_emptyAt_r_forE[n] = false;
					goto enemyWithEnemy;
				}
				else
				{
					e_emptyAt_r_forE[n] = true;
				}
			 
			 if(
				((eW[n] - 1) == eW[eN])
				&& (
				(eH[n] == eH[eN])
				|| ((eH[n] + 1) == eH[eN])
				|| ((eH[n] - 1) == eH[eN])
				)
				)
				{
					e_emptyAt_l_forE[n] = false;
					goto enemyWithEnemy;
				}
				else
				{
					e_emptyAt_l_forE[n] = true;
				}
				
			}
			enemyWithEnemy:
			
			int noothing;
}

	// Enemy emptyAt Factor
void e_emptyAtFactor()
{

	if (e_notSolid == true)
	{

		for (int n = 0; n < eNumb; n++)
		{

			if (e_notSolid_r[n] == true)
			{
				e_emptyAt_r[n] = true;
			}
			else
			{
				e_emptyAt_r[n] = false;
			}
			if (e_notSolid_l[n] == true)
			{
				e_emptyAt_l[n] = true;
			}
			else
			{
				e_emptyAt_l[n] = false;
			}
			if (
			(e_notSolid_d[n] == true) || (px[eW[n]][eH[n] + 1] == roof)
			)
			{
				e_emptyAt_d[n] = true;
			}
			else
			{
				e_emptyAt_d[n] = false;
			}
			if (
			(e_notSolid_u[n] == true)
				|| (px[eW[n]][eH[n] - 1] == _floor)
				|| (px[eW[n]][eH[n] - 1] == spikes)
				)
			{
				e_emptyAt_u[n] = true;
			}
			else
			{
				e_emptyAt_u[n] = false;
			}

			if (e_notSolid_d_r[n] == true)
			{
				e_emptyAt_d_r[n] = true;
			}
			else
			{
				e_emptyAt_d_r[n] = false;
			}
			if (e_notSolid_d_l[n] == true)
			{
				e_emptyAt_d_l[n] = true;
			}
			else
			{
				e_emptyAt_d_l[n] = false;
			}
			if (e_notSolid_wall_r[n] == true)
			{
				e_emptyAt_wall_r[n] = true;
			}
			else
			{
				e_emptyAt_wall_r[n] = false;
			}
			if (e_notSolid_wall_l[n] == true)
			{
				e_emptyAt_wall_l[n] = true;
			}
			else
			{
				e_emptyAt_wall_l[n] = false;
			}
			if (e_notSolid_upAbove[n] == true)
			{
				e_emptyAt_upAbove[n] = true;
			}
			else
			{
				e_emptyAt_upAbove[n] = false;
			}
			if (
			(
			(eW[n] == plW)
			|| (eW[n] - 1 == plW)
			|| (eW[n] + 1 == plW)
			)
			&& (eH[n] == plH)
			)
			{
				e_emptyAt_forP[n] = false;
			}
			else
			{
				e_emptyAt_forP[n] = true;
			}
			
			e_emptyAt_forE(n);

		}

		e_emptyAt = true;
	}

}

	// Function for fixing bullets crossing enemy bug
void eShNoMoveThrough()
{

	for (int n = 0; n < eNumb; n++)
	{
		for (int p = 0; p < 19; p++)
		{

			if (
			(eW[n] + 1 == plShW[p])
			&& (eH[n] == plShH[p])
			)
			{
				e_emptyAt_r[n] = false;
			}
			else if (
			(eW[n] - 1 == plShW[p])
			&& (eH[n] == plShH[p])
			)
			{
				e_emptyAt_l[n] = false;
			}
			else if (
			(eW[n] == plShW[p])
			&& (eH[n] == plShH[p])
			)
			{
				e_emptyAt_r[n] = false;
				e_emptyAt_l[n] = false;
			}

		}
	}

}