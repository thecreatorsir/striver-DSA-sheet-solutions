//find maxinum overlap with a perticular train O(n^2) time complexity 
int findPlatform(int arr[], int dep[], int n)
{
 
    int plat_needed = 0, result = 0;
    // run a nested  loop to find overlap
    for (int i = 0; i < n; i++) {
        // minimum platform
        plat_needed = 1;
 
        for (int j = i + 1; j < n; j++) {
            // check for overlap
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
           (arr[j] >= arr[i] && arr[j] <= dep[i]))
                plat_needed++;
        }
 
        // update result
        result = max(result, plat_needed);
    }
 
    return result;
}

// O(nlogn) solution
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);
        int plat_needed = 1, result = 1,i = 1, j = 0;;
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) plat_needed++,i++;
            else plat_needed--,j++;
            result = max(result,plat_needed);
        }
        return result;
    }
};
 