<?php
$db = "BDD_Serre_Automatique";
$user = 'sfl5';
$pass = 'sfl5db';
$host = "10.16.37.161";

$conn = mysqli_connect($host,$user ,$pass, $db);
if($conn)
{
	echo "connected...!";
}
	/*
	$q = 'SELECT * FROM user WHERE user LIKE \''.$user'\ AND pass LIKE \''$pass'\'';
	$result = mysqli_query($conn , $q);
	if(mysqli_num_rows($result) > 0)
	{
		echo "login sucessfull...!";
	}
	else
	{
		echo "login failed...!";
	}
	*/
	else
	{	
		echo "Not Connected...!";
	}

?>