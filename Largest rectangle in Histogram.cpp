// problem : https://leetcode.com/problems/largest-rectangle-in-histogram/

/* stack based O(n) solution */

int largestRectangleArea(vector<int> &A) 
{
   
    A.push_back(0);
    int maxArea=0;
    stack<int> st;

    for(int i = 0; i < A.size(); i++)
    {
        while(!st.empty() && A[i] < A[st.top()])
        {
            int top = st.top();
            st.pop(); 
            int nextTop = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (i - nextTop - 1) * A[top]);
        }

        st.push(i);
    }
    return maxArea;
}

/*Another O(n) solution without stack */

int largestRectangleArea(vector<int> &A) 
{
    
   int n = A.size(), maxArea = 0;
   vector<int> lessLeft(n), lessRight(n);
   
   lessLeft[0] = -1;
   lessRight[n - 1] = n;
   
   for(int i = 1; i < n; i++)
   {
       int p = i - 1;
       
       while(p >= 0 && A[p] >= A[i])
       {
           p = lessLeft[p];
       }
       lessLeft[i] = p;
   }
   
   for(int i = n - 2; i >= 0; i--)
   {
       int p = i + 1;
       
       while(p < n & A[p] >= A[i])
       {
           p = lessRight[p];
       }
       lessRight[i] = p;
   }
   
   for(int i = 0; i < n; i++)
   {
       maxArea = max(maxArea, A[i] * (lessRight[i] - lessLeft[i] - 1));
   }
   
   return maxArea;
}

