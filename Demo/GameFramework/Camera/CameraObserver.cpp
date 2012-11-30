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
#include "layers_scenes_transitions_nodes/CCScene.h"

namespace Game
{
    CameraObserver::CameraObserver(cocos2d::CCScene *scene)
        :m_scene(scene)
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
            case ENCameraEvent::enCameraEvent_PosChanged:
                {
                    const CameraPosChanged *posChangedEvent = reinterpret_cast<const CameraPosChanged*>(event);
                    m_scene->setPosition(cocos2d::ccpNeg(posChangedEvent->GetCameraPosition()));
                }
                break;
            default:
                break;
        }
    }
}