#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

vector <string> names;
int curSize;
void getFile();
void createFile(string);
void shuffle();
void main() {
	srand((unsigned int)time(NULL));
	getFile();
	createFile("Shuffle1.txt");
	createFile("Shuffle2.txt");

}

void getFile() {
	ifstream pull;
	pull.open("NAMES.txt");
	string line;
	names.clear();
	while (!pull.eof()) {
		line.clear();
		getline(pull,line);
		if (line != "") {
			names.push_back(line);
		}
	}
}
void createFile(string file) {
	ofstream outFile;
	shuffle();
	outFile.open(file.c_str());
	for (int i = 0; i < (int)names.size(); i++) {
		outFile << names[i] << "\n";
	}
	outFile.close();
}
void shuffle() {
	random_shuffle(names.begin(), names.end());
}