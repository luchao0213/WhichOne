#include "Block.h"

USING_NS_CC;

Sprite* Block::createBlock(int count){
	auto block = Sprite::create();
	int width = 50;
	int height = 50;
	block->setTextureRect(Rect(0,0,width,height));
	auto label = Label::createWithTTF("1","fonts/arial.ttf",32);
	
	switch (random()%(count*2))
	{
	case(0):
		block->setColor(Color3B::RED);
		block->setTag(1);
		break;
	case(1):
		block->setColor(Color3B::BLACK);
		label->setPosition(width/2,height/2);
		block->addChild(label);
		block->setTag(1);
		break;
	case(2):
		block->setColor(Color3B::BLUE);
		block->setTag(2);
		break;
	case(3):
		block->setColor(Color3B::BLACK);
		label->setPosition(width/2,height/2);
		label->setString("2");
		block->addChild(label);
		block->setTag(2);
		break;
	case(4):
		block->setColor(Color3B::YELLOW);
		block->setTag(3);
		break;
	case(5):
		block->setColor(Color3B::BLACK);
		label->setPosition(width/2,height/2);
		label->setString("3");
		block->addChild(label);
		block->setTag(3);
		break;
	case(6):
		block->setColor(Color3B::GREEN);
		block->setTag(4);
		break;
	case(7):
		block->setColor(Color3B::BLACK);
		label->setPosition(width/2,height/2);
		label->setString("4");
		block->addChild(label);
		block->setTag(4);
		break;
	case(8):
		block->setColor(Color3B::MAGENTA);
		block->setTag(5);
		break;
	case(9):
		block->setColor(Color3B::BLACK);
		label->setPosition(width/2,height/2);
		label->setString("5");
		block->addChild(label);
		block->setTag(5);
		break;	
	default:
		break;
	}
	return block;
}

