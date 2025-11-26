# 🕹️ Pong Clone (C++ & raylib)

This is a simple, two-player implementation of the classic arcade game **Pong**, built using C++ and the **raylib** game development library.

---

## 🚀 How to Play

### 1. Game Objective

The goal is to hit the ball past your opponent's paddle. Scoring happens when the ball passes the opponent's side of the screen. The first player to reach a set score wins (though the current game loops indefinitely).

### 2. Controls

| Player | Action | Key |
| :--- | :--- | :--- |
| **Paddle 1** (Left) | Move Up | **W** |
| **Paddle 1** (Left) | Move Down | **S** |
| **Paddle 2** (Right) | Move Up | **UP ARROW** (↑) |
| **Paddle 2** (Right) | Move Down | **DOWN ARROW** (↓) |
| **Global** | Pause/Unpause | **SPACEBAR** |

---

## 💻 Setup and Running the Game

Follow these steps to download and run the game on your PC using **Visual Studio** (as the project uses a `.sln` file):

### Prerequisites
* You must have **Visual Studio** (with C++ development tools) installed.

### Step-by-Step Instructions

1.  **Clone the Repository:**
    Download the project files to your local machine:
    ```bash
    git clone [Your Repository URL Here]
    ```

2.  **Open the Solution:**
    Open the main solution file:
    ```
    PongGame.sln
    ```
    This will launch the project in Visual Studio.

3.  **Install raylib (Dependency):**
    Since this project relies on **raylib**, you must install it using NuGet:
    * In Visual Studio, right-click the project in the Solution Explorer.
    * Select **"Manage NuGet Packages..."**.
    * Go to the **"Browse"** tab and search for the appropriate raylib package (e.g., `raylib` or a C++-specific wrapper).
    * Install the package to link the necessary libraries.

4.  **Run the Game:**
    Build and run the program (typically by pressing **F5** or selecting **Debug > Start Debugging**).

---
