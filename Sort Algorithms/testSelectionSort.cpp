#include <iostream>
using namespace std;
void selectionSort();
void input();
void output();

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void input(int a[], int n)
{
    cout << "\nInput data for Array\n";
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n;
    cout << "input n: ";
    cin >> n;

    int a[n];

    input(a, n);
    cout << "\nArray before Sort\n";
    output(a, n);
    selectionSort(a, n);
    cout << "\nArray after Sort\n";
    output(a, n);

    return 0;
}