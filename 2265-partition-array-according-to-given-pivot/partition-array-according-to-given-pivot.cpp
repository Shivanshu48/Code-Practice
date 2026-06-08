class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> arr1;
        vector<int> arr2;
        int c = 0;
        for(int i : nums){
            if(i < pivot){
                arr1.push_back(i);
            }
            else if(i == pivot){
                c++;
            }
            else{
                arr2.push_back(i);
            }
        }
        
        while(c != 0){
            arr1.push_back(pivot);
            c--;
        }
      
        for(int i = 0; i < arr2.size(); i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};