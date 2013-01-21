//
//  GridProp.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#ifndef __Demo__GridProp__
#define __Demo__GridProp__

#include "../Base/INotifier.h"
#include <string>
#include "cocoa/CCGeometry.h"

namespace Game
{
	class GridProp
		:public INotifier
	{
	public:
		_Decl_Notifier(GridProp);
		GridProp(void);
		virtual ~GridProp(void);

		void Init(int id, const char *imageName, float x, float y, float width, float height);
		void Remove(void);

		int GetID(void) const { return m_id; }
		const std::string& GetImageName(void) const { return m_imageName; }
		const cocos2d::CCPoint& GetPosition(void) const { return m_position; }
		const cocos2d::CCSize& GetSize(void) const { return m_size; }
	private:
		int m_id;
		std::string m_imageName;
		cocos2d::CCPoint m_position;
		cocos2d::CCSize m_size;
	};
}

#endif /* defined(__Demo__GridProp__) */
