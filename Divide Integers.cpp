/*
 Divide two integers without using multiplication, division and mod operator.
 Return the floor of the result of the division.  
 
 Example: 5 / 2 = 2
 Also, consider if there can be overflow cases. For overflow case, return INT_MAX.
 
 Soln : https://leetcode.com/problems/divide-two-integers/discuss/13524/Summary-of-3-C%2B%2B-solutions
*/

int divide(int A, int B) 
{

    long long result = 0;
    long long m = abs((long long)A);
    long long n = abs((long long)B);

    while(m >= n)
    {
        long long s = n, power = 1;
        while((s << 1) <= m) 
        { 
            s <<= 1; 
            power <<= 1; 
        }

        result += power;
        m -= s;
    }
    
    if( (A>0) ^ (B>0))  
        result = -result;

    return result > INT_MAX ? INT_MAX : result; 
}
