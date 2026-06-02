# Technical Design Document: Poker Run System (Kelompok 7)

## Project Overview
This project is a C++ implementation of a roguelike Poker evaluation system, inspired by games like "Balatro". Players navigate through a series of "Blinds" (rounds), accumulating points by playing poker hands and strategically using **Jokers** and **Skip Tags** to scale their power.

The system is designed with a focus on **Design Patterns** to ensure modularity, allowing easy addition of new hand types, rewards, and game rules.

### Core Game Loop
1.  **Blind Initialization**: The system sets a target score based on the current `BlindState` and `Ante`.
2.  **Strategic Decision**: Players choose to **Play** the blind or **Skip** it. Skipping triggers a **SkipCommand** (Tag reward).
3.  **Hand Evaluation**: If playing, cards are drawn from a `Deck`. Selected cards are evaluated via a **Chain of Responsibility**.
4.  **Score Modification**: Base scores are passed through active **Jokers** for chip and multiplier bonuses.
5.  **Economy & Progression**: Winning grants money to spend in the **Shop**. Defeating a Boss Blind increases the difficulty (Ante).

---

## Architectural Design Patterns

### 1. Chain of Responsibility (Hand Identification)
Used to decouple the identification of poker hands from the scoring logic.
-   **Structure**: Each `PokerHandChecker` (e.g., `FlushChecker`, `PairChecker`) knows how to identify one specific hand.
-   **Behavior**: If a checker identifies a hand, it returns the rank; otherwise, it passes the request to the `nextChecker`.
-   **Advantage**: New hand ranks (like "Flush Five") can be added by simply inserting a new checker into the chain.

### 2. State Pattern (Game Flow & Difficulty)
Manages the progression of the game through different phases.
-   **Structure**: `BlindState` is the interface. Concrete states are `SmallBlindState`, `BigBlindState`, and `BossBlindState`.
-   **Behavior**: Each state defines its own target score multiplier and reward money. The `nextState()` method handles the transition (e.g., Boss Blind increments the Ante and cycles back to Small Blind).

### 3. Command Pattern (Skip Rewards / Tags)
Encapsulates the rewards granted for skipping a blind as executable objects.
-   **Structure**: `SkipCommand` is the interface with an `execute(GameManager&)` method.
-   **Concrete Commands**:
    -   `MoneySkipCommand`: Grants a flat amount of cash.
    -   `FreeJokerSkipCommand`: Sets a flag to make the next shop item free.
    -   `ExtraHandSkipCommand`: Increases the hand limit for the next round.
    -   `AddCardSkipCommand`: Adds a permanent random card to the deck.
-   **Advantage**: The `GameManager` doesn't need to know the details of the reward; it simply calls `execute()`.

### 4. Factory Pattern (Randomized Content)
Centralizes the creation of randomized game elements.
-   **`JokerFactory`**: Shuffles and filters a pool of Jokers to present unique options in the Shop.
-   **`SkipCommandFactory`**: Randomly selects a `SkipCommand` to be attached to Small and Big Blinds, ensuring variability in skip rewards.

---

## Key Components

| Component | Responsibility |
| :--- | :--- |
| **`GameManager`** | The central hub. Manages player stats, inventory, active Jokers, and orchestrates the main loop. |
| **`Deck`** | A persistent collection of `Card` objects. Supports adding cards permanently during a run. |
| **`ScoringRule`** | Manages the Chain of Responsibility and converts identified Ranks into base Chips and Multipliers. |
| **`HandPlayer`** | Handles user interaction and card selection from the current hand. |
| **`Shop`** | Manages the purchasing of `Jokers` and handles "Free Tag" logic. |

---

## Development & Extension Guide

### Adding a New Hand Rank
1.  Create a new class inheriting from `PokerHandChecker`.
2.  Implement identification logic in `check()`.
3.  Register the new checker in `ScoringRule.cpp` and define its base chips/multiplier in `convertRankToScore`.

### Adding a New Skip Reward (Tag)
1.  Create a new class inheriting from `SkipCommand`.
2.  Implement the reward logic in `execute(GameManager& gm)`.
3.  Add the new command to the randomization pool in `SkipCommandFactory.cpp`.

### Adding a New Joker
1.  Inherit from `Joker`.
2.  Override `applyScoreBonus(const Hand&, ScoreResult&)` to modify the chips or multiplier.
3.  Add the Joker to the `generateFullJokerPool` method in `JokerFactory.cpp`.

---

## Building and Running

**Requirements**: C++17 compatible compiler (g++, clang++, or MSVC).

**Compilation**:
```bash
g++ -std=c++17 *.cpp -o poker
```

**Execution**:
```bash
./poker
```
