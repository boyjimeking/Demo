//
//  CameraObserver.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#ifndef Demo_CameraObserver_h
#define Demo_CameraObserver_h

#include "Base/IObserver.h"
#include "base_nodes/CCNode.h"

namespace cocos2d
{
    class CCScene;
}

namespace Game
{
    class CameraObserver
        :public IObserver
        ,public cocos2d::CCNode
    {
    public:
        static CameraObserver* Create(void);
        CameraObserver(void);
        void Init(void);
        virtual ~CameraObserver(void);
        virtual void OnNotifyChange(INotifier *notify, const INotifyEvent *event);

		virtual void addChild(CCNode *child, float moveScale);

		virtual void removeChild(CCNode* child, bool cleanup);
		virtual void removeAllChildrenWithCleanup(bool cleanup);

		//
		//virtual void addChild(CCNode * child, int zOrder, int tag);
	private:
		typedef std::map<CCNode*, float> MoveScale;
		MoveScale m_moveScale;
		cocos2d::CCPoint m_lastPos;
    };
}

#endif
