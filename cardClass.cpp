/*
Ramsha Bilal
bilal_week4_gp
Game Project 4
cardClass.cpp
PC
*/
#include <iostream>
#include<string>
#include <iomanip>
#include <vector>
#include<cstdlib>
#include<ctime>
#include "cardClass.h"
using namespace std;

Suit Cards::getSuit()
{
	return m_Suit;
}
string Cards::getRank()
{
	return m_Rank;
}

int Cards::getValue()
{
	return m_Value;
}