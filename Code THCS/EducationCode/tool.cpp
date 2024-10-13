#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return 0;
	}
	string file_name = argv[1];
	system(("echo. > " + file_name + ".cpp").c_str());
	system(("echo. > " + file_name + ".inp").c_str());
	system(("echo. > " + file_name + ".out").c_str());
}
