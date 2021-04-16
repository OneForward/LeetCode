import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> M = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            Integer j = M.get(target - nums[i]);
            if (  j != null )  return new int[]{j, i};
            M.put(nums[i], i);
        }
        return null;
    }
}

/**
 * leet000
 */
public class leet000 {

    public static void main(String[] args) {
        var sol = new Solution();
        System.out.println(Arrays.toString(sol.twoSum(new int[] {2, 7, 11, 15}, 9)));
    }
}