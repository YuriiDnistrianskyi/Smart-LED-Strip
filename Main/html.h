#ifndef HTML_H
#define HTML_H

const char* html = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Smart LED</title>
    <style>
        .body{
            overscroll-behavior: none;
        }

        .section-1 {
            display: flex;
            justify-content: space-between;
            width: 100%;
            height: 15vh;
            background-color: rgb(38, 38, 38);
        }

        .section-block {
            display: flex;
            align-items: center;
            justify-content: center;
            width: 45%;
            height: 100%;
        }

        .text {
            font-family: 'Franklin Gothic Medium', 'Arial Narrow', Arial, sans-serif;
            color: #ffffff;
        }

        .button-control {
            width: 60%;
            height: 50%;
            border: 2px;
            border-radius: 50px;
            background-color: #54996d;
            font-size: 20px;
            transition: linear 0.3s;
        }

        .button-control:active{
            transform: scale(0.9);
            background-color: #8adda8;
        }


        .section-control {
            display: flex;
            justify-content: space-between;
            width: 100%;
            height: 70vh;
        }

        .box {
            display: flex;
            justify-content: center;
            width: 30%;
            height: 95%;
        }

        .control {
            display: flex;
            align-items: center;
            justify-content: center;
            flex-grow: 1;
            width: 50%;
            height: 90%;
        }

        .slider {
            -webkit-appearance: none;
            appearance: none;
            position: absolute;
            width: 100%;
            height: 20px;
            border-radius: 4px;
            outline: none;
            opacity: 0.8;
            transition: opacity 0.3s;
            transform: rotate(-90deg);
        }

        .slider.red {
            background: linear-gradient(to right, #ffffff, #ba3c3c);
        }

        .slider.green {
            background: linear-gradient(to right, #ffffff, #4fba3c);
        }

        .slider.blue {
            background: linear-gradient(to right, #ffffff, #4f3cba);
        }

        .slider::-webkit-slider-thumb {
            -webkit-appearance: none;
            appearance: none;
            width: 30px;
            height: 50px;
            border-radius: 20px;
            background: rgb(138, 138, 138);
            cursor: pointer;
            transition: 0.2s;
        }
    </style>
</head>
<body>
    <div class="section-1">
        <div class="section-block">
            <h1 class="text">Smart LED</h1>
        </div>
        <div class="section-block">
            <button class="button-control">ON/OFF</button>
        </div>
    </div>

    <div class="section-control">
        <div class="box">
            <div class="control">
                <input class="slider red" type="range" id="volume-red" min="0" max="255" value="50">
            </div>
        </div>

        <div class="box">
            <div class="control">
                <input class="slider green" type="range" id="volume-green" min="0" max="255" value="50">
            </div>
        </div>

        <div class="box">
            <div class="control">
                <input class="slider blue" type="range" id="volume-blue" min="0" max="255" value="50">
            </div>
        </div>
    </div>

</body>
</html>
)rawliteral";

#endif // HTML_H
