#include "MergeSort.h"

/*
method: displaystate

description:

display the current state of Elements in MergeSort
O(n) reads element one by one
*/
void MergeSort::displayState (void)
{
    ITERATE(n)
    {
        std::cout << this->elem[i] << "\t";
    }
    std::cout << std::endl;
}


/*
MergeSort Constructor

in: problem size n, int pointer to array of int elements
out : Constructs Object
*/
MergeSort::MergeSort (int n,int* data)
{
    if (n <= 0)
    {
        // disarms the object to do any further sorting
        this->clearState ();
        return;
    }
    this->elem = new int[n];
    if (elem == NULL)
    {
        // Out of Memory Situation
        std::cerr << "MergeSort.Elem failed due to Out of Memory Issue";
    }
    // now Element array is created , fill elements and update necessary State
    ITERATE (n)
    {
        elem[i] = *data++;
    }
    this->n = n;
    updateState ();
}

void MergeSort::sort ()
{
      // lack of conceptual clarity , either to n-1 or n
      // ] or } has to be clearly mentioned
      this->doMergeSort (0, n-1);
}

void MergeSort::doMergeSort (int start, int end)
{
    if (start < end)
    {
        int mid = ((end - start)+1)  / 2 ;
        if (mid != 0)
        {
            doMergeSort (start, start+mid-1);
            doMergeSort (start+mid, end);
            Merge (start,start+mid,end);
        }
    }
}
// MergeSort :: Merge
// args : start, mid, end
// start - start index from which the array has to be merged
// mid   - mid element that splits L and R Array
void MergeSort::Merge (int start, int mid, int end)
{
    int n1 = mid - start;
    int n2 = end - mid + 1;

    // So to assert what does n1 and n2 contains 
    // for 4 elements , start = 0 , mid = 2 , end = 4
    // n1 = 2 and n2 = 2 , which is true

    int* lArr = new int[n1];
    int* rArr = new int[n2];

    // copy the elements back into this new array
    ITERATE (n1)
    {
      lArr[i] = this->elem[start+i];
    }

    ITERATE_(mid,end)
    {
       rArr[i] = this->elem[mid+i];
    } 

    // sub arrays with Left and right components are created
    // Now we need to merge 
    int x=0;
    int y=0;

    for (int j=start; j <= end; j++)
    {
      if (lArr[x] <= rArr[y])
      {
        this->elem[j] = lArr[x];
        x++;
      }
      else
      {
        this->elem[j] = rArr[y];
        y++;
      }
    }

    delete[] lArr;
   delete[] rArr;

}

void MergeSort::updateState ()
{
    if (this->elem != NULL && this->n > 0)
    {
        this->bReadyToSort = true;
    }
    this->nMergeSortCalls = 0;
    this->nCompares = 0;
    this->nMergeCalls = 0;
    this->nElemAccess = 0;
}

void MergeSort::clearState (void)
{
    this->bReadyToSort = false;
    this->nMergeSortCalls = 0;
    this->nCompares = 0;
    this->nMergeCalls = 0;
    this->nElemAccess = 0;
    if (this->elem)
    {
        delete[] elem;
    }
    this->n = -1;
}

int MergeSort::data(int i)
{
    return this->elem[i];
}

