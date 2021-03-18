#ifndef SCORE_H

class Score {
	int PlayerXScore = 0;
	int PlayerYScore = 0;

public:
	void tampil() {
		std::cout << "\nSkor X = " << PlayerXScore << endl;
		std::cout << "Skor Y = " << PlayerYScore;
	}
	void tambah(string p) {				//adding score based on X or Y
		if (p == "\nPlayer X") {
			PlayerXScore += 1;
		}
		else {
			PlayerYScore += 1;
		}
		tampil();
	}
	int returnX() {
		return PlayerXScore;
	}
	int returnY() {
		return PlayerYScore;
	}
};


#endif // !SCORE_H