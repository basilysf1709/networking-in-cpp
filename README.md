# Sockets

#### Different types of connections:

- `SOCK_STREAM`: It indicates that this socket will be used for a stream-oriented connection, which is typically TCP/IP communication. This means that data is sent in a continuous stream and is guaranteed to be delivered in order.
- `SOCK_DGRAM`: This type is for datagram-based communication, which is typically UDP/IP. It means that data is sent in discrete packets (datagrams) and is not guaranteed to be delivered in order.
- `SOCK_RAW`: This type provides raw access to network protocols below the transport layer. It allows you to create packets manually.
- `SOCK_SEQPACKET`: This is a sequenced-packet socket, which is a reliable, connection-oriented socket similar to SOCK_STREAM, but it preserves message boundaries.

#### Differences with TCP/IP and UDP/IP:
TCP/IP and UDP/IP are two different transport layer protocols used for transmitting data over a network. Here are the key differences between them:

1. **Connection-oriented vs Connectionless:**

   - **TCP/IP (Transmission Control Protocol/Internet Protocol):**
     - **Connection-Oriented:** TCP establishes a connection between the sender and receiver before sending data. It ensures reliable delivery of data by managing acknowledgments, retransmissions, and flow control.

   - **UDP/IP (User Datagram Protocol/Internet Protocol):**
     - **Connectionless:** UDP does not establish a connection before sending data. It simply sends packets to the recipient. There is no guarantee of delivery, and packets may arrive out of order or be lost.

2. **Reliability:**

   - **TCP/IP:**
     - **Reliable:** TCP ensures that data is reliably delivered to the receiver. It handles retransmissions in case of lost packets, ensures in-order delivery, and manages flow control to prevent overwhelming the receiver.

   - **UDP/IP:**
     - **Unreliable:** UDP does not guarantee delivery. It does not manage retransmissions or acknowledgments. It is up to the application layer to handle any required reliability.

3. **Packet Header Size:**

   - **TCP/IP:**
     - The TCP header is larger, including various control information for managing the reliable delivery of data.

   - **UDP/IP:**
     - The UDP header is smaller, containing only basic information such as source and destination ports.

4. **Overhead:**

   - **TCP/IP:**
     - More overhead due to the additional control information in the header.

   - **UDP/IP:**
     - Less overhead, making it faster and more efficient for simple, low-latency communications.

5. **Order of Delivery:**

   - **TCP/IP:**
     - Ensures that data is delivered in the same order it was sent.

   - **UDP/IP:**
     - Packets may arrive out of order, and it's up to the application to reassemble them if needed.

6. **Use Cases:**

   - **TCP/IP:**
     - Used for applications where data integrity and reliability are crucial, such as web browsing, email, file transfers, and online gaming.

   - **UDP/IP:**
     - Used for real-time applications where low latency is more important than guaranteed delivery, such as video streaming, VoIP, online gaming (especially fast-paced games), and IoT applications.

7. **Examples:**

   - **TCP/IP:**
     - HTTP, FTP, SMTP, Telnet.

   - **UDP/IP:**
     - DNS, SNMP, VoIP (e.g., Skype), online multiplayer games.

In summary, TCP/IP provides a reliable and ordered delivery of data, making it suitable for applications where accuracy and completeness are critical. UDP/IP, on the other hand, is faster and more efficient, making it ideal for real-time applications that prioritize speed over guaranteed delivery. Each protocol has its own strengths and is chosen based on the requirements of the specific application.