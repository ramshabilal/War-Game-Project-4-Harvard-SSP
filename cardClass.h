/*
Ramsha Bilal
bilal_week4_gp
Game Project 4
cardClass.h
PC
*/
#ifndef CARD_CLASS
#define CARD_CLASS

#include <iostream>
#include<string>
#include <iomanip>
#include <vector>
#include<cstdlib>
#include<ctime>
using namespace std;
enum Suit
{
	heart,
	spade,
	diamond,
	club
};
//string suitsOfCards[4] = { "hearts", "spades", "diamonds", "clubs" };

class Cards
{
public:
	Suit m_Suit;
	string m_Rank;
	int m_Value;

/*methods to access suit, rank, and
value of card respectively;*/ 
Suit getSuit();
string getRank();
int getValue();
};

#endif