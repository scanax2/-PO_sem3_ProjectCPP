# Game Mars Colony

## Tags: terminal based game, turn-based strategy, resource management

A simple game, developed at using C++ Standard Library. The concept of the project was originally 
intended for the game jam ([Game off 2020](https://itch.io/jam/game-off-2020)) on Unity3D engine, but i couldn't make it on time, so i simplified the game
and converted it to C++ and made it terminal based.

### Short description:
You develop the colony on Mars by sending spacecrafts to it. To beat the game you need 
bring the colony's progress to 100 and keep the colony's population within the range of 350 (abandoned) to 1000 (overpopulated) people.
Going beyond 350 and 1000 is an automatic loss. You can send one spacecraft in one day (turn).

* **Colony**
  * Have water supplies <0,100>.
  * Have food supplies <0,100>.
  * After every day (turn), colony consumpting water and food:
    * consumpted water: 0.05 * population 
    * consumpted food : 0.04 * population
  * After every day (turn), colony population is increasing:
    * produced population: food / 100 * population / 2
    * in case of lack of water: population -= population / 2.5
    * in case of lack of food: population -= population / 2
  * After every day (turn), colony progress is increasing:
    * then closer the population is to the median, then greater the progress.
  <pre>
      350 (+0 units)         675 (+12 units)        1000 (+0 units)
       | ---------------------|--------------------- |
  </pre>
   
There are 3 types of spacecrafts:
* **Cargo**
  * Have **4 slots (cells)** for supply.
  * Delivers food or water supply.
  * One water cell equals **40 units of water**.
  * One food cell equals **35 units of food**.
  * You are not forced to load all the cells.
  
* **Passenger**
  * Have **3 slots (cells)** for passengers.
  * Delivers new population.
  * One passenger cell equals **50 units of the population**.
  * You are not forced to load all the cells.
 
* **Missile**
  * Have **2 slots (cells)** for uranium charges.
  * Reduces population, preventing overpopulation.
  * One missile cell equals **50 units of death (-50 units of the population)**.
  * You are not forced to load all the cells.
  
 
## Usage
Clone repo. Open in VSC repo folder. Select main.cpp. To compile use Ctrl+Shift+B (Run build task) or
install in Extensions: 'CMake Tools' and after it, from the command palette in VS Code, run the CMake: Build command, press the keyboard shortcut F7, or select the Build button in the status bar.


