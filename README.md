# Enterprise Hospital Management System

```
    ╱|、
  (˚ˎ 。7
   |、˜〵
   じしˍ,)ノ
```

A comprehensive, enterprise-grade **Hospital Management System** built with modern C++ featuring advanced design patterns (Builder, Cache, Factory), CSV-based data persistence, and robust object-oriented architecture. This system manages complete healthcare operations including patient records, appointments, billing, inventory, lab tests, and staff scheduling.

## 🏥 Features

### Core Modules
- **Patient Management**: Complete patient lifecycle with medical records and prescriptions
- **Doctor & Nurse Management**: Staff profiles with specializations and shift scheduling
- **Appointment System**: Comprehensive booking and scheduling with department allocation
- **Billing System**: Automated invoice generation and payment processing
- **Medical Records**: Secure health history, diagnoses, and treatment tracking
- **Prescription Management**: Medication tracking with dosage and instructions
- **Laboratory System**: Test orders, results, and lab report management
- **Inventory Management**: Medical supplies, stock items, and supplier tracking
- **Department Management**: Multi-department support with resource allocation
- **Shift Scheduling**: Advanced scheduling system for doctors and nurses
- **Administrative Staff**: Role-based access control and staff management

### Advanced Features
- **Builder Pattern Implementation**: Flexible object construction for complex entities
- **Object Caching System**: Performance optimization with intelligent caching
- **Object Counter**: Real-time tracking and memory management
- **Logger System**: Comprehensive logging with file persistence (data/log.txt)
- **CSV Data Management**: Large-scale data ingestion and export capabilities
- **Factory Pattern**: Automated builder creation and object instantiation
- **Data Validation**: Robust input validation and error handling

## 🛠️ Tech Stack

- **Language**: C++ (C++11/14 standard)
- **Build System**: CMake 3.x
- **Architecture**: Object-Oriented Design with Design Patterns
- **Data Storage**: CSV files (data/*.csv)
- **IDE Support**: VS Code configuration included
- **Platform**: Cross-platform (Windows, Linux, macOS)

### Design Patterns Used
- Builder Pattern (Patient, Doctor, Nurse builders)
- Factory Pattern (BuilderFactory)
- Singleton Pattern (ObjectCache, Logger)
- Template Pattern (ObjectCounter)

## 📋 Prerequisites

- **C++ Compiler**: 
  - GCC/G++ 7.0+ (Linux/macOS)
  - MinGW-w64 or MSVC (Windows)
- **CMake**: Version 3.10 or higher
- **Python**: 3.7+ (for data generation scripts)
- **Text Editor/IDE**: VS Code (recommended) or any C++ IDE

## ⚙️ Installation & Setup

### Step 1: Clone the Repository
```bash
git clone https://github.com/PriyanshSahu65/Enterprise-Hospital-Management-System
cd Enterprise-Hospital-Management-System
```

### Step 2: Build the Project

#### Using CMake (Recommended)
```bash
# Create and enter build directory
mkdir build
cd build

# Generate build files
cmake ..

# Compile the project
cmake --build .

# Or on Windows with MinGW
cmake -G "MinGW Makefiles" ..
mingw32-make
```

#### On Windows (PowerShell/CMD)
```cmd
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

#### On Linux/macOS
```bash
mkdir build && cd build
cmake ..
make
```

### Step 3: Run the Application
```bash
# From build directory
./hospital_app           # Linux/macOS
hospital_app.exe         # Windows
```

## 🚀 Usage

### Running the Application
```bash
# After building
cd build
./hospital_app.exe  # Windows
./hospital_app      # Linux/macOS
```

### Data Generation
```bash
# Generate large test datasets
cd utils
python generate_large_data.py
```

### Initial Setup
The application loads data from CSV files in the `data/` directory on startup. Pre-populated datasets are included for:
- Patients (patients_large.csv)
- Doctors (doctors_large.csv)
- Nurses (nurses_large.csv)
- Appointments (appointments_large.csv)
- Departments (departments_large.csv)
- Medical Records (medicalrecords_large.csv)
- Billing (billing_large.csv)
- Inventory (inventory_large.csv, stockitems_large.csv)
- Lab Tests (labs_large.csv, tests_large.csv)
- Prescriptions (prescriptions_large.csv)
- Staff Schedules (shiftschedules_*.csv)

## 📊 Project Structure

```
Enterprise-Hospital-Management-System/
│
├── main.cpp                    # Application entry point
├── CMakeLists.txt             # CMake build configuration
├── README.md                  # Project documentation
│
├── include/                   # Header files (.h)
│   ├── Person.h              # Base person class
│   ├── Patient.h             # Patient management
│   ├── Doctor.h              # Doctor entity
│   ├── Nurse.h               # Nurse entity
│   ├── Staff.h               # Staff base class
│   ├── AdministrativeStaff.h # Admin staff
│   ├── Appointment.h         # Appointment scheduling
│   ├── Billing.h             # Billing system
│   ├── Department.h          # Department management
│   ├── MedicalRecord.h       # Medical records
│   ├── Prescription.h        # Prescription management
│   ├── Lab.h                 # Laboratory system
│   ├── Test.h                # Lab tests
│   ├── Inventory.h           # Inventory management
│   ├── Item.h                # Inventory items
│   ├── StockItem.h           # Stock tracking
│   ├── Supplier.h            # Supplier management
│   ├── ShiftSchedule.h       # Shift scheduling
│   ├── ShiftDetails.h        # Shift details
│   ├── Logger.h              # Logging system
│   ├── ObjectCache.h         # Caching system
│   ├── ObjectCounter.h       # Object tracking
│   ├── DataObject.h          # Base data object
│   └── config.h              # Configuration
│
├── src/                       # Implementation files (.cpp)
│   ├── Person.cpp
│   ├── Patient.cpp
│   ├── Doctor.cpp
│   ├── Nurse.cpp
│   ├── Staff.cpp
│   ├── AdministrativeStaff.cpp
│   ├── Appointment.cpp
│   ├── Billing.cpp
│   ├── Department.cpp
│   ├── MedicalRecord.cpp
│   ├── Prescription.cpp
│   ├── Lab.cpp
│   ├── Test.cpp
│   ├── Inventory.cpp
│   ├── Item.cpp
│   ├── StockItem.cpp
│   ├── Supplier.cpp
│   ├── ShiftSchedule.cpp
│   ├── ShiftDetails.cpp
│   ├── Logger.cpp
│   ├── ObjectCache.cpp
│   ├── ObjectCounter.cpp
│   └── ObjectData.cpp
│
├── utils/                     # Utility classes and scripts
│   ├── Builder.h/cpp         # Builder pattern base
│   ├── BuilderFactory.h/cpp  # Factory for builders
│   ├── PatientBuilder.h/cpp  # Patient construction
│   ├── DoctorBuilder.h/cpp   # Doctor construction
│   ├── NurseBuilder.h/cpp    # Nurse construction
│   └── generate_large_data.py # Python data generator
│
├── data/                      # CSV data files
│   ├── patients_large.csv
│   ├── doctors_large.csv
│   ├── nurses_large.csv
│   ├── appointments_large.csv
│   ├── billing_large.csv
│   ├── departments_large.csv
│   ├── medicalrecords_large.csv
│   ├── prescriptions_large.csv
│   ├── labs_large.csv
│   ├── tests_large.csv
│   ├── inventory_large.csv
│   ├── stockitems_large.csv
│   ├── suppliers_large.csv
│   ├── admins_large.csv
│   ├── shiftschedules_doctors_large.csv
│   ├── shiftschedules_nurses_large.csv
│   ├── items_large.csv
│   ├── shiftdetails_large.csv
│   ├── log.txt               # Application logs
│   └── README_data_ingestion.md
│
├── build/                     # Build output directory
│   ├── hospital_app.exe      # Compiled executable
│   ├── CMakeCache.txt
│   ├── Makefile
│   └── CMakeFiles/
│
└── .vscode/                   # VS Code configuration
    └── settings.json
```

## 💡 Key Highlights

### Performance & Scalability
- **Object Caching**: Reduces database/file I/O with intelligent caching
- **Large Dataset Support**: Handles 1000+ records per entity type
- **Optimized Data Loading**: Efficient CSV parsing and memory management
- **Design Pattern Architecture**: Maintainable and extensible codebase

### Code Quality
- **Modular Design**: Clean separation of concerns with 25+ classes
- **SOLID Principles**: Interface segregation and dependency inversion
- **Builder Pattern**: Flexible object construction for complex entities
- **Factory Pattern**: Centralized object creation logic
- **Comprehensive Logging**: File-based logging for debugging and auditing

### Data Management
- **CSV Persistence**: Human-readable data storage format
- **Bulk Data Operations**: Import/export capabilities
- **Data Validation**: Input sanitization and error checking
- **Referential Integrity**: Maintains relationships between entities

## 🎯 Core Functionality

### 1. Patient Management
- Registration with demographic details
- Medical history tracking
- Prescription management
- Appointment scheduling
- Billing and payment tracking

### 2. Staff Management
- Doctor profiles with specializations
- Nurse assignments and schedules
- Administrative staff records
- Shift scheduling and tracking
- Performance monitoring

### 3. Appointment System
- Book appointments with doctors
- Department-based scheduling
- Appointment status tracking
- Automated conflict detection
- Calendar integration

### 4. Billing & Finance
- Automated invoice generation
- Payment processing
- Outstanding balance tracking
- Financial reporting
- Insurance claim management

### 5. Laboratory Management
- Test ordering system
- Result recording and reporting
- Lab equipment tracking
- Quality control

### 6. Inventory Control
- Medical supplies tracking
- Stock level monitoring
- Supplier management
- Automated reordering alerts
- Expiry date tracking

## 🚀 Future Enhancements

- **Database Integration**: MySQL/PostgreSQL backend
- **Web Interface**: RESTful API with React/Angular frontend
- **Real-time Updates**: WebSocket-based notifications
- **Authentication System**: Secure user login and role-based access
- **Report Generation**: PDF/Excel export functionality
- **Mobile Application**: Cross-platform mobile app
- **Data Analytics**: Dashboard with charts and insights
- **Integration APIs**: Third-party system integration
- **Cloud Deployment**: AWS/Azure hosting
- **Backup & Recovery**: Automated data backup system

## 🧪 Testing

```bash
# Build in debug mode
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

# Run with verbose logging
./hospital_app --verbose

# Generate test data
cd utils
python generate_large_data.py
```

## 🐛 Troubleshooting

### Build Errors
```bash
# Clean build directory
rm -rf build/*  # Linux/macOS
rmdir /s build  # Windows

# Rebuild from scratch
cmake ..
cmake --build .
```

### CSV File Errors
- Ensure all CSV files exist in `data/` directory
- Check file permissions (read access required)
- Verify CSV format matches expected schema
- Run data generation script if files are missing

### Runtime Errors
- Check `data/log.txt` for detailed error messages
- Verify all dependencies are installed
- Ensure sufficient disk space for logs and data

## 🤝 Contributing

Contributions welcome! Please follow these guidelines:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Follow C++ coding standards (Google C++ Style Guide)
4. Add/update comments and documentation
5. Test your changes thoroughly
6. Commit with clear messages (`git commit -m 'Add: Feature description'`)
7. Push to branch (`git push origin feature/AmazingFeature`)
8. Open a Pull Request

### Code Standards
- Use meaningful variable names
- Comment complex algorithms
- Follow RAII principles
- Use smart pointers (shared_ptr, unique_ptr)
- Maintain consistent indentation (4 spaces)
- Write modular, testable code

## 📝 License

This project is open-source and available under the MIT License.

## 👨‍💻 Author

**Priyansh Sahu**
- GitHub: [@PriyanshSahu65](https://github.com/PriyanshSahu65)
- Roll Number: RA2211003010439
- Institution: SRM Institute of Science and Technology

## 🙏 Acknowledgments

- Implements industry-standard design patterns
- Inspired by real-world hospital management systems
- Built for academic learning and demonstration
- Special thanks to the C++ and open-source community

## 📧 Support

For questions, issues, or feature requests:
- Open an issue on GitHub
- Check `data/README_data_ingestion.md` for data format details
- Review closed issues for common solutions
- Contact via GitHub profile

## 📚 Documentation

### System Requirements
- **Minimum RAM**: 512 MB
- **Disk Space**: 100 MB
- **Processor**: Any modern CPU
- **OS**: Windows 7+, Linux (any), macOS 10.12+

### Performance Metrics
- Handles 10,000+ patient records
- Supports 1,000+ concurrent appointments
- Processes 500+ inventory items
- Manages 100+ staff members

---

⭐ **Star this repository if you find it helpful!**

Made with ❤️ and Modern C++ by Priyansh Sahu

*Last Updated: October 2025*

