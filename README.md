<h1 align="center"><em>Anime Catalog in C++ using Doubly Linked List</em></h1>

## About the Project
C++ Project based on an **anime catalog** that loads data from a *.csv file* and stores it in a *Doubly Linked List*(no libraries) containing the following attributes:
- Name
- Number of seasons
- Number of episodies
- Release date
- Finish year*
- Main genre
- Status**

## Functions
- Display an especific **interval** or **print the entire catalog** sorted by *name*, *genre*, *latest releases* or *no filters*.
- **Filter the catalog** (name, season, episode, year, genre and status)
- **Add**, **overwrite** and **remove** animes
- Save changes option*** (internal list and/or file)

> *If the anime is still ongoing, *Finish Year = 0*.

> **Status can be *“In Progress”* or *“Finished”*.

> ***The inserted data represent the current state of the anime at the time of insertion into the catalog.

## Available Genres
- Ação(Action)
- Aventura(Adventure)
- Comédia(Comedy)
- Corrida(Race)
- Drama(Drama)
- Esporte(Sport)
- Romance
- Slice of Life
- Supernatural
- Terror

## How to Start
1. Clone or download the repository
```bash
  cd *desired directory*
  git clone https://github.com/LuizGustavo1001/Anime-Catalog-in-cpp.git
```
2. Open **CatalogoLista.cpp** and compile the program.

## Future Changes
- Enable simultaneous filters
- Implement sorting directly within the list class (without the auxiliary vector)
- Use a binary file to store the *.csv* content for improved performance.
- Change the entire program leanguage to English.


