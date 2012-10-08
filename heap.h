/*
Head:	Template Class Heap
Author:	Ding Yaguang / 2012-1-23
*/
#include <vector>
using namespace std;
#ifndef DINGYAGUANG_HEAP
#define DINGYAGUANG_HEAP

/*=============== heap类声明 =====================*/
template<typename T,typename CMP = less<T>>
class heap
{
private:
	vector<T> _data;	//容器用的是vector，暂时不会适配器，所以定死了
	CMP _cmp;			//比较的 函数对象，默认是小于，即大顶堆
private:
	void _push_adjust(size_t n);
	void _adjust(size_t n);
	void _build();
	inline void _swap(T &a,T &b)
	{
		T t=a;
		a=b;
		b=t;
	}
public:
	heap();
	template<typename _RanIt> heap(_RanIt first,_RanIt end);
	template<typename _RanIt> void assign(_RanIt first,_RanIt end);
	size_t size();
	T pop();
	void push(T);
	T top();

};

//=========构造函数================
template<typename T,typename CMP>
heap<T,CMP>::heap():_data(T()),_cmp(CMP())
{

}


//嵌套模板，语法是瞎蒙的
template<typename T,typename CMP>
template<typename _RanIt>
heap<T,CMP>::heap(_RanIt first,_RanIt end):_data(first,end),_cmp(CMP())
{
	//填充第一位
	_data.insert(_data.begin(),T());
	_build();
}

//=============内部函数===================
template<typename T,typename CMP>
template<typename _RanIt>
void heap<T,CMP>::assign(_RanIt first,_RanIt end)
{
	//填充第一位
	_data.assign(first,end);
	_data.insert(_data.begin(),T());
	_build();
}

template<typename T,typename CMP>
void heap<T,CMP>::_push_adjust(size_t n)
{
	size_t parent = n>>1;
	if ( parent > 0)
	{
		if (_cmp(_data[parent],_data[n]))
		{
			_swap(_data[parent],_data[n]);
			_push_adjust(parent);
		}
	}
	
}

template<typename T,typename CMP>
void heap<T,CMP>::_adjust(size_t n)
{
	size_t L = n<<1;
	size_t R = L|1;

	if ( L <= size())
	{
		if (_cmp(_data[n], _data[L]))
		{
			_swap(_data[n],_data[L]);
			_adjust(L);
		}
	}
	if ( R <= size())
	{
		if (_cmp(_data[n], _data[R]))
		{
			_swap(_data[n],_data[R]);
			_adjust(R);
		}
	}
}

template<typename T,typename CMP>
void heap<T,CMP>::_build()
{
	size_t i;
	for ( i = size() / 2; i > 0; --i )
	{
		_adjust(i);
	}
}
//================接口=================
template<typename T,typename CMP>
T heap<T,CMP>::top()
{
	return _data[1];
}

template<typename T,typename CMP>
T heap<T,CMP>::pop()
{
	T ans = _data[1];
	_data[1] = *_data.rbegin();
	_data.pop_back();
	_adjust(1);
	return ans;
}

template<typename T,typename CMP>
void heap<T,CMP>::push(T val)
{
	_data.push_back(val);
	_push_adjust(size());
}

template<typename T,typename CMP>
size_t heap<T,CMP>::size()
{
	return _data.size()-1;
}


#endif