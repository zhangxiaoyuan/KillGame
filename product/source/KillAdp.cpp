#include "KillAdp.h"


RobertLan::RobertLan()
{
	cout << "this is robert language" << endl;
	m_name = "robert language";
};

string RobertLan::GetLanName()
{
	return m_name;
}

HumanLan::HumanLan()
{
	cout << "this is human language" << endl;
	m_name = "human language";
};

string HumanLan::GetLanName()
{
	return m_name;
}

MachineLan::MachineLan()
{
	cout << "this is machine language" << endl;
	m_name = "machine language";
}
string MachineLan::GetLanName()
{
	return m_name;
}


killAdpRobert::killAdpRobert()
{
	cout << "this is adapter to robert" << endl;
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
	cout << "this is adapter to human" << endl;
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
	cout << "this is adapter to machine" << endl;
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
