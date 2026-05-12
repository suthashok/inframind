# 🚦 Real World Traffic Light Simulator

A simple yet powerful project that brings real-world traffic light logic to life using an **Arduino Uno**.

This simulator helps you understand how traffic signals operate, making it perfect for beginners, students, and hobbyists exploring embedded systems and electronics.

---

## 📌 Overview

This project tries to replicate the behavior of a real-world traffic signal system using LEDs, Switches and an Arduino Uno board. It cycles through standard traffic light states—**Red**, **Yellow**, and **Green**—with realistic timing and transitions.

Whether you're learning Arduino or want to demonstrate a real world embedded system, this project can help you understand the design.

---

## ✨ Features

* 🚥 Simulates real-world traffic light sequences (Green -> Yello -> Red)
* ⏱ Adjustable timing for each signal
* 🔌 Easy-to-build circuit using basic components (Arduino Board, LEDs, Switches)
* 🧠 Beginner-friendly logic and code structure
* 🛠 Emergency Operator Switch to make any existing Green to Red and existing Red to Green (Ambulance, VIP passing etc.)

---

## 🧰 Components Required

* Arduino Uno
* Red, Yellow, and Green LEDs
* Resistors (220Ω recommended)
* Breadboard
* Jumper wires
* Push Button Switches
* USB cable for programming

---

## 🔌 Circuit Diagram

Detailed Circuit Diagram is available here: link

---

## 💻 Installation & Setup

1. Clone this repository:

   ```bash
   git clone https://github.com/suthashok/inframind.git
   ```

2. Open the Arduino IDE.

3. Upload the traffic signal lights code to your Arduino Uno.

4. Power the board via USB.

---

## 🧠 How It Works

The Arduino runs a loop that:

1. Turns **Green ON** → allows traffic to move
2. Switches to **Yellow** → warns that the signal is about to change
3. Turns **Red ON** → stops traffic

Each state runs for a defined duration using `timers`.

---


## 🤝 Contributing

Contributions are welcome! Feel free to fork this repo and submit a pull request.

---

## 📄 License

This project is open-source and available under the MIT License.

---

## 🙌 Acknowledgments

Inspired by real-world traffic systems and useful Arduino projects.

---

⭐ If you found this helpful, consider giving it a star!