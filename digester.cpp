#include <cstdlib>
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
	void Digester::printState(std::ostream& out) {
		std::queue<int> quecopy = std::queue<int>(markovState);
		while (!quecopy.empty()) {
			out << (char)quecopy.front();
			quecopy.pop();
		}
	}
	void Digester::printNext(std::ostream& out) {
		std::map<int, int> freqs = datas[markovState];
		std::map<int, int>::iterator it;
		int total = 0;
		for ( it=freqs.begin() ; it != freqs.end(); it++ ) {
			total += (*it).second;
		}
		int prob = rand() % total;
		int result = 0;
		for ( it=freqs.begin() ; it != freqs.end(); it++ ) {
			prob -= (*it).second;
			if (prob < 0) {
				result = (*it).first;
				break;
			}
		}
		markovState.pop();
		markovState.push(result);
		out << (char)result;
	}
	void Digester::display() {
		std::map<std::queue<int>, std::map<int, int> >::iterator it;
		for ( it=datas.begin() ; it != datas.end(); it++ ) {
			std::queue<int> quecopy = std::queue<int>((*it).first);
			while (!quecopy.empty()) {
				std::cout << (char)quecopy.front() << " ";
				quecopy.pop();
			}
			std::cout << "===> ";
			std::map<int, int>::iterator jt;
			for (jt=(*it).second.begin(); jt != (*it).second.end(); jt++) {
				std::cout << (char)(*jt).first << " => " << (*jt).second << " ";
			}
			std::cout << "\n";
		}
	}
}
