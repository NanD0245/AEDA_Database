cmake_minimum_required(VERSION 3.17)
project(aeda2020_portagens)

set(CMAKE_CXX_STANDARD 14)

add_executable(aeda2020_portagens main.cpp Classes/Toll.cpp Classes/Toll.h Classes/Vehicle.cpp Classes/Vehicle.h Classes/EmployeeRecord.cpp Classes/EmployeeRecord.h Classes/Employee.cpp Classes/Employee.h Classes/SystemNetwork.cpp Classes/SystemNetwork.h Classes/Highway.cpp Classes/Highway.h Classes/HighwayRecord.cpp Classes/HighwayRecord.h Classes/Lane.cpp Classes/Lane.h Classes/Movement.cpp Classes/Movement.h Classes/MovementRecord.cpp Classes/MovementRecord.h Classes/VehicleRecord.cpp Classes/VehicleRecord.h Classes/Date.cpp Classes/Date.h Classes/Utils.cpp Classes/Utils.h Classes/Exceptions.h Classes/bst.h Classes/Technician.cpp Classes/Technician.h Classes/Intervention.cpp Classes/Intervention.h Classes/InterventionRecord.cpp Classes/InterventionRecord.h Classes/OwnerRecord.cpp Classes/OwnerRecord.h Classes/Owner.cpp Classes/Owner.h)

target_link_libraries(aeda2020_portagens PUBLIC sqlite3)