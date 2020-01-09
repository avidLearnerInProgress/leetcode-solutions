class solution{
    public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        // prefix vector
        vector<vector<int>> vec;
        
        // current sum
        vector<int> tmp(26, 0);
        vec.push_back(tmp);
        
        // fill prefix vector
        for(int i=0; i<s.size(); i++){
            tmp[s[i]-'a']++;
            vec.push_back(tmp);
        }
        
        vector<bool> ans;
        for(auto const& q: queries){
            int lo = q[0], hi = q[1], k = q[2];
            vector<int> cnt = vec[hi+1];
            
            // odd = elements to be matched
            int odds = 0, sum = 0;
            
            // compute letter count from prefix array
            for(int i=0; i<26; i++){
                cnt[i]-=vec[lo][i];
                sum += cnt[i];
                odds += (cnt[i]%2);
            }
            
            // if total sum of elements is odd, decrement odds--
            // we can change odds/2 elements to match other odds/2 elements so odds/2<=k or rewriting it as odds<=2*k(considering odds can be odd ^_^)
            ans.push_back((odds-=(sum%2))<= k*2?true:false);
            
        }
        return ans;
    }
}

    /*
    class Solution {
public:
bool checkPalin(string s){
    int start = 0, end = s.length() - 1;
    while(end > start){
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}

bool canMakePalinSubStr(string &substr, int k){
    if(substr.length() == 0) return false;
    int start = 0, end = substr.length() - 1;
    
    //if(k > end) return false;
    // k represents the possible no of modifications allowed in a substr 
    int mid = start + (end - start) / 2;
    cout<<mid<<"\n";
    /*
    string newstr = "";
    
    while(start <= end){
        newstr += substr[end];
        start++;
        end--;
    }
    cout<<newstr<<"\n";
    *//*
    cout<<"k: "<<k<<"\n";
    string m_start = "", m_end = "";
    sort(substr.rbegin() + mid,substr.rend());
    while(start <= mid){
        if(k == 0) break;
        if(substr[end] != substr[start]){
            //string m_start = "";
            //string m_end = "";
            substr[end] = substr[start]; //--> greedy approach jsut replaces end..
            //can be replaced at start as well
            k--;
        }
        //cout<<substr[start]<<"\t"<<substr[end];
        end--; start++;
    }
    cout<<"Modified substr:- "<<substr<<"\n";
    if(checkPalin(substr))
                return true;
            else
                return false;        
}

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries){
    if(s == "" or queries.size() == 0){
        return {};
    }
    string current_substr;
    int start, end, k;
    vector<bool> result;
    
    for(int i=0; i<queries.size(); i++){
        current_substr = "";
        start = queries[i][0];
        end = queries[i][1];
        k = queries[i][2];
        if(end > s.length() - 1 || start > s.length() - 1) result.push_back(false);
        else{
            while(start <= end){
                current_substr += s[start];
                start++;
            }//now I have complete substr   to perform operation.
            cout<<"Original substr:- "<<current_substr<<"\n";
            result.push_back(canMakePalinSubStr(current_substr, k));
        }
    }
    for(bool r: result)
        cout<<r<<" ";
    return result;
    }
};  
*/
    