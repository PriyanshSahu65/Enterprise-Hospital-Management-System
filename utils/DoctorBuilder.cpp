// src/DoctorBuilder.cpp
#include "DoctorBuilder.h"
#include "Doctor.h"          // Definition of the Doctor class
#include "ShiftSchedule.h"   // Definition of the ShiftSchedule class
#include "ShiftDetails.h"    // Definition of the ShiftDetails class (now used)
#include <iostream>          // For standard output (e.g., debugging messages, errors)
#include <stdexcept>         // For exceptions like std::stoi (string to int conversion)
#include <string>            // For std::string usage
#include <vector>            // For std::vector usage

DoctorBuilder::DoctorBuilder() {
    std::cout << "DoctorBuilder created." << std::endl;
    this->filePath = "data/doctors.csv"; // Example path, adjust as needed by your data files
}

std::vector<DataObject*>* DoctorBuilder::constructDataObject(std::vector<std::vector<std::string>>* rawData) {
    std::vector<DataObject*>* doctors = new std::vector<DataObject*>();

    if (!rawData) {
        std::cerr << "Error: rawData is null in DoctorBuilder::constructDataObject. Returning empty list." << std::endl;
        return doctors;
    }

    // Expected CSV format for Doctor:
    // ID,Name,DOB,Gender,Mobile,City,Specialization,ScheduleID,Shift1ID,Shift1Date,Shift1StartTime,Shift1EndTime,Shift2ID,Shift2Date,Shift2StartTime,Shift2EndTime,...
    // Minimum columns for Doctor without shifts: 7
    // Minimum columns for Doctor with a schedule ID and at least one shift entry:
    // 7 (Doctor) + 1 (ScheduleID) + 4 (ShiftDetails entry: ID, Date, StartTime, EndTime) = 12
    const size_t MIN_DOCTOR_COLUMNS = 7;
    const size_t INDEX_SCHEDULE_ID = MIN_DOCTOR_COLUMNS; // Index of ScheduleID column
    const size_t SHIFT_DETAILS_ENTRY_SIZE = 4; // Each shift detail is four columns (ID, Date, StartTime, EndTime)

    for (const auto& row : *rawData) {
        if (row.size() < MIN_DOCTOR_COLUMNS) {
            std::cerr << "Warning: Skipping malformed row in doctor data (expected at least " << MIN_DOCTOR_COLUMNS << " columns): ";
            for (const auto& cell : row) {
                std::cerr << cell << " ";
            }
            std::cerr << std::endl;
            continue; // Skip to the next row
        }

        std::string id = row[0];
        std::string name = row[1];
        std::string dob = row[2];
        std::string gender = row[3];
        std::string mobile = row[4];
        std::string city = row[5];
        std::string specialization = row[6];

        ShiftSchedule* currentShiftSchedule = nullptr;
        std::string scheduleID_str = "NoSchedule";
        std::vector<ShiftDetails*> shiftsForSchedule; // Temporarily hold ShiftDetails for current schedule

        // Check if there's enough data for a schedule ID and potentially shifts
        if (row.size() > INDEX_SCHEDULE_ID) {
            scheduleID_str = row[INDEX_SCHEDULE_ID]; // Get ScheduleID

            // Parse ShiftDetails entries from remaining columns
            // Start parsing from column after ScheduleID (INDEX_SCHEDULE_ID + 1)
            for (size_t i = INDEX_SCHEDULE_ID + 1; i + SHIFT_DETAILS_ENTRY_SIZE - 1 < row.size(); i += SHIFT_DETAILS_ENTRY_SIZE) {
                std::string shiftDetailID = row[i];
                std::string shiftDate = row[i + 1];
                std::string shiftStartTime = row[i + 2];
                std::string shiftEndTime = row[i + 3];
                shiftsForSchedule.push_back(new ShiftDetails(shiftDetailID, shiftDate, shiftStartTime, shiftEndTime));
            }
        }

        // Create the ShiftSchedule object using the constructor that takes a vector of ShiftDetails*
        // The ShiftSchedule constructor will deep copy the ShiftDetails objects.
        currentShiftSchedule = new ShiftSchedule(scheduleID_str, shiftsForSchedule);

        // IMPORTANT: Delete the original ShiftDetails objects created in this loop.
        // ShiftSchedule's constructor made *copies*, so these originals are no longer needed.
        for (ShiftDetails* sd : shiftsForSchedule) {
            delete sd;
        }
        shiftsForSchedule.clear(); // Clear the temporary vector

        // Create the Doctor object
        Doctor* doctor = new Doctor(id, name, dob, gender, mobile, city, specialization, currentShiftSchedule);
        doctors->push_back(doctor);
    }
    return doctors;
}