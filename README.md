 # Snakey Game
 
 ## Description
 Snakey is a simple game where the player controls a snake that moves around the screen, eating fruits to grow longer while avoiding hitting itself and the game borders.
 
 **Note:**
 - This project uses SDL2 library for graphics and input handling.
 - The project is considered to be built and tested in a Linux environment. It has not been tested for other platforms.
 
 ## Project Structure
 ```
 Snakey/
 │
 ├── bin/             # Directory for compiled executable
 │
 ├── doc/             # Documentation files
 │   └── README.md   # Project README file
 │
 ├── res/             # Resource files such as images or sounds
 │   └── game_over.bmp
 │
 ├── src/             # Source code files
 │   ├── Game.cc      # Implementation of the Game class
 │   ├── Game.hpp     # Declaration of the Game class
 │   ├── Fruit.cc     # Implementation of the Fruit class
 │   ├── Fruit.hpp    # Declaration of the Fruit class
 │   ├── Snake.cc     # Implementation of the Snake class
 │   ├── Snake.hpp    # Declaration of the Snake class
 │   └── main.cc      # Main function to start the game
 │
 └── README.md        # Project README file
 ```
 
 ## Usage
 
 ### Build
 To build the Snakey game, follow these steps:
 
 1. Clone the repository:
    ```
    git clone https://github.com/yourusername/Snakey.git
    ```
 
 2. Navigate to the project directory:
    ```
    cd Snakey
    ```
 
 3. Create a build directory:
    ```
    mkdir build
    ```
 
 4. Navigate to the build directory:
    ```
    cd build
    ```
 
 5. Generate build files using CMake:
    ```
    cmake ..
    ```
 
 6. Build the project:
    ```
    make
    ```
 
 ### Run
 Once the game is built, you can run it from the command line:
 
 1. Navigate to the build directory if you're not already there:
    ```
    cd Snakey/build
    ```
 
 2. Run the game executable:
    ```
    ./bin/Snakey
    ```
 
 This command will execute the Snakey game, allowing you to play it directly from the terminal.
 
 ### Gameplay
 - Use the arrow keys to control the direction of the snake.
 - The snake will automatically move in the chosen direction.
 - Eat fruits to grow longer.
 - Avoid hitting itself and the game borders.
 - The game ends when the snake hits itself or the borders.
