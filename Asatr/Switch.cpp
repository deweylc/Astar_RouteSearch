#include "Switch.h"
Switch::Switch(int id, QString name, int type, int x, int y, int next1, int next2, int next3, int ScreenX, int ScreenY, int state , int lock )
	:Node(id, name, type, x, y, next1, next2, next3, ScreenX, ScreenY)
{
	this->state = state;
	this->lock = lock;
}
void Switch::Draw(QPainter* p)
{
	QColor color;
	if (state == 0)
		color = QColor(Qt::gray);
	else if (state == 1 || state == 2)
		color = QColor(Qt::white);
	p->setPen(QPen(color, 1));
	p->setBrush(color);
	QPoint p1(ScreenX, ScreenY);
	if (type % 10 == 1)
	{
		QPoint p2(ScreenX - 5, ScreenY - 3);
		QPoint p3(ScreenX + 5, ScreenY);
		p->drawRect(QRect(p2, p3));
	}
	else if (type % 10 == 2)
	{
		QPoint p2(ScreenX - 5, ScreenY + 3);
		QPoint p3(ScreenX + 5, ScreenY);
		p->drawRect(QRect(p3, p2));
	}

}
int Switch::State()
{
	return state;
}
void Switch::SetState(int state)
{
	this->state = state;
}
void Switch::Clear()
{
	lock = 0;
	state = 0;
	fatherNode = NULL;
	f = 0;
	g = 0;
	h = 0;
}
void Switch::SetLock(int lock)
{
	this->lock = lock;
}