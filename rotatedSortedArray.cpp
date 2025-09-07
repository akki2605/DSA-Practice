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
int rotatedSortedArray(vector<int>, int, int);

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

	int n, target;
	vector<int> arr;
	
	cin>>n>>target;

	for(int i=0; i<n; ++i){
		int x;
		cin >>x;
		arr.push_back(x);
	}
	cout<< rotatedSortedArray(arr,n, target);
}

int rotatedSortedArray(vector<int> arr, int n, int target){

	int low=0, high=n-1, mid;

	while( low <= high ){
		
		mid =(low + high)/2;
		
		//found the target 
		if(arr[mid]== target){
			return 1;
		}
		
		//handel dublicated 
		 if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
				low = low + 1;
				high = high - 1;
				continue;
		}

		//left half is sorted
		if(arr[low] <= arr[mid] ){

			//check in the sorted half
			if(arr[low]<= target && target <= arr[mid]){
				high = mid-1;
			}else
			{
				low = mid+1;
			}

		}else//right half is sorted 
		{
			//check in the sorted half
			if(arr[mid] <= target  && target <= arr[high]){
				low=mid+1;
			}else
			{
				high=mid-1;
			}
		}
	}
	return -1;
}