#ifndef PLAYER_H
#include<iostream>
#include <mutex>
mutex m;
class Player {
	float hits;
	string p;
	enum players {
		PlayerX = 0, PlayerY = 1
	};
public:
	Player(int c) {
		if (c == PlayerX) {						//inizialitation based on int
			p = "\nPlayer X";
		}
		else {
			p = "\nPlayer Y";
		}
		hits = 0;
	}

	Player(Player& test) {
		if (test.p == "\nPlayer X") {			//no duplicate X or Y
			p = "\nPlayer Y";
		}
		else {
			p = "\nPlayer X";
		}
		hits = test.hits;
	}

	float getHits() {
		return hits;
	}

	string getP() {
		return p;
	}
	void tambah() {
		m.lock();											//unaccessible for other thread
		int* temp = new int;
		srand((int)temp);
		delete temp;
		hits = rand() % 100 + 1;
		std::cout << getP() << " gets " << getHits();		//gets different hits up to 100
		m.unlock();									
	}
};
#endif // !PLAYER_H


