class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles/numExchange > 0){
            int temp_drink = emptyBottles/numExchange;
            drink += temp_drink;
            emptyBottles = (emptyBottles - (temp_drink * numExchange)) + temp_drink;
        }
        return drink;
    }
};