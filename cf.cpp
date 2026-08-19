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


cf 1675 B
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    // Walk backward from second-to-last element
    for (int i = n - 2; i >= 0; i--) {
        while (a[i] >= a[i + 1] && a[i] > 0) {
            a[i] /= 2;
            ans++;
        }
        // If a[i] is still >= a[i+1], it means both are 0 
        // and making the array strictly increasing is impossible.
        if (a[i] >= a[i + 1]) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (cin >> q) {
        while (q--) {
            solve();
        }
    }
    return 0;
}

Cf 1666 D
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optional fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        
        unordered_map<char, int> mp;
        for (int i = 0; i < t.length(); i++) {
            mp[t[i]]++;
        }
        
        for (int i = s.length() - 1; i >= 0; i--) {
            // FIX 1: Added missing ']'
            if (mp[s[i]] > 0) {
                mp[s[i]]--; 
            }
            else {
                s[i] = '.';
            }
        }
        
        string final_string = "";
        // FIX 2: Replaced undefined 'n' with 's.length()'
        for (int i = 0; i < s.length(); i++) { 
            if (s[i] != '.') {
                final_string += s[i];
            }
        }
        
        if (final_string == t) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

C f 1665 B
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
        
        unordered_map<int,int> mp;
        for(auto it : a){
            mp[it]++;
        }
        int mf = 0; //maxfreq
        for(auto it : mp){
            mf = max(mf,it.second);
        }
        
        int o = 0;
        while(mf<n){
            o++;
            if(mf*2<=n){
                o += mf;
                mf *= 2;
            }
            else{
                o += n-mf;
                mf = n;
            }
        }
        cout<<o<<endl;
    }
    return 0;
}

Cf 1624 B 
//In this question we just have to know about the concept of ap and the one formula of ap that is a+b = 2b
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        
        long long a,b,c;
        cin>>a>>b>>c;
        
        bool answer = false;
        
        long long na = 2*b-c;
        if(na/a > 0 && na%a == 0){
            answer = true;
        }
        
        long long nb = (a + c)/2;
        if(na/a > 0 && na%a == 0 && (a-c)%2 == 0){
            answer = true;
        }
        
        long long nc = 2*b-a;
        if(nc/c > 0 && nc%c == 0){
            answer = true;
        }
        
        if(answer){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}


Cf 1607 B
In this question we diid nothing we just checked that after 4 iteration evverything was reating that we can see after dry run also the n is very high so we have to check that using if else as only linear solution was needed tos olev thos so we solve it by this logic only
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        long long s,j;
        cin>>s>>j;
        
        long long fpos;
        
        if(j%4 == 1){
            fpos = -j;
        }
        else if(j%4 == 2){
            fpos = 1;
        }
        else if(j%4 == 3){
            fpos = j+1;
        }
        else if(j%4 == 0){
            fpos = 0;
        }
        
        if(s%2 == 0){
            fpos = s + fpos;
        }
        else{
            fpos = s - fpos;
        }
        
        cout<<fpos<<endl;
    }
    return 0;
}


C f 1606 A
//Here we just need to check whether the first letter and the last letter is same or not if not then make it same and return the same one .......... just this we have to do in this 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        int n = s.size();
        
        if(s[0] != s[n-1]){
            s[n-1] = s[0];
        }
        
        cout<<s<<endl;
    }
    return 0;
}


C f 1373 B
//In this question we just did nothing we counted the number of 0s and 1s and then return the min of both and then check the whether they are evven or not if evven then print YES else NO 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        //inputs
        int c1 = 0;
        int c0 = 0;
        int minc = INT_MAX;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){
                c1++;
            }
            else{
                c0++;
            }
        }
        minc = min(c1,c0);
        if(minc%2 == 0){
            cout<<"NET"<<endl;
        }
        else{
            cout<<"DA"<<endl;
        }
    }
    return 0;
}

C f 1380 A
//In this question we just have to find the peak elemmt types like we checkded whther our current element is greater than the previous one and also greater than the next one 
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
        int flag = 0;
        for(int j=1;j<n-1;j++){
            
            int i = -1;
            int k = -1;
            
            for(int left=0;left<j;left++){
                if(a[j]>a[left]){
                    i = left;
                    break;
                }
            }
            
            for(int right=j+1;right<n;right++){
                if(a[j]>a[right]){
                    k = right;
                    break;
                }
            }
            
            if(i != -1 && k!= -1){
                cout<<"YES"<<endl;
                cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}    


CF 1471 A
//See basically 2 things you must have command on this problem to solve 
//first the ceil can be implemented as ceil(a/b) as a+b-1/b using normal division
//2nd thing we should focus on basically is max is calculated after when we combine dont combine like do the things individuslly
//3rd min is calculated when we compute using adding all the things at first then dividing it together
//last thing to maibtain the docimal presiocion of one we should multiple by 1.0

#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int n,x;
        cin>>n>>x;
        
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        long long max = 0;
        long long min = 0;
        
        for(int i=0;i<n;i++){
            max += ceil(a[i]*1.0/x);
            min += a[i];
        }
        min = ceil(min*1.0/x);
        cout<<min<<" "<<max<<endl;
    }
    return 0;
}
