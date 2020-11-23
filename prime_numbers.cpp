#include<iostream>
#include<vector>
using namespace std;
 
int countPrimes(int n) {
        int count = 0;
        if(n == 0 || n == 1)return 0;
        vector<bool> isPrime(n, true);     //vector which tells us that particular ith number is Prime if it is true else not Prime.
        isPrime[0] = false;                //0 is not a prime number
        isPrime[1] = false;                //1 is not a prime number
        int i, j;
        for(i = 2; i < n; i++)             //to check the primalty of other numbers
        {
            if(isPrime[i])                 //if a number is prime, then make all of it multiples non prime. 
            {
                for(j = i + i; j < n; j += i) //ex: 2 is prime then make 4, 6, 8, 10, ... n. all as non prime.
                {
                    isPrime[j] = false;
                }
                count++;                      //increment the count because our current ith number is prime.
            }
        }
        return count;
    }
    
int main()
{
  int n;
  cout << "Enter value for n:";
  cin >> n;
  
  int ans = countPrimes(n);
  cout << "There are " << ans << " prime numbers below " << n << "\n";
}
