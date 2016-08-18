public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int len1=ransomNote.length();
        int len2=magazine.length();
        if(len1>len2)
            return false;
        HashMap<Character,Integer> r1=change(ransomNote,len1);
        HashMap<Character,Integer> r2=change(magazine,len2);
        for(char tmp:r1.keySet()){
            if(!r2.containsKey(tmp))
                return false;
            if(r1.get(tmp)>r2.get(tmp))
                return false;
        }

        return true;
    }
    public HashMap<Character,Integer> change(String str,int lens){
        HashMap<Character,Integer> ret=new HashMap<Character,Integer>();
        char cha[]=str.toCharArray();
        for(char tmp:cha){
            if(ret.containsKey(tmp))
            {
                int i=ret.get(tmp);
                ret.replace(tmp,++i);
            }
            else
                ret.put(tmp,1);
        }
        return ret;
    }

}