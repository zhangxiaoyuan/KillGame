#ifndef __KILL_ADP_H
#define __KILL_ADP_H

#include "Common.h"

#if DESC("类：language | RobertLan | HumanLan | MachineLan")
class Language
{
public:
	virtual string GetLanName() = 0;
private:
};

class RobertLan : Language
{
public:
	RobertLan();
	string GetLanName();
private:
	string m_name;
};

class HumanLan : Language
{
public:
	HumanLan();
	string GetLanName();
private:
	string m_name;
};

class MachineLan : Language
{
public:
	MachineLan();
	string GetLanName();
private:
	string m_name;
};
#endif

#if DESC("类：KillAdp | killAdpRobert | KillAdpHuman | KillAdpMachine")
class KillAdp
{
public:
	KillAdp(){cout << "this is kill adapter." << endl;}
	virtual Language* GetLanguage() = 0;
};

class killAdpRobert : KillAdp
{
public:
	killAdpRobert();
	~killAdpRobert();
	Language* GetLanguage();
private:
	Language* m_lan;
};

class KillAdpHuman : KillAdp
{
public:
	KillAdpHuman();
	~KillAdpHuman();
	Language* GetLanguage();
private:
	Language* m_lan;
};

class KillAdpMachine : KillAdp
{
public:
	KillAdpMachine();
	~KillAdpMachine();
	Language* GetLanguage();
private:
	Language* m_lan;
};
#endif

#endif
