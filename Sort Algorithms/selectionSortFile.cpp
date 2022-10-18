#include <bits/stdc++.h>
#include <fstream>

using namespace std;
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])

                min_pos = j;
            if (min_pos != i)
            {
                int temp = a[i];
                a[i] = a[min_pos];
                a[min_pos] = temp;
            }
        }
    }
}
void readFile(ifstream &fileIn, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        fileIn >> a[i];
    }
}
void showArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    ifstream fileIn;
    fileIn.open("selectionFileIn.txt");
    
    int n;

    fileIn >> n;
    int a[n];
    readFile(fileIn, a, n);

    cout << "\nValue after read File\n";
    showArray(a, n);

    selectionSort(a, n);
    cout << "\nAfter Sort\n";
    showArray(a, n);

    cout << endl;
    system("pause");

    return 0;
}