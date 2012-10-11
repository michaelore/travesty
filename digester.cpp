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
				if (nextChar == -1) continue;
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
			std::queue<int> quecopy = std::queue<int>((*it).first);
			while (!quecopy.empty()) {
				std::cout << (char)quecopy.front() << " ";
				quecopy.pop();
			}
			std::cout << "===> ";
			std::map<int, long>::iterator jt;
			for (jt=(*it).second.begin(); jt != (*it).second.end(); jt++) {
				std::cout << (char)(*jt).first << " => " << (*jt).second << " ";
			}
			std::cout << "\n";
		}
	}
}
