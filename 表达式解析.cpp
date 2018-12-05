#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
using namespace std;

// 双向线性链表容器模板
template<typename T>
class List 
{
public:
	// 构造、析构、拷贝构造、拷贝赋值
	List (void) : m_head (NULL), m_tail (NULL) {}
	~List (void) 
	{
		clear ();
	}

	List (const List& that) : m_head (NULL),m_tail (NULL) 
	{
		for (Node* node = that.m_head; node;
			node = node->m_next)
			push_back (node->m_data);
	}

	List& operator= (const List& that) 
	{
		if (&that != this) {
			List list (that);
			swap (m_head, list.m_head);
			swap (m_tail, list.m_tail);
		}
		return *this;
	}

	// 获取首元素
	T& front (void) 
	{
		if (empty ())
			throw underflow_error ("链表下溢！");
		return m_head->m_data;
	}

	const T& front (void) const 
	{
		return const_cast<List*> (this)->front ();
	}

	// 向首部压入
	void push(const T& data) 
	{
		m_head = new Node (data, NULL, m_head);
		if (m_head->m_next)
			m_head->m_next->m_prev = m_head;
		else
			m_tail = m_head;
	}

	// 从首部弹出
	void pop(void) 
	{
		if (empty ()) throw underflow_error ("链表下溢！");
		Node* next = m_head->m_next;
		delete m_head;
		m_head = next;
		if (m_head)
			m_head->m_prev = NULL;
		else
			m_tail = NULL;
	}

	// 从首部弹出
	T top(void) 
	{
		if (empty ())
			throw underflow_error ("链表下溢！");
		return m_head->m_data;
	}

	// 获取尾元素
	T& back (void) 
	{
		if (empty ())
			throw underflow_error ("链表下溢！");
		return m_tail->m_data;
	}

	const T& back (void) const 
	{
		return const_cast<List*> (this)->back ();
	}

	// 向尾部压入
	void push_back (const T& data) 
	{
		m_tail = new Node (data, m_tail);
		if (m_tail->m_prev)
			m_tail->m_prev->m_next = m_tail;
		else
			m_head = m_tail;
	}

	// 从尾部弹出
	void pop_back (void) 
	{
		if (empty ()) throw underflow_error ("链表下溢！");
		Node* prev = m_tail->m_prev;
		delete m_tail;
		m_tail = prev;
		if (m_tail)
			m_tail->m_next = NULL;
		else
			m_head = NULL;
	}

	// 删除所有匹配元素
	void remove (const T& data) 
	{
		for (Node* node = m_head, *next; node; node = next) 
		{
			next = node->m_next;
			if (equal (node->m_data, data)) 
			{
				if (node->m_prev)
					node->m_prev->m_next =
						node->m_next;
				else
					m_head = node->m_next;
				if (node->m_next)
					node->m_next->m_prev =
						node->m_prev;
				else
					m_tail = node->m_prev;
				delete node;
			}
		}
	}

	// 清空
	void clear (void) 
	{
		for (Node* next; m_head; m_head = next) 
		{
			next = m_head->m_next;
			delete m_head;
		}
		m_tail = NULL;
	}

	// 判空
	bool empty (void) const
	{
		return ! m_head && ! m_tail;
	}

	// 获取大小
	size_t size (void) const 
	{
		size_t count = 0;
		for (Node* node = m_head; node;
			node = node->m_next)
			++count;
		return count;
	}

	// 插入输出流
	friend ostream& operator<< (ostream& os,const List& list) 
	{
		for (Node* node = list.m_head; node;
			node = node->m_next)
			os << *node;
		return os;
	}
private:
	// 节点
	class Node 
	{
	public:
		Node (const T& data = 0, Node* prev = NULL,Node* next = NULL) : 
			m_data (data),m_prev (prev), m_next (next) {}

		friend ostream& operator<< (ostream& os,const Node& node) 
		{
			return os << '(' << node.m_data << ')';
		}

		T m_data; // 数据
		Node* m_prev; // 前指针
		Node* m_next; // 后指针
	};

	bool equal (const T& a, const T& b) const 
	{
		return a == b;
	}
	Node* m_head; // 头指针
	Node* m_tail; // 尾指针
public:
	// 正向迭代器
	class Iterator 
	{
	public:
		Iterator (Node* head = NULL,Node* tail = NULL, Node* node = NULL) :
			m_head (head), m_tail (tail),m_node (node) {}

		bool operator== (const Iterator& it) const 
		{
			return m_node == it.m_node;
		}

		bool operator!= (const Iterator& it) const 
		{
			return ! (*this == it);
		}

		Iterator& operator++ (void) 
		{
			if (m_node)
				m_node = m_node->m_next;
			else
				m_node = m_head;
			return *this;
		}

		const Iterator operator++ (int) 
		{
			Iterator old = *this;
			++*this;
			return old;
		}

		Iterator& operator-- (void) 
		{
			if (m_node)
				m_node = m_node->m_prev;
			else
				m_node = m_tail;
			return *this;
		}

		const Iterator operator-- (int) 
		{
			Iterator old = *this;
			--*this;
			return old;
		}

		T& operator* (void) const 
		{
			return m_node->m_data;
		}

		T* operator-> (void) const 
		{
			return &**this;
		}
	private:
		Node* m_head;
		Node* m_tail;
		Node* m_node;
		friend class List;
	};

	Iterator begin (void)
	{
		return Iterator (m_head, m_tail, m_head);
	}

	Iterator end (void) 
	{
		return Iterator (m_head, m_tail);
	}

	Iterator insert (Iterator loc, const T& data) 
	{
		if (loc == end ()) 
		{
			push_back (data);
	   		return Iterator (m_head, m_tail,m_tail);
		}
		else 
		{
			Node* node = new Node (data,
				loc.m_node->m_prev, loc.m_node);
			if (node->m_prev)
				node->m_prev->m_next = node;
			else
				m_head = node;
			node->m_next->m_prev = node;
			return Iterator (m_head, m_tail, node);
		}
	}

	Iterator erase (Iterator loc) 
	{
		if (loc == end ())
			throw invalid_argument ("无效迭代器！");
		if (loc.m_node->m_prev)
			loc.m_node->m_prev->m_next =
				loc.m_node->m_next;
		else
			m_head = loc.m_node->m_next;
		if (loc.m_node->m_next)
			loc.m_node->m_next->m_prev =
				loc.m_node->m_prev;
		else
			m_tail = loc.m_node->m_prev;
		Node* next = loc.m_node->m_next;
		delete loc.m_node;
		return Iterator (m_head, m_tail, next);
	}
};

// 针对const char*的特化
template<>
bool List<const char*>::equal (const char* const& a,
	const char* const& b) const {
	return strcmp (a, b) == 0;
}

class Exp
{
	List<char> ops;//运算符链表
	List<double> ds;//数据链表
	double v, lh, rh;//计算结果和临时操作数变量
	char op;//运算符
public:
	double calinput()
	{//读取并计算表达式直到结束
		do
		{
			readdata();//读取数据
			skipspace();//跳过空白
		}while(readop());//读取运算符

		calremain();//处理链表中剩余的运算符
		return v;
	}

	void readdata()
	{
		while(!(cin>>v))
		{//读取数据失败应该是'('
			cin.clear();
			cin >> op;//读取'('
			if(op!='(') throw string("在该出现数值的地方遇到了")+op;
			ops.push(op);
		}
		ds.push(v);
	}
	
	void skipspace()
	{//跳过空格
		while(cin.peek()==' ') cin.ignore();
	}

	bool readop()
	{//读取运算符，可能遇到')'或者'\n'
		while((op=cin.get())==')')
		{//遇到')'了
			while(ops.top()!='(')
			{//找链表里的'('为止
				rh=ds.top();ds.pop();//从链表中取得右操作数
				lh=ds.top();ds.pop();//从链表中取得左操作数
				ds.push(cal(lh,ops.top(),rh));//计算并入链表
				ops.pop();
			}
			ops.pop();//丢弃'('
		}

		if(op=='\n') return false;//换行，表达式结束
		if(strchr("+-*/",op)==NULL)//无效运算符
			throw string("无效运算符")+op;

		while(!ops.empty()&&ops.top()!='('&&!prior(op,ops.top()))
		{//处理链表中优先级不低的运算符
			rh=ds.top();ds.pop();
			lh=ds.top();ds.pop();
			ds.push(cal(lh,ops.top(),rh));
			ops.pop();
		}
		ops.push(op);
		return true;
	}

	void calremain()
	{
		while(!ops.empty())
		{//处理链表里剩余的全部运算符
			rh=ds.top();ds.pop();
			lh=ds.top();ds.pop();
			ds.push(cal(lh,ops.top(),rh));
			ops.pop();
		}
		if(ds.size()!=1) throw string("无效的表达式");
		v = ds.top();//最后数据链表里唯一的数据就是结果
		ds.pop();
	}

	double cal(double lh, char op, double rh)
	{//计算
		return op=='+'?lh+rh:op=='-'?lh-rh:op=='*'?lh*rh:lh/rh;
	}

	bool prior(char o1, char o2)
	{//比优先级
		return o1!='+'&&o1!='-'&&o2!='*'&&o2!='/';
	}
};

int main()
{
	Exp e;
	try
	{
		cout << e.calinput() << endl;
	}
	catch(const string& e)
	{
		cout << e << endl;
	}
}