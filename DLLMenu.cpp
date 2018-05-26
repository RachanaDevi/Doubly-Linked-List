#include<iostream>
#include<stdio.h>
using namespace std;
class node
{
	int info;
	node *next,*prev;
	
	public:
	
		node(int n)
		{
			info=n;
			next=prev=NULL;
		}
		int flag;
	
	    friend class list;
}*ptr,*newptr;

class list
{
	node *start;
	public:
		list()
		{
		start=NULL;
		}
		void create();
		int search(int n);
		node *insert();
		void display();
	    list concat(list);
	    void copy(list);
	    list sort();
	    void del();
	    void uni(list);
	    void intersection(list);
	    bool present(int);
	    void merge(list);
	    list reverse();
	    bool exists();
	   
		
};

bool list::exists()
{
	if(start==NULL)
	return false;
	
	return true;
}
void list::create()
{
	int no,i,val;
	node *newnode,*temp;
	cout<<"\nEnter the no of nodes";
	cin>>no;
	cout<<"\nEnter the value:\n";
	for(i=0;i<no;i++)
	{
	  cin>>val;
	  newnode=new node(val);
	  if(start==NULL)
	  {
	  	start=temp=newnode;
	  	
	  }
	  else
	  {
	  	temp->next=newnode;
	  	newnode->prev=temp;
	  	temp=temp->next;
	  }
	}
}
node* list::insert()
{  
   node *temp;
   int ch,inf;
   do
   
   {
   system("cls");
   cout<<"\nEnter your choice\n1.Insert At Beginning\n2.Insert at End\n3.Insert At Middle\n";
   cin>>ch;
   cout<<"\nEnter the info:";
   cin>>inf;
   newptr=new node(inf);
   switch(ch)
   {

	
	case 1:
	if(start==NULL)
	{
		start=temp=newptr;
	}
	else
	{
		newptr->next=start;
		start->prev=newptr;
		start=newptr;
	}
	break;
	
	case 2:
		if(start==NULL)
	{
		start=temp=newptr;
	}
	else
	{
	  
	
	  temp=start;
		while(temp->next!=NULL)
		{
		    temp=temp->next;
	    }
		
		temp->next=newptr;
		newptr->prev=temp;
	}
	break;
	
	case 3:
	if(start==NULL)
	{
		start=newptr;
	}
	else
	{
		int no;
		display();
		cout<<"Enter the number after which you want to insert:";
		cin>>no;
		temp=start;
		while(temp!=NULL&& temp->info!=no )
		{
			temp=temp->next;
		}
		if(temp==NULL)
		{
			cout<<"\nELEMENT NOT FOUND";
			break;
		}
		newptr->next=temp->next;
		newptr->prev=temp;
		temp->next=newptr;
	
	}
	break;
}
cout<<"\nDo you want to insert more(1=yes)?\n";
cin>>ch;
}while(ch==1);

}



void list::del()
{
	int ch;

   
   node *temp;
   do
   {
   	system("cls");
   cout<<"\nEnter your choice\n1.Delete at beginning\n2.Delete at End\n3.Delete At Middle\n";
   cin>>ch;

   switch(ch)
   {
  case 1:
	if(start==NULL)
	{
	   cout<<"\nUNDERFLOW!!";
	   break;
	}
	else
	{
		temp=start;
		start=temp->next;
		temp->prev=NULL;
		delete temp;
	}
	break;
	
	case 2:
		if(start==NULL)
	{ 
	   cout<<"\nUNDERFLOW!!";
	   break;
		
	}
	else
	{
		node *temp1;
	
		temp=start;
		while(temp->next!=NULL)
		{
		
		    temp=temp->next;
	    }
		temp->prev->next=temp->next;
		 delete temp;
	}
	break;
	
	case 3:
	if(start==NULL)
	{
		cout<<"\nUNDERFLOW!!";
	}
	else
	{
		int no;
		cout<<"Enter the number you want to delete:";
		cin>>no;
		temp=start;
		while(temp!=NULL &&temp->info!=no  )
		{
			temp=temp->next;
		}
		if(temp==NULL)
		{
			cout<<"\nELEMENT NOT FOUND";
			break;
		}
		temp->prev->next=temp->next;	
		temp->next->prev=temp->prev;
	}
	break;
}	
cout<<"\nDo you want to delete more(1=yes)?\n";
cin>>ch;
}while(ch==1);
}
void list::display()
{ 

 node *temp=start;
 while(temp!=NULL)
 {
 	cout<<temp->info<<"->";
 	temp=temp->next;
 }
 cout<<endl;
  
}
void list::merge(list l2)
{
	list lAns;
	cout<<"\nFirst list contents:\n";
	sort();
	cout<<"\nSecond list contents:\n";
	l2.sort();
	node *newnode;
    node *temp1=start;
    node *temp2=l2.start;
    node *temp3;
 while((temp1!=NULL)&&(temp2!=NULL))
 {

 	if(temp1->info>=temp2->info)
	 	{
	 		newnode=new node(temp1->info);
	 	  if(lAns.start==NULL)
		   {
		   	lAns.start=temp3=newnode;
		   }
		   else
		   {
		   	  temp3->next=newnode;
		   	  newnode->prev=temp3;
		   	  temp3=temp3->next; 
		   	  
		   }
		   temp1=temp1->next;
	    }
					   else 
					   {
					   	
					   	  newnode=new node(temp2->info);
				 	       if(lAns.start==NULL)
					      {
					      	lAns.start=temp3=newnode;
					       }
					   	else
					    {
					   	  temp3->next=newnode;
					   	  newnode->prev=temp3;
					   	  temp3=temp3->next;
					   	  
					     }
					     temp2=temp2->next;
					   }
	   
	}
	while(temp1!=NULL)
	{
		newnode=new node(temp1->info);
		temp3->next=newnode;
		newnode->prev=temp3;
		temp3=temp3->next;
		temp1=temp1->next;
	}
	while(temp2!=NULL)
	{
		newnode=new node(temp2->info);
		temp3->next=newnode;
		newnode->prev=temp3;
		temp3=temp3->next;
		temp2=temp2->next;
	}
  cout<<"\nThe merged list is:\n";
  lAns.display();
  	
 }
 


void list::copy(list l1)
{
	
	node*temp=l1.start;
	node *temp1;
	while(temp!=NULL)
	{
       newptr=new node(temp->info);
       if(start==NULL)
       {
       	start=temp1=newptr;
	   }
	   else
	   {
	   	 temp1->next=newptr;
	   	 newptr->prev=temp1;
	   	 temp1=temp1->next;

	   }
       temp=temp->next;
      }
     
}

list list::concat(list l2)  //l1 and l2
{   list lCopy; //Concatenated list
    lCopy.copy(*this);//copying l1
    node *temp;
	temp=lCopy.start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=l2.start;
	l2.start->prev=temp;

   lCopy.display();
}



void list:: uni(list l1)
{
	list l2;node *t2;
	node *t=l1.start;
	while(t!=NULL)
	{
		node *newnode=new node(t->info);
		
	
		if(!l2.present(t->info))
		{
		
		if(l2.start==NULL)
		 {
		 	l2.start=t2=newnode;
		 }
		 else
		 {
		
			 
		 	t2->next=newnode;
		 	newnode->prev=t2;
		 	t2=t2->next;
		  
		 }
		 
     	}
		
		 t=t->next;

	}
	t=start;
	while(t!=NULL)
    {
    	if(!l2.present(t->info))
    	{
    		node *newnode=new node(t->info);
    		t2->next=newnode;
    		t2=t2->next;
		}
		t=t->next;
	}
	
	l2.display();

}

void list:: intersection(list l)
{
	node *temp=l.start;
	list l1;
	node *t,*t2;
	while(temp!=NULL)
	{
		if(present(temp->info))
		{
			node *newnode=new node(temp->info);
		 if(!l1.present(temp->info))
		 {
			
			if(l1.start==NULL)
		    {
		    	l1.start=t2=newnode;
		    	
			}
			else
			{
				t2->next=newnode;
				newnode->prev=t2;
				t2=t2->next;
			}
		  }
		}
		temp=temp->next;
	}
	l1.display();
}
bool list::present(int data)
{
	node *t=start;
	while(t!=NULL)
	{
		if(t->info==data)
		return 1;
		t=t->next;
	}
	return 0;
}

list list ::sort()
{
	node *temp=start;
	int data;
	node *temp1;
	while(temp!=NULL)
	{
		temp1=temp->next;
		while(temp1!=NULL)
		{
			if(temp->info<=temp1->info)
			{
				data=temp->info;
				temp->info=temp1->info;
				temp1->info=data;
			}
			temp1=temp1->next;
			
		}
		temp=temp->next;
		
	}
	display();
}
int list::search(int n)
{
	int i=1;
	node *temp;
	temp=start;
	while(temp!=NULL)
	{
		if(temp->info==n)
		return(i);
		
		i++;
		temp=temp->next;
	}
	return 0;
}

list list ::reverse()
{
	
	node *temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
	
	cout<<temp->info<<"->";
 	temp=temp->prev;
		
	}	

}
	



int main()
{
	
	list l[10],lCon;
	int ch,i,j,flag=0,data;
	do
	{
	system("cls");
	cout<<"\n*****************************MENU********************************\n";
	cout<<"\n1.Create List\n2.Insert\n3.Delete\n4.Display\n5.Concatenate\n6.Merge\n7.Union \n8.Intersection\n9.Reverse\n10.Search";
	cin>>ch;
	switch(ch)
	{
			case 1:cout<<"\nSelect your list:";
		       cin>>i;
		       if(!l[i].exists()&&i<10)
		       l[i].create();
		       else
		       {
		       	if(l[i].exists())
		       	cout<<"\nList already exists";
		       	else
		       	cout<<"\nEnter list between 0 and 9";
			   }
		break;
		
		case 2:
			  cout<<"\nEnter the list";
			  cin>>i;
			  
			  if(l[i].exists()&&i<10) 
				{
				
		       l[i].insert();
				
				}
				else
				{
					 cout<<"\nThe list does not exist";
				}
	
			  
		      
		      
		break;
		
		case 3:
			 cout<<"\nEnter the list";
			  cin>>i;
			  if(l[i].exists()&&i<10) 
				{
			
		       l[i].del();
				
				}
				else
				{
					 cout<<"\nThe list does not exist";
				}
		       
		       
		break;
		
		case 4:cout<<"\nSelect your list:";
		       cin>>i;
		        if(l[i].exists()&&i<10) 
				{
			      l[i].display(); 
				
				}
				else
				{
					 cout<<"\nThe list does not exist";
				}
		      
	    break;
		
		case 5:	
			cout<<"\nEnter the two lists who you want to concatenate:";
		        cin>>i>>j;
				if((l[i].exists()) && (l[j].exists()) && i<10 && j<10)
				{
					
		             l[i].concat(l[j]);  
		             
				}
				else
				{
					 cout<<"\nOne of the list does not exist";
				}
		       
		        
		break;
		
		case 6:
			cout<<"\nEnter the two lists who you want to merge:";
		        cin>>i>>j;
				if((l[i].exists()) && (l[j].exists()) && i<10 && j<10)
				{
					l[i].merge(l[j]);
				
				}
				else
				{
					 cout<<"\nOne of the list does not exist";
				}
		       
		break;		    
		
		case 7:
			cout<<"\nEnter the two lists who you want to union of:\n";
		        cin>>i>>j;
				if((l[i].exists()) && (l[j].exists()) && i<10 && j<10)
				{
				l[i].uni(l[j]);
				}
				else
				{
					 cout<<"\nOne of the list does not exist";
				}
		break;
		
		case 8:
		     	cout<<"\nEnter the two lists who you want to union of:\n";
		        cin>>i>>j;
				if((l[i].exists()) && (l[j].exists()) && i<10 && j<10)
				{
			     l[i].intersection(l[j]);
				}
				else
				{
					 cout<<"\nOne of the list does not exist";
				}
			  
		break;   
			
	    case 9:
	    	 cout<<"\nEnter which list you want to reverse ";
	    	 cin>>i;
	    	  if(l[i].exists() && i<10) 
				{
			      l[i].reverse();
				
				}
				else
				{
					 cout<<"\nOne of the list does not exist";
				}
		      
	    	 
	    break;	 
	   	case 10: cout<<"\nEnter which list in which you want to search :";
	    	    cin>>i;
	    	     if(l[i].exists()&& i<10) 
				{
			    cout<<"\nEnter the element you want to search?";
	    	    cin>>data;
	    	    int res=l[i].search(data);
				if(res!=0)
				cout<<"\nElement found at "<<res;
				else
				cout<<"\nElement not found";
				}
				else
				{
					 cout<<"\nOne of the list does not exist";
			    }
		break;		 
			
	}
cout<<"\nDo you want to go to menu again(1=yes)?";
cin>>ch;	
}while(ch==1);

}
