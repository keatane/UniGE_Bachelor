<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>Sign-up</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>

<?php
	echo "<h1>I have been called after submit on your form</h1>\n";
	
    if(!isset($_POST["submit"])) return;
    if(empty($_POST["firstname"]) || empty($_POST["lastname"]) || empty($_POST["email"]) || empty($_POST["password"]) || empty($_POST["confirm"])){
		print_r("<div><h1>Check input data, some are missing</h1></div>");
		return;
	}

	$psw1 = trim($_POST["password"]);
	$psw2 = trim($_POST["confirm"]);

	// Compare password and confirm password inputs
	if(!password_verify($psw1, password_hash($psw2, PASSWORD_DEFAULT))){
		print_r("<div><h3>Password doesn't match</h3></div>");
		return;
	}

	// Saving password in a file
	$f = fopen("users.txt", "a+");
	if(!$f){
		echo "Cannot open the file";
		return;
	}
	$data = $_POST['firstname'] . ";" . $_POST['lastname'] . ";" . $_POST['email'] . ";" . password_hash($psw1, PASSWORD_DEFAULT) . ";\n";
	fwrite($f, $data);
	fclose($f);
	echo "<h1>You have been registered</h1>\n";
?>
        

</body>
</html>
