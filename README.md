# OOP_Online_Shopping_System
Using classes and arrays, the team will develop a set of functions for an online shopping system. The system is represented by the following structure:
1- Class Item having the following private attributes: (ID, name, quantity, price) and the following public methods:
- Constructors (default, parameterized, and copy)
- Setters & Getters
- Operator overloading for the ==, +=,-=, >> and << operators
2- Class Seller having the following private attributes: (name, email, items,maxItems), where items is a dynamic array of objects of type Item with the size maxItems. The class has the following public methods:
- Constructor (parameterized)
- Operator overloading for the >> and << operators
- Add An Item.
- This will take an Item object as a parameter:
- If the item already exists in the seller's items you will increase the item’s quantity by the quantity of the parameter item using the (+=) in Item class, and the price of the parameter object will be ignored. Use the == operator for this where an item is equal to another if they have the same name.
- Else you will add it to the seller’s items.
- The member function should return a boolean that indicates the successful addition of item, which will succeed if there is a place in the array and fail otherwise.
- Sell An Item.
- This will take an item name and a quantity as parameters
- If the quantity is <= item’s quantity you will decrease it from item Using the (-=) in Item class.
- Else you will print him “There is only {quantity} left for this item”.
- The member function should return a boolean which is true if the item was found, false otherwise.
- Print Items.
- This will print all the item information for the seller.
- You will print each item using the (<<) operator.
- Find an Item by ID
- This returns an Item object (or a pointer to Item) with the specified ID if there is an item with such ID.
- Destructor
- 3- In the main function, ● First you’ll ask the seller to input his details using the (>>) operator in Seller class.
● Then you’ll ask him for his store capacity (maxNumberOfItems).
● Then you will show him a menu to choose from which have the following options:
1. Print My Info.
a. This will print the seller info using the (<<) operator in Seller class.
2. Add An Item.
3. Sell An Item.
4. Print Items.
5. Find an Item by ID
6. Exit
