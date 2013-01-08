//
//  Camera.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#ifndef Demo_Camera_h
#define Demo_Camera_h

#include "../Base/INotifier.h"
#include "cocoa/CCGeometry.h"

namespace cocos2d
{
    class CCScene;
}
using namespace cocos2d;
namespace Game
{
	class CameraObserver;
    class Camera
		:public INotifier
	{
	public:
		_Decl_Notifier(Camera);
        Camera(void);
        virtual ~Camera(void);

        void init(IObserver *observer);
		void Reset(void);
        
        CCPoint ConvertWorldPosToDesign(const CCPoint &worldPos);
        CCPoint ConvertDesignPosToWorld(const CCPoint &screenPos);

		float LogicToPoint(float size);
		float PointToLogic(float size);
		CCPoint LogicToPoint(const CCPoint &pos);
		CCPoint PointToLogic(const CCPoint &pos);
		CCSize LogicToPoint(const CCSize &pos);
		CCSize PointToLogic(const CCSize &pos);

        void SetPosition(const CCPoint &newPosition);
        const CCPoint& GetPosition(void) const { return m_position; }


		void SetTransScale(float transScale);
		float GetTransScale(void) const { return m_transScale; }
		float GetObjectScale(void) const { return 1 / m_transScale; }

		void Shake(void);
	protected:
		void SetRootScale(float scale);
    private:
        CCSize m_size;
        CCPoint m_position;
		float m_scale;
		float m_transScale;
    };
}

#endif
