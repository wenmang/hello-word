import java.util.*;

class fullArray {
    public List<List<Integer>> fullArray(int n) {
        List<List<Integer>> ret = new LinkedList<>();
        ArrayList<Integer> nums = new ArrayList<>();

        for (int i = 1; i <= n; i++)
            nums.add(i);
        helper(n, nums, ret, 0);
        return ret;
    }


    private void helper(int n, ArrayList<Integer> nums, List<List<Integer>> ret, int index) {
        if (index == n)
            ret.add(new ArrayList<>(nums));

        for (int i = index; i < n; i++) {
            Collections.swap(nums, i, index);
            helper(n, nums, ret, index+1);
            Collections.swap(nums, i, index);
        }
    }

    public static void main(String[] args) {
        fullArray test = new fullArray();
        List<List<Integer>> ret = test.fullArray(4);
        for (List i:ret)
            System.out.println(i);
    }
}
