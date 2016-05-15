package leetcode;



public class leetcode334 {

	public boolean increasingTriplet(int[] nums) {
  
        int a=(int)Integer.MAX_VALUE,b=(int)Integer.MAX_VALUE;
        for(int i:nums){
        	if(a>=i)
        		a=i;
        	else if(b>=i)
        		b=i;
        	else{
        		return true;
        	}
        }
        return false;
    }
	
}
