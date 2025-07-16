# Autonomous_Navigation_Robot

<img src="https://github.com/user-attachments/assets/ab0de446-8694-43d3-a473-4477a548696f" width="300" height="300">
<img src="https://github.com/user-attachments/assets/4bdd75f5-8e7e-4d91-979d-9ddc39a68365" width="400" height="500">

The project features a compact autonomous robot designed with **NVIDIA Jetson Nano** for high-level perception and **Arduino UNO** for low-voltage motor control. The system achieves **synchronized control** via serial communication and demonstrates smooth navigation and real-time motion coordination across diverse environments.

## Features <img width="20" height="20" src="https://github.com/user-attachments/assets/aad1c7d2-f85b-4926-a4dc-0078bb78e500" />

1. **Dual-Board Architecture**: Jetson Nano (AI processing) + Arduino UNO (real-time motor control)
2. **Autonomous Navigation**: Precision control and obstacle avoidance logic
3. **Serial Communication Protocol**: Custom UART commands between boards
4. **Motion Control**: DC motors controlled via L298N using PID-like tuned logic
5. **Performance Gains**: 20% improvement in navigation accuracy, 15% latency reduction
6. **Hardware-Compliant**: Developed by interpreting technical datasheets and pin mappings for clean integration

## How It Works <img width="20" height="20" src="https://github.com/user-attachments/assets/21a7819d-10a2-4485-8305-d492213519cb" />

• **Jetson Nano** handles navigation logic, path planning, and sends motor commands via UART. <br/>
• **Arduino UNO** receives serial commands and drives DC motors using L298N driver. <br/>
• Continuous feedback loop ensures real-time adjustments and accurate navigation. <br/>
• Testing involved 50+ runs to fine-tune latency, speed, and direction stability.
