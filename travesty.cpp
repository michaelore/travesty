#include <stdlib.h>
#include <iostream>
#include <istream>
#include <ostream>
#include <map>
#include <queue>
#include "digester.h"

using namespace travesty;

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		std::cout << "Usage: travesty N\n";
		return -1;
	}
	long nparam = strtol(argv[1], NULL, 10);
	if (nparam < 1) {
		std::cout << "N must be positive.\n";
	}
	Digester digest = Digester(std::cin, nparam);
	//digest.display();
	digest.printState(std::cout);
	while (true) {
		digest.printNext(std::cout);
	}
	return 0;
}
