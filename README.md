# Socket Programming in C

A beginner-friendly implementation of **Socket Programming in C** using the **TCP** and **UDP** transport layer protocols on Linux.

This repository demonstrates how client-server communication works using sockets and includes complete source code for both TCP and UDP programming.

---

# Table of Contents

- Introduction
- What is a Socket?
- Types of Socket Programming
- Repository Structure
- TCP Socket Programming
  - Workflow
  - Server Flow
  - Client Flow
- UDP Socket Programming
  - Workflow
  - Server Flow
  - Client Flow
- How to Compile
- How to Run
- Expected Output
- Key Socket Functions
- TCP vs UDP
- References

---

# What is a Socket?

A **socket** is a **software endpoint of communication** between two processes over a network.

It enables two devices (or two applications) to exchange data using an IP address and a port number.

A socket is uniquely identified by:

- **IP Address** – Identifies the device on the network.
- **Port Number** – Identifies the specific application running on that device.

**Socket = IP Address + Port Number**

Example:

```
IP Address : 192.168.1.10
Port Number: 8080

Socket = 192.168.1.10 : 8080
```

---

# Repository Structure

```
Socket_Programming
│
├── TCP Programming
│   ├── server.c
│   └── client.c
│
├── UDP Programming
│   ├── udp_server.c
│   └── udp_client.c
│
└── README.md
```

---

# TCP Socket Programming

## What is TCP?

**TCP (Transmission Control Protocol)** is a **connection-oriented** transport layer protocol.

Before transferring data, a connection is established between the client and the server.

TCP guarantees:

- Reliable communication
- Ordered delivery
- Error checking
- Retransmission of lost packets

Hence it is used wherever data reliability is important.

Examples:

- Web Browsing (HTTP/HTTPS)
- Email
- Banking Applications
- File Transfer

---

# TCP Server Workflow

```
socket()
      │
      ▼
bind()
      │
      ▼
listen()
      │
      ▼
accept()
      │
      ▼
recv()
      │
      ▼
send()
      │
      ▼
close()
```

---

# TCP Client Workflow

```
socket()
      │
      ▼
connect()
      │
      ▼
send()
      │
      ▼
recv()
      │
      ▼
close()
```

---

# TCP Communication Flow

```
                 SERVER

socket()
    │
bind()
    │
listen()
    │
accept()
    │
recv()  <------------------- send()
    │
send()  -------------------> recv()
    │
close()

                 CLIENT

socket()
    │
connect()
    │
send()
    │
recv()
    │
close()
```

---

# UDP Socket Programming

## What is UDP?

**UDP (User Datagram Protocol)** is a **connectionless** transport layer protocol.

Unlike TCP, UDP does **not establish a connection** before sending data.

Data is transmitted as independent packets called **datagrams**.

UDP is faster because it does not perform:

- Connection establishment
- Acknowledgements
- Retransmissions
- Packet ordering

Examples:

- Online Gaming
- Live Video Streaming
- VoIP Calls
- DNS

---

# UDP Server Workflow

```
socket()
      │
      ▼
bind()
      │
      ▼
recvfrom()
      │
      ▼
sendto()
      │
      ▼
close()
```

---

# UDP Client Workflow

```
socket()
      │
      ▼
sendto()
      │
      ▼
recvfrom()
      │
      ▼
close()
```

---

# UDP Communication Flow

```
                 SERVER

socket()
    │
bind()
    │
recvfrom() <-------------- sendto()
    │
sendto() ----------------> recvfrom()
    │
close()

                 CLIENT

socket()
    │
sendto()
    │
recvfrom()
    │
close()
```

---

# ⚙️ How to Compile

## TCP Server

```bash
gcc server.c -o server
```

## TCP Client

```bash
gcc client.c -o client
```

## UDP Server

```bash
gcc udp_server.c -o udp_server
```

## UDP Client

```bash
gcc udp_client.c -o udp_client
```

---

# How to Run

Open **two terminals**.

### Terminal 1

```bash
./server
```

or

```bash
./udp_server
```

---

### Terminal 2

```bash
./client
```

or

```bash
./udp_client
```

---

# 💻 Expected Output

### TCP Server

```
Waiting for client...
Client Connected!
Client Says: Hello Server
```

---

### TCP Client

```
Server Says: Hello Client
```

---

### UDP Server

```
UDP Server is waiting for messages...
Client Says: Hello Server
```

---

### UDP Client

```
Server Says: Hello Client
```

---

# 🔧 Common Socket Functions

| Function | Description |
|----------|-------------|
| socket() | Creates a socket |
| bind() | Assigns an IP address and port number |
| listen() | Waits for incoming connections |
| accept() | Accepts a client connection |
| connect() | Connects to the server |
| send() | Sends data using TCP |
| recv() | Receives data using TCP |
| sendto() | Sends data using UDP |
| recvfrom() | Receives data using UDP |
| close() | Closes the socket |

---

# TCP vs UDP

| TCP | UDP |
|------|------|
| Connection-Oriented | Connectionless |
| Reliable | Unreliable |
| Ordered Delivery | No Order Guarantee |
| Error Recovery | No Error Recovery |
| Slower | Faster |
| Uses ACK | No ACK |
| Uses connect() | Uses sendto() |
| File Transfer | Live Streaming |
| Email | Online Gaming |
| Banking | VoIP |

---

# Technologies Used

- C Programming
- Linux (Ubuntu)
- GCC Compiler
- Berkeley Socket API
- TCP/IP Networking

---

# References

- Beej's Guide to Network Programming
- Linux Manual Pages
- TCP/IP Protocol Suite Documentation

---

# Author

**Akshay Kumar P**

 Electronics and Communication Engineering (ECE)

Rajalakshmi Engineering College

---

 If you found this repository helpful, consider giving it a **Star** on GitHub!
