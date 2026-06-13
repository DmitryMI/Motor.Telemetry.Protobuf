#include <gtest/gtest.h>

#include "PiSubmarine/Motor/Telemetry/Protobuf/ErrorCode.h"

namespace PiSubmarine::Motor::Telemetry::Protobuf
{
    TEST(ErrorCodeTest, ConvertsToErrorCode)
    {
        const auto errorCode = make_error_code(ErrorCode::SerializationFailed);

        EXPECT_EQ(errorCode.value(), static_cast<int>(ErrorCode::SerializationFailed));
        EXPECT_STREQ(errorCode.category().name(), "PiSubmarine.Motor.Telemetry.Protobuf");
    }
}
