#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>
#include "color.h"
#include <csignal>

#define question "Choose a date: "

std::string fileName = "ovi.txt";
std::vector<std::string> dates = {};
std::vector<std::string> lines; // this store the entire file, line by line

void printLine(int _a);

// ---------- Signal handler --------------------
void signalHandler(int signum)
{
	std::cout << "\n Bye Bye ! " << '\n';
	exit(signum);
}

// -------- MAIN ----------
int main()
{
	std::signal(SIGINT, signalHandler);

	//------------ Read lines and dates ------------
	std::ifstream myFile(fileName);

	if (!myFile.is_open())
	{
		std::cout << RED << "\nFile doesn't exist. Now exit...\n";
		std::cout << RESET;
		exit(1);
	}

	std::string line;
	std::vector<int> datesLineNum{}; // store the dates line number
	int lineNumber{1};				 // iterate number from one
	while (std::getline(myFile, line))
	{
		if (line.length() > 0 && line.length() < 11)
		{
			dates.push_back(line);				// collect dates
			datesLineNum.push_back(lineNumber); // collect dates line numbers
		}
		lines.push_back(line);
		lineNumber++; // store all line number
	}
	//------------ END Read lines and dates ------------

	// -------------------
	while (1)
	{
		//------------ Pick One ------------
		int pickOne;
		for (int i = 0; i < dates.size(); i++)
		{
			std::cout << i + 1 << ". " << GREEN << dates[i] << "\n"; // set GREEN cout
			std::cout << RESET;										 // reset color
		}
		std::cout << question;
		std::cin >> pickOne;
		while (!std::cin.good() || pickOne < 1 || pickOne > dates.size())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << question;
			std::cin >> pickOne;
		}
		//------------ END Pick One ------------

		//------------ Readout ------------
		srand(time(NULL)); // reset time
		int randNum{};

		if (pickOne < dates.size())
			randNum = rand() % int(datesLineNum[pickOne] - datesLineNum[pickOne - 1] - 2) + datesLineNum[pickOne - 1]; // example: rand() % 11 + 1;
		else if (pickOne == dates.size())
			randNum = rand() % int((lineNumber + 1) - datesLineNum[pickOne - 1] - 2) + datesLineNum[pickOne - 1];

		printLine(randNum); // This is the goal

		//------------ END Readout ------------
	}
	myFile.close();
	return 0;
}

// ---------- VOIDS ----------
// ---------- VOIDS ----------
void printLine(int _a)
{
	std::cout << UNDLYELLOW << "\nThe quoted text:\n"
			  << RESET << ' ' << lines[_a] << '\n'
			  << '\n';
}
