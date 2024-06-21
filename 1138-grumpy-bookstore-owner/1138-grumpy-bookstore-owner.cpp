class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0, mx = 0, unsat = 0;
        for(int i=0; i<customers.size(); i++){
            sum += customers[i];  //Total customers
            customers[i] *= grumpy[i]; 
            unsat += customers[i]; // Toal customers when shopkeeper is grumpy
        }
        for(int i=0; i<=customers.size()-minutes; i++)
        {
            int k = minutes, count = 0, j = i;
            while(k--)
                count += customers[j++]; 
            if(count>mx)
                mx = count; // Maximum customers coming in the minutes window when shopkeeper can control themself
        }
    return sum - unsat + mx; 
    }
};