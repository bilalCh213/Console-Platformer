
/*
FUNCTIONS FOR FRAMERUNNER;
keyboardCont();

FUNCTIONS FOR INTERNAL USE:
* None *
*/

using namespace std;

void keyboardCont()
{
	if (emptyAt == true)
	{
		
		if (kbhit())
		{
			input = getch();

			// Most Used ones are:
			// char 119 for "w"
			// char 97 for "a"
			// char 115 for "s"
			// char 100 for "d"
			// char 32 for "space"
			// char 27 for ESC

 //Keyboard Keys responding to functions
   if (
			(input == 119)
			&& (plW == doorlv_w[lv])
			&& (plH == doorlv_h[lv])
			&& (room[lv] == doorRoom[lv])
			)
			{
				lv = lv + 1;
				lvSet = true;
				
				isSlowPow = false;
				isRegenerate = false;
				isInvulnerable = false;
				isNuke = false;
				//Add Power here
				
				if( lv != maxLv)
				{
					input = 0;
		  		nextLv();
		  	}
			
			}
			if(
			(input == 119)
			&& (plW == shoplv_w[lv])
			&& (plH == shoplv_h[lv])
			&& (room[lv] == shopRoom[lv])
			)
			{
				shopMenu();
				
				isSlowPow = false;
				isRegenerate = false;
				isInvulnerable = false;
				isNuke = false;
				//Add Power here
			}
			else if(
			(input == 99)
			&& (plShAgainDelay <= 0)
			&& (stabShowDelay <= 0)
			)
			{
				bool selDone = false;
					int i = 0;
					
					if(
					(shoot[0] == false) && (shoot[1] == false) && (shoot[2] == false) && (shoot[3] == false) && (shoot[4] == false) && (shoot[5] == false) && (shoot[6] == false) && (shoot[7] == false) && (shoot[8] == false) && (shoot[9] == false) && (shoot[10] == false) && (shoot[11] == false) && (shoot[12] == false) && (shoot[13] == false) && (shoot[14] == false) && (shoot[15] == false) && (shoot[16] == false) && (shoot[17] == false) && (shoot[18] == false) && (shoot[18] == false)
				)
				{
					
					while(selDone == false)
					{
						
				if(
				(is_plSh[i] == true)
				)
				{
				is_plSh[i] = false;
				plShValForType[i] = plShVal;
				is_plSh[i + 1] = true;
				plShVal = plShValForType[i + 1];
				selDone = true;
				}
				else if(
				(is_plSh[plShTypes - 1] == true)
				)
				{
					is_plSh[plShTypes - 1] = false;
					plShValForType[plShTypes - 1] = plShVal;
					is_plSh[0] = true;
					plShVal = plShValForType[0];
					selDone = true;
				}
				
				i++;
				
					}
				
				}
				
				intendedStatDelayA = maxStatDelay;
			}
			else if(
			(input == 118)
			)
			{
				
				if(selectedSlowPow == true)
				{
					selectedSlowPow = false;
					isSlowPow = false;
					
					selectedRegenerate = true;
				}
				else if(selectedRegenerate == true)
				{
					selectedRegenerate = false;
					isRegenerate = false;
					
					selectedInvulnerable = true;
				}
				else if(selectedInvulnerable == true)
				{
					selectedInvulnerable = false;
					isInvulnerable = false;
					
					selectedNuke = true;
				}
				else if(selectedNuke == true)
				{
					selectedNuke = false;
					isNuke = false;
					
					selectedSlowPow = true;
				}
				//Add Power here
				
			}
			else if (
			(input == 104)
			)
			{
				
				if(
				(selectedSlowPow == true)
				&& (slowPowDelay > 0)
				)
				{
					
				if(isSlowPow == false)
				{
				isSlowPow = true;
				}
				else if(isSlowPow == true)
				{
					isSlowPow = false;
				}
				
				}
				else if(
				(selectedRegenerate == true)
				&& (regenDelay > 0)
				)
				{
					
					if(isRegenerate == false)
					{
						isRegenerate = true;
					}
					else if(isRegenerate == true)
					{
						isRegenerate = false;
					}
					
				}
				else if(
				(selectedInvulnerable == true)
				&& (plVul > 0)
				)
				{
					
					if(isInvulnerable == false)
					{
						isInvulnerable = true;
					}
					else if(isInvulnerable == true)
					{
						isInvulnerable = false;
					}
					
				}
				else if(
				(selectedNuke == true)
				&& (nukeCount > 0)
				)
				{
					
					if(isNuke == false)
					{
						isNuke = true;
					}
					else if(isNuke == true)
					{
						isNuke = false;
					}
					
				}
				//Add Power here
				else
				{
					
					if(selectedSlowPow == true)
				{
					selectedSlowPow = false;
					isSlowPow = false;
					
					selectedRegenerate = true;
				}
				else if(selectedRegenerate == true)
				{
					selectedRegenerate = false;
					isRegenerate = false;
					
					selectedInvulnerable = true;
				}
				else if(selectedInvulnerable == true)
				{
					selectedInvulnerable = false;
					isInvulnerable = false;
					
					selectedNuke = true;
				}
				else if(selectedNuke == true)
				{
					selectedNuke = false;
					isNuke = false;
					
					selectedSlowPow = true;
				}
				//Add Power here
				
				}
				
				intendedStatDelayB = maxStatDelay;
			}
		 else	if (
			(input == 119)
			&& (jump == false)
			&& (jumpForce == true)
			)
			{
				dir_ver = "u";
				jump = true;
				jumpTime = setJumpTime;
			}
			else if (input == 115)
			{
				dir_ver = "d";
				moveDown();
			}
			else if (input == 97)
			{
				dir_hor = "l";
				moveLeft();
			}
			else if (input == 100)
			{
				dir_hor = "r";
				moveRight();
			}
			else if (
			(input == 32)
			&& (plDamage == true)
			&& (plShAgainDelay <= 0)
			)
			{
				
				if(stabShowDelay <= 0)
				{
				if(plShVal > 0)
				{
			if(shoot[shCount] == false)
				{
			shDir[shCount] = dir_hor;
			
			if(shDir[shCount] == "r")
			{
			plShW[shCount] = plW;
			}
			else if(shDir[shCount] == "l")
			{
			plShW[shCount] = plW;
			}
			
			plShH[shCount] = plH;
			shoot[shCount] = true;
			
			plShAgainDelay = plShMaxAgainDelay;
			
			plShVal--;
			
			intendedStatDelayA = maxStatDelay;
				}
				else if(shCount >= 19)
				{
					shCount = 0;
				}
				else
				{
					shCount++;
				}
				
				}
				else if(plShVal <= 0)
				{
					bool selDone = false;
					int i = 0;
					
					if(
					(shoot[0] == false) && (shoot[1] == false) && (shoot[2] == false) && (shoot[3] == false) && (shoot[4] == false) && (shoot[5] == false) && (shoot[6] == false) && (shoot[7] == false) && (shoot[8] == false) && (shoot[9] == false) && (shoot[10] == false) && (shoot[11] == false) && (shoot[12] == false) && (shoot[13] == false) && (shoot[14] == false) && (shoot[15] == false) && (shoot[16] == false) && (shoot[17] == false) && (shoot[18] == false) && (shoot[18] == false)
				)
				{
					
					while(selDone == false)
					{
						
				if(
				(is_plSh[i] == true)
				)
				{
				is_plSh[i] = false;
				plShValForType[i] = plShVal;
				is_plSh[i + 1] = true;
				plShVal = plShValForType[i + 1];
				selDone = true;
				}
				else if(
				(is_plSh[plShTypes - 1] == true)
				)
				{
					is_plSh[plShTypes - 1] = false;
					plShValForType[plShTypes - 1] = plShVal;
					is_plSh[0] = true;
					plShVal = plShValForType[0];
					selDone = true;
				}
				
				i++;
				
					}
				
				}
				
				}
				
				}
				else if(stabShowDelay > 0)
				{
					
					if(stabCollect <= 0)
					{
						plStab();
					}
					else if(stabCollect > 0)
					{
						stabCollect--;
					}
					
				}
				
			}
			else if (input == 110)
			{
				isSlowPow = false;
				isRegenerate = false;
				isInvulnerable = false;
				isNuke = false;
				//Add Power here
				
				//ONLY FOR DEVELOPMENTAL PURPOSES
				devNumbers();
				
			}
			else if (input == 27)
			{
				// Game exits...

				// To terminate, use:
				run = false;
			}
			
 //Code end for responding keys (control)
		}
		
	}
		
}