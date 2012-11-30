//
//  Camera.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#include "Camera.h"
#include "CameraObserver.h"
#include "CameraNotifyEvents.h"
namespace Game
{
    Camera::Camera(void)
    {

    }
    Camera::~Camera(void)
    {
    	//只有Camera类知道CameraObserver，所以在释放的时候要把observer释放掉
    	delete reinterpret_cast<CameraObserver*>(m_observer);
    }

    void Camera::init(void)
    {
    	CameraObserver *observer = new CameraObserver;
    	this->AttachObserver(observer);
        CameraInited initedEvent;
        NotifyChange(&initedEvent);
    }
}