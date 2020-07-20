#pragma once
#include "Node.h"
#include<unordered_set>
using namespace std;
class Track :
	public Node
{
public://成员
	QPoint p1, p2, p3, p4, p5, p6,p7;
	int state;//0 未锁定 1定位 2反位 3锁定无岔区段，双道岔区段定位 4左反  5右反【4 5为双道岔区段专用】 
	int track_type;
public:
	Track(int id, QString name, int type, int x, int y, int next1, int next2, int next3, int ScreenX, int ScreenY,Track* t);
	Track(int id, QString name, int track_type, QPoint p1, QPoint p2, QPoint p3, QPoint p4, QPoint p5, QPoint p6, QPoint p7);
	void Clear();
	int State();
	void SetState(int state);
	void Draw(QPainter* p);
	
};

