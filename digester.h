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
		std::map<std::queue<int>, std::map<int, long> > datas;
		std::queue<int> markovState;
		Digester();
		public:
		Digester(std::istream& in, int nparam);
		//void score(std::queue<int> preceding, int next);
		void display();
	};
}

#endif
