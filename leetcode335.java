package just;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Twitter {
	class Feed{
		int userId,tweetId;
		public Feed(int userId,int tweetId){
			this.userId=userId;
			this.tweetId=tweetId;
		}
		public String toString(){
			return tweetId+"";
		}
	}
	HashMap<Integer,Set<Integer>> maps;
    List<Feed> feed;
	/** Initialize your data structure here. */
    public Twitter() {
    	maps=new HashMap<Integer,Set<Integer>>();
        feed=new ArrayList<Feed>();
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        Feed f=new Feed(userId,tweetId);
        feed.add(f);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> ret=new ArrayList<Integer>();
        Set<Integer> users=maps.get(userId);
        if(users==null)
        	users=new HashSet<Integer>();
        users.add(userId);
        for(int i=feed.size()-1;i>=0;i--)
        {
        	Feed f=feed.get(i);
        	if(ret.size()<10&&users.contains(f.userId))
        		ret.add(f.tweetId);
        	if(ret.size()>=10)
        		break;
        }
        
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        Set<Integer> sets;
        if(maps.containsKey(followerId)){
        	sets=maps.get(followerId);
        }
        else{
        	sets=new HashSet<Integer>();
        }
        sets.add(followeeId);
        maps.put(followerId,sets);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        Set<Integer> sets=maps.get(followerId);
        if(sets!=null&&sets.contains(followeeId))
        {
        	sets.remove(followeeId);
        	maps.put(followerId, sets);
        }
    }
}
