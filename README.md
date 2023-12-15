# 2023_2024_mini_project_Junjiang_Thuang_Stephane

## Introduction
Following the production of the AIME laboratory gas sensor, we aim to develop a system using an ESP32 microcontroller. This system will be designed to gather data from the sensor and transmit the detection of a specific gas to a server via a LoRA module.
Our projects mainly include：
 - The Arduino code for sensors to collect data
 - The PCB shield and KiCad project content
 - The Node-Red to display the dashboard
 - The Datasheet for the sensor

## LoRa
The code in the directory Piste_Verte is a key component of our project, enabling wireless communication over long distances with low power consumption.

<details>
 <summary><b>Pin Configuration</b></summary>
```c++
#define rxPin 10
#define txPin 11
```
rxPin and txPin are defined for the serial connection to the LoRa module, allowing for data transmission and reception.
</details>
