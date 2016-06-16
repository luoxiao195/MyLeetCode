/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
	int index;
	List<Integer> vals;
    public NestedIterator(List<NestedInteger> nestedList) {
        vals=parser(nestedList);
    }
    public List<Integer> parser(List<NestedInteger> nestedList){
    	List<Integer> res=new ArrayList<Integer>();
    	for(NestedInteger n:nestedList){
    		if(n.isInteger())
    			res.add(n.getInteger());
    		else
    			res.addAll(parser(n.nestedList()));
    	}
    	return res;
    }

    @Override
    public Integer next() {
        if(index<vals.size()){
        	int val=vals.get(index);
        	index++;
        	return val;
        }
        else
        	return -1;
    }

    @Override
    public boolean hasNext() {
        return !(index>=vals.size());
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */