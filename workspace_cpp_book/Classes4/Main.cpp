#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Film.h";

using namespace std;

int main() {
	string input;
	string filmName;
	string description;
	string nothing;
	int runningTime;
	string rating;
	ifstream filmFile;

	vector<Film> films;

	filmFile.open("films.dat", ios::in);
	int i = 0;
	getline(filmFile, filmName, ',');
	while (filmFile) {
		cout << filmName << endl;
		getline(filmFile, description,  ',');
		cout << description << endl;
		filmFile >> runningTime;
		cout << runningTime << endl;
		getline (filmFile, nothing, ',');
		getline(filmFile, rating, ',');
		cout << rating << endl;

		films.push_back(Film(i, filmName, description, rating, runningTime));
		i++;


		getline(filmFile, filmName, ',');
	}

	for (int i = 0; i < films.size(); i++) {
		films[i].print();
	}

	return 0;
}

