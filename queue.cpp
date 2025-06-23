# include <iostream>
# include "queue.h"
using namespace std;

template <class T>
Queue<T>::Queue()
{
    front = 0;
    rear = 0;
}

template <class T>
Queue<T>::~Queue() {

}

template <class T>
bool Queue<T>::isEmpty() {
    if (front == rear) {
        cout << "Queue is empty" << endl;
        return true;
    }

    cout << "Queue is not empty" << endl;
    return false;
}

template <class T>
void Queue<T>::deQueue() {
    if (front == rear) {
        cout << "Queue is empty, cannot deque" << endl;
        return;
    }

    T deletes = queue[front];
    front++;
}

template <class T>
bool Queue<T>::isFull() {
    if (front > 0) {
        int step = front;
        for (int i = front; i < rear; i++) {
            data[i - step] = data[i];
        }
        front = 0;
        rear -= step;
        return false;
    }
    else {
        return true;
    }
}

template <class T>
void Queue<T>::enQueue(T data) {
    if (rear >= MAX_SIZE) {
        if (!isfull()) {
            cout << "Queue is full, cannot enqueue" << endl;
            return;
        }
    }

    queue[rear] = data;
    rear++;
}

template <class T>
T Queue<T>::getFront() {
    if (rear == front) {
        cout << "Queue is empty" << endl;
        return -1;
    }

    else {
        return queue[front];
    }
}

