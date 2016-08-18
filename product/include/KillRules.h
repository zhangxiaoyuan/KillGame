#ifndef __KILL_RULE_H
#define __KILL_RULE_H

#include "KillOrder.h"
#include "Common.h"

#if DESC("pre rules")
class PreKillRule
{
public:
	virtual int PreAction(KillOrder& order, int id){return 0;}
};

class GunPreRule : PreKillRule
{
public:
	GunPreRule(){cout << "gun pre rule" << endl;}
	int PreAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use gun pre kill person[" << id << "]" <<endl;
		return 0;
	}
};
class KnifePreRule : PreKillRule
{
public:
	KnifePreRule(){cout << "knife pre rule" << endl;}
	int PreAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use knife pre kill person[" << id << "]" <<endl;
		return 0;
	}
};
class RopePreRule : PreKillRule
{
public:
	RopePreRule(){cout << "rope pre rule" << endl;}
	int PreAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use rope pre kill person[" << id << "]" <<endl;
		return 0;
	}
};
#endif

#if DESC("do rules")
class DoKillRule
{
public:
	
	virtual int DoAction(KillOrder& order, int id){return 0;}
};

class GunDoRule : DoKillRule
{
public:
	GunDoRule(){cout << "gun do rule" << endl;}
	int DoAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use gun do kill person[" << id << "]" <<endl;
		return 0;
	}
};
class KnifeDoRule : DoKillRule
{
public:
	KnifeDoRule(){cout << "knife do rule" << endl;}
	int DoAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use knife do kill person[" << id << "]" <<endl;
		return 0;
	}
};
class RopeDoRule : DoKillRule
{
public:
	RopeDoRule(){cout << "rope do rule" << endl;}
	int DoAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use rope do kill person[" << id << "]" <<endl;
		return 0;;
	}
};

#endif

#if DESC("clean rules")
class CleanKillRule
{
public:
	CleanKillRule(){}
	virtual int CleanAction(KillOrder& order, int id){return 0;}
};

class GunCleanRule : CleanKillRule
{
public:
	GunCleanRule(){cout << "gun clean rule" << endl;}
	int CleanAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use gun clean kill person[" << id << "]" <<endl;
		return 0;
	}
};
class KnifeCleanRule : CleanKillRule
{
public:
	KnifeCleanRule(){cout << "knife clean rule" << endl;}
	int CleanAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use knife clean kill person[" << id << "]" <<endl;
		return 0;
	}
};
class RopeCleanRule : CleanKillRule
{
public:
	RopeCleanRule(){cout << "rope clean rule" << endl;}
	int CleanAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use rope clean kill person[" << id << "]" <<endl;
		return 0;
	}
};

#endif

#if DESC("answer rules")
class AnswerKillRule
{
public:
	virtual int AnswerAction(KillOrder& order, int id){return 0;};
};

class GunAnswerRule : AnswerKillRule
{
public:
	GunAnswerRule(){cout << "gun answer rule" << endl;}
	int AnswerAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use gun answer kill person[" << id << "]" <<endl;
		return 0;
	}
};
class KnifeAnswerRule : AnswerKillRule
{
public:
	KnifeAnswerRule(){cout << "knife answer rule" << endl;}
	int AnswerAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use knife answer kill person[" << id << "]" <<endl;
		return 0;
	}
};
class RopeAnswerRule : AnswerKillRule
{
public:
	RopeAnswerRule(){cout << "rope answer rule" << endl;}
	int AnswerAction(KillOrder& order, int id)
	{
		cout << order.GetOrder() << " use rope answer kill person[" << id << "]" <<endl;
		return 0;
	}
};

#endif


class KillRule
{
public:
	KillRule();
	~KillRule();

	int Pre(KillOrder& data, int id);
	int Do(KillOrder& data, int id);
	int Clean(KillOrder& data, int id);
	int Answer(KillOrder& data, int id);

	KillRule& SetPreRule(PreKillRule* pre);
	KillRule& SetDoRule(DoKillRule* doRule);
	KillRule& SetCleanRule(CleanKillRule* clean);
	KillRule& SetAnswerRule(AnswerKillRule* answe);

private:
	PreKillRule* m_preRule;
	DoKillRule*  m_doRule;
	CleanKillRule* m_cleanRule;
	AnswerKillRule* m_answerRule;
};
#endif
