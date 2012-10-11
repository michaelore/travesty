#include <iostream>
#include <istream>
#include <ostream>
#include <map>
#include <queue>

//using namespace travesty;

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		std::cout << "Usage: travesty N\n";
		return -1;
	}
	long nparam = strtol(argv[1], NULL, 10);
	if (nparam < 1) {
		std::cout << "N must be positive.\n";
	}
	std::map<std::queue<int>, std::map<int, long> > processed;
	std::queue<int> ongoing;
	std::queue<int> initial;
	while (!std::cin.eof()) {
		int nextChar = std::cin.get();
		if (ongoing.size() < nparam-1) {
			ongoing.push(nextChar);
			initial.push(nextChar);
		}
		else {
			processed[ongoing][nextChar]++;
			ongoing.pop();
			ongoing.push(nextChar);
		}
	}
	std::map<std::queue<int>, std::map<int, long> >::iterator it;
	for ( it=processed.begin() ; it != processed.end(); it++ ) {
		std::cout << (*it).first.size() << " => " << (*it).second.size() << std::endl;
	}
	return 0;
}
