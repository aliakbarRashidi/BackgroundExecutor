

#ifndef CBACKGROUNDEXECUTOR_H
#define CBACKGROUNDEXECUTOR_H

#include <QtCore/qmetatype.h>
#include <QtCore/qnamespace.h>
#include <QtCore/qobjectdefs.h>
#include <QtCore/qthread.h>
#include <functional>

typedef std::function<void(void)> Closure;

template<typename T, typename N1>
Closure toClosure(T func, N1 arg) {
   return std::bind(func, arg);
}

template<typename T, typename N1, typename N2>
Closure toClosure(T func, N1 arg, N2 arg2) {
   return std::bind(func, arg, arg2);
}

Q_DECLARE_METATYPE(Closure);
class ClosureRegisterer {
public:
	ClosureRegisterer(){qRegisterMetaType<Closure>();};
};

class CBackroundExecutor : public QThread {
Q_OBJECT;
public:
    static CBackroundExecutor* createOne();
public Q_SLOTS:
	void executeTaskInBackground(Closure task){QMetaObject::invokeMethod(this, "executeTask", Qt::QueuedConnection, Q_ARG(Closure, task));};
private Q_SLOTS:
	void executeTask(Closure task){task();};
protected:
    CBackroundExecutor(){};
};

#endif
