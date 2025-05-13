class NumberContainers {
        
   private Map<Integer, Integer> indexToNumber;
    private Map<Integer, TreeSet<Integer>> numberToIndices;

    public NumberContainers() {
        indexToNumber = new HashMap<>();
        numberToIndices = new HashMap<>();
    }

    public void change(int index, int number) {
        if (indexToNumber.containsKey(index)) {
            int oldNumber = indexToNumber.get(index);
            if (oldNumber != number) {
                TreeSet<Integer> oldSet = numberToIndices.get(oldNumber);
                if (oldSet != null) {
                    oldSet.remove(index);
                    if (oldSet.isEmpty()) {
                        numberToIndices.remove(oldNumber);
                    }
                }
            }
        }

        indexToNumber.put(index, number);
        numberToIndices.putIfAbsent(number, new TreeSet<>());
        numberToIndices.get(number).add(index);
    }

    public int find(int number) {
        if (!numberToIndices.containsKey(number)) {
            return -1;
        }

        TreeSet<Integer> indices = numberToIndices.get(number);
        if (indices.isEmpty()) {
            return -1;
        }

        return indices.first(); // smallest index for this number
}
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */