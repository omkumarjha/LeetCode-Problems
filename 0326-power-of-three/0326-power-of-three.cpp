class Solution {
public:
    bool isPowerOfThree(int n) {
        /* Edge case , iterative way 

        if(n <= 0){
            return false;
        }
        else{
            while(n != 0 && n != 1){
                if(n % 3 == 0){
                    n = n / 3;
                }
                else{
                    return false;
                }
            }
        }
          return true;

        */

        /* Base case ,  Recursive way 
        if(n <= 0){
            return false;
        }
        if(n == 1){
            return true;
        }

        // processing 
        if(n % 3 != 0){
            return false;
        }

        n = n / 3;
        return isPowerOfThree(n);
        */


        // By using math

        return n > 0 && 1162261467 % n == 0;

    }
};