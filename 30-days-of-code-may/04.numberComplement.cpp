class Solution {
public:
    int findComplement(int num) {
      
        
        if(num == 0) return 0;
        vector<int> bits;
        
        while(num != 0){
            bits.push_back(num % 2);    
            num /= 2;
        }
        //for(auto i : bits)cout<<i<<" ";
        //cout<<"\n";
        
        reverse(bits.begin(), bits.end());
        
        //for(auto i : bits)cout<<i<<" ";
        vector<int> complement;
        for(auto i : bits){
            if(i == 0)
                complement.push_back(1);
            else
                complement.push_back(0);
        }
        
        //cout<<"\n";
        //for(auto i : complement)cout<<i<<" ";
        
        int sz = complement.size()- 1;
        unsigned int complement_no = 0;
        for(int i=sz; i>=0; i--){
            //cout<<"sz-i: "<<sz-i<<"\t";
            int expr = (complement[i] * pow(2, (sz- i)));
            //cout<<expr<<"\t\n";
            complement_no += expr;
        }
        
        //cout<<complement_no<<"\n";
        return complement_no;
    }
};