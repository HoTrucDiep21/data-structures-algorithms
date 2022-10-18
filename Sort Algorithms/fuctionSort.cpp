#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    // int n;
    // cout << "\nenter n: ";
    // cin >> n;

    // string a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    // sort(a, a + n, greater<string>());

    // for (string x : a)
    //     cout << x << " ";

    string s;
    getline(cin, s);
    sort(s.begin(), s.end());

    cout << s << endl;

    return 0;
}
