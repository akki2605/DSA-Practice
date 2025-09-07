#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <tuple>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iterator>
#include <sstream>
#include <fstream>

using namespace std;

#define ll long long
#define forn(n) for(int i=0; i<n; i++)
#define mod 1000000007

void solve();
int minimumRotatedSortedArray(vector<int>, int);

int main()
{
	//fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--) {
		solve();
		cout << "\n";
	}

	cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << " sec" << endl;
	return 0;
}

void solve()
{

	int n;
	vector<int> arr;
	
	cin>>n;

	for(int i=0; i<n; ++i){
		int x;
		cin >>x;
		arr.push_back(x);
		// cout<<arr[i]<<endl;
		

	}
	cout<< minimumRotatedSortedArray(arr,n);
}

int minimumRotatedSortedArray(vector<int> arr, int n){

	int low=0, high=n-1, mid;
	int ans = INT_MAX;

	while( low <= high ){
		
		mid =(low + high)/2;

		// if the search space is sorted 
		// then we can just return the arr[low]
		if(arr[low]<arr[high]){
			ans = min(ans, arr[low]);
			break;
		}

		//left half is sorted
		if(arr[low] <= arr[mid] ){
			// cout<<"left : low = "<<low<<" mid = "<<mid<<" high ="<<high<<endl;
			//check in the sorted half
			ans = min(ans, arr[low]);
			low = mid+1;
			
			// cout<<"updated : low = "<<low<<" mid = "<<mid<<" high ="<<high<<endl;
			// cout<<"ans = "<<ans<<endl;
			
		}else//right half is sorted 
		{
			// cout<<"right : low = "<<low<<" mid = "<<mid<<" high ="<<high<<endl;
			//check in the sorted half
			ans = min(ans, arr[mid]);
			high = mid-1;
			
			// cout<<"updated : low = "<<low<<" mid = "<<mid<<" high ="<<high<<endl;
			// cout<<"ans = "<<ans<<endl;
		}
	}
	return ans;
}