# Motor.Telemetry.Protobuf

`PiSubmarine.Motor.Telemetry.Protobuf` adapts `Motor.Telemetry.Api` to and from
raw protobuf payloads.

- `Serializer` implements `Telemetry.Api::IRawSource` by querying a local
  `Motor::Telemetry::Api::IProvider`
- `Deserializer` implements `Motor::Telemetry::Api::IProvider` by reading bytes
  from a `Telemetry.Api::IRawSource`
