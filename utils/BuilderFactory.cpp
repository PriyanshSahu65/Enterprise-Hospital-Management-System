#include "BuilderFactory.h"
#include "DoctorBuilder.h"
#include "PatientBuilder.h"
#include "NurseBuilder.h"
#include <string>

Builder* BuilderFactory::createBuilder(const std::string& type) {
    if (type == "Doctor") return new DoctorBuilder();
    if (type == "Patient") return new PatientBuilder();
    if (type == "Nurse") return new NurseBuilder();
    return nullptr;
}
