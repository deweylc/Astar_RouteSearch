#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Asatr.h"
#include<unordered_set>
#include"Node.h"
#include"Signal.h"
#include"Switch.h"
#include"Track.h"
#include<QtSql/qsqldatabase.h>
#include<QtSql/qsqlquery.h>
#include<qmessagebox.h>
#include<qdebug.h>
#include<QtSql/qsqlerror.h>
#include<QtSql/qsqlrecord.h>
using namespace std;
class Asatr : public QMainWindow
{
	
    Q_OBJECT

public:
    Asatr(QWidget *parent = Q_NULLPTR);
	
private:
    Ui::AsatrClass ui;
public://成员
	unordered_set<Node*> Nodelist;
	unordered_set<Track*> TrackList;
private:
	int TimerID;
public://函数
	void ReadDB();

	Track* FindTrack(int id);
	Node* FindNode(int id);
	Node* FindNode(QString name);
	bool InOpen(Node* node, vector<Node*>& open);
	bool InClosed(Node* node, vector<Node*>& closed);
	void InsertNextNode(Node* node, vector<Node*>& open, vector<Node*>& closed, bool& find,Node* end);
	void FindPath(vector<Node*>& closed, Node* start,vector<Node*>&path);
	void ChangeStateSwitch(vector<Node*>& path);//路径中的道岔
	void ChangeStateTrack(vector<Node*> &list,vector<Node*>& path);//路径中的轨道电路
	bool InPath(Node* node, vector<Node*>& path);
	Node* FindSwitch(vector<Node*>& path, QPoint p);
private://事件函数
	void paintEvent(QPaintEvent* event);
	virtual void timerEvent(QTimerEvent* event);
private slots:
	void GetPath();
	void ClearSearch();
};
