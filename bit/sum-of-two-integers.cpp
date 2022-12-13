/**
* @description:
* Step 1: we must simulate addition by using bit manipulation
* Step 2: addition is just XOR'ing two values in a position and having a possible carry
* Step 3: Calc carry by AND operator, calc addition simulation by XOR operator
* Step 4: Mutate b in place by setting it to new carry value 
    4.1: We left shift b by 1 in order to simulate a carry moving to the value to the left
    4.2: cast b to unsigned int because if b is signed, left shifting a signed value will 
    lead to undefined behavior
* Step 5: Keep looping and simulating XOR addition until no carry remains (b = 0)
*/
class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while(b != 0) {
            carry = a & b;
            a = a ^ b;
            b = (unsigned int)(carry) << 1;
        }
        return a;
    }
};
