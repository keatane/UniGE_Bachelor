#include <iostream>
#include <vector>
using namespace std;

vector<int> Merge(std::vector<int>, std::vector<int>);
vector<int> MergeSort(std::vector<int>);
void PrintVector(vector<int> a);

int main()
{
    std::vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(20);
	a.push_back(5);
	a.push_back(10);
	a.push_back(15);
    
	cout << "Original linked list: \n"; 
    PrintVector(a);

    a = MergeSort(a);
    
	cout << "Sorted linked list: \n"; 
	PrintVector(a);

    return 0;
}

vector<int> Merge(vector<int> arr1, vector<int> arr2) {
    int size1 = arr1.size();
    int size2 = arr2.size();
    vector<int> res;
    int i1 = 0;
    int i2 = 0;
    while (i1 < size1 && i2 < size2) {
        if (arr1[i1] < arr2[i2]) {
            res.push_back(arr1[i1]);
            i1++;
        }
        else {
            res.push_back(arr2[i2]);
            i2++;
        }
    }
    while (i1 < size1) {
        res.push_back(arr1[i1]);
        i1++;
    }
    while (i2 < size2) {
        res.push_back(arr2[i2]);
        i2++;
    }
    return res;
}

vector<int> MergeSort(vector<int> arr) {
    if (arr.size() < 2) {
        return arr;
    }
    else if (arr.size() == 2) {
        // If array is of size 2, return it sorted
        if (arr[0] > arr[1]) {
            int swap = arr[1];
            arr[1] = arr[0];
            arr[0] = swap;
        }
        return arr;
    }
    else {
        // Recursively split in halves until all vectors are size 1 or 2, then merge
		vector<int> a = MergeSort(vector<int>(arr.begin(), arr.begin() + arr.size() / 2));
		vector<int> b = MergeSort(vector<int>(arr.begin() + arr.size() / 2, arr.end()));

		arr = Merge(a, b);
        return arr;
    }
}

void PrintVector(vector<int> a){
	 for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}