<?php
	
   $con=mysqli_connect("10.16.37.161", "sfl5", "sfl5db");

   if (mysqli_connect_errno($con)) {
      echo "Failed to connect to MySQL: " . mysqli_connect_error();
   }

   $username = $_GET['sfl5'];
   $password = $_GET['sfl5db'];
   $result = mysqli_query($con,"SELECT Role FROM table1 where Username='$username' 
      and Password='$password'");
   $row = mysqli_fetch_array($result);
   $data = $row[0];

   if($data){
      echo $data;
   }
   mysqli_close($con);
?>

<?php
$db = "test";
$user = $_POST["user"];
$pass = $_POST["pass"];
$host = "localhost";

$conn = mysqli_connect($host,$user ,$pass, $db);
if($conn)
{
	echo "connecte...!";
	$q = "select * from user where user like '$user' and pass like '$pass'";
	$result = mysqli_query($conn , $q);
	if(mysqli_num_rows($result) > 0)
	{
		echo "login sucessfull...!";
	}
	else{
		echo "echec login...!";
		
		
		

?>
