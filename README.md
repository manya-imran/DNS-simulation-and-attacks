# DNS-simulation-and-attacks
This network and security depicts a DNS simulation and its possible attacks.

The projects has:
1. A client browser
2. The following DNS servers:
  a. One local resolver
  b. Five root servers
  c. Two TLD servers
  d. One authoritative server for a domain www.example.com
3. An attacker machine
4. The attacker’s authoritative server for his own domain, www.attacker.com

All communication between entities is via
(simulated) DNS query and response packets.

When the program is run, it displays a menu that gives the user the following options:
1. Demonstrate DNS resolution for a cached name
2. Demonstrate DNS resolution for an uncached name
3. Demonstrate DNS resolution for a domain name that does not exist at all
4. Demonstrate a successful cache poisoning attack on the local resolver WITHOUT using
the Kaminsky bug
5. Demonstrate an unsuccessful cache poisoning attack on the local resolver WITHOUT
using the Kaminsky bug
6. Demonstrate a successful cache poisoning attack on the local resolver using the
Kaminsky bug
7. Demonstrate an unsuccessful cache poisoning attack on the local resolver using the
Kaminsky bug.
