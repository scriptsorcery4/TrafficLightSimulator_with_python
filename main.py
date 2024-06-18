import serial
import time

# Connect to the serial port (replace 'COM3' with the appropriate port)
ser = serial.Serial('COM3', 9600, timeout=1)

# Wait for Arduino to reset and connect
time.sleep(2)

def send_command(command):
    if command.lower() == 'stop':
        ser.write(b'1,0,0\n')
    elif command.lower() == 'wait':
        ser.write(b'0,1,0\n')
    elif command.lower() == 'go':
        ser.write(b'0,0,1\n')
    else:
        print("Unknown command")

try:
    while True:
        user_input = input("Enter command (stop, wait, go) or 'exit' to quit: ")
        if user_input.lower() == 'exit':
            break
        send_command(user_input)
        time.sleep(0.5)  # Give time for Arduino to process the command

except KeyboardInterrupt:
    print("Program interrupted")

finally:
    ser.close()
