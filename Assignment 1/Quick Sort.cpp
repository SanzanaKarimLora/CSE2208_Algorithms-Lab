#include <iostream>
#include <stdlib.h>

using namespace std;

int A[100];



int PARTITION(int p, int r)
{
    int x = A[r];
    int i = p - 1;

    for(int j = p; j <= r - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp2 = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp2;

    return i + 1;
}

void QUICKSORT(int p, int r)
{
    if(p < r)
    {
        int q = PARTITION(p, r);
        QUICKSORT(p, q - 1);
        QUICKSORT(q + 1, r);
    }
}

int main()
{
    int n;

    cout << "Enter the number of integers which you want to sort :";

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        A[i] = rand() % 1000;
    }

    cout << "The unsorted numbers : ";
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";

    QUICKSORT(0, n - 1);

    cout << "The sorted numbers : ";
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";

    return 0;
}
