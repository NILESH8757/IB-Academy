// https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation

double findMedianSortedArrays(const vector<int> &A,const vector<int> &B) 
{    
    int m = (int)A.size();
    int n = (int)B.size();
    int l, r, lhalf, rhalf, half;

    if(m > n)
     return findMedianSortedArrays(B, A);


    l = 0 ; r = m; half = (m + n + 1) / 2;

    while(l <= r)
    {
        int i = (l + r) / 2;
        int j = half - i;

        if(i < m && B[j - 1] > A[i])
            l = i + 1;
        else if(i > 0 && A[i - 1] > B[j])
            r = i - 1;
        else
        {
            if(!i)
                lhalf = B[j - 1];
            else if(!j)
                lhalf = A[i - 1];
            else
                lhalf = max(A[i - 1], B[j - 1]);

            if((m + n) & 1)
                return 1.0 * lhalf;

            if(i == m)
                rhalf = B[j];
            else if(j == n)
                rhalf = A[i];
            else
                rhalf = min(A[i], B[j]);

            return (lhalf + rhalf) / 2.0;
        }

    }

}
