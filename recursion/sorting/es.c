// mergesort

int main ()
{


    return 0;
}

void MergeSort(int arr[], int p, int r)
{
    int q;

    if(p < r) {

        q = r/2;

        MergeSort(arr,p,q); //left arr
        MergeSort(arr,q+1,r); //righ arr

        //merge
    }
}

