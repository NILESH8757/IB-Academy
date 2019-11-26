// minimum subarray having maximum OR value in O(nlogn) time
#include<bits/stdc++.h>
 using namespace std;

int main()
{ 
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    int p[32];
    memset(p, -1, sizeof(p));

    int maxor = 0;
    for(int i = 0; i < n; i++)
    {
       maxor |= a[i];
    }

    int ans = INT_MAX;

    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < 32; j++)
      {
          if(a[i] & (1 << j))
             p[j] = i;
      }

      int minind = INT_MAX;
      bool isPresent = true;

      for(int j = 0; j < 32; j++)
      {
          if((maxor & (1 << j)) && p[j] != -1)
          {
              minind = min(minind, p[j]);
          }
          else if(maxor & (1<<j))
          {
              isPresent = false;
          }
      }

      if(isPresent)
      {
          ans = min(ans, i - minind + 1);
      }
    }

    cout << ans;

  return 0;
}
