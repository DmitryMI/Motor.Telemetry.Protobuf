include("${_build_cmake_local}")

set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)

set(MOTOR_TELEMETRY_PROTO "${CMAKE_CURRENT_SOURCE_DIR}/PiSubmarine/Motor/Telemetry/Protobuf/Motor.proto")
protobuf_generate_cpp(MOTOR_TELEMETRY_PROTO_SRCS MOTOR_TELEMETRY_PROTO_HDRS "${MOTOR_TELEMETRY_PROTO}")

message("Adding library: ${PISUBMARINE_MODULE_NAME}")
add_library(${PISUBMARINE_MODULE_NAME}
        PiSubmarine/Motor/Telemetry/Protobuf/Deserializer.cpp
        PiSubmarine/Motor/Telemetry/Protobuf/ErrorCode.cpp
        PiSubmarine/Motor/Telemetry/Protobuf/Serializer.cpp
        "../public/PiSubmarine/Motor/Telemetry/Protobuf/Deserializer.h"
        "../public/PiSubmarine/Motor/Telemetry/Protobuf/ErrorCode.h"
        "../public/PiSubmarine/Motor/Telemetry/Protobuf/Serializer.h"
        ${MOTOR_TELEMETRY_PROTO_SRCS}
        ${MOTOR_TELEMETRY_PROTO_HDRS})
target_include_directories(${PISUBMARINE_MODULE_NAME} PUBLIC "../public" PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME})

PiSubmarineAddDependency("https://github.com/PiSubmarine/Motor.Telemetry.Api.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} PUBLIC PiSubmarine.Motor.Telemetry.Api)

PiSubmarineAddDependency("https://github.com/PiSubmarine/Telemetry.Api.git" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} PUBLIC PiSubmarine.Telemetry.Api)

target_link_libraries(${PISUBMARINE_MODULE_NAME} PRIVATE protobuf::libprotobuf)
