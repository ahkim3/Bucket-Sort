/*
Name: Andrew Kim
Date: May 13, 2021
Program: Bucket Sort

I hereby certify that this program represents my
work and that the design and logic was completed
without outside assistance.

Signature: Andrew Kim
*/

#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

void insertionSort(vector<unsigned int>&, const unsigned int);


int main()
{
	unsigned int bucketNumber, max = 0,	min = RAND_MAX, range, index;
	unsigned int* nums = new unsigned int[200];
	vector<vector<unsigned int>> buckets;
	vector<unsigned int> bucket;

	srand((unsigned)time(NULL));

	// Create 200 pieces of random data between 1 and randmax
	for (unsigned int i = 0; i < 200; i++)
		nums[i] = (rand() % RAND_MAX) + 1;

	// Print unsorted numbers
	cout << "Unsorted numbers:" << endl;
	for (unsigned int i = 0; i < 200; i++)
		cout << nums[i] << " ";
	cout << endl << endl;

	// Prompt user for number of buckets
	cout << "Please enter the number of desired buckets: ";
	cin >> bucketNumber;

	// Find maximum value
	for (unsigned int i = 0; i < 200; i++)
		if (nums[i] > max)
			max = nums[i];

	// Find minimum value
	for (int i = 199; i >= 0; i--)
		if (nums[i] < min)
			min = nums[i];

	//Determine range of each bucket
	range = (max - min) / bucketNumber;

	// Assign elements into buckets
	for (int j = 1; j <= bucketNumber + 1; j++)
	{
		for (int i = 0; i < 200; i++)
		{
			// Assigns elements that are within range of selected bucket
			if (nums[i] >= ((j - 1) * range) && nums[i] <= (j * range))
				bucket.push_back(nums[i]);
		}
		buckets.push_back(bucket); // Push bucket vector onto vector of buckets
		bucket.clear(); // Reset bucket vector
	}

	// Sort buckets
	for (unsigned int i = 0; i < bucketNumber; i++)
		insertionSort(buckets.at(i), buckets.at(i).size());

	// Copy sorted elements from buckets into original array
	index = 0;
	for (unsigned int j = 0; j <= bucketNumber; j++)
	{
		for (unsigned int i = 0; i < buckets.at(j).size(); i++)
		{
			nums[index] = buckets.at(j).at(i);
			index++;
		}
	}

	// Print sorted numbers
	cout << endl << "Sorted numbers:" << endl;
	for (unsigned int i = 0; i < 200; i++)
		cout << nums[i] << " ";

	// Deallocate memory
	delete[] nums;
}


// Sorts elements in array via insertion sort
void insertionSort(vector<unsigned int>& nums, const unsigned int size)
{
	int j, limit;

	for (unsigned int i = 1; i < size; i++)
	{
		limit = nums.at(i); // Selects first unsorted element
		j = i - 1;

		// Shifts elements of array to the right
		while (j >= 0 && nums.at(j) > limit)
		{
			nums.at(j + 1) = nums.at(j);
			j = j - 1;
		}

		nums.at(j + 1) = limit; // Places unsorted element in sorted position
	}
}
