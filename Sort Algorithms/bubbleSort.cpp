#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void readFile(ifstream &fileIn, int a[], int n){
    for (int i = 0; i < n; i++)
    {
        fileIn >> a[i];
    }
    

}
void showArray(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
}

int main(){
    ifstream fileIn;
    fileIn.open("bubleSortFileIn.txt");

    int n;
    fileIn >> n;
    int a[n];
    readFile(fileIn, a, n);

    cout << "\nValue after readFile\n";
    showArray(a, n);

    fileIn.close();

    return 0;
}