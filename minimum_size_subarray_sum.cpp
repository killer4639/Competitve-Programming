class Solution {
public:
    bool isPossible(vector<int> &nums, int mid, int target)
    {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<mid-1;i++){
            sum+=nums[i];
        }
        for(int i=mid-1;i<n;i++){
            sum+=nums[i];
            if(sum>=target){
                return true;
            }
            sum-=nums[i-mid+1];
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n;
        int d=n+1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(nums,mid,target))
            {
                d=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        if(d==n+1){
            d=0;
        }
        return d;
    }
};
