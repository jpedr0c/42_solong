<h1 align=center>
  <strong> SO_LONG </strong>
</h1>

<p align="center">
  <sub> C program to redirect process output to input via pipes and execute specified commands in a file.
  <sub>
</p>


[![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/colored.png)](#table-of-contents)

<p align="center">
  <a href="#About"> 💡 About the project </a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#HowUse"> ⚙️ How to use</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
    <a href="#HowWork"> 🕹️ How to play</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#Credits"> 🏆 Credits</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</p>

<br/>

<a id="About"></a>
## 💡 About the project
> This project involves creating a C program that redirects the output of one process to the input of another process using pipes. The goal of the project is to create a program that is capable of executing two commands (e.g., cat and grep) and redirecting the output of the first command as input to the second command using pipes. The program should be able to read a file and execute the commands specified in it.

<br/>

<a id="HowUse"></a>
## ⚙️ How to use

1. Clone this repository
```sh
git clone https://github.com/jpedr0c/42_solong.git
```
2. In the project directory, compile the program using the following command
```sh
make
```
3. Run the game
```sh
./so_long maps/map.ber
```
- Where "maps/map.ber" is the path to the map file that you want to use in the game. You can use any map file provided in the "maps" folder or create your own.
4. If you want to remove the object files generated during compilation
```sh
make clean
```
5. If you want to remove the object files and executable generated during compilation
```sh
make fclean
```

<br/>

<a id="HowPlay"></a>
## 🕹️ How to play
> The objective of the game is to collect all collectibles and then exit through the exit door. You must avoid colliding with walls and enemies, otherwise, you will lose the game.

The game's control keys are as follows:

- `W`: move up
- `S`: move down
- `A`: move left
- `D`: move rigth
- `ESC`: quit the game

<br/>

<a id="Credits"></a>
## 🏆 Credits
***Thank you for taking the time to review my project. If you have any questions or would like to connect with me, please feel free to reach out to me on [LinkedIn](https://www.linkedin.com/in/jpedroc)***
