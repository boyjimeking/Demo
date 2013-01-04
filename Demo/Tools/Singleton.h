//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\Tools
//	created:	2013-1-4
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef Singleton_h__
#define Singleton_h__

template<typename T>
class Singleton
{
public:
	static T* getSingleton( void )
	{
		static T* _ins = new T;
		return ( _ins );
	}
protected:
	Singleton(void){}
	virtual ~Singleton(void){}
	
private:
	Singleton& operator=(const Singleton&);
	Singleton(const Singleton&);
};

#endif // Singleton_h__
