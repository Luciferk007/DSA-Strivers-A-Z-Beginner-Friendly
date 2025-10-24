#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> print_all_subsets_using_bit(vector<int> arr)
{
    int n = arr.size();
    int subset_max = 1 << n;              // total subsets = 2^n
    vector<vector<int>> ans;              // to store all subsets

    for (int num = 0; num < subset_max; num++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            // check if i-th bit in num is set
            if ((num & (1 << i)) != 0)
            {
                subset.push_back(arr[i]);
            }
        }
        ans.push_back(subset); // add one subset after inner loop ends
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> subsets = print_all_subsets_using_bit(arr);

    for (auto &s : subsets)
    {
        cout << "{ ";
        for (auto x : s)
            cout << x << " ";
        cout << "}\n";
    }
}
