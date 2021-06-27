/*
leet460


*/


#include "../utils/LeetCpp.utils.hpp"
using namespace std;


struct Node
{
    int key, val, cnt, time;

    bool operator<(const Node& rhs) const {
        // 时间戳最小的（最老的）放列表最后
        return cnt < rhs.cnt or (cnt == rhs.cnt and time < rhs.time);
    }
};


class LFUCache {
public:
    // 哈希表 套 双端链表
    // 36ms, 98%, O(1)

    unordered_map<int, Node> M;
    set<Node> tree;
    int N; int time;

    LFUCache(int capacity):  N{capacity}, time{}  { }
    
    int get(int key) {
        if (M.find(key) == M.end()) return -1;
        auto&& node = M[key];
        tree.erase(node);
        node.cnt++; node.time = time++;
        tree.insert(node);
        return node.val;
    }
    
    void put(int key, int val) {
        if (N == 0) return;

        if (M.find(key) == M.end()) {
            // remove the minimum
            if (tree.size() == N) {
                auto node = *tree.begin();
                M.erase(node.key);
                tree.erase(tree.begin());
            }
            auto node = Node{key, val, 1, time++};
            tree.insert(node);
            M[key] = node;
            return;
        }
        
        // inc counter of key, move it forward
        auto&& node = M[key];
        tree.erase(node);
        node.cnt++; node.time = time++; node.val = val;
        tree.insert(node);
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
    
    // LFUCache lFUCache = LFUCache(3);
    // lFUCache.put(1, 1);   
    // lFUCache.put(2, 2);   
    // lFUCache.put(3, 3);   
    // lFUCache.put(4, 4);   
    // cout << endl << lFUCache.get(4);      // 返回 3
    // cout << endl << lFUCache.get(3);      // 返回 3
    // cout << endl << lFUCache.get(2);      // 返回 -1（未找到）
    // cout << endl << lFUCache.get(1);      // 返回 -1（未找到）
    
    
    
    LFUCache lFUCache = LFUCache(2);
    lFUCache.put(3,1);
    lFUCache.put(2,1);
    lFUCache.put(2,2);
    lFUCache.put(4,3);
    cout << endl << lFUCache.get(2) << endl;
    return 0;
}
