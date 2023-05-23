#include <iostream>
// online system shopping
using namespace std;
/* first class for items in the shop
  class having private attributes
 this attributes represent each product info and have setters and getters
  */
class Item{
//private attributes of Item class
private:
    int ID;
    string name;
    int quan;
    int price ;
    // static varriable to set id number
    static int c;
public:
    // setters for id ,name,quantity,price( Mutator functions )
    void setId(int i){
        ID=i;
    }
    void setname(string n){
        name=n;
    }
    void setquan(int q){
        quan=q;
    }
    void setprice(int p){
        price=p;
    }
    //getters for id ,name,quantity,price (Accessor functions)
    int getId(){
        return ID;
    }
    string getname(){
        return name;
    }
    int getquan(){
        return quan;
    }
    int getprice(){
        return price;
    }
//default constructor
    Item(){
        name=" ";
        quan=0;
        price=0;
    }
    /*copy constructor
     we use it if we need to copy info of object
     */
    Item(Item &obj){
        quan=obj.quan;
        name=obj.name;
        price=obj.price;
        ID=obj.ID;
    }
    /*parameterized constructor
      automatically called when an object is created
     */
    Item(int p,int q,string n){
        c++;
        ID=c;
        price=p;
        quan=q;
        name=n;
    }
    /* overloaded operator ==
     we use it if we want to compare between name of products
     in our shop
     */
    bool operator==(Item &right){
        if(name==right.name){
            return true;
        }
        else
            return false;
    }
    /*overloaded operator +=
     to add quantity
     */
    Item operator+=(Item&right){
        quan+=right.quan;
    }

    /* overloaded operator -=

    */
    Item operator-=(int right){
        quan-=right;

    }
// overloaded operator functions
    friend ostream& operator<<(ostream& os,const Item& x);

    friend istream& operator>>(istream& is,Item& x );



};
//  overloaded operator >>
istream& operator >>(istream&is,Item&x){
    cout<<"enter item name: ";
    is>>x.name>>x.price;
    cout<<"enter item price: ";
}
// overloaded operator <<
ostream& operator<<(ostream& os,const Item& x){
    os<<"product info:"<<endl;
    os<<" ID: "<<x.ID<<endl;
    os<<" Name: "<<x.name<<endl;
    os<<" QUANTITY: "<<x.quan<<endl;
    os<<" Price: "<<x.price<<endl<<endl;

    return os;
}
int Item::c=0;
/* second class for  the seller
  to do his job if he need to add items or sell items
  or to know what is the products in the shop
 * */
class Seller{
private:
    /* private attributes name and email of the seller
     array of items in the shop
     max items
     */
    string name;
    string email;
    Item *item;
    int maxitems;
public:
    // static varriable to count number of items in the array
    static int objects;
    /*parameterized constructor for seller class , take 3 parameter name ,email,max items
     sets the private attributes values
     and allocates memory for array
     * */
    Seller(string n,string mail,int max){
        name=n;
        email=mail;
        maxitems=max;
        item= new Item[maxitems];

    }
    /*boolean function to check if you can add item , take item object as a parameter
     first you check if you have reached to maxitems in the shop to know if you raached maxitems return false
     second you search in items if you have the same object with operator == to add quantity with +=
     if you not found it and not raached max items you add this product to the array
     */
    bool Additems(Item itt){

        bool flag = false;
        // condition to check if the array full or not
        if(objects==maxitems)return false;
        int num;
        // loop to search if we have the same product
        for(int i=0;i<objects;i++){
            if(item[i]==itt){
                flag= true;
                num=i;
            }
        }
        // if we found it you add the quatity
        if(flag== true){
            item[num]+=itt;
            return true;
        }
            //else you add it to next place of the array
        else{
            item[objects]=itt;
            objects++;
        }

    }
    /*boolean function to check if you can sell item ,take 2 parameters name and quantity
      loop to search if we have the same item in the shop with operator ==
      then we check if we have this quantity or not
     */
    bool sellitems(string n,int q){
        for(int i=0;i<objects;i++){
            //condition
            if(item[i].getname()==n){

                if(item[i].getquan()<q){
                    // if he not found this this quantity in the shop
                    cout<<"There is only "<<q<<"  left for this item"<<endl;

                }
                else{
                    item[i]-=q;

                }
                return true;
            }


        }
        return false;

    }
    /* overloaded operator <<
       to print seller info
    */
    friend ostream& operator<<(ostream& os,const Seller& x){
        os<<"seller info :"<<endl;
        os<<"Name: "<<x.name<<endl;
        os<<"E-Mail: "<<x.email<<endl;
        return os;
    }

    /*find item by id()
     it returns pointer we use it to print to the user if there is item with this id or not
     */
    Item* find_item(int elem){
        for(int i=0;i<objects;i++){
            if(item[i].getId()==elem){

                return &(item[i]);
            }
        }
        return nullptr;
    }
// function to return object with id
    /* Item search_with_id(int iddd){

     return item[iddd-1];

     }*/
    // function to print items
    void printitems(){
        for(int i=0;i<objects;i++){
            cout<<item[i];
        }
    }
    //Destructor of class seller
    ~Seller(){
        for(int i=0;i<objects;i++){
            delete[]item;
        }
    }
};
int Seller::objects=0;
int main()
{
    cout<<"Welcome to our system"<<endl;
    string name,mail;
    int cap;
    cout<<"please enter your name and mail :"<<endl;
    cin>>name>>mail;
    cout<<"please enter the capacity :"<<endl;
    cin>>cap;
    Seller employer(name,mail,cap);
    //choose number of order
    int number;
    while(true){
        cout<<"Enter the number of your order:"<<endl;
        cout<<"1. Print My Info"<<endl;
        cout<<"2. Add An Item."<<endl;
        cout<<"3. Sell An Item."<<endl;
        cout<<"4. Print Items."<<endl;
        cout<<"5. Find an Item by ID"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>number;
        if(number==1){
            cout << employer;

        }
        else if(number==2){

            cout<<"please enter item name,quantity and price"<<endl;
            string nam;
            int quantity,price;
            cin>>nam>>quantity>>price;
            Item obj(price,quantity,nam);
            if(employer.Additems(obj)){
                cout<<"The item Added succesfully to the shop"<<endl;
            }
            else{
                cout<<"Added failed"<<endl;
            }
        }
        else if(number==3){
            cout<<"please enter item name,quantity "<<endl;
            string s;
            int quntit;
            cin>>s>>quntit;
            if(!employer.sellitems(s,quntit)){
                cout<<"failed to sell "<<endl;
            }
            else{
                cout<<"SOLD"<<endl;
            }

        }
        else if(number==4){
            employer.printitems();
        }
        else if(number==5){
            cout<<"please enter id to search for it: "<<endl;
            int Id;cin>>Id;
            //condition to check if this id has product or not
            if(employer.find_item(Id) == nullptr){
                cout<<"Not found"<<endl;
            }
            else{
                cout<<"found"<<endl;
            }
            // employer.search_with_id(Id);
        }
        else{
            return 0;
        }
    }

    return 0;
}