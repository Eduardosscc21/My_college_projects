<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Mostrar Videos</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            margin: 20px;
            background-color: #BBE2F3 ;
        }

        .video-container {
            max-width: 600px;
            margin: 0 auto;
        }

        h1 {
            background-color: #D6A2F4;
            color: white;
            padding: 10px;
        }

        ul {
            list-style: none;
            padding: 0;
        }

        li {
            margin-bottom: 10px;
            border: 1px solid #D6A2F4;
        }

        form {
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        label {
            margin-bottom: 5px;
        }

        input {
            margin-bottom: 10px;
            padding: 8px;
            font-size: 16px;
            border: 1px solid #D6A2F4;
        }

        button {
            padding: 10px;
            font-size: 16px;
            border: 1px solid #D6A2F4;
        }
    </style>
</head>
<body>
    <div class="video-container">
        <h1>Mostrar Videos</h1>

        <form action="" method="post">
            <label for="peso">Peso:</label>
            <input type="number" name="peso" required>

            <label for="estatura">Estatura(ingrese los centimetros agregados al metro):</label>
            <input type="number" name="estatura" required>

            <button type="submit">Mostrar Videos</button>
        </form>

        <ul>
            <?php
            if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['peso']) && isset($_POST['estatura'])) {
                $peso = $_POST['peso'];
                $estatura = $_POST['estatura'];

                if ($peso > $estatura) {
                    $videoDir = 'videos/mayor/';
                } elseif ($peso == $estatura) {
                    $videoDir = 'videos/igual/';
                } else {
                    $videoDir = 'videos/menor/';
                }

                $videoFiles = glob($videoDir . '*.mp4');

                foreach ($videoFiles as $videoFile) {
                    echo '<li><a href="' . $videoFile . '">' . basename($videoFile) . '</a></li>';
                }
            }
            ?>
        </ul>
    </div>
</body>
</html>