/*
Ramsha Bilal
bilal_week4_gp
Game Project 4
playerClass.h
PC
*/
#ifndef DECK_CLASS
#define DECK_CLASS
#include <iostream>
#include<string>
#include <iomanip>
#include <vector>
#include<cstdlib>
#include<ctime>
#include "cardClass.h"

using namespace std;

class Player
{   
    public:
		vector<Cards> m_MyCards;
		int m_Score; 
		int m_RoundsWon;
		int m_BattlesWon;
		int m_BattlesPlayed;

		void constructor()
		{
			m_Score = 0;
			m_MyCards.clear();
			m_RoundsWon=0; 
			m_BattlesWon = 0;
			m_BattlesPlayed = 0;
		}

		Cards drawCard()
		{
			Cards cardToReturn; 
			cardToReturn = m_MyCards.back();
			m_MyCards.pop_back();
			return cardToReturn;
		}
		void addScore(int score)
		{
			m_Score += score;
		}
		void displayScore(int num)
		{
			cout << "Score for Player " << num << ": " << m_Score;
		}
}; 

#endif
