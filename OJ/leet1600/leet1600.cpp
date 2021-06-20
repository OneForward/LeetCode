/*
leet1600


*/

#include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define ALL(A) A.begin(),A.end()
using VI=vector<int>;
using VVI=vector<VI>;


struct TNode
{
    string val; bool isdeleted{};
    TNode* sibling{},  *son{}, *lastson{};
};

class ThroneInheritance {
public:
    TNode* t;
    unordered_map<string, TNode*> M;
    
    ThroneInheritance(string kingName) {
        M[kingName] = t = new TNode{kingName};
    }
    
    void birth(string parentName, string childName) {
        auto p = M[parentName];
        auto last = new TNode{childName}; M[childName] = last;
        if (not p->son) p->son = p->lastson = last;
        else p->lastson = p->lastson->sibling = last;
    }
    
    void death(string name) {
        // M.erase(name);
        M[name]->isdeleted = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> v;
        
        function<void(TNode*)> preorder = [&](TNode* root) {
            if (not root) return;
            if (not M[root->val]->isdeleted) v.push_back(root->val);
            if (root->son) preorder(root->son);
            if (root->sibling) preorder(root->sibling);
        };

        preorder(t);
        return v;
    }
};




int main(int argc, char const *argv[])
{
    ThroneInheritance t =  ThroneInheritance("king"); // 继承顺序：king
    t.birth("king", "andy"); // 继承顺序：king > andy
    t.birth("king", "bob"); // 继承顺序：king > andy > bob
    t.birth("king", "catherine"); // 继承顺序：king > andy > bob > catherine
    t.birth("andy", "matthew"); // 继承顺序：king > andy > matthew > bob > catherine
    t.birth("bob", "alex"); // 继承顺序：king > andy > matthew > bob > alex > catherine
    t.birth("bob", "asha"); // 继承顺序：king > andy > matthew > bob > alex > asha > catherine
    cout << endl << t.getInheritanceOrder(); // 返回 ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
    t.death("bob"); // 继承顺序：king > andy > matthew > bob（已经去世）> alex > asha > catherine
    cout << endl << t.getInheritanceOrder(); // 返回 ["king", "andy", "matthew", "alex", "asha", "catherine"]
    return 0;
}
