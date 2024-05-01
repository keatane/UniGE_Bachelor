<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>Sign-up</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>

<?php	
	ini_set('display_errors', false);
	ini_set('error_log', 'php.log');
	echo "<h1>I have been called after submit on your form</h1>\n";
	
	include("connection.php");

    if(!isset($_POST["submit"])) exit();
    if(empty($_POST["firstname"]) || empty($_POST["lastname"]) || empty($_POST["email"]) || empty($_POST["password"]) || empty($_POST["confirm"])){
		print_r("<div><h1>Check input data, some are missing</h1></div>");
		exit();
	}

	$first = trim($_POST["firstname"]);
	$first = htmlentities($first, ENT_QUOTES);
	if(!preg_match('/([a-zA-Z0-9])/', $first)){
		echo "Invalid firstname input";
		exit();
	}
	$last = trim($_POST["lastname"]);
	$last = htmlentities($last, ENT_QUOTES);
	if(!preg_match('/([a-zA-Z0-9])/', $last)){
		echo "Invalid lastname input";
		exit();
	}
	$email = trim($_POST["email"]);
	$email = htmlentities($email, ENT_QUOTES);
	if(!preg_match('/([a-zA-Z])@([a-zA-Z]).([a-zA-Z])/', $email)){
		echo "Invalid email input";
		exit();
	}
	$psw1 = trim($_POST["password"]);
	$psw2 = trim($_POST["confirm"]);

	// Compare and confirm password inputs
	if($psw1 != $psw2){
		print_r("<div><h3>Password doesn't match</h3></div>");
		exit();
	}
	$hash = password_hash($psw1, PASSWORD_DEFAULT);

	// Saving data in a db
	$stmt = $mysqli->prepare("INSERT INTO users(Id,Firstname,Lastname,Email,Psw) VALUES (NULL, ?, ?, ?, ?)");
	$stmt->bind_param("ssss", $first, $last, $email, $hash);
	
	/*
	// execute query
	if (!$stmt->execute()) {
		error_log("Execute failed: (" . $stmt->errno . ") " . $stmt->error); // scrive nel file la mancata cattura dell'eccezione: EXIT non viene stampato!
		exit("Something went wrong, visit us later\n");
	}
	*/
	
	try{
		$stmt->execute(); // esplode se l'errore arriva dal db (es. email duplicata)
	}
	catch(mysqli_sql_exception $e){
		if($stmt->errno == 1062){ // controllo dell'errno
			die("<h2>Duplicate email, try again</h2>");
		}
		error_log("Error: " . $stmt->error . " " . $stmt->errno);
		die("<h2>Error while registrating, please try later</h2>");
	}
	
	$num = $stmt->affected_rows;

	echo "Num of affected rows: " . $num;
	echo "<h1>You have been registered</h1>\n";
	$stmt->close();
	$mysqli->close();
?>
        

</body>
</html>
