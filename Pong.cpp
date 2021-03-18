#include <iostream>
#include <thread>
#include <stdlib.h>
#include "Score.h"
#include "Player.h"
using namespace std;
bool play=true;
bool ulang=true;

int main() {
	int a;
	int round = 1;
	Score score;
	srand(time(0));
	a = rand() % 2; //randoms first player

	Player player1(a);
	Player player2 = player1; //clone

	while (play) {
		ulang = true;
		cout << "\n\nRound " << round;
			while (ulang) {
				thread t1(&Player::tambah, &player1); //1st thread runs...
				t1.join();
				if (player1.getHits() > 50) {
					score.tambah(player1.getP());
					ulang = false;
				}
				else {
					ulang = true;
				}
				if (ulang) {								// excecuted if previous hits < 50
					thread t2(&Player::tambah, &player2);	//2nd thread runs...
					t2.join();
					if (player2.getHits() > 50) {
						score.tambah(player2.getP());
						ulang = false;
					}
					else {
						ulang = true;
					}										//will go to first thread if 2nd hits also < 50
				}
			}
			if (score.returnX() == 10) {					//exit condition
				cout << "\nX menang!";
				play = false;
			}
			else if (score.returnY() == 10) {
				cout << "\nY menang!";
				play = false;
			}
			round++;										//rounds
		}
		score.tampil();										//final score
}