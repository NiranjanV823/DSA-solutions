class Solution {
public:
    unordered_map<string,int> mp; 

    bool hasDup(string & s1, string &s2){
        int arr[26] = {0};
        for(char ch:s1){
            if(arr[ch-'a']>0) return true;
            arr[ch-'a']++;
        }
        for(char ch:s2){
            if(arr[ch-'a']>0) return true;
        }

        return false;
    }
    int solve(int ind, string temp, vector<string>& arr,int n){
        if(ind == n) return 0; 

        if(mp.find(temp)!= mp.end()) return mp[temp];

        int notake = solve(ind+1,temp,arr,n);
        int take = INT_MIN ;
        if(!hasDup(arr[ind],temp)){
            take = arr[ind].size() + solve(ind+1,temp+arr[ind],arr,n);
        }
        return mp[temp] = max(take,notake);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        mp.clear();
        string temp = "";
        return solve(0,temp,arr,n);
    }
};