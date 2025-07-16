import cv2
import serial
import time
import numpy as np

# Initialize serial communication with Arduino
arduino = serial.Serial('/dev/ttyUSB0', 9600)  # Update COM port as needed
time.sleep(2)  # Allow time for Arduino to reset

# Define HSV range for blue color
lower_blue = np.array([100, 150, 50])
upper_blue = np.array([140, 255, 255])

# Initialize webcam
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Convert to HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Create mask for blue color
    mask = cv2.inRange(hsv, lower_blue, upper_blue)
    result = cv2.bitwise_and(frame, frame, mask=mask)

    # Find contours
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if contours:
        # Get largest contour
        c = max(contours, key=cv2.contourArea)
        area = cv2.contourArea(c)
        if area > 500:  # Threshold to filter noise
            x, y, w, h = cv2.boundingRect(c)
            cx = x + w // 2

            # Draw rectangle and center
            cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)
            cv2.circle(frame, (cx, y + h // 2), 5, (0, 255, 0), -1)

            # Send direction to Arduino
            frame_center = frame.shape[1] // 2
            if cx < frame_center - 50:
                arduino.write(b'L')  # Left
            elif cx > frame_center + 50:
                arduino.write(b'R')  # Right
            else:
                arduino.write(b'F')  # Forward
        else:
            arduino.write(b'S')  # Stop
    else:
        arduino.write(b'S')  # Stop if no object found

    # Show result
    cv2.imshow("Frame", frame)
    cv2.imshow("Mask", mask)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
arduino.close()