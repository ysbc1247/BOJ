#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> p, vector<string> c) {
    string answer = "";
    map<string,int>mp;
    for(int i=0; i<p.size(); i++){
        mp[p[i]]++;
    }
    for(int i=0; i<c.size(); i++){
        mp[c[i]]--;
    }
    for(auto i:mp){
        if(i.second){
            answer = i.first; break;
        }
    }
    return answer;
}