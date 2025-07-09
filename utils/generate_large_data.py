import random
import csv
import os
from datetime import datetime, timedelta

# Settings
# Set your total patients here
total_patients = 200_000
# Derived counts based on ratios

total_doctors = max(1, total_patients // 20)
total_nurses = max(1, total_patients // 15)
total_admins = max(1, total_patients // 25)
total_departments = 5
total_medical_records = total_patients * 2
total_appointments = int(total_patients * 1.75)
total_items = 20
total_suppliers = 7
total_prescriptions = int(total_patients * 1.75)
total_billing = int(total_patients * 1.75)
total_inventory = 3
total_stocked_items = 60
total_labs = 3
total_tests = 150
shift_details = ['Morning', 'Evening', 'Night']
shift_schedules_per_doctor = 2
shift_schedules_per_nurse = 2

def random_date(start, end):
    return start + timedelta(days=random.randint(0, (end - start).days))

def generate_patients(filename, count):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['PatientID', 'PatientName', 'DOB', 'Gender', 'Phone', 'City', 'MedicalHistory'])
        for i in range(1, count+1):
            pid = f"P{i:07d}"
            name = f"Patient_{i}"
            dob = random_date(datetime(1950,1,1), datetime(2020,1,1)).strftime('%Y-%m-%d')
            gender = random.choice(['M', 'F'])
            phone = f"{random.randint(1000000000,9999999999)}"
            city = f"City_{random.randint(1,100)}"
            medhist = random.choice(['None', 'Diabetes', 'Hypertension', 'Asthma', 'Allergy', 'Heart Disease'])
            writer.writerow([pid, name, dob, gender, phone, city, medhist])

def generate_doctors(filename, count):
    specialties = ['Cardiology', 'Neurology', 'Pediatrics', 'Oncology', 'Orthopedics', 'General']
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['DoctorID', 'DoctorName', 'DOB', 'Gender', 'Phone', 'City', 'Specialization'])
        for i in range(1, count+1):
            did = f"D{i:05d}"
            name = f"Doctor_{i}"
            dob = random_date(datetime(1950,1,1), datetime(1995,1,1)).strftime('%Y-%m-%d')
            gender = random.choice(['M', 'F'])
            phone = f"{random.randint(1000000000,9999999999)}"
            city = f"City_{random.randint(1,100)}"
            specialty = random.choice(specialties)
            writer.writerow([did, name, dob, gender, phone, city, specialty])

def generate_nurses(filename, count):
    depts = ['ICU', 'ER', 'Pediatrics', 'Surgery', 'General']
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['NurseID', 'NurseName', 'DOB', 'Gender', 'Phone', 'City', 'Department'])
        for i in range(1, count+1):
            nid = f"N{i:06d}"
            name = f"Nurse_{i}"
            dob = random_date(datetime(1960,1,1), datetime(2000,1,1)).strftime('%Y-%m-%d')
            gender = random.choice(['M', 'F'])
            phone = f"{random.randint(1000000000,9999999999)}"
            city = f"City_{random.randint(1,100)}"
            dept = random.choice(depts)
            writer.writerow([nid, name, dob, gender, phone, city, dept])

def generate_admins(filename, count):
    roles = ['Receptionist', 'HR', 'Accountant', 'Manager', 'Clerk']
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['AdminID', 'AdminName', 'DOB', 'Gender', 'Phone', 'City', 'Designation'])
        for i in range(1, count+1):
            aid = f"A{i:05d}"
            name = f"Admin_{i}"
            dob = random_date(datetime(1955,1,1), datetime(2000,1,1)).strftime('%Y-%m-%d')
            gender = random.choice(['M', 'F'])
            phone = f"{random.randint(1000000000,9999999999)}"
            city = f"City_{random.randint(1,100)}"
            role = random.choice(roles)
            writer.writerow([aid, name, dob, gender, phone, city, role])

def generate_departments(filename, count, doctor_ids):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['DepartmentID', 'Name', 'Description'])
        for i in range(1, count+1):
            did = f"DEP{i:03d}"
            name = f"Department_{i}"
            desc = f"Description for {name}"
            writer.writerow([did, name, desc])

def generate_items(filename, count):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['ItemID', 'Name', 'Price'])
        for i in range(1, count+1):
            iid = f"ITM{i:04d}"
            name = f"Item_{i}"
            price = round(random.uniform(5, 500), 2)
            writer.writerow([iid, name, price])

def generate_suppliers(filename, count):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['SupplierID', 'Name', 'Mobile'])
        for i in range(1, count+1):
            sid = f"SUP{i:03d}"
            name = f"Supplier_{i}"
            mobile = f"{random.randint(1000000000,9999999999)}"
            writer.writerow([sid, name, mobile])

def generate_stockitems(filename, count, item_ids, supplier_ids):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['StockItemID', 'PurchaseDate', 'Quantity', 'ItemID', 'SupplierID'])
        for i in range(1, count+1):
            stid = f"STK{i:05d}"
            date = random_date(datetime(2022,1,1), datetime(2025,1,1)).strftime('%Y-%m-%d')
            qty = random.randint(1, 100)
            item = random.choice(item_ids)
            supplier = random.choice(supplier_ids)
            writer.writerow([stid, date, qty, item, supplier])

def generate_inventory(filename, count):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['InventoryID', 'Description'])
        for i in range(1, count+1):
            iid = f"INV{i:02d}"
            desc = f"Inventory_{i}"
            writer.writerow([iid, desc])

def generate_tests(filename, count):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['TestID', 'Name', 'Cost'])
        for i in range(1, count+1):
            tid = f"TST{i:04d}"
            name = f"Test_{i}"
            cost = round(random.uniform(10, 1000), 2)
            writer.writerow([tid, name, cost])

def generate_labs(filename, count, admin_ids):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['LabID', 'Name', 'AdminID'])
        for i in range(1, count+1):
            lid = f"LAB{i:03d}"
            name = f"Lab_{i}"
            admin = random.choice(admin_ids)
            writer.writerow([lid, name, admin])

def generate_shiftdetails(filename, count):
    days = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['ShiftID', 'Day', 'StartTime', 'EndTime'])
        for i in range(1, count+1):
            sid = f"SHF{i:05d}"
            day = random.choice(days)
            start = f"{random.randint(6,14):02d}:00"
            end = f"{random.randint(15,22):02d}:00"
            writer.writerow([sid, day, start, end])

def generate_shiftschedules(filename, count, person_ids, shift_ids):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['ScheduleID', 'PersonID', 'ShiftID'])
        for i in range(1, count+1):
            scid = f"SCH{i:06d}"
            person = random.choice(person_ids)
            shift = random.choice(shift_ids)
            writer.writerow([scid, person, shift])

def generate_medicalrecords(filename, count, patient_ids, doctor_ids, prescription_ids):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['RecordID', 'PatientID', 'DoctorID', 'AdmissionDate', 'Diagnosis', 'Treatment', 'PrescriptionID'])
        for i in range(1, count+1):
            rid = f"MR{i:07d}"
            pat = random.choice(patient_ids)
            doc = random.choice(doctor_ids)
            date = random_date(datetime(2015,1,1), datetime(2025,1,1)).strftime('%Y-%m-%d')
            diag = random.choice(['Flu', 'Infection', 'Fracture', 'Diabetes', 'Hypertension', 'Asthma'])
            treat = random.choice(['Medication', 'Surgery', 'Therapy', 'Observation'])
            presc = random.choice(prescription_ids)
            writer.writerow([rid, pat, doc, date, diag, treat, presc])

def generate_appointments(filename, count, patient_ids, doctor_ids):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['AppointmentID', 'PatientID', 'DoctorID', 'DateTime', 'Reason'])
        for i in range(1, count+1):
            aid = f"APPT{i:07d}"
            pat = random.choice(patient_ids)
            doc = random.choice(doctor_ids)
            dt = random_date(datetime(2022,1,1), datetime(2025,1,1)).strftime('%Y-%m-%d %H:%M')
            reason = random.choice(['Checkup', 'Consultation', 'Follow-up', 'Emergency'])
            writer.writerow([aid, pat, doc, dt, reason])

def generate_prescriptions(filename, count, item_ids):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['PrescriptionID', 'DateIssued', 'ItemIDs', 'DosageInstructions'])
        for i in range(1, count+1):
            pid = f"PRC{i:07d}"
            date = random_date(datetime(2015,1,1), datetime(2025,1,1)).strftime('%Y-%m-%d')
            items = ','.join(random.sample(item_ids, k=random.randint(1,3)))
            dosage = random.choice(['1x/day', '2x/day', 'After meal', 'Before bed'])
            writer.writerow([pid, date, items, dosage])

def generate_billing(filename, count, patient_ids):
    with open(filename, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['BillID', 'PatientID', 'Services', 'Cost'])
        for i in range(1, count+1):
            bid = f"BILL{i:07d}"
            pat = random.choice(patient_ids)
            services = ','.join(random.sample(['Consultation','Lab','Surgery','Medication','Room'], k=random.randint(1,3)))
            cost = round(random.uniform(100, 5000), 2)
            writer.writerow([bid, pat, services, cost])

def ensure_file_generated(filename, generator_func, *args):
    if not os.path.exists(filename):
        print(f"Generating {filename} ...")
        generator_func(filename, *args)
    else:
        print(f"{filename} already exists. Skipping generation.")

if __name__ == "__main__":
    # Ensure data directory exists
    os.makedirs('data', exist_ok=True)
    # Patients
    ensure_file_generated('data/patients_large.csv', generate_patients, total_patients)
    # Doctors
    ensure_file_generated('data/doctors_large.csv', generate_doctors, total_doctors)
    # Nurses
    ensure_file_generated('data/nurses_large.csv', generate_nurses, total_nurses)
    # Admins
    ensure_file_generated('data/admins_large.csv', generate_admins, total_admins)
    # Items
    ensure_file_generated('data/items_large.csv', generate_items, total_items)
    # Suppliers
    ensure_file_generated('data/suppliers_large.csv', generate_suppliers, total_suppliers)
    item_ids = [f"ITM{i:04d}" for i in range(1, total_items+1)]
    supplier_ids = [f"SUP{i:03d}" for i in range(1, total_suppliers+1)]
    # StockItems
    ensure_file_generated('data/stockitems_large.csv', generate_stockitems, total_stocked_items, item_ids, supplier_ids)
    # Inventory
    ensure_file_generated('data/inventory_large.csv', generate_inventory, total_inventory)
    # Departments
    ensure_file_generated('data/departments_large.csv', generate_departments, total_departments, [])
    # Tests
    ensure_file_generated('data/tests_large.csv', generate_tests, total_tests)
    # Labs
    admin_ids = [f"A{i:05d}" for i in range(1, total_admins+1)]
    ensure_file_generated('data/labs_large.csv', generate_labs, total_labs, admin_ids)
    # ShiftDetails
    ensure_file_generated('data/shiftdetails_large.csv', generate_shiftdetails, 21)
    shift_ids = [f"SHF{i:05d}" for i in range(1, 22)]
    doctor_ids = [f"D{i:05d}" for i in range(1, total_doctors+1)]
    nurse_ids = [f"N{i:06d}" for i in range(1, total_nurses+1)]
    patient_ids = [f"P{i:07d}" for i in range(1, total_patients+1)]
    # ShiftSchedules for doctors and nurses
    ensure_file_generated('data/shiftschedules_doctors_large.csv', generate_shiftschedules, total_doctors*shift_schedules_per_doctor, doctor_ids, shift_ids)
    ensure_file_generated('data/shiftschedules_nurses_large.csv', generate_shiftschedules, total_nurses*shift_schedules_per_nurse, nurse_ids, shift_ids)
    # Prescriptions
    ensure_file_generated('data/prescriptions_large.csv', generate_prescriptions, total_prescriptions, item_ids)
    prescription_ids = [f"PRC{i:07d}" for i in range(1, total_prescriptions+1)]
    # MedicalRecords
    ensure_file_generated('data/medicalrecords_large.csv', generate_medicalrecords, total_medical_records, patient_ids, doctor_ids, prescription_ids)
    # Appointments
    ensure_file_generated('data/appointments_large.csv', generate_appointments, total_appointments, patient_ids, doctor_ids)
    # Billing
    ensure_file_generated('data/billing_large.csv', generate_billing, total_billing, patient_ids)
    print(f"Large sample data files generated for all entities (only if missing).")

