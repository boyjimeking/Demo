//
//  PhysicalControl.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-4.
//
//

#ifndef __Demo__PhysicalControl__
#define __Demo__PhysicalControl__

class b2World;

namespace Game
{
	class PhysicalObj;
	//
	class PhysicalControl
	{
	public:
		PhysicalControl(void);
		~PhysicalControl(void);
	
		void Update(float dt);

		b2World* GetBox2DWorld(void) const { return m_box2dWorld; }
	private:
		b2World *m_box2dWorld;
	};
}

#endif /* defined(__Demo__PhysicalControl__) */
