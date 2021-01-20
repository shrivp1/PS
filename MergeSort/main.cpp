#include<iostream>
using namespace std;

template <class T>
class Array
{
private:
    T *a;
    T *c;
    int size;
public:
    explicit Array(int n) {
        size = n;
        a = new T[n];
        c = new T[n];
    }
    ~Array() {
        delete a;
        delete c;
    }
    void inputArray();
    void outputArray();
    void mergeSortedSubArrays(int, int, int, int);
    void mergeSortRecursive(int, int);
    void mergeSort();
};

template <class T>
void Array<T>::inputArray() {
    int i;
    cout << "\nEnter " << size << " elements of array\n\n";
    for ( i = 0; i < size; i++) {
        cin >> a[i];
    }
}

template <class T>
void Array<T>::outputArray() {
    int i;
    for ( i = 0; i < size; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

template <class T>
void Array<T>::mergeSortedSubArrays(int lb, int lr, int rb, int rr)
{
    int na, nb, nc, k;
    na = lb;
    nb = rb;
    nc = lb;
    while( (na <= lr) && (nb <= rr)) {
        if ( a[na] < a[nb] )
            c[nc] = a[na++];
        else
            c[nc] = a[nb++];
        nc++;
    }
    if ( na > lr ) {
        while ( nb <= rr )
            c[nc++] = a[nb++];
    }
    else {
        while ( na <= lr)
            c[nc++] = a[na++];
    }
    for ( k = lb; k <=rr; k++ )
        a[k] = c[k];
}

template <class T>
void Array<T>::mergeSortRecursive(int beg, int end)
{
    int mid;
    if ( beg < end )
    {
        mid = ( beg + end ) / 2;
        mergeSortRecursive(beg, mid);
        mergeSortRecursive(mid + 1, end);
        mergeSortedSubArrays(beg, mid, mid+1, end);
    }
}

template <class T>
void Array<T>::mergeSort()
{
    mergeSortRecursive(0, size-1);
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    Array<int> a(n);
    a.inputArray();
    cout << "\n\nInput Array is: ";
    a.outputArray();
    a.mergeSort();
    cout << "\n\nSorted Array is: ";
    a.outputArray();
}

