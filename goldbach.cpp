#include <iostream>
#include <vector>
typedef unsigned int uInt;
uInt odd_uInteger;

void combinationUtil(uInt arr[], uInt data[], uInt start, uInt end, 
                     uInt index, uInt r);
 
// The main function that pruInts all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(uInt arr[], uInt n, uInt r)
{
    // A temporary array to store all combination one by one
    uInt data[r];
 
    // PruInt all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, r);
}
 
/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be pruInted */
void combinationUtil(uInt arr[], uInt data[], uInt start, uInt end,
                     uInt index, uInt r)
{
    // Current combination is ready to be pruInted, pruInt it
    if (index == r)
    {
        if (data[0] + data[1] + data[2] == odd_uInteger) {
            std::cout << data[0] << " " << data[1] << " " << data[2] << std::endl;
            exit(0);
        }
        return;
    }
 
    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (uInt i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
 

int main()
{
    std::ios_base::sync_with_stdio (false);
    std::cin >> odd_uInteger;
    std::vector<uInt> prime_numbers;
    //prime_numbers.reserve(odd_uInteger);
    // FIND PRIME NUMBERS
    bool is_prime;

	uInt count = 1;
	uInt my_prime = 2; //set to first prime

	for(uInt i = 3; count < odd_uInteger; i += 2) { //skip ALL even numbers, find 10001st prime

		is_prime = true;

		for(uInt j = 3; j * j <= i && is_prime; j += 2) //again, skipping all even numbers
			if(i % j == 0) is_prime = false;

		if(is_prime) {
			++count;
			my_prime = i;
			prime_numbers.push_back(i);
			if (i > odd_uInteger) {
			    prime_numbers.pop_back();
			    break;
			}
		}
	}

    uInt arr[prime_numbers.size()];
    int i = 0;
    for (auto item : prime_numbers) {
        arr[i++] = item;
    }
    uInt r = 3;
    uInt n = prime_numbers.size();
    printCombination(arr, n, r);
    std::cout << "counterexample" << std::endl;
    return 0;
}
