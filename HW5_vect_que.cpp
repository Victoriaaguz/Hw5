#include <iostream>
#include <string>
#include<iterator>
#include <vector>
using namespace std;

// For this homework, you are going to implement an extendable vector based queue that 
// uses "jump" trick to save space. 
// Finish function 
//              front() that prints the first element in the queue
//              deque() that dequeues the queue
//          	enque(val) that enqueues val to the queue
//              print_vect() that prints out vect_que.
// Demonstrate that your code works in main.
// Refer to class PPT if you forgot all the different cases. 

template <class T>
class vect_queue {
private:
	vector<T> vect_que;
	size_t size_;
	int que_front_;
public:
	
	vect_queue(T val) {
		vect_que.push_back(val);
		size_ = 1;
		que_front_ = 0;
	}
	T front() const{
        return vect_que[que_front_];
    }
	void deque(){
        
        que_front_ = (que_front_ + 1) % vect_que.size();
        size_--;
        if(vect_que.size() >= 2.5*size_)
        {
            int newsize = size_*2;
            vector<T> newVector(newsize, T());
            for(int i = 0; i< size_; i++)
            {
                int j = (que_front_+i)%vect_que.size();
                newVector[i] = vect_que[j];
            }
            vect_que = newVector; 
            que_front_ = 0;
        }
    }
	void enque(T val){
        if((size_ + 1)> vect_que.size()){
            //resize
            int newsize = size_*2;
            vector<T> newVector(newsize, T());
            for(int i = 0; i< size_; i++)
            {
                int j = (que_front_+i)%vect_que.size();
                newVector[i] = vect_que[j];
            }
            vect_que = newVector; 
            que_front_ = 0;
        }
        int i = (que_front_+size_) % vect_que.size();
        vect_que[i] = val;
        size_++;
        cout << val << ' ';
    }
	void print_vect() const{
        
        for(auto itr = vect_que.begin(); itr!=vect_que.end(); itr++)
        {
            cout << *itr << " ";
        }
        cout << endl;
        
    }
};



int main()
{   
    //Demonstrate your code works by adding/removing values in a vect_que class 
    //object. Print out your result.
    //You should include front index of queue, back index of queue, and the entire
    //vector (not queue) for each case.
    
    //case 1: add to an empty queue
    cout << "case 1" << endl;
    vect_queue<int> q1(1);
    cout << "back of queue: ";
    q1.enque(2);
    cout << endl;
    cout << "front of queue: " << q1.front() << endl;
    cout << "entire vector: ";
    q1.print_vect();
  
    //case 2: add to a non-empty queue without jump 
    cout << "case 2" << endl;
    vect_queue<int> q2(q1);
    cout << "back of queue: ";
    q2.enque(3);
    cout << endl;
    cout << "front of queue: " << q2.front() << endl;
    cout << "entire vector: ";
    q2.print_vect();
    
    cout << "back of queue: ";
    q2.enque(4);
    cout << endl;
    cout << "front of queue: " << q2.front() << endl;
    cout << "entire vector: ";
    q2.print_vect();
    //case 3: add to a non-empty queue with a jump
    cout << "case 3" << endl;
    cout << "back of queue: ";
    q2.enque(5);
    cout << endl;
    cout << "front of queue: " << q2.front() << endl;
    cout << "entire vector: ";
    q2.print_vect();
    //case 4: remove from a queue with number of elements > 1 
    //        and que.front not at vect.back
    cout << "case 4" << endl;
    cout << "remove from a queue" << endl;
    q2.deque();
    cout << "front of queue: " << q2.front() << endl;
    q2.deque();
    cout << "front of queue: " << q2.front() << endl;
    q2.deque();
    cout << "front of queue: " << q2.front() << endl;
    cout << "entire vector: ";
    q2.print_vect();
    //case 5: remove from a queue with number of elements > 1 
    //        and que.front at vect.back
    cout << "case 5" << endl;
    q2.deque();
    cout << "front of queue: " << q2.front() << endl;
    cout << "entire vector: ";
    q2.print_vect();
    //case 6: remove from a queue with 1 element in it and que.front 
    //        not at vect[0]
    cout << "case 6" << endl;
     q2.deque();
    cout << "front of queue: " << q2.front() << endl;
    cout << "entire vector: ";
    q2.print_vect();
    cout<<"\nprogram ends here.\n";

    return 0;
}
