<?php


include('db.php');  // Incluye el archivo de conexión

$USUARIO=$_POST['usuario'];
$PASSWORD=$_POST['password'];

$consulta = "SELECT * FROM Personal where usuario = '$USUARIO' and password = '$PASSWORD' ";
$resultado = mysqli_query($conexion, $consulta);
$filas = mysqli_num_rows($resultado);

if ($filas) {
    // Las credenciales son válidas, puedes redirigir al usuario a la página principal.
    header("location: pagina principal_premium.html");
} else {
    // Las credenciales son incorrectas, redirige de nuevo al formulario de inicio de sesión con un mensaje de error.
    include("LoginPremium.html")
    ?>
    <h1>ERROR</h1>
    <?php
    
}

mysqli_free_result($resultado);
mysqli_close($conexion);

?>
