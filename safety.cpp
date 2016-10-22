#include <iostream>
#include <string>

int main(){
    std::ios_base::sync_with_stdio (false);
    std::string password;
    std::cin >> password;
    int numCase;
    std::cin >> numCase;
    std::string current_password = password;
    for (int n = 0; n < numCase; n++) {
        int comm;
        std::cin >> comm;
        int i, j, k, m, p;
        switch(comm){
            case 1:
                /*'''Check if 
                the substring that starts at position i and ends at position j (inclusive) of the current password 
                is equal to 
                the substring that starts at position k of the current password and has length j - i + 1'''*/
                std::cin >> i;
                std::cin >> j;
                std::cin >> k;
                //if (current_password.substr(i-1,j) == current_password.substr(k-1,k+j-i)) {
                if (current_password.compare(i-1,j-i+1,current_password,k-1,j-i+1) == 0) {
                    std::cout << 'Y' << std::endl;
                } else {
                    std::cout << 'N' << std::endl;
                }
                break;
            case 2:
                /*'''Replace 
                the substring that starts at position i and ends at position j (inclusive) of the current password, 
                with 
                the substring that starts at position k of the original password and has length j - i + 1 '''*/
                std::cin >> i;
                std::cin >> j;
                std::cin >> k;
                current_password.replace(i-1,j-i+1,password,k-1,j-i+1);
                //current_password = current_password.substr(0,i-1) + password.substr(k-1,k+j-i) + current_password.substr(j);
                break;
            case 3:
                /*'''Replace 
                each letter in the string that starts at position i and ends at position j (inclusive) of the current password 
                with 
                the next letter of the Latin alphabet, except if the input letter is 'z' where it would be replaced with 'a'.'''*/
                std::cin >> i;
                std::cin >> j;
                //std::cout << current_password << std::endl;
                for (k = i-1; k < j; ++k) {
                    if (current_password[k] == 'z') {
                        current_password[k] = 'a';
                    } else {
                        ++(current_password[k]);
                    }
                }
                //std::cout << current_password << std::endl;
                break;
            default:
                break;
        }
    }

    return 0;
}
