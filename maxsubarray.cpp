/**
 * Find the subarray which has the maximum sum in a given array.
 * Kadane's Algorithm: O(n).
 * V.IMP
**/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int i, n, data;
  vector<int> v;
  cout << "Enter size of array: ";
  cin >> n;
  
  cout << "Enter data in array: ";
  for(i = 0; i < n; i++)
  {
    cin >> data;
    v.push_back(data);
  }

  int max = v[0], sum = 0; //max will hold the maximum contiguous subarray sum

  //sum will keep the temporary max sum
  
  for(i = 0; i < n; i++)
  {
     sum += v[i];   //increase the temporary sum value with current element's value.
     if(sum > max)max = sum; //if the sum value till now is greater than max then update max.
     if(sum < 0)sum = 0;     //if sum is negative then reset the sum.
  }

  cout << "\nThe max subarray sum: " << max << "\n";
}
