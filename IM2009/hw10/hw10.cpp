# include <iostream>
# define INFINITY 922337203685477580 
// assign the infinity value: choose llong_max / 100 since using llong_max directly may cause over_flow
using namespace std;

int main(){
	int n = 0, k = 0;
    cin >> n >> k; 
	// input n(the number of distinct red values that occur in the original image) and 
	// k(the number of distinct red values allowed in the posterized image)
    int* r = new int [n + 1];
    long long* p = new long long [n + 1];    
    for(int i = 1 ; i <= n ; i++)
        cin >> r[i] >> p[i]; // input r(a red intensity value) and p(the number of pixels having red intensity r) for n times 
    if(n <= k){ // if n >= k, we can directly choose all r of the input which will cause the output to be 0
        cout << 0;
        return 0;
    }
    long long** pre_table = new long long* [n + 1]; // construct a table to store for the minimum achievable sum of squared errors 
    for(int i = 0 ; i <= n ; i++){ // initialize the pre_table
        pre_table[i] = new long long [n + 1];
        for(int j = 0 ; j <= n ; j++)
            pre_table[i][j] = INFINITY; 
    }  
    for(int l = 0 ; l < 256 ; l++){ 
		// Calculate to make pre_table[i][j] stored the minimum achievable sum of squared errors 
		// for the i-th to j-th r of v from 0 to 255
        for(int i = 1 ; i <= n ; i++){
            long long ans = 0; 
            for(int j = i ; j <= n ; j++){ 
                ans += (r[j] - l) * (r[j] - l) * p[j]; // (r[i] - v[i])^2 * p[i]
                pre_table[i][j] = min(pre_table[i][j], ans); 
				// making pre_table[i][j] to be the minimum achievable sum of squared errors
            }
        }
    }
    long long** dp_table = new long long* [n + 1]; 
	// use the concept of dynamic programming to solve the problem 
	// construction for the dp_table
    for(int i = 0 ; i <= n ; i++){
        dp_table[i] = new long long[k + 1];
        for(int j = 0 ; j <= k ; j++)
            dp_table[i][j] = INFINITY; // initialize dp_table to be infinity
    }
    dp_table[0][0] = 0; // make dp_table[0][0] to be 0
    for(int i = 1; i <= n; i++){ 
        for(int j = 1 ; j <= k ; j++){ // with k v(s) to choose
            for(int l = 0 ; l < i ; l++){ 
                dp_table[i][j] = min(dp_table[i][j], dp_table[l][j - 1] + pre_table[l + 1][i]); 
            }
        }
    }
    cout << dp_table[n][k];
    return 0;
}
