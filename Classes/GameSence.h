#include "cocos2d.h"

USING_NS_CC;

class Game:public LayerColor{
public:
	Layer* _layer;               //blockµÄ¸¸½Úµã       
	Size visibleSize;
	static int count;
	int currentFrame,nextFrame,speed,upMargin,downMargin,groundHeight;
    Vector<Sprite*> blocks;

	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Game);

	void resetFrame();
	void addBlock();
	void gameOver();
	void update(float dt);
	Color3B color(int i);

	bool onTouchBegan(Touch* t,Event* e);
};