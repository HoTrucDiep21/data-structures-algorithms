#include<iostream>
using namespace std;
void nextBits(string s){
    bool check = false;
    int n = s.length()-1;
    for (int i = n; i >= 0; i--)
    {
        if (s[i]=='0')
        {
            s[i] = '1';
            check = true;
            break;

        }
        
    }
    if (check == true)
    {
        for (int i = n+1; i <= s.length(); i++)
        {
            s[i] = '0';
        }
        cout << s;
    }
    else
    {
        cout << "No!!";
    }
    
}
int main(){
    string s;
    cin >> s;
    nextBits(s);
    return 0;
}