//happy number if we do the sum of its squared digits it will end to be stucked at 1
//but every other number will never stuck at 1 and it will make a acycle to its old version or results 
//so i had to detect a cycle 
class Solution {
public:
    bool isHappy(int n) 
    {
      int slow = n , fast = n;
      do
      {
        slow = getSquare(slow);
        fast = getSquare(getSquare(fast));
      }
      while (slow != fast);

      return slow == 1;  
    }
    int getSquare(int num)
    {
        int sum = 0 , digit;
        while(num > 0)
        {
            digit = num % 10;
            sum += digit * digit;
            num = num / 10;
        }
        return sum;
    }
};
