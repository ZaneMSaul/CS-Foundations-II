#include <iostream>
#include <fstream>
#include <string>


int main() {
	std::string input;
	std::string filmName;
	std::string runningTime;
	std::string rating;
	std::ifstream filmFile;

	filmFile.open("films.dat", std::ios::in);
	getline(filmFile, filmName, ',');
	while (filmFile) {
		std::cout << filmName << std::endl;
		getline(filmFile, runningTime, ',');
		std::cout << runningTime << std::endl;
		getline(filmFile, rating, ',');
		std::cout << rating << std::endl;
		getline(filmFile, filmName, ',');
	}
}
