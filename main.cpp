#include <iostream>
#include <vector>
#include <string>

using namespace std;

// This class represents a single room in the hotel
class Room {
public:
  // Room number (e.g., 101, 202)
  int roomNumber;

  // Type of room (e.g., Single, Double, Suite)
  string type;

  // Whether the room is available for booking (true) or not (false)
  bool available;

  // Constructor to create a new Room object (called when adding a room)
  Room(int number, string type) : roomNumber(number), type(type), available(true) {}

  // Function to display information about the room
  void displayInfo() const {
    cout << "Room Number: " << roomNumber << endl;
    cout << "Type: " << type << endl;
    cout << "Available: " << (available ? "Yes" : "No") << endl;
  }
};

// This class represents the entire hotel
class Hotel {
private:
  // Vector (like an array) to store all the Room objects in the hotel
  vector<Room> rooms;

public:
  // Function to add a new room to the hotel
  void addRoom() {
    int number;
    string type;

    cout << "Enter room number: ";
    cin >> number;

    cout << "Enter room type (Single, Double, Suite): ";
    cin >> type;

    // Create a new Room object with the entered details and add it to the vector
    rooms.push_back(Room(number, type));

    cout << "Room added successfully!" << endl;
  }

  // Function to check if a room is available for booking
  bool isRoomAvailable(int number) {
    for (const Room& room : rooms) {
      if (room.roomNumber == number && room.available) {
        return true;
      }
    }
    return false;
  }

  // Function to book a room (assuming successful payment is handled elsewhere)
  void bookRoom(int number) {
    if (isRoomAvailable(number)) {
      for (Room& room : rooms) {
        if (room.roomNumber == number) {
          room.available = false;
          cout << "Room " << number << " booked successfully!" << endl;
          break;
        }
      }
    } else {
      cout << "Room " << number << " is not available." << endl;
    }
  }

  // Function to display information about all rooms
  void displayAllRooms() {
    if (rooms.empty()) {
      cout << "There are currently no rooms in the hotel." << endl;
    } else {
      cout << "** Hotel Rooms **" << endl;
      for (const Room& room : rooms) {
        room.displayInfo();
        cout << endl;
      }
    }
  }
};

int main() {
  // Create a Hotel object (represents our hotel)
  Hotel myHotel;

  int choice;

  // Loop to display a menu and handle user input
  do {
    cout << "\n** Hotel Booking System **" << endl;
    cout << "1. Add Room" << endl;
    cout << "2. Display All Rooms" << endl;
    cout << "3. Book a Room" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        myHotel.addRoom(); // Call function to add a new room
        break;
      case 2:
        myHotel.displayAllRooms(); // Call function to display all rooms
        break;
      case 3:
        int roomNumber;
        cout << "Enter room number to book: ";
        cin >> roomNumber;
        myHotel.bookRoom(roomNumber); // Call function to book a room
        break;
      case 4:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice." << endl;
    }
  } while (choice != 4);

  return 0;
}
