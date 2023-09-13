# Networking in C++

## Different types of connections:

- `SOCK_STREAM`: It indicates that this socket will be used for a stream-oriented connection, which is typically TCP/IP communication. This means that data is sent in a continuous stream and is guaranteed to be delivered in order.
- `SOCK_DGRAM`: This type is for datagram-based communication, which is typically UDP/IP. It means that data is sent in discrete packets (datagrams) and is not guaranteed to be delivered in order.
- `SOCK_RAW`: This type provides raw access to network protocols below the transport layer. It allows you to create packets manually.
- `SOCK_SEQPACKET`: This is a sequenced-packet socket, which is a reliable, connection-oriented socket similar to SOCK_STREAM, but it preserves message boundaries.

## Differences with TCP/IP and UDP/IP:
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


## IPv4 vs IPv6

IPv4 and IPv6 are two different versions of the Internet Protocol, which is the set of rules that govern how data is sent and received over the internet. Here are the key differences between IPv4 and IPv6:

### IPv4:

1. **Address Length:**
   - IPv4 addresses are 32-bit long, expressed as four decimal numbers (0-255) separated by periods (e.g., 192.168.1.1).
  
2. **Address Space:**
   - IPv4 provides approximately 4.3 billion unique addresses.
  
3. **Address Notation:**
   - Expressed in dotted-decimal format (e.g., 192.168.1.1).
   
4. **Address Configuration:**
   - Manual configuration or through DHCP (Dynamic Host Configuration Protocol).
   
5. **Address Depletion:**
   - IPv4 addresses have largely been exhausted due to the rapid growth of the internet and the increasing number of connected devices.

### IPv6:

1. **Address Length:**
   - IPv6 addresses are 128-bit long, expressed as eight groups of four hexadecimal digits separated by colons (e.g., 2001:0db8:85a3:0000:0000:8a2e:0370:7334).

2. **Address Space:**
   - IPv6 provides an astronomically large number of unique addresses, approximately 340 undecillion (3.4x10^38).

3. **Address Notation:**
   - Expressed in hexadecimal format separated by colons (e.g., 2001:0db8:85a3:0000:0000:8a2e:0370:7334).

4. **Address Configuration:**
   - IPv6 supports both stateless address autoconfiguration and DHCPv6, but stateless autoconfiguration is the preferred method.

5. **Address Depletion:**
   - IPv6 was developed to address the issue of IPv4 address exhaustion. Its vast address space ensures that there will be sufficient addresses for the foreseeable future.

6. **Additional Features:**
   - IPv6 includes features such as improved multicast support, simpler header structure, and built-in security features.

### Transition Mechanisms:

1. **Dual-Stack:**
   - In a dual-stack environment, both IPv4 and IPv6 are used concurrently. This allows devices to communicate using either protocol.

2. **Tunneling:**
   - Tunneling involves encapsulating IPv6 packets within IPv4 packets to allow them to traverse IPv4-only networks.

3. **Translation:**
   - IPv6-to-IPv4 and IPv4-to-IPv6 translation mechanisms allow devices using one version of the protocol to communicate with devices using the other.

### Adoption:

1. **Current Adoption:**
   - IPv4 is still widely used, and the transition to IPv6 is ongoing. Many networks operate with both IPv4 and IPv6 support.

2. **Future Expectations:**
   - As the number of connected devices continues to grow and IPv4 addresses become scarcer, IPv6 adoption is expected to become more widespread.

In summary, IPv6 was developed to address the limitations of IPv4, primarily the scarcity of addresses. IPv6 provides a much larger address space and includes several additional features. While IPv4 is still widely used, the transition to IPv6 is gradually taking place to ensure the continued growth of the internet.