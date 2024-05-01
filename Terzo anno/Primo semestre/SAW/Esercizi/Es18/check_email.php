<?php

    include("connection.php");
	$stmt = $mysqli->prepare("SELECT COUNT(*) FROM users WHERE Email = ?");
	$stmt->bind_param("s", $_POST["echeck"]);
	
	try{
		$stmt->execute();
	}
	catch(mysqli_sql_exception $e){
		die("<h2>Generic Error</h2>");
	}
    $result = $stmt->get_result();
    
    while ($row = mysqli_fetch_array($result, MYSQLI_NUM)){
        foreach($row as $r){
            if($r !== 0){
                //echo $_POST["echeck"];
            //print_r($result);
                echo "<b>Email already used, please try another one</b>";
            }
            else{
                echo "";
            }
        }
     }
    
?>