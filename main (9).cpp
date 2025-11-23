#include <iostream>
#include <iomanip>
using namespace std;

void createArray(int a[], int n, int i = 0)
{
    if (i == n) return;
    cout << "a[" << i << "] = ";
    cin >> a[i];
    createArray(a, n, i + 1);
}

void printArray(const int a[], int n, int i = 0)
{
    if (i == n)
    {
        cout << endl;
        return;
    }
    cout << setw(5) << a[i];
    printArray(a, n, i + 1);
}

int findMinIndex(const int a[], int n, int i = 1, int minIndex = 0)
{
    if (i == n) return minIndex;
    if (a[i] < a[minIndex]) minIndex = i;
    return findMinIndex(a, n, i + 1, minIndex);
}

int findMaxIndex(const int a[], int n, int i = 1, int maxIndex = 0)
{
    if (i == n) return maxIndex;
    if (a[i] > a[maxIndex]) maxIndex = i;
    return findMaxIndex(a, n, i + 1, maxIndex);
}

double averageOfIndexes(int minIndex, int maxIndex)
{
    return (minIndex + maxIndex) / 2.0;
}

int main()
{
    int n;
    cout << "Vvedit kilkist elementiv masyvu: ";
    cin >> n;

    int* a = new int[n];

    cout << "\n--- Formuvannia masyvu ---\n";
    createArray(a, n);

    cout << "\n--- Masyv ---\n";
    printArray(a, n);

    int minIndex = findMinIndex(a, n);
    int maxIndex = findMaxIndex(a, n);

    double avg = averageOfIndexes(minIndex, maxIndex);

    cout << "\nIndeks minimalnoho elementa: " << minIndex << endl;
    cout << "Indeks maksymalnoho elementa: " << maxIndex << endl;
    cout << "Serednie arytmetychne indeksiv = " << avg << endl;

    delete[] a;
    return 0;
}
