class Solution {
public:
    int findComplement(int num) {
       if(num == 0) return 1;
        unsigned mask = ~0;
        while( mask & num ) mask = mask << 1;
        return ~num ^ mask; 
    }
};

