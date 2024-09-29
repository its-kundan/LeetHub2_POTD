class AllOne {
public:
    set<pair<int,string>>st;   //sorted order   pair<int,string>
	unordered_map<string,int>mp; 
    AllOne() 
    {
       st.clear();
       mp.clear();
    }
    
    void inc(string key) 
	{
        if(mp[key]==0)   //first entry of the sting
        {
            mp[key]++;
            st.insert(make_pair(mp[key],key));
		}
		else    //duplicate entry of the stirng 
		{
			int prev_freq=mp[key];
			int new_freq=prev_freq+1;
			
			auto it=st.find(make_pair(prev_freq,key));
			st.erase(it);
			
			st.insert(make_pair(new_freq,key));
			
			mp[key]++;
		}
    }
    
    void dec(string key) 
	{
        //key always exist
        int prefreq=mp[key];
        int newfreq=prefreq-1;
        if(newfreq==0)
        {
        	//only remove from the set and mp
        	mp.erase(key);
        	auto it=st.find(make_pair(prefreq,key));
        	st.erase(it);
		}
		else if(newfreq>0)
		{
			mp[key]--;
			auto it=st.find(make_pair(prefreq,key));
        	st.erase(it);
        	st.insert(make_pair(newfreq,key));
		}
    }
 
    string getMaxKey() 
	{
        if(st.size()==0)
        {
        	return "";
		}
		pair<int,string>p=*(st.rbegin());
		return p.second;
    }
    
    string getMinKey() 
	{
        if(st.size()==0)
        {
        	return "";
		}
		pair<int,string>p=*(st.begin());
		return p.second;
    }
    
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */