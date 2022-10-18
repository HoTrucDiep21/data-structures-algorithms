#include <iostream>

using namespace std;

int partintion(int a[], int s, int e)
{
    int pivot = a[e];
    int pIndex = s;
    for (int i = s; i < e; i++)
    {
        if (a[i] < pivot)
        {
            int temp = a[i];
            a[i] = a[pIndex];
            a[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = a[e];
    a[e] = a[pIndex];
    a[pIndex] = temp;
    return pIndex;
}

void quickSort(int a[], int s, int e)
{
    if (s < e)
    {
        int p = partintion(a, s, e);
        quickSort(a, s, (p - 1));
        quickSort(a, (p + 1), e);
    }
}

int main()
{
    cout << "\ninput n: ";
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "\nBefore Sorrt\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    quickSort(a, 0, n - 1);
    cout << "\nAfter Sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}