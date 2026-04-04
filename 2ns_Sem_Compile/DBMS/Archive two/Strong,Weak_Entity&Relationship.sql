-- Strong Entity and Weak Entity

drop database if exists Hello;
create database Hello;
use Hello;

CREATE TABLE Buildings (
    BuildingID INT PRIMARY KEY,      -- Strong Entity
    BuildingName VARCHAR(100),
    CampusZone VARCHAR(50)
);
insert into Buildings(BuildingID,BuildingName,CampusZone)
values
(101,'Oxford','North'),
(102,'Oxford','South'),
(103,'Oxford','East'),
(104,'Oxford','West');

CREATE TABLE Rooms (
    BuildingID INT,                  -- Borrows the ID from the strong entity
    RoomNumber VARCHAR(10),          -- The room's partial identifier (e.g., "101")
    RoomType VARCHAR(50),
    Capacity INT,
    
    PRIMARY KEY (BuildingID, RoomNumber),  -- A room is identified by combining the Building AND the Room Number.
    
    FOREIGN KEY (BuildingID) REFERENCES Buildings(BuildingID) ON DELETE CASCADE  -- It ensures that if the strong entity is deleted then weak entity also gets deleted														
);
insert into Rooms(BuildingID,RoomNumber,RoomType,Capacity)
values
(101,202,'Storage Closet',20),
(101,201,'Lecture Hall',50);
