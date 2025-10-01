class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> outer = new ArrayList<>();
        //outer.add(new ArrayList<>());
        List<Integer> internal = new ArrayList<>();
        //internal.add(new ArrayList<>());
        helper(nums,0,internal, outer);
        return outer;
        
    }

    public static void helper(int nums[], int i, List<Integer> internal, List<List<Integer>> outer){
        
        
        if(i >= nums.length)
        {
            outer.add(new ArrayList<>(internal));
            return;
        }

        internal.add(nums[i]);
        helper(nums, i+1,internal,outer);

        internal.remove(internal.size()-1);
        helper(nums, i+1, internal, outer);

    }
}