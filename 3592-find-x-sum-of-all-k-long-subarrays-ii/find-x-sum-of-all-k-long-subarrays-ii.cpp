class Solution {
    public:
    long long sum=0;
    set<pair<int,int>>main;
    set<pair<int,int>>sec;
    void insertinset(pair<int,int>p,int x){
        if(main.size()<x|| p> *(main.begin())){
            main.insert(p);
            sum+=1LL*p.first*p.second;
            if(main.size()>x){
                auto smallest= *main.begin();
                sum-=1LL*smallest.first*smallest.second;
                main.erase(smallest);
                sec.insert(smallest);
            }
        }
        else{
            sec.insert(p);
        }
    }

    void removefromset(pair<int,int>p,int x){
        if(main.find(p)!=main.end()){
            sum-=1LL*p.first*p.second;
            main.erase(p);
            if(!sec.empty()){
                auto largest = *sec.rbegin();
                sec.erase(largest);
                main.insert(largest);
                sum+=1LL*largest.first*largest.second;
            }
        }
        else{
            sec.erase(p);
        }
    }


public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        //using sliding window approach
        vector<long long>ans;
        int n=nums.size();
        int i=0;
        int j=0;
        map<int,int>m;
        while(j<n){
            if(nums[j]>0){
                removefromset({m[nums[j]],nums[j]},x);
            }
            m[nums[j]]++;
            insertinset({m[nums[j]],nums[j]},x);
            if(j-i+1==k){
                ans.push_back(sum);
                removefromset({m[nums[i]],nums[i]},x);
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                else{
                    insertinset({m[nums[i]],nums[i]},x);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};