#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <ctime>
#include <string>
#include <unistd.h> // for sleep function

int main()
{
	std::cout << "Welcome to the Dice Roller!" << std::endl;
	std::cout << "How many sides does the die have? ";
	int sides;
	std::string s_sides;
	std::getline(std::cin, s_sides);
	sides = std::stoi(s_sides);
	std::cout << "How many dice do you want to roll? ";
	int numDice;
	std::string s_numDice;
	std::getline(std::cin, s_numDice);
	numDice = std::stoi(s_numDice);

	int dice_rslt[numDice];
	for(int i = 0; i < numDice; i++)
	{
		time_t t = time(0);
		//std::cout << t << std::endl;
		dice_rslt[i] = t % sides + 1; // Simulate rolling a die
		usleep(t % 5000000); // Sleep for a short duration to simulate rolling
		
	}
	std::cout << "You rolled: ";
	for(int i = 0; i < numDice; i++)
	{
		std::cout << dice_rslt[i] << " ";
	}
	std::cout << std::endl;
	int total = std::accumulate(dice_rslt, dice_rslt + numDice, 0);
	std::cout << "Total: " << total << std::endl;
	std::cout << "Average: " << static_cast<double>(total) / numDice << std::endl;
	std::cout << "Do you want to roll again? (y/n) ";
	std::string rollAgain;
	std::getline(std::cin, rollAgain);
	if (rollAgain == "y" || rollAgain == "Y")
	{
		main(); // Recursion to roll again
	}
	else
	{
		std::cout << "Thanks for playing!" << std::endl;
	}
}