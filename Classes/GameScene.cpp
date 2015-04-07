#include "GameSence.h"
#include "Block.h"
#include "GameOver.h"

USING_NS_CC;
int Game::count = 2;

Scene* Game::createScene(){
	
	auto scene = Scene::create();
	auto layer = Game::create();
	scene->addChild(layer);
	return scene;
}

bool Game::init(){
	if(!LayerColor::initWithColor(Color4B::WHITE)){
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	speed = 10*count+30;
	resetFrame();
	_layer = Layer::create();
	addChild(_layer,3);
	//addBlock();

	upMargin = visibleSize.height/12;
	downMargin = visibleSize.height/12;
	groundHeight = (visibleSize.height-upMargin-downMargin)/count;


	for (int i = 0; i <count; i++)
	{
		//add ground
		auto ground = Sprite::create();
		ground->setTextureRect(Rect(0,0,visibleSize.width,groundHeight));
		ground->setColor(color(i));
		ground->setPosition(visibleSize.width/2,downMargin+groundHeight*(2*i+1)/2);
		addChild(ground,1);

		//add num
		auto label = Label::createWithTTF(Value(i+1).asString(),"fonts/arial.ttf",32);
		label->setColor(Color3B::BLUE);
		label->setPosition(visibleSize.width/2,downMargin+groundHeight*(2*i+1)/2);
		addChild(label,2);
	}


	//¸ø_layer°ó¶¨¼àÌýÊÂ¼þ
	auto listen1 = EventListenerTouchOneByOne::create();
	listen1->setSwallowTouches(true);
	listen1->onTouchBegan = CC_CALLBACK_2(Game::onTouchBegan,this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listen1,_layer);

	scheduleUpdate();

	return  true;
}

void Game::update(float dt){
	auto sp =_layer->getChildren();
	for(auto b:sp){
		b->setPositionX(b->getPositionX()-3);
		if (b->getPositionX()<0)
		{
			gameOver();
		}
	}


	++currentFrame;
	if(currentFrame>=nextFrame){
		resetFrame();
		if(speed>20)
			--speed;
		addBlock();
	}
}

void Game::resetFrame(){
	currentFrame = 0;
	nextFrame = random()%20 + speed;
}

void Game::addBlock(){
	auto b = Block::createBlock(count);
	blocks.pushBack(b);
	b->setPosition(visibleSize.width,downMargin+groundHeight*(random()%count)+groundHeight/2);
	_layer->addChild(b);
}

void Game::gameOver(){
	//log("gameOver");
	blocks.clear();
	_layer->removeAllChildren();
	Director::getInstance()->replaceScene(GameOver::createScene());
}

bool Game::onTouchBegan(Touch* t,Event* e){
	//log("%d %d  %d",(int)(t->getLocation().y),((int)(t->getLocation().y) -downMargin)/groundHeight+1,blocks.at(0)->getTag());
	if (!blocks.empty()&&((int)(t->getLocation().y) -downMargin)/groundHeight+1 == blocks.at(0)->getTag())
	{
		//log("remove %d",blocks.at(0)->getTag());
		blocks.at(0)->removeFromParent();
		blocks.erase(0);
	}
	else{
		gameOver();
	}
	return false;
}

Color3B Game::color(int i){
	switch (i)
	{
	case(0):
		return Color3B(255,99,71);      //ºì
	case(1):
		return Color3B(135,206,235);   //ÂÌ
	case(2):
		return Color3B(255,200,0);     //»Æ
	case(3):
		return Color3B(127,255,0);     //À¶
	case(4):
		return Color3B(218,112,214);   //×Ï
	default:
		return Color3B(218,112,214);
		break;
	}
}