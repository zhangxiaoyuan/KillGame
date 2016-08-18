#include "Common.h"
#include "KillTools.h"
#include "KillOrder.h"

void main()
{
	cout << " .welcome  to kill game. " << endl;

	string msg = "MACHINE|GUN";

	KillOrder order(msg);

	int per1 = 2;
	order.kill(per1);
	int per2 = 1;
	order.kill(per2);
}
