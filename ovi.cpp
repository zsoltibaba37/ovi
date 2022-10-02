#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>

#define question "Choose a date: "

std::string fileName="ovi.txt";
std::vector<std::string> dates = {"1989–1993", "1994–1998", "1998–2001", "2002–2005", "2006-2018"};
std::vector<std::string> lines; // this store the entire file, line by line

void printLine(int _a);

int main(int argc, char const *argv[])
{
	//------------ Files stuffs ------------
	std::ifstream myFile(fileName);

	std::string l;
	while (std::getline(myFile, l)){
		lines.push_back(l);
	}
	//------------ END Files stuffs ------------
	while(1){
		//------------ Choose ------------
		int s;
		for (int i=0; i < dates.size(); i++ ){
			std::cout << i << ". " << dates[i] << "\n";
		}
		std::cout << question;
		std::cin >> s;
		while(!std::cin.good() || s < 1 || s > dates.size()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << question;
			std::cin >> s;
		}
		//------------ END Choose ------------

		//------------ Readout ------------
		srand(time(NULL));
		int v;
		
		switch (s){
			case 1:
			v = rand() % 11 +1;
			printLine(v);
			break;
			case 2:
			v = rand() % 4 +14;
			printLine(v);
			break;
			case 3:
			v = rand() % 9 +20;
			printLine(v);
			break;
			case 4:
			v = rand() % 10 +31;
			printLine(v);
			break;
			case 5:
			v = rand() % 44 +43;
			printLine(v);
			break;
		}
		//------------ END Readout ------------
	}
	myFile.close();
	return 0;
}

// ---------- VOIDS ----------
// ---------- VOIDS ----------
void printLine(int _a){
	std::cout << "\n" << lines[_a] << "\n" << "\n";
}