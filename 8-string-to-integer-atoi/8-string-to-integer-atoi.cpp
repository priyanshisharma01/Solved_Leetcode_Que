class Solution {
public:
    int myAtoi(string s) {
        
        // conditions
        //     start from space or symbol like +/- or numbers
        //     if start from any other except above mentioned we can return 0
        //     if numbers exceeds 32 bit range we can return boundary of the 32 bit limits as per the symbol mentioned in                  string
                    
        
        // declarations and assignments
        long long number=0;
        int index =0;
        int max = INT_MAX;
        int min = INT_MIN;
        int sign =1;
        
        // check for emptry string
        if(s == ""  ) return 0;
        
        // check and ignore spaces at prefix
        while(s.length() > index && s.at(index) == ' ') {
            index++;
        }

        // find and store the symbol
        if(s.length() > index && s.at(index) == '-') {
            sign =-1;
            index++;
        } else if(s.length() > index && s.at(index) =='+') {
            sign =1;
            index++;
        }

        // find and store the numbers into the number variable 
        while(s.length() > index && ('0' <= s.at(index) && s.at(index) <= '9')) {
            number = number*10;
            number = number+(s.at(index)-'0');
            if(number/max!=0 && (sign == 1 || sign==0)) {
                number = max;
                return number;
            }
            if(number/min !=0 && sign ==-1) {
                number = min;
                return number;
            }

            index++;
        }
        
        // return the number with sign
        return number*sign;
    }
};