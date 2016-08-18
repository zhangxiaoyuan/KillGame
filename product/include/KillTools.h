#ifndef _KILL_TOOLS_H_
#define _KILL_TOOLS_H_

#include "KillAdp.h"

enum ADP_TYPE
{
	ROBERT_TYPE = 1,
	HUMAN_TYPE = 2,
	MACHINE_TYPE = 3,
};

class KillTool
{
public:
	virtual ~KillTool();

	static KillTool& GetInstance(int adp, int personArr[]);
	static KillTool* GetInstancePtr(int adp, int personArr[]);

	//创建适配器
	void CreateAdp(int adp, int personArr[]);
	KillAdp* GetAdpPtr();
	//安装和卸载规则
	void InstallRobertRule(int personArr[]);
	void InstallHumanRule(int personArr[]);
	void InstallMachineRule(int personArr[]);
	void UninstallRoberRule();
	void UninstallHumanRule();
	void UninstallMachineRule();
private:
	KillTool(int adpType, int personArr[]);
	KillAdp* m_AdpType;
	static KillTool* m_pInstance;
};

#endif
