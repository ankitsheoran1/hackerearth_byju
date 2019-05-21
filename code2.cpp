#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int fa[26]={0};
        int fb[26]={0};
        for(int i=0;i<n;i++){
            fa[s1[i]-'a']++;
            fb[s2[i]-'a']++;
        }
        int res=0;
        for(int i=0;i<26;i++){
            if(fa[i]<=fb[i])
            res+=fa[i];
            else
            res+=fb[i];
        }
        cout<<res<<endl;
    }
    return 0;
}
