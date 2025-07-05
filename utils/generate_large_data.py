import random
import csv
import os
from datetime import datetime, timedelta

# Settings
total_patients = 200_000
total_doctors = 500
total_nurses = 1000
total_admins = 200

def random_date(start, end):
    return start + timedelta(days=random.randint(0, (end - start).days))

def generate_patients(filename, count):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['PatientID', 'PatientName', 'DOB', 'Gender', 'Address', 'Phone', 'MedicalHistory'])
        for i in range(1, count+1):
            pid = f"P{i:07d}"
            name = f"Patient_{i}"
            dob = random_date(datetime(1950,1,1), datetime(2020,1,1)).strftime('%Y-%m-%d')
            gender = random.choice(['M', 'F'])
            address = f"{random.randint(100,999)} Main St, City_{random.randint(1,100)}"
            phone = f"{random.randint(1000000000,9999999999)}"
            medhist = random.choice(['None', 'Diabetes', 'Hypertension', 'Asthma', 'Allergy', 'Heart Disease'])
            writer.writerow([pid, name, dob, gender, address, phone, medhist])

def generate_doctors(filename, count):
    specialties = ['Cardiology', 'Neurology', 'Pediatrics', 'Oncology', 'Orthopedics', 'General']
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['DoctorID', 'DoctorName', 'Specialty', 'Phone', 'Address', 'DOB'])
        for i in range(1, count+1):
            did = f"D{i:05d}"
            name = f"Doctor_{i}"
            specialty = random.choice(specialties)
            phone = f"{random.randint(1000000000,9999999999)}"
            address = f"{random.randint(100,999)} Clinic Rd, City_{random.randint(1,100)}"
            dob = random_date(datetime(1950,1,1), datetime(1995,1,1)).strftime('%Y-%m-%d')
            writer.writerow([did, name, specialty, phone, address, dob])

def generate_nurses(filename, count):
    depts = ['ICU', 'ER', 'Pediatrics', 'Surgery', 'General']
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['NurseID', 'NurseName', 'Department', 'Phone', 'Address', 'DOB'])
        for i in range(1, count+1):
            nid = f"N{i:06d}"
            name = f"Nurse_{i}"
            dept = random.choice(depts)
            phone = f"{random.randint(1000000000,9999999999)}"
            address = f"{random.randint(100,999)} Nurse St, City_{random.randint(1,100)}"
            dob = random_date(datetime(1960,1,1), datetime(2000,1,1)).strftime('%Y-%m-%d')
            writer.writerow([nid, name, dept, phone, address, dob])

def generate_admins(filename, count):
    roles = ['Receptionist', 'HR', 'Accountant', 'Manager', 'Clerk']
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['AdminID', 'AdminName', 'Role', 'Phone', 'Address', 'DOB'])
        for i in range(1, count+1):
            aid = f"A{i:05d}"
            name = f"Admin_{i}"
            role = random.choice(roles)
            phone = f"{random.randint(1000000000,9999999999)}"
            address = f"{random.randint(100,999)} Admin Ave, City_{random.randint(1,100)}"
            dob = random_date(datetime(1955,1,1), datetime(2000,1,1)).strftime('%Y-%m-%d')
            writer.writerow([aid, name, role, phone, address, dob])

if __name__ == "__main__":
    # Ensure data directory exists
    os.makedirs('data', exist_ok=True)
    generate_patients('data/patients_large.csv', total_patients)
    generate_doctors('data/doctors_large.csv', total_doctors)
    generate_nurses('data/nurses_large.csv', total_nurses)
    generate_admins('data/admins_large.csv', total_admins)
    print("Large sample data files for patients, doctors, nurses, and admins generated.")
