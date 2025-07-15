#include <iostream>
#include <string>
#include "threadTree.h"
using namespace std;

string trees = "ABDH##EJ###CF##G##";

template <class T>
threadTree<T>::threadTree()
{
    root = nullptr;
    prev = nullptr;
    head = nullptr;
}

template <class T>
void threadTree<T>::destroy(threadNode* node) {
    if (node != nullptr) {
        if (node->ltag == 0) destroy(node->lchild);
        if (node->rtag == 0) destroy(node->rchild);
        delete node;
    }
}

template <class T>
threadTree<T>::~threadTree()
{
    destroy(root);
    root = nullptr;
}

template <class T>
void threadTree<T>::create(threadNode*& node) {
    if (index >= trees.length()) {
        return;
    }

    char ch = trees[index++];
    if (ch == '#') {
        node = nullptr;
    }
    else {
        node = new threadNode;
        node->data = ch;

        create(node->lchild);
        node->ltag = (node->lchild != nullptr) ? 0 : 1;

        create(node->rchild);
        node->rtag = (node->rchild != nullptr) ? 0 : 1;
    }
}

template <class T>
void threadTree<T>::createBystr() {
    index = 0;
    create(root);
}

template <class T>
void threadTree<T>::threading(threadNode* node) {
    if (node == nullptr) return;

    if (node != nullptr) {
        threading(node->lchild);
        if (node->lchild == nullptr) { 
            node->ltag = 1;
            node->lchild = prev;
        }

        if (prev != nullptr && prev->rchild == nullptr) {
            prev->rtag = 1;
            prev->rchild = node;
        }

        prev = node;
        threading(node->rchild);
    }
}

template <class T>
void threadTree<T>::inOrderThreading() {
    head = new threadNode;
    head->ltag = 0;
    head->rtag = 1;
    head->rchild = head;

    prev = head;

    if (root == nullptr) {
        head->lchild = head;
    }
    else {
        head->lchild = root;
        threading(root);     // 线索化

        // 处理最后一个节点
        prev->rtag = 1;      // 最后一个节点的右线索指向头结点
        prev->rchild = head; // 形成循环
        head->rchild = prev; // 头结点的右线索指向最后一个节点（可选）
    }
}

template <class T>
void threadTree<T>::inOrderTraverse() {
    threadNode* p = head->lchild;

    // 1. 找到中序第一个节点（最左节点）
    while (p != head && p->ltag == 0) {
        p = p->lchild;
    }

    // 2. 沿线索遍历
    while (p != head) {
        cout << p->data << " ";

        // 如果右指针是线索，直接跳转
        if (p->rtag == 1) {
            p = p->rchild;
        }
        // 否则转入右子树的最左节点
        else {
            p = p->rchild;
            while (p != head && p->ltag == 0) {
                p = p->lchild;
            }
        }
    }

}

int main() {
    system("chcp 65001");
    threadTree<char> t;
    t.createBystr();
    t.inOrderThreading();
    t.inOrderTraverse();

    system("pause");
    return 0;
}