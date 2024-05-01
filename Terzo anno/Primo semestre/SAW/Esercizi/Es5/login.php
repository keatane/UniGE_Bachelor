<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>Sign-up</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>

<?php
	echo "<h1>Login state:</h1>";
    if(!isset($_POST["submit"])) return;
    if(empty($_POST["email"]) || empty($_POST["pass"])){
		print_r("<h2>Login failed: check input data, some are missing</h2>");
		return;
	}

	$psw1 = trim($_POST["pass"]);

	// Lookup to file
	$f = fopen("users.txt", "r");
	if(!$f){
		echo "<h2>Login failed: cannot open the file</h2>";
		return;
	}
	$found = false;
    while (($line = fgets($f)) !== false) {
        if(!str_contains($line, $_POST["email"])) continue;
		$found = true;

		$psw2 = "";
		$c = $line[0];
		$i = 0;
		$j = 0;

		// Search for psw index
		while($j != 3){
			if($c == ';') $j++;
			$c = $line[++$i];
		}
		// $c is already on the next char
		while($c != ';'){
			$psw2 = $psw2 . $c;
			$c = $line[++$i];
		}

		// Compare password and confirm password inputs
		if(!password_verify($psw1, $psw2)){
			print_r("<div><h2>Login failed: password is not correct</h2></div>");
			return;
		}

		$user = "";
		$c = $line[0];
		$i = 0;
		while($c != ';'){
			$user = $user . $c;
			$c = $line[++$i];
		}
		echo "<h2>Login successful \n<h2>Welcome " . $user . "</h2>\n"; 
		$found = true;
    }
	if(!$found) echo "<h2>Login failed: user not found</h2>";
	fclose($f);
?>
        

</body>
</html>
