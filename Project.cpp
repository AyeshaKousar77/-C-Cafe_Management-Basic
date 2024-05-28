#include<iostream>
#include<ctime>  
using namespace std;
struct cafe{
	string itemsNames;
	int price;
	char itemcode; 
	int pTime; // preparation time
};
void add(cafe mine[20]);
void del(cafe mine[20]);
void update(cafe mine[20]);
void viewOrders(cafe mine[20], string order[10]);
void display(cafe mine[20]);
void search(cafe mine[20]);
void receipt(cafe mine[20], string order[10]);
int main()
{
    int enter; int orderPrice[10]; int password = 85979;
    int choiceA; int choiceC; char checking; char cancel;
	int choose; char put;  string order[10];
    cafe mine[20]={{"Pizza", 1000, 'a', 30}, {"Burger", 700, 'b', 20}, {"Pasta", 370, 'c', 35},
	 {"Arabic Roll", 380, 'd', 10}, {"Spaghetti", 420, 'e', 40}, {"Chinese Rice", 600, 'f', 45},
	{"Lasagna piece", 370, 'g', 50}, {"Sandwich", 490, 'h', 15}, {"Coffee Mug", 200, 'i', 8}, {"Orange juice", 500, 'j', 18}}; 
		 	
	cout<<"**********************************************"<<endl;
	cout<<"    ^^^Welcome to Ayesha's Cafeteria^^^       "<<endl;
	cout<<"**********************************************"<<endl;
 do{	
	cout<<"          Are you:"<<endl;
	cout<<"                   1. Manager"<<endl;
	cout<<"                   2. Customer"<<endl;
	cout<<"           Enter your choice as 1 or 2"<<endl;
	cin>>choose;
	
	if (choose == 1)
	{   
	 do{  
	    cout<<"Enter password"<<endl;
	    cin>>enter;
	    if(enter == password) 
	    {
		 cout<<"Welcome Manager"<<endl;
		 cout<<"Choose"<<endl;
		 cout<<"1. Add food items"<<endl;
		 cout<<"2. Delete an item from list"<<endl;
		 cout<<"3. Update an item in list"<<endl;
		 cout<<"4. View orders"<<endl;
		 cin>>choiceA;
		 if(choiceA == 1)
		 { 
		 	  add(mine);		
		 }
		 if(choiceA == 2)
		 {
			del(mine);
		 }
		 if(choiceA == 3)
		 {
			update(mine);
		 }
		 if(choiceA == 4)
		 {
            viewOrders(mine, order);	
		 }
       }
        else
         { 
        	cout<<"Oops! Wrong password. Try again."<<endl;
		 }
        }while(enter!= password);       
 }
	if(choose == 2)
	{
		cout<<"Brings you the best taste"<<endl;
		cout<<"Choose"<<endl;
		cout<<"1. View Menu"<<endl;
		cout<<"2. Search a food item"<<endl;
		cout<<"3. Place order"<<endl;
		cout<<"4. Get receipt"<<endl;
		cin>>choiceC;
		if(choiceC == 1)
		{
			display(mine);
		} 
		if(choiceC == 2)
		{
			 search(mine);
		}
		if(choiceC == 3)
		{
			string order[10]={"No"}; char input; string buy; 
			do{
		        cout<<"Enter your order"<<endl;
            	cin>>buy;
            	for(int i=0; i<20; i++)
            	{
            	 if(buy == mine[i].itemsNames)
            	 {
            	    checking = 'y';
				 }
			    }
				 if(checking == 'y')
				 {
				 	int x= time( 0 ) % 3600  / 60 ;
                    cout <<"Order placed at \t" <<x<<endl;  
                    cout<<"To cancel order your time limit ends at\t"<<endl;
                    cout<<"Enter c to cancel order or y to move further"<<endl;
				    cin>>cancel;
				    if(cancel == 'c')
				     {
					  int y= time( 0 ) % 3600  / 60 ;
					  if (y <= x+5)
					  { 
						cout<<"Cancelled"<<endl;
					  } 
			         }
			         else
			         {
			         	cout<<"Time out. Order can't be cancelled."<<endl;
                        for(int i=0; i<10; i++)
                        {
                	     if (order[i] == " ")
                    	 {
                		  order[i] = buy;
					     }
			            }
			         }
				}
				else
				{
					cout<<"This item is not available"<<endl;
			    }
				cout<<"If you want to order again. Press y otherwise, press n"<<endl;
            	cin>>input;
            	
			}while(input == 'y');
		}
		if(choiceC == 4)
		{
		receipt(mine, order);
		}
	}
	 cout<<"Do you want to run the system again"<<endl;
	 cin>>put;
 }while(put == 'y');
}
void add(cafe mine[20])
{
	int i = 10; char quest;
	do{
	cout<<"Enter the food item."<<endl;
    cin>>mine[i].itemsNames;
	cout<<"Enter Price."<<endl;
	cin>>mine[i].price;
	cout<<"Enter its code."<<endl;
	cin>>mine[i].itemcode;
	cout<<"Enter its preparation time in minutes."<<endl;
	cin>>mine[i].pTime;
	cout<<"Do you want to add more"<<endl;
	cin>>quest;
 }while(quest == 'y');
    i++;
} 
void del(cafe mine[20])
{
	string num; char check;
	cout<<"Enter the food item you wants to delete"<<endl;
	cin>>num;
	for(int i=0; i<20; i++)
	{
	 if(num == mine[i].itemsNames )
	 {
	  mine[i].itemsNames = "N";
	  mine[i].price = 0;
	  mine[i].itemcode = 0;
	  mine[i].pTime = 0;
	  check = 'y';
     }
    } 
     if(check == 'y')
     {
       cout<<"deleted"<<endl;
	 }
	 else
     {
		cout<<"Item is not present in list"<<endl;
	 }
}
void update(cafe mine[20])
{   
    string no; char see; int num;
	cout<<"Enter the food item you wants to change"<<endl;
	cin>>no;
	for(int i=0; i<20; i++)
	{
	 if(no == mine[i].itemsNames )
	 {
	  see = 'y';
	   i = num;
     }
	}
     if (see = 'y')
     {	
      	 cout<<"Enter the new food item"<<endl;
	     cin>>mine[num].itemsNames;
	     cout<<"Enter it's price"<<endl;
	     cin>>mine[num].price;
	     cout<<"Enter it's code"<<endl;
	     cin>>mine[num].itemcode;
	     cout<<"Enter it's preparation time in minutes."<<endl;
	     cin>>mine[num].pTime;
	     cout<<"UPDATED"<<endl;
	 }
     else
     {
     	cout<<"This item is not in list"<<endl;
	 } 
}
void viewOrders(cafe mine[20], string order[10])
{
	int orderPrice[10]={0};
         int timing[10]; int cd[10];
		 for(int j=0; j<20; j++)
		 {	
		   for(int i=0; i<10; i++)
		   {
		 	if(order[i] == mine[j].itemsNames)
		 	{
		 		orderPrice[i] = mine[j].price;
		 		timing[i] = mine[j].pTime;
		 		cd[i]= mine[j].itemcode;
			}
		   }
	     }
	 cout<<"Items purchased by customer:"<<endl;
		 for(int i=0; i<10; i++)
		 {
		 	if(order[i] == " ")
		 	{
		 		cout<<"N/A"<<endl;
		    }
		    else
		 	{
		     cout<<cd[i]<<" Item: "<<order[i]<<" Price: "<<orderPrice[i]<<endl;
			 cout<<"Preparation Time: "<<timing[i]<<endl;	
		    }   	
		 }
}
void display(cafe mine[20])
{
	cout<<"               ***Menu***  "<<endl;
	for(int i=0; i<20; i++)
	{
		cout<<"_________________________________________________________________________________"<<endl;
		cout<<mine[i].itemcode<<" Item "<<mine[i].itemsNames<<"   \t\t\tPrice: "<<mine[i].price<<"    Preparation Time "<<mine[i].pTime <<endl;
	
	}
}
void search(cafe mine[20])
{
	string srch; string item; char ans; int n;
	cout<<"Search a food item"<<endl;
	cin>>srch;
	for(int i=0; i<20; i++)
	{
		if(srch == mine[i].itemsNames)
		{
			ans = 'y';
			i = n;
		  mine[i].itemsNames = item;
		}
	}
	if(ans= 'y')
	{
	 cout<<"Available "<<endl;
	 cout<<mine[n].itemcode<<" Item: "<<mine[n].itemsNames<<endl;
	 cout<<"Price: "<<mine[n].price<<endl;
	 cout<<"Preparation time: "<<mine[n].pTime<<endl;
	}
	else
	{
    	cout<<"This item is not available"<<endl;
	}
}
void receipt(cafe mine[20], string order[10])
{	     int orderPrice[10]={0};
         int timing[10]; int cd[10];
         cout<<"Ayesha's Cafe"<<endl;
         cout<<"Brings you the best taste"<<endl;
		 for(int j=0; j<20; j++)
		 {	
		   for(int i=0; i<10; i++)
		   {
		 	if(order[i] == mine[j].itemsNames)
		 	{
		 		orderPrice[i] = mine[j].price;
		 		timing[i] = mine[j].pTime;
		 		cd[i]= mine[j].itemcode;
			}
		   }
	     }
	 cout<<"Items purchased:"<<endl;
		 for(int i=0; i<10; i++)
		 {
		 	if(order[i] == " ")
		 	{
		 		cout<<"N/A"<<endl;
		    }
		    else
		 	{
		     cout<<cd[i]<<" Item: "<<order[i]<<" Price: "<<orderPrice[i]<<endl;
			 cout<<"Preparation Time: "<<timing[i]<<endl;	
		    }   	
		 }
		 	cout<<"Thanks For Coming"<<endl;
}
