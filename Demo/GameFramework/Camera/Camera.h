//
//  Camera.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#ifndef Demo_Camera_h
#define Demo_Camera_h

#include "Base/INotifier.h"

namespace Game
{
	class CameraObserver;
    class Camera
        :public INotifier
    {
    public:
        Camera(void);
        virtual ~Camera(void);

        void init(void);
        
    protected:
    private:
    };
}

#endif
