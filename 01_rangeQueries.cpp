#include <iostream>
#include <vector>
using namespace std;

int sum1DprefixSum(int n ,int init, int final)
{
    if (n > 0)
    {
        init --;
        final --;
        vector<float> prefixArray = {}; 
        
        int elem = 0;
        cin >> elem;

        prefixArray.push_back(elem);

        /*
        You build the prefix array as you receive the input,
        so that you will only take to pass through all the `n`
        element again for buildig it.
        */
        for (int i = 1; i < n; i++)
        {
            cin >> elem;
            prefixArray.push_back(elem+prefixArray[i-1]);
        }
        
        if (n > 1)
            return prefixArray[final]-prefixArray[init-1];
        return prefixArray[final];
    }
    else
        return 0;

}

void test1DprefixSum()
{
    cout << sum1DprefixSum(10, 3, 8) << endl; //ok
    cout << sum1DprefixSum(10, 5, 10) << endl; //ok
    cout << sum1DprefixSum(0, 0, 0) << endl; //ok
    cout << sum1DprefixSum(1, 1, 1) << endl; //ok
    cout << sum1DprefixSum(10, 10, 10) << endl; //ok
}



int main()
{
    cin.tie(0);
    //testing 1D prefixSum
    test1DprefixSum();
    
}