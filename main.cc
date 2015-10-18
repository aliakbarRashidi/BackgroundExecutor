
#include <cbackroundexecutor.h>
#include <QApplication>

void test(int arg) {
    printf("%d\n", arg);
}


int main(int argc, char**argv)
{
	CBackroundExecutor *c = CBackroundExecutor::createOne();

	QApplication app(argc, argv);

	c->executeTaskInBackground(toClosure(test, 4));

	app.exec();
	c->wait(5000);
	c->quit();
}
