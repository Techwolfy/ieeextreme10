from itertools import combinations, chain

def split_list(data, n):
    from itertools import combinations, chain
    for splits in combinations(range(1, len(data)), n-1):
        result = []
        prev = None
        for split in chain(splits, [None]):
            result.append(data[prev:split])
            prev = split
        yield result

def get_sum_of_ranges(data):
    sum_of_ranges = 0
    for each in data:
        sum_of_ranges += each[-1] - each[0]
    return sum_of_ranges
    
if __name__ == "__main__":
    
    # Get number of test cases
    numCase = int(input())
    
    # For each test case
    for i in range(numCase):
        n, k = input().split()
        n = int(n)
        k = int(k)
        min_sum_of_ranges = -1 #-1 means no sum of ranges is computed yet
        
        weights = []
        
        # Get the weights of dogs
        for j in range(n):
            weights.append(int(input()))
            
        # sort list in increasing order
        weights.sort() 
        
        # test all combinations and find the minimum sum of ranges
        all_possible_combinations = split_list(weights, k)
        for one_combination in all_possible_combinations:
            sum_of_ranges = get_sum_of_ranges(one_combination)
            if min_sum_of_ranges == -1 or min_sum_of_ranges > sum_of_ranges:
                min_sum_of_ranges = sum_of_ranges
        print(min_sum_of_ranges)
