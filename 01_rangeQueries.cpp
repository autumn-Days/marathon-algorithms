#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

int sum1DprefixSum(int n ,int init, int final)
{
    //This function was built for receiving coordinates for a 1-based array
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
        so that you won't have to pass through all the `n`
        elements of the array again for building it.
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

int matrixprefixSum_easyWay(int n, int m,
                        pair<int,int> upperLeft, pair<int,int>upperRight,
                        pair<int,int> lowerLeft, pair<int,int>lowerRight)
{
    //This function was built for receiving coordinates for a 0-based matrix

    int prefixMatrix[n+1][m+1];

    /*
    buiding n+1, m+1 array with 0th-row and 0th-column fullfilled with zeros
    This function has the `easyWay` suffix, because the easier way to implement
    a prefix matrix is by having an extra row and extra collumn fullfilled with
    zeros, which will lead to an O((n+1)*(m+1) + n*m) complexity.

    The harder way is paying close attention to border-cases, which will lead
    to a O(n*m) complexity.
    */
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            prefixMatrix[i][j] = 0;
        }
    }

    int elem = 0;

    //building the actual prefix matrix
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            cin >> elem;
            prefixMatrix[i][j] = elem - prefixMatrix[i-1][j-1] + prefixMatrix[i-1][j] + prefixMatrix[i][j-1];
        }
    }
    
    return prefixMatrix[lowerRight.first + 1][lowerRight.second +1]
            - prefixMatrix[lowerLeft.first + 1][lowerLeft.second-1 + 1]
            - prefixMatrix[upperRight.first-1 + 1][upperRight.second + 1]
            + prefixMatrix[upperLeft.first-1 + 1][upperLeft.second-1 + 1];
}

void testMatrixprefixSum_easyWay()
{
    cout << matrixprefixSum_easyWay(4,4,
            make_pair(1,1),
            make_pair(1,2),
            make_pair(2,1),
            make_pair(2,2)) << endl; //ok
}


int main()
{
    cin.tie(0);
    //testing 1D prefixSum
    //test1DprefixSum();
    testMatrixprefixSum_easyWay();
}