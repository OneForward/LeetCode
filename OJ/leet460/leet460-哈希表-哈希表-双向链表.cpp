/*
leet460


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;


// 缓存的节点信息
struct Node {
    int key, val, freq;
};

class LFUCache {
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        list<Node>::iterator node = it -> second;
        int val = node -> val, freq = node -> freq;
        freq_table[freq].erase(node);
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 缓存已满，需要进行删除操作
            if (key_table.size() == capacity) {
                // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            } 
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // 与 get 操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it -> second;
            int freq = node -> freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};
 
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const *argv[])
{
    // LFUCache lFUCache = LFUCache(2);
    // lFUCache.put(1, 1);   // cache=[1,_], cnt(1)=1
    // lFUCache.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    // cout << endl << lFUCache.get(1);      // 返回 1
    //                     // cache=[1,2], cnt(2)=1, cnt(1)=2
    // lFUCache.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
    //                     // cache=[3,1], cnt(3)=1, cnt(1)=2
    // cout << endl << lFUCache.get(2);      // 返回 -1（未找到）
    // cout << endl << lFUCache.get(3);      // 返回 3
    //                     // cache=[3,1], cnt(3)=2, cnt(1)=2
    // lFUCache.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
    //                     // cache=[4,3], cnt(4)=1, cnt(3)=2
    // cout << endl << lFUCache.get(1);      // 返回 -1（未找到）
    // cout << endl << lFUCache.get(3);      // 返回 3
    //                     // cache=[3,4], cnt(4)=1, cnt(3)=3
    // cout << endl << lFUCache.get(4);      // 返回 4
    //                     // cache=[3,4], cnt(4)=2, cnt(3)=3
    
    LFUCache lFUCache = LFUCache(3);
    lFUCache.put(1, 1);   
    lFUCache.put(2, 2);   
    lFUCache.put(3, 3);   
    lFUCache.put(4, 4);   
    cout << endl << lFUCache.get(4);      // 返回 3
    cout << endl << lFUCache.get(3);      // 返回 3
    cout << endl << lFUCache.get(2);      // 返回 -1（未找到）
    cout << endl << lFUCache.get(1);      // 返回 -1（未找到）
                        // cache=[3,4], cnt(4)=1, cnt(3)=3
                        // cache=[3,4], cnt(4)=2, cnt(3)=3
    
    
    // LFUCache lFUCache = LFUCache(2);
    // lFUCache.put(3,1);
    // lFUCache.put(2,1);
    // lFUCache.put(2,2);
    // lFUCache.put(4,3);
    // cout << endl << lFUCache.get(2) << endl;
    return 0;
}
