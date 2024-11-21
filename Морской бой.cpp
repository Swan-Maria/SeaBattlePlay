#include "SeaBattle.h"

int main()
{
	srand(time(NULL));

	char** field1 = new char* [SIZE];
	//char** field2 = new char* [SIZE];
	for (size_t i = 0; i < SIZE; ++i)
	{
		field1[i] = new char[SIZE];
		//field2[i] = new char[SIZE];
	}
	CreateField(field1, SIZE);
	//CreateField(field2, SIZE);

	int ships[SIZE] = { Battleship, Cruiser, Cruiser, Destroyer, Destroyer, Destroyer, Patrol_Boat, Patrol_Boat, Patrol_Boat, Patrol_Boat };

	short choice;
	MakeChoice(choice);

	for (int k = 0; k < SIZE; ++k)
	{
		int x = 0, y = 0, number = 0;
		char letter;
		int deckNumber = ships[k];
		bool direction[4];
		int possibleDirection;
		do
		{
			GetCoord(choice, x, y, letter, number);
			CheckFreePlace(deckNumber, x, y, direction, field1);
			GetPossibleDirection(choice, direction, possibleDirection);
		} while (!PlaceShip(deckNumber, x, y, possibleDirection, field1));
		/*
		while (true)
		{
			GetCoord(choice, x, y, letter, number);
			CheckFreePlace(deckNumber, x, y, direction, field1);
			GetPossibleDirection(choice, direction, possibleDirection);
			if (PlaceShip(deckNumber, x, y, possibleDirection, field1))
				break;
		}
		*/
	}


	PrintField(field1, SIZE);
	//PrintField(field2, SIZE);
	//PrintTwoFields(field1, field2, SIZE);

	for (size_t i = 0; i < SIZE; ++i)
	{
		delete[] field1[i];
		//delete[] field2[i];
	}
	delete[] field1;
	//delete[] field2;

	return 0;
}