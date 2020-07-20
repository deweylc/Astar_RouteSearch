#include "Signal.h"
Signal::Signal(int id, QString name, int type, int x, int y, int next1, int next2, int next3, int ScreenX, int ScreenY,int state)
	:Node(id,name,type,x,y,next1,next2,next3,ScreenX,ScreenY)
{
	this->state = state;
}

void Signal::Draw(QPainter* p)
{
	p->setPen(QPen(Qt::white, 1));
	int r = 10;
	int height = 25;
	if (type == 11)
	{

		QColor frist(Qt::red);//1灯位
		QColor second(Qt::red);//2灯位
		if (state==0)
		{
			frist = QColor(Qt::red);
			second = QColor(Qt::gray);
		}
		else if (state == 1)
		{
			frist = QColor(Qt::yellow);
			second = QColor(Qt::gray);
		}
		else if (state == 2)
		{
			frist = QColor(Qt::yellow);
			second = QColor(Qt::yellow);
		}
		
		QPoint p1(ScreenX, ScreenY - 5);
		QPoint p2(ScreenX, ScreenY - height);
		p->drawLine(p1, p2);
		QPoint p3(ScreenX, ScreenY - height + r);
		QPoint p4(ScreenX + 10, ScreenY - height + r);
		p->drawLine(p3, p4);
		QPoint p5(ScreenX + 10 + r, ScreenY - height + r);
		QPoint p6(ScreenX + 10 + r + 2*r, ScreenY - height + r);
		
		p->setPen(QPen(frist, 1));
		p->setBrush(frist);
		p->drawEllipse(p5, r, r);
		p->setPen(QPen(second, 1));
		p->setBrush(second);
		p->drawEllipse(p6, r, r);
		p->setPen(QPen(Qt::white, 1));
		
	}
	else if (type == 12)
	{
		QColor frist(Qt::red);//1灯位
		QColor second(Qt::red);//2灯位
		if (state == 0)
		{
			frist = QColor(Qt::red);
			second = QColor(Qt::gray);
		}
		else if (state == 1)
		{
			frist = QColor(Qt::yellow);
			second = QColor(Qt::gray);
		}
		else if (state == 2)
		{
			frist = QColor(Qt::yellow);
			second = QColor(Qt::yellow);
		}
	
		QPoint p1(ScreenX, ScreenY + 5);
		QPoint p2(ScreenX, ScreenY + height);
		p->drawLine(p1, p2);
		QPoint p3(ScreenX, ScreenY + height - r);
		QPoint p4(ScreenX - 10, ScreenY + height - r);
		p->drawLine(p3, p4);
		QPoint p5(ScreenX - 10 - r, ScreenY + height - r);
		QPoint p6(ScreenX - 10 - r - 2 * r, ScreenY + height - r);
		p->setPen(QPen(frist, 1));
		p->setBrush(frist);
		p->drawEllipse(p5, r, r);
		p->setPen(QPen(second, 1));
		p->setBrush(second);
		p->drawEllipse(p6, r, r);
		p->setPen(QPen(Qt::white, 1));
	}
	else if (type == 13)
	{
		QColor color;
		if (state == 0)
			color = QColor(Qt::blue);
		else if (state == 1)
			color = QColor(Qt::white);
		
		QPoint p1(ScreenX, ScreenY - 5);
		QPoint p2(ScreenX, ScreenY - height);
		p->drawLine(p1, p2);
		QPoint p3(ScreenX, ScreenY - height + r);
		QPoint p4(ScreenX+1 , ScreenY - height + r);
	//	p->drawLine(p3, p4);
		QPoint p5(ScreenX +1 + r, ScreenY - height + r);
		p->setPen(QPen(color, 1));
		p->setBrush(color);
		p->drawEllipse(p5, r, r);
		p->setPen(QPen(Qt::white, 1));
	}
	else if (type == 14)
	{
		QColor color;
		if (state == 0)
			color = QColor(Qt::blue);
		else if (state == 1)
			color = QColor(Qt::white);
		
		QPoint p1(ScreenX, ScreenY + 5);
		QPoint p2(ScreenX, ScreenY + height);
		p->drawLine(p1, p2);
		QPoint p3(ScreenX, ScreenY + height - r);
		QPoint p4(ScreenX -1, ScreenY + height - r);
	//	p->drawLine(p3, p4);
		QPoint p5(ScreenX -1 - r, ScreenY + height - r);
		p->setPen(QPen(color, 1));
		p->setBrush(color);
		p->drawEllipse(p5, r, r);
		p->setPen(QPen(Qt::white, 1));
	}
	if (type % 2 == 1)
	{
		QFont font;
		font.setPixelSize(15);
		p->setFont(font);
		QPoint point1(ScreenX - 3 - 45, ScreenY - height + r - 10);
		QPoint point2(ScreenX - 3, ScreenY - height + r + 10);
		p->drawText(QRect(point1,point2),Qt::AlignRight,name);
	}
	else if (type % 2 == 0)
	{
		QFont font;
		font.setPixelSize(15);
		p->setFont(font);
		QPoint point(ScreenX + 3, ScreenY + height-10);
		QPoint point1(ScreenX + 3 + 45, ScreenY + height - r + 10);
		QPoint point2(ScreenX + 3, ScreenY + height - r - 10);
		p->drawText(QRect(point2, point1), Qt::AlignLeft, name);
	}
 }
 int Signal::State()
 {
	 return state;
 }
 void Signal::SetState(int state)
 {
	 this->state = state;
 }
 void Signal::Clear()
 {
	 fatherNode = NULL;
	 f = 0;
	 g = 0;
	 h = 0;
	 state = 0;
 }