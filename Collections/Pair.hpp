template<class T1, class T2> 
struct Pair
{
	T1 first;
	T2 second;

	Pair()
		: first()
		, second()
	{
	}

	Pair(const T1& _Val1, const T2& _Val2)
		: first(_Val1)
		, second(_Val2)
	{
	}

	Pair& operator=(const Pair<T1, T2>& other)
	{
		first = other.first;
		second = other.second;
		return (*this);
	}

	Pair& operator=(Pair<T1, T2>&& other)
	{
		first = other.first;
		second = other.second;
		return (*this);
	}
};

template<class T1, class T2>
bool operator==(const Pair<T1, T2>& _Left, const Pair<T1, T2>& _Right)
{	
	return (_Left.first == _Right.first && _Left.second == _Right.second);
}
	
template<class T1, class T2>
bool operator!=(const Pair<T1, T2>& _Left, const Pair<T1, T2>& _Right)
{	
	return (!(_Left == _Right));
}

template<class T1, class T2> 
Pair<T1, T2> makePair(const T1& _Left, const T2& _Right)
{
	return Pair<T1, T2>(_Left, _Right);
}