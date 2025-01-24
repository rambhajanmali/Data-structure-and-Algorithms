#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // crerate a vector

    vector<int> arr;
    int ans = sizeof(arr)/sizeof(int);
    cout  << ans << endl;
    cout << "Size of vector: " << arr.size() << endl;

    return 0;
}
