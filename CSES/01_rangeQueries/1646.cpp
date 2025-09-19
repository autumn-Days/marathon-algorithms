/*
Given an array of n integers,
your task is to process q queries of the form:
what is the sum of values in range [a,b]?
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    long int n = 0, q = 0;
    cin >> n >> q;
    vector<long long int> prefix = {};
    long long int elem = 0;
    cin >> elem;
    prefix.push_back(elem);
    for (long int i = 1; i < n; i++)
    {
        cin >> elem;
        prefix.push_back(elem + prefix[i-1]);
    }
    long int lower = 0, upper = 0;
    for (long int j = 0; j < q; j++)
    {
        cin >> lower >> upper;
	if (lower != 1)
	        cout << prefix[upper-1] - prefix[lower-2] << endl; // antes você havia posto "prefix[lower-1]", mas nessa parte você não tira nada, é só mesmo a imporessão do limite superior.
	else
		cout << prefix[upper-1] << endl;
    }
}
