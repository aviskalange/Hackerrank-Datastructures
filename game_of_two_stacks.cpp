#include <bits/stdc++.h>

using namespace std;

int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++)
    {
        long long int n;
        long long int m;
        long long int x,sum=0;
        cin >> n >> m >> x;
        long long int a[n],i,j,max;
        for(i = 0; i < n; i++)
            cin >> a[i];
        long long int b[m];
        for(i = 0; i < m; i++)
            cin >> b[i];
        i=0;
        while(i<n&&sum+a[i]<=x)
        {
            sum+=a[i];
            i++;
        }
        j=0;
        max=i;
        while(j<m&&i>=0)
        {
            sum+=b[j];
            j++;
            while(sum>x&&i>0)
                sum-=a[--i];
            if(sum<=x&&i+j>max)
                max=i+j;
        }
        cout<<max<<endl;
    }
    return 0;
}
