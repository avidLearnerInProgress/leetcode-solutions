#include <bits/stdc++.h>
using namespace std;

int makeAnagram(string a, string b) {

    char hashmap[26] = {0};

    for(auto& c: a)hashmap[c-'a']++;
    for(auto& c: b)hashmap[c-'a']--; //all repeated characters get 0 as their count in the freq

    int count = 0;
    for(auto& x : hashmap)count += abs(x);
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string a;
    getline(cin, a);
    string b;
    getline(cin, b);
    int res = makeAnagram(a, b);
    fout << res << "\n";
    fout.close();
    return 0;
}
