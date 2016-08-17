#include "KillTools.h"
#include "InstallKillRule.h"

KillTool* KillTool::m_pInstance = NULL;

KillTool::KillTool(int adp)
{
	cout << "KillTool ready" << endl;
	cout << "create adapter type : " << adp << endl;
	CreateAdp(adp);
}

KillTool::~KillTool()
{
	cout << "KillTool end" << endl;
}


KillTool& KillTool::GetInstance(int adp)
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new KillTool(adp);
	}

	return *m_pInstance;
}


KillTool* KillTool::GetInstancePtr(int adp)
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new KillTool(adp);
	}

	return m_pInstance;
}


void KillTool::CreateAdp(int adpType)
{
	if (ROBERT_TYPE == adpType)
	{
		m_AdpType = (KillAdp*)new killAdpRobert();
		InstallRobertRule();
	}
	else if (HUMAN_TYPE == adpType)
	{
		m_AdpType = (KillAdp*)new KillAdpHuman();
		InstallHumanRule();
	}
	else if (MACHINE_TYPE == adpType)
	{
		m_AdpType = (KillAdp*)new KillAdpMachine();
		InstallMachineRule();
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
void KillTool::InstallRobertRule()
{
	int per1 = 1;
	int per2 = 2;
	WHOINTALLEDKILLRULE(per1)	
		.SetAnswerRule((AnswerKillRule*)new RopeAnswerRule())
		.SetCleanRule((CleanKillRule*)new KnifeCleanRule())
		.SetDoRule((DoKillRule*)new GunDoRule())
		.SetPreRule((PreKillRule*)new GunPreRule());

	WHOINTALLEDKILLRULE(per2)
		.SetAnswerRule((AnswerKillRule*)new RopeAnswerRule())
		.SetCleanRule((CleanKillRule*)new KnifeCleanRule())
		.SetDoRule((DoKillRule*)new KnifeDoRule())
		.SetPreRule((PreKillRule*)new RopePreRule());
}

void KillTool::InstallHumanRule()
{
	int per1 = 1;
	WHOINTALLEDKILLRULE(per1)	
		.SetAnswerRule((AnswerKillRule*)new RopeAnswerRule())
		.SetCleanRule((CleanKillRule*)new KnifeCleanRule())
		.SetDoRule((DoKillRule*)new GunDoRule())
		.SetPreRule((PreKillRule*)new GunPreRule());
}

void KillTool::InstallMachineRule()
{
	int per2 = 2;
	WHOINTALLEDKILLRULE(per2)	
		.SetAnswerRule((AnswerKillRule*)new RopeAnswerRule())
		.SetCleanRule((CleanKillRule*)new KnifeCleanRule())
		.SetDoRule((DoKillRule*)new GunDoRule())
		.SetPreRule((PreKillRule*)new GunPreRule());
	int per1 = 1;
	WHOINTALLEDKILLRULE(per1)	
		.SetAnswerRule((AnswerKillRule*)new RopeAnswerRule())
		.SetCleanRule((CleanKillRule*)new KnifeCleanRule())
		.SetDoRule((DoKillRule*)new GunDoRule())
		.SetPreRule((PreKillRule*)new GunPreRule());
}
