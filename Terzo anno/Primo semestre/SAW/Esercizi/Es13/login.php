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
	include("connection.php");
	echo "<h1>Login state:</h1>";
    if(!isset($_POST["submit"])) return;
    if(empty($_POST["email"]) || empty($_POST["pass"])){
		print_r("<h2>Login failed: check input data, some are missing</h2>");
		exit();
	}

	$email = trim($_POST["email"]);
	$email = htmlentities($email, ENT_QUOTES);
	$mysqli->real_escape_string($email);
	$psw = trim($_POST["pass"]);

	// Lookup to db
	$query = "SELECT Firstname, Psw FROM Users WHERE Email = '" . $email . "'";
	$res = $mysqli->query($query);
	//echo $res->num_rows;
	if($res->num_rows == 1){
		$row = $res->fetch_assoc();
		if(!password_verify($psw, $row["Psw"])){
			die("<h2>Invalid email or password</h2>");
		}
		$user = $row["Firstname"];
		//echo "<h2>Login successful \n<h2>Welcome " . $user . "</h2>\n";
	}
	else{
		die("<h2>Invalid email or password</h2>");
	}

	// Login successful
	$_SESSION["login"] = 1;
	setcookie("username", $user, time()+3600);
	if(isset($_POST["rememberMe"])){
		$token = bin2hex(random_bytes(20));
		setcookie("Remember", $token, time()+3600);
	}
	header("Location: reserved.php")
?>     

</body>
</html>
