class LRUCache {
    LinkedHashMap<Integer, Integer> lm;
    int capacity = 0;

    public LRUCache(int capacity) {
        lm = new LinkedHashMap<>(capacity, 0.75f, true);
        this.capacity = capacity;
    }
    
    public int get(int key) {
        return lm.getOrDefault(key, -1);
    }
    
    public void put(int key, int value) {
        lm.put(key, value);
        if (lm.size() > capacity){
            for (Map.Entry<Integer, Integer> m : lm.entrySet()){
                lm.remove(m.getKey());
                break;
            }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */