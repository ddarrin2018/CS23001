/**
*Marianna Matousek
*stack.hpp
*cs23001
*generic ADT stack class implemented using a linked list
*/


# include <iostream>
# include <new> //for nothrow


template <typename T>
class node {
public:
	
	
	node(): next(0) {};
	node(const T& x) : data(x), next(0) {};

	T data;
	node <T> * next;
};

template <typename T>
class Stack {
public:
	Stack() : tos(0) {};//default constructor
	~Stack(); //destructor
	Stack(const Stack<T>&);
	void swap(Stack <T> &);
	Stack<T> & operator = (Stack <T> rhs) { //was no & in notes
		swap(rhs);
		return *this;
	}
	bool isEmpty() const { return tos == 0 };
	bool isFull() const;
	void push(const T&);
	T top() const; //peek()
	T pop();

private:
	node <T> *tos;
};


  
template <typename T>
Stack<T>::Stack(const Stack<T>& actual) {
	node<T> * temp = actual.tos, *bottom = nullptr; 
	while (temp->next != nullptr) {//shouldn't this be temp.tos.data != 0
		if (tos = nullptr) { //shouldn't this be tos.next == 0?
			tos = new node<T>(temp->data); //create a new node with the data of temp
			bottom = tos; //bottom is now top of stack
		}
		else {//if current node is empty
			bottom->next = new node<T>(top->data);
			botom = bottom->next;
		}
		
		temp = temp->next;
		}

}

template <typename T>
void Stack<T>::swap(Stack<T>& rhs) {
	node <T> *temp = tos;
	tos = rhs.tos;
	rhs.tos = temp; 
}

template<typename T>
bool Stack<T>::isFull()const {
	Node<T> * node = new(std::nothrow) Node<T>;
	if (node == nullptr)
		return true;
	delete node;
	return false;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>& rhs)  {
	swap(rhs);
	return *this;
}


template <typename T>
Stack<T>::~Stack() { 
	node<T> * temp;
	//while tos is pointing to a node
	while (tos != 0) {
		//save adress of current tos node
		temp = tos;
		//move top of stack over to next node
		tos = tox->next; 
		//dealocate saved address of prev TOS
		delete temp;
	}
}

/*
//what is wrong with this push?:
template<typename T>
void Stack<T>::push(conts T & value) {
	//initializes a new node
	node<T> new_tos_node(value);
	//points new node's next to next to curent tos
	new_tos_node->next = tos;
	//points tos pointer to the new node
	tos =  & new_tos_node; 
}
*/

//puts a new node on top of stack
template <typename T>
void Stack<T>::push(const T& x) {
	assert(!isfull());
	//points a pointer at a newly alocated node 
	//initialized with value x
	node<T> *temp = new node<T>(x);
	
	//points temp's next at current tos node
	temp->next = tos;
	
	//gives tos the value of temp which is
	//the address of the new node
	tos = temp;
}

//template <typename T>
//T Stack<T>::pop() {
//	if (tos != 0) {
//		node<T> *temp = tos;
//		tos = tos->next;
//		T value = temp->data;
//		delete temp;
//		return value; 
//	}
//}


//takes the top node off stack
//so when we exit this  method the dealocator deletes temp?
template<typename T>
T Stack<T>::pop() {
	assert(!isEmpty());
	T result = tos->data;
	node<T> * temp = tos; 
	tos = tos->next;
	return result;
}

//returns top node's data value
template<typename T>
T Stack<T>::top() const{
	assert(!isEmpty());
	return tos->data; 
}