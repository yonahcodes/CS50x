# CS50x Week 7 - HTML, CSS, JavaScript

## The internet

The **internet** is the global system of interconnected computer networks that uses the internet protocol suite `TCP/IP` to send packets of data between networks and devices. The **ARPANET** connected the first points on the internet to one another. Dots between two points could be considered **routers**.

<br>

## Routers

To route data from point A to point B, we need to make **routing decisions** and program how data is transferred. Data could take multiple paths from point A and point B, such that when a router is congested, data can flow through another path. 

`Packets` of data are transferred from one router to another, from one computer to another. Packets are structured as follows:
```
0                   1                   2                   3   
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|Version|  IHL  |Type of Service|          Total Length         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Identification        |Flags|      Fragment Offset    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  Time to Live |    Protocol   |         Header Checksum       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                           Source Address                      |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                        Destination Address                    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Options                    |    Padding    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

                Example Internet Datagram Header
```
- Packets are **standardized**. The source and destination are held within each packet.

<br>

`TCP/IP` is a pair of **protocols** that allow computers to transfer data between them over the internet.

<br>

`TCP`, or `transmission control protocol`, is used to distinguish web services from one another. For example, `80` is used to denote `HTTP` and `443` is used to denote `HTTPS`. These numbers are `port numbers`.

When information is sent from one location to another, a `source IP address`, a `destination IP address`, and `TCP port number` are sent.

These protocols are also used to **fragment** large files into multiple parts or `packets`. For example, a large photo of a cat can be sent in multiple packets. When a packet is **lost**, `TCP/IP` can **request missing packets** again from the **origin server**.

`TCP` will **acknowledge** when all the data has been **transmitted** and **received**.

<br>

`IP` or `internet protocol` is a way by which computers can be **identified** across the internet. Every computer has a unique address in the world. Addresses are in this form:
```
#.#.#.#
```
- Numbers range from `0` to `255`.

- **IP addresses** are `4 bytes` or `32-bits`, meaning that these addresses could accommodate over 4 billion addresses. 

- Newer versions of **IP addresses**, implementing `128-bits`, can accommodate far more computers!

<br>

## DNS



