#include<iostream>
#include<fstream>
#include "PokerGame.h"
#include<algorithm>
using namespace std;

void checkMachine()
{
   ifstream in;
   ofstream out;
   in.open("input.txt");
   out.open("output.txt");
   if(!in.is_open()) cout << "fail";
   if(!out.is_open()) cout << "fail";
   int n;
   in >> n;
   for(int i = 0;i < n;i++)
	 {
        vector <int> p1;
        vector <int> p2;
        int p11[5],p22[5];
        for(int i = 0;i < 5;i++) {
                in >> p11[i];
                p1.push_back(p11[i]);
        }
        for(int i = 0;i < 5;i++) {
                in >> p22[i];
                p2.push_back(p22[i]);
        }
		PokerGame player1, player2;
		    for(int i = 0;i < 5;i++){
                player1.setCards(p1);
                player2.setCards(p2);
		    }
			//Evaluate the type of cards and which is maxNumber in the cards
			player1.evaluate();
			player2.evaluate();

			out << table[player1.getType()] << endl;
			out << table[player2.getType()] << endl;

			//Compare and output winner
			if(player1.getType() > player2.getType()
             || player1.getType() == player2.getType() && player1.getMaxNumber() % 13 > player2.getMaxNumber() % 13
             || player1.getType() == player2.getType() && player1.getMaxNumber() % 13 == player2.getMaxNumber() % 13 && player1.getMaxNumber() / 13 > player2.getMaxNumber() / 13 )
            out << "1" << endl;
            else out << "2" << endl;
	}

}
int main() {
	bool Exit = false;
	checkMachine();
	while (!Exit) {
		PokerGame player1, player2;
		bool usedCards[52] = { false };
		int winner;
		char GameType;
		cout << "Do you want to play a poker game? [Y/N]";
		cin >> GameType;
		cout << endl;

		switch (GameType) {
		case 'y':
		case 'Y':
			//generate five cards for each players
			player1.distribute(usedCards);
			player2.distribute(usedCards);

			//Evaluate the type of cards and which is maxNumber in the cards
			player1.evaluate();
			player2.evaluate();

			//Print the cards of each players
			player1.printCards();
			player2.printCards();

			cout << "Player1 Type = " << table[player1.getType()] << endl;
			cout << "Player2 Type = " << table[player2.getType()] << endl;

			//Compare and output winner
			player1.compare(player2.getType(),player2.getMaxNumber());
			break;
		case 'n':
		case 'N':
			Exit = true;
		default:
			break;
		}
	}
}
