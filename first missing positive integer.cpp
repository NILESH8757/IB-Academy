// soln. credit : https://leetcode.com/problems/first-missing-positive/discuss/17071/My-short-c%2B%2B-solution-O(1)-space-and-O(n)-time

int firstMissingPositive(vector<int> &A) 
{
    int n = A.size();
   
    for(int i = 0; i < A.size(); i++)
    {
        while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
         swap(A[i], A[A[i] - 1]);
    }
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] != i + 1)
          return i + 1;
    }
    
    return n + 1;
}
