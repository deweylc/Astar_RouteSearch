#pragma once
#include<math.h>
#include<vector>
#include<qstring.h>
#include<qpainter.h>
#include<unordered_set>

using namespace std;
class Node
{

public://函数
	Node(int id, QString name, int type, int x, int y, int next1, int next2, int next3, int ScreenX, int ScreenY);
	Node();
	virtual void Draw(QPainter* p);
	void GetF();
	void GetG(Node* start);
	void GetH(Node* end);
	virtual void Clear();
	virtual int State() { return -1; };
	virtual void SetState(int state) {};
	virtual void SetLock(int lock) {};
	
public://成员
	int ID;
	QString name;
	int type;
	int X;
	int Y;
	int NextID_1;
	int NextID_2;
	int NextID_3;
	int ScreenX;
	int ScreenY;
	Node* fatherNode;//该结点的父节点(特指在closed表，由该结点回溯时的上一个节点
	std::vector<Node*> next;//该结点的邻接结点
	double f;
	double g;
	double h;
	
};

