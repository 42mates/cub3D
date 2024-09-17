## Introduction
"Cub3D" is a 3D game developed in C using the MiniLibX graphics library, which emulates 3D textures using the raycasting technique.

<div align="center">
	<img src=".vids/cub3d_basement.gif" alt="cub3d_trees.gif">
</div>

## Code Implementation

This project relies on [**raycasting**](https://en.wikipedia.org/wiki/Ray_casting), which is a rendering technique used to create a 3D perspective in a 2D environment. It works by **casting rays** from the player's position in the direction they are facing. Each ray is traced until it hits a wall, and the **distance to the wall** is used to determine the height of the wall slice to draw on the screen. This process is repeated for **each vertical slice** of the screen, creating a 3D illusion:

<div align="center">
	<img src=".vids/wiki_raycasting.gif" alt="cub3d_trees.gif">
</div>

Every time the user moves, a new image is created from the `ray_casting()` function based on the player's position in the map and their orientation. This new image is then instantly drawn on the screen.

## User Experience

The game is controlled using the `←` and `→` keys or by using the mouse for direction and `W`, `A`, `S`, `D` for movement. The goal of the game is to navigate through a 3D map. The program exits by pressing `Esc` or by clicking the window's `❌` button.


## Features

Besides the basic map rendering, the program also includes the following features:
- **Map parsing**: the program analyses the map sent as an argument and returns an error in case it doesn't meet the subject requirements.
- **Wall collisions**: based on the map's layout and the player's position, the player cannot move further than the map's limitations.
- **Minimap**: a minimap appears at the top left of the screen. It can be toggled using the `M` key, and it can be zoomed in or out using the `-`/`+` keys.

## Try Me!

### Requirements
To build the game, you must use a stable version of Linux with a graphical environment such as [GNOME](https://wiki.gnome.org/Projects/GnomeShell/Extensions/StepByStepTutorial#Installing_GNOME_Shell_Extensionsand) and have the [X11](https://www.x.org/wiki/) library installed on your system. You must also meet the [minilibx](https://github.com/42Paris/minilibx-linux)'s following requirements:

>  - MinilibX only support TrueColor visual type (8,15,16,24 or 32 bits depth) 
> - gcc
> - make
> - X11 include files (package xorg)
> - XShm extension must be present (package libxext-dev)
> - Utility functions from BSD systems - development files (package libbsd-dev)  

For example:
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev (Debian/Ubuntu)
```  
### Installation

First, download the source code, either by cloning the repository in your shell:
```bash
git clone https://github.com/42mates/cub3d.git
```

Create the program:
```bash
make
```

### Running the game

to run the game, simply run the program with the map as argument:
```bash
./cub3d example.cub
```
Replace `example.cub` with the path to the map file you want to play. You can find some in the [maps](./maps) repository.   


### Enjoy the 3D experience!
<div align="center">
	<img src=".vids/cub3d_trees.gif" alt="cub3d_trees.gif">
</div>

