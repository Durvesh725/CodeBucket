func closestPrimes(left int, right int) []int {
    const N = 1e6 + 1
    isPrime := make([]bool, N)
    primes := []int{}

    for i := range isPrime{
        isPrime[i] = true
    }

    isPrime[0], isPrime[1] = false, false

    for i := 2; i*i <= int(N); i++ {
		if isPrime[i] {
			for j := i * i; j < int(N); j += i {
				isPrime[j] = false
			}
		}
	}

    for i := 2; i < int(N); i++ {
		if isPrime[i] {
			primes = append(primes, i)
		}
	}

    low := sort.Search(len(primes), func(i int) bool {return primes[i] >= left})
    high := sort.Search(len(primes), func(i int) bool {return primes[i] > right}) - 1

    if len(primes) < 2{
        return []int{-1, -1}
    }

    num1, num2, diff := -1, -1, math.MaxInt32
    for i := low + 1; i <= high; i++{
        if primes[i]-primes[i-1] < diff {
			diff = primes[i] - primes[i-1]
			num1 = primes[i-1]
			num2 = primes[i]
		}
    }

    return []int{num1, num2}
}