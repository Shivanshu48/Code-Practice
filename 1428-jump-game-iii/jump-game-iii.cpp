class Solution {
public:
    int n;
    bool solve(vector<int>& arr, int start) {
        if(start < 0 || start >= n || arr[start] < 0){
            return false;
        }
        if(arr[start] == 0){
            return true;
        }
        arr[start] *= -1;
        int left  = solve(arr, start-arr[start]);
        int right = solve(arr, start+arr[start]);
        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        return solve(arr, start);
    }
};