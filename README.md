# shootingRio_1.2
This is a simple 2D game created by me on my 2nd semister in University using iGraphics.
Shooting Rio

Overview

Shooting Rio is an action-packed 2D shooting game developed using iGraphics in C. Players control a skilled fighter defending the city from enemy drones and aerial threats. The game features engaging shooting mechanics, power-ups, and strategic gameplay elements for an immersive experience.

Features

Player Movement: Control a fighter moving horizontally and vertically.

Shooting Mechanics: Players fire bullets to eliminate enemy drones.

Wave System: Enemies attack in increasing difficulty with progressive levels.

Power-Ups: Health packs, rapid-fire mode, and shield boosts.

Scoring System: Players earn points based on successful hits and streaks.

Boss Battles: Every 3rd wave introduces a powerful enemy boss.

Game Over Conditions: The game ends when the player runs out of health or if too many enemies invade.

Technologies Used

Programming Language: C, C++

IDE: Visual Studio 2010/2013

Graphics Library: iGraphics

Platform: Windows PC

Code Structure

The game consists of multiple modules:

main.c – Initializes the game, starts the iGraphics engine.

player.c – Handles player movement and shooting.

aliens.c – Manages enemy waves.

collision.c – Detects collisions between player bullets and enemies.

scoring.c – Updates the player's score and tracks high scores.

Challenges & Solutions

Challenge

Solution

Collision detection issues

Implemented precise bounding box checks

Player movement delays

Optimized frame update rate for smooth control

Repetitive enemy patterns

Introduced randomized enemy formations

Screenshots

![Screenshot 2025-03-18 095618](https://github.com/user-attachments/assets/f2c8dfae-e990-49ca-b2bb-834070594c83)
![Screenshot 2025-03-18 095755](https://github.com/user-attachments/assets/8d22307c-3975-4631-b623-f06fb7c84eb4)

Figure 1: Player Shooting Enemies

Figure 2: Boss Battle Scene

Future Enhancements

Multiplayer Mode: Introduce a co-op mode for two players.

Sound Effects: Add gunfire sounds, background music, and explosions.

Advanced Graphics: Enhance enemy animations and background environments.

How to Run

Clone this repository.

Open the project in Visual Studio 2010/2013.

Build and run the project.

Contributors

MD. All-Nur-Bin Khuobaira (ID: 20230204065)

Minhal Riaz (ID: 20230204066)

Rhidoy Kumar Paul (ID: 20230204074)

License

This project is open-source and available under the MIT License.

