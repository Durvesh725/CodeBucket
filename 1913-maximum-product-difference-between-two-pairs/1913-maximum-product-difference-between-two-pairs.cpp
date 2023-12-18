class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int biggest = 0, secondBig = 0, small = 1e5,secondSmall = 1e5;
        
        // for(int num: nums){
        //     secondBig = (num > biggest) ? exchange(biggest, num) : max(secondBig, num);
        //     secondSmall = (num < small) ? exchange(small, num) : min(secondSmall, num);
        // }
        
        for(int i:nums){
            small=min(small,i);
            biggest=max(biggest,i);
            
        }
        int sf=0,bf=0;
        
        for(int i:nums){
            if(i==small){
                sf++;
            }
            if(i==biggest)
                bf++;
          
            if(i!=small)
                secondSmall=min(secondSmall,i);
            if(i!=biggest)
            secondBig=max(secondBig,i);
            
        }
        if(bf>=2)
            secondBig=biggest;
        else if(secondBig==0)
            secondBig=biggest;
        if(sf>=2)
            secondSmall=small;
        
        else if(secondSmall==1e5)
            secondSmall=small;
        
        
            
        cout<<small<<" "<<secondSmall<<" "<<biggest<<" "<<secondBig;
        return (biggest * secondBig) - (small * secondSmall);
    }
};