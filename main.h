/*
Ramsha Bilal
bilal_week4_gp
Game Project 4
main.h
PC
*/

#ifndef MAIN_H
#define MAIN_H


void gameOfWar();
void divideCards(Player& player1, Player& player2);
void battle(Cards card1, Cards card2, Player& player1, Player& player2);
bool checkIfSuffCards(Player player);
void showCard(Cards cardToShow);
void playRound(Player& player1, Player& player2);
Cards getACard();
void announceWinner(Player player1, Player player2);
void displayStats(Player player1, Player player2);

#endif

