#ifndef __KILL_ORDER_H
#define __KILL_ORDER_H

//#include "KillRules.h#include "KillLanguage.h"
//#include "KillAdp.h"
#include "Common.h"
#include <string>


class KillAdp;
class Language;
class KillRule;
class KillOrder
{
public:
	KillOrder(string msg, int personArr[]);
	~KillOrder();

	int ParseMsg(string msg);
	void kill(int perdon);
	string GetOrder();

private:
	KillRule* m_killRule;
	KillAdp*  m_killAdp;
	Language* m_language;
	string m_order;
};

#endif
