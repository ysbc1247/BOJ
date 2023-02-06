#include<bits/stdc++.h>
using namespace std;double k;int main(){string s; cin>>s;vector<string>v={"1","2","6","24","120","720"};if(find(v.begin(),v.end(),s)!=v.end()){for(int i=0; i<v.size(); i++){if(v[i]==s){cout<<i+1; return 0;}}}int i=0;while(1){i++;k+=log10(i);if(floor(k)==s.size()-1){cout<<i;break;}}}
