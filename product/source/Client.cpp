//#include "vld.h"
#include "Common.h"
#include "KillTools.h"
#include "KillOrder.h"


void main()
{
	cout << " .welcome  to kill game. " << endl;

	string msg = "MACHINE|GUN";
	int personArray[] = {1,2};

	KillOrder order(msg, personArray);

	order.kill(personArray[0]);
	order.kill(personArray[1]);

	cout << "...OVER..." << endl;
}
