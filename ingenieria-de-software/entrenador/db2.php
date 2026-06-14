<?php
$Chost = "localhost";
$Cuser = "root";
$Cpass = "";
$db = "validar";

$con = new mysqli($Chost,$Cuser,Cpass,$db );

 if($con->connect_error) {
    die("Ha ocurrido un error");
 }
 ?>