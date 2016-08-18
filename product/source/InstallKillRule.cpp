
#include "InstallKillRule.h"

InstallKillRule* InstallKillRule::m_instance = NULL;

InstallKillRule::InstallKillRule()
{
	cout << "install kill rule " << endl;
}

InstallKillRule::~InstallKillRule()
{
	KILL_RULE_MAP::iterator ite = m_PersonRulesMap.begin();
	while (ite != m_PersonRulesMap.end())
	{
		PERSON_DEL_RULES(ite->second);
	}

	m_PersonRulesMap.clear();
};

InstallKillRule& InstallKillRule::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new InstallKillRule();
	}

	return *m_instance;
}

InstallKillRule* InstallKillRule::GetInstancePtr()
{
	if (m_instance == NULL)
	{
		m_instance = new InstallKillRule();

		return m_instance;
	}

	return m_instance;
}


KillRule& InstallKillRule::InstallRule(int personID)
{
	cout << "install person[" << personID << "]" << endl;
	KILL_RULE_MAP::iterator ite = m_PersonRulesMap.find(personID);

	if (ite != m_PersonRulesMap.end())
	{
		PERSON_DEL_RULES((*ite).second);
	}

	m_PersonRulesMap[personID] = new KillRule;

	return *m_PersonRulesMap[personID];
}

KillRule* InstallKillRule::GetSomeoneRules(int personID)
{
	KILL_RULE_MAP::iterator ite = m_PersonRulesMap.find(personID);
	if (ite != m_PersonRulesMap.end())
	{
		return ite->second;
	}

	cout << "this person has no kill ruls" << endl;
	return NULL;
}



