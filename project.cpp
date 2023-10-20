#include<iostream>
#include<cstring>
using namespace std;
class Node{
public:
    char ch;
    Node *next;
    Node(char c){
        ch=c;
        next=NULL;
    }
};
class SLL{
public:
    Node *head=NULL;
    void destinations(){
    Node *d0 = new Node('E');
    Node *d1 = new Node('D');
    Node *d2 = new Node('C');
    Node *d3 = new Node('B');
    Node *d4 = new Node('A');
    d0->next=NULL;
    d1->next=d0;
    d2->next=d1;
    d3->next=d2;
    d4->next=d3;
    head=d4;
}
void printDestination(){
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<"\t\tPlace Name: "<<temp->ch<<endl;
        temp=temp->next;
    }
    cout<<endl<<endl;
}
};
class stackNode{
public:
    string name;
    string destination;
    string time;
    int bogies_numbers;
    int seat_numbers;
    int bogies_seat [100][100];
    int total_seat;
    int first_class_total_seats;
    int second_class_total_seats;
    int third_class_total_seats;
    stackNode *next;
    stackNode(string d,string n,string t,int bogies_num,int first_class_seats,int second_class_seats,int third_class_seats){
        destination=d;
        name=n;
        time=t;
        bogies_numbers=bogies_num;
        seat_numbers=10;
        total_seat=bogies_numbers*seat_numbers*2;
        first_class_total_seats=first_class_seats;
        second_class_total_seats=second_class_seats;
        third_class_total_seats=third_class_seats;
        for(int i=0;i<bogies_numbers;i++){
       for(int j=0;j<10;j++){
            bogies_seat[i][j]=2;
          }
        }
        next=NULL;
    }
};
class queueNode{
public:
    string name;
    int age;
    string trainName;
    string destination;
    string time;
    int bogie_number;
    int cls;
    int seat_number;
    queueNode *next;
    queueNode(string nam,int ag,string trainNam,string dest,string t,int clas,int bogi_num,int seat_n){
        name=nam;
        age=ag;
        trainName=trainNam;
        destination=dest;
        time=t;
        cls=clas;
        bogie_number=bogi_num;
        seat_number=seat_n;
        next=NULL;
    }
};

class stacks{
public:
    stackNode *top;

    void traindetails(){
        top=NULL;
        stackNode *n14 = new stackNode("D-E","Rupsha","3:00pm",6,20,40,60);
        stackNode *n13 = new stackNode("C-D","Ekota","4:00pm",7,20,40,80);
        stackNode *n12 = new stackNode("B-C","Provati","9:00am",6,20,40,60);
        stackNode *n11 = new stackNode("A-B","Mohanogor","10:00am",6,20,40,60);
        stackNode *n1 = new stackNode("D-E","Shuborna","10:00am",5,20,40,40);
        stackNode *n2 = new stackNode("C-D","Jamuna","10:00am",6,20,40,60);
        stackNode *n3 = new stackNode("B-C","Tista","3:00pm",7,20,40,80);
        stackNode *n4 = new stackNode("A-B","Shuprovat","4:00pm",8,20,40,80);
        n4->next=n11;
        n3->next=n12;
        n2->next=n13;
        n1->next=n14;
        n11->next=n3;
        n12->next=n2;
        n13->next=n1;
        n14->next=NULL;
        top=n4;
    }

    stackNode *pop(){
        if(top==0){
        return 0;
    }
        stackNode *t;
        t=top;
        top=top->next;
        return t;
    }

    void printTrainDetails(){
        stackNode *s=top;
        cout<<"\t\t\t\t~TRAIN DETAILS~"<<endl;
        while(s!=0)
        {
        //cout<<"s";
            cout<<"\t\t\tTrain Name: "<<s->name<<endl;
            cout<<"\t\t\tTrain Destination: "<<s->destination<<endl;
            cout<<"\t\t\tTime: "<<s->time<<endl;
            cout<<"\t\t\tTotal Seats: "<<s->total_seat<<endl;
            cout<<"\t\t\tFirst class total seats: "<<s->first_class_total_seats<<endl;
            cout<<"\t\t\tSecond class total seats: "<<s->second_class_total_seats<<endl;
            cout<<"\t\t\tThird class total seats: "<<s->third_class_total_seats<<endl;
            cout<<endl<<endl;
            s=s->next;
        }
    }
    stackNode *coustomer_certain_train(string trainName){
        stackNode *temp=top;
        while(temp!=0){
            if(temp->name==trainName){
                return temp;
            }
            temp=temp->next;
        }
    }
    void availableTrains(string des){
     stackNode *temp=top;
     cout<<"\t\t\t\t~Available trains for this destination~"<<endl;
     while(temp!=NULL)
     {
         if(temp->destination==des)
         {
             cout<<"\t\t\tTrain Name: "<<temp->name<<endl;
             cout<<"\t\t\tStarting Time: "<<temp->time<<endl;
             cout<<"\t\t\tTotal Seats: "<<temp->total_seat<<endl;
             cout<<"\t\t\tFirst Class Seats: "<<temp->first_class_total_seats<<endl;
             cout<<"\t\t\tSecond Class Seats: "<<temp->second_class_total_seats<<endl;
             cout<<"\t\t\tThird Class Seats: "<<temp->third_class_total_seats<<endl;
         }
         temp=temp->next;
     }
 }
};
class Queue{
public:
    stacks s;
    queueNode *front=NULL;
    void reservedticket(string nam,int ag,string trainNam,string dest,string t,int clas,int bogi_num,int seat_n){
        queueNode *temp = new queueNode(nam,ag,trainNam,dest,t,clas,bogi_num,seat_n);
        if(front==NULL){
            front=temp;
        }
        else{
            queueNode *t=front;
            while(t->next!=NULL){
                t=t->next;
            }
            t->next=temp;
        }
    }
    void printCoustomerDetails(){
     queueNode* temp=front;
     if(temp==0){
        cout<<"\n\t\t~No ticket is sold.~"<<endl;
     }
     while(temp!=0){
         cout<<"\t\t\tName: "<<temp->name<<endl;
         cout<<"\t\t\tAge: "<<temp->age<<endl;
         cout<<"\t\t\tTrain Name: "<<temp->trainName<<endl;
         cout<<"\t\t\tTime: "<<temp->time<<endl;
         cout<<"\t\t\tDestination: "<<temp->destination<<endl;
         cout<<"\t\t\tBogie Number: "<<temp->bogie_number<<endl;
         cout<<"\t\t\tSeat Number: "<<temp->seat_number<<endl;
         temp=temp->next;
        }
    }
    void viewTicket(string n,string tn,string t){
     if(front==NULL){
        cout<<"No ticket is purchased."<<endl;
        }
     else{
        queueNode *temp=front;
        while(temp!=NULL){
            if(temp->name==n && temp->trainName==tn && temp->time==t){
                cout<<"\t\t\tName: "<<temp->name<<endl;
                cout<<"\t\t\tAge: "<<temp->age<<endl;
                cout<<"\t\t\tTrain Name: "<<temp->trainName<<endl;
                cout<<"\t\t\tTime: "<<temp->time<<endl;
                cout<<"\t\t\tDestination: "<<temp->destination<<endl;
                cout<<"\t\t\tSeat Number: "<<temp->seat_number<<endl;
            }
            temp=temp->next;
        }
    }
 }
};

int main()
{
    int flag2=1,i=0,j=0;
    stacks st;
    SLL sl;
    Queue q;
    cout<<"\t\t\t\t----------------------------------------\n";
    cout<<"\t\t\t\t\tTICKET RESERVATION SYSTEM\t\t\t\t\t";
    cout<<"\t\t\t\t\t\t\t    -   WELCOME   -\t\t\t\t\t\n";
    cout<<"\t\t\t\t----------------------------------------\n";
    sl.destinations();
    st.traindetails();
   while(1){
        cout<<"\n\n\t\t******* For Admin *******\t\t\t******* For Customer *******\n";
        cout<<"\n\n\n\t\t1.All Railway Platforms\t\t\t\t  4.Reserve a Ticket \n\n\t\t2. All Train Details\t\t\t\t  5.View Ticket   \n\n\t\t3.Train Tickets Sold\n";


    printf("\n\n\t\tEnter a number from the option: ");
    int ch;
    cin>>ch;
    if(ch==1){
        int c;
        cout<<"\t\tEnter Admin Code:";
        cin>>c;
        if(c==950)
        sl.printDestination();
    }
    else if(ch==2){
        int c;
        cout<<"\t\tEnter Admin Code:";
        cin>>c;
        if(c==950){
            st.printTrainDetails();
        }
    }
    else if(ch==3){
       int c;
       cout<<"\t\tEnter Admin Code:";
       cin>>c;
       if(c==950)
       q.printCoustomerDetails();
    }
    else if(ch==4){
        cout<<"\t\tName:";
        string name;
        cin>>name;

        cout<<"\t\tAge:";
        int age;
        cin>>age;

        cout<<"\t\tChoose a Destination (Type Full text):";
        cout<<"\n\t\t1.A-B";
        cout<<"\n\t\t2.B-C";
        cout<<"\n\t\t3.C-D";
        cout<<"\n\t\t4.D-E\n\n\t\t";
        string choice;
        cin>>choice;

        st.availableTrains(choice);
        cout<<"\n\t\tInput Train Name:";
        string train_name;
        cin>>train_name;
        stackNode *temp;
        temp=st.coustomer_certain_train(train_name);

        int clas;
        cout<<"\n\t\tClass: (Press 1::First class  Press 2::Second class  Press 3::Third class)\n";
        cout<<"\n\t\t";
        cin>>clas;
        if(clas==1){
                  while(i<10){
                       if(temp->bogies_seat[0][i]!=0){
                         q.reservedticket(name,age,train_name,choice,temp->time,clas,0,i);
                         temp->bogies_seat[0][i]--;
                         temp->total_seat--;
                         temp->first_class_total_seats--;
                         flag2=0;
                         i++;
                         break;
                       }
                    }
                }
                else if(clas=2){
                    for(i=1;i<3;i++){
                        for(j=0;j<10;j++){
                         if(temp->bogies_seat[i][j]!=0){
                            q.reservedticket(name,age,train_name,choice,temp->time,clas,i,j);
                            temp->bogies_seat[i][j]--;
                            temp->second_class_total_seats--;
                            temp->total_seat--;
                            flag2=0;
                            break;
                        }
                        if(flag2==0)break;
                    }
                }
                }
                else{
                    for(i=3;i<temp->total_seat;i++){
                        for(j=0;j<10;j++){
                            if(temp->bogies_seat[i][j]!=0){
                                q.reservedticket(name,age,train_name,choice,temp->time,clas,i,j);
                                temp->bogies_seat[i][j]--;
                                temp->third_class_total_seats--;
                                temp->total_seat--;
                                flag2=0;
                                break;}
                        }
                        if(flag2==0)break;
                    }
                }

       if(flag2==0){
            cout<<"\t\t\\\\\\\\\\\\\\\\\\\\\Ticket Sold////////////////////////\n";
       }
       else{
            cout<<"\t\t\\\\\\\\\\\\\\\\\\\\\No ticket availabe for this class////////////////////////\n";
       }
    }

    else if(ch==5)
    {
        cout<<"Enter name: ";
        string name;
        cin>>name;
        cout<<"Enter Train Name: ";
        string trainn;
        cin>>trainn;
        cout<<"Enter time: ";
        string time;
        cin>>time;
        q.viewTicket(name,trainn,time);
    }
    /*else if(ch==6){
        cout<<"Enter Name:";
        string name;
        cin>>name;

        cout<<"Enter Age:";
        int age;
        cin>>age;
        q.cancelticket(name,age);
               printf("\n>>>>>>>Ticket Canceled.<<<<<<<<\n");
        }*/
        else{
            break;
        }
    }

return 0;
}
