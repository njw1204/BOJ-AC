#include <bits/stdc++.h>
using namespace std;
string s[1005];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    sort(s,s+n,[](string a,string b){
        if(a.length()!=b.length()) return a.length()<b.length();
        else{
            int ca=0,cb=0;
            for(int i=0;i<a.length();i++){
                ca+=('0'<=a[i]&&a[i]<='9'?a[i]-'0':0);
                cb+=('0'<=b[i]&&b[i]<='9'?b[i]-'0':0);
            }
            if(ca!=cb) return ca<cb;
            else return a<b;
        }
    });
    for(int i=0;i<n;i++)
        cout << s[i] << endl;
    return 0;
}