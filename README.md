# DODGE-EM-Car-Game



DODGE EM…… 

**Description:** 

Dodge 'Em is a 1980 Atari 2600 driving game based on a single screen of concentric roadways. The game was programmed by Carla Meninsky and released by Sears for the "Sears Video Arcade" under the name Dodger Cars. 

![](Aspose.Words.89903fe2-cebf-4592-a762-3fe01abc5d2f.002.jpeg)

**Player Vs. Opponent:** 

The game is played in a racing arena where the player drives his brown colored car to pick the maximum rewards, avoiding a head-on collision with the blue opponent car(s) run by the computer (figure 1). The player car moves anti-clockwise while the opponent car(s) move clockwise only. When the game starts, the player is awarded three lives to collect the rewards from the arena. The player gets one reward point when his/her car picks up any rectangularshaped gift-boxes placed at equal distances in the arena. When the player car hits the opponent car, one life is lost and the game arena is refilled with the reward gift-boxes. The score and the number of lives left are visible on the top of the screen. 

![](Aspose.Words.89903fe2-cebf-4592-a762-3fe01abc5d2f.003.png)

**Driving rules:** 

Each roadway in the arena has four turns – one each after covering one-fourth of the roadway. The player car starts from the middle of the topmost roadway on the screen, while the opponent car(s) start randomly at any turn at least one turn away from the player car on the same roadway. The player car is controlled by the keyboard – arrow keys to turn and spacebar to drive at the double speed than normal. The opponent car(s) makes the decision to take a turn or not on the basis of distance from the player car, i.e. it takes the turn if taking the turn brings it closer to the roadway in which the player car is moving. 

**Game levels:** 

A new level starts when the player picks up all the gift boxes in the arena. The player gets 100 reward points and the arena is refilled with the gift boxes. All the cars also restart from their respective positions (as explained above in the driving rules). 

Level 1: At this level, the opponent car is less active and can only take the top and the bottom turns on any roadway. However, the player can take any of the four turns to avoid the collision.  

Level 2: At this level, the opponent car is in the active mode and can take any turn just like the player car. 

Level 3: At this level, the opponent car is in active mode and its speed is also doubled. Level 4: At this level, two opponent cars start chasing the player car in the active mode as in  level 2. For this level, the opponent cars should not start at the same location. 

At the completion of the level 4, the game finishes after displaying a message, “You won!”. 

**High scores:** 

When the game starts, the high-scores are read from a file (named highscores.txt) on the hard- disk and stored in an array of size 10. If the score of the current game makes to the list of high- scores, the lowest score is removed from the array and the new contents of the array overwrite the file. 

**Menu:** 

The game should be menu-driven and the following options should be available to the user: 

1) Start a new game 
1) See high-scores 
1) Help 
1) Exit During the execution of the game, 

` `the player can press the ‘P’ key to pause the game and see the following menu: 

1) Start a new game 
1) See high-scores 
3) Help 
3) Exit 
3) Continue 


