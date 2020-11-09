class Solution {
public:
    string intToRoman(int num) {
        if(num == 0) return "";
        
        string table[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        
        //2538 => run through this example when revisiting code.
        
        int count = 0; //gives the index of row in table.. 10's place, 100's place, 1000's place
        string result = "";
        while(num > 0) {
            int value = num % 10; //gives the index in the row of table basicall
            result = table[count][value] + result;
            count++;
            num /= 10;
        }
        return result;
    }
};
