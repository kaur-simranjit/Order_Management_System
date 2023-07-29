# Order_Management_System
The project is about order management system using C++ and it is UML-focused.
* Admin can add, modify, delete and search products.

Note: Kindly view the UML diagram for better understanding.

UML diagram is based on the following scenario:
* Customer make order. Customers can be either corporate customer or personal customer.
* There is a association between employee and corporate customer. Zero or more corporate customer create from employees. An employee can or cannot be corporate customer.
* Order is composed of customer. The order could contain extract one customer, while each customer can make many orders.
* There is an association between order and order line. An order can have zero or many order line.
* Order line and product has association.

The code also uses a design pattern: Template Method.
