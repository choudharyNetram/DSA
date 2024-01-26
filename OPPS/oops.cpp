/*
oops is type of programing that revolve around a object 
object is one type of entity that have property, state and behaviour 

class:- user defined data type 
object:- instance of class 
class is like a tamplate and object is like what we fill in tamplate
empty class me 1 byte memory hoti h

there are 3 type of access modifiers 
1. public :- we can access this data anywhere 
2. privte:- we can only access it in class 
3. protected 
:- by defalut every class is private 

if we want to access the data from private class than we can use getter/ setter function 
getter:- it gives us the value 
setter:- by this we can set the value 
/*********read about padding and greddy ali

*/
#include<iostream> 
#include<cstring> 
using namespace std ; 
class Jat {
    
    // properties
   

    private: 
    char level ;  
    public: 
    // default constructor made by compiler like below code
    char *name ; 
    Jat(){
        cout<<"constructor called"<<endl; // after building this constructor the default constructor is disappeared or deleted 
        name = new char[100] ;
    }
    // when we made our any constructor than we should made a non-parametrized(simple) constructor because the default constructor deleted 
     // parametrized constructor 
    Jat (int health, int power ){
        this->health = health ; // the address of object is stored in this key-word 
        this->power = power ; 
    }

    
    
    int power ; 
    int health ; 
   
    int getpower(){
        return power ; 
    }
    char getlevel(){
        return level ; 
    }
    void setpower(int pwr){
        power = pwr ; 
    }
    void setLevel(char ch){
        level = ch ; 
    }
     void setname(char name[]) {
        this->name = name ;
    }
    // copy constructor 
    // in deep copy new memory address is made for jat2 
    // how to do deep copy:- for that use our made copy constructor 
    // in deep copy we made a new array at new address for name string 
    Jat (Jat &temp){    // if we pass by value then this didn't work because infinte loops become 
        char *ch = new char[strlen(temp.name)+1 ]; 
        strcpy(ch, temp.name);
        this->name = ch ; 
        this-> health = temp.health ; 
        this->level = temp.level ; 
    }

    // what is the static keyword:- it is a data type that belongs to class. for access it we can't need to made object.     
    static int timeToComplete ; 
    // static function:- no need to create object for this, in static funtion there is no this keyword (this keyword is poiting to current object and there is no  object)
// static funtion only can access to static member 
    static int random(){
        return timeToComplete ;
    }

    void print(){
        cout<<"name is "<<this->name<<endl ; 
        cout<<"health is "<<this-> health<<endl ; 
        cout<<"power is "<<this-> power<<endl ; 
       
    }
    // destructor :- memory deallocate 

   ~Jat(){
     cout<<"destructor called "<<endl ; 
   }


} ;

// we have to defining value to static at outside of class 
// datatype className :: fieldName = value ;      (:: this is the scope resolution operator )
int Jat :: timeToComplete = 5 ; 

// in empty class 1 byte of memory is stored
// if we declared any data type in class than the size of class is increased 
// we can also take class from other files , for that #include<Jat.cpp> 
int main(){
   //Jat Netram ; // creation of a object // this is the static allocation 
    // if we doesn't give any value to object than garbage value is putted on object 
    // &Netram = this  
    //cout<<"size "<<sizeof(Netram)<<endl ;
   // Netram.health = 98 ; 
    //Netram.power = 100 ; 
    //cout<<"power is "<< Netram.power <<endl ; 
    //cout<<"health is "<<Netram.health <<endl ;
    // if we want to access from private class then what to do 
   // cout<<"Netram  power is "<<Netram.getpower()<<endl ;
    //Netram.setpower(101) ;
    // we set a password that who can change the value of power 
    // like that in setPower function setPower(101, A)
    // in the function is class setpower(int pwr, char password)
    // if(password == 'A'){power = pwer }
    //cout<<"Netram  power is "<<Netram.getpower()<<endl ;
    
    // dynamic allocation of object creation 
  //  Jat *komal = new Jat ; 
    //komal->setLevel('A') ;
    //cout<<"power is "<<(*komal).power<<endl; // similar komal->power ; 
   // cout<<"level is "<<(*komal).getlevel()<<endl ; 
   // Jat komal(50,60 );
    //Jat Netram(komal) ; // coping constructor 
   // komal.print() ;
  //  Netram.print() ;

    // shallow copy and 
    // default copy constructor shallow copy krta h 
    // 
/*
    Jat jat1 ;
    jat1.setLevel('B');
    jat1.setpower(100);
    char name[7] = "Netram" ;
    jat1.setname(name) ;
    jat1.print() ;
    // using default copy constructor, we coping below
    // in shallow coping method we use same memory access for jat1 and jat2 also 
    Jat jat2(jat1) ;
   
    jat2.print();
    jat1.name[0] = 'k'; //by changing the jat1 the jat2 is also changed automatically 
    jat1.print() ;
    jat2.print();
*/ 
    // copy assignment operator :- jat2 = jat1 // by this all values of jat1 is copied in jat2 

   /* Jat jat1 ; // static allocation 
    Jat* jat2 = new Jat() ; // dynamic allocation 
    // for static allocation the destructor was called automatically but for dynamic we should do manually 
    delete jat2 ;*/
    cout<< Jat :: timeToComplete<<endl ; 
    Jat a ; 
    cout<< a.timeToComplete<<endl ; 
    Jat b ; 
    b.timeToComplete = 10 ; 
    cout<<b.timeToComplete<<endl ; // if we change value of static data type then it changes for whole class 
     cout<< a.timeToComplete<<endl ; 
    return 0 ; 
}


// some topics for learn :- 1. constant key-word (how to use it for object creation and which funtions we can create) 2. initilisation list 
