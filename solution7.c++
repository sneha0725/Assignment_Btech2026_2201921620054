#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static int count_professor = 0 , count_student = 0;

class Person{
    protected:
        string name;
        int age , cur_id;
    public:
        virtual void getdata() = 0;
        virtual void putdata() = 0;
};

class Professor : public Person{
    private:
        int publications;
    public:
        void getdata(){
            cin>>name;
            cin>>age;
            cin>>publications;
            cur_id = ++(::count_professor);
        }
        void putdata(){
            cout<<name<<" "<<age<<" "<<publications<<" "<<cur_id<<endl;
        }
};
class Student : public Person{
    private:
        int marks;
    public:
        void getdata(){
            cin>>name;
            cin>>age;
            int temp;
            marks = 0;
            for(int i = 0; i < 6;i++){   
                cin>>temp;
                marks += temp;
            }
            cur_id = ++(::count_student);
        }
        void putdata(){
            cout<<name<<" "<<age<<" "<<marks<<" "<<cur_id<<endl;
        }
};
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
