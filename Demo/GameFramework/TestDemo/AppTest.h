//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\TestDemo
//	created:	2012-12-17
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef AppTest_h__
#define AppTest_h__

#include "CCApplication.h"

class AppTest
	:private cocos2d::CCApplication
{
public:
	AppTest(void);
	virtual ~AppTest(void);

    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();
protected:
	
private:
	
};

#endif // AppTest_h__
