#include "Asatr.h"

Asatr::Asatr(QWidget *parent)
    : QMainWindow(parent)
{
	setWindowState((Qt::WindowMaximized));
	ReadDB();
	ui.setupUi(this);
	QPalette palette(this->palette());
	palette.setColor(QPalette::Background, Qt::black);
	this->setPalette(palette);
}
void Asatr::ReadDB()
{
	QSqlDatabase db;
	db = QSqlDatabase::addDatabase("QODBC");
	db.setDatabaseName("Nodeinfo");
	if (!db.open())
	{
		QMessageBox::critical(0, QObject::tr("Database Error"), db.lastError().text());
		return;
	}
	
	QSqlQuery query,query2;
	QString sqlstr2 = "select * from track";
	query2.exec(sqlstr2);
	while (query2.next())
	{
		int id = query2.value(0).toInt();
		QString name = query2.value(1).toString();
		int track_type = query2.value(2).toInt();
		int a = 2;
		double b = 1.5;
		QPoint p1 = QPoint(query2.value(3).toInt() * a, query2.value(4).toInt() * b);
		QPoint p2 = QPoint(query2.value(5).toInt() * a, query2.value(6).toInt() * b);
		QPoint p3 = QPoint(query2.value(7).toInt() * a, query2.value(8).toInt() * b);
		QPoint p4 = QPoint(query2.value(9).toInt() * a, query2.value(10).toInt() * b);
		QPoint p5 = QPoint(query2.value(11).toInt() * a, query2.value(12).toInt() * b);
		QPoint p6 = QPoint(query2.value(13).toInt() * a, query2.value(14).toInt() * b);
		QPoint p7 = QPoint(query2.value(15).toInt() * a, query2.value(16).toInt() * b);
		Track* track;
		track = new Track(id, name, track_type, p1, p2, p3, p4, p5, p6, p7);
		TrackList.insert(track);
	}

	QString sqlstr = "select * from info";
	query.exec(sqlstr);
	while (query.next())
	{
		int id = query.value(0).toInt();
		QString name = query.value(1).toString();
		int type = query.value(2).toInt();
		int X = query.value(3).toInt();
		int Y = query.value(4).toInt()*50;
		int next1 = query.value(5).toInt();
		int next2 = query.value(6).toInt();
		int next3 = query.value(7).toInt();
		int sx = query.value(8).toInt() * 2;
		int sy = query.value(9).toInt() * 1.5;
		Node* node;
		if (type / 10 == 1)
			node = new Signal(id, name, type, X, Y, next1, next2, next3, sx, sy, 0);
		else if (type / 10 == 2)
			node = new Switch(id, name, type, X, Y, next1, next2, next3, sx, sy, 1, 0);
		else if (type == 3)
			node = new Track(id, name, type, X, Y, next1, next2, next3, sx, sy, FindTrack(id));
		else 
			node = new Node(id, name, type, X, Y, next1, next2, next3, sx, sy);
		Nodelist.insert(node);
	}//读取节点数据

	db.close();

	
	for (unordered_set<Node*>::iterator it = Nodelist.begin(); it != Nodelist.end(); it++)
	{

		(*it)->Clear();
		if (FindNode((*it)->NextID_1) != NULL)
			(*it)->next.push_back(FindNode((*it)->NextID_1));
		if (FindNode((*it)->NextID_2) != NULL)
			(*it)->next.push_back(FindNode((*it)->NextID_2));
		if (FindNode((*it)->NextID_3) != NULL)
			(*it)->next.push_back(FindNode((*it)->NextID_3));
	}
	
	
}
void Asatr::paintEvent(QPaintEvent* event)
{
	QPalette pa;
	pa.setColor(QPalette::WindowText, Qt::white);
	ui.label->setPalette(pa);
	ui.label_2->setPalette(pa);
	ui.label_3->setPalette(pa);
	QPainter p(this);
	unordered_set<Node*>::iterator it;
	for (it = Nodelist.begin(); it != Nodelist.end(); it++)
	{
		(*it)->Draw(&p);
	}
	TimerID = this->startTimer(500);
}
void Asatr::GetPath()
{
	unordered_set<Node*>::iterator it;
	for (it = Nodelist.begin(); it != Nodelist.end(); it++)
	{
		(*it)->Clear();
	}
	
	Node* start = FindNode(ui.InputStart->text());
	Node* end = FindNode(ui.InputEnd->text());
	vector<Node*> open;
	vector<Node*> closed;
	vector<Node*> path;
	bool find = false;
	if (start != NULL && end != NULL)
		open.push_back(start);
	while (!find)
	{
		if (open.empty())
		{
			QMessageBox mes;
			QString str = QStringLiteral("该进路无效");
			mes.information(NULL, "Error", str, QMessageBox::Ok);
		
			return;
		}
		double minF = INT_MAX;
		for (int i = 0; i < open.size(); i++)
		{
			open[i]->GetH(end);
			open[i]->GetG(start);
			open[i]->GetF();
			minF = min(minF, open[i]->f);
		}//获取最小值
		vector<Node*> minVec;
		for (int i = 0; i < open.size(); i++)
		{
			if (open[i]->f == minF)
			{
				minVec.push_back(open[i]);
				open.erase(open.begin() + i);
				i--;
			}
		}
	/*	for (vector<Node*>::iterator it=open.begin(); it != open.end();it++ )
		{
			if ((*it)->f == minF)
			{
				minVec.push_back(*it);
				open.erase(it);
				it--;
			}
			
		}//open表中的最小值
		*/
		closed.insert(closed.end(),minVec.begin(), minVec.end());
		for (int i = 0; i < minVec.size(); i++)
		{
			InsertNextNode(minVec[i], open, closed, find, end);//将open表中f最小的加入closed，检索他们的邻接节点加入到open表中
			
		}
		if (find)
		{
			FindPath(closed, start, path);
			ChangeStateSwitch(path);
			//ChangeStateTrack(path);
			vector<Node*> list(Nodelist.begin(), Nodelist.end());
			ChangeStateTrack(list,path);
		
			QMessageBox::information(NULL, "Sucess", "Search completed", QMessageBox::Ok);
			QString str;
			for (int i = 0; i < path.size()-1; i++)
			{
				QString s;
				s = path[i]->name + "->";
				str += s;
			}
			str += path.back()->name;
			ui.Search->setText(str);
		}

		
		repaint();
		
	}
	
}
Node* Asatr::FindNode(int id)
{
	unordered_set<Node*>::iterator it;
	for (it = Nodelist.begin(); it != Nodelist.end(); it++)
	{
		if ((*it)->ID == id)
			return *it;
	}
	return NULL;
}
Node* Asatr::FindNode(QString name)
{
	unordered_set<Node*>::iterator it;
	for (it = Nodelist.begin(); it != Nodelist.end(); it++)
	{
		if ((*it)->name == name)
			return *it;
	}
	return NULL;
}
bool Asatr::InOpen(Node* node, vector<Node*>& open)
{
	for (int i = 0; i < open.size(); i++)
	{
		if (open[i] == node)
			return true;
	}
	return false;
}
bool Asatr::InClosed(Node* node, vector<Node*>& closed)
{
	for (int i = 0; i < closed.size(); i++)
	{
		if (closed[i] == node)
			return true;
	}
	return false;
}
void Asatr::InsertNextNode(Node* node, vector<Node*>& open, vector<Node*>& closed, bool& find,Node* end)
{
	vector<Node*>::iterator it;
	for (it = node->next.begin(); it != node->next.end(); it++)
	{
		if (InClosed(*it, closed))
			continue;
		else if ((*it)==end)
		{
			find = true;
			(*it)->fatherNode = node;
			closed.push_back((*it));
			return;
		}
		else
		{
			(*it)->fatherNode = node;
			open.push_back((*it));
		}
	}
}
void Asatr::FindPath(vector<Node*>& closed, Node* start,vector<Node*>&path)
{
	Node* node = closed.back();
	while (node != start)
	{
		if (node->type / 10 == 1)
		{
			if (node->type % 2 == start->type % 2)
			{
				node->SetState(1);
								
			}
		}


		path.push_back(node);
		node = node->fatherNode;
	}
	if (start->Y == closed.back()->Y)
		start->SetState(1);
	else
		start->SetState(2);
	path.push_back(start);
	reverse(path.begin(), path.end());
	return;
}
void Asatr::timerEvent(QTimerEvent* event)
{
	if (event->timerId() == TimerID)
	{
		repaint();
	}
}
void Asatr::ClearSearch()
{
	unordered_set<Node*>::iterator it;
	for (it = Nodelist.begin(); it != Nodelist.end(); it++)
	{
		(*it)->Clear();
	}
	ui.InputEnd->clear();
	ui.InputStart->clear();
	repaint();
}

Track* Asatr::FindTrack(int id)
{
	unordered_set<Track*>::iterator it;
	for (it = TrackList.begin(); it != TrackList.end(); it++)
	{
		if ((*it)->ID == id)
			return *it;
	}
	return NULL;
}
void::Asatr::ChangeStateSwitch(vector<Node*>& path)
{
	for (int i = 0; i < path.size(); i++)
	{
		if (path[i]->type / 10 == 2)
		{
			Node* front, * back;
			try
			{
				front = path[i - 1];
				back = path[i + 1];
			}
			catch (exception e)
			{
				int x = i;
				e.what();
			}
			if (front->Y != back->Y)
			{
				path[i]->SetState(2);
			}
			else
				path[i]->SetState(1);
			
		}
		
		
	}

}
void Asatr::ChangeStateTrack(vector<Node*> &list,vector<Node*> &path)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->type == 3)
		{
			Track* t;
			t = (Track*)list[i];
			if (t->track_type == 1)
			{
				Node* node = FindSwitch(list, t->p6);
				if (node->State() == 1)
				{
					t->SetState(1);
				}
				else if (node->State() == 2)
				{
					t->SetState(2);
				}
			}
			else if (t->track_type == 2)
			{
				Node* node1 = FindSwitch(list, t->p6);
				Node* node2 = FindSwitch(list, t->p7);
				if (node2 == NULL && node1 == NULL)
					continue;
				if (node1->State() == 2 && node2->State()==0)
				{

					t->SetState(4);

				}
				else if (node1->State() == 0 && node2->State() == 2)
				{
					t->SetState(5);
				}
				else if (node1->State() == 1 && node1->State() == 1)
				{
					t->SetState(3);
				}
				else if (node1->State() == 2 && node2->State() == 1)
				{
					t->SetState(4);
				}
				else if (node1->State() == 1 && node2->State() == 2)
				{
					t->SetState(5);
				}
				else
					t->SetState(0);
			}
			else if (t->track_type == 3)
			{
				if (InPath(list[i], path))
					t->SetState(3);
			}
			else if (t->track_type == 4)
			{
				Node* node = FindSwitch(list, t->p6);
				if (node->State() == 1)
				{
					t->SetState(1);
				}
				else if (node->State() == 2)
				{
					t->SetState(2);
				}
			}
			else if (t->track_type == 5)
			{
				Node* node1 = FindSwitch(list, t->p6);
				Node* node2 = FindSwitch(list, t->p7);
				if (node1->State() == 1 && node2->State() == 1)
				{
					t->SetState(3);
				}
				else if (node1->State() == 1 && node2->State() == 2)
				{
					t->SetState(5);
				}
				else if (node1->State() == 2 && node2->State() == 1)
				{
					t->SetState(4);
				}
				else if (node1->State() == 2 && node2->State() == 2)
				{
					t->SetState(6);
				}
			}
		}
	}

}
Node* Asatr::FindSwitch(vector<Node*>& path, QPoint p)
{
	vector<Node*>::iterator it;
	for (it = path.begin(); it != path.end(); it++)
	{
		if ((*it)->type / 10 == 2)
		{
			if ((*it)->ScreenX == p.x() && (*it)->ScreenY == p.y())
			{
				return *it;
			}
		}
	}
	return NULL;
}
bool Asatr::InPath(Node* node, vector<Node*>& path)
{
	for (vector<Node*>::iterator it = path.begin(); it != path.end(); it++)
	{
		if ((*it)->ID == node->ID)
			return true;
	}
	return false;
}