/*
Ramsha Bilal
bilal_week4_gp
Game Project 4
main.cpp
PC
*/
#include <iostream>
#include<string>
#include <iomanip>
#include <vector>
#include<cstdlib>
#include<ctime>
#include "cardClass.h"
#include "playerClass.h"
#include "main.h"
using namespace std;

string suits[4] = { "heart", "spade", "diamond", "club" };

/*it calls the gameOfWar function*/
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	gameOfWar(); 
	return 0;
}




/*it creates two player objects and calls constructor to initialise them
 it calls divideCards to evenly distribute cards randomly among the two players
it then asks if user wants debug mode -i.e see whether both players get 
unique and equal number of cards
it calls playRound until both players have run out of cards.
it then calls announceWinner and displayStats to display 
who won and the stats of each player
*/
void gameOfWar()
{   bool debug = false;
	int answer;
	Player player1, player2;
	player1.constructor();
	player2.constructor();
	divideCards(player1, player2);

	cout << "Do you want to see the cards of each player? Press 1 for yes, press 0 for no." 
		 << endl;
	 cin >> answer;
	if (answer == 1)
		debug = true;
	if (debug == true)
	{
		cout << "Player 1's cards: " << endl;
		for (int i = 0; i < 26; i++)
			cout << player1.m_MyCards[i].m_Rank
			<< "  of  "
			<< suits[player1.m_MyCards[i].m_Suit]
			<< " of value: "
			<< player1.m_MyCards[i].m_Value
			<< endl;

		cout << endl << "Player 2's cards: " << endl;
		for (int i = 0; i < 26; i++)
			cout << player2.m_MyCards[i].m_Rank
			<< "  of  "
			<< suits[player2.m_MyCards[i].m_Suit]
			<< " of value: "
			<< player2.m_MyCards[i].m_Value
			<< endl;
	}

	while ((player1.m_MyCards.empty()==false) && (player2.m_MyCards.empty()==false))
	{
		playRound(player1, player2);
	}

	announceWinner(player1, player2);
	displayStats(player1, player2);
}

/*this function randomly initialises a card with value, rank, and suit and returns it*/
Cards getACard()
{
	Cards newCard;
	Suit suitOfCard;
	string rankOfCard; 
	int valueOfCard;
	int randForRank, randomNumber = rand() % 4;

	if (randomNumber == 0)
		suitOfCard = club;
	else if (randomNumber == 1)
		suitOfCard = diamond;
	else if (randomNumber == 2)
		suitOfCard = heart;
	else if (randomNumber == 3)
		suitOfCard = spade;

	randForRank = rand() % 13 + 1;
	if (randForRank == 1)
	{
		rankOfCard = "Ace";
		valueOfCard = 1;
	}

	else if (randForRank == 11)
	{
		rankOfCard = "Jack";
		valueOfCard = 10;
	}
	else if (randForRank == 12)
	{
		rankOfCard = "Queen";
		valueOfCard = 10;
	}
	else if (randForRank == 13)
	{
		rankOfCard = "King";
		valueOfCard = 10;
	}
	else
	{
		rankOfCard = to_string(randForRank);
		valueOfCard = randForRank;
	}
	newCard.m_Rank = rankOfCard;
	newCard.m_Suit = suitOfCard;
	newCard.m_Value = valueOfCard; 

	return newCard; 
}

/*this function uses getACard function to get a card
It then checks if the card is unique or not-if unique it adds it to the deck 
it repeats until 52 cards are added to the deck
it then evenly divides the randomly generated deck among the two players
*/
void divideCards(Player& player1, Player& player2)
{
	Cards card;
	vector<Cards> deck = {};
	bool add = false;
	
	for (int count = 0; count < 52; count++)
	{
		card = getACard();
		for (int z = 0; z < deck.size(); z++)
		{
			if (deck[z].m_Rank != card.m_Rank)
			{
				if (deck[z].m_Suit != card.m_Suit)
				{
					if (deck[z].m_Value != card.m_Value)
						add = true;
				}
			}
		}
		if (add = true)
			deck.push_back(card);
		else
			count--;
	}

	for (int z = 0; z < 26; z++)
		player1.m_MyCards.push_back(deck[z]);
	for (int m = 26; m < 52; m++)
		player2.m_MyCards.push_back(deck[m]);

	cout << "Size of deck is " << deck.size() << endl;
		
}

/*this function, when called, allows one round between 2 players 
passed as arguments
conditions of the game i.e same suit, same rank, etc are checked 
and appropriate action is taken
player stats are updated
in case of same suit, battle() function is called
at the end, score of each player is displayed*/
void playRound(Player& player1, Player& player2)
{
	int response;
	cout << "Press 1 to start round." << endl;
	cin >> response; 
	if (response == 1)
	{
		Cards card1, card2;
		card1= player1.drawCard();
		cout << "Player 1: " << endl;
		showCard(card1);
		card2 = player2.drawCard();
		cout << "Player 2: " << endl;
		showCard(card2);

		
		
		if (card1.m_Suit != card2.m_Suit)
		{
			if (card1.m_Rank != card2.m_Rank)
			{
				if (card1.m_Rank > card2.m_Rank)
				{
					player1.addScore(2);
					player1.m_RoundsWon++;
				}
				else
				{
					player2.addScore(2);
					player2.m_RoundsWon++;
				}
			}
			else if (card1.m_Rank == card2.m_Rank)
			{
				bool exitLoop = false; int cardsNow = 1;
				cout << "Both cards have same rank but different suit." << endl;
				while (exitLoop == false)
				{
					if ((player1.m_MyCards.empty() == true)||(player2.m_MyCards.empty()==true))
					{
						break;
					}
					Cards newCard1, newCard2;
					newCard1 = player1.drawCard();
					newCard2 = player2.drawCard();
					cardsNow++;
					if (newCard1.m_Rank > newCard2.m_Rank)
					{
						player1.addScore(cardsNow);
						player1.m_RoundsWon++;
						exitLoop = true;
					}
					else if (newCard1.m_Rank < newCard2.m_Rank)
					{
						player2.addScore(cardsNow);
						player1.m_RoundsWon++;
						exitLoop = true;
					}
				}
			}
		}
		else
		{
			cout << "Both cards have the same suit, it is time for battle!" << endl;
			battle(card1, card2, player1, player2);
		}

		player1.displayScore(1);
		cout << endl;
		player2.displayScore(2);
		cout << endl; 
		
	}
}

/*it displays the value, rank, and suit of the card which 
is passed as parameter*/
void showCard(Cards cardToShow)
{
	cout << cardToShow.m_Rank 
		 << " of " 
		 << suits[cardToShow.m_Suit] 
		 << " of value " 
		 << cardToShow.m_Value << endl; 
}

/*this function is for battle between players passed as arguments
it draws cards from each player - it checks if cards are available by 
calling function checkIfSuffCards
if cards availabe it draws cards, updates score of each player depending 
on who won or if there was a tie*/
void battle(Cards card1, Cards card2, Player &player1, Player &player2)
{
	int player1Value, player2Value; 
	Cards card2P1, card3P1, card2P2, card3P2; 
	if ((checkIfSuffCards(player1)) && (checkIfSuffCards(player2)))
	{
		card2P1 = player1.drawCard();
		card2P2 = player2.drawCard();
		player1Value = card1.m_Value + card2P1.m_Value;
		player2Value = card2.m_Value + card2P2.m_Value;
		cout << "Player 1 has drawn: " << endl;
		showCard(card2P1); 
		cout << "Player 2 has drawn: " << endl;
		showCard(card2P2); 
	}
	if ((checkIfSuffCards(player1)) && (checkIfSuffCards(player2)))
	{
		card3P1 = player1.drawCard();
		card3P2 = player2.drawCard();
		player1Value += card3P1.m_Value;
		player2Value += card3P2.m_Value;
		cout << "Player 1 has drawn: " << endl;
		showCard(card3P1);
		cout << "Player 2 has drawn: " << endl;
		showCard(card3P2);
	}

	if (player1Value == player2Value)
	{
		player1.addScore(3); player2.addScore(3);
	}
	else if (player1Value > player2Value)
	{
		player1.addScore(6);
		player1.m_BattlesPlayed++;
		player1.m_BattlesWon++;
		player2.m_BattlesPlayed++;
	}
	else
	{
		player2.addScore(6);
		player2.m_BattlesPlayed++;
		player2.m_BattlesWon++;
		player1.m_BattlesPlayed++;
	}
}

/*this function checks whether a player has cards left to 
draw and returns true in case there are cards left*/
bool checkIfSuffCards(Player player)
{
	if (player.m_MyCards.empty() == true)
		return false;

	return true;
}

/*this function displays the statistcs of each player and it 
is called at the end of the game*/
void displayStats(Player player1, Player player2)
{
	cout << "Player 1 stats: " << endl
		<< "#Rounds Won: " << player1.m_RoundsWon << endl
		<< "#Battles Played: " << player1.m_BattlesPlayed << endl
		<< "#Battles Won: " << player1.m_BattlesWon << endl;

	cout << "Player 2 stats: " << endl
		<< "#Rounds Won: " << player2.m_RoundsWon << endl
		<< "#Battles Played: " << player2.m_BattlesPlayed << endl
		<< "#Battles Won: " << player2.m_BattlesWon << endl;
}

/*this function displays the results of the game
i.e who won or if there was a tie*/
void announceWinner(Player player1, Player player2)
{
	if (player1.m_Score > player2.m_Score)
		cout << endl << "Player One wins!" << endl;
	else if (player1.m_Score < player2.m_Score)
		cout << endl << "Player Two wins!" << endl;
	else
		cout << endl << "It is a tie!" << endl;
}