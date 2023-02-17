#pragma once
#ifndef PAIR
#define PAIR
#include <iostream>
template<class T>
class Pair
{
public:
	Pair();
	Pair(T firstVale, T secondVal);
	void setFirst(T newVal);
	void setSecond(T newVal);
	T getFirst() const;
	T getSecond() const;
	//Below friend functions were needed to allow operations to be completed in the LinkedList class and PairList class. PairList class operator overload does not function correctly
	friend std::ostream& operator<< (std::ostream &out, const Pair<T> &pair)
	{
		out << pair.getFirst() << ", " << pair.getSecond();
		return out;
	}
	friend bool operator ==(const Pair &p1, const Pair &p2)
	{
		return(p1.F == p2.F && p1.S == p2.S);
	}
	friend bool operator!= (const Pair &p1, const Pair &p2)
	{
		return !(p1 == p2);
	}
	Pair& operator=(const Pair &pair1)
	{
		F = pair1.F;
		S = pair1.S;
		return *this;
	}
private:
	T F;//first value of the pair
	T S;//second value of the pair
};

#endif
/*
Funtion:		Pair()
Author:			Johnathan Bates
Description:	Default Constructor. Template type. first and second values are unknown as they are not defined here
Inputs:			None
Outputs:		None
*/
template<class T>
Pair<T>::Pair() {}
/*
Funtion:		Pair(T F, T S)
Author:			Johnathan Bates
Description:	Constructor. Template type. first and second values are set equal to the inputs
Inputs:			Two templated inputs
Outputs:		None
*/
template<class T>
Pair<T>::Pair(T F, T S)
{
	this->F = F;//sets the first value in the pair equal to the first input
	this->S = S;//sets the second value in the pair equal to the second input
}
/*
Funtion:		setFirst(T newVal)
Author:			Johnathan Bates
Description:	Mutator. Template type. first value is set equal to the input
Inputs:			One templated input
Outputs:		None
*/
template <class T>
void Pair<T>::setFirst(T newVal)
{
	this->F = newVal;//sets the first value in the pair equal to the input
}
/*
Funtion:		setSecond(T newVal)
Author:			Johnathan Bates
Description:	Mutator. Template type. second value is set equal to the input
Inputs:			One templated input
Outputs:		None
*/
template <class T>
void Pair<T>::setSecond(T newVal)
{
	this->S = newVal;//sets the second value in the pair equal to the input
}
/*
Funtion:		getFirst() const
Author:			Johnathan Bates
Description:	Accessor. Template type. returns the first value in the pair to the caller
Inputs:			None
Outputs:		one templated output
*/
template <class T>
T Pair<T>::getFirst() const
{
	return (T)this->F;
}
/*
Funtion:		getSecond() const
Author:			Johnathan Bates
Description:	Accessor. Template type. returns the second value in the pair to the caller
Inputs:			None
Outputs:		one templated output
*/
template <class T>
T Pair<T>::getSecond() const
{
	return (T)this->S;
}

