/******************************************************************************
                    ASMA
                         ~A technology that leaps to the sky

Problem Statement:
To simulate the functions of a television control device on an interactive console
using data structures and algorithms.

*******************************************************************************/

#include <iostream>
using namespace std;

 /*ChannelNode is a blueprint for any channel created i.e, all the details of a particular channel */
class ChannelNode        
{
    public:              
    int channel_no;                 //variable to store the channel no
    string channel_name;           //variable to store channel name
    string channel_genre;         //variable to store channel genre
    float channel_price;         //variable to store channel Price
    ChannelNode *prev;          //variable to store previous channel link
    ChannelNode *next;         //variable to store next channel link
    
    //Constructor to intialise the variables to default values
    ChannelNode()
    {
        channel_no=0;
        channel_name="";
        channel_genre="";
        channel_price=0.0;
        prev=NULL;
        next=NULL;
    }
    
    //Constructor to initialise variables to custom value
    ChannelNode(int ch_no,string ch_name,string ch_genre,float ch_price) 
    {
        channel_no=ch_no;
        channel_name=ch_name;
        channel_genre=ch_genre;
        channel_price=ch_price;
        prev=NULL;
        next=NULL;
        
    }
    friend class Channel_dcll;
    friend class Stack;
    friend class Menu_Operations;
};
/*__________________________End of ChannelNode class_________________________*/

/*Channel_dcll class enables the operations of a Doubly Circular Linked List*/
class Channel_dcll  
{
    public:
    ChannelNode *head;      //head is a ChannelNode that points to the first node of any dcll created
    
    //default Constructor
    Channel_dcll()          
    {
        head=NULL;
    }
    
    //Boolean function to check if the list is empty
    bool isEmpty()       
    {
        return head==NULL;
    }
    //end of isEmpty() function
    
    //Function to add channels to the list
    void create(int ch_no,string ch_name,string ch_genre,float ch_price)
    {
        ChannelNode *newChannel=new ChannelNode(ch_no,ch_name,ch_genre,ch_price);       //creation of new channel
        
        if(head==NULL)      //if list is empty     
        {
            newChannel->prev=newChannel;
            newChannel->next=newChannel;
            head=newChannel;
            
        }
        else            //else if list is not empty
        {
            newChannel->next=head;
            newChannel->prev=head->prev;
            (head->prev)->next=newChannel;
            head->prev=newChannel;
        }
    } //end of create function
    
     //Function to display the list
    void displayAllChannels(int flag)   //flag to differentiate between types of details to printed
    {
        //if list is empty
        if(head==NULL)
            cout<<"\n\n\t\t***NO CHANNELS ADDED TO THE PACKAGE***"<<endl;
            
        //if list is not empty
        else
        {
        ChannelNode *ptr=head;
        
            //display template cases other than create package 
            if(flag==0)
            {
                cout<<" --------------------------------------------------------"<<endl;
                cout<<"   Channel Number\t |      \tChannel Name"<<endl;
                cout<<" --------------------------------------------------------"<<endl;
                cout<<"\t"<<ptr->channel_no<<"\t         |       \t"<<ptr->channel_name<<endl;      //display head node
                cout<<" --------------------------------------------------------"<<endl;
            }
            
            //display template cases of create package 
            else
            {
                cout<<" ----------------------------------------------------------------------------------------------"<<endl;
                cout<<"   Channel Number\t |     \t  Channel Price\t         |    \tChannel Name( Genre )"<<endl;
                cout<<" ----------------------------------------------------------------------------------------------"<<endl;
                cout<<"\t"<<ptr->channel_no<<"\t         |       \t"<<ptr->channel_price<<"\t         |     \t"<<ptr->channel_name<<" ( "<<ptr->channel_genre<<" )"<<endl;      //display head node
                cout<<" ----------------------------------------------------------------------------------------------"<<endl;
            }
            
    
            ptr=ptr->next;
            while(ptr!=head)
            {
                //display template cases other than create package 
                if(flag==0)
                {
                    cout<<"\t"<<ptr->channel_no<<"\t         |       \t"<<ptr->channel_name<<endl;      //display all other elements of the list
                    cout<<" --------------------------------------------------------"<<endl;
                }
                
                //display template cases of create package   
                else    
                {
                    cout<<"\t"<<ptr->channel_no<<"\t         |       \t"<<ptr->channel_price<<"\t         |     \t"<<ptr->channel_name<<" ( "<<ptr->channel_genre<<" )"<<endl;      //display all other elements of the list
                    cout<<" ----------------------------------------------------------------------------------------------"<<endl;
                }
                    
                ptr=ptr->next;
            }
        }
    }//End of displayAllChannels function
    
    //Function to remove a channel
    int removeChannel(ChannelNode *chToRemove)
    {
        int sucess=0;   //variable to check if removal of channel was successful
     
        //If head removal is desired & it is the only element present
        if(head->next==head && (head->channel_no==chToRemove->channel_no))
        {
            head=NULL;
            sucess=1;
            cout<<"*** "<<chToRemove->channel_no<<" Removed from the package***"<<endl;
            
        }
        //If head removal is desired & there are multiple elements present in the list
        else if(head->channel_no==chToRemove->channel_no)
            {
                (head->prev)->next=head->next;
                (head->next)->prev=head->prev;
                 head=head->next;
                 cout<<"*** "<<chToRemove->channel_no<<" Removed from the package***"<<endl;
                 sucess =1;
            }
            
        //Else to remove elements other than head node
         else
         {
             ChannelNode *temp=head->next;
             while(temp!=head && temp->channel_no!=chToRemove->channel_no)
             {
                 temp=temp->next;
             }
             //If channel to be deleted is not found
             if(temp==head)     
                 cout<<"*** This Channel is not present in the package ***"<<endl;
             else
             {
                (temp->prev)->next=temp->next;
                (temp->next)->prev=temp->prev;
                cout<<"*** "<<chToRemove->channel_no<<" Removed from the package ***"<<endl;
                 sucess =1;
             
             }
         }
         return sucess;     //returning suceess to convey status of channel removal
            
    }//end of removeChannel function
    
};

/*__________________________End of Channel_dcll class_______________________________*/


/*Stack class enables the operations of a Stack*/
class Stack
{
    public:
    ChannelNode *top;       //top is the ChannelNode poitnting to the top of the Stack
    
    //default Constructor
    Stack()
    {
        top=NULL;
    }
    
    //Boolean function to check if Stack is Empty
    bool isStackEmpty()
    {
        return top==NULL;
    }
    //isStackEmpty function ends here
    
    //Function to push a ChannelNode in the Stack
    void push(ChannelNode * n) 
    {
        //if Stack is Empty 
        if (top == NULL) 
            top = n;
    }
    //push function ends here
    
    //Function to pop a ChannelNode from the Stack
    ChannelNode *pop() 
    {
        ChannelNode *temp = NULL;
        //if Stack is Empty
        if (isStackEmpty()) 
            return temp;
        //Else if Stack is not empty
        else
        {
            temp = top;
            top = NULL;
            return temp;        //returning the element which is popped
        }
     }//pop function ends here
     
};
/*__________________________End of Stack class_______________________________*/

//function to clear the screen
void clrscr()
{
     cout << "\033[2J\033[1;1H";        //special string to clear the console
}

/*Menu_Operations class handles the functions of the Main Class*/
class Menu_Operations   
{
    public:
    
    //Boolean function to check if channel_no is within the passed limit
    bool Channel_exists(int ch_no,int start,int end)
    {
        //If channel number is within range
        if(ch_no>=start && ch_no<=end)
            return true;
        //else if channel number is not in range
        else
        {
            cout<<"\nThis Channel doesn't exist\n"<<endl;
            return false;
        }
            
    }
    //end of the Channel_exists function
    
    //Function to search a Channel in the given list on the basis of Channel number
    ChannelNode *SearchNode(Channel_dcll channellist,int playChannel)
    {
        
        ChannelNode *ptr=NULL;          //ChannelNode node variable to store the details of searched Channel 
        
        //if list is Empty
        if(channellist.head==NULL)
            return NULL;
        //if head node is the Channel to be searched
        if((channellist.head)->channel_no==playChannel)
            ptr=channellist.head;
        //Else to search a Channel excluding head node
        else
            {
                ptr=(channellist.head)->next;
                while(ptr!=channellist.head && ptr->channel_no!=playChannel)
                    {
                        ptr=ptr->next;
                    }
                //if Channel not found
                if(ptr==channellist.head)
                    ptr=NULL;
            }
            return ptr;     //returning the search result
    
        
    }//SearchNode function ends here
    
    
   //Function to form a filtered list based on a genre desired by the user in guide menu
   Channel_dcll guide_operation(string genre,Channel_dcll ch_list)
    {
        
         Channel_dcll sel_genre_ls;         //DCLL to store the selected genre channels
         ChannelNode *ptr=ch_list.head;     //ChannelNode variable to traverse the parent List 
        
         cout<<"\n\t!**!**!**!**! "<<genre<<" !**!**!**!**!\n"<<endl;
         
         //while loop to traverse the parent list & form the sel_genre_ls
	     while(ptr->next!=ch_list.head)
	     {
	        //if genre of the ptr node is the user desired genre
	        if((genre.compare(ptr->channel_genre))==0)
	        {
	           sel_genre_ls.create(ptr->channel_no,ptr->channel_name,ptr->channel_genre,ptr->channel_price);        //adding Channel details to the sel_genre_ls list using Create function 
	        }
	        
	        //Else if ptr node does not have user desired genre & the sel_genre_ls list  has channels
	        else if((sel_genre_ls.isEmpty()==0) && (genre.compare(ptr->channel_genre)!=0))
	        {
	          break;
	        }//else if ends here
	        
	        ptr=ptr->next;
	     }
	     //If last channel is also a part of the user desired genre
	     if((ptr->next)==ch_list.head)
	     {
	         sel_genre_ls.create(ptr->channel_no,ptr->channel_name,ptr->channel_genre,ptr->channel_price);
	     }
	                     
	     sel_genre_ls.displayAllChannels(0);       //Displaying the sel_genre_ls
	     return sel_genre_ls;                     //returning the sel_genre_ls for further operations
     
    }//guide_operation function ends here

    
    //Function to Allow user create a customised package
    void Create_package(Channel_dcll ch_list)
    {
        int playChannel;                    //Variable to accept channel number for addition to the package
        string name;                        //Variable to accept name of the package
        Channel_dcll package_list;          //DCLL to store the channels added to the package
        float result=0.0;                   //variable to store the total cost of the package
        cout<<"\n\n\t\t~*~*~*~*~*~*~*~*~Create you Own Package Now ~*~*~*~*~*~*~*~*~\n\n"<<endl;
        ch_list.displayAllChannels(1);      //displaying all the available channels along with their price
        char ch_add;
                   
        
        cout<<"\nEnter a name for your package :"<<endl;
        cin>>name;                  //Accepting name of the package
        do
        {
                cout<<"\nSelect an Option :   + ->Add more channels to the package   - ->Remove channels from package   # ->Display bill"<<endl;
                cin>>ch_add;         //Accepting option from the user
                switch(ch_add)
                {
                    
                    /*************** To add Channels to the package ****************/
                    case '+':
                    {
                          do
                          {
                            cout<<"Enter the channel no. you want to add to the package :"<<endl;
                            cin>>playChannel;           //accepting channel to be added to the package
                            
                          }while(!Channel_exists(playChannel,(ch_list.head)->channel_no,((ch_list.head)->prev)->channel_no));  //Checking if entered Channel is a valid Channel
                          
                          //If channel is already present in the package
                          if(SearchNode(package_list,playChannel)!=NULL)
                            cout<<"!!! This channel is already present in the package !!!"<<endl;
                          
                          //Else adding channel to the package 
                          else
                            {
                               ChannelNode *temp=SearchNode(ch_list,playChannel);
                               package_list.create(temp->channel_no,temp->channel_name,temp->channel_genre,temp->channel_price);
                               result=result+temp->channel_price;           //Adding the cost of new Channel to the total cost
                               cout<<temp->channel_no<<" added to the package :)"<<endl;
                            }
            
                    }
                    break;
                    
                     /*************** To remove Channel from the package ****************/
                    case '-':
                    {
                        //If no channels are present in the package
                        if(package_list.head==NULL)
                            cout<<"!!!! The package has no channels to delete !!!!"<<endl;
                        
                        //If channels are present in the package
                        else
                        {
                            do
                            {
                                cout<<"Enter the channel no. you want to remove from the package :"<<endl;
                                cin>>playChannel;       //accepting channel to be added to the package
                            
                            }while(!Channel_exists(playChannel,(ch_list.head)->channel_no,((ch_list.head)->prev)->channel_no));       //Checking if entered Channel is a valid Channel
                          
                            ChannelNode *temp=SearchNode(ch_list,playChannel);          //Searching the Channel to be removed in the Channel list
                            
                            //Checking if removal of Channel is successful
                            if(package_list.removeChannel(temp)==1)
                                result=result-temp->channel_price;      //Reducing the price of the removed Channel from the total cost
                        }
                    }
                    break;
                    
                    /*************** To display the Channels of the package ****************/
                    case '#':
                    {
                        int send;
                        clrscr();   
                        cout<<"\n\t   @_@_@_@_@_@_@  "<<name<<" Package is as follows @_@_@_@_@_@_@\n"<<endl;
                        package_list.displayAllChannels(1);         //displaying the channels added to the package
                        
                        //if package is not empty
                        if(package_list.head!=NULL)
                        {
                            cout<<"\n\t***The final price of your customised package is :"<<result<<" ***"<<endl;
                        
                             //Asking the user if he wants to use this package for his next month service
                            do
                            {
            
                            cout<<"\nDo u want to sent a request to the provider to avail this package next month : \n1-->Yes \n2-->No"<<endl;
                            cin>>send;
             
                            switch(send)
                            {
                                case 1:
                                    cout<<"Your request is send!!! Thank you :)"<<endl;
                                break;
                                case 2:
                                    cout<<"*** Okay the request for this package will not be considered ***"<<endl;
                                break;
                                default:
                                    cout<<"***INVALID INPUT***"<<endl;
                
                            }
             
                            }while(!(send==1||send==2));
                        }
                   
                    }
                    break;
                    
                    default:
                        cout<<"!!!***INVALID OPTION SELECTED***!!!"<<endl;
                }
                
        }while(ch_add!='#');
        

        //Returning back to main menu
        cout<<"\n X -->Go back to main menu "<<endl;
        do
        {
            cout<<"Press your option :"<<endl;
            cin>>ch_add;
            if(ch_add=='X')
                clrscr();
            else
                cout<<"***Invalid Option***"<<endl;
        }while(ch_add!='X');
        
        
        
    }//Create_package Function ends here
    
};
/*__________________________End of Menu_Operations class_______________________________*/


//main begins here
int main()
{
    cout<<"\t\t\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!"<<endl;
    cout<<"\n\t\t\t\t\t\t\tआसमां\t\t\t\t\t\t\t"<< endl;
    cout<<"\t\t\t\t\t\t              ~जहाँ हमने सबके लिए खुशियां जोड़ी हैं। " << endl;
    cout<<"\n\t\t\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n"<<endl;
    
    Menu_Operations menu_object;        //Object of Menu_Operations Class to access its functions
    
    Channel_dcll channel_list;          //Object of Channel_dcll Class to access its functions
    
    string genre_list[5] = { "Entertainment", "Kids", "Music","News", "Food and Culture"};      //Array to store genre names
    
    Stack previous_channel;             //Stack declared to store the previously played Channel
    
    int playChannel;                    //Variable to store the channel number to be searched
    
    /*------------Creating Entertainment Channels--------------*/
    
    channel_list.create(101,"Star Plus","Entertainment",19.0);
    channel_list.create(102,"Zee TV","Entertainment",18.5);
    channel_list.create(103,"Colors","Entertainment",19.5);
    channel_list.create(104,"SabTV","Entertainment",20.0);
    channel_list.create(105,"& TV","Entertainment",12.0);
    channel_list.create(106,"UTV Action","Entertainment",2.00);
    channel_list.create(107,"Zee Cinema","Entertainment",15.0);
    channel_list.create(108,"Star Gold","Entertainment",8.00);
    channel_list.create(109,"Sony Pix","Entertainment",10.0);
    channel_list.create(110,"Sony Max","Entertainment",15.0);
    
    /*------------Creating Kids Entertainment Channels--------------*/
    
    channel_list.create(111,"Cartoon Network","Kids",4.0);
    channel_list.create(112,"Pogo","Kids",4.00);
    channel_list.create(113,"Disney","Kids",3.00);
    channel_list.create(114,"Disney Junior","Kids",2.50);
    channel_list.create(115,"Nickelodean","Kids",4.00);
    channel_list.create(116,"Nick Junior","Kids",3.50);
    channel_list.create(117,"Hungama TV","Kids",2.00);
    channel_list.create(118,"Marvel HQ","Kids",3.00);
    channel_list.create(119,"Sony YAY","Kids",2.00);
    channel_list.create(120,"Discovery Kids","Kids",3.50);
    
    /*------------Creating Music Channels--------------*/
    
    channel_list.create(121,"MTV","Music",3.00);
    channel_list.create(122,"9XM","Music",1.00);
    channel_list.create(123,"B4U ","Music",0.00);
    channel_list.create(124,"MTV Beats ","Music",2.00);
    channel_list.create(125,"Zing","Music",2.00);
    channel_list.create(126,"Mastii ","Music",2.00);
    channel_list.create(127,"9X Jalwa ","Music",0.00);
    channel_list.create(128,"Music India ","Music",2.00);
    channel_list.create(129,"VH1 ","Music",3.00);
    channel_list.create(130,"ZEE ETC ","Music",2.00);
    
   /*------------Creating News Channels--------------*/
   
    channel_list.create (131, "DD News", "News", 0.50);
    channel_list.create (132, "NDTV India", "News", 1.50);
    channel_list.create (133, "Aajtak HD", "News", 2.77);
    channel_list.create (134, "CNBC Awaaz", "News", 1.18);
    channel_list.create (135, "Zee News", "News", 0.78);
    channel_list.create (136, "CNN News 18", "News", 0.89);
    channel_list.create (137, "WION", "News", 3.54);
    channel_list.create (138, "ETV Telangana", "News", 1.09);
    channel_list.create (139, "Al Jazeera", "News", 4.50);
    channel_list.create (140, "ABP News", "News", 0.40);

    
    /*------------Creating Food and Culture Channels--------------*/
    
    channel_list.create(141,"History TV 18","Food and Culture",13.0);
    channel_list.create(142,"Fox Life","Food and Culture",14.0);
    channel_list.create(143,"EPIC","Food and Culture",11.0);
    channel_list.create(144,"Zee Zest","Food and Culture",8.00);
    channel_list.create(145,"TLC India","Food and Culture",12.0);
    channel_list.create(146,"FOOD FOOD","Food and Culture",11.0);
    channel_list.create(147,"Travel XP","Food and Culture",7.00);
    channel_list.create(148,"Green TV","Food and Culture",12.0);
    channel_list.create(149,"Sanskar TV","Food and Culture",3.00);
    channel_list.create(150,"Aastha Bhajan","Food and Culture",1.00);
    
    ChannelNode *present_channel=channel_list.head;     //ChannelNode to store the presently played Channel     
    
    previous_channel.push(present_channel);             //Initializing the stack 

    int ch;
    
    /*------------Do while loop to Drive the MAIN MENU--------------*/
   do 
   {
       cout<<"\n  **Now Playing : "<<present_channel->channel_no<<"--"<<present_channel->channel_name<<"..."<<endl;
       cout<<"\n  =================================="<<endl;
       cout<<"\t   ***MAIN MENU***"<<endl;
       cout<<"  =================================="<<endl;
       cout<<"\n   1->Channel List"<<endl;
       cout<<"  ----------------------------------"<<endl;
       cout<<"   2->Guide"<<endl;
       cout<<"  ----------------------------------"<<endl;
       cout<<"   3->Search"<<endl;
       cout<<"  ----------------------------------"<<endl;
       cout<<"   4->Create your own package"<<endl;
       cout<<"  ----------------------------------"<<endl;
       cout<<"   5->Back"<<endl;
       cout<<"  ----------------------------------"<<endl;
       cout<<"   6->EXIT"<<endl;
       cout<<"  =================================="<<endl;
       cout<<"\nEnter your choice"<<endl;
       cin>>ch;             //Accepting the choice from the user 
       
       switch(ch)
       {
           /*------------To Drive the Channel list sub_menu--------------*/
           case 1:      
           {
               clrscr();
               cout<<"\n\t\t****Channel List****"<<endl;
               cout<<"\t\t===================="<<endl;
               char in_ch;
               channel_list.displayAllChannels(0);
               cout<<"\n  **Now Playing : "<<present_channel->channel_no<<"--"<<present_channel->channel_name<<"..."<<endl;   
                    cout<<"\n--------------------"<<endl;
                    cout<<"   ***MENU***"<<endl;
                    cout<<"--------------------"<<endl;
                    cout<<" + ->Next Channel"<<endl;
                    cout<<" - ->Previous Channel"<<endl;
                    cout<<" @ ->Select a Channel"<<endl;
                    cout<<" x ->Back to Main Menu"<<endl;
                    cout<<"--------------------"<<endl;
                    cout<<"\nEnter your choice"<<endl;
                    cin>>in_ch;     //accepting choice from the user

                
               while(in_ch!='x')
               {
                    
                    switch(in_ch)
                    {
                        /*--------------------TO play the Next Channel--------------*/
                        case '+':
                        {
                            ChannelNode *trial=previous_channel.pop();    //Popping the previous Channel from the Stack
                            previous_channel.push(present_channel);      //Pushing the present Channel in the Stack
                            present_channel=present_channel->next;      //Updating the present Channel
                            cout<<"\n  **Now Playing : "<<present_channel->channel_no<<"--"<<present_channel->channel_name<<"..."<<endl;    //displaying the presently played Channel
                        }
                        break;
                        
                        /*--------------------TO play the Previous Channel--------------*/
                        case '-':
                        {
                            ChannelNode *trial=previous_channel.pop();      //Popping the previous Channel from the Stack
                            previous_channel.push(present_channel);        //Pushing the present Channel in the Stack
                            present_channel=present_channel->prev;        //Updating the present Channel
                            cout<<"\n  **Now Playing : "<<present_channel->channel_no<<"--"<<present_channel->channel_name<<"..."<<endl;     //displaying the presently played Channel
                        }
                        break;
                        
                        /*--------------------TO play the Searched Channel--------------*/
                        case '@':
                        {
                            ChannelNode *trial=previous_channel.pop();  //Popping the previous Channel from the Stack
                            previous_channel.push(present_channel);     //Pushing the present Channel in the Stack
                            do
                            {
                                cout<<"Enter the channel no you want to play Next:"<<endl;
                                cin>>playChannel;       //Accepting the Channel Number from the user
                                
                            }while(!menu_object.Channel_exists(playChannel,(channel_list.head)->channel_no,((channel_list.head)->prev)->channel_no));   //Checking if entered Channel is a valid Channel
                         
                            present_channel=menu_object.SearchNode(channel_list,playChannel);   //Updating the present Channel
                            cout<<"\n  **Now Playing : "<<present_channel->channel_no<<"--"<<present_channel->channel_name<<"..."<<endl;        //displaying the presently played Channel
                        }
                        break;
                        
                        /*--------------------To go back to the Main Menu--------------*/
                        case 'x':
                            break;
                        
                        default:
                        cout<<"\n!!!***INVALID OPTION SELECTED***!!!"<<endl;
                        
                    }
                    
                    cout<<"Select an option :\t+ ->Next Channel  \t- ->Previous Channel  \t@ ->Select a Channel  \tx ->Back to Main Menu"<<endl;
                    cin>>in_ch;     //Accepting choice from the user
                    
               }
               clrscr();
           }break;
           
            /*------------To Drive the Guide sub menu--------------*/
           case 2:     
             int g_ch;      //accepting choice from the user
	         clrscr();
	        do
	        {

		        cout << "\n     ***GUIDE SUB MENU***"<< endl;
		        cout<<"\n ============================"<<endl;
		        cout << "\n 1--->Entertainment\n 2-->Kids Entertainment\n 3--->Music\n 4--->News\n 5--->Food & Culture\n 6 --->Go Back to Main Menu" << endl;
		        cout<<"\n ============================"<<endl;
		        cout << "\nEnter your choice" << endl;
		        cin >> g_ch;
		        
		        switch(g_ch)
		        {
		          case 1:   
		            
                  case 2:
                    
                  case 3:
                    
                  case 4:
                    
                  case 5:
                  {
                      clrscr();
                     
                      Channel_dcll genre_ls=menu_object.guide_operation(genre_list[(g_ch-1)],channel_list);     //passing genre and channel_list to the guide operation function
                      char o_ch='x';
                      ChannelNode *trial=genre_ls.head;               //ChannelNode variable to store the head of genre_ls
                      ChannelNode *temp=previous_channel.pop();      //Popping the previous Channel from the Stack
	                  previous_channel.push(present_channel);       //Pushing the present Channel in the Stack
	                  present_channel=trial;                       //Updating the present Channel
                      
                      do{
                          
	                    cout<<"\nNow Playing....."<<trial->channel_no<<" "<<trial->channel_name<<endl;
	                    cout<<"+..Next Channel     -..Previous Channel    @..Select Channel   x..Back to Guide Sub Menu" <<endl;
	                    cin>> o_ch;
	                    switch(o_ch){
	                       
	                        /*--------------------TO play the Next Channel--------------*/
	                    case '+':
	                    {
	                        ChannelNode *temp=previous_channel.pop();   //Popping the previous Channel from the Stack
	                        previous_channel.push(present_channel);    //Pushing the present Channel in the Stack
	                        trial=trial->next;                        //moving to the next Channel
                            present_channel=trial;                   //Updating the present Channel
                            
	                    }
	                   break;
	                   
	                    /*--------------------TO play the Previous Channel--------------*/
	                   case '-':
	                   {
	                        ChannelNode *temp=previous_channel.pop();       //Popping the previous Channel from the Stack
	                        previous_channel.push(present_channel);        //Pushing the present Channel in the Stack
	                        trial=trial->prev;                            //moving to the previous Channel
                            present_channel=trial;                       //Updating the present Channel
                            
	                   }
	                 break;
	                 
	                 /*--------------------TO play the Searched Channel--------------*/
	                case '@':
	                {
	                    ChannelNode *temp=previous_channel.pop();       //Popping the previous Channel from the Stack
	                    previous_channel.push(present_channel);        //Pushing the present Channel in the Stack
                      do
                    {
                        cout<<"Enter the channel no you want to search for :"<<endl;
                        cin>>playChannel;                    //Accepting the Channel Number from the user
                        
                    }while(!menu_object.Channel_exists(playChannel,(genre_ls.head)->channel_no,((genre_ls.head)->prev)->channel_no));       //Checking if entered Channel is a valid Channel
                    trial=menu_object.SearchNode(genre_ls,playChannel);     //moving to the searched Channel
                    present_channel=trial;                      //Updating the present Channel
	                }
	                break;
	                
	                /*--------------------To go back to the Guide Sub Menu--------------*/
	                case 'x':
	                    clrscr();
	                break;
	                
	                default:
	                    cout<<"!!!***INVALID INPUT***!!!"<<endl;
	                }//switch ends here
	     
	            }while(o_ch!='x');
              }
                break;
                /*--------------------To go back to the Main Menu--------------*/
                  case 6:
                  {
                      clrscr();
                  }
                  break;
                  default:
                        cout<<"Incorrect"<<endl;
		        }
		        
	            }while (g_ch!=6);
	 
           break;
           /*------------To drive the search Option and Display the details-------------*/
           case 3:  
           {
               clrscr();
               cout<<"\n**** Search For Channels Now!!! ****\n"<<endl;
               int choice;
               do
               {
                   
                   do
                    {
                        cout<<"Enter the channel no you want to search for :"<<endl;
                        cin>>playChannel;               //Accepting the Channel Number from the user
                        
                    }while(!menu_object.Channel_exists(playChannel,(channel_list.head)->channel_no,((channel_list.head)->prev)->channel_no));//Checking if entered Channel is a valid Channel
                   
                   ChannelNode *ptr=menu_object.SearchNode(channel_list,playChannel);   //moving to the searched Channel
                   cout<<"\nChannel Details are as follows: \nChannel-Number : "<<ptr->channel_no<<"\nChannel_Name : "<<ptr->channel_name<<"\nChannel_genre : "<<ptr->channel_genre<<"\nChannel_Price : "<<ptr->channel_price<<endl;  //Checking if entered Channel is a valid Channel
                   
                   do{
                       
                   cout<<"\nDo you want to search more channels ?\n1-->Yes\n2-->-No "<<endl;
                   cout<<"\nEnter your choice :"<<endl;
                   cin>>choice;     //Accepting choice from the user 
                    
                    //if Invalid Choice is entered
                   if(!(choice==1||choice==2))
                    cout<<"!!!***INVALID OPTION SELECTED***!!!"<<endl;
                   }while(!(choice==1||choice==2));
                  
                
               }while(choice!=2);
               
               clrscr();
               
           }break;
           
           /*--------------------To Drive the Create Package section--------------*/
           case 4:
           {
               clrscr();
               menu_object.Create_package(channel_list);        //passing channel list to the Create_package function
               
           }break;
           
           /*--------------------To Drive the Back section--------------*/
           case 5:     
           {
               clrscr();
               ChannelNode *temp=present_channel;           //storing present value to a temp 
               present_channel=previous_channel.pop();     //popping Channel from stack and Updating present Channel
               previous_channel.push(temp);               //passing temp to the stack
               
           }break;
           
           /*--------------------To Exit the Program--------------*/
           case 6:      
           {
                clrscr();
                cout<<"\n\t\t\t\t\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!"<<endl;
                cout<<"\n\t\t\t\t\t\t\t\t\tआसमां\t\t\t\t\t\t\t"<< endl;
                cout<<"\t\t\t\t\t\t\t\t              ~जहाँ हमने सबके लिए खुशियां जोड़ी हैं। " << endl;
                cout<<"\n\t\t\t\t\t!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!\n"<<endl;
                cout<<"\n\t\t\t\t\t\t\t\tसमोसे चाय लेकर बैठे जो परिवार के संग"<<endl;
                cout<<"\t\t\t\t\t\t\t\t   हर दिन बने यादों के अनेक रंग,"<<endl;
                cout<<"\n\t\t\t\t\t\t\t    आप रहें सुरक्षित इसलिए लेकर मनोरंजन के सारे ढंग"<<endl;
                cout<<"\t\t\t\t\t\t\t   आसमां से आपके घर ले आते है हम तारों की नई उमंग।"<<endl;

                cout<<"\n\n\n\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                cout<<"\t\t\t\t\t\t\t\t\t  धन्यवाद\t\t\t\t\t\t\t"<<endl;
                cout<<"\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"<<endl;
                
                
           }break;
           
           /*If INVALID OPTION is  SELECTED*/
           default: 
                cout<<"!!!***INVALID OPTION SELECTED***!!!"<<endl;
       }
       
   }while(ch!=6);
    return 0;
}
//main ends here


