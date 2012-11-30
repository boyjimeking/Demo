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
namespace Game
{
    CameraObserver::CameraObserver(void)
        :m_camera(NULL)
    {
        
    }
    CameraObserver::~CameraObserver(void)
    {
        
    }
    void CameraObserver::OnNotifyChange(const INotifier *notify, const INotifyEvent *event)
    {
        if (NULL == event)
        {
            return;
        }
        switch (event->GetNotifyEventType())
        {
            case ENCameraEvent::enCameraEvent_Inited:
                {
                    m_camera = new cocos2d::CCCamera;
                    m_camera->init();
                }
                break;
            default:
                break;
        }
    }
}