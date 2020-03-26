#include <iostream>
#include "chasing.h"

using namespace std;


int main()
{
    int a = 3, b = 3, c = 3;
    int **A[3] = {}, *B[3] = {}, C[3] = {2, 1, 4};
    chasing(A, a, B, b, C, c);

    int **ansA[3] = {}, *ansB[3] = {};
    for (int i = 0; i < a; i++)
        ansA[i] = NULL;
    for (int i = 0; i < b; i++)
        ansB[i] = NULL;
    ansA[0] = &B[0], ansA[1] = &B[2], ansB[0] = &C[2], ansB[1] = &C[1];
    /*Check A*/
    for (int i = 0; i < a; i++)
        if (A[i] != ansA[i])
            cout << "A[" << i << "] wrong answer!" << endl;

    /*Check B*/
    for (int i = 0; i < b; i++)
        if (B[i] != ansB[i])
            cout << "B[" << i << "] wrong answer!" << endl;

    return EXIT_SUCCESS;
}

