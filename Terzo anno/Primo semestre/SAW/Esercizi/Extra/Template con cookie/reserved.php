<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>Sign-up</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>

<?php
	session_start();
	echo "<h1>Personal Area</h1>";
    if(!isset($_COOKIE["auth"])){
        echo "<h3>You have no permission to stay here</h3>";
        exit();
    }

    echo "<h3>Welcome into your private area, " . $_COOKIE["user"] . "</h3>";
?>
        

</body>
</html>
