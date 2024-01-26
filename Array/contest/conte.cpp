/*#include<iostream>
using namespace std ;

#include<vector> 
int main(){
    int t  ; 
    cin>>t ; 
    while(t--){
        int n, k;
        cin>>n>>k ; 
        int i = 0 ; 
        int d = n ; 
        int countMoves = 0 ; 
        vector<int>ans ; 
        while(i<n){
            if(d%k != 0){
                i = i+d ; 
                countMoves++; 
                ans.push_back(d) ;
                d = n-i ; 
            }
            else {
                d = d-1 ; 
            }
        }
        cout<<countMoves<<endl; 
        for(int i =0;i<ans.size() ;i++){
            cout<<ans[i]<<" "; 
        }
        cout<<endl;  
    }
}
*/

/*

#include<iostream>
using namespace std ;

int main(){
    int t  ; 
    cin>>t ; 
    while(t--){
        int n ; 
        cin>>n ; 
        string s ; 
        cin>>s ; 
        int maxcount = 0 ; 
        int curr = 0 ; 
        bool flag = 1 ; // 1 for greater than 
        if(n==1){
            cout<<2<<endl; 
        }
        else {
            if(s[0]=='<'){
                flag = 0 ; 
            }
            curr = 2; 
            for(int i = 1 ;i<n ;i++){
                if(flag==1 && s[i]=='>'){
                    curr++; 
                }
                else if(flag == 0 && s[i]=='<'){
                    curr++ ; 
                }
                else if (flag ==1 && s[i]=='<'){
                    flag = 0 ; 
                    maxcount = max(maxcount, curr) ;
                    curr = 2 ; 
                }
                else {
                    flag = 1 ; 
                    maxcount = max(maxcount, curr) ;
                    curr =2 ; 
                }
                maxcount = max(maxcount, curr) ;
            }
            cout<<maxcount<<endl; 
        }
        
    }
    return 0 ; 
}
*/
/*

#include<iostream>
using namespace std ;

int main(){
    int t  ; 
    cin>>t ; 
    while(t--){
        string s ; 
        cin>>s ; 
        int len = s.size() ;
        char left = 'o' ; 
        char right = 'o' ;
        if(s[0]=='?'){
            int i = 0;
            while(i<len&& s[i]=='?'){
                i++; 
            }
            if(i<len){
                right = s[i];
                 for(int j= 0 ;j<i;j++ ){
                    s[j] =  right ; 
                }
            }
            else {
                for(int j= 0 ;j<len;j++ ){
                    s[j] =  '0' ; 
                }
            }
        }
        if (s[len-1]=='?'){
            int i = len-1;
            while(i>= 0&& s[i]=='?'){
                i--; 
            }
            if(i>=0){
                right = s[i];
                 for(int j= i+1 ;j<len;j++ ){
                    s[j] =  s[i] ; 
                }
            }
            else {
                for(int j= 0 ;j<len;j++ ){
                    s[j] =  '0' ; 
                }
            }
        }
        int li = 0 ; 
        int ri = 0 ; 
        int i = 0 ;
        int j = 0 ; 
        while(j<len){
            if(s[j]=='0'){
                left = s[j] ;
            }
            else if (s[j]=='1'){
                left = s[j] ;
            }
            else if(s[j]=='?'){
                ri = j+1 ; 
                while(ri<len && s[ri]=='?'){
                    ri++; 
                }
                right = s[ri] ;
                    for(int k = j ;k<ri ;k++){
                        s[k] = right ; 
                    }
                
                
                j = ri ; 

            }
            j++; 
        }

        cout<<s<<endl; 
    }
    return 0 ; 
}
*/

/*#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, world!";
    std::string subStr = "world";

    // Find the substring within the string
    size_t found = str.find(subStr);

    if (found != std::string::npos) {
        std::cout << "Substring found at index " << found << std::endl;
    } else {
        std::cout << "Substring not found" << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);
        nums[n - 1] = 1;
        int count = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (count < ceil((double)(n - i) / k)) {
                nums[i] = 1;
                count++;
            }
            else {
                nums[i] = 0;
            }
        }

        nums[0] = 1;
        count = 1;

        for (int i = 1; i < n; i++) {
            if (count < ceil((double)(i + 1) / k)) {
                nums[i] = 1;
                count++;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}



#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n ; 
        cin>>n ; 
        vector<int>ans(n) ; 
        int flag = 1 ; 
        for(int i = 0 ; i<n ;i++){
            cin>>ans[i] ;
            if(ans[i]<0){
                flag = 0 ; 
            }
        }
         if(flag ==1){
            int maxi = INT_MIN ; 
             for(int i = 0; i<n ;i++){
                maxi = max(maxi, ans[i]);
             }
             cout<<maxi<<endl; 
        }
        else {
            int negmini = INT_MIN; 
            for(int i = 0 ;i<n ;i++){
                if(ans[i]<0 ){
                    negmini = max(negmini, ans[i]) ;
                }
            }
            cout<<negmini<<endl; 
        }

    }
}
*/

/*#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n ; 
        cin>>n ; 
        vector<int>nums(n) ; 
        int i1 ; int in ; int i2 ; int i3 ; 
        for(int i = 0  ;i<n ; i++){
            cin>>nums[i];
            if(nums[i]==1){
                i1 = i ; 
            }
            if(nums[i]==2){
                i2 = i ; 
            }
            if(nums[i]==n){
                in = i ; 
            }
            if(nums[i]==3){
                i3 = i ; 
            }
        }
        int ans1  =1 ; 
        int ans2 = 1; 
        // find the smallest side of number around left or right 
        if(i2>i1 && in<i1){
            // swap 
            if(i3>i1){
                ans1 = i2 ; ans1 = in ;
            }
             
        }
        if(i2<i1 && in>i1){
            if(i3<i1){
                ans1 = i2 ; ans2 = in ;
            }
            
        }
        if(i2>i1 && in>i1){
            if(in>i2){
                ans1 = i2  ; 
                ans2 = in ; 
            }

        }
        if(i2<i1 && in<i1){
            if(in<i2){
                ans1 = i2 ; 
                ans2 = in ; 
            }
        }
        cout<<ans1<<" "<<ans2<<endl; 
    }
}
*/

#include <iostream>
#include <vector>

using namespace std;
#include <cmath>

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int m,n ; 
        cin>>m>>n ; 
        int flag1 = isPrime(m) ;
        int flag2 = isPrime(n) ;
        vector<vector<int>> grid(n, vector<int>(m, 0));

        if(flag2 == 0){
            int ans = m*n ; 
            for(int i = 0 ;i<m ;i++){
                for(int j = 0;j<n ;j++){
                    cout<<ans<<" " ;
                    ans--; 
                }
                cout<<endl;  
            }
        }
        else if(flag1 == 0 && flag2 == 1){

            for(int i = 0;i<m ;i++){
                int k = m*n-i ; 
                for(int j = 0;j<n ;j++){
                    cout<<k<<" " ;
                    k = k-m ; 
                }
                cout<<endl; 
            }
        }
        else {
            int ans = m*n ; 
            for(int i = 0 ;i<m ;i++){
                for(int j = 0;j<n; j++){
                    if(j!=0){
                        grid[i][j] =  ans ; 
                        ans-- ;  
                    }

                }
            }
            for(int i = 0 ;i<m ;i++){
                for(int j = 0;j<n; j++){
                    cout<<grid[i][j]<<" "; 
                }
                cout<<endl; 
            }
        }
    }
}

