
	

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

	