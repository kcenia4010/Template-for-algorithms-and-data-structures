#pragma once

#include <iostream>
using namespace std;

template <class T>
class TListElem
{
protected:
	T data;
	TListElem<T>* next;
	TListElem<T>* prev;

public:
	TListElem(T _data);

	T GetData();
	TListElem<T>* GetNext();
	TListElem<T>* GetPrev();

	void SetData(T _data);
	void SetNext(TListElem* _next);
	void SetPrev(TListElem* _prev);

	virtual TListElem<T>* Clone() const;

	template <class T1>
	friend ostream& operator << (ostream& ostr, const TListElem<T1>& A);
	template <class T1>
	friend istream& operator >> (istream& istr, TListElem<T1>& A);
};

template<class T1>
inline ostream& operator<<(ostream& ostr, const TListElem<T1>& A)
{
	ostr << A.data;
	return ostr;
}

template<class T1>
inline istream& operator>>(istream& istr, TListElem<T1>& A)
{
	istr >> A.data;
	return istr;
}

template<class T>
inline TListElem<T>::TListElem(T _data)
{
	data = _data;
	next = nullptr;
	prev = nullptr;
}

template<class T>
inline T TListElem<T>::GetData()
{
	return data;
}

template<class T>
inline TListElem<T>* TListElem<T>::GetNext()
{
	return next;
}

template<class T>
inline TListElem<T>* TListElem<T>::GetPrev()
{
	return prev;
}

template<class T>
inline void TListElem<T>::SetData(T _data)
{
	data = _data;
}

template<class T>
inline void TListElem<T>::SetNext(TListElem<T>* _next)
{
	next = _next;
}

template<class T>
inline void TListElem<T>::SetPrev(TListElem<T>* _prev)
{
	prev = _prev;
}

template<class T>
inline TListElem<T>* TListElem<T>::Clone() const
{
	TListElem<T>* result = new TListElem<T>(*this);
	return result;
}



