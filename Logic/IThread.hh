#ifndef ITHREAD_H_
# define ITHREAD_H_

class IThread
{
public:
	virtual void sync() = 0;
	virtual void launch() = 0;
	virtual void play() = 0;
	virtual void quit() = 0;
	virtual ~IThread() {}
};

#endif /* !ITHREAD_H_ */
