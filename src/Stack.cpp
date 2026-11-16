#include "Stack.h"

int Stack::activeStacksCount=0;

int Stack :: getactiveStacksCount(){
           // LOG(this->top);//Compiler Error Unabialable for Static memberFunction
            return activeStacksCount;
}
Stack::Stack()
{
    activeStacksCount++;
    LOG("No Parameter Constructor Stack()");
    this->sizeArray=10;
    this->top=-1;
    this->employees=new Employee[sizeArray];
    //ctor
}
Stack::Stack(Stack & s)
{
    activeStacksCount++;
    LOG("Copy Constructor :: ");
    this->employees=new Employee[s.sizeArray];
    this->sizeArray=s.sizeArray;
    this->top=s.top;
    for(int i=0; i<=top; i++){
            this->employees[i]=s.employees[i];
    }

}
Stack::Stack(int sizeArray)
{
    activeStacksCount++;
    LOG("Parameter Constructor Stack()");
    this->sizeArray=sizeArray;
    this->top=-1;
    this->employees=new Employee[sizeArray];
    //ctor
}
void Stack:: push(Employee e){
  // 5 employees push() push()   push() push() push()
   if(top >= sizeArray -1){//5
        LOG("Stack is FUll");
        return ; //Early Exit
   }
   top++;   //0        1        2      3      4
   LOG("We Write index :"<< top );
   employees[top]=e;
}
int Stack::pop(Employee * e){
    if(top == -1){
        //LOG("Stack Empty");
        return 0;
        //return ??
    }
    *e=employees[top];
    employees[top]=Employee();
    //LOG("Before POP"<<top);
    top--;
    //LOG("After POP"<<top);
    return 1;
}
void Stack:: display(void){
   for(int i=top; i>=0; i--){
        LOG(employees[i].name<<"--->");
        LOG(employees[i].age<<"--->");
        LOG(employees[i].department<<"--->");
        LOG(employees[i].salary<<"--->");
   }
}
Stack & Stack:: operator=(const Stack  s){
LOG("Assgiment Operator :: ");
delete [] this->employees;
employees=new Employee[s.sizeArray];
this->sizeArray=s.sizeArray;
this->top=s.top;
for(int i=0; i<=top; i++){
        this->employees[i]=s.employees[i];
}
return *this;

}

Stack::~Stack()
{
    LOG("Destructor");
    activeStacksCount--;
    delete []employees;
    //dtor
}
