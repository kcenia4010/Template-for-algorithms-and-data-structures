#pragma once
#include <iostream>
#include "List.h"

using namespace std;

struct TMonomData
{
	double K;
	int dim;
	double* data;

	TMonomData(int t = 0);
	~TMonomData();
};

class TMonom : public TListElem<TMonomData>
{
public:
	TMonom(double* _data = 0, int _dim = 0, double _K = 0);
	TMonom(const TMonom& other);
	~TMonom();

	TMonom& operator = (const TMonom& other);

	double GetK() const;
	void SetK(double _K);
	int GetDim() const;
	void SetDim(int _dim);

	TMonom* GetNext();

	TMonom* Clone() const override;

	double& operator [](int i);
	TMonomData& operator *();

	TMonom operator * (const TMonom& other);
	TMonom operator / (const TMonom& other);
	TMonom* operator + (const TMonom& other);
	TMonom* operator - (const TMonom& other);
	
	bool operator >(const TMonom& other);
	bool operator <(const TMonom& other);
	bool operator ==(const TMonom& other);

	friend ostream& operator << (ostream& ostr, const TMonom& A);
	friend istream& operator >> (istream& istr, TMonom& A);
};

inline TMonom::TMonom(double* _data, int _dim, double _K) : TListElem<TMonomData>(0)
{
	if (_dim < 0)
		throw - 1;
	data.dim = _dim;
	data.K = _K;
	if (data.dim == 0)
	{
		data.data = 0;
	}
	else if (data.dim > 0)
	{
		data.data = new double[data.dim];
		for (int i = 0; i < data.dim; i++)
			data.data[i] = _data[i];
	}
}

inline TMonom::TMonom(const TMonom& other) : TListElem<TMonomData>(other)
{
	next = 0;
	prev = 0;
	data.dim = other.data.dim;
	data.K = other.data.K;
	if (data.dim > 0)
	{
		data.data = new double[data.dim];
		for (int i = 0; i < data.dim; i++)
			data.data[i] = other.data.data[i];
	}
	else if (data.dim == 0)
		data.data = 0;
}

inline TMonom::~TMonom()
{
}

inline TMonom& TMonom::operator=(const TMonom& other)
{
	if (*this == other)
		return *this;
	next = 0;
	prev = 0;
	data.K = other.data.K;
	if (data.dim == other.data.dim)
	{
		for (int i = 0; i < data.dim; i++)
			data.data[i] = other.data.data[i];
	}
	else
	{
		if (data.data != nullptr)
			delete[] data.data;
		data.dim = other.data.dim;
		if (data.dim > 0)
		{
			data.data = new double[data.dim];
			for (int i = 0; i < data.dim; i++)
				data.data[i] = other.data.data[i];
		}
		else if (data.dim == 0)
			data.data = 0;
	}
	return *this;
}

inline double TMonom::GetK() const
{
	return data.K;
}

inline void TMonom::SetK(double _K)
{
	data.K = _K;
}

inline int TMonom::GetDim() const
{
	return data.dim;
}

inline void TMonom::SetDim(int _dim)
{
	if (data.dim == _dim) return;
	if (_dim < 0)
		throw - 1;

	if (data.dim > 0)
		delete[] data.data;
	if (_dim == 0)
	{
		data.dim = 0;
		data.data = 0;
	}
	else if (_dim > 0)
	{
		data.dim = _dim;
		data.data = new double[data.dim];
		for (int i = 0; i < data.dim; i++)
			data.data[i] = 0;
	}
}

inline TMonom* TMonom::GetNext()
{
	return static_cast<TMonom*>(next);
}

inline TMonom* TMonom::Clone() const 
{
	TMonom* result = new TMonom(*this);
	return result;
}

inline ostream& operator<<(ostream& ostr, const TMonom& A)
{
	ostr << A.data.K;
	char ch = 'x';
	for (int i = 0; i < A.data.dim; i++)
		ostr << ch++ << "^" <<A.data.data[i];
	return ostr;
}

inline istream& operator>>(istream& istr, TMonom& A)
{
	int dim = 0;
	if (A.data.dim != 0)
		dim = A.data.dim;
	else
	{
		istr >> dim;
		A.SetDim(dim);
	}

	istr >> A.data.K;
	for (int i = 0; i < dim; i++)
		istr >> A[i];
	return istr;
}
 
inline bool TMonom::operator==(const TMonom& other)
{
	if (data.dim != other.data.dim)
		return false;
	bool f = true;
	for (int i = 0; i < data.dim; i++)
	{
		if (data.data[i] != other.data.data[i])
		{
			f = false;
			break;
		}
	}
	return f;
}

inline double& TMonom::operator[](int i)
{
	return data.data[i];
}

inline TMonomData& TMonom::operator*()
{
	return data;
}

inline TMonom TMonom::operator*(const TMonom& other)
{
	TMonom result(*this);
	if (data.dim != other.data.dim)
		throw - 1;
	result.data.K = data.K * other.data.K;
	for (int i = 0; i < data.dim; i++)
		result.data.data[i] = this->data.data[i] + other.data.data[i];
	return result;
}

inline TMonom TMonom::operator/(const TMonom& other)
{
	if (data.dim != other.data.dim)
		throw - 1;
	TMonom result(*this);
	result.data.K = data.K / other.data.K;
	for (int i = 0; i < result.data.dim; i++)
		result.data.data[i] = data.data[i] - other.data.data[i];
	return result;
}

inline TMonom* TMonom::operator+(const TMonom& other)
{
	if (data.dim != other.data.dim)
		throw - 1;
	TMonom* result = 0;
	if (*this == other)
	{
		result = new TMonom(*this);
		result->data.K += other.data.K;
	}
	else
	{
		result = new TMonom[2];
		if (*this > other)
		{
			result[0] = *this;
			result[1] = other;
		}
		else
		{

			result[0] = other;
			result[1] = *this;
		}
	}
	return result;
}

inline TMonom* TMonom::operator-(const TMonom& other)
{
	if (data.dim != other.data.dim)
		throw - 1;
	TMonom* result = 0;

	if (*this == other)
	{
		result = new TMonom(*this);
		result->data.K -= other.data.K;
	}
	else
	{
		result = new TMonom[2];

		if (*this > other)
		{
			result[0] = *this;
			result[1] = other;
			result[1].data.K *= -1;
		}
		else
		{

			result[0] = other;
			result[1] = *this;
			result[0].data.K *= -1;
		}
	}
	return result;
}

inline bool TMonom::operator>(const TMonom& other)
{
	if (data.dim != other.data.dim)
		throw - 1;

	for (int i = 0; i < data.dim; i++)
	{
		if (data.data[i] > other.data.data[i])
		{
			return true;
		}
		else if (data.data[i] < other.data.data[i])
		{
			return false;
		}
	}
	return false;
}

inline bool TMonom::operator<(const TMonom& other)
{
	if (data.dim != other.data.dim)
		throw - 1;

	for (int i = 0; i < data.dim; i++)
	{
		if (data.data[i] < other.data.data[i])
		{
			return true;
		}
		else if (data.data[i] > other.data.data[i])
		{
			return false;
		}
	}
	return false;
}

inline TMonomData::TMonomData(int t)
{
	if (t < 0)
		throw - 1;
	K = 0;
	dim = t;
	if (t == 0)
	{
		data = 0;
	}
	else
	{
		data = new double[dim];
		for (int i = 0; i < dim; i++)
			data[i] = 0;
	}
}

inline TMonomData::~TMonomData()
{
	if (data != nullptr)
	{
		delete[] data;
		data = 0;
		dim = 0;
		K = 0;
	}
}