#include <bits/stdc++.h>

using namespace std;

int LEFT(int i)
{
    return 2 * i;
}

int RIGHT(int i)
{
    return 2 * i + 1;
}

void MAX_HEAPIFY(int A[], int i, int n)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;

    if((l <= n) && (A[l] > A[i]))
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if((r <= n) && (A[r] > A[largest]))
    {
        largest = r;
    }

    if(largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MAX_HEAPIFY(A, largest,n);
    }
}

void BUILD_MAX_HEAP(int A[], int n)
{
    for(int i = n/2; i >= 1; i--)
    {
        MAX_HEAPIFY(A,i,n);
    }
}

void HEAPSORT(int A[],int n)
{
    BUILD_MAX_HEAP(A,n);
    for(int i = n; i >= 2; i--)
    {
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;

        MAX_HEAPIFY(A,1,i-1);
    }
}


int main()
{


    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    int A[n];

    cout << "Enter the elements in the array : ";
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    HEAPSORT(A,n);

    cout<<"The sorted array : ";
    for (int i = 1; i <= n; i++)
    {
        cout <<A[i] <<" ";
    }
    cout << endl;

    return 0;
}
