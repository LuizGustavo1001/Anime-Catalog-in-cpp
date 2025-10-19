<h1><em>Anime Catalog in C++ using Doubly Linked List</em></h1>

<h2>💡 <em>About the Project</em></h2>

<p>➔ C++ Project based on an <strong>anime catalog</strong> that loads data from a <em>.csv file</em> and stores it in a <em>Doubly Linked List</em> containing the following attributes:</p> 
<ul>
  <li>Name</li>
  <li>Number of Seasons</li>
  <li>Number of Episodes</li>
  <li>Release Year</li>
  <li>Finish Year<strong>*</strong></li>
  <li>Main Genre</li>
  <li>Status<strong>**</strong></li>
</ul>


<p>➔ The program allows you to:</p>
<ol type="A">
  <li>Display an especific Interval or Print the entire catalog sorted by <em> name</em>, <em>genre</em>, <em>latest releases</em> or <em>without filters</em>.</li>
  <li> 
     Filter the Catalog by: <em>Name</em>, <em>Number of Seasons</em>, <em>Number of Episodes</em>, <em>Release Year</em>, <em>Finish Year</em>, <em>Genre</em> or <em>Status</em>.
  </li>
  <li>Add or Overwrite an anime, with the option to save the changes to both list and file<strong>***</strong>.</li>
  <li>Remove an anime from the catalog.</li>
</ol>

<strong>
  <p>*If the anime is still ongoing, <em>Finish Year = 0</em>.</p>
  <p>**Status can be <em>“In Progress”</em> or <em>“Finished”</em>.</p>
  <p>***The inserted data represent the state of the anime at the time of insertion into the catalog.</p>
</strong>

<hr>
<h2>📄 <strong>Main Functions</strong></h2>
<p>➔ <em>Quick Sort</em>: Sort the catalog by <em>Name</em>, <em>Genre</em> or <em>Latest Releases</em>. Each sorting mode uses an auxiliary partition function. The data from the list are temporarily copied to a dynamically allocated vector to assist in the sorting process.</p>
<p><em>TrocarValores</em> – helps partition the vector during sorting(Quick Sort).</p></p>

<p>➔ <strong><em>Menu</em></strong>: Displays the available options to the user at the start of the program.</p>

<p>➔ <strong><em>MensagemErro</em></strong>: Called when the user select an invalid input range. Displays an default error message.</p>

<p>➔ <strong><em>Main</em></strong>: Capture the inputs and call another function to perform the desired operations.</p>
<hr>
<h2>📑Available Genres(At release time):</h2>
<ul>
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
</ul>
<hr>

<h2>💻 How to Start</h2>
<ol type="1">
    <li>Clone or download the repository. </li>
    <li>Open <code>CatalogoLista.cpp</code> and compile the program.</li>
</ol>

<hr>
<h2>🔦 <em>Possible Future Changes:</em></h2>
<ul>
  <li>Enable multiple simultaneous filters.</li>
  <li>Implement sorting directly within the list class (without the auxiliary vector).</li>
  <li>✔️ Add input validation to ensure the correct data types (e.g., <em>int</em> fields only accept integers).</li>
  <li>Use a binary file to store the <em>.csv</em> content for improved performance.</li>
  <li>Change the entire program leanguage to English</li>
</ul>
