# Robot
*This is the first part of a programming project I done in the academic year 2019/2020*

Simulation of a robot movements into room. Room's floor is made by square boxs also room has inner and outer walls as is showed into the pictures below, feature of inner walls is at each execution their location and size changes. Before simulation start, user can choose size of the room so size of walls depend on this. Robot can move on one of the four directions  
(forward, behind, right, left) but he can always moves only one box at a time. Robot can estimate in the four directions the free boxes up to the wall. In 30% of cases the robot moves randomly in one of the four possible neighboring boxes (considering the presence of a wall), in 70% of cases chooses the direction with more free blocks (in the case of multiple routes of maximum length, the direction is chosen at random among these). In each case, the robot must never step in one direction and to the next phase a step in the opposite direction. The simulation ends when the robot "exits the door" of the room (bottom left into the picture). Program show robot's path step by step showing his position and the room.

![Screenshot (2)](https://user-images.githubusercontent.com/60264767/141704136-e5fca6be-3aa2-4987-abdc-c75a29b5f785.png)
