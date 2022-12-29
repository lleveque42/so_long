# So Long for 42cursus

This project is a very small 2D game. Its purpose is to make us work with textures, sprites, and some other very basic gameplay elements. 
The goal is to improve our skills in the following areas: window management, event handling, colors, textures, and so forth.  
We are using the school graphical library Minilibx that includes basic necessary tools to open a window, create images and deal with
keyboard and mouse events.

The game is about a character that needs to collect all the collectibles on the map before escaping.

### My grade :mortar_board:
[![lleveque's 42 so_long Score](https://badge42.vercel.app/api/v2/clc6bxaur00060fmon220zhly/project/2451984)](https://github.com/JaeSeoKim/badge42)

### Usage :desktop_computer:

#### :warning: Only works on linux :warning:

First:
  
    git clone https://github.com/lleveque42/so_long/
    cd so_long
  
Then:

    make
    
<p align="center">
    <img src="https://github.com/lleveque42/so_long/blob/master/readme/so_long_make.gif">
</p>

Finally:

    ./so_long map.ber
    
// AJOUTER LE GIF DU JEU

It will create a new window where you'll be able to play the game.

The W, A, S, and D keys or arrows can be used to move the character. You can go up, down, left and right. Your number of movements is displayed in your terminal.  
Pressing ESC or clicking the cross on the window's frame will close the game.

You can design your own maps by modifying map.ber or creating a new .ber file. The map can be composed of only these 5 characters:   
- 0 for an empty space  
- 1 for a wall  
- C for a collectible  
- E for a map exit  
- P for the player’s starting position.  

The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.  
It must be rectangular and surrounded by walls.

This is a valid map:

    1111111111111  
    10010000000C1  
    1000011111001  
    1P0011E000001  
    1111111111111  

This is not a valid map:

    111111111  
    1001000001111  
    1000011111001  
     11011E000001  
    1111111100111  
