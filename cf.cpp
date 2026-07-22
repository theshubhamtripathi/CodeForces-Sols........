CF 1727 A
//there are 3 kinds we can find the answer of this question keeping the first one same and iterating the 2nd element 
//now keeping the last one same and iterating the first one 
//now chnaging the both ones 
//then returing the max out of all 3 answer 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        //inputs
        
        int ans = a[n-1] - a[0];
        for(int i=1;i<n;i++){
            ans = max(ans,a[i]-a[0]);
        }
        for(int i=0;i<n-1;i++){
            ans = max(ans,a[n-1]-a[i]);
        }
        for(int i=0;i<n-1;i++){
            ans = max(ans,a[i]-a[i+1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}


CF 1696 B
In competitive programming, MEX stands for Minimum Excluded value. It is defined as the smallest non-negative integer (\(0, 1, 2, \dots\)) that is not present in a given set or array.
// The main arigument in this question is answer must be between 0,1,2 and we have seen till now if all elements are 0 ans is 0
// if we have a continuous track of elements of positive elements acnanak se then we have to print 1 
// els eout answer will be always 0 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        //inputs
        
        int c0 = 0;
        for(int i=0;i<n;i++){
          if(a[i] == 0)
            c0++;
        }
        
        int l = 0;
        int r = n-1;
        bool is0 = false;
        while(a[l] == 0){
            l++;
        }
        while(a[r] == 0){
            r--;
        }
        for(int i=l;i<r;i++){
            if(a[i] == 0){
                is0 = true;
            }
        }
        if(c0 == n) cout<<0<<endl;
        else if(is0 == false) cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}

cf 1679 A
//Here the main concept was to find the min and max busses needed and w find that
//by dividing by 4 to find the max one (using floor here)
//by dividing by 6 to find the min one (using ceiling here) we add 5 here cause it is using the same thing like ceil
//beacsue in copetitive programming we should not use ceil and floor as they may cause some errors.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        long long n;
        cin>>n;
        if(n<4 || n%2 == 1){
            cout<<-1<<endl;
        }
        else{
            cout<<(n+5)/6/*min*/<<" "<<n/4/*max*/<<endl;
        }
    }
    return 0;
}
