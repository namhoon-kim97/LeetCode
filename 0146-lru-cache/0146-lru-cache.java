class LRUCache {
    class Node {
        int k,v;
        Node prev, next;
        Node(int k, int v) {this.k = k; this.v = v;}
    }
    Map<Integer, Node> m = new HashMap<>();
    int capacity = 0;
    Node head = new Node(0,0);
    Node tail = new Node(0,0);

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head.next = tail; tail.prev = head;
    }
    
    public int get(int key) {
        Node n = m.get(key);
        if (n == null) return -1;
        moveToFront(n);
        return n.v;
    }
    
    public void put(int key, int value) {
        if (capacity == 0) return;
        Node n = m.get(key);
        if (n != null){
            n.v = value;
            moveToFront(n);
            return;
        }
        if (m.size() == capacity){
            Node lru = tail.prev;
            remove(lru);
            m.remove(lru.k);
        }
        Node nn = new Node(key, value);
        addFirst(nn);
        m.put(key, nn);
    }

    void moveToFront(Node n){
        remove(n);
        addFirst(n);
    }
    void remove(Node n){
        n.prev.next = n.next;
        n.next.prev = n.prev;
    }
    void addFirst(Node n){
        n.next = head.next;
        head.next.prev = n;
        n.prev = head;
        head.next = n;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */