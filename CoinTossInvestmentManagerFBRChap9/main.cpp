/*
Author: Joe Mafrici
Filename CoinTossInvestmentManagerFBRChap9.cpp
Date Created: 12/07/2019
*/

/*
Overview: A recreation of the Investment Manger Monte Carlo Coin Flip scenario
mentioned in chapter 9 of Nassim Taleb's book Fooled By Randomness.
We start with 10k investment managers. Each year they have a 50% change to profit $10k
and a 50% chance to lose $10k. If they lose they are eliminated from the sample size.
Taleb shows that after five years we end up having 313 investment managers 
that won five years in a row just by luck. 
My most recent run of this program shows 305 very lucky investment managers.
*/

#include <iostream>
#include <vector>

#include "MonteCarlo.h"

int main()
{
	char choice{};
	MonteCarlo<int> investmentManagers(10000);
	
	investmentManagers.flipCoin();
	std::cout << "Would you like to run another year ?" << std::endl;
	std::cin >> choice;

	while (toupper(choice) == 'Y')
	{
		investmentManagers.flipCoin();
		std::cout << "Would you like to run another year ?" << std::endl;
		std::cin >> choice;
	}

	return 0;
}



/*
PROGRAM OUTPUT:

After year 1 4915 managers are up this year
Would you like to run another year ?
y
After year 2 2456 managers are up this year
Would you like to run another year ?
y
After year 3 1246 managers are up this year
Would you like to run another year ?
y
After year 4 605 managers are up this year
Would you like to run another year ?
y
After year 5 305 managers are up this year
Would you like to run another year ?

*/