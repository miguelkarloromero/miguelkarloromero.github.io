<!DOCTYPE html>
<html lang="en-US">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Art Gallery</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            background-color: #000; /* Black background */
            color: #fff; /* White text color */
        }
        .container {
            padding: 20px;
        }
        .gallery {
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(150px, 1fr));
            gap: 20px;
            padding: 20px 0;
        }
        .gallery-item {
            position: relative;
            border: 1px solid #fff;
            padding: 10px;
            text-align: center;
            background-color: #000;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            cursor: pointer;
            outline: none; /* Remove blue outline */
        }
        .gallery-item img {
            max-width: 100%;
            height: auto;
            display: block;
            margin: 0 auto;
        }
        .gallery-item p {
            color: #fff; /* Black text for descriptions */
        }
        .overlay {
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: rgba(255, 255, 255, 0);
            z-index: 1;
        }
        /* Modal styles */
        .modal {
            display: none;
            position: fixed;
            z-index: 2;
            left: 0;
            top: 0;
            width: 100%;
            height: 100%;
            overflow: auto;
            background-color: rgba(0, 0, 0, 0.9);
        }
        .modal-content {
            margin: 10% auto;
            display: block;
            width: 80%;
            max-width: 700px;
        }
        .modal-content img {
            width: 100%;
            height: auto;
        }
        .close {
            position: absolute;
            top: 15px;
            right: 35px;
            color: #fff;
            font-size: 40px;
            font-weight: bold;
            transition: 0.3s;
            outline: none; /* Remove blue outline */
        }
        .close:hover,
        .close:focus {
            color: #bbb;
            text-decoration: none;
            cursor: pointer;
        }
        @media (min-width: 600px) {
            .gallery {
                grid-template-columns: repeat(auto-fill, minmax(200px, 1fr));
            }
        }
        @media (min-width: 900px) {
            .gallery {
                grid-template-columns: repeat(auto-fill, minmax(250px, 1fr));
            }
        }
        .header {
        font-size: 30px;
        }
    </style>
</head>
<body>
    <div class="container">
        <p class="header">Welcome to my Art Gallery!</p>
        <p>Browse through the collection of my artworks below. Click on any image to view it in a larger size and zoom it to view the details.</p>
        <p class="header">NOTE:</p>
        <p>1: The images are renewed every month.</p>
        <p>2: The images are sorted by date.</p>
        <div class="gallery">
            <div class="gallery-item" onclick="openModal('$images/image3.jpg')" tabindex="0">
                <div class="overlay"></div>
                <img src="$images/image3.jpg" alt="Artwork 1">
                <p>Newest.</p>
                <p>July 10, 2024, 1:36 AM.</p>
                <p>File size: 5.71MB.</p>
            </div>
            <div class="gallery-item" onclick="openModal('$images/image2.jpg')" tabindex="0">
                <div class="overlay"></div>
                <img src="$images/image2.jpg" alt="Artwork 2">
                <p>July 7, 2024, 11:11 PM.</p>
                <p>File size: 6.60MB.</p>
            </div>
            <div class="gallery-item" onclick="openModal('$images/image1.jpg')" tabindex="0">
                <div class="overlay"></div>
                <img src="$images/image1.jpg" alt="Artwork 3">
                <p>Oldest.</p>
                <p>Jun 30, 2024, 5:33 PM.</p>
                <p>File size: 5.02MB.</p>
            </div>
        </div>
    </div>

    <!-- The Modal -->
    <div id="myModal" class="modal">
        <span class="close" onclick="closeModal()">&times;</span>
        <div class="modal-content">
            <img id="modalImage" src="" alt="Expanded Image.">
        </div>
    </div>

    <script>
        function openModal(src) {
            document.getElementById('myModal').style.display = "block";
            document.getElementById('modalImage').src = src;
        }

        function closeModal() {
            document.getElementById('myModal').style.display = "none";
        }
    </script>
</body>
		</html>
