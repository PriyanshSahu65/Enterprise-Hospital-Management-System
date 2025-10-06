# MediCare Plus: Comprehensive Hospital Management System

```
    ╱|、
  (˚ˎ 。7
   |、˜〵
   じしˍ,)ノ
```

A robust console-based Hospital Management System engineered in C++ to automate and streamline critical healthcare operations including patient management, appointment scheduling, billing, and medical records administration.

## 🏥 Features

### Core Functionality
- **Patient Management**: Complete patient registration, admission, and discharge workflows
- **Appointment Scheduling**: Automated booking system with doctor availability tracking
- **Doctor Administration**: Comprehensive doctor profiles, specializations, and schedules
- **Billing System**: Integrated invoicing and payment processing
- **Medical Records**: Secure storage and retrieval of patient health records
- **Department Management**: Multi-department support with queue management
- **Staff Management**: Employee records and role-based access control
- **Bed Allocation**: Real-time bed availability and assignment system

### Advanced Features
- Priority-based patient queuing (critical vs. regular patients)
- Search functionality for patients and staff
- Report generation for administrative insights
- Secure authentication system for administrators
- Database persistence using MySQL

## 🛠️ Tech Stack

- **Language**: C++
- **Database**: MySQL
- **IDE**: Code::Blocks / Dev C++
- **Server**: XAMPP (for MySQL)
- **Type**: Console Application

## 📋 Prerequisites

Before running this project, ensure you have:

- C++ Compiler (GCC/MinGW)
- Code::Blocks IDE (recommended v16.01 or higher)
- XAMPP (for MySQL database)
- MySQL Connector for C++

## ⚙️ Setup Instructions

### Step 1: Clone the Repository
```bash
git clone https://github.com/PriyanshSahu65/2.Hospital_managment
cd 2.Hospital_managment
```

### Step 2: Database Setup
1. Start XAMPP and enable MySQL service
2. Open phpMyAdmin (http://localhost/phpmyadmin)
3. Create a new database named `hospital_db`
4. Import the provided SQL schema file

### Step 3: Configure Database Connection
Update the database credentials in the configuration file:
```cpp
// config.h
#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS ""
#define DB_NAME "hospital_db"
```

### Step 4: Compile and Run
```bash
# Using Code::Blocks
- Open the .cbp project file
- Build & Run (F9)

# Using g++ directly
g++ main.cpp -o hospital_system -lmysql
./hospital_system
```

## 👥 Default Login Credentials

**Administrator:**
- Username: `admin`
- Password: `admin123`

## 📊 System Modules

### 1. Patient Module
- Register new patients
- Update patient information
- Search patient records
- Admission and discharge management

### 2. Doctor Module
- Add/remove doctor profiles
- Manage specializations
- Schedule management
- Patient assignment

### 3. Appointment Module
- Book appointments
- View scheduled appointments
- Cancel/reschedule appointments
- Automated reminders

### 4. Billing Module
- Generate invoices
- Process payments
- Track outstanding bills
- Generate financial reports

### 5. Administrative Module
- User authentication
- Staff management
- System configuration
- Report generation

## 🎯 Use Cases

- **Hospitals & Clinics**: Streamline daily operations and patient care
- **Medical Centers**: Efficient appointment and billing management
- **Healthcare Administrators**: Comprehensive oversight and reporting
- **Academic Projects**: Learning C++ with real-world applications

## 📁 Project Structure

```
2.Hospital_managment/
├── src/
│   ├── main.cpp
│   ├── patient.h
│   ├── doctor.h
│   ├── appointment.h
│   └── billing.h
├── include/
│   └── database.h
├── data/
│   ├── patients.dat
│   ├── doctors.dat
│   └── schema.sql
├── docs/
│   └── documentation.pdf
└── README.md
```

## 🚀 Future Enhancements

- Web-based interface using C++ backend
- Integration with electronic health records (EHR)
- Multi-language support
- SMS/Email notification system
- Analytics dashboard
- Mobile application integration
- Prescription management system
- Laboratory test tracking

## 💡 Key Highlights

- **Optimized Performance**: Handles 1000+ patient records efficiently
- **Data Security**: Encrypted storage and secure authentication
- **Scalable Design**: Modular architecture for easy feature additions
- **User-Friendly**: Intuitive console interface with clear menu navigation
- **Reliable**: Robust error handling and data validation

## 🤝 Contributing

Contributions are welcome! Please follow these steps:
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit changes (`git commit -m 'Add AmazingFeature'`)
4. Push to branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is open-source and available under the MIT License.

## 👨‍💻 Author

**Priyansh Sahu**
- GitHub: [@PriyanshSahu65](https://github.com/PriyanshSahu65)
- Roll Number: RA2211003010439

## 🙏 Acknowledgments

- Inspired by real-world healthcare management systems
- Built as an academic project to demonstrate C++ programming concepts
- Special thanks to the open-source community

## 📧 Contact

For queries or support, please open an issue on GitHub.

## 🐛 Known Issues

- Database connection may fail if XAMPP is not running
- File paths must be absolute on some systems
- Limited concurrent user support in current version

## 📚 Documentation

For detailed documentation, please refer to the `docs/` folder or visit the [Wiki](https://github.com/PriyanshSahu65/2.Hospital_managment/wiki).

## 🔧 Troubleshooting

### Database Connection Error
```
Solution: Ensure XAMPP is running and MySQL service is active
```

### Compilation Error
```
Solution: Install MySQL Connector for C++ and update include paths
```

### File Not Found Error
```
Solution: Check that all data files exist in the data/ directory
```

---
⭐ **Star this repository if you find it helpful!**

Made with ❤️ by Priyansh Sahu
