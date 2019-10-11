#pragma once
//file: 3mylist-iter.h
#include "3mylist.h"

template <class Item>	//Item可以是单向链表节点或双向链表节点
struct ListIter {
	Item* ptr;		//保持与容器之间的一个联系(keep a reference to container)

	ListIter(Item* p = 0)	//default ctor
		: ptr(p){
	}

	//不必实现copy ctor，因为编译器提供的缺省行为已足够
	//不必实现operator=，因为编译器提供的缺省行为已足够

	Item& operator*() const { return *ptr; }
	Item* operator->() const { return ptr; }

	//以下两个operator++遵循标准做法
	//（1）pre-increment operator
	ListIter& operator++() {
		ptr = ptr->next();
		return *this;
	}

	//（2）post-increment operator
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