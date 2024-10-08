// 4 Varik

#include <iostream>

using namespace std;

void n1_lab6(int* B, int size)
{
    for (int i = 0; i < size; i++)
    {
        B[i] = i + 1;
    }
}

void n2_lab6(int** A, int* B, int n)
{
    int c = 0;

    for (int i = 0; i < (n + 1) / 2; i++)
    {

        for (int j = i; j < n - i; j++) {
            A[j][i] = B[c++];
        }

        for (int j = i + 1; j < n - i; j++) {
            A[n - i - 1][j] = B[c++];
        }

        for (int j = n - i - 2; j >= i; j--) {
            A[j][n - i - 1] = B[c++];
        }


        for (int j = n - i - 2; j > i; j--) {
            A[i][j] = B[c++];
        }

    }
}

void n3_lab6(int** A, int n)
{
   for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << "\t"; 
        }
        cout << endl;
    } 
}

int lab_6()
{
    int n;
    cout << "Rozmirnist` matrici: ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Nepravilna rozmirnist` matrici. Treba vid 1 do 100." << endl;
        return 1;
    }

    int** A = new int*[n];
    for (int a = 0; a < n; a++)
    {
        A[a] = new int[n];
    }

    int* B = new int[n*n];

    n1_lab6(B, n * n);
    n2_lab6(A, B, n);
    n3_lab6(A, n);
    return 0;
}