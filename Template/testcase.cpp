/**
 * author: tinhnopro (tinh nop)
 * created: 2024-11-29
**/

#include <iostream>
#include <fstream>
#include <strstream>
#include <stdio.h>
#include <stdlib.h>

const int MAX_TEST = 1011;

std::string fileName;
bool answer[MAX_TEST];

int num_tests;

void ReadInput() {

	std::ofstream os((fileName + ".in").c_str());

	std::string s;
	std::cin.ignore();
	while (std::getline(std::cin, s)) {
		if (s == "|") break;
		os << s << '\n';
	}

	os.close();
}

void ReadExpOutput() {
	std::ofstream os((fileName + ".ans").c_str());

	std::string s;
	while (std::getline(std::cin, s)) {
		if (s == "|") break;
		os << s << '\n';
	}

	os.close();
}

void RunCode(int Case) {
	system((fileName + ".exe").c_str());
	// Linux must be change fc to diff
	if (system(("fc " + fileName + ".out " + fileName + ".ans").c_str()) != 0) {
		answer[Case] = false;
		return ;
	}
	answer[Case] = true;
}

void PrintResult() {
	for (int tests = 1; tests <= num_tests; ++tests) {
		std::cout << "Case #" << tests << ": " << (answer[tests] ? "AC" : "WA") << "\n";
	}
}

void Clear() {
	system(("del " + fileName + ".ans").c_str());
}

int main() {
	atexit(Clear);

	std::cout << "File name: ";
	std::getline(std::cin, fileName);


	std::cout << "Num of testcases: ";
	std::cin >> num_tests;

	std::cout << "\t\t Please | enter to end of input\n";

	for (int testcases = 1; testcases <= num_tests; ++testcases) {
		std::cout << "Input Case " << testcases <<  ":\n";
		ReadInput();
		std::cout << "Expected Output Case " << testcases <<  ":\n";
		ReadExpOutput();

		RunCode(testcases);
	}

	PrintResult();

	return 0;
}

