#include "MainMenuScene.h"
#include "GameSence.h"

USING_NS_CC;

Scene* MainMenu::createScene(){
	auto scene = Scene::create();
	auto layer = MainMenu::create();
	scene->addChild(layer);
	return scene;
}

bool MainMenu::init(){
	if(!LayerColor::initWithColor(Color4B::BLACK)){
		return false;
	}
	Size size = Director::getInstance()->getVisibleSize();

	//添加背景
	auto BG = Sprite::create("cloudBG.jpg");
	BG->setPosition(size.width/2,size.height/2);
	addChild(BG,1);

	//游戏标题
	auto title = Label::createWithTTF("Which One ?","fonts/HYLeMiao.ttf",50);
	title->setColor(Color3B::BLACK);
	title->setPosition(size.width/2,size.height-title->getContentSize().height*2);
	this->addChild(title,2);


	//创建菜单项
   auto item1 = MenuItemLabel::create(Label::createWithTTF("Easy","fonts/hanyixiuyin.ttf",40),CC_CALLBACK_1(MainMenu::ReplaceScene,this,2));
   auto item2 = MenuItemLabel::create(Label::createWithTTF("Normol","fonts/hanyixiuyin.ttf",40),CC_CALLBACK_1(MainMenu::ReplaceScene,this,3));
   auto item3 = MenuItemLabel::create(Label::createWithTTF("Hard","fonts/hanyixiuyin.ttf",40),CC_CALLBACK_1(MainMenu::ReplaceScene,this,4));
   auto item4 = MenuItemLabel::create(Label::createWithTTF("Hell","fonts/hanyixiuyin.ttf",40),CC_CALLBACK_1(MainMenu::ReplaceScene,this,5));

	auto menu = Menu::create(item1,item2,item3,item4,NULL);
	menu->setPosition(size.width/2,size.height/3);
	menu->alignItemsVertically();
	menu->setColor(Color3B::BLACK);
	addChild(menu,2);

	return true;
}

void MainMenu::ReplaceScene(Ref* pSender,int count){
	Game::count = count;
    Director::getInstance()->replaceScene(Game::createScene());
}