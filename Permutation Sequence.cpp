//using next pemutation stl
string getPermutation(int n, int k) {
    vector<int> nums;
    for (int i=1;i<=n;i++) nums.push_back(i);
    while(--k) next_permutation(nums.begin(),nums.end());
    string ans="";
    for(int l:nums) ans+=to_string(l);
    return ans;
}

// efficient way time o(n^2) space O(n)
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact  = 1;
        vector<int> v;
        for(int i=1;i<n;i++){
            fact = fact * i;
            v.push_back(i);
        }
        v.push_back(n);
        string ans = "";
        k = k-1;
        while(true){
            //put the desired blocks first element
            ans = ans + to_string(v[k/fact]);
            //delete the element
            v.erase(v.begin()+k/fact);
            //if v is empty
            if(v.empty()){
                break;
            }
            // updating values for new interation
            k = k%fact;
            fact = fact/v.size();
        }
        return ans;
        
    }
};