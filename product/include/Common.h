#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>

using namespace std;

#define DESC(P) 1

#define FREE_PTR(p) \
{\
	if (p != NULL)\
{\
	delete p;\
	p = NULL;\
}	\
}

#endif
