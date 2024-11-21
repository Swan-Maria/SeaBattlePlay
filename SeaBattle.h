#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <cctype>

const int SIZE = 10;
const int Patrol_Boat = 1;
const int Destroyer = 2;
const int Cruiser = 3;
const int Battleship = 4;

//Ётап 1: —оздание игрового пол€ и его вывод в консоль 
bool CreateField(char** field, size_t SIZE);

bool PrintLetterAxis(size_t SIZE);

bool PrintNumberAxis(size_t SIZE, size_t i);

bool PrintField(char** field, size_t SIZE);

bool PrintTwoFields(char** field1, char** field2, size_t SIZE);

bool CoordToLetterNumber(int& x, int& y, char& letter, int& number);

bool LetterNumberToCoord(char& letter, int& number, int& x, int& y);

//Ётап 2: –асположение кораблей на поле
bool MakeChoice(short& choice);

bool GetCoord(short& choice, int& x, int& y, char& letter, int& number);

bool CheckFreePlace(int& deckNumber, int& x, int& y, bool* direction, char** field);

bool GetPossibleDirection(short& choice, bool* direction, int& posibleDirection);

bool PlaceShip(int& deckNumber, int& x, int& y, int& posibleDirection, char** field);
