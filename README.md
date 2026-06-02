# 🛸 BPLA Console Simulator

A cross-platform console simulator for a UAV (unmanned aerial vehicle) control terminal, written in **C++**. The project is built on the principles of modular architecture, secure input validation, and state management (State Machine).

## 🚀 Main Features

* **Secure Access Module (Encryption):** System login is password-protected with a limited number of attempts (3 attempts), simulating brute-force protection found in real military or industrial hardware.
* **Engine Control (ARM/DISARM):** Logical protection against accidental engine shutdown during flight or acceleration.
* **Automatic Takeoff (TAKEOFF):** Rapid ascent to an initial safe altitude of 10 meters.
* **Flexible flight control:** Ability to manually adjust altitude (from 0 to 500 m) and speed (from 0 to 100 km/h) with full “foolproof” protection (Bulletproof Input Validation). The system ignores letters accidentally entered instead of numbers and does not get stuck in a loop.
* **Safe landing (LAND):** Physically correct landing algorithm. The drone first reduces horizontal speed to 0 (hovering), and then smoothly (simulating real time via `Sleep` delays) lowers its altitude until it comes to a complete stop on the ground.

## 🛠️ Project Architecture

The project is divided into logical modules (header files `.h` + implementation `.cpp`), which complies with commercial development standards:

* `main.cpp` — a clean entry point that launches the security check and menu.
* `encryption.h` / `encryption.cpp` — an isolated “black box” for the authorization module.
* `drone.h` / `drone.cpp` — the simulator core (UAV state variables in the `namespace Drone` namespace and flight control functions).
* `.gitignore` — a custom filter that protects the repository from being cluttered with junk and temporary Visual Studio files.

## ⚙️ How to run the project

1. Clone the repository to your computer.
2. Open the project folder in **Visual Studio** (or any other IDE that supports C++20).
3. Make sure all 5 files (`main.cpp`, `drone.cpp`, `drone.h`, `encryption.cpp`, `encryption.h`) are included in your build.
4. Compile and run the project.
5. **Default login password:** `1234`

Translated with DeepL.com (free version)
