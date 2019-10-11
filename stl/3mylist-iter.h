#pragma once
//file: 3mylist-iter.h
#include "3mylist.h"

template <class Item>	//Item�����ǵ�������ڵ��˫������ڵ�
struct ListIter {
	Item* ptr;		//����������֮���һ����ϵ(keep a reference to container)

	ListIter(Item* p = 0)	//default ctor
		: ptr(p){
	}

	//����ʵ��copy ctor����Ϊ�������ṩ��ȱʡ��Ϊ���㹻
	//����ʵ��operator=����Ϊ�������ṩ��ȱʡ��Ϊ���㹻

	Item& operator*() const { return *ptr; }
	Item* operator->() const { return ptr; }

	//��������operator++��ѭ��׼����
	//��1��pre-increment operator
	ListIter& operator++() {
		ptr = ptr->next();
		return *this;
	}

	//��2��post-increment operator
	ListIter operator++(int) {
		ListIter tmp = *this;
		++*this;
		return tmp;
	}

	bool operator ==(const ListIter& i) const {
		return ptr == i.ptr;
	}

	bool operator!=(const ListIter& i)const {
		return ptr != i.ptr;
	}
};