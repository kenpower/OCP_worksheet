# Applying the Open/Closed Principle (OCP)

Objective: Refactor the provided SFML game code to follow the Open/Closed Principle (OCP). 
The goal is to extend the behavior of the game to allow for the addition of new target types (e.g., squares and cars) without modifying the existing code.

Instructions:

Define a Target Interface: Create an interface named Target that declares methods common to all target types. This interface should include methods for drawing the target and checking if a point is inside the target.
Implement Concrete Target Classes: Implement the Target interface for each target type (CircleTarget, SquareTarget, and CarTarget). Ensure that each class provides its own implementation of the draw and isPointInside methods.
Modify the Game Class: Update the Game class to use the Target interface instead of directly using concrete target classes. This means the Game class should interact with targets through the Target interface, allowing it to work with any target type that implements this interface.
Test Your Implementation: Write a main method to create instances of your target classes, add them to a list in the Game class, and run the game to ensure that all target types can be added and interacted with without any issues.
