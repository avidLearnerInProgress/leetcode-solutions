class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       if(s2.size() < s1.size()) return false;
    
    std::vector<int> vs1(26, 0);
    
    for(const auto &el: s1)
    {
        vs1[el - 'a']++;
    }

    std::vector<int> vtmp(26, 0);
    const std::string tmp = s2.substr(0, s1.size());

    for(const auto &el: tmp)
    {
        vtmp[el - 'a']++;
    }

    if(vtmp == vs1)
    {
        return true;
    }

    for(size_t i = 1; i <= s2.size() - s1.size(); i++)
    {   
        const auto c1 = s2[i-1];
        const auto c2 = s2[i+s1.size()-1];

        vtmp[c1 - 'a']--;
        vtmp[c2 - 'a']++;

        if(vtmp == vs1)
        {
            return true;
        }
    }

    return false;
}
};