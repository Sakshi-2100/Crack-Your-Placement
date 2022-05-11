#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(string s){
    unordered_map<char, int>mp;
    for(auto i : s){
        mp[i]++;
    }
    for(auto i : mp){
        if(i.second>1)
            cout<<i.first<<" "<<i.second<<endl;
    }
} 

int main() {
    string s;
    cin>>s;
    print(s);
	return 0;
}