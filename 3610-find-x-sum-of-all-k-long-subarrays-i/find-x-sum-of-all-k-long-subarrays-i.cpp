class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i=0; i<k; i++){
            freq[nums[i]]++;
        }
        auto getXSum=[&](){
            vector<pair<int,int>> v(freq.begin(),freq.end());

            sort(v.begin(),v.end(),[&](auto&a,auto&b){
                if(a.second == b.second){
                    return a.first>b.first;
                }

                return a.second>b.second;
            });

            int sum = 0,cnt = 0;

            for(auto&p:v){
                if(cnt == x) break;
                sum += p.first*p.second;
                cnt++;
            }
            return sum;
    };

    ans.push_back(getXSum());
        for(int i=k; i<n;i++){
            if(--freq[nums[i-k]]==0){
                freq.erase(nums[i-k]);
            }
            freq[nums[i]]++;
            ans.push_back(getXSum());
        }
        return ans;
    }
};