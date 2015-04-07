#include "GameOver.h"
#include "MainMenuScene.h"
#include "GameSence.h"

USING_NS_CC;
Scene*  GameOver::createScene(){
	auto scene = Scene::create();
	auto layer = GameOver::create();
	scene->addChild(layer);
	return scene;
}

bool GameOver::init(){
	if (!LayerColor::initWithColor(Color4B(189,252,201,255)))
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto label = Label::createWithTTF("Game Over","fonts/HYLeMiao.ttf",33);
	label->setColor(Color3B::BLACK);
	label->setPosition(visibleSize.width/2,visibleSize.height*2/3);
	addChild(label,1);

	auto label1 = Label::createWithTTF("MainMenu","fonts/hanyixiuyin.ttf",33);
	label1->setColor(Color3B::BLACK);
	auto item1 = MenuItemLabel::create(label1,CC_CALLBACK_1(GameOver::replaceScene,this,1));
	auto label2 = Label::createWithTTF("Again","fonts/hanyixiuyin.ttf",33);
	label2->setColor(Color3B::BLACK);
	auto item2 = MenuItemLabel::create(label2,CC_CALLBACK_1(GameOver::replaceScene,this,2));

	auto menu = Menu::create(item1,item2,NULL);
	menu->setPosition(visibleSize.width/2,visibleSize.height/3);
	menu->alignItemsHorizontallyWithPadding(visibleSize.width/12);
	addChild(menu,1);

	return true;
}

void GameOver::replaceScene(Ref* pSender,int tag){
	if (tag == 1)
	{
		Director::getInstance()->replaceScene(MainMenu::createScene());
	}
	else{
		Director::getInstance()->replaceScene(Game::createScene());
	}
}
