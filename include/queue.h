#ifndef __QUEUE__
#define __QUEUE__

template <class T>
class Queue{
	T* data = nullptr;
	int   front  = 0;
	int   back   = 0;
	int   count  = 0;
	int capacity = 1;

public:
	Queue(int size = 1) {
		if (size < 0)
			throw "size should not be negative";

		data  = new T[size];
		capacity = size;
	}

	Queue(const Queue& q) {
		this->front    =  q.front;
		this->back     =  q.back;
		this->capacity =  q.capacity;
		this->count    =  q.count;

		this->data = new T[capacity];
		for (int i = front, j = 0; j < count; i += (i + 1) % capacity, j++)
			data[i] = q.data[i];
	}

	Queue& operator=(const Queue& q) {
		if (this == &q) return *this;
		delete[] data;

		this->front    =  q.front;
		this->back     =  q.back;
		this->capacity =  q.capacity;
		this->count    =  q.count;
		
		this->data = new T[capacity];
		for (int i = front, j = 0; j < count; i += (i + 1) % capacity, j++)
			data[i] = q.data[i];

		return *this;
	}

	~Queue() {
		delete[] data;
	}

	T top() {
		if (count == 0)
			throw "Queue is empty";

		return data[front];
	}

	void pop() {
		if (count == 0)
			throw "Queue is empty";
		front = (front + 1) % capacity;
		count -= 1;
	}

	void push(T value) {
		if (count == capacity)
			repacking();
		data[back] = value;
		back = (back + 1) % capacity;
		count++;
	}

	bool empty() {
		return (count == 0);
	}

	int size() {
		return count;
	}

	void repacking() {
		T* tmp = new T[capacity * 2];
		for (int i = front, j = 0; j < count; i = (i + 1) % capacity, j++) {
			tmp[j] = data[i];
		}
		delete[] data;
		data  = tmp;
		front = 0;
		back  = count;
		capacity *= 2;
	}
};

#endif
