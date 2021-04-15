#pragma once
#include "List.h"
#include "Monom.h"
#include <iostream>
using namespace std;


class TPolinom : public TList<TMonomData>
{
public:
	TPolinom();
	TPolinom(const TPolinom& other);
	~TPolinom();

	TPolinom& operator += (const TMonom& other);
	TPolinom operator * (const TPolinom& other);
	TPolinom operator + (const TPolinom& other);
	TPolinom operator - (const TPolinom& other);

	friend ostream& operator << (ostream& ostr, const TPolinom& P);
};


inline TPolinom::TPolinom() : TList<TMonomData>()
{
}


inline TPolinom::TPolinom(const TPolinom& other) : TList<TMonomData>(other)
{
}

inline TPolinom::~TPolinom()
{
}



inline TPolinom& TPolinom::operator+=(const TMonom& other)
{
	TMonom* v1 = other.Clone();
	if (this->root == nullptr)
	{
		this->root = v1;
		this->end = this->root;
		return *this;
	}
	TMonom* tmp = static_cast<TMonom*>(this->root);
	while (tmp != nullptr)
	{
		if (*tmp == other)
		{
			tmp->SetK(tmp->GetK() + other.GetK());
			return *this;
		}
		else
		{
			TMonom* v = other.Clone();
			if (*tmp < other)
			{
				v->SetNext(tmp);
				v->SetPrev(tmp->GetPrev());

				if (tmp->GetPrev() != nullptr)
					tmp->GetPrev()->SetNext(v);
				else
					this->root = v;

				tmp->SetPrev(v);
				return *this;
			}
			else if (tmp->GetNext() == nullptr)
			{
				v->SetPrev(tmp);
				tmp->SetNext(v);
				this->end = v;
				return *this;
			}
		}
		tmp = tmp->GetNext();
	}
	return *this;
}

inline TPolinom TPolinom::operator*(const TPolinom& other)
{
	TPolinom result;
	TMonom* tmp1 = static_cast<TMonom*>(root);
	if ((root == nullptr) &&  (other.root == nullptr))
		throw - 1;
	while (tmp1 != nullptr)
	{
		TMonom* tmp2 = static_cast<TMonom*>(other.root);
		while (tmp2 != nullptr)
		{
			TMonom tmp3 = *tmp2 * *tmp1;
			result += tmp3;
			tmp2 = tmp2->GetNext();
		}
		tmp1 = tmp1->GetNext();
	}
	return result;
}

inline TPolinom TPolinom::operator+(const TPolinom& other)
{
	if ((other.root == nullptr) || (root == nullptr))
		throw - 1;
	TPolinom result;
	TMonom* tmp = static_cast<TMonom*>(other.root);
	TMonom* tmp2 = static_cast<TMonom*>(root);
	TMonom* r = nullptr;
	while ((tmp != nullptr) && (tmp2 != nullptr))
	{
		TMonom tmp3;
		if (*tmp == *tmp2)
		{
			tmp3 = (*tmp + *tmp2)[0];
			tmp = tmp->GetNext();
			tmp2 = tmp2->GetNext();
		}
		else if (*tmp < *tmp2)
		{
			tmp3 = *tmp2;
			tmp2 = tmp2->GetNext();
		}
		else
		{
			tmp3 = *tmp;
			tmp = tmp->GetNext();
		}

		if (r == nullptr)
		{
			result += tmp3;
			r = static_cast<TMonom*>(result.root);
		}
		else
		{
			r->SetNext(tmp3.Clone());
			r->GetNext()->SetPrev(r);
			r = r->GetNext();
		}
	}
	if (tmp != nullptr)
	{
		while (tmp != nullptr)
		{
			r->SetNext(tmp->Clone());
			r->GetNext()->SetPrev(r);
			r = r->GetNext();
			tmp = tmp->GetNext();
		}
	}
	else if (tmp2 != nullptr)
	{
		r->SetNext(tmp2->Clone());
		r->GetNext()->SetPrev(r);
		r = r->GetNext();
		tmp2 = tmp2->GetNext();
	}
	return result;
}

inline TPolinom TPolinom::operator-(const TPolinom& other)
{
	if ((other.root == nullptr) || (root == nullptr))
		throw - 1;
	TPolinom result;
	TMonom* tmp = static_cast<TMonom*>(other.root);
	TMonom* tmp2 = static_cast<TMonom*>(root);
	TMonom* r = nullptr;
	while ((tmp != nullptr) && (tmp2 != nullptr))
	{
		TMonom tmp3;
		if (*tmp == *tmp2)
		{
			tmp3 = (*tmp2 - *tmp)[0];
			tmp = tmp->GetNext();
			tmp2 = tmp2->GetNext();
		}
		else if (*tmp < *tmp2)
		{
			tmp3 = *tmp2;
			tmp2 = tmp2->GetNext();
		}
		else
		{
			tmp3 = *tmp;
			tmp3.SetK((-1) * (tmp3.GetK()));
			tmp = tmp->GetNext();
		}

		if (r == nullptr)
		{
			result += tmp3;
			r = static_cast<TMonom*>(result.root);
		}
		else
		{
			r->SetNext(tmp3.Clone());
			r->GetNext()->SetPrev(r);
			r = r->GetNext();
		}
	}
	if (tmp != nullptr)
	{
		while (tmp != nullptr)
		{
			r->SetNext(tmp->Clone());
			r->GetNext()->SetPrev(r);
			r = r->GetNext();
			tmp = tmp->GetNext();
		}
	}
	else if (tmp2 != nullptr)
	{
		r->SetNext(tmp2->Clone());
		r->GetNext()->SetPrev(r);
		r = r->GetNext();
		tmp2 = tmp2->GetNext();
	}
	return result;
}

ostream& operator<<(ostream& ostr, const TPolinom& P)
{
	TMonom* tmp = static_cast<TMonom*>(P.root);
	while (tmp != nullptr)
	{
		if (tmp == P.root)
			ostr << *tmp;
		else
			ostr << ((tmp->GetK() > 0) ? "+" : "") << *tmp;
		tmp = tmp->GetNext();
	}
	return ostr;
}