class Solution
{
    public:
    // we are greedy for value/weight
    bool static cmp(struct Item a, struct Item b) { 
    	double r1 = (double)a.value / (double)a.weight; 
    	double r2 = (double)b.value / (double)b.weight; 
    	return r1 > r2; 
    } 
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        int currWeight = 0;
        double finalProfit = 0.0;
        for(int i=0;i<n;i++){
            if(currWeight + arr[i].weight <= W){
                // we will consider as whole
                currWeight += arr[i].weight;
                finalProfit += arr[i].value;
            }else{
                // take a fraction of it
                int remWeight = W - currWeight;
                finalProfit += ((double)arr[i].value)*((double)remWeight/(double)arr[i].weight);
                break;
            }
        }
        return finalProfit;
    }
        
};