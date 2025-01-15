class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int result = 0, targetSetBits = __builtin_popcount(num2); // Fix typo in variable name

        // Set bits from num1's higher bits to match the number of set bits in num2
        for (int i = 31; i >= 0 && targetSetBits > 0; i--) {
            if (num1 & (1 << i)) { // Check if the ith bit is set in num1
                result |= (1 << i); // Set the same bit in result
                targetSetBits--;
            }
        }

        // If more bits are needed, set from the lowest available positions
        for (int i = 0; i < 32 && targetSetBits > 0; i++) {
            if (!(result & (1 << i))) { // If the ith bit is not set in result
                result |= (1 << i); // Set it
                targetSetBits--;
            }
        }

        return result;
    }
};
