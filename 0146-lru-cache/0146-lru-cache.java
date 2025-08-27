class LRUCache {
    Queue<Integer> q = new LinkedList<>();
    Map<Integer, Integer> m = new HashMap<>();
    int capacity = 0;

    public LRUCache(int capacity) {
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if (m.containsKey(key)){
            q.remove(key);
            q.add(key);
            return m.get(key);
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if (m.containsKey(key)){
            m.put(key, value);
            q.remove(key);
            q.add(key);
            return;
        }
        q.add(key);
        if (capacity < q.size()){
            int cur = q.poll();
            m.remove(cur);
        }
        m.put(key, value);    
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */