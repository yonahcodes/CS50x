# CS50x Week 7 - HTML, CSS, JavaScript

## The internet

The **internet** is the global system of interconnected computer networks that uses the internet protocol suite `TCP/IP` to send packets of data between networks and devices. The **ARPANET** connected the first points on the internet to one another. Dots between two points could be considered **routers**.

<br>

## Routers

To **route** data from point `A` to point `B`, we need to make **routing decisions** and program how data is transferred. `Data` could take multiple **paths** from point A and point B, such that when a router is **congested**, data can flow through another path. 

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
- `Packets` are **standardized**. The source and destination are held within each packet.

<br>

`TCP/IP` is a pair of **protocols** that allow computers to **transfer** data between points over the internet.

<br>

`TCP`, or `transmission control protocol`, is used to distinguish web services from one another. For example, `80` is used to denote `HTTP` and `443` is used to denote `HTTPS`. These numbers are `port numbers`.

When information is sent from one location to another, a `source IP address`, a `destination IP address`, and `TCP port number` are sent.

These protocols are also used to **fragment** large files into multiple parts or `packets`. For example, a large photo of a cat can be sent in multiple packets. When a packet is **lost**, `TCP/IP` can **request missing packets** again from the **origin server**.

`TCP` will also **acknowledge** when all the data has been **transmitted** and **received**.

<br>

`IP` or `Internet Protocol` is a way by which computers can be **identified** across the internet. Every computer has a unique address in the world. Addresses are in this form:
```
#.#.#.#
```
- Numbers range from `0` to `255`.

- `IP addresses` are `4 bytes` or `32-bits`, meaning that these addresses could accommodate over 4 billion addresses. 

- Newer versions of **IP addresses**, implementing `128-bits`, can accommodate far more devices.

<br>

## DNS

`DNS` or `Domain Name System` is a collection of **servers** that provide a **naming system** for computers, services, and other resources on the Internet or other Internet Protocol (IP) networks. 

`DNS` simply hold a table or database that **links** specific, fully qualified **domain names** such as **harvard.edu** to specific **IP addresses** so that we don't have to remember an IP address to visit a website.

<br>

## HTTP

`HTTP` or `hypertext transfer protocol` is an application-level **protocol** that developers use to **transfer data**, such as HTML documents, images, videos, and other types of content, between clients (usually web browsers) and servers.

<br>

When you see an address such as `https://www.example.com` you are actually implicitly visiting that address with a `/` at the end of it.

- The `path` is what exists after that slash `/`. For example, `https://www.example.com/folder/file.html` visits `example.com` and browses to the `folder` named folder and then visits the file named `file.html`.

- The `.com` is called a `top-level domain` that is used to denote the **location** or **type of organization** associated with this address.

- `https` in this address is the **protocol** that is used to **connect** to that web address.

<br>

HTTP utilizes `GET` or `POST` **requests** to ask for information from a **server**. For example, you can launch Google Chrome, right-click, and click `inspect`. When you open the developer tools and visit `Network`, selecting `Preserve log`, you will see `Request Headers`. You’ll see mentions of `GET`.

<br>

For example, when issuing a `GET request`, your computer may send the following to a server:
```
GET / HTTP/2
Host: www.harvard.edu
```
- Notice that this **requests** via `HTTP` the content served on www.harvard.edu

<br>

Generally, after making a request a server, you will receive the following in `Response Headers`:
```
HTTP/2 200
Content-Type: text/html
```
<br>

This approach to **inspecting** these logs may be a bit more complicated than need be. You can analyze the work of `HTTP protocols` at **cs50.dev**. For example, type the following in your **terminal** window:
```
curl -I https://www.harvard.edu/
```
- Notice that the output of this command returns **all the header values** of the **responses** of the server.

<br>

> Via `developer tools` in your **web browser**, you can see all the `HTTP requests` when browsing to the above website.

<br>

Further, execute the following command in your terminal window:
```
curl -I https://harvard.edu/
```
- Notice that you will see a `301` response, providing a hint to a browser of **where it can find the correct website**.

<br>

Similarly, execute the following in your terminal window:
```
curl -I http://www.harvard.edu/
```
- Notice that the `s` in `https` has been removed. The server response will show that the response is `301`, meaning that the website has **permanently moved**.

<br>

Similar to `301`, a code of `404` means that a specified `URL` has **not been found**. There are numerous other response codes, such as:
```
200 OK
301 Moved Permanently
302 Found
304 Not Modified
304 Temporary Redirect
401 Unauthorized
403 Forbidden
404 Not Found
418 I'm a Teapot
500 Internal Server Error
503 Service Unavailable
```
- It’s worth mentioning that `500` errors are always your fault as the developer.

<br>

## HTML

