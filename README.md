<h1>cub3D</h1>
<p>The goal of this project is to build a simple 3D game using the raycasting technique.</p>
<h2>Table of Contents</h2>
<ol>
  <li><a href="#about">About</a></li>
  <li><a href="#installation">Installation</a></li>
  <li><a href="#usage">Usage</a></li>
  <li><a href="#bonus">Bonus</a></li>
</ol>
<h2 id="about">About</h2>
<p>cub3D is a graphical program that provides a "realistic" 3D graphical representation of the inside of a maze, which the player must navigate through. The program is designed to be a tribute to the historic game Wolfenstein 3D, the first-ever first-person shooter.</p>
<h2 id="installation">Installation</h2>
<ol>
  <li>Clone the repository: <pre><code>git clone https://github.com/lpincoli/Cub3d42.git</code></pre></li>
  <li>Move to the project's directory: <pre><code>cd Cub3d42</code></pre></li>
  <li>Compile the project: <pre><code>make</code></pre></li>
</ol>
<h2 id="usage">Usage</h2>
<p>The program takes one argument, a scene description file with the .cub extension:</p>
<pre><code>./cub3D map.cub</code></pre>
<p>The .cub file describes the maze map and specifies various settings such as the textures of the walls and the colors of the floor and ceiling. The maze map is made up of characters: '1' for walls, '0' for empty spaces, and 'N', 'S', 'E', or 'W' for the player's start position and orientation.</p>
<p>Once the program is running, use the left and right arrow keys to look around and the W, A, S, and D keys to move. Press ESC or click on the red cross on the window's frame to exit the program.</p>
<h3 id="bonus">Bonus</h3>
<p>To compile the bonus part of the code, use the following command:</p>
<pre><code>make bonus</code></pre>
<p>The bonus part includes additional features such as wall collisions, a minimap system, interactive doors, animated sprite, and the ability to rotate the point of view with the mouse. Be aware that your base program must be fully functional and error-free to have the bonus part evaluated.</p>

<h2>Subject</h2>

<p>For more information about the project, read the subject file.</p>
