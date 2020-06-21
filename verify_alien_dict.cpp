class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0 ;i <words.size() - 1; i++){
            const auto& word1 = words[i];
            const auto& word2 = words[i + 1];
            auto i1 = 0, i2 = 0;
            while(word1[i1] == word2[i2]){       
                i1++; i2++;
            }

            i1 = order.find(word1[i1]);
            i2 = order.find(word2[i2]);
            if(i1 > i2) return false;
        }
        return true;
    }
};