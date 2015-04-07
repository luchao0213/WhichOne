#include "cocos2d.h"

USING_NS_CC;

class Block:public Sprite{
public:
	static Sprite* createBlock(int count);
};