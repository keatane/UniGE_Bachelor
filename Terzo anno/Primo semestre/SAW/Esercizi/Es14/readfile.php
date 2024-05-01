<?php
//if (!isset($argv[1])) 
	//exit("\nPlease provide an URL\n\n");

$url = "https://www.google.it/images/branding/googlelogo/1x/googlelogo_light_color_272x92dp.png";

$file = "C:/Users/kavan/Desktop/img.png";

// Create a cURL handle
$handle = curl_init();
$fp = fopen($file,"w");
// Specify options
curl_setopt($handle, CURLOPT_URL, $url);
curl_setopt($handle, CURLOPT_RETURNTRANSFER, true);
curl_setopt($handle, CURLOPT_FILE, $fp);


// Execute
$output = curl_exec($handle);

echo "\n=================================================\n";

// Check if any error occurred
if (curl_errno($handle)) 
	echo "\nAn error has occurred\n\n";
else 
	echo "\n$output\n\n";

$info = curl_getinfo($handle);
print_r($info);

echo "\n=================================================\n";

// Close handle
curl_close($handle);
fclose($fp);
?>