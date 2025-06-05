# Marine Species Tracker

A simple C program to record and track marine species data, supporting SDG 14: Life Below Water.

## What it does

This program helps marine researchers record information about sea creatures they find. It stores data like species name, type, length, and other details.

## Features

- Add new marine species records
- View all recorded species
- Search by species type (Fish, Mammal, Crustacean, Mollusk)
- Delete records
- Show basic statistics
- Input validation to prevent errors

## How to run

1. Compile the program:
   ```bash
   gcc -o marine_tracker marine_tracker.c
   ```

2. Run it:
   ```bash
   ./marine_tracker
   ```

## How to use

The program shows a menu with 6 options:

1. **Add Record** - Enter a new species
2. **List All Records** - See all your data
3. **Search by Species** - Find specific types
4. **Delete Record** - Remove an entry
5. **Show Statistics** - See summary data
6. **Exit** - Close the program

### Example:
```
Enter name: Blue Whale
Enter Species:
0 = Fish
1 = Mammal
2 = Crustacean  
3 = Mollusk
Choice: 1
Length (cm): 2500
Average weight (kg): 150000
```

## Team Members

- **David Alexander** (2406351592) - Core structures and memory management
- **Nicholas Edmund** (2406352986) - Display functions and integration  
- **Tubagus Dafa Izza Fariz** (2406350122) - User interface and input validation
- **M. Rifqi Fadil** (2406355306) - Search and statistics functions

## Course Info

- **Course**: Basic Programming (Pemrograman Dasar)
- **University**: Universitas Indonesia, Faculty of Engineering
- **Year**: 2025
- **Instructor**: Prof. Dr. Ir. Anak Agung Putri Ratna, M.Eng

## GitHub

Repository: https://github.com/davidalexander24/FINPRO_PROGDAS
