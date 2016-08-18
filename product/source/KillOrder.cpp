#include "InstallKillRule.h"
#include "KillAdp.h"
#include "KillOrder.h"
#include "KillTools.h"

KillOrder::KillOrder(string msg, int personArr[])
{
	int adpTtype = ParseMsg(msg);

	//获取适配指针
	m_killAdp = KillTool::GetInstancePtr(adpTtype, personArr)->GetAdpPtr();

	/*将暗杀指令转换为对应的机器或者人的语言*/
	m_language = m_killAdp->GetLanguage();
	string name = m_language->GetLanName();

	cout << "who: " << name << endl;
	m_order = "order is " + name;
} 

KillOrder::~KillOrder()
{

}

int KillOrder::ParseMsg(string msg)
{
	if (msg.find("ROBERT") != string::npos)
	{
		return ROBERT_TYPE;
	}
	else if (msg.find("HUMAN") != string::npos)
	{
		return HUMAN_TYPE;
	}
	else if (msg.find("MACHINE") != string::npos)
	{
		return MACHINE_TYPE;
	}

	return -1;
}

void KillOrder::kill(int personId)
{
	m_killRule = InstallKillRule::getInstance().GetSomeoneRules(personId);

	m_killRule->Pre(*this, personId);
	m_killRule->Do(*this, personId);
	m_killRule->Clean(*this, personId);
	m_killRule->Answer(*this, personId);

}

string KillOrder::GetOrder()
{
	return m_order;
}
