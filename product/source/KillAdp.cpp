#include "KillAdp.h"


RobertLan::RobertLan()
{
	m_name = "robert";
};

string RobertLan::GetLanName()
{
	return m_name;
}

HumanLan::HumanLan()
{
	m_name = "human";
};

string HumanLan::GetLanName()
{
	return m_name;
}

MachineLan::MachineLan()
{
	m_name = "machine";
}
string MachineLan::GetLanName()
{
	return m_name;
}


killAdpRobert::killAdpRobert()
{
	cout << "adapter to robert" << endl;
}

killAdpRobert::~killAdpRobert()
{
	if (m_lan!=NULL) 
		FREE_PTR(m_lan)
};

Language* killAdpRobert::GetLanguage()
{
	m_lan = (Language*)new RobertLan();
	return m_lan;
};

KillAdpHuman::KillAdpHuman()
{
	cout << "adapter to human" << endl;
}

KillAdpHuman::~KillAdpHuman()
{
	if (m_lan!=NULL) 
		FREE_PTR(m_lan)
}

Language* KillAdpHuman::GetLanguage()
{
	m_lan = (Language*)new HumanLan();
	return m_lan;
}

KillAdpMachine::KillAdpMachine()
{
	cout << "adapter to machine" << endl;
}

KillAdpMachine::~KillAdpMachine()
{
	if (m_lan!=NULL) 
		FREE_PTR(m_lan)
}

Language* KillAdpMachine::GetLanguage()
{
	m_lan = (Language*)new MachineLan();
	return m_lan;
};
