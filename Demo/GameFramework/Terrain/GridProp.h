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

namespace Game
{
	class GridProp
		:public INotifier
	{
	public:
		GridProp(void);
		virtual ~GridProp(void);
	
		void Load(const char *gridName, float posX, float posY);
		void Release(void);
	private:
		float m_x;
		float m_y;
	};
}

#endif /* defined(__Demo__GridProp__) */
