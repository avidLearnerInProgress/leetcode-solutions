class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts,long long s=0) {
        // walk from the end of the string add the shifts and change the char at that pos 
        for(int i=shifts.size()-1; i>=0; i--) {
            s += shifts[i];  // sum of shifts
            long long perShift = (S[i]-'a'+s) % 26; // at a particular pos , (sum of shifts + pos of char between 0..25) % 26 
            S[i] = (char)(perShift+'a'); // change the char at every pos of the given string to the new shifted char
        }
        return S;
    }
};
