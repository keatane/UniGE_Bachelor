<?php
//if (!isset($argv[1])) 
	//exit("\nPlease provide an URL\n\n");

$url = "https://randomfox.ca/floof/";
#$url = "https://xkcd.com/info.0.json";
#$url = "https://api.waifu.im/search/?is_nsfw=false";

// Create a cURL handle
$handle = curl_init();

// Specify options
curl_setopt($handle, CURLOPT_URL, $url);
curl_setopt($handle, CURLOPT_RETURNTRANSFER, true);

// Execute
$output = curl_exec($handle);
#$info = curl_getinfo($handle);

echo $output;

// Close handle
curl_close($handle);
?>
