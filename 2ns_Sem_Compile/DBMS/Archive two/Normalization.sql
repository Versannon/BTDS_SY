-- Normalization in MySQL

drop database if exists Normalisaion;
create database Normalisation;
use Normalisation;

-- 1 NF (Each cell must contain a single (atomic) value, and there should be no repeating groups)
/*
CREATE TABLE Orders(
    OrderID INT,
    CustomerName VARCHAR(100),
    CustomerCity VARCHAR(100),
    ItemID INT,
    ItemName VARCHAR(100),
    Price DECIMAL(10, 2),
    PRIMARY KEY (OrderID, ItemID) -- Composite Key
);

insert into Orders(OrderID,CustomerName,CustomerCity,ItemID,ItemName,Price)
values
(101,'Aryan Suryavanshi','PUNE',1,'Burger',100.20),
(102,'Dhawal Chaudhari','PUNE',2,'Dhokla',50.22);
*/

-- 2 NF (Must be in 1NF, and not contain any partial dependency(primary should not contain duplicate values))
/*
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    CustomerName VARCHAR(100),
    CustomerCity VARCHAR(100)
);
insert into Orders(OrderID,CustomerName,CustomerCity)
values
(101,'Aryan Suryavanshi','PUNE'),
(102,'Dhawal Chaudhari','PUNE');

CREATE TABLE OrderItems (
    OrderID INT,
    ItemID INT,
    ItemName VARCHAR(100),
    Price DECIMAL(10, 2),
    PRIMARY KEY (OrderID, ItemID),
    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID)
);
insert into OrderItems(OrderID,ItemID,ItemName,Price)
values
(101,1,'Burger',100.22),
(102,2,'Dhokla',50.55);

Select Orders.OrderID,Orders.CustomerName,OrderItems.ItemName
from Orders Inner Join
OrderItems on Orders.OrderID=OrderItems.OrderID;
*/

-- 3 NF (Must be in 2NF, and non-key columns should not depend on other non-key columns i.e. no transitive dependency)

-- 1. Customers Table
CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY,
    CustomerName VARCHAR(100),
    City VARCHAR(100)
);
insert into Customers(CustomerID,CustomerName,City)
values
(8,'Aryan Suryavanshi','Pune'),
(28,'Dhawal Chaudhari','Pune');

-- 2. Products Table
CREATE TABLE Products (
    ProductID INT PRIMARY KEY,
    ProductName VARCHAR(100),
    Price DECIMAL(10, 2)
);
insert into Products(ProductID,ProductName,Price)
values
(1111,'Burger',100.55),
(2222,'Dhokla',50.55);

-- 3. Orders Table (Links Customer to a point in time)
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    CustomerID INT,
    OrderDate DATE,
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);
insert into Orders(OrderID,CustomerID,OrderDate)
values
(101,8,'2026-03-23'),
(102,28,'2026-03-23');

-- 4. OrderDetails Table (The final junction)
CREATE TABLE OrderDetails (
    OrderID INT,
    ProductID INT,
    Quantity INT,
    PRIMARY KEY (OrderID, ProductID),
    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID),
    FOREIGN KEY (ProductID) REFERENCES Products(ProductID)
);

insert into OrderDetails(OrderID,ProductID,Quantity)
values
(101,1111,2),
(102,2222,4);


