from math import log,ceil

def get_next_power_of_2(N):
    test = ceil(log(N+1,2))
    # handle incorrect logarithm
    if 2**(test-1)>N:
        return test-1
    if 2**(test+1)<=N:
        return test+1
    return test
    
if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        N = int(input())
        '''
        # RULES
        petals = list(range(N))
        remainder = 1
        while len(petals) >= 2:
            #print(len(petals))
            indices_to_delete = []
            for j in range(len(petals)):
                if j%2==remainder:
                    indices_to_delete.append(j)
            if len(petals)-1 == indices_to_delete[-1]:
                remainder = 1
            else:
                remainder = 0
            for k in indices_to_delete[::-1]:
                petals.pop(k)
            #remainder = len(petals)%2
        print(str(N)+ ' : '+str(petals[0]+1))
        '''
        # PATTERN, which does not pass all the tests rn
        '''
        1: 1
        2: 1
        3: 3
        4: 1
        5: 3
        6: 5
        7: 7
        ...
        13: 2^4 - 2*3 + 1
        14: 2^4 - 2*2 + 1
        15: 2^4 - 2*1 + 1
        16: 2^5 - 2*16 + 1
        17: 2^5 - 2*15 + 1
        18: 2^5 - 2*14 + 1
        '''
        next_power = get_next_power_of_2(N)
        second_number = 2**(next_power) - N
        #print("{} : 2^{} - 2*{} + 1".format(N,next_power,second_number)) #DEBUG_MESSAGE
        print(2**next_power - 2*second_number + 1)
