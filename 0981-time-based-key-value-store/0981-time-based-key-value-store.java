class TimeMap {
    HashMap<String, TreeMap<Integer, String>> hashMap;
        
    public TimeMap() {
        hashMap = new HashMap<>(); 
    }
    
    public void set(String key, String value, int timestamp) {
        var entry = hashMap.get(key);
        if(entry==null){
            entry = new TreeMap<Integer, String>();
        }
        entry.put(timestamp, value);
        hashMap.put(key, entry);
    }
    
    public String get(String key, int timestamp) {
        var entry = hashMap.get(key);
        if(entry==null)
            return "";
        
        var K = entry.lowerEntry(timestamp+1);
        if(K==null)
            return "";
        else
            return K.getValue();
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */