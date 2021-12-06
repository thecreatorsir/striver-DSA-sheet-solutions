// will be greedy for the profit
class Solution 
{
    public:
    static bool cmp(Job a,Job b){
      return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
      sort(arr,arr+n,cmp);
      int count=0,profit = 0;
      int slots[n] = {0};
      for(int i=0;i<n;i++){
          for(int j=min(arr[i].dead-1,n-1);j>=0;j--){
            if(!slots[j]){
              slots[j] = 1;
              profit += arr[i].profit;
              count++;
              break;
            }
          }
      }
      return {count,profit};
    } 
};