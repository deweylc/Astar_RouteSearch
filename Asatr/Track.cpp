#include "Track.h"
Track::Track(int id, QString name, int type, int x, int y, int next1, int next2, int next3, int ScreenX, int ScreenY,Track* t)
	:Node(id,name,type,x,y,next1,next2,next3,ScreenX,ScreenY)
{
	state = 0;
	this->track_type = t->track_type;
	this->p1 = t->p1;
	this->p2 = t->p2;
	this->p3 = t->p3;
	this->p4 = t->p4;
	this->p5 = t->p5;
	this->p6 = t->p6;
	this->p7 = t->p7;
}
Track::Track(int id, QString name, int track_type, QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5, QPoint p6, QPoint p7)
{
	this->ID = id;
	this->name = name;
	this->track_type = track_type;
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	this->p5 = p5;
	this->p6 = p6;
	this->p7 = p7;
}
void Track::Clear()
{
	Node::Clear();
	state = 0;
}
int Track::State()
{
	return state;
}
void Track::SetState(int state)
{
	this->state = state;
}
void Track::Draw(QPainter* p)
{

	if (track_type == 1)
	{
		QColor color_d;
		QColor color_f;
		QColor color = QColor(Qt::white);
		if (state == 0)
		{
			color = QColor(Qt::gray);
			color_d = QColor(Qt::gray);
			color_f = QColor(Qt::gray);
		}
		else if (state == 1)

		{
			color_d = QColor(Qt::white);
			color_f = QColor(Qt::gray);
		}
		else if (state == 2)
		{
			color_d = QColor(Qt::gray);
			color_f = QColor(Qt::white);
		}
		p->setPen(QPen(color, 2));
		p->drawLine(p6, p1);
		
		p->setPen(QPen(color_d, 2));
		p->drawLine(p6, p2);//定位
		p->setPen(QPen(color_f, 2));
		p->drawLine(p6, p3);//反位


		p->setPen(QPen(Qt::gray, 2));
		p->drawLine(p1.x(), p1.y() - 2, p1.x(), p1.y() + 2);
		p->drawLine(p2.x(), p2.y() - 2, p2.x(), p2.y() + 2);
		p->drawLine(p3.x(), p3.y() - 2, p3.x(), p3.y() + 2);
	}
	else if (track_type == 2)
	{
		p->setPen(QPen(Qt::gray, 2));
		QColor ld,lf,rd,rf, mid;
		ld = Qt::gray;
		lf = Qt::gray;
		rd = Qt::gray;
		rf = Qt::gray;
		mid = Qt::gray;
		if (state == 3)
		{
			ld = Qt::white;
			rd = Qt::white;
			mid = Qt::white;
		}
		else if (state == 4)
		{
			lf = Qt::white;
			ld = Qt::white;
		}
		else if (state == 5)
		{
			rf = Qt::white;
			rd = Qt::white;
		}
		else if (state == 6)
		{
			lf = Qt::white;
			ld = Qt::white;
		}
		
		p->setPen(QPen(ld, 2));
		p->drawLine(p6, p1);//左反

		p->setPen(QPen(lf, 2));
		p->drawLine(p6, p2);//左定
		
		p->setPen(QPen(rf, 2));
		p->drawLine(p7, p3);//右反
		p->setPen(QPen(rd, 2));
		p->drawLine(p7, p4);//右定

		p->setPen(QPen(mid, 2));
		p->drawLine(p6, p7);//中段

		p->setPen(QPen(Qt::gray, 2));
		p->drawLine(p1.x(), p1.y() - 2, p1.x(), p1.y() + 2);
		p->drawLine(p2.x(), p2.y() - 2, p2.x(), p2.y() + 2);
		p->drawLine(p3.x(), p3.y() - 2, p3.x(), p3.y() + 2);
		p->drawLine(p4.x(), p4.y() - 2, p4.x(), p4.y() + 2);
	}
	else if (track_type == 3)
	{
		QColor color = Qt::gray;
		if (state == 0)
			color = Qt::gray;
		else if (state == 3)
			color = Qt::white;
		p->setPen(QPen(color, 2));
		p->drawLine(p1, p2);

		p->setPen(QPen(Qt::gray, 2));
		p->drawLine(p1.x(), p1.y() - 2, p1.x(), p1.y() + 2);
		p->drawLine(p2.x(), p2.y() - 2, p2.x(), p2.y() + 2);
	}
	else if (track_type == 4)
	{
		p->setPen(QPen(Qt::gray, 2));
		QColor d, f, c;
		d = Qt::gray;
		f = Qt::gray;
		c = Qt::white;
		if (state == 0)
		{
			c = Qt::gray;
		}
		else if (state == 1)
		{
			d = Qt::white;
		}
		else if (state == 2)
		{
			f = Qt::white;
		}
		
		
		p->setPen(QPen(c, 2));
		p->drawLine(p6, p1);//顺向部分

		p->setPen(QPen(d, 2));
		p->drawLine(p6, p2);//定位
		
		p->setPen(QPen(f, 2));
		p->drawLine(p6, p3);
		p->drawLine(p3, p4);//反位

		p->setPen(QPen(Qt::gray, 2));
		p->drawLine(p1.x(), p1.y() - 2, p1.x(), p1.y() + 2);
		p->drawLine(p2.x(), p2.y() - 2, p2.x(), p2.y() + 2);
		p->drawLine(p4.x(), p4.y() - 2, p4.x(), p4.y() + 2);
	}
	else if (track_type == 5)
	{
		p->setPen(QPen(Qt::gray, 2));
		QColor ld, lf, rd, rf, mid;
		
		ld = Qt::gray;
		lf = Qt::gray;
		rd = Qt::gray;
		rf = Qt::gray;
		mid = Qt::gray;

		if (state == 3)//左右定
		{
			ld = Qt::white;
			mid = Qt::white;
			rd = Qt::white;
		}
		else if (state == 4)//左反右定
		{
			lf = Qt::white;
			mid = Qt::white;
			rd = Qt::white;
		}
		else if (state == 5)//左定右反
		{
			ld = Qt::white;
			mid = Qt::white;
			rf = Qt::white;
		}
		else if (state == 6)//左反右反
		{
			lf = Qt::white;
			mid = Qt::white;
			rf = Qt::white;
		}

		p->setPen(QPen(ld, 2));
		p->drawLine(p6, p1);//左定
		
		p->setPen(QPen(lf, 2));
		p->drawLine(p6, p2);//左反
	
		p->setPen(QPen(rd, 2));
		p->drawLine(p7, p3);//右定

		p->setPen(QPen(rf, 2));
		p->drawLine(p7, p4);
		p->drawLine(p4, p5);//右反

		p->setPen(QPen(mid, 2));
		p->drawLine(p6, p7);//中部


		p->setPen(QPen(Qt::gray, 2));
		p->drawLine(p1.x(), p1.y() - 2, p1.x(), p1.y() + 2);
		p->drawLine(p2.x(), p2.y() - 2, p2.x(), p2.y() + 2);
		p->drawLine(p3.x(), p3.y() - 2, p3.x(), p3.y() + 2);
		p->drawLine(p5.x(), p5.y() - 2, p5.x(), p5.y() + 2);
	}
}