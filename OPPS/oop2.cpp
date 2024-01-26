#include<iostream> 
using namespace std ; 
// Inheritance, Polymorphism, Encapsulation & Abstraction

// 1.Encapsulation:- wrapping up data members & functions 
// fully encapsulated class:-all data member private 
// encapsulation:- information hiding & data hiding 
// why encapsulation:-1. we can hide data(security increased)
//2. if we want we can make class - 'read only'
// 3. code reusability 
//   4. unit testing 

/*
class student{
    private:
        string name ;
        int age ;
        int height ;
    public: 
        int getAge(){
            return this->age ; 
        }
};

int main(){
    student Netram; 
    cout<<"Netam is a student"<<endl; 
    return 0; 
}
*/

// Inheritance:- inherite properties from one class to another 
// parent class(super class ):- from who we take properties 
// child class( sub-class) :- to whom we give properties 

class Human{
    public: 
    int height ; 
    int weight ;
    int age ; 
    public: 
    int getAge(){
        return this->age ; 
    }
    void setWeight(int w ){
        this->weight= w ; 

    }

};
// how we write child class
// class child_class: access-modifier parent_class{};
// private data member of any class is not inheritable 
// protected :- similar private, accessible inside own class, child class(derived class) can access 


 /*
class Male : public Human {
    public: 
    string color ; 
    void sleep(){
        cout<<"male sleeping"<<endl ; 
    }
};

int main(){
    Male Netram ; 
    cout<<Netram.age<<endl ; 
    cout<<Netram.color<<endl; 
    Netram.sleep() ;
    return 0 ; 
}

*/
/// types of inheritance:- single, multi-level, multiple, hybrid,hiretical 

// single inheritance:- 
/*
class Animal{
    public: 
    int age ;
    int weight ;
    public:
    void speak(){
        cout<<"speaking "<<endl ; 
    }
};
class Dog : public Animal {

};
int main(){
    Dog d ; 
    d.speak();
    cout<<d.age <<endl ;
    return 0 ;

}
*/
// multilevel:- if we inherite classes in a chain 
// example: A->B->C->D  
/*    
class Animal{
    public: 
    int age ;
    int weight ;
    public:
    void speak(){
        cout<<"speaking "<<endl ; 
    }
};
class Dog : public Animal {

};
class JarmanSephat : public Dog {

}; 
int main(){
    JarmanSephat JS ; 
    JS.speak();
    cout<<JS.age <<endl ;
    return 0 ;

}
*/

// multiple inheritance 
// A->C & B->C 
// class C: public A,  public B { };



// hierarchical:- one class serve as parent class for more than 1 class 
// read codestudio OOPS guide 

// hybrid inheritance:- it is the combination of more than 1 inheritance 


// inheritance ambiguity:
// example :// A->C & B->C , if there is a funtion fun1() name in both A & B then what to do?
// then use ambiguity function 
/*
class A {
    public:
    void fun1(){
        cout<<" i am A "<<endl ; 
    }
};
class B {
     public:
    void fun1(){
        cout<<" i am B "<<endl ; 
    }
};

class C : public A, public B {

};

int main(){
    C obj1 ;
    obj1.A::fun1() ;
    obj1.B::fun1() ;

    return 0 ;
}
*/ 
// polymorphism : multiple forms 
// two types :- compile time polymorphism, run-time polymorphism 
// 1. Compile time polymorphism (we call it static polymorphism ):- Function overloading, operator overloading 
/*
class A {
    public:
    // when two functions with same name has different inputs argument than no problem , see below code, here we changed the function signature 
    // we can't make two function with same name and different return type 
    void sayHello(){
        cout<<"hello komal"<<endl ; 
    }
    void sayHello(string name){
        cout<<"hello "<<name<<endl ; 
    }
};

int  main(){
    A obj1 ;
    obj1.sayHello("komali");
    return 0 ; 
}
*/

// operator overloading:- a function that add, concatinate and subtract at a same time 

// syntax of overloading operator 
// return_type operator+(inputs){}
/*
class B {
    public:
    int a ;
    int b ;
    public:
    int add(){
        return a+b ; 
    }
    // below we chagne the job of '+' 
    void operator+ (B &obj ){
        int value1  = this-> a ;
        int value2 = obj.a ; 
        cout<<"output"<<value1 - value2<<endl ; 

    }
    void operator() (){
        cout<<"i am bracket"<<endl ; 
    }
};
// some operator can't be overload, read codestudio guide 
int main(){
    B obj1, obj2 ;
    obj1.a  =  11;
    obj2.a = 7 ; 
    obj1+obj2 ; 
    obj1() ;

    return 0 ; 
}*/

// Run time polymorphism( dynamci polymorphism ):- method over-riding (here first we inherit a class into another class and than make same name function and do changes)
// condition for run-time polymorphism 
// 1. function name same 2. fuction input arguments same 3. inheritance must 
/*
class Animal {
    public:
    void speak(){
        cout<<"speaking "<<endl ; 
    }
};

class dog: public Animal {
    // function overiding 
    public :
    void speak(){
        cout<<"barking"<<endl ; 
    }
};

int main(){
    dog a ;
    a.speak();
    return 0; 
}
*/
// read advantages and use of all four pillars 
// Abstraction:- implemenation hiding 

// read difference in encapsulation and abstraction 
/// https://stackoverflow.com/questions/742341/difference-between-abstraction-and-encapsulation

// this lecture is not complete OOPS, this is the only for interview of dsa 
/// this is the basic of oops 
 