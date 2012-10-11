#include <iostream>
#include <istream>
#include <ostream>
#include <map>
#include <queue>
#include "digester.h"

namespace travesty {
	Digester::Digester() {}
	Digester::Digester(std::istream& in, int nparam) {
		std::queue<int> ongoing;
		std::queue<int> initial;
		while (true) {
			int nextChar = 0;
			if (!in.eof()) {
				nextChar = in.get();
			} else if (!initial.empty()) {
				nextChar = initial.front();
				initial.pop();
			} else {
				break;
			}
			if (ongoing.size() < nparam-1) {
				ongoing.push(nextChar);
				initial.push(nextChar);
				markovState.push(nextChar);
			}
			else {
				datas[ongoing][nextChar]++;
				ongoing.pop();
				ongoing.push(nextChar);
			}
		}
	}
	void Digester::display() {
		std::map<std::queue<int>, std::map<int, long> >::iterator it;
		for ( it=datas.begin() ; it != datas.end(); it++ ) {
			std::cout << (*it).first.size() << " => " << (*it).second.size() << std::endl;
		}
	}
}
