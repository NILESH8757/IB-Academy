//Boyer–Moore majority vote algorithm
//ref. : https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm

int Solution::majorityElement(const vector<int> &A) 
{
   int mxid = 0, cnt = 0;

   for(int i = 0; i < A.size(); i++)
   {
       A[i] == A[mxid] ? cnt++ : cnt--;

       if(cnt == 0)
       {
           mxid = i;
           cnt = 1;
       }
   }

   cnt = 0;
   
   for(int i = 0; i < A.size(); i++)
   {
      if(A[i] == A[mxid])
       cnt++;
   }
   
   return (cnt > n / 2) ? A[mxid] : -1;
}

