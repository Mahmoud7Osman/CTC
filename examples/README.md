<h1>Introduction</h1>
<p>This example project consists of three files: <code>main.c</code>, <code>main2.c</code>, and <code>tasks.c</code>. Both <code>main.c</code> and <code>main2.c</code> use <code>tasks.c</code> to load tasks, but <code>main2.c</code> executes tasks in a different way than <code>main.c</code>.</p>

<h2>Compilation</h2>
<p>To compile the project, navigate to the <code>examples</code> folder and use the following commands:</p>

<pre><code>gcc -o main main.c tasks.c
</code></pre>

<p>This command will compile <code>main.c</code> and <code>tasks.c</code> into an executable file named <code>main</code>.</p>

<pre><code>gcc -o main2 main2.c tasks.c
</code></pre>

<p>This command will compile <code>main2.c</code> and <code>tasks.c</code> into an executable file named <code>main2</code>.</p>

<p><em>Note: This README assumes that you have <a href="https://gcc.gnu.org/">GCC</a> installed on your system.</em></p>
