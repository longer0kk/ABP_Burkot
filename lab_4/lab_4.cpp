#include <iostream>

using namespace std;

int lab_4()
{
    const int n = 9; 
    int A[9][9]; 
    int b[9 * 9]; 

    
    for (int i = 0; i < n * n; i++)
    {
        b[i] = n * n - i;
    }

    int a = 0;


    for (int i = 0; i < (n + 1) / 2; i++)
    {

        for (int j = i; j < n - i; j++) {
            A[i][j] = b[a++];
        }
        

        for (int j = i + 1; j < n - i; j++) {
            A[j][n - i - 1] = b[a++];
        }
        

        for (int j = n - i - 2; j >= i; j--) {
            A[n - i - 1][j] = b[a++];
        }
        
 
        for (int j = n - i - 2; j > i; j--) {
            A[j][i] = b[a++];
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << "\t"; 
        }
        cout << endl;
    }

    return 0;
}
