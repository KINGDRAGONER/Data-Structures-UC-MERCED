#include <bits/types/time_t.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;

struct Person{
    string name;
    int time;
    Person(){
        name = "Generic";
        time =0; 
    }
    Person(string name, int time){
        this->name=name;
        this->time =time;
    }
}person;

/*std::ostream& operator <<(std::ostream& os,Person&person){
    os<<person.name<<" : " <<person.time;
    return os;
} */
int main(){

    int jobCount;
    Queue<int> times;
    Queue<string> names;
    Queue<Person> people;
    cin >> jobCount;

    for (int i = 0; i < jobCount; i++){
        string name;
        int time;
        cin >> name;
        person.name = name;
        //names.enqueue(name);
        cin >> time;
        person.time = time;
        //times.enqueue(time);

        people.enqueue(Person(name,time));

        cout << person.name << " : " << person.time << endl;
    }

    int period;
    cin >> period;
    // Output round robin schedule, where person can use machine for no longer than the set period
    while(people.length()>0){
        person = people.peek();
        if(person.time>period){
            people.enqueue(Person(person.name, person.time-period));
            person.time = period;
            
        }
        
        people.dequeue();
        cout<<person.name<<" : "<<person.time<<endl;
    }
    cout << "Done..." << endl;

    return 0;
}