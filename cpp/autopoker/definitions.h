//definitions

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

const int totalCards = 52;
const int deckRows = 4;
const int deckColumns = 13;

int deck[ deckRows ][ deckColumns ] = { 0 };

char *suite[ 4 ] = { "Hearts", "Diamonds", "Spades", "Clubs" };
char *face[ 13 ] = { "1-Ace", "2-Deuce", "3-Three", "4-Four", "5-Five", "6-Six", "7-Seven", "8-Eight", "9-Nine", "10-Ten", "11-jack", "12-Queen", "13-King" };

#endif
