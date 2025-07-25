class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
      if(n==0) return 0;
       sort(nums.begin(),nums.end());
       int len=1;
       int ans=1;
       int cur=nums[0];
       for (int i = 1; i < n; i++) {
    if (nums[i] == cur) {
        continue; // skip duplicates
    }
    if (nums[i] - cur == 1) {
        ans++;
    } else {
        ans = 1;
    }
    cur = nums[i];
    len = max(len, ans);
}
       return len;
    }
};