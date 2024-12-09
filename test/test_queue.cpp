#include "queue.h"
#include <gtest.h>

TEST(queue, CreateQueue) {
	ASSERT_NO_THROW(Queue<int> q);
}

TEST(queue, CanPushElement) {
	Queue<int> q;
	ASSERT_NO_THROW(q.push(1));
}

TEST(queue, CanTopElement) {
	Queue<int> q;
	q.push(1);
	EXPECT_EQ(1,q.top());
}

TEST(queue, ThrowWhenPopInEmptyQueue) {
	Queue<int> q;
	q.push(1);
	q.pop();
	ASSERT_ANY_THROW(q.pop());
}

TEST(queue, ThrowWhenTopInEmptyQueue) {
	Queue<int> q;
	q.push(1);
	q.pop();
	ASSERT_ANY_THROW(q.top());
}

TEST(queue, CanPushAndPopElement) {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.pop();
	q.pop();
	q.push(3);
	q.push(4);
	EXPECT_EQ(3,q.top());
}

TEST(queue, CorrectSequnceElements) {
	Queue<int> q;
	for (int i = 1; i < 10; i++)
		q.push(i);

	for (int i = 1; i < 10;i++) {
		EXPECT_EQ(i, q.top());
		q.pop();
	}
}

TEST(queue, CorrectSequnceWhenBackBeforeFrontInCycle) {
	Queue<int> q(4);
	for (int i = 1; i < 5; i++)
		q.push(i);
	q.pop();
	q.pop();
	q.push(5);
	q.push(6);
	for (int i = 3; i < 7;i++) {
		EXPECT_EQ(i, q.top());
		q.pop();
	}
}

TEST(queue, EmptyAfterPushAndPop) {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.pop();
	q.pop();
	EXPECT_EQ(true, q.empty());
}

TEST(queue, NotEmptyAfterPushAndPop) {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.pop();
	q.pop();
	EXPECT_EQ(false, q.empty());
}

TEST(queue,	SizeQueueAfterPushAndPop) {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.pop();
	q.pop();
	q.push(3);
	q.push(4);
	EXPECT_EQ(2,q.size());
}

TEST(queue,	CanCopyQueue) {
	Queue<int> q;
	Queue<int> qc;
	q.push(1);
	q.push(2);
	q.pop();
	q.pop();
	q.push(4);
	q.push(5);
	qc = q;
	EXPECT_EQ(4, qc.top());
	qc.pop();
	EXPECT_EQ(5, qc.top());
}
