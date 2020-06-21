  size_t len = nums.size();
        if(len < 3) return false;
        // seq1 is the count of sequences with a single number
        // seq2 is the count of sequences with 2 numbers 
        // seq is the count of sequences has 3 or more numbers
        // count is the count of current number
        // prevNum is the previous number
        int seq1 = 0, seq2 = 0, seq = 0, count = 0, prevNum = nums[0];
        for(size_t i = 0; i < len; i++){
            count = 1;
            // Count current number.
            // When the loop ends, the pointer stays in the last item of current number and the count is the total count of current number
            while(i < len - 1 && nums[i] == nums[i+1]){ 
                    count++; i++;
            }
            
            if(prevNum < nums[i] - 1){
                // If there is a gap, all sequences should start over, if there are incomplete sequences, the assert fails.
                if(seq1 + seq2 > 0) return false;
                seq = 0;
            }else{
                int all_seq = seq1 + seq2 + seq;
                // If current number has enough items, they can lengthen all sequences
                // And after that the remaining items of current number become single number sequences
                if(count > all_seq){
                    seq += seq2;
                    seq2 = seq1;
                    seq1 = count - all_seq;
                }else if(count >= seq1 + seq2){ // Current number has enough items to lengthen all incomplete sequences (length == 1 or 2)                    
                    seq = count - seq1;
                    seq2 = seq1;
                    seq1 = 0;
                }else 
                    return false; // Current number doesn't have enough items to lengthen all incomplete sequences, game over.
            }

            prevNum = nums[i];
        }
        
        return seq1 + seq2 == 0;