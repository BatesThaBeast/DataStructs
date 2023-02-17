#include "MyTemplateFile.h"

template<class T>
Pair<T>::Pair(){}
template<class T>
Pair<T>::Pair(T F, T S)
{
	this->F = F;
	this->S = S;
}
template <class T>
void Pair<T>::setFirst(T newVal) 
{
	this->F = newVal;
}
template <class T>
void Pair<T>::setSecond(T newVal) 
{
	this->S = newVal;
}
template <class T>
T Pair<T>::getFirst() const
{
	return (T)this->F;
}
template <class T>
T Pair<T>::getSecond() const
{
	return (T)this->S;
}