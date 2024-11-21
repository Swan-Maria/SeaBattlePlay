#include "SeaBattle.h"

//���� 1
bool CreateField(char** field, size_t SIZE)
{
    for (size_t i = 0; i < SIZE; ++i)
    {
        for (size_t j = 0; j < SIZE; ++j)
        {
            field[i][j] = '.';
        }
    }
    return true;
}

bool PrintLetterAxis(size_t SIZE)
{
    std::cout << "  ";
    for (size_t i = 0; i < SIZE; ++i) {
        std::cout << ' ' << static_cast<char>('A' + i);
    }
    return true;
}

bool PrintNumberAxis(size_t SIZE, size_t i)
{
    std::cout << std::setw(2) << i + 1 << " ";
    return true;
}

bool PrintField(char** field, size_t SIZE)
{
    PrintLetterAxis(SIZE);
    std::cout << std::endl;
    for (size_t i = 0; i < SIZE; ++i)
    {
        PrintNumberAxis(SIZE, i);
        for (size_t j = 0; j < SIZE; ++j)
        {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return true;
}

bool PrintTwoFields(char** field1, char** field2, size_t SIZE)
{
    PrintLetterAxis(SIZE);
    std::cout << "   ";//���������� ����� ������
    PrintLetterAxis(SIZE);
    std::cout << std::endl;

    for (size_t i = 0; i < SIZE; ++i)
    {
        PrintNumberAxis(SIZE, i);
        for (size_t j = 0; j < SIZE; ++j)
        {
            std::cout << field1[i][j] << " ";
        }
        std::cout << "  ";//���������� ����� ������
        PrintNumberAxis(SIZE, i);
        for (size_t j = 0; j < SIZE; ++j)
        {
            std::cout << field2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return true;
}

bool CoordToLetterNumber(int& x, int& y, char& letter, int& number)
{
    if (x >= 0 && x <= 9 && y >= 0 && y <= 9)
    {
        letter = static_cast <char>('�' + x);
        number = y + 1;
        return true;
    }
    else
        return false;
}

bool LetterNumberToCoord(char& letter, int& number, int& x, int& y)
{
    letter = std::toupper(letter);
    if (letter >= 'A' && letter <= 'J' && number >= 1 && number <= 10)
    {
        x = static_cast<int>(letter - '�');
        y = number - 1;
        return true;
    }
    else
        return false;
}

//���� 2
bool MakeChoice(short& choice)
{
    while (true)
    {
        std::cout << "Select the method of placing ships: 1: automatically, 2: by user.\nInput number: ";
        std::cin >> choice;
        if (std::cin.fail() || (choice != 1 && choice != 2)) // ���� ���������� ���������� ��������� ��������� ��� �����������������
        {
            std::cin.clear(); // �� ���������� cin � '�������' ����� ������
            std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n'); // ������� ������ ��������
            return choice;
        }
    }
    return true;
}

bool GetCoord(short& choice, int& x, int& y, char& letter, int& number)
{
    if (choice == 2)
    {
        do
        {
            std::cout << "Input letter from A to J: ";
            std::cin >> letter;
            if (std::cin.fail() || (letter < 'A' && letter > 'J')) // ���� ���������� ���������� ��������� ��������� ��� �����������������
            {
                std::cin.clear(); // �� ���������� cin � '�������' ����� ������
                std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                std::cin.ignore(32767, '\n'); // ������� ������ ��������
                return letter;
            }

            std::cout << "Input number from 1 to 10: ";
            std::cin >> number;
            if (std::cin.fail() || (number < 1 && number > 10)) // ���� ���������� ���������� ��������� ��������� ��� �����������������
            {
                std::cin.clear(); // �� ���������� cin � '�������' ����� ������
                std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                std::cin.ignore(32767, '\n'); // ������� ������ ��������
                return number;
            }
        } while (!LetterNumberToCoord(letter, number, x, y));
        return true;
    }
    else
    {
        x = rand() % 10;
        y = rand() % 10;
        return true;
    }
}

bool CheckFreePlace(int& deckNumber, int& x, int& y, bool* direction, char** field)
{
    direction[0] = (y - deckNumber >= 0); // up
    direction[1] = (x + deckNumber < SIZE); // right
    direction[2] = (y + deckNumber < SIZE); // down
    direction[3] = (x - deckNumber >= 0); // left

        //To be continued after midnight
        // Up direction
        if (direction[0])
        {
            for (int k = y; k >= y - deckNumber; k--)
            {
                if (field[x][k] == '*')
                {
                    direction[0] = false;
                    break;
                }
            }
            return true;
        }
        else
            return false;
        // Right direction
        if (direction[1])
        {
            for (int k =x ; k <= x + deckNumber; k++)
            {
                if (field[k][y] == '*')
                {
                    direction[1] = false;
                    break;
                }
            }
            return true;
        }
        else
            return false;

        // Down direction
        if (direction[2])
        {
            for (int k = y; k <= y + deckNumber; k++)
            {
                if (field[x][k] == '*')
                {
                    direction[2] = false;
                    break;
                }
            }
            return true;
        }
        else
            return false;

        // Left direction
        if (direction[3]) {
            for (int k = x; k >= x - deckNumber; k--)
            {
                if (field[k][y] == '*')
                {
                    direction[3] = false;
                    break;
                }
            }
            return true;
        }
        else
            return false;
}

bool GetPossibleDirection(short& choice, bool* direction, int& possibleDirection)
{
    char possibleDirections[4] = { 'N', 'E', 'S', 'W' };
    if (choice == 2) {
        while (true)
        {
            std::cout << "Choose a direction:\n";
            for (int i = 0; i < 4; ++i) {
                if (direction[i]) {
                    std::cout << i + 1 << ": " << possibleDirections[i] << std::endl;
                }
            }
            std::cout << "Input number of your choice: ";
            std::cin >> possibleDirection;
            if (std::cin.fail() || (possibleDirection < 1 && possibleDirection > 4)) // ���� ���������� ���������� ��������� ��������� ��� �����������������
            {
                std::cin.clear(); // �� ���������� cin � '�������' ����� ������
                std::cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                std::cin.ignore(32767, '\n'); // ������� ������ ��������
                return possibleDirection;
            }
        }
        possibleDirection -= 1;
        return true;
    }
    else
    {
        do
        {
            possibleDirection = rand() % 4;
        } while (!possibleDirections[choice]);
        return true;
    }
}

bool PlaceShip(int& deckNumber, int& x, int& y, int& posibleDirection, char** field)
{
    if (posibleDirection == 0) //up (N-north)
    {
        for (int k = 0; k < deckNumber; ++k)
            field[x][y - k] = '*';
        return true;
    }
    else
        return false;

    if (posibleDirection == 1) //right (E-east)
    {
        for (int k = 0; k < deckNumber; ++k)
            field[x + k][y] = '*';
        return true;
    }
    else
        return false;

    if (posibleDirection == 2) //down (S-south)
    {
        for (int k = 0; k < deckNumber; ++k)
            field[x][y + k] = '*';
        return true;
    }
    else
        return false;

    if (posibleDirection == 3) //left (W-west)
    {
        for (int k = 0; k < deckNumber; ++k)
            field[x - k][y] = '*';
        return true;
    }
    else
        return false;
}
