class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> outer = new ArrayList<>();
        outer.add(new ArrayList<>());
        for(int i = 0; i < nums.length; i++){
            int n = outer.size();
            for(int j = 0; j < n; j++){
                List<Integer> internal = new ArrayList<>(outer.get(j));
                internal.add(nums[i]);
                outer.add(internal);
            }
        }
        return outer;
    }
}