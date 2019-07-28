/*
  You are given an array of N non-negative integers, A0, A1 ,..., AN-1. Considering each array element Ai 
  as the edge length of some line segment, count the number of triangles which you can form using these array values.

  return answer modulo 10^9 + 7.
*/
// source : https://leetcode.com/problems/valid-triangle-number/discuss/104174/Java-O(n2)-Time-O(1)-Space

int countTriangles(vector<int> &A) 
{
    
    sort(A.begin(), A.end());
    
    int count = 0, n = A.size();
    const int mod = 1e9 + 7;
    
    for (int i = n - 1; i > 1; i--) 
    {
        int l = 0, r = i-1;
        while (l < r) 
        {
            if (A[l] + A[r] > A[i]) 
            {
                count = (count + r-l + mod) % mod;
                r--;
            }
            else 
            l++;
        }
    }
    
    return count;
}
