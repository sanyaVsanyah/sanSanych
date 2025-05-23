#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>

void inputStr(char** , int*, int );
void sortStr(char** , int* , int);
void outputStr(char**, int* , int );
void deleteMemory(char**, int );
int checkNumber(const char*);

const int MAX_INPUT_LEN = 100;
int main()
{

    setlocale(LC_ALL, "Rus");

    int entryCount{};
    std::cout << "Введите кол-во строк: ";
    std::cin >> entryCount;
    std::cin.ignore();

    char** wordArray = new char* [entryCount];
    int* numberArray = new int[entryCount];

    inputStr(wordArray, numberArray, entryCount);
    sortStr(wordArray, numberArray, entryCount);
    outputStr(wordArray, numberArray, entryCount);

    deleteMemory(wordArray, entryCount);
    delete[] wordArray;
    delete[] numberArray;

    return 0;
}


int checkNumber(const char* inputLine) 
{

    int number{ 0 };
    bool foundDigit = false;

    for (int i = 0; inputLine[i] != '\0'; ++i)
    {
        if (inputLine[i] >= '0' && inputLine[i] <= '9') 
        {
            number = number * 10 + (inputLine[i] - '0');
            foundDigit = true;
        }
        else if (foundDigit) 
        {
            break; 
        }
    }
    return number;
}


void sortStr(char** wordList, int* numList, int count) {
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = 0; j < count - i - 1; ++j) 
        {
            if (numList[j] > numList[j + 1]) 
            {
                std::swap(numList[j], numList[j + 1]);
                std::swap(wordList[j], wordList[j + 1]);
            }
        }
    }
}

void inputStr(char** wordList, int* numList, int count) 
{
    for (int i = 0; i < count; ++i) 
    {
        char inputLine[MAX_INPUT_LEN];
        std::cout << "Введите строку " << i + 1 << ": ";
        std::cin.getline(inputLine, MAX_INPUT_LEN);

        char* word = strtok(inputLine, " ");
        char* numStr = strtok(nullptr, " ");

        if (word && numStr) 
        {
            wordList[i] = new char[strlen(word) + 1];
            strcpy(wordList[i], word);
            numList[i] = std::atoi(numStr);
        }
        else
        {
            wordList[i] = new char[5];
            strcpy(wordList[i], "null");
            numList[i] = 0;
        }
    }
}


void outputStr(char** wordList, int* numList, int count)
{
    std::cout << "Отсортированные строки:\n";
    for (int i = 0; i < count; ++i)
    {
        std::cout << i + 1 << "-ая строка после сориторовки: " << wordList[i] << " -> " << numList[i] << "\n";
    }
}
void deleteMemory(char** wordList, int count)
{
    for (int i = 0; i < count; ++i) 
    {
        delete[] wordList[i];
    }
}

