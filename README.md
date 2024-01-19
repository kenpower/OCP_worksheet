# OCP_worksheet

## Objective

Refactor[^1] the code so that, in the future we can add additional character types, without needing into modify existing code, thereby making the Game *"open to extension"*

## Steps

### Part 1 refactor

You should only refactor code in Game::Interact and the Character class and it's sub-classes.

1. There is a lot of feature envy in Game::Interact, remove it.
2. Remove the if...else structure with polymorphisim
3. Remove any duplicate code
4. Check code runs correctly and commit

### Part 2 

Add a Mage class to the game. You should be able to do this *without* changing the game class.
Add the correct behaviour to the mage class (see comments)

Check the mage class functions correctly and commit.

## Submit


[^1]: Refactor: change the code structure, but do not change the behaviours
