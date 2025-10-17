<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Flutter 3D Rotation Demo - Nord Theme</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Ubuntu Sans Mono' !important;
        }

        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background: #2E3440;
            color: #ECEFF4;
            padding: 20px;
        }

        .container {
            max-width: 1400px;
            margin: 0 auto;
        }

        h1 {
            text-align: center;
            color: #88C0D0;
            margin-bottom: 10px;
            font-size: 2.5em;
        }

        .subtitle {
            text-align: center;
            color: #D8DEE9;
            margin-bottom: 40px;
            font-size: 1.1em;
        }

        .rotation-grid {
            display: grid;
            grid-template-columns: repeat(3, 1fr);
            gap: 30px;
            margin-bottom: 40px;
        }

        .rotation-card {
            background: #3B4252;
            border-radius: 12px;
            padding: 25px;
            box-shadow: 0 8px 16px rgba(0, 0, 0, 0.3);
        }

        .card-title {
            font-size: 1.5em;
            margin-bottom: 20px;
            text-align: center;
            font-weight: bold;
        }

        .rotation-x { color: #BF616A; }
        .rotation-y { color: #A3BE8C; }
        .rotation-z { color: #88C0D0; }

        .scene {
            width: 100%;
            height: 300px;
            perspective: 800px;
            margin-bottom: 20px;
            position: relative;
            background: 
                linear-gradient(#4C566A 1px, transparent 1px),
                linear-gradient(90deg, #4C566A 1px, transparent 1px);
            background-size: 20px 20px;
            background-position: center center;
            border-radius: 8px;
            overflow: hidden;
        }

        .cube-container {
            position: absolute;
            top: 50%;
            left: 50%;
            transform-style: preserve-3d;
            transition: transform 0.3s ease;
        }

        .cube {
            width: 120px;
            height: 120px;
            position: relative;
            transform-style: preserve-3d;
        }

        .cube-face {
            position: absolute;
            width: 120px;
            height: 120px;
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 18px;
            font-weight: bold;
            border: 2px solid rgba(255, 255, 255, 0.3);
        }

        .front {
            background: rgba(191, 97, 106, 0.7);
            transform: translateZ(60px);
        }

        .back {
            background: rgba(163, 190, 140, 0.7);
            transform: translateZ(-60px) rotateY(180deg);
        }

        .right {
            background: rgba(136, 192, 208, 0.7);
            transform: rotateY(90deg) translateZ(60px);
        }

        .left {
            background: rgba(180, 142, 173, 0.7);
            transform: rotateY(-90deg) translateZ(60px);
        }

        .top {
            background: rgba(235, 203, 139, 0.7);
            transform: rotateX(90deg) translateZ(60px);
        }

        .bottom {
            background: rgba(216, 222, 233, 0.7);
            transform: rotateX(-90deg) translateZ(60px);
        }

        .controls {
            text-align: center;
        }

        .slider-container {
            margin-bottom: 15px;
        }

        .slider-label {
            display: block;
            margin-bottom: 8px;
            color: #D8DEE9;
            font-size: 0.95em;
        }

        input[type="range"] {
            width: 100%;
            height: 6px;
            border-radius: 3px;
            background: #4C566A;
            outline: none;
            -webkit-appearance: none;
        }

        input[type="range"]::-webkit-slider-thumb {
            -webkit-appearance: none;
            appearance: none;
            width: 18px;
            height: 18px;
            border-radius: 50%;
            background: #88C0D0;
            cursor: pointer;
        }

        input[type="range"]::-moz-range-thumb {
            width: 18px;
            height: 18px;
            border-radius: 50%;
            background: #88C0D0;
            cursor: pointer;
            border: none;
        }

        .value-display {
            color: #88C0D0;
            font-weight: bold;
            font-size: 1.1em;
        }

        .reset-btn {
            background: #5E81AC;
            color: #ECEFF4;
            border: none;
            padding: 10px 25px;
            border-radius: 6px;
            cursor: pointer;
            font-size: 1em;
            margin-top: 10px;
            transition: background 0.3s;
        }

        .reset-btn:hover {
            background: #81A1C1;
        }

        .axis-info {
            background: #434C5E;
            padding: 15px;
            border-radius: 8px;
            margin-top: 20px;
            font-size: 0.9em;
            line-height: 1.6;
        }

        .legend {
            display: flex;
            justify-content: center;
            gap: 30px;
            margin-top: 30px;
            flex-wrap: wrap;
        }

        .legend-item {
            display: flex;
            align-items: center;
            gap: 10px;
        }

        .legend-color {
            width: 30px;
            height: 30px;
            border-radius: 4px;
            border: 2px solid rgba(255, 255, 255, 0.3);
        }

        @media (max-width: 1024px) {
            .rotation-grid {
                grid-template-columns: 1fr;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>🎯 Flutter 3D Rotation Visualizer</h1>
        <p class="subtitle">Interactive demonstration of rotateX, rotateY, and rotateZ transformations</p>

        <div class="rotation-grid">
            <!-- Rotation X -->
            <div class="rotation-card">
                <h2 class="card-title rotation-x">Rotate Around X</h2>
                <div class="scene" id="scene-x">
                    <div class="cube-container" id="cube-x">
                        <div class="cube">
                            <div class="cube-face front">Front</div>
                            <div class="cube-face back">Back</div>
                            <div class="cube-face right">Right</div>
                            <div class="cube-face left">Left</div>
                            <div class="cube-face top">Top</div>
                            <div class="cube-face bottom">Bottom</div>
                        </div>
                    </div>
                </div>
                <div class="controls">
                    <div class="slider-container">
                        <label class="slider-label">Angle: <span class="value-display" id="value-x">0°</span></label>
                        <input type="range" id="slider-x" min="-180" max="180" value="0" step="1">
                    </div>
                    <button class="reset-btn" onclick="reset('x')">Reset</button>
                </div>
                <div class="axis-info">
                    <strong>X-Axis (Horizontal):</strong><br>
                    Rotates around horizontal line. Widget flips forward/backward like opening a laptop lid.
                </div>
            </div>

            <!-- Rotation Y -->
            <div class="rotation-card">
                <h2 class="card-title rotation-y">Rotate Around Y</h2>
                <div class="scene" id="scene-y">
                    <div class="cube-container" id="cube-y">
                        <div class="cube">
                            <div class="cube-face front">Front</div>
                            <div class="cube-face back">Back</div>
                            <div class="cube-face right">Right</div>
                            <div class="cube-face left">Left</div>
                            <div class="cube-face top">Top</div>
                            <div class="cube-face bottom">Bottom</div>
                        </div>
                    </div>
                </div>
                <div class="controls">
                    <div class="slider-container">
                        <label class="slider-label">Angle: <span class="value-display" id="value-y">0°</span></label>
                        <input type="range" id="slider-y" min="-180" max="180" value="0" step="1">
                    </div>
                    <button class="reset-btn" onclick="reset('y')">Reset</button>
                </div>
                <div class="axis-info">
                    <strong>Y-Axis (Vertical):</strong><br>
                    Rotates around vertical line. Widget turns left/right like a door swinging open.
                </div>
            </div>

            <!-- Rotation Z -->
            <div class="rotation-card">
                <h2 class="card-title rotation-z">Rotate Around Z</h2>
                <div class="scene" id="scene-z">
                    <div class="cube-container" id="cube-z">
                        <div class="cube">
                            <div class="cube-face front">Front</div>
                            <div class="cube-face back">Back</div>
                            <div class="cube-face right">Right</div>
                            <div class="cube-face left">Left</div>
                            <div class="cube-face top">Top</div>
                            <div class="cube-face bottom">Bottom</div>
                        </div>
                    </div>
                </div>
                <div class="controls">
                    <div class="slider-container">
                        <label class="slider-label">Angle: <span class="value-display" id="value-z">0°</span></label>
                        <input type="range" id="slider-z" min="-180" max="180" value="0" step="1">
                    </div>
                    <button class="reset-btn" onclick="reset('z')">Reset</button>
                </div>
                <div class="axis-info">
                    <strong>Z-Axis (Depth):</strong><br>
                    Rotates around depth line (perpendicular to screen). Normal 2D rotation like a spinning wheel.
                </div>
            </div>
        </div>

        <div class="legend">
            <div class="legend-item">
                <div class="legend-color" style="background: rgba(191, 97, 106, 0.7);"></div>
                <span>Front</span>
            </div>
            <div class="legend-item">
                <div class="legend-color" style="background: rgba(163, 190, 140, 0.7);"></div>
                <span>Back</span>
            </div>
            <div class="legend-item">
                <div class="legend-color" style="background: rgba(136, 192, 208, 0.7);"></div>
                <span>Right</span>
            </div>
            <div class="legend-item">
                <div class="legend-color" style="background: rgba(180, 142, 173, 0.7);"></div>
                <span>Left</span>
            </div>
            <div class="legend-item">
                <div class="legend-color" style="background: rgba(235, 203, 139, 0.7);"></div>
                <span>Top</span>
            </div>
            <div class="legend-item">
                <div class="legend-color" style="background: rgba(216, 222, 233, 0.7);"></div>
                <span>Bottom</span>
            </div>
        </div>
    </div>

    <script>
        // Rotation X
        const sliderX = document.getElementById('slider-x');
        const cubeX = document.getElementById('cube-x');
        const valueX = document.getElementById('value-x');

        sliderX.addEventListener('input', (e) => {
            const angle = e.target.value;
            valueX.textContent = angle + '°';
            cubeX.style.transform = `translate(-50%, -50%) rotateX(${angle}deg)`;
        });

        // Rotation Y
        const sliderY = document.getElementById('slider-y');
        const cubeY = document.getElementById('cube-y');
        const valueY = document.getElementById('value-y');

        sliderY.addEventListener('input', (e) => {
            const angle = e.target.value;
            valueY.textContent = angle + '°';
            cubeY.style.transform = `translate(-50%, -50%) rotateY(${angle}deg)`;
        });

        // Rotation Z
        const sliderZ = document.getElementById('slider-z');
        const cubeZ = document.getElementById('cube-z');
        const valueZ = document.getElementById('value-z');

        sliderZ.addEventListener('input', (e) => {
            const angle = e.target.value;
            valueZ.textContent = angle + '°';
            cubeZ.style.transform = `translate(-50%, -50%) rotateZ(${angle}deg)`;
        });

        // Reset function
        function reset(axis) {
            if (axis === 'x') {
                sliderX.value = 0;
                valueX.textContent = '0°';
                cubeX.style.transform = `translate(-50%, -50%) rotateX(0deg)`;
            } else if (axis === 'y') {
                sliderY.value = 0;
                valueY.textContent = '0°';
                cubeY.style.transform = `translate(-50%, -50%) rotateY(0deg)`;
            } else if (axis === 'z') {
                sliderZ.value = 0;
                valueZ.textContent = '0°';
                cubeZ.style.transform = `translate(-50%, -50%) rotateZ(0deg)`;
            }
        }

        // Initialize positions
        cubeX.style.transform = 'translate(-50%, -50%) rotateX(0deg)';
        cubeY.style.transform = 'translate(-50%, -50%) rotateY(0deg)';
        cubeZ.style.transform = 'translate(-50%, -50%) rotateZ(0deg)';
    </script>
</body>
</html>
