#ifndef _DIGESTER_H
#define _DIGESTER_H
#include <iostream>
#include <istream>
#include <ostream>
#include <map>
#include <queue>

namespace travesty {
	class Digester {
		private:
		std::map<std::queue<int>, std::map<int, int> > datas;
		std::queue<int> markovState;
		Digester();
		public:
		Digester(std::istream& in, int nparam);
		void printState(std::ostream& out);
		void printNext(std::ostream& out);
		void display();
	};
}

#endif
