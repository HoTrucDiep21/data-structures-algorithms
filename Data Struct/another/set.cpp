#include<bits/stdc++.h>
#include<set>

using namespace std;

int main(){

    set<int> s;
    for (int i = 0; i < 10; i++)
    {
        s.insert(i);
    }
    if (s.count(9)!=0)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found";
    }
    
 

    cout << s.size()<< endl;
    return 0;
}