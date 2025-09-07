#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	string s = "   Akash.  , kritika ,   rahul ,   adarsh ,   piyush  ";
	
	stringstream ss (s);

	string temp;
	
	vector<string> splitString;
	char delimeter = ',';
	
	while (getline ( ss, temp,  delimeter))
	{
		splitString.push_back(temp);

	}
	
	for(auto s : splitString ) cout<<s<<endl;
	

	return 0;
}