class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        int counter = 0;
        vector<int> first(8); //after N days
        
        for(int i=1; i<7; i++) //for comparison
            first[i] = (cells[i-1] == cells[i+1]) ? 1:0;
        
        counter++;
        //decrement day_count
        N -= 1;
        
        for(int i=0; i<8; i++) //back into cells for comparison
            cells[i] = first[i];    
        
        while(N--){
            vector<int> t(8);      
            for(int i=1; i<7; i++){
                //if(i==0 || i == 7) t[i] = cells[i];
                t[i] = (cells[i-1] == cells[i+1] ? 1 : 0);
            }
            if(first == t) //optimisation.. 
                N = N % counter;
            for(int i=0; i<8; i++)
                cells[i] = t[i]; //copy back to og
            counter++;
        }    
        return cells;
    }
};