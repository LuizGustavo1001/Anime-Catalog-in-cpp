<em>Anime Catalog in c++ using Double Linked List, that can: show an interval, find with a filter, write/ overwrite or remove animes.</em>

➔ User: <a href="https://github.com/LuizGustavo1001/">Luiz Gustavo De Almeida Lopes</a>

<em>About the Project</em>

➔ C++ Project based in a <strong>Catalog of animes</strong> that comes from a .csv file and will be stored in a Double Linked List with the Name, Number of Seasons, Number of Episodes, Release Year, Finish Date*, Main Genre and Status** with the possibility of:

<ol type="I">
  <li> Show an Interval or Print the entire Catalog in alphabetic order of name or genre, latest releases order or without filters.</li>
  <li> Filter the Catalog by: Name, Number of Seasons, Number of Episodes, Release or Finish Year, Genre and Status.</li>
  <li> Write or Overwrite an anime with the option to save the changes in the list and file***.</li>
  <li> Remove an anime.</li>
</ol>

*If the anime are not finished yet, <em>Finish Year = 0</em>. <br>
**Status can be <em>“In Progress (Em Progresso)”</em> or <em>“Finished (Finalizado)”</em>.  <br>
***The inserted data correspond the current state of the anime before the insert day on the catalog. <br>

<strong>Functions</strong> 
➔ <em>Quick Sort</em>: Sort the catalog by Alphabetic order of <em>Name</em> or <em>Gender</em> and <em>Latest Releases</em>. Each one of the Quick sorts have an assist partition to help the sorting process. The datas from the list are transferred to an dynamic allocated vector to assist the process of sorting by the desired filter. Assist function of Quick Sort: “Troca”-> assist the partitions of the vector.

➔ <em>Menu</em>: A simple function to show to the user the options that he can execute on the program, initially.

➔ <em>MensagemErro</em>: When the user digit an unavailable interval of options, this function will be called to show the error message to the user and returns to the program menu.

➔ <em>Main</em>: Should capture the entries that the user writed and call another function to execute what the user wants.

<strong>Available Genres At the moment of releasing:</strong>
<ol type="a">
  <li>Ação (Action)</li>
  <li>Aventura (Adventure)</li>
  <li>Comédia (Comedy)</li>
  <li>Corrida (Race)</li>
  <li>Drama (Drama)
  <li>Esporte (Sports)</li>
  <li>Romance (Romance)</li>
  <li>Slice of Life (Slice of Life)</li>
  <li>Supernatural (Supernatural) </li>
  <li>Terror (Terror)</li>
</ol>

<em>Possible Future Changes:</em>

➔ Use multiple filters; ➔Sort the list directly from the list class, without using the assist vector; <br>
➔ A way to see if the user has writed the correct type of variable (int in int space, string in string space...) ✔️
➔ Use an Binary Archive to storage the .csv content
