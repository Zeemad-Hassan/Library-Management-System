//----__Library Management System__----

#include <iostream>
using namespace std;

int const MAX=100;

struct book{
	int id;
	string name;
	string author;
	float price;
	int status;
};

//Book Add Karny K Liye Function

void add(book b[], int &count){
	if(count>=MAX){
		cout<<"Books Limit Reached "<<endl;
	}
	else{
		cout<<"Enter Book Id : ";
		cin>>b[count].id;
		
		cin.ignore();
		cout<<"Enter Book Name : ";
		getline(cin, b[count].name);
		cout<<"Enter Author's Name : ";
		getline(cin, b[count].author);
		cout<<"Enter The Price : ";
		cin>>b[count].price;
		
		b[count].status=0;
		count++;
	}
}

//Total Books Ko Display Karny K Liye Function

void display(book b[], int count){
	if(count==0){
		cout<<"No Book Has Been Added "<<endl;
	}
	else{
		cout<<"========== ALL BOOKS =========="<<endl;
		
		for(int i=0; i<count; i++){
			cout<<"Data Of Book "<<i+1<<endl;
			cout<<"ID"<<" : "<<b[i].id<<endl;
			cout<<"Name"<<" : "<<b[i].name<<endl;
			cout<<"Author"<<" : "<<b[i].author<<endl;
			cout<<"Price"<<" : "<<b[i].price<<endl;
			
			if(b[i].status==1){
				cout<<"Status : Issued"<<endl;
			}
			else{
				cout<<"Status : Available"<<endl;
			}
			
			cout<<"--------------------------------"<<endl;
		}
	}
}

///Koi Book search Karny K Liye

void search(book b[], int count){
	int id;
	int found=0;
	if(count==0){
		cout<<"No Book Has Been Added "<<endl;
	}
	else{
		cout<<"Enter Book Id You Want To Search ";
		cin>>id;
		
		
			for(int i=0; i<count; i++){
			if(id==b[i].id){
			cout<<"Book Found Of This Id "<<endl;
			cout<<"ID"<<" : "<<b[i].id<<endl;
			cout<<"Name"<<" : "<<b[i].name<<endl;
			cout<<"Author"<<" : "<<b[i].author<<endl;
			cout<<"Price"<<" : "<<b[i].price<<endl;
			
			if(b[i].status==1){
				cout<<"Status : Issued"<<endl;
			}
			else{
				cout<<"Status : Available"<<endl;
			}
			found=1;
			return;
		}
		if(found==0){
			cout<<"No Book Of This Id Found "<<endl;
		}
		}
	}
}

//Kisi book Ko Issue(purchase) karny k liye function

void issue(book b[], int count){
	int id;
	int found=0;
	if(count==0){
		cout<<"No Book Has Been Added "<<endl;
	}
	else{
		cout<<"Enter Book Id You Want To Issue ";
		cin>>id;
		for(int i=0; i<count; i++){
			if(id==b[i].id){
				found=1;
				if(b[i].status==1){
					cout<<"Book Has Already Been Issued "<<endl;
				}
				else{
					b[i].status=1;
					cout<<"Book Issued Successfully "<<endl;
				}
				
				return;	
			}
			if(found==0)
			{
				cout<<"Book Of This Id Not Found "<<endl;
			}
		}
	}
}

//Kisi Book Ko Return Karny Ke Liye

void returning(book b[], int count){
	int id;
	int found=0;
	if(count==0){
		cout<<"No Book Has Been Added "<<endl;
	}
	else{
		cout<<"Enter Book Id You Want To Return ";
		cin>>id;
		for(int i=0; i<count; i++){
			if(id==b[i].id){
				found=1;
				if(b[i].status==0){
					cout<<"Book Is Already Available "<<endl;
			}
				else{
					b[i].status=0;
					cout<<"Book Returned Successfully "<<endl;
				}
				return;
			}
			if(found==0){
				cout<<"Book With This Id Not Found "<<endl;
			}
		}
	}
}

//kisi book ki details ko update karny ke liye function

void update(book b[], int count){
	int id;
	int found=0;
	if(count==0){
		cout<<"No Has Been Added "<<endl;
	}
	else{
		cout<<"Enter Book Id You Want To Update ";
		cin>>id;
		for(int i=0; i<count; i++){
			if(id==b[i].id){
				cout<<"Enter New Id : ";
				cin>>b[i].id;
				
				cin.ignore();
				cout<<"Enter New Name : ";
				getline(cin, b[i].name);
				cout<<"Enter New Author : ";
				getline(cin, b[i].author);
				cout<<"Enter New Price : ";
				cin>>b[i].price;
				
				cout<<"Book Updated Successfully "<<endl;
				found=1;
				return;
			}
			if(found==0){
				cout<<"Book Of This Id Not Found "<<endl;
			}
		}
	}
}

//Kisi Book Ka Data Delete Karny K Liye

void del(book b[], int &count){
	int id;
	int found=0;
	if(count==0){
		cout<<"No Book Has Been Added "<<endl;
	}
	else{
		cout<<"Enter Id Of The Book You Wanted To Delete ";
		cin>>id;
		for(int i=0; i<count; i++){
			if(id==b[i].id){
				
				for(int j=i; j<count-1; j++){
					b[j]=b[j+1];
				}
				
				count--;
				found=1;
				cout<<"Book Deleted Successfully"<<endl;
				return;
			}
			if(found==0){
				cout<<"Book Of This Id Not Found "<<endl;
			}
		}
	}
}

//----Main function Program Ka----

int main()
{
	book b[MAX];
	int count=0;
	int choice;
	
	// Jump statement lagai hai takey jab aik dafa program run hojaye to dubara se start ho aur choice enter krny ka boly
	
	
	do
	{	
        cout<<"===================================="<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. Display All Books"<<endl;
        cout<<"3. Search Book"<<endl;
        cout<<"4. Update Book"<<endl;
        cout<<"5. Issue A Book"<<endl;
        cout<<"6. Return A Book"<<endl;
        cout<<"7. Delete A Book"<<endl;
        cout<<"8. To Exit"<<endl;
        cout<<"===================================="<<endl;
        
		
		cout<<"Enter your choice: ";
        cin>>choice;
        
		//switch structure laga ke apni marzi k function main janay k liya choice select krna
		
		switch (choice){
        	case 1:
        		add(b,count);
        		break;
        	case 2:
        	    display(b,count);
				break;
			case 3:
			    search(b,count);
				break; 
			case 4:
			    update(b,count);
				break;
		    case 5:
		    	issue(b,count);
		    	break;
			case 6:
				returning(b,count);
				break;
		    case 7:
		        del(b,count);
		        break;
		    case 8:
		    	break;
			default:
			cout<<"Invalid Choice Chose A Correct Number"<<endl; 			
		}
	}while(choice!=8);
	
	return 0;
}