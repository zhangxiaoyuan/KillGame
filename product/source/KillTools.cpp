#include "KillTools.h"
#include "InstallKillRule.h"

KillTool* KillTool::m_pInstance = NULL;

KillTool::KillTool(int adp, int personArr[])
{
	cout << "KillTool ready" << endl;
	cout << "create adapter type : " << adp << endl;
	CreateAdp(adp, personArr);
}

KillTool::~KillTool()
{
	cout << "KillTool end" << endl;
}


KillTool& KillTool::GetInstance(int adp, int personArr[])
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new KillTool(adp, personArr);
	}

	return *m_pInstance;
}


KillTool* KillTool::GetInstancePtr(int adp, int personArr[])
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new KillTool(adp, personArr);
	}

	return m_pInstance;
}

/*根据编译工程的不同，采用同名函数就可以将adp区分开*/
void KillTool::CreateAdp(int adpType, int personArr[])
{
	if (ROBERT_TYPE == adpType)
	{
		m_AdpType = (KillAdp*)new killAdpRobert();
		InstallRobertRule(personArr);
	}
	else if (HUMAN_TYPE == adpType)
	{
		m_AdpType = (KillAdp*)new KillAdpHuman();
		InstallHumanRule(personArr);
	}
	else if (MACHINE_TYPE == adpType)
	{
		m_AdpType = (KillAdp*)new KillAdpMachine();
		InstallMachineRule(personArr);
	}
	else
	{
		cout << "adapter type error" << endl;
	}

	return ;
}

KillAdp* KillTool::GetAdpPtr()
{
	return m_AdpType;
}

/*
KillRule& KillRule::SetPreRule(PreKillRule* pre)
KillRule& SetDoRule(DoKillRule* doRule);
KillRule& SetCleanRule(CleanKillRule* clean);
KillRule& SetAnswerRule(AnswerKillRule* answe);
*/
void KillTool::InstallRobertRule(int personArr[])
{
	if (personArr == NULL)
	{
		return ;
	}
	int perCnt = sizeof(personArr) / sizeof(personArr[0]);


	WHOINTALLEDKILLRULE(personArr[0])	
		.SetAnswerRule((AnswerKillRule*)new RopeAnswerRule())
		.SetCleanRule((CleanKillRule*)new KnifeCleanRule())
		.SetDoRule((DoKillRule*)new GunDoRule())
		.SetPreRule((PreKillRule*)new GunPreRule());

	WHOINTALLEDKILLRULE(personArr[1])
		.SetAnswerRule((AnswerKillRule*)new RopeAnswerRule())
		.SetCleanRule((CleanKillRule*)new KnifeCleanRule())
		.SetDoRule((DoKillRule*)new KnifeDoRule())
		.SetPreRule((PreKillRule*)new RopePreRule());
}

void KillTool::InstallHumanRule(int personArr[])
{
	if (personArr == NULL)
	{
		return ;
	}
	int perCnt = sizeof(personArr) / sizeof(personArr[0]);

	WHOINTALLEDKILLRULE(personArr[1])	
		.SetAnswerRule((AnswerKillRule*)new RopeAnswerRule())
		.SetCleanRule((CleanKillRule*)new KnifeCleanRule())
		.SetDoRule((DoKillRule*)new GunDoRule())
		.SetPreRule((PreKillRule*)new GunPreRule());
}

void KillTool::InstallMachineRule(int personArr[])
{
	if (personArr == NULL)
	{
		return ;
	}
	int perCnt = sizeof(personArr) / sizeof(personArr[0]);

	WHOINTALLEDKILLRULE(personArr[0])	
		.SetAnswerRule((AnswerKillRule*)new RopeAnswerRule())
		.SetCleanRule((CleanKillRule*)new KnifeCleanRule())
		.SetDoRule((DoKillRule*)new GunDoRule())
		.SetPreRule((PreKillRule*)new GunPreRule());
	int per1 = 1;
	WHOINTALLEDKILLRULE(personArr[1])	
		.SetAnswerRule((AnswerKillRule*)new RopeAnswerRule())
		.SetCleanRule((CleanKillRule*)new RopeCleanRule())
		.SetDoRule((DoKillRule*)new GunDoRule())
		.SetPreRule((PreKillRule*)new KnifePreRule());
}
