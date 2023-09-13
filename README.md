# Sockets


#### Different types of connections:

- `SOCK_STREAM`: It indicates that this socket will be used for a stream-oriented connection, which is typically TCP/IP communication. This means that data is sent in a continuous stream and is guaranteed to be delivered in order.
- `SOCK_DGRAM`: This type is for datagram-based communication, which is typically UDP/IP. It means that data is sent in discrete packets (datagrams) and is not guaranteed to be delivered in order.
- `SOCK_RAW`: This type provides raw access to network protocols below the transport layer. It allows you to create packets manually.
- `SOCK_SEQPACKET`: This is a sequenced-packet socket, which is a reliable, connection-oriented socket similar to SOCK_STREAM, but it preserves message boundaries.