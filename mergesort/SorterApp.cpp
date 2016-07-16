#include "MergeSort.h"

using namespace std;

int main()
{
    cout << "Merge Sort App : \n\n Enter n > ";
    int n;
    cin >> n;
    int *data = new int[n];
    int *base = data;
    if(data != NULL)
    {
        ITERATE(n)
        {
            int temp;
            cout << (i+1) << " : ";
            cin >> temp;
            *data++ = temp;
        }
        data = base;

        MergeSort* util = new MergeSort (n, data);
        util->sort ();
        util->displayState ();

    }
    int a;
    cin >> a;
    return 0;
}
