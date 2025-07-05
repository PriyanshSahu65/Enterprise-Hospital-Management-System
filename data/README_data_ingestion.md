# HMS Data Ingestion Documentation

## File Formats

### Patients CSV (patients_large.csv)
- Columns: PatientID, PatientName, DOB, Gender, Address, Phone
- Example:
  P0000001,John Doe,1980-01-01,M,123 Main St,1234567890

### Doctors CSV (doctors_large.csv)
- Columns: DoctorID, DoctorName, Specialty, Phone
- Example:
  D00001,Jane Smith,Cardiology,9876543210

## How to Generate Large Data Files

1. Ensure you have Python 3 installed.
2. Run the script:
   ```
   python utils/generate_large_data.py
   ```
   This will create `data/patients_large.csv` and `data/doctors_large.csv`.

## How to Ingest Large Data in the HMS Application

1. In `main.cpp`, update the builder usage to load from the large files:
   - For patients: use `PatientBuilder("data/patients_large.csv")`.
   - For doctors: use `DoctorBuilder("data/doctors_large.csv")`.
2. Example code snippet:
   ```cpp
   PatientBuilder patientBuilder("data/patients_large.csv");
   auto patients = patientBuilder.makeDataObjectList();
   std::cout << "Loaded " << patients->size() << " patients." << std::endl;
   delete patients;
   ```
3. Repeat similarly for doctors.

## Notes
- The ingestion code is designed to handle large files efficiently using streaming.
- You can time the ingestion process using `std::chrono` for benchmarking.
