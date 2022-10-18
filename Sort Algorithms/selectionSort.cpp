#include <bits/stdc++.h>

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
void inPut(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void outPut(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n;
    cout << "\nEnter n: ";
    cin >> n;

    int a[n];
    cout << "\nEnter value for Array\n";
    inPut(a, n);

    cout << "\nBefor Sort\n";
    outPut(a, n);

    selectionSort(a, n);

    cout << "\nAfter Sort\n";
    outPut(a, n);

    system("pause");
    return 0;
}