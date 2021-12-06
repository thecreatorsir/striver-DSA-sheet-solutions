class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    sort(coins,coins+M,greater<int>());
	    int count = 0;
	    int i = 0;
	    while(V!=0 and i<M){
	        if(coins[i]<=V){
	            V -= coins[i];
	            count++;
	        }else{
	            i++;
	        }
	    }
	    return (!count)?-1:count;
	} 
};