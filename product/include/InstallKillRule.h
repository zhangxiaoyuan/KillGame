#ifndef __INSTALL_KILL_RULE_H
#define __INSTALL_KILL_RULE_H

#include "KillRules.h"
#include <map>

#define WHOINTALLEDKILLRULE(person) InstallKillRule::getInstance().InstallRule(person)

typedef map<int, KillRule*> KILL_RULE_MAP;

#define PERSON_DEL_RULES(p)\
{\
	if (p != NULL)\
{\
	delete p;\
	p = NULL;\
}\
}\

class InstallKillRule
{
public:
	~InstallKillRule();
	static InstallKillRule* GetInstancePtr();
	static InstallKillRule& getInstance();

	KillRule& InstallRule(int personId);
	KillRule* GetSomeoneRules(int personID);


private:
	InstallKillRule();
	static InstallKillRule* m_instance;

	KILL_RULE_MAP m_PersonRulesMap;
};



#endif
