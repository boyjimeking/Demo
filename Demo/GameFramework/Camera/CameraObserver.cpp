//
//  CameraObserver.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#include "CameraObserver.h"
#include "CCCamera.h"
#include "CameraNotifyEvents.h"
#include "support/CCPointExtension.h"
#include "WorldManager.h"

namespace Game
{
    CameraObserver* CameraObserver::Create(void)
    {
        CameraObserver *camera = new CameraObserver();
        camera->Init();
        camera->autorelease();
        return camera;
    }
    CameraObserver::CameraObserver(void)
    {
        
    }
    CameraObserver::~CameraObserver(void)
    {
        
    }
    void CameraObserver::Init(void)
    {

    }
    void CameraObserver::OnNotifyChange(INotifier *notify, const INotifyEvent *event)
    {
        if (NULL == event)
        {
            return;
        }
        switch (event->GetNotifyEventType())
        {
            case ENCameraEvent::enPosChanged:
                {
                    const CameraPosChanged *posChangedEvent = reinterpret_cast<const CameraPosChanged*>(event);
                    setPosition(cocos2d::ccpNeg(posChangedEvent->GetCameraPosition()));
                }
                break;
			case ENCameraEvent::enScaleChanged:
				{
					const CameraScaleChanged *changedEvent = reinterpret_cast<const CameraScaleChanged*>(event);
					getParent()->setScale(changedEvent->GetScale());
				}
				break;
            default:
                break;
        }
    }
}