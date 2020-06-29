
/*
FUNCTIONS FOR FRAMERUNNER:
statusBar();

FUNCTIONS FOR INTERNAL USES:
* None *
*/

using namespace std;

void statusBar()
{
	
if(emptyAt_forE == false)
{
	stabShowDelay = maxStabShowDelay;
}

/*
  if(
	(intendedStatDelayA > 0)
	&& (intendedStatDelayB > 0)
	)
	{
		intendedStatDelayA = 0;
		intendedStatDelayB = 0;
	}
	
	if(
	(
	(statDelay > 0)
	&& (statDelay < ((int)maxStatDelay/2))
	)
	|| (intendedStatDelayA > 0)
	)
	{
		*/
 	cout << beginDiv;
 	
 	//Level
 	cout << lvInd;
 	cout << valDiv;
 	if( lv < 10)
 	{
 		cout << "0";
 	}
 	cout << lv;
	
 	 cout << statDiv;
 	 
 	 //Player HP
		cout << hpInd;
		cout << valDiv;
		if( hp < 10)
 	{
 		cout << "0";
 	}
		cout << hp;
		
		cout <<statDiv;
		
		//Player Gun type and amount
		if(stabShowDelay > 0)
		{
			cout << stabInd;
			stabShowDelay--;
		}
		else if(stabShowDelay <= 0)
		{
			
		for( int i = 0; i < plShTypes; i++)
		{
			
		if( is_plSh[i] == true)
		{
			plShInd = plSh[i];
		
		cout << plShInd;
		cout << valDiv;
		if( plShVal < 10)
 	{
 		cout << "0";
 	}
		cout << plShVal;
		}
		
		}
		
		}
		
		cout << statDiv;
		
		/*
		cout << "\n";
	}
	else if(
	(
	(statDelay > ((int)maxStatDelay/2))
  && (statDelay < maxStatDelay)
  )
  || (intendedStatDelayB > 0)
  )
	{
		cout << statDiv;
		*/
		
		//Player Power
		if(selectedSlowPow == true)
		{
			
		if( isSlowPow == false)
		{
		cout << slowPowInd;
		}
		else if( isSlowPow == true)
		{
		cout << powActivInd;
		}
		
		cout << valDiv;
		
		if( slowPowDelay < 10)
		{
			cout << "00";
		}
		else if( slowPowDelay < 100)
 	{
 		cout << "0";
 	}
 	
		cout << slowPowDelay;
		
		}
		else if(selectedRegenerate == true)
		{
			
			if( isRegenerate == false)
			{
				cout << regenerateInd;
			}
			else if( isRegenerate == true)
			{
				cout << powActivInd;
			}
			
			cout << valDiv;
			
			if( regenDelay < 10)
			{
				cout << "00";
			}
			else if( regenDelay < 100)
			{
				cout << "0";
			}
			
			cout << regenDelay;
			
		}
		else if(selectedInvulnerable == true)
		{
			
			if(isInvulnerable == false)
			{
				cout << invulnerableInd;
			}
			else if(isInvulnerable == true)
			{
				cout << powActivInd;
			}
			
			cout << valDiv;
			
			if(((int)plVul) < 10)
			{
				cout << "00";
			}
			else if(((int)plVul) < 100)
			{
				cout << "0";
			}
			
			cout << ((int)plVul);
			
		}
		else if(selectedNuke == true)
		{
			
			if( isNuke == false)
			{
				cout << nukeInd;
			}
			else if( isNuke == true)
			{
				cout << powActivInd;
			}
			
			cout << valDiv;
			
			if( nukeCount < 10)
			{
				cout << "00";
			}
			else if( nukeCount < 100)
			{
				cout << "0";
			}
			
			cout << nukeCount;
			
		}
		
		cout << statDiv;
		
		//Player Gold
		cout << goldInd;
		cout << valDiv;
		if( gold < 10)
		{
			cout << "00";
		}
		else if(gold < 100)
		{
			cout << "0";
		}
		cout << gold;
		
		cout << statDiv;
		
		//Player Score
		cout << scoreInd;
		cout << valDiv;
		if( score < 10)
		{
			cout << "0000";
		}
		else if( score < 100)
		{
			cout << "000";
		}
		else if( score < 1000)
		{
			cout << "00";
		}
		else if( score < 10000)
		{
			cout << "0";
		}
		cout << score;
		
		cout << endDiv;
		
		cout << "\n";
		/*
	}*/
	
	if(statDelay <= 0)
	{
		statDelay = maxStatDelay;
	}
	else if(statDelay > 0)
	{
		statDelay--;
	}
	
	if(intendedStatDelayA > 0)
	{
		intendedStatDelayA--;
	}
	
	if(intendedStatDelayB > 0)
	{
		intendedStatDelayB--;
	}
	
}