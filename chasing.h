#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void chasing(int **A[], int a, int *B[], int b, int C[], int c);
bool isInputValid(std::string line, int a, int b, int c);

void chasing(int **A[], int a, int *B[], int b, int C[], int c)
{

    std::ifstream inFile("input.txt");
    std::string line;

    while (getline(inFile, line))
    {
        std::string letter;
        int index[2];
        std::istringstream ss(line);

        if (isInputValid(line, a, b, c))
        {
            std::string dismisal;
            ss >> letter;
            if (letter == "A")
            {
                ss >> index[0] >> dismisal >> index[1];
                A[index[0]] = &B[index[1]];
            }
            else
            {
                ss >> index[0] >> dismisal >> index[1];
                B[index[0]] = &C[index[1]];
            }
        }
    }
}

bool isInputValid(std::string line, int a, int b, int c)
{
    std::string argsArr[2];
    int argsIndex[2];
    std::istringstream ss(line);

    if (!(ss >> argsArr[0] >> argsIndex[0] >> argsArr[1] >> argsIndex[1]))
    {
        return false;
    }
    else
    {
        if (argsArr[0] == "A" && argsArr[1] == "B")
        {
            if (argsIndex[0] >= 0 && argsIndex[0] < a && argsIndex[1] >= 0 && argsIndex[1] < b)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (argsArr[0] == "B" && argsArr[1] == "C")
        {
            if (argsIndex[0] >= 0 && argsIndex[0] < b && argsIndex[1] >= 0 && argsIndex[1] < c)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
}
