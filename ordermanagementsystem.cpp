#include <iostream>
#include <fstream>
#include <string>
#include <memory>
using namespace std;
/** Template method pattern base class, most of the time abstract */
class Customer
{
public:
	void templateMethod()
	{
		Set_Details();
		Get_Details();
	}
	virtual void Set_Details() = 0;
	virtual void Get_Details() = 0;
};
/** Derived class */
class CorporateCustomer : public Customer
{
private:
    int Customer_ID;
    string Contact_Name;
	string Contact_Number;
	string Address;
	float Credit_Limit;
public:
  void Set_Details()
  {
    cout<<"\n\t * Enter Corporate Customer Details * "<<endl;
    cout<<"Enter Your Customer Id : ";
    cin>>Customer_ID;
    cout<<"Enter Your Name : ";
    cin>>Contact_Name;
    cout<<"Enter Your Contact Number : ";
    cin>>Contact_Number;
    cout<<"Enter Your Address : ";
    cin>>Address;
    cout<<"Enter Credit Limit : Rs. ";
    cin>>Credit_Limit;
  }
  void Get_Details()
  {
    cout<<"\n\t * Your Corporate Customer Details * "<<endl;
    cout<< "Customer Id: " <<Customer_ID<<endl;
    cout<< "Name: " <<Contact_Name<<endl;
    cout<< "Contact Number: "<<Contact_Number<<endl;
    cout<< "Address: "<<Address<<endl;
    cout<< "Credit Limit: Rs. " <<Credit_Limit<<endl;
  }
};
/** Derived class */
class PersonalCustomer : public Customer
{
private:
    int Customer_ID;
    string Name;
	string Contact_Number;
	string Address;
	string Credit_Card_Number;
public:
  void Set_Details()
  {
    cout<<"\n\t * Enter Personal Customer Details * "<<endl;
    cout<<"Enter Your Customer Id : ";
    cin>>Customer_ID;
    cout<<"Enter Your Name : ";
    cin>>Name;
    cout<<"Enter Your Contact Number : ";
    cin>>Contact_Number;
    cout<<"Enter Your Address : ";
    cin>>Address;
    cout<<"Enter Credit Card Number : ";
    cin>>Credit_Card_Number;
  }
  void Get_Details()
  {
    cout<<"\n\t * Your Personal Customer Details * "<<endl;
    cout<< "Customer Id: " <<Customer_ID<<endl;
    cout<< "Name: " <<Name<<endl;
    cout<< "Contact Number: "<<Contact_Number<<endl;
    cout<< "Address: "<<Address<<endl;
    cout<< "Credit Card Number: " <<Credit_Card_Number<<endl;
  }
};
class Employee
{
private:
    int Employee_ID;
    string Employee_Name;
    string Department;
    string Designation;
    string Employee_Contact_Number;
public:
    void Set_EmployeeDetails();
    void Get_EmployeeDetails();
};
class Order
{
private:
    int Order_ID;
public:
    void Get_Order_ID();
};
class Order_Line
{
private:
    int Order_Line_ID;
    int Product_ID;
    string Product_Name;
    string Product_Quantity;
    float Price;
    float Discount;
public:
    void receipt();
};
class Product
{
private:
    int Product_ID;
    string Product_Name;
    string Product_Quantity;
    float Price;
    string Product_Status;
    float Discount;
public:
    void Product_Operations();
    void add_product();
    void modify_product();
    void delete_product();
    void search_product();
    void Productlist();
};
/** Entering employee details */
void Employee :: Set_EmployeeDetails()
{
    cout<<"Enter Employee ID : ";
    cin>>Employee_ID;
    cout<<"Enter Name : ";
    cin>>Employee_Name;
    cout<<"Enter Department : ";
    cin>>Department;
    cout<<"Enter Designation : ";
    cin>>Designation;
    cout<<"Enter Contact Number : ";
    cin>>Employee_Contact_Number;
}
/** Displaying employee details */
void Employee :: Get_EmployeeDetails()
{
    cout<<"Employee ID : "<<Employee_ID<<endl;
    cout<<"Employee Name : "<<Employee_Name<<endl;
    cout<<"Employee Department : "<<Department<<endl;
    cout<<"Employee Designation : "<<Designation<<endl;
    cout<<"Employee Contact Number : "<<Employee_Contact_Number<<endl;
}
/** Printing order id */
void Order :: Get_Order_ID()
{
    Order_ID = rand();
    cout <<"\nOrder Id: "<<Order_ID<< " "<<endl;
}
/** Identifying type of customer */
void Customer_Type()
{
    char choice;
    cout<<"\nAre you a corporate customer or personal customer?"<<endl;
    cout<<"Enter C for Corporate Customer or P for Personal Customer : ";
    cin>>choice;
    switch(choice)
    {
    case 'C':
        {
            CorporateCustomer cc;
            cc.templateMethod();
            char choice1;
            cout<<"\nAre you an employee too? If yes then press y if no then press n: ";
            cin>>choice1;
            if(choice1=='y')
            {
                Employee E;
                cout<<"\n\t * Enter Employee Details * "<<endl;
                E.Set_EmployeeDetails();
                cout<<"\n\t * Employee Details * "<<endl;
                E.Get_EmployeeDetails();
            }
        }
        break;
    case 'P':
        {
            PersonalCustomer pc;
            pc.templateMethod();
        }
        break;
    default:
        cout<<"Invalid choice"<<endl;
    }
}
/** Adding product details in the system */
void Product :: add_product()
{
    m:
    fstream data;
    int Id;
    string Name;
    string Quantity;
    float Cost;
    string Availability;
    float dis;
    int token=0;
    cout<<"\n\t--Add New Product--"<<endl;
    cout<<"Product Id: ";
    cin>>Product_ID;
    cout<<"Product Name: ";
    cin>>Product_Name;
    cout<<"Product Quantity: ";
    cin>>Product_Quantity;
    cout<<"Product Price: ";
    cin>>Price;
    cout<<"Product Status: ";
    cin>>Product_Status;
    cout<<"Discount: ";
    cin>>Discount;
    data.open("Data.txt",ios::in);
    if(!data)
    {
        data.open("Data.txt",ios::app|ios::out);
        data<<" "<<Product_ID<<" "<<Product_Name<<" "<<Product_Quantity<<" "<<Price<<" "<<Product_Status<<" "<<Discount<<"\n";
        data.close();
    }
    else
    {
        data>>Id>>Name>>Quantity>>Cost>>Availability>>dis;
        while(!data.eof())
        {
            if(Id==Product_ID)
            {
                token++;
            }
            data>>Id>>Name>>Quantity>>Cost>>Availability>>dis;
        }
        data.close();
        if(token==1)
        {
            goto m;
        }
        else
        {
            data.open("Data.txt",ios::app|ios::out);
            data<<" "<<Product_ID<<" "<<Product_Name<<" "<<Product_Quantity<<" "<<Price<<" "<<Product_Status<<" "<<Discount<<"\n";
            data.close();
        }
    }
    cout<<"\n\tRecord Inserted!!"<<endl;
}
/** Modifying product details from the system */
void Product :: modify_product()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int Id;
    string Name;
    string Quantity;
    float Cost;
    string Availability;
    float dis;
    cout<<"\n\t--Modify the record--"<<endl;
    cout<<"Enter the id of the product which you want to modify: ";
    cin>>pkey;
    data.open("Data.txt",ios::in);
    if(!data)
    {
        cout<<"\n\t--File does not exist--"<<endl;
    }
    else
    {
        data1.open("Data1.txt",ios::app|ios::out);
        data>>Product_ID>>Product_Name>>Product_Quantity>>Price>>Product_Status>>Discount;
        while(!data.eof())
        {
            if(pkey==Product_ID)
            {
                cout<<"\n * You can now modify the details * "<<endl;
                cout<<"Product Id: ";
                cin>>Id;
                cout<<"Product Name: ";
                cin>>Name;
                cout<<"Product Quantity: ";
                cin>>Quantity;
                cout<<"Product Price: ";
                cin>>Cost;
                cout<<"Product Status: ";
                cin>>Availability;
                cout<<"Discount: ";
                cin>>Discount;
                data1<<" "<<Id<<" "<<Name<<" "<<Quantity<<" "<<Cost<<" "<<Availability<<" "<<dis<<"\n";
                cout<<"\n\tRecord modified!!"<<endl;
                token++;
            }
            else
            {
                data1<<" "<<Product_ID<<" "<<Product_Name<<" "<<Product_Quantity<<" "<<Price<<" "<<Product_Status<<" "<<Discount<<"\n";
            }
            data>>Product_ID>>Product_Name>>Product_Quantity>>Price>>Product_Status>>Discount;
        }
        data.close();
        data1.close();
        remove("Data.txt");
        rename("Data1.txt","Data.txt");
        if(token==0)
        {
            cout<<"\n\t--Record not found--"<<endl;
        }
    }
}
/** Deleting product details from the system */
void Product :: delete_product()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\t--Delete Product--"<<endl;
    cout<<"Product Id: ";
    cin>>pkey;
    data.open("Data.txt",ios::in);
    if(!data)
    {
        cout<<"\n\t--File does not exist--"<<endl;
    }
    else
    {
        data1.open("Data1.txt",ios::app|ios::out);
        data>>Product_ID>>Product_Name>>Product_Quantity>>Price>>Product_Status>>Discount;
        while(!data.eof())
        {
            if(Product_ID==pkey)
            {
                cout<<"\n\tProduct deleted successfully!!"<<endl;
                token++;
            }
            else
            {
                data1<<" "<<Product_ID<<" "<<Product_Name<<" "<<Product_Quantity<<" "<<Price<<" "<<Product_Status<<" "<<Discount<<"\n";
            }
            data>>Product_ID>>Product_Name>>Product_Quantity>>Price>>Product_Status>>Discount;
        }
        data.close();
        data1.close();
        remove("Data.txt");
        rename("Data1.txt","Data.txt");
        if(token==0)
        {
            cout<<"\n\t--Record not found--"<<endl;
        }
    }
}
/** Searching product details from the system */
void Product :: search_product()
{
    fstream data;
    int Id;
    int found=0;
    cout<<"\n\t--Search Product--"<<endl;
    cout<<"Product Id: ";
    cin>>Id;
    data.open("Data.txt",ios::in);
    if(!data)
    {
        cout<<"\n\t--File does not exist--"<<endl;
    }
    else
    {
        data>>Product_ID>>Product_Name>>Product_Quantity>>Price>>Product_Status>>Discount;
        while(!data.eof())
        {
            if(Id==Product_ID)
            {
                cout<<"\n\t * Searched Product * "<<endl;
                cout<<"Product Id: "<<Product_ID<<endl;
                cout<<"Product Name: "<<Product_Name<<endl;
                cout<<"Product Quantity: "<<Product_Quantity<<endl;
                cout<<"Product Price: "<<Price<<endl;
                cout<<"Product Status: "<<Product_Status<<endl;
                cout<<"Discount: "<<Discount<<endl;
                found++;
            }
            data>>Product_ID>>Product_Name>>Product_Quantity>>Price>>Product_Status>>Discount;
    }
    data.close();
    if(found==0)
    {
        cout<<"Record not found!!"<<endl;
    }
    }
}
/** Displaying available products */
void Product :: Productlist()
{
    fstream data;
    data.open("Data.txt",ios::in);
    cout<<"\n\t\t\t--Product Menu--"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Product Id\tProduct Name\tProduct Quantity\tProduct Price(Rs.)\tProduct Status\tDiscount\n";
    data>>Product_ID>>Product_Name>>Product_Quantity>>Price>>Product_Status>>Discount;
    while(!data.eof())
    {
        cout<<Product_ID<<"\t\t"<<Product_Name<<"\t\t"<<Product_Quantity<<"\t\t\t"<<Price<<"\t\t\t"<<Product_Status<<"\t"<<Discount<<"%"<<"\n";
        data>>Product_ID>>Product_Name>>Product_Quantity>>Price>>Product_Status>>Discount;
    }
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    data.close();
}
/** Taking an order and printing the bill */
void Order_Line :: receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float total=0;
    float Discount=0;
    data.open("Datad.txt",ios::in);
    if(!data)
    {
        cout<<"Empty database"<<endl;
    }
    else
    {
        data.close();
        cout<<"\n * Place the order *\n"<<endl;
        do
        {
            cout<<"Enter Product Id: ";
            cin>>arrc[c];
            cout<<"Enter Product Quantity: ";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"Duplicate product code please try again!"<<endl;
                }
            }
            c++;
            cout<<"\nDo you want to buy another product? If yes then press y and if no then press n: ";
            cin>>choice;
        }
        while(choice=='y');
        cout<<"\n\t\t* Receipt * "<<endl;
        cout<<"--Please provide your details to create the receipt--"<<endl;
        Customer_Type();
        cout<<"\n\t * Your Order Details * "<<endl;
        Order O;
        O.Get_Order_ID();
        Order_Line_ID = rand();
        cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Order Line Id\tProduct Id\tProduct Name\tQuantity\tTotal items\tProduct Price\tAmount\tAmount with discount\n";
        for(int i=0;i<c;i++)
        {
            data.open("Datad.txt",ios::in);
            data>>Product_ID>>Product_Name>>Product_Quantity>>Price>>Discount;
            while(!data.eof())
            {
                if(Product_ID==arrc[i])
                {
                    amount=Price*arrq[i];
                    Discount=amount-(amount*Discount/100);
                    total=total+Discount;
                    cout<<"\n"<<Order_Line_ID<<"\t\t"<<Product_ID<<"\t\t"<<Product_Name<<"\t\t"<<Product_Quantity<<"\t\t"<<arrq[i]<<"\t\tRs. "<<Price<<"\t"<<amount<<"\t"<<Discount;
                }
                data>>Product_ID>>Product_Name>>Product_Quantity>>Price>>Discount;
        }
    data.close();
        }
}
cout<<"\n----------------------------------------------------------------------------------------------------------------------------"<<endl;
cout<<"Total Amount: Rs. "<<total;
}
void Product :: Product_Operations()
{
    int choice;
    cout<<"\n\t--Administrator Menu--"<<endl;
    cout<<"1: Add Product"<<endl;
    cout<<"2: Modify Product"<<endl;
    cout<<"3: Delete Product"<<endl;
    cout<<"4: Search Product"<<endl;
    cout<<"5: Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            add_product();
            break;
        }
    case 2:
        {
            modify_product();
            break;
        }
    case 3:
        {
            delete_product();
            break;
        }
    case 4:
        {
            search_product();
        }
    case 5:
        {
            exit(0);
        }
    default:
        {
            cout<<"Invalid choice! Please select from the given option"<<endl;
        }
    }
}
/** Driver code */
int main()
{
    Product P;
    int choice;
    string email;
    string password;
    cout<<"\n\t*****ZamWholeSale Main Menu*****"<<endl;
    cout<<"\n1: Administrator"<<endl;
    cout<<"2: Customer"<<endl;
    cout<<"3: Exit"<<endl;
    cout<<"Enter Your Choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"\n\t--Login--"<<endl;
        cout<<"Enter Email: ";
        cin>>email;
        cout<<"Enter password: ";
        cin>>password;
        if(email=="ZamWholeSale@email.com" && password=="admin123")
        {
            P.Product_Operations();
        }
        else
        {
            cout<<"Invalid email/password"<<endl;
        }
        break;
    case 2:
        {
            cout<<"\n\t\t\t * Buy Product * "<<endl;
            P.Productlist();
            Order_Line OL;
            OL.receipt();
        }
        break;
    case 3:
        {
            exit(0);
        }
    default:
        {
            cout<<"Invalid choice! Please select from the given option"<<endl;
        }
    }
    return 0;
}
