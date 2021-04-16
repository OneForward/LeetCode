/*
约瑟夫环问题
*/
#include <iostream>
using namespace std;
struct node
{
    int nodeValue;
    node* next;
    node(int item):nodeValue(item),next(NULL){}
};

int main()
{
    int numOfMonkey, Kn;
    cin >> numOfMonkey;
    node* head = new node(1), *curr = head, *tmp;
    for (int i = 2; i <= numOfMonkey; i++)
    {
        curr->next = new node(i);
        curr = curr->next;
    }
    curr->next = head;

    // curr 永远指向被删结点的前一个
    while(numOfMonkey-1)
    {
        cin >> Kn;
        Kn = Kn % numOfMonkey;
        if (Kn == 0) Kn = numOfMonkey;
        while (--Kn)
            curr = curr->next;

        tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
        numOfMonkey--;
    }
    cout << curr->nodeValue;
    return 0;
}
