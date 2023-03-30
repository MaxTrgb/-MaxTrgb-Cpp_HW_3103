/*Lesson #14
Arrays and algorithms*/


#include <iostream>
#include <algorithm>

using namespace std;

// Function to swap two integers
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
// Binary search function to find target in array from index left to index right
int binarySearch(int arr[], int left, int right, int target) {
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target) {
			return mid;// return index of target if it is found
		}

		if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return -1;// return -1 if target is not found
}
// Merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays L[] and R[]
	int* L = new int[n1];
	int* R = new int[n2];

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]
	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	// Free memory allocated for temp arrays
	delete[] L;
	delete[] R;
}

// Merge sort function to sort array arr[] from index l to index r
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
void shellSort(int arr[], int n) {

	// Start with a large gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2) {

		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is gap sorted
		for (int i = gap; i < n; i += 1) {

			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct location for a[i] is found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			// put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
}
int main()
{
	int SIZE;
	srand(time(NULL));
	cout << "Enter size of array: ";
	cin >> SIZE;

	// Fill the array with user input
	int* arr = new int[SIZE];
	int choice;
	cout << "Fill th array: ";

	for (int i = 0; i < SIZE; i++) {
		int value;
		cin >> value;

		//check if value already exists in array
		bool duplicate = false;
		for (int j = 0; j < i; j++) {

			if (arr[j] == value) {

				duplicate = true;
				break;
			}
		}

		if (duplicate) {

			cout << "Duplicate value entered, please enter a unique value." << endl;
			i--; //decrement i so that current index can be entered again
		}
		else {
			arr[i] = value;
		}
	}

	// Display the array
	for (int i = 0; i < SIZE; i++) {

		cout << arr[i] << " ";
	}

	while (true) {

		// sorting and searching algorithms to choose from
		cout << "\nMake your choice: " << endl;
		cout << "1 - Buble sort;" << endl;
		cout << "2 - Selection sort;" << endl;
		cout << "3 - Insertion sort;" << endl;
		cout << "4 - Random order;" << endl;
		cout << "5 - Line search;" << endl;
		cout << "6 - Binary search;" << endl;
		cout << "7 - Expand max num of books;" << endl;
		cout << "8 - Enter the book in any position;" << endl;
		cout << "9 - Merge sort;" << endl;
		cout << "10 - Shell sort;" << endl;
		cout << "11 - Exit;" << endl;
		cin >> choice;

		// Perform the corresponding operation based on user input
		// Perform bubble sort
		if (choice == 1) {

			int select;
			cout << "Select rise 1 or decline 2: "; cin >> select;

			
			if (select == 1) {  // ascending order 
				for (int i = 1; i < SIZE; i++) {
					int key = arr[i];
					int j = i - 1;
					while (j >= 0 && arr[j] > key) {
						arr[j + 1] = arr[j];
						j--;
					}
					arr[j + 1] = key;
				}
			}
			else if (select == 2) {  // descending order 
				for (int i = 1; i < SIZE; i++) {
					int key = arr[i];
					int j = i - 1;
					while (j >= 0 && arr[j] < key) {
						arr[j + 1] = arr[j];
						j--;
					}
					arr[j + 1] = key;
				}
			}
			else {
				cout << "Invalid choice.\n";
				return 0;
			}

			cout << "Sorted array:\n";
			for (int i = 0; i < SIZE; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;

			
		}
		// Perform selection sort
		if (choice == 2) {

			int select;
			cout << "Select rise 1 or decline 2: "; cin >> select;

			if (select == 1) {// ascending order 
				for (int step = 0; step < SIZE - 1; step++) {

					int min_idx = step;

					for (int i = step + 1; i < SIZE; i++) {

						if (arr[i] < arr[min_idx])
							min_idx = i;
					}
					swap(arr[min_idx], arr[step]);
				}
			}
			if (select == 2) {// descending order 

				for (int step = 0; step < SIZE - 1; step++) {

					int min_idx = step;

					for (int i = step + 1; i < SIZE; i++) {

						if (arr[i] > arr[min_idx])
							min_idx = i;
					}
					swap(arr[min_idx], arr[step]);
				}
			}

			for (int i = 0; i < SIZE; i++) {
				cout << arr[i] << " ";
			}

		}
		// Perform insertion sort
		if (choice == 3) {
			int select;
			cout << "Select 1 rise or decline 2: ";
			cin >> select;
			if (select == 1) {// ascending order 
				for (int i = 1; i < SIZE; i++) {
					int key = arr[i];
					int j = i - 1;
					while (j >= 0 && arr[j] > key) {
						arr[j + 1] = arr[j];
						j--;
					}
					arr[j + 1] = key;
				}
			}
			else if (select == 2) {// descending order 
				for (int i = 1; i < SIZE; i++) {
					int key = arr[i];
					int j = i - 1;
					while (j >= 0 && arr[j] < key) {
						arr[j + 1] = arr[j];
						j--;
					}
					arr[j + 1] = key;
				}
			}
			else {
				cout << "Invalid selection" << endl;
				continue;
			}

			cout << "Sorted array: ";
			for (int i = 0; i < SIZE; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;

		}
		// Shuffle the array in random order
		if (choice == 4) {

			// Shuffle the array using the Fisher-Yates shuffle algorithm
			for (int i = SIZE - 1; i > 0; i--) {
				int j = rand() % (i + 1);
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

			cout << "Randomized values:\n";
			for (int i = 0; i < SIZE; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		// Perform linear search on the array
		if (choice == 5) {

			// Display the original array
			cout << "Original array:" << endl;
			for (int i = 0; i < 5; i++) {

				cout << arr[i] << " ";
			}
			cout << endl;

			// Get the target element from the user
			int target;
			cout << "Enter the element to search for: ";
			cin >> target;

			// Linear search for the target element
			int index = -1;
			for (int i = 0; i < 5; i++) {

				if (arr[i] == target) {

					index = i;
					break;
				}
			}

			// Display the search result
			if (index != -1) {

				cout << "Found target element at index " << index << endl;
			}
			else {

				cout << "Target element not found in the array" << endl;
			}

		}
		// Perform binary search on the array
		if (choice == 6) {

			sort(arr, arr + 5);

			// Display the original array
			cout << "Original array:" << endl;
			for (int i = 0; i < 5; i++) {

				cout << arr[i] << " ";
			}
			cout << endl;
			// Get the target element from the user
			int target;
			cout << "Enter the element to search for: ";
			cin >> target;

			// Binary search for the target element
			int index = binarySearch(arr, 0, 4, target);

			// Display the search result
			if (index != -1) {

				cout << "Found target element at index " << index << endl;
			}
			else {

				cout << "Target element not found in the array" << endl;
			}

		}
		// Expand the maximum number of books
		if (choice == 7) {

			// Allow the user to expand the size of the array
			cout << "Do you want to expand the size of the array? (y/n): ";
			char choice;
			cin >> choice;

			if (choice == 'y') {
				// Get the new size of the array from the user
				int new_size;
				cout << "Enter the new size of the array: ";
				cin >> new_size;

				// Resize the array using dynamic memory reallocation
				int* new_arr = new int[new_size];
				for (int i = 0; i < SIZE; i++) {
					new_arr[i] = arr[i];
				}
				delete[] arr;
				arr = new_arr;

				// Fill in the additional elements with new random integer elements
				for (int i = SIZE; i < new_size; i++) {
					arr[i] = rand() % 100 + 1;
				}

				// Update the size variable
				SIZE = new_size;

				// Display the updated array
				cout << "Updated array:" << endl;
				for (int i = 0; i < SIZE; i++) {
					cout << arr[i] << " ";
				}
				cout << endl;
			}
		}
		// Add a book to the array in any position
		if (choice == 8) {

			// Ask the user for the index and new value
			int index, value;
			cout << "Enter the index of the value you want to replace (0-" << SIZE - 1 << "): ";
			cin >> index;
			cout << "Enter the new value: ";
			cin >> value;

			// Replace the existing value with the new value
			arr[index] = value;

			// Print the updated array
			cout << "Updated array:" << endl;
			for (int i = 0; i < SIZE; i++) {

				cout << arr[i] << " ";
			}
			cout << endl;
		}
		// Perform merge sort
		if (choice == 9) {
			// Output the original unsorted array
			cout << "Original array: ";
			for (int i = 0; i < SIZE; i++) {

				cout << arr[i] << " ";
			}
			cout << endl;

			// Call the merge sort function to sort the array
			mergeSort(arr, 0, SIZE - 1);

			cout << "Sorted array: ";
			for (int i = 0; i < SIZE; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;

			// Deallocate the memory allocated for the array
			delete[] arr;
		}
		// Perform shell sort
		if (choice == 10) {

			// Output original array before sorting
			cout << "Original array: ";
			for (int i = 0; i < SIZE; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;

			// Sort the array using shellSort function
			shellSort(arr, SIZE);

			// Output sorted array after sorting
			cout << "Sorted array: ";
			for (int i = 0; i < SIZE; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;

			delete[] arr;
		}
		// Exit the program
		if (choice == 11) {

			cout << "Exiting..." << endl;
			return 0;
		}

	}
}