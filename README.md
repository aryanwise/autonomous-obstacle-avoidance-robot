# Autonomous Obstacle Avoidance Robot (Arduino, 4WD)

Autonomous 4-wheel robotic system capable of real-time obstacle detection and navigation using ultrasonic sensing and servo-based environmental scanning.

---

## 🚀 Overview

This project implements a real-time autonomous control system based on a perception–decision–action pipeline:

**Sensor Input → Environment Mapping → Decision Logic → Motor Control**

The robot dynamically scans its surroundings and adjusts movement to avoid obstacles without human intervention.

---

## 🎥 Demo

[▶️ Watch Full Demo](YOUR_VIDEO_LINK)

---

## 🧠 System Architecture

![Circuit Diagram](docs/circuit.png)

### Core Pipeline
- **Perception** → Ultrasonic sensor + servo scanning
- **Processing** → Distance computation + comparison
- **Decision** → Rule-based navigation logic
- **Action** → Motor control via L298N driver

---

## ⚙️ Hardware Components

| Component | Description |
|----------|------------|
| Arduino Uno | Main controller |
| HC-SR04 | Ultrasonic distance sensor |
| Servo Motor | Directional scanning |
| L298N | Motor driver module |
| 4× DC Motors | 4WD chassis |
| 2× 18650 Batteries | Power supply (7.4V) |
| Switch Module | Power control |

---

## 🔧 Key Features

- Autonomous navigation (no manual control)
- Real-time obstacle detection
- Servo-based directional scanning
- Multi-motor control (4WD)
- Low-latency decision-making system
- Embedded C++ implementation (Arduino)

---

## 🧩 Working Logic

1. Measure forward distance using ultrasonic sensor  
2. If obstacle detected:
   - Rotate servo left and right
   - Measure distances in both directions  
3. Compare values  
4. Navigate toward the clearer path  
5. Execute movement via motor driver  

---

## 📁 Project Structure
autonomous-obstacle-avoidance-robot/
│
├── README.md
├── arduino/
│ └── obstacle_avoidance_robot.ino
│
├── docs/
│ ├── circuit.png
│ └── demo video


---

## 💻 Code Highlights

- Modular control functions:
  - `getDistance()`
  - `moveForward()`
  - `turnLeft()`
  - `turnRight()`
  - `stopRobot()`

- Real-time loop execution for continuous navigation
- Embedded system optimized for responsiveness

---

## 📊 Performance

- Detection Range: ~2 cm – 400 cm  
- Response Time: <100 ms  
- Tested across multiple obstacle configurations  

---

## 🤖 Relevance to AI & Industry 4.0

This project demonstrates foundational concepts of autonomous intelligent systems:

- **Perception** (sensor data acquisition)
- **Decision-making** (rule-based logic)
- **Action execution** (motor control)

These principles directly map to:
- Robotics systems  
- AI agents  
- Industrial automation (Industry 4.0)

---

## 🔮 Future Improvements

- Replace rule-based logic with ML-based navigation
- Integrate additional sensors (IR, camera)
- Implement SLAM or path planning algorithms
- Add ROS (Robot Operating System) integration

---

## 🛠️ Setup & Usage

1. Connect components as per circuit diagram  
2. Upload `.ino` file using Arduino IDE  
3. Power system using battery pack  
4. Place robot in environment with obstacles  
