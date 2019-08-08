void combine(vector<pair<int,int>> &a, vector<int> &cnt, int i, int mid, int j)
{
   vector<pair<int,int > > temp(j - i + 1);
   int l = i, r = mid + 1, idx = 0, smaller = 0;

   while(l <= mid && r <= j)
   {
      if(a[l].first > a[r].first)
      {
         smaller++;
         temp[idx++] = a[r++];
      }
      else // a[l].first <= a[r].first
      {
         cnt[a[l].second] += smaller;
         temp[idx++] = a[l++];
      }
   }

   while(l <= mid)
   {
      cnt[a[l].second] += smaller;
      temp[idx++] = a[l++];
   }

   while(r <= j)
   {
      temp[idx++] = a[r++];
   }
   
   for(int k = i; k <= j; k++)
     a[k] = temp[k - i];
}

void countSmaller(vector<pair<int,int>> &a, vector<int> &cnt, int i, int j)
{
    if(i < j)
    {
        int mid = (i + j)/2;
        countSmaller(a, cnt, i, mid);
        countSmaller(a, cnt, mid + 1, j);
        combine(a, cnt, i, mid, j);
    }
}

int main()
{
        
    int n;
    cin >> n;
    vector<int> res(n, 0);
    vector<pair<int, int> > a;
    
    for(int i = 0; i < n; i++)
    {
       cin >> a[i].first;
       a[i].second = i;
    }
     
    countSmaller(a, res, 0, n - 1);
   
    // print result
    
    return 0;
}
