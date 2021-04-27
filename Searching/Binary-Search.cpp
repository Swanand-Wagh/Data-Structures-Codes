#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int i, size, num, first, last, middle;

    cout << "How many elements: ";
    cin >> size;
    int arr[size];

    cout << "Enter Elements (in ascending order): ";
    for (i = 0; i < size; i++)
        cin >> arr[i];

    cout << "\nEnter Element to be Search: ";
    cin >> num;
    first = 0;
    last = size - 1;
    middle = (first + last) / 2;

    while (first <= last)
    {
        if (arr[middle] < num)
            first = middle + 1;
        else if (arr[middle] == num)
        {
            cout << "\nThe number, " << num << " found at Position " << middle + 1;
            break;
        }
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }

    if (first > last)
        cout << "\nThe number, " << num << " is not found in given Array";
    cout << endl;
    return 0;
}