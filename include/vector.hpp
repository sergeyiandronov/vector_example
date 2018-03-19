#include <iostream>
template <typename T>
class vector_t
{
private:
	T * elements_;
	std::size_t size_;
	std::size_t capacity_;
    void at(std::size_t index) const;
public:
  
	vector_t();
	vector_t(vector_t const & other);
	vector_t & operator =(vector_t const & other);
	~vector_t();

	std::size_t size() const;
	std::size_t capacity() const;
    
	void push_back(T value);
	void pop_back();

	T & operator [](std::size_t index);
	T operator [](std::size_t index) const;
    
	bool operator ==(vector_t const & other) const;
};
template<typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs);
#include <algorithm>
#include <cassert>
template <typename T>
void vector_t<T>::at(std::size_t index) const
{
    if(index>=capacity_){
        throw "index out of range"; 
    }
}
template <typename T>
vector_t<T>::vector_t()
{
  elements_=nullptr;
  size_=0;
  capacity_=0;
}
template <typename T>
vector_t<T>::vector_t(vector_t const & other)
{
  elements_=new T[other.capacity()];
  for(int i=0;i<other.size();i++){
    elements_[i]=other.elements_[i];
  }
  size_=other.size();
  capacity_=other.capacity();
}
template <typename T>
vector_t<T> & vector_t<T>::operator =(vector_t const & other)
{   if(this!=&other){
           if(elements_!=nullptr){
                  delete[] elements_; 
           }
           elements_=new T[other.capacity()];
           for(int i=0;i<other.size();i++){
               elements_[i]=other.elements_[i];
           } 
           size_=other.size();
           capacity_=other.capacity();
    }

   return *this;

}
template <typename T>
bool vector_t<T>::operator ==(vector_t const & other) const
{
  bool result=true;
  if(size_!=other.size()){
    return false;
  }
  for(int i=0;i<other.size();i++){
    if(elements_[i]!=other.elements_[i]){
      result=false;
      return result;
    }
  }

  return result;
}
template <typename T>
vector_t<T>::~vector_t()
{
  if(elements_!=nullptr){
        delete[] elements_; 
    }
}
template <typename T>
std::size_t vector_t<T>::size() const
{
    return size_;
}
template <typename T>
std::size_t vector_t<T>::capacity() const
{
    return capacity_;
}
template <typename T>
void vector_t<T>::push_back(T value)
{
     size_+=1;
     if(size_>capacity_){
      if(capacity_==0){
        capacity_=1;
      }else{
          capacity_=2*capacity_;
      }
      
      T *elements=new T[capacity_];
      for(int i=0;i<size_-1;i++){
        elements[i]=elements_[i];
      }
      elements[size_-1]=value;
      if(elements_!=nullptr){
            delete[] elements_; 
        }
        elements_=elements;

     }
     else{
      elements_[size_-1]=value;
     }

}
template <typename T>
void vector_t<T>::pop_back()
{   
  if (size_==0){
    return;
  }
  size_-=1;
  
  if(size_<=(capacity_/4)){
      capacity_=capacity_/2;
      T *elements=new T[capacity_];
      for(int i=0;i<size_;i++){
        elements[i]=elements_[i];
      }
      
      if(elements_!=nullptr){
            delete[] elements_; 
        }
      elements_=elements;

     }
     
}
template <typename T>
T & vector_t<T>::operator [](std::size_t index)
{
  at(index);
  return elements_[index];
}
template <typename T>
T vector_t<T>::operator [](std::size_t index) const
{
  at(index);
  return elements_[index];
}
template <typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs)
{   
  bool result=false;
  if(rhs.size()!=lhs.size()){
    return true;
  }
  
  if(!(lhs==rhs)){
      result=true;
      return result;
  }
  

  return result;
  
}
