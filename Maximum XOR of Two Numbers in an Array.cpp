//  link : https://qr.ae/TWnA4r

int maxXor(vector<int> &A) 
{
    int mx = 0, mask = 0;

    for(int i = 31; i >= 0; i--)
    {
        mask |= (1LL << i);
        set<int> s;
   
        for(int num : A)
        {
            s.insert(num & mask);
        }

        int temp = mx | (1LL << i);
      
        for(int v : s)
        {
            if(s.find(temp ^ v) != s.end())
            {
                mx = temp;
                break;
            }
        }
        
     }

    return mx;
}
