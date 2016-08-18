#include "InstallKillRule.h"
#include "KillAdp.h"
#include "KillOrder.h"
#include "KillTools.h"

KillOrder::KillOrder(string msg)
{
	int adpTtype = ParseMsg(msg);

	//获取适配指针
	m_killAdp = KillTool::GetInstancePtr(adpTtype)->GetAdpPtr();

	/*将暗杀指令转换为对应的机器或者人的语言*/
	m_language = m_killAdp->GetLanguage();
	string name = m_language->GetLanName();

	cout << "who: " << name << endl;
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

int KillOrder::PreGun(int id)
{
	cout << "person[" << id << "]"  "gun pre action" << endl; 
	return 0;
}
int KillOrder::DoGun(int id)
{
	cout << "person[" << id << "]" << "gun do action" << endl;
	return 0;
}
int KillOrder::CleanGun(int id)
{
	cout << "person[" << id << "]"  "gun clean action" << endl;
	return 0;
}
int KillOrder::AnswerGun(int id)
{
	cout << "person[" << id << "]"  "gun answer action" << endl;
	return 0;
}

int KillOrder::PreKnife(int id)
{
	cout << "person[" << id << "]"  "knife pre action" << endl;
	return 0;
}
int KillOrder::DoKnife(int id)
{
	cout << "person[" << id << "]"  "knife do action" << endl;
	return 0;
}
int KillOrder::CleanKnife(int id)
{
	cout << "person[" << id << "]"  "knife clean action" << endl;
	return 0;
}
int KillOrder::AnswerKnife(int id)
{
	cout << "person[" << id << "]"  "knife answer action" << endl;
	return 0;
}

int KillOrder::PreRope(int id)
{
	cout << "person[" << id << "]"  "rope pre action" << endl;
	return 0;
}
int KillOrder::DoRope(int id)
{
	cout << "person[" << id << "]"  "rope do action" << endl;
	return 0;
}
int KillOrder::CleanRope(int id)
{
	cout << "person[" << id << "]"  "rope clean action" << endl;
	return 0;
}
int KillOrder::AnswerRope(int id)
{
	cout << "person[" << id << "]" <<"rope answer action" << endl;
	return 0;
}
