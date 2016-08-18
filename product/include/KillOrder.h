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
	KillOrder(string msg);
	~KillOrder();

	int ParseMsg(string msg);

	int PreGun(int id);
	int DoGun(int id);
	int CleanGun(int id);
	int AnswerGun(int id);

	int PreKnife(int id);
	int DoKnife(int id);
	int CleanKnife(int id);
	int AnswerKnife(int id);

	int PreRope(int id);
	int DoRope(int id);
	int CleanRope(int id);
	int AnswerRope(int id);

	void kill(int perdon);

private:
	KillRule* m_killRule;
	KillAdp*  m_killAdp;
	Language* m_language;
};

#endif
