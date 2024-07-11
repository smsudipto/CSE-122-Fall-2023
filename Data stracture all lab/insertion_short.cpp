
#include <iostream>
using namespace std;

int main() {
    int a[10];
    int i, m, n, position;

    cout << "Enter the size of the array (n): ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter the element to insert (m): ";
    cin >> m;

    cout << "Enter the position to insert at: ";
    cin >> position;

    // Shifting elements to the right to make space for the new element
    for (i = n - 1; i >= position - 1; i--) {
        a[i + 1] = a[i];
    }

    a[position - 1] = m;

    cout << "Array after insertion: ";
    for (i = 0; i < n + 1; i++) {
        cout << a[i] << " ";
    }

    return 0;
}





