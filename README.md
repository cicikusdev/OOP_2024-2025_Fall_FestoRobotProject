# OOP_2024-2025_Fall_FestoRobotProject
This project simulates and manages robots in a Festo production line. Built with object-oriented programming (OOP) principles, it features a modular and reusable architecture. The implementation includes class structures, inheritance, polymorphism, and encapsulation to ensure scalability and maintainability.


## Overview
This project is a part of the **Object-Oriented Programming 1** course for the 2024-2025 Fall term. 
It focuses on developing a modular and extensible software system for controlling a **Festo robot** using **Webots** and **C++**. 
The project implements advanced object-oriented programming principles such as **virtual classes**, **polymorphism**, and **encapsulation**.

The robot system is designed to handle tasks like **access control**, **safe navigation**, **movement control**, and **connection status monitoring** in a simulation environment. 
Additionally, it includes features for **data encryption**, **sensor integration**, and **map visualization**.

---

## Key Features
- **Robot Control System:**
  - Movement: Omni-directional navigation with support for precise turns and safe maneuvers.
  - Connection: Real-time monitoring and management of the robot's connection status.
- **Sensor Integration:**
  - IR and LIDAR sensors for obstacle detection and environmental mapping.
- **Access Control:**
  - Secure operator management using encrypted access codes.
- **Safe Navigation:**
  - Collision detection and avoidance mechanisms.
- **Mapping and Visualization:**
  - Dynamic mapping of the environment using LIDAR sensor data.
- **Modular Design:**
  - Interfaces and virtual classes for enhanced code reusability and maintainability.

---

## Technologies and Tools
- **Programming Language:** C++  
- **Simulation Environment:** Webots  
- **Development Tools:** Visual Studio  
- **Documentation:** Doxygen for generating detailed class and function documentation.  
- **UML Design:** Visual Paradigm and Draw.io for architecture planning.  

---

## Project Structure

FestoRobotProject  
├── 📂 src  
│   ├── main.cpp                 - Entry point of the application  
│   ├── RobotControler.h/.cpp    - Manages robot's movement and connection  
│   ├── Pose.h/.cpp              - Represents robot's position and orientation  
│   ├── IRSensor.h/.cpp          - Handles IR sensor data  
│   ├── LidarSensor.h/.cpp       - Processes LIDAR sensor data  
│   ├── SafeNavigation.h/.cpp    - Implements safe navigation logic  
│   ├── Mapper.h/.cpp            - Manages environmental mapping  
│   ├── Point.h/.cpp             - Handles coordinate-based calculations  
│   ├── MAP.h/.cpp               - Represents a 2D grid map  
│   ├── Record.h/.cpp            - Handles file operations  
│   ├── RobotOperator.h/.cpp     - Manages operator access and credentials  
│   ├── Encryption.h/.cpp        - Provides encryption and decryption functionalities  
└── README.md  
