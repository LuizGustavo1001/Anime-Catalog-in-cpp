<h1><em>Anime Catalog in C++ using Double Linked List</em></h1>

<hr>
➔ User: <a href="https://github.com/LuizGustavo1001/">Luiz Gustavo De Almeida Lopes</a>
<hr>
<h2><em>About the Project</em></h2>

<p>➔ C++ Project based in a <strong>anime catalog</strong> that comes from a <em>.csv file</em> and is stored in a <em>Double Linked List</em> with the:</p> 
<ul>
  <li>Name</li>
  <li>Number of Seasons</li>
  <li>Number of Episodes</li>
  <li>Release Year</li>
  <li> Finish Date<strong>*</strong></li>
  <li>Main Genre</li>
  <li>Status<strong>**</strong></li>
</ul>
<p>With the possibility of:</p>

<ol type="A">
  <li> Show an Interval or Print the entire Catalog in alphabetic order of name or genre, latest releases order or without filters.</li>
  <li> Filter the Catalog by: Name, Number of Seasons, Number of Episodes, Release or Finish Year, Genre and Status.</li>
  <li> Write or Overwrite an anime with the option to save the changes in the list and file***.</li>
  <li> Remove an anime.</li>
</ol>
<strong>
<p>*If the anime are not finished yet, <em>Finish Year = 0</em>. </p>
<p>**Status can be <em>“In Progress (Em Progresso)”</em> or <em>“Finished (Finalizado)”</em>.  </p>
<p>***The inserted data correspond the current state of the anime before the insert day on the catalog. </p>
</strong>
<hr>
<h2><strong>Functions</strong></h2>
<p>➔ <strong><em>Quick Sort</em></strong>: Sort the catalog by Alphabetic order of <em>Name</em> or <em>Gender</em> and <em>Latest Releases</em>. Each one of the Quick sorts have an assist partition to help the sorting process. The datas from the list are transferred to an dynamic allocated vector to assist the process of sorting by the desired filter. Assist function of Quick Sort: “Troca”-> assist the partitions of the vector.</p>

<p>➔ <strong><em>Menu</em></strong>: A simple function to show to the user the options that he can execute on the program, initially.</p>

<p>➔ <strong><em>MensagemErro</em></strong>: When the user digit an unavailable interval of options, this function will be called to show the error message to the user and returns to the program menu.</p>

<p>➔ <strong><em>Main</em></strong>: Should capture the entries that the user writed and call another function to execute what the user wants.</p>
<hr>
<h2><strong>Available Genres At the moment of releasing:</strong></h2>
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
<hr>
<h2><em>Possible Future Changes:</em></h2>
<ul>
  <li>Use multiple filters</li>
  <li>Sort the list directly from the list class, without using the assist vector</li>
  <li>✔️A way to see if the user has writed the correct type of variable (int in int space, string in string space...) </li>
  <li> Use an Binary Archive to storage the .csv content</li>

  
</ul>
