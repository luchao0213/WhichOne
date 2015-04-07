#include "cocos2d.h"

USING_NS_CC;
class GameOver:public LayerColor{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameOver);
	void replaceScene(Ref* pSender,int tag);
};
