class RandomizedSet {
public:
    unordered_map<int, int> um;  // val - > idx
    unordered_map<int, int> um2; // idx -> val
    int idx = 0;
    RandomizedSet() { srand(time(nullptr)); }

    bool insert(int val) {
        if (um.find(val) != um.end())
            return false;
        um[val] = idx;
        um2[idx] = val;
        idx++;
        return true;
    }

    bool remove(int val) {
        auto it = um.find(val);
        if (it == um.end())
            return false;

         int removeIdx = it->second;
        int lastIdx = idx - 1;
        int lastVal = um2[lastIdx];

        um2[removeIdx] = lastVal;
        um[lastVal] = removeIdx;

        um2.erase(lastIdx);
        um.erase(it);
        --idx;

        return true;
    }

    int getRandom() {
        int x = rand() % (idx);
        return um2[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */