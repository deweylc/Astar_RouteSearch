#include "Node.h"
Node::Node(int id, QString name, int type, int x, int y, int next1, int next2, int next3,int ScreenX,int ScreenY)
{
	ID = id;
	this->name = name;
	this->type = type;
	this->X = x;
	this->Y = y;
	this->NextID_1 = next1;
	this->NextID_2 = next2;
	this->NextID_3 = next3;
	this->ScreenX = ScreenX;
	this->ScreenY = ScreenY;
	fatherNode = NULL;
	
}
Node::Node()
{
	ID = -1;
	name = "";
	type = 0;
	X = 0;
	Y = 0;
	NextID_1 = -1;
	NextID_2 = -1;
	NextID_3 = -1;
	this->ScreenX = 0;
	this->ScreenY = 0;
	fatherNode = NULL;
}
void Node::Draw(QPainter* p)
{
	p->setPen(QPen(Qt::white, 1));
	int x = ScreenX;
	int y = ScreenY; 

	QFont font;
	font.setPixelSize(15);
	p->setFont(font);
	p->drawText(x+7, y-23, name);
	p->setBrush(Qt::gray);
	p->drawEllipse(x,y, 3, 3);

}
void Node::GetF()
{
	f = g + h;
}
void Node::GetG(Node* start)
{
	g = sqrt(pow(start->X - this->X, 2) + pow(start->Y - this->Y, 2));//欧氏距离 实际代价
}
void Node::GetH(Node* end)
{
	int k = 5;
	h = k * (abs(this->X - end->X) + abs(this->Y - end->Y));
}
void Node::Clear()
{
	fatherNode = NULL;
	f = 0;
	g = 0;
	h = 0;
	
}
