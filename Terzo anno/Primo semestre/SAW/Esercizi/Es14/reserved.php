<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>Reserved page</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>
<nav>
	<div class="nav-container">
		<div class="vertical-center"> 
			<a class="nav-text" href="index.php"> Home </a> |
			<a class="nav-text" href="#"> Show profile</a> |
			<a class="nav-text" href="clear.php"> Logout</a>
		</div>
	</div>
</nav>
<?php
	session_start();
	echo "<h1>Personal Area</h1>";
    if(!isset($_COOKIE["Remember"]) && !isset($_SESSION["login"])){
        die("<h3>You have no permission to stay here</h3>");
    }
    if(isset($_COOKIE["Remember"]))
        echo "Accesso con ricordo";
    if(isset($_COOKIE["username"]))
        echo "<h3>Welcome into your private area, " . $_COOKIE["username"] . "</h3>";
?>
        

</body>
</html>
