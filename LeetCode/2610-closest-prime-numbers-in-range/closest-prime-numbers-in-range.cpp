class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> isPrime(1e6+1, 1);
        vector<int> primes;

        isPrime[0] = isPrime[1] = 0;
        for(int i = 2; i * i <= 1e6; i++){
            if(isPrime[i]){
                for(int j = i * i; j <= 1e6; j += i){
                    isPrime[j] = false;
                }
            }
        }

        for(int i = 2; i <= 1e6; i++){
            if(isPrime[i])
                primes.push_back(i);
        }

        int low = lower_bound(primes.begin(), primes.end(), left) - primes.begin();
        int high = upper_bound(primes.begin(), primes.end(), right) - primes.begin() - 1;

        if(primes.size() < 2)
            return {-1, -1};

        int num1 = -1, num2 = -1;
        int diff = INT_MAX;
        for(int i = low + 1; i <= high; i++){
            if(primes[i] - primes[i-1] < diff){
                diff = primes[i] - primes[i-1];
                num1 = primes[i-1];
                num2 = primes[i];
            }
        }

        return {num1, num2};
    }
};