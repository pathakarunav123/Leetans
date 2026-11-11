class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long totalCost = 0;
        long long totalCost_both=0;
        long long totalCost_min_need=0;
        long long max_need=0;
        long long min_need =0;
         max_need = max(need1,need2);
         min_need = min(need1,need2);
         totalCost_both = max_need*costBoth;
         totalCost_min_need = min_need*costBoth;
         long long new_need1 = need1-min_need;
         long long new_need2 = need2-min_need;
         if(new_need1!=0){
            totalCost_min_need+=cost1*new_need1;
         }else{
            totalCost_min_need+=cost2*new_need2;
         }
           long long need_req1 = (1LL)*cost1*(1LL)*need1;
           long long need_req2 = (1LL)*cost2*(1LL)*need2;
             totalCost = need_req1+need_req2;
         long long ans =0;
         ans = min({totalCost,totalCost_both,totalCost_min_need});
         return ans; 
    }
};