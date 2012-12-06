//
//  CSMessageType.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#ifndef __Demo__CSMessageType__
#define __Demo__CSMessageType__

#ifndef DefType
#define DefType(className) en##className
#endif

struct ENMessage
{
	enum Type
	{
		enError,
		DefType(CSInitScene_S2C),
		DefType(CSInitMainActor_S2C),
		DefType(CSSycActor_S2C),
		DefType(CSChangeTarget_S2C),
	};
};

#ifndef GetMessageType
#define GetMessageType(className) ENMessage::en##className
#endif

#endif /* defined(__Demo__CSMessageType__) */
