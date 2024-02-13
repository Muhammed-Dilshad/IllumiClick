# IllumiClick

## Executive Summary:

- The "IllumiClick" project involves the integration of an ESP32 microcontroller with Firebase Realtime Database to control an LED remotely.
- The project includes a mobile app, "IllumiClick," allowing users to interact with the Firebase Realtime Database to toggle the LED state.

## Introduction:

The "IllumiClick" project aims to create a user-friendly system for remote LED control via a mobile app. It integrates an ESP32 with Firebase Realtime Database, enabling users to toggle the LED using the "IllumiClick" app. Key objectives include real-time communication, secure data transmission, and a simple mobile interface. The project showcases IoT capabilities by facilitating wireless control of a physical device through a cloud-based platform.

The "IllumiClick" project involves three main hardware components:

1. [ESP32 Microcontroller:](http://esp32.net)
   - Facilitates communication with the Firebase Realtime Database.
   - Controls the LED based on received data.
2. LED:
   - Represents a tangible output that users can control remotely.
3. Mobile App ("IllumiClick"):
   - User-friendly interface for toggling the LED's state.

## Project Scope:

The project focuses on developing both hardware and software components to enable remote LED control.

**Inclusions:**

1. ESP32 Microcontroller:
   - Core hardware for communication and control.
2. Firebase Realtime Database:
   - Cloud-based storage facilitating real-time data exchange.
3. "IllumiClick" Mobile App:
   - User interface for remote LED control.

**Exclusions:**

The current project focuses specifically on its defined scope, and extensive discussions about other IoT devices or additional functionalities are not within the current scope.

## Stakeholders:

**Team Members:**

1. Aswinlal K S
   - Role: App Developer
   - Responsibilities:
     - Developed the "IllumiClick" mobile app.
     - Focused on the user interface and overall app functionality.
2. Muhammed Dilshad K
   - Role: Integration
   - Responsibilities:
     - Integrated the mobile app with Firebase Realtime Database.
     - Integrated the app and ESP32 module for seamless communication.
3. Remiel George VJ
   - Role: Project Support
   - Responsibilities:
     - Provides general support to the project.
     - Assists with miscellaneous tasks or requirements as needed.
4. Sharun P S
   - Role: Project Support
   - Responsibilities:
     - Provides general support to the project.
     - Assists with miscellaneous tasks or requirements as needed.

## Requirements:

- Functional requirements:
  - ESP32 connectivity to Firebase Realtime Database.
  - Secure and reliable data transmission.
  - Mobile app interface for controlling LED state.
- Non-functional requirements:
  - Real-time communication between the app and the ESP32.

## Architecture:

### System Architecture:

The project's system architecture involves two primary components:

1. ESP32 Interacting with Firebase Realtime Database:
   - The ESP32 microcontroller communicates with the Firebase Realtime Database to send and receive data, enabling remote LED control.
2. Mobile App Communicating with the Database:
   - The "IllumiClick" mobile app interacts with the Firebase Realtime Database to send user commands and receive real-time updates on the LED state.

### Database Design:

The Firebase Realtime Database incorporates a dedicated node for LED state storage:

- "/LED_STATE" Node:
  - This node serves as a repository for storing and retrieving real-time information about the LED, allowing seamless communication between the ESP32 and the mobile app.

## Design:

### Hardware Design:

![Screenshot 2024-02-01 064400.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/47461b2c-536a-443a-b874-34c0c5502936/d5ced98d-2a1b-438b-a7d1-88d08355f45d/Screenshot_2024-02-01_064400.png)

### Components:

1. Microcontroller: ESP32
   - Model: ESP32 Devkit
   - Description: The ESP32 microcontroller serves as the main processing unit in the project. It is responsible for interfacing with the Firebase Realtime Database and controlling connected peripherals.
2. LED
   - Type: RED 5mm LED
   - Description: The LED is used as an indicator in the project. It is connected to the ESP32 and controlled based on data retrieved from the Firebase Realtime Database.
3. [Firebase Realtime Database](https://www.notion.so/IllumiClick-9172a7ae9d9140e0bd6c1fc65e11bb81?pvs=21)
   - Description: The Firebase Realtime Database acts as the cloud-based storage solution for the project. It facilitates real-time communication between the ESP32 microcontroller and the mobile app, allowing for dynamic control of connected devices.

### User Interface Design

:

The "IllumiClick" app features an intuitive user interface designed for remote LED control. Included are screenshots or wireframes showcasing the app's layout, controls, and visual elements.

![Section 1 (Medium).png](https://prod-files-secure.s3.us-west-2.amazonaws.com/47461b2c-536a-443a-b874-34c0c5502936/7ece02f6-aeb9-46c4-bf75-3f708c21106a/Section_1_(Medium).png)

### Data Flow Diagrams:

A diagram visually representing the flow of data within the system. Illustrates the communication pathways between the "IllumiClick" app, Firebase Realtime Database, and the ESP32 microcontroller. Provides an overview of how user commands are transmitted to the ESP32, influencing the LED state, and how real-time updates on the LED status are conveyed back to the app.

### Work flow:

![hai.svg](https://prod-files-secure.s3.us-west-2.amazonaws.com/47461b2c-536a-443a-b874-34c0c5502936/d7722868-f1c4-4cee-9f93-f634194de12d/hai.svg)

## Technologies Used:

- **Programming Languages:**
  - **C++:** Utilized for developing the codebase of the ESP32 microcontroller.
  - **MIT App Inventor** (Visual Blocks Language): Employed for developing the "IllumiClick" mobile app.
- **Frameworks and Libraries:**
  - FirebaseESP32 Library: Facilitated seamless integration between the ESP32 and the Firebase Realtime Database.
- **Database Management System:**
  - Firebase Realtime Database: Selected as the cloud-based database system for storing and retrieving real-time LED state information.

## Implementation:

- **Overview of Code Structure:**
  - The codebase is organized to ensure clarity and efficiency in handling ESP32 functionality and interaction with the Firebase Realtime Database.
  - Structured modules for distinct functionalities, promoting maintainability.
  - Explanation for your provided Arduino code:

```arduino
#include <FirebaseESP32.h>
#include <WiFi.h>

// Firebase configuration
#define FIREBASE_HOST "Your_firebase_url "
#define FIREBASE_AUTH "your_firebase_auth_token"

// LED pin configuration
#define LED_PIN 13 // Assuming the LED is connected to pin 13

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin("your_wifi_ssid", "your_wifi_password");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Read LED state from Firebase
  Firebase.getString("LED_STATE");
  if (Firebase.getString("LED_STATE") == "ON") {
    digitalWrite(LED_PIN, HIGH); // Turn ON the LED
  } else {
    digitalWrite(LED_PIN, LOW); // Turn OFF the LED
  }

  delay(1000); // Adjust delay as needed
}
```

**Explanation:**

1. **Firebase Configuration:**
   - The code defines the Firebase Realtime Database host and authentication token, which are used to establish a connection with the database.
2. **LED Pin Configuration:**
   - The code sets the GPIO pin for the LED, assuming it is connected to pin 13 on the ESP32.
3. **Setup Function:**
   - Initiates the serial communication for debugging.
   - Connects to the specified Wi-Fi network using the provided SSID and password.
   - Initializes the Firebase connection with the configured host and authentication token.
4. **Loop Function:**
   - In each iteration of the loop:
     - Reads the "LED_STATE" value from the Firebase Realtime Database using `Firebase.getString()`.
     - Checks if the retrieved state is "ON" and turns the LED ON (HIGH) accordingly, or turns it OFF (LOW) if the state is anything else.
     - Includes a delay of 1000 milliseconds (1 second) between iterations, which can be adjusted based on the project requirements.

This code essentially enables the ESP32 to read the LED state from the Firebase database and control the connected LED accordingly. Adjustments can be made to the delay or other parameters based on specific project needs.

- **Key Functions:**
  - Highlighting crucial functions such as:
    - Initialization: Setting up pins, establishing Wi-Fi connection, and initializing Firebase.
    - Real-time Data Retrieval: Code responsible for fetching LED state from the Firebase "/LED_STATE" node.
    - LED Control: Functions managing the state of the LED based on Firebase data.
- **Configuration Details for Firebase and Wi-Fi Settings:**
  - Guidance on configuring Firebase:
    - Integration of FirebaseESP32 library.
    - Providing authentication details and defining the database structure.
  - Configuration of Wi-Fi settings:
    - Instructions for connecting the ESP32 to the local Wi-Fi network.
      1. **Open the Arduino IDE:**
         - Launch the Arduino IDE on your development machine.
      2. **Load the ESP32 Code:**
         - Load the ESP32 code for the "IllumiClick" project into the Arduino IDE.
      3. **Navigate to Wi-Fi Configuration Section:**
         - Locate the section in the code where Wi-Fi settings are configured.
      4. **Enter Wi-Fi SSID and Password:**
         - Replace the placeholders with your Wi-Fi credentials:
           - Replace "your-Wi-Fi-ssid" with your Wi-Fi SSID.
           - Replace "your-Wi-Fi-password" with your Wi-Fi password.
      5. **Compile and Upload:**
         - Compile the code to check for any errors.
         - Upload the code to the ESP32 board.
      6. **Open Serial Monitor:**
         - Open the Serial Monitor in the Arduino IDE to monitor the ESP32's connection status.
      7. **Power Up ESP32:**
         - Ensure the ESP32 is powered up and connected to your development machine.
      8. **Monitor Serial Output:**
         - Observe the Serial Monitor for messages indicating the ESP32's successful connection to the Wi-Fi network.

         ```arduino
         cssCopy code
         Connecting to WIFI..........
         Connected to WIFI!
         ```

      9. **Confirmation:**
         - Confirm the successful connection before proceeding with any interactions with the "IllumiClick" app.

## Conclusion:

In summary, the "IllumiClick" project has successfully achieved its objectives of creating a seamless and user-friendly system for remote LED control. The integration of the ESP32 microcontroller with the Firebase Realtime Database, coupled with the "IllumiClick" mobile app, showcases the practical implementation of IoT in enabling wireless control of a physical device.

**Key Achievements:**

- Establishment of real-time communication between the mobile app and the ESP32.
- Secure data transmission through Firebase Realtime Database integration.
- Development of a user-friendly interface in the "IllumiClick" app for intuitive LED control.

**Acknowledgments:**

We extend our sincere gratitude to the entire project team for their dedication and collaborative efforts in bringing "IllumiClick" to fruition. Each team member

's unique contributions played a crucial role in the project's success. Additionally, we appreciate any external contributors or resources that supported our endeavor.

The "IllumiClick" project serves as a testament to the capabilities of IoT, providing a practical solution for remote device control. We look forward to future enhancements and applications of this technology.

### Tools and Resources Used

### Software Tools:

1. **Arduino IDE:**
   - Used for writing, compiling, and uploading code to the ESP32 microcontroller.
2. **MIT App Inventor:**
   - Employed for developing the "IllumiClick" mobile app using visual blocks language.

### Websites:

1. **Firebase Console:**
   - Accessed for configuring and managing the Firebase Realtime Database.
   - [Firebase Console](https://console.firebase.google.com/)
2. **ESP32 Official Website:**
   - Referenced for documentation, specifications, and support related to the ESP32 microcontroller.
   - [ESP32 Official Website](http://esp32.net/)

### Special Mention:

We would like to express our gratitude to the developers and communities behind these tools and resources. Their contributions have been invaluable to the successful implementation of the "IllumiClick" project.
