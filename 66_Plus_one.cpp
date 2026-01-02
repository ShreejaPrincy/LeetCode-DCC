//codewithmik

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        while(n>=0){
            if(digits[n]<9){
                digits[n]++;
                return digits;
            }
            digits[n]=0;
            n--;
        }

        digits.insert(begin(digits),1);
        return digits;
    }
};


//my code

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        int carry=1;
        while(n>=0){
            int i=(digits[n]+carry)%10;
            carry=(digits[n]+carry)/10;
            digits[n]=i;
            n--;
        }
        cout<<carry;
        if(carry>0){
            digits[0]=1;
            digits.push_back(0);
        }
        return digits;
    }
};


