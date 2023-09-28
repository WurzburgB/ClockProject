#include <iostream>
#include <ctime>

class Clock {
private:
    int hours;
    int minutes;
    int seconds;
    bool is24HourFormat;

public:
    // Constructor to initialize the clock
    Clock(bool is24HourFormat = false) : is24HourFormat(is24HourFormat) {
        // Initialize clock with current time
        time_t currentTime = time(0);
        struct tm* now = localtime(&currentTime);

        // Set clock values to current time
        hours = now->tm_hour;
        minutes = now->tm_min;
        seconds = now->tm_sec;
    }

    // Display the clock
    void display() const {
        if (is24HourFormat) {
            // Display both clocks in 24-hour format
            std::cout << "**************************   ***************************\n";
            std::cout << "*       12-Hour Clock    *   *      24-Hour Clock      *\n";
            std::cout << "*        " << formatTime(true) << " A M    *   *       " << formatTime(false) << "          *\n";
            std::cout << "**************************   ***************************\n";
        } else {
            // Display both clocks in 12-hour format
            std::cout << "**************************   ***************************\n";
            std::cout << "*       12-Hour Clock    *   *      24-Hour Clock      *\n";
            std::cout << "*        " << formatTime(true) << " P M    *   *       " << formatTime(false) << "          *\n";
            std::cout << "**************************   ***************************\n";
        }
    }

    // Add one hour to the clock
    void addHour() {
        hours = (hours + 1) % (is24HourFormat ? 24 : 12);
    }

    // Add one minute to the clock
    void addMinute() {
        minutes = (minutes + 1) % 60;
    }

    // Add one second to the clock
    void addSecond() {
        seconds = (seconds + 1) % 60;
    }

private:
    // Format the time for display
    std::string formatTime(bool use12HourClock) const {
        char buffer[9];
        int hour = use12HourClock ? (hours % 12 == 0 ? 12 : hours % 12) : hours;
        snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hour, minutes, seconds);
        return buffer;
    }
};

int main() {
    Clock clock12(false); // Create 12-hour clock
    Clock clock24(true);  // Create 24-hour clock

    int choice;
    do {
        clock12.display();
        std::cout << "\nSelect an option:\n";
        std::cout << "1 - Add One Hour\n";
        std::cout << "2 - Add One Minute\n";
        std::cout << "3 - Add One Second\n";
        std::cout << "4 - Exit Program\n";
        std::cout << "\nEnter your choice:\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                clock12.addHour();
                clock24.addHour();
                break;
            case 2:
                clock12.addMinute();
                clock24.addMinute();
                break;
            case 3:
                clock12.addSecond();
                clock24.addSecond();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please select a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}