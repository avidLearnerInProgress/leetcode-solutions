// "static void main" must be defined in a public class.
//https://leetcode.com/discuss/interview-question/365872/Microsoft-or-OA-2019-or-Max-Sum-Formed-by-Any-2-Numbers

//assumptions
// num > 0
// two digit nums
// same digit sum less 10 ?
public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        System.out.println(main.getSameDigitLargestSum(new int[]{51, 71, 17, 42, 33, 44, 24, 62}));
        System.out.println(main.getSameDigitLargestSum(new int[]{51, 71, 17, 42}));
        System.out.println(main.getSameDigitLargestSum(new int[]{42, 33, 60}));
        System.out.println(main.getSameDigitLargestSum(new int[]{51, 32, 43}));
    }
    
    private int getSameDigitLargestSum(int[] nums) {
        int result = -1;
        if(nums == null || nums.length == 0) return result;
        Map<Integer, Integer> map = new HashMap<>();
        
        /*
        System.out.println(main.getSameDigitLargestSum(new int[]{51, 71, 17, 42, 33, 44, 24, 62}));
            map:
                a. 6 => 51
                b. 8 => 71
                c. 8 => max(71, 17) => result := max(-1, 17 + 71)
                d. 6 => max(51, 42) => result := max(17 + 71, 51 + 42) 
                e. 6 => max(51, 33) => result := max(51 + 42, 51 + 33)
                f. 8 => max(71, 44) => result := max(51 + 42, 71 + 44)
                g. 6 => max(51, 24) => result := max(71 + 44, 51 + 24)
                h. 8 => max(71, 62) => result := max(71 + 44, 71 + 62)
        */
        
        for(int num : nums) {
            int sum = getSum(num);
            if(map.containsKey(sum)) {
                result = Math.max(result, num + map.get(sum));  //max(-1, 17 + 71)
                map.put(sum, Math.max(num, map.get(sum)));
            } else {
                map.put(sum, num);
            }
        }
        return result;
    }
    
    private int getSum(int num) {
        int sum = 0;
        while(num >0) {
            sum += num%10;
            num /=10;
        }
        return sum;
    }
}