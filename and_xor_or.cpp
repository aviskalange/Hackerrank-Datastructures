#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,i;
    cin>>n;
    long long int a[n],m1,m2,ans=-1,s;
    for(i=0;i<n;i++)
        cin>>a[i];
    stack<int> st;
    for(i=0;i<n;i++)
    {
        while(!st.empty())
        {
            m1=a[i];
            m2=st.top();
            s=(((m1&m2)^(m1|m2))&(m1^m2));
            if(s>ans)
                ans=s;
            if(m1<m2)
                st.pop();
            else
                break;
        }
        st.push(a[i]);
    }
    cout<<ans;
    return 0;
}
