#include <iostream>
using namespace std;
 
typedef long long ll;
 
int N;
ll cnt[200005];
 
int main () {
    scanf("%d", &N);
    int a, sum=0;
    cnt[0]=1;
    ll ans=0;
    for (int i=0; i<N; i++) {
        scanf("%d", &a);
        sum=(sum+a)%N;
        if (sum<0)
            sum+=N;
        ans+=cnt[sum];
        cnt[sum]++;
    }
    printf("%lld\n", ans);
    return 0;
}
