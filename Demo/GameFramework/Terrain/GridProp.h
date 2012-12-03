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
	
		void Load(const char *gridName, int posX, int posY);
	private:
		int m_width;
		int m_height;
	};
}

#endif /* defined(__Demo__GridProp__) */
