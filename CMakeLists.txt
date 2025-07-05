cmake_minimum_required(VERSION 3.10)

project(HospitalApp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define source files
set(SOURCE_FILES
    main.cpp
    src/AdministrativeStaff.cpp
    src/Appointment.cpp
    src/Billing.cpp
    src/Department.cpp
    src/Doctor.cpp
    src/Inventory.cpp
    src/Item.cpp
    src/Lab.cpp
    src/Logger.cpp
    src/MedicalRecord.cpp
    src/Nurse.cpp
    src/ObjectCache.cpp
    src/ObjectCounter.cpp
    src/ObjectData.cpp
    src/Patient.cpp
    src/Person.cpp
    src/Prescription.cpp
    src/ShiftDetails.cpp
    src/ShiftSchedule.cpp
    src/Staff.cpp
    src/StockItem.cpp
    src/Supplier.cpp
    src/Test.cpp
    utils/Builder.cpp
    utils/DoctorBuilder.cpp
    utils/PatientBuilder.cpp
    utils/NurseBuilder.cpp
    utils/BuilderFactory.cpp
)

# Add executable first
add_executable(hospital_app ${SOURCE_FILES})

# Now it's safe to configure the target
target_include_directories(hospital_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Compiler warnings and debug symbols
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(hospital_app PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        #-Werror
        -g
    )
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(hospital_app PRIVATE
        /W4
        #/WX
        /Zi
    )
endif()
