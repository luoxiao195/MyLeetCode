public class Solution {
    public boolean isPowerOfFour(int num) {
        if((num&(num-1))==0)
        {
        	if((num&0x55555555)!=0)
        		return true;
        		
        }
		return false;
    }
}