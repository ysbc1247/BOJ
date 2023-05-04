#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    char c; cin>>c;
    string s; cin>>s;
    vector<char>v;
    int a=0,b=0;
    for(int i=0; i<s.size(); i++){
        v.push_back(s[i]);
        if(s[i]==c){
            a++;
        }
        if(s[i]==tolower(c)){
            b++;
        }
    }
    sort(all(v));
    if(v[0]==c){
        for(int i=0; i<a; i++){
            cout<<(char)c;
        }
        if(b){
            cout<<(char)tolower(c);
        }
        bool chk = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i]==c) continue;
            if(v[i]==tolower(c)){
                if(!chk){
                    chk = 1; continue;
                }
            }
            cout<<(char)v[i];
        }
    }
    else{
        if(b<=1){
            for(int i=0; i<v.size(); i++){
                if(v[i]==tolower(c)||v[i]==c)continue;
                cout<<(char)v[i];
            }
            if(b){
                cout<<(char)tolower(c);
                for(int i=0; i<a; i++){
                    cout<<(char)c;
                }
                for(int i=0; i<b-1; i++){
                    cout<<(char)tolower(c);
                }
            }
            else{
                for(int i=0; i<a; i++){
                    cout<<(char)c;
                }
            }
        }
        else{
            int now = 0;
            string ss = "";
            ss+=(char)tolower(c);
            for(int i=0; i<a; i++){
                ss+=(char)c;
            }
            ss+=(char)tolower(c);
            for(int i=0; i<v.size(); i++){
                if(v[i]==c)continue;
                if(v[i]>=tolower(c)){
                    cout<<ss;
                    now = i; break;
                }
                cout<<v[i];
            }
            if(!now){
                cout<<ss;
            }
            else{
                int ccc = 0;
                for(int i=now; i<v.size(); i++){
                    if(v[i]==c)continue;
                    if(v[i]==tolower(c)){
                        if(ccc<2){
                            ccc++; continue;
                        }
                    }
                    cout<<char(v[i]);
                }
            }
        }
    }
}

