<!DOCTYPE html>
<html>

<head>
    <title>Subir y Mostrar Videos</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            background-color: #BBE2F3 ;
        }

        .container {
            max-width: 600px;
            margin: 0 auto;
        }

        h1 {
            background-color: #D6A2F4;
            color: white;
            padding: 10px;
        }

        form {
            padding: 20px;
            background-color: #f4f4f4;
            border: 1px solid #D6A2F4;
        }

        ul {
            list-style: none;
            padding: 0;
        }

        li {
            margin-bottom: 10px;
        }
    </style>
</head>

<body>
    <div class="container">
        <h1>Subir Video</h1>
        <form action="upload_SE.php" method="post" enctype="multipart/form-data">
            <input type="file" name="video" accept="video/*" required>
            <input type="submit" value="Subir Video">
        </form>

        <h1>Videos Disponibles</h1>
        <ul>
            <?php
            $videoDir = 'uploads/';
            $videoFiles = glob($videoDir . '*.{mp4,avi,flv}', GLOB_BRACE);

            foreach ($videoFiles as $videoFile) {
                echo '<li><a href="' . $videoFile . '">' . basename($videoFile) . '</a></li>';
            }
            ?>
        </ul>
    </div>
</body>

</html>