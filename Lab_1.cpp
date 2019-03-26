
#include<cstdlib>
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
Node *INSERT(Node *heder, Node *current) {
    if (current == heder)
    {
        return current->next;
    }
    else
    {
        Node *p = heder;
        Node *prev = current;
        Node *pp;
        while (p != current)
        {
            pp = prev->next;
            prev->next = new Node;
            prev = prev->next;
            prev->data = p->data;
            prev->next = pp;
            p = p->next;
        }
        return prev->next;
    }
}

int main()
{
    int n;
    cin >> n;
    Node *head, *last;
    head = new Node;
    //вот здесь мы создали первый элемент списка
    //и должны заполнить поле data
    head->data = 1;
    last = head;//говорим, что первый элемент является и последним
    //он сейчас единственный
    int k = 2;//так как первый элемент списка уже =1, то следующий =2
    //в цикле создаем и заполняем элементы списка
    while (n-1 > 0) {
        last->next = new Node;
        last = last->next;
        last->data = k;
        last->next = NULL;
        k++;
        n--;
    }
    for (Node *current = head; current != last;) {
        //здесь сначала выводим элемент, а затем переходим
        //к следующему. Иначе вывод начнется со второго элемента
        cout << current->data << endl;
        current = current->next;
    }
    for (Node *uk = head; uk != NULL;) {
        uk = INSERT(head, uk);
    }
    for (Node *uk = head; uk != NULL;) {
        cout << uk->data << " ";
        uk = uk->next;
    }
    cout << endl;
    system ("pause");
    return 0;
}
