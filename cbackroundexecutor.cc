
#include <cbackroundexecutor.h>

CBackroundExecutor* CBackroundExecutor::createOne(){
	CBackroundExecutor *ret = new CBackroundExecutor();
	static ClosureRegisterer __R;
	ret->moveToThread(ret);
	ret->start();

	return ret;
}
