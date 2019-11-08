#include<bits/stdc++.h>
using namespace std;

string findWindow(string str, string pat){
    if(pat.size() > str.size())
        return "-1";
    int hashPat[256]={0};
    int hashStr[256]={0};
    for(int i=0; i<pat.size(); i++){
        hashPat[pat[i]]++;
    }
    int count = 0;
    int startMin = -1;
    int start = 0;
    int minWin = INT_MAX;
    for(int i=0; i<str.size(); i++){
        if(hashPat[str[i]]!=0){ // useful char
            if(hashPat[str[i]] > hashStr[str[i]]){
                count++;
            }
            hashStr[str[i]]++;
            if(count == pat.size()){
                while(hashPat[str[start]] == 0 || hashPat[str[start]]<hashStr[str[start]]){
                    if(hashPat[str[start]] != 0){
                        hashStr[str[start]]--;
                    }
                    start++;
                }
                if(minWin > i-start+1){
                    startMin = start;
                    minWin = i-start+1;
                }
            }
        }
    }
    if(startMin!=-1){
        return str.substr(startMin, minWin);
    }
    return "-1";
}
int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        string pat;
        string str;
        cin >> str;
        cin >> pat;
        cout << findWindow(str, pat) << endl;
    }
	return 0;
}