# Pokémon Battle Game

## Overview

This project is a text-based Pokémon battle game implemented in C++. It allows two players to engage in a turn-based battle using their chosen Pokémon. Each Pokémon can learn up to four moves, and the game includes mechanics for move selection, damage calculation, status effects, and Pokémon leveling up.

## Features

- Turn-based combat between two trainers.
- Each Pokémon can learn up to four moves.
- Move selection with damage calculation and accuracy checks.
- Status effects such as poison and paralysis.
- Automatic leveling up of Pokémon when they win a battle.

## Classes

### Pokémon

- **Attributes:**
  - `Name`
  - `Type`
  - `Health`
  - `Attack`
  - `Defense`
  - `Special Attack`
  - `Special Defense`
  - `Speed`
  - `Level`
  - `Experience`
  - `Moves` (list of `Move` objects)
  - `Is Wild`

- **Methods:**
  - `attackOpponent(opponent, move)`
  - `takeDamage(damage)`
  - `gainExperience(exp)`
  - `levelUp()`
  - `learnMove(move)`
  - `getStat(stat)`
  - `applyStatusEffect(effect)`
  - `handleStatusEffects()`
  - `getMoves()`
  - `getName()`

### Move

- **Attributes:**
  - `Name`
  - `Type`
  - `Power`
  - `Accuracy`
  - `Category` (Physical, Special)
  - `Effect` (optional)

- **Methods:**
  - `applyEffect(target)`

### Trainer

- **Attributes:**
  - `Name`
  - `Team` (list of `Pokemon` objects)
  - `Inventory` (list of `Item` objects)

- **Methods:**
  - `catchPokemon(wildPokemon)`
  - `useItem(item, target)`
  - `battle(opponent)`
  - `getTeam()`

### Item

- **Attributes:**
  - `Name`
  - `Type`
  - `Effect`

- **Methods:**
  - `use(target)`

### Pokéball

- **Attributes:**
  - `Name`
  - `Catch Rate`

- **Methods:**
  - `catchPokemon(target)`

## How to Run

1. **Prerequisites:**
   - Make sure you have `g++` installed. You can check this by running `g++ --version`.

2. **Compilation:**
   - Navigate to the project directory.
   - Run the following command to compile the project:
     ```sh
     g++ Pokemon.cpp Move.cpp Item.cpp Trainer.cpp Pokeball.cpp main.cpp -o pokemon_game
     ```

3. **Execution:**
   - After successful compilation, run the executable:
     ```sh
     ./pokemon_game
     ```

4. **Gameplay:**
   - Enter the names for Trainer 1 and Trainer 2 when prompted.
   - Both trainers will take turns to choose a move for their Pokémon.
   - The game will display the current HP of the Pokémon after each attack.
   - The battle continues until one Pokémon faints.
   - The winning Pokémon will automatically level up if it wins the battle.


## License

This project is open-source and available under the MIT License.

## Acknowledgments

- Inspired by the Pokémon game series.
- Developed as a learning project for understanding OOP concepts in C++.
