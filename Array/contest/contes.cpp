/*#include<iostream> 
using namespace std ; 
#include<algorithm>

int main(){
    int t ; 
    cin>>t ; 
    while(t--){
        int n ; 
        cin>>n ; 
        int arr[n] ;
        for(int i = 0 ;i<n ; i++){
            cin>>arr[i]; 
        }
        int ans[n] ;
        for(int i = 0 ;i<n ;i++){
            ans[i] = n-arr[i]+1 ; 
            cout<<ans[i]<<" "; 
        }
        cout<<endl; 

    }
}
*/
/*
#include<iostream> 
#include<map>
#include<vector> 
using namespace std ; 
int main(){
    int t ; 
    cin>>t ; 
    
    while(t--){
        int n ; 
        cin>>n ; 
        
        int a[n] ; int b[n] ;
        for(int i = 0 ;i<n ; i++){
            cin>>a[i]; 
        }
        for(int i = 0 ;i<n ; i++){
            cin>>b[i]; 
        }
        int i = 0; 
        int ans = 0 ;
        vector<bool> m1(100*n, false);
        vector<bool> m2(100*n, false);

        while(i<n){
            int  x = a[i] ;
            if(m1[x]==1){
                continue;
            }
            m1[x] = 1 ; 
            int maxcount1 = 0 ; 
            int count1 = 0 ; 
            for(int j = 0 ;j<n ;j++){
                if(a[j]==x){
                    count1++; 
                }
                else {
                    count1 = 0 ; 
                }
                maxcount1 = max(maxcount1, count1) ;
            }            
            int maxcount2 = 0 ; int count2 = 0; 
            for(int  j = 0; j<n ;j++ ){
                if(b[j]==x){
                    count2++ ; 
                }
                else {
                    count2= 0; 
                }
                maxcount2 = max(count2, maxcount2  ) ;

            }
            ans = max(ans, maxcount2+maxcount1) ;
           
            i++; 
        }   
        i = 0 ; 
         while(i<n){
            int  x = b[i] ;
            if(m2[x]==1 || m1[x]==1){
                continue;
            }
            m2[x] = 1 ; 
            int maxcount1 = 0 ; 
            int count1 = 0 ; 
            for(int j = 0 ;j<n ;j++){
                if(b[j]==x){
                    count1++; 
                }
                else {
                    count1 = 0 ; 
                }
                maxcount1 = max(maxcount1, count1) ;
            }            
            int maxcount2 = 0 ; int count2 = 0; 
            for(int  j = 0; j<n ;j++ ){
                if(a[j]==x){
                    count2++ ; 
                }
                else {
                    count2= 0; 
                }
                maxcount2 = max(count2, maxcount2  ) ;

            }
            ans = max(ans, maxcount2+maxcount1) ;
           
            i++; 
        }   
        cout<<ans<<endl ;  
    }
}
*/
/*
#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            int maxcount1 = 0;
            int count1 = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] == x) {
                    count1++;
                }
                else {
                    count1 = 0;
                }
                maxcount1 = max(maxcount1, count1);
            }

            int maxcount2 = 0;
            int count2 = 0;
            for (int j = 0; j < n; j++) {
                if (b[j] == x) {
                    count2++;
                }
                else {
                    count2 = 0;
                }
                maxcount2 = max(maxcount2, count2);
            }
            ans = max(ans, maxcount1 + maxcount2);
        }
        cout << ans << endl;
    }
    return 0;
}

*/
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid(int i, int j, int rows, int cols) {
    return (i >= 0 && i < rows && j >= 0 && j < cols);
}

int dfs(vector<vector<int>>& matrix, int i, int j) {
    int count = 0;
    if (!isValid(i, j, matrix.size(), matrix[0].size()) || matrix[i][j] != 1) {
        return 0;
    }
    matrix[i][j] = 0;
    count++;
    for (int k = 0; k < 4; k++) {
        count += dfs(matrix, i + dx[k], j + dy[k]);
    }
    return count;
}

int largestHouseGroup(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxGroupSize = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                int groupSize = dfs(matrix, i, j);
                maxGroupSize = max(maxGroupSize, groupSize);
            }
        }
    }
    return maxGroupSize;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int largestGroupSize = largestHouseGroup(matrix);
    cout << largestGroupSize << endl;
    return 0;
}
*/
/*#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        int minOnes = n;
        for (int i = 1; i <= k; ++i) {
            int ones = (n + i - 1) / i;
            int totalOnes = ones * k;
            if (totalOnes >= n)
                minOnes = std::min(minOnes, totalOnes);
        }

        std::cout << minOnes << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
    if (num < 2)
        return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void constructGrid(int n, int m) {
    vector<vector<int>> grid(n, vector<int>(m, 0));
    int num = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            while (true) {
                grid[i][j] = num++;
                bool valid = true;

                if (i > 0 && isPrime(abs(grid[i][j] - grid[i - 1][j])))
                    valid = false;

                if (j > 0 && isPrime(abs(grid[i][j] - grid[i][j - 1])))
                    valid = false;

                if (valid)
                    break;
            }
        }
    }

    // Print the constructed grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        constructGrid(n, m);
        cout << endl;
    }

    return 0;
}
*/

/*#include <iostream>
#include <cmath>
#include<vector>
using namespace std ; 
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n ; 
        cin>>n ; 
        string s ;  
        cin>>s ; 
        int i = 0 ; 
        vector<pair<int,int>>v ; 
        while(i<n){
            char c = s[i] ;
            int j = i+1 ;
            while(j<n && s[j]!=c){
                j++; 
            }
           // s.erase(i+1,j-i);
           if(i!=j){
                v.push_back(make_pair(i,j)) ;

           }
            i = j+1 ; 
        }
        int siz = v.size() ;
        int sizdec = 0 ; 
        for(int j = 0 ;j<siz ; j++){
            int x = v[j].first ; 
            int y = v[j].second ; 
            s.erase(x+1-sizdec, y-x) ;
            sizdec += y-x ; 
        }
        cout<<s<<endl; 
    }
}
*/
/*
#include <iostream>
#include <cmath>
using namespace std ; 
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n,k ; 
        cin>>n ; 
        cin>>k ; 
        // cost = 2^i ; 
        // if(n>=allcost) then return 2^k 
        // else 
        long long int totalcost  = 0 ; 
        for(int i = 0 ;i<=k-1 ;i++){
            totalcost += pow(2,i) ;
            if(totalcost > n){
                break ; 
            }
        }
        if(totalcost <=n){
            cout<<pow(2,k)<<endl ; 
        }
        else {
            cout<<n+1<<endl; 
        }
    }
}
*/

#include <iostream>
#include <cmath>
using namespace std ; 
#include<unordered_map> 
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n,k,q ; 
        cin>>n>>k>>q ;
        int ar[n] ; 
        unordered_map<int, bool> m;
        for (int i = 0; i < n; i++) {
            m[i] = false; // Set default value to false
        }
        for(int i = 0;i<n ;i++){
            cin>>ar[i] ; 
            if(ar[i]>q){
                m[i] = true ; 
            }
        } 
        int i = 0  ; 
        int ans = 0 ; 
        while(i<n){
            int j = i ; 
            while(j<n && m[j]==false){
                j++; 
            }
            // k must taken 
            int a = j-i-k+1 ; 
            int b = a ; 
            while(a>0){
                b = a ;
                ans += b ; 
                a--; 
            }
            
            //cout<<ans<<" "<<endl;
            i = j+1 ; 
        }
        cout<<ans<<endl; 
    }
}
