#include "cocos2d.h"

USING_NS_CC;

class MainMenu:public LayerColor{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MainMenu);
	void ReplaceScene(Ref* pSender,int tag);
};