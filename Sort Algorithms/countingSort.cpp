#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX 100
void inPut(int a[], int &n, int &max)
{
    do
    {
        cout << "\nEnter amount element of array: ";
        cin >> n;

    } while (n <= 0 || n > MAX);
    max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a[" << i << "] = ";
        cin >> a[i];
        if (max < a[i])
            max = a[i];
    }
    
}

void countSort(int a[], int b[], int n, int k){
    int *c = new int[k + 1];
    // return array is b[]
    for (int i = 0; i <= k; i++)

        c[i] = 0; // to count amount appear of a element in Array
        // Lôop browsing to count amount appear value
    // number of occurrences
    for (int i = 0; i < n; i++)
    
        c[a[i]]++;
    // converd from c[] to b[]
    int j = 0;
    for (int i = 0; i <= k; i++)
    
        while (c[i] > 0)
        {
            b[j++] = i;
            c[i]--;
        }

    delete []c;
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
    int a[MAX], b[MAX], n, k;
    // Max value of Array
    inPut(a, n, k);
    cout << "\nBefore Sort\n";
    outPut(a, n);
    cout << "\nAfter Sort\n";
    countSort(a, b, n, k);
    outPut(b, n);

    cout << endl;

    system("pause");
    return 0;
}