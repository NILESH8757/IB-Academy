// https://leetcode.com/problems/longest-valid-parentheses/

//solution using stack

int longestValidParentheses(string A) 
{
    int ans = 0;
    stack<int> st;
    st.push(-1);
    
    for (int i = 0; i < A.size(); i++) 
    {
        if (A[i] == '(') 
        {
            st.push(i);
        }
        else 
        {
            st.pop();
            if (st.empty()) 
            {
                st.push(i);
            } 
            else 
            {
                ans = max(ans, i - st.top());
            }
        }
    }
    
    return ans;
}

// O(n) time, O(1) space solution : https://leetcode.com/problems/longest-valid-parentheses/solution/
