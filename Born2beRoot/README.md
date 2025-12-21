*This project has been created as part of the 42 curriculum by mbahri.*

# Born2beroot (Debian + LVM on VirtualBox)

## Description
**Born2beroot** is a system administration and virtualization project where you set up a secure Linux server inside a virtual machine. The goal is to learn how to install, configure, and harden an operating system by applying best practices for storage/partitioning, user and permission management, services, networking, and security policies.

In this project, I installed **Debian** on **VirtualBox**, used **LVM** with multiple logical volumes to separate critical directories, configured secure remote access with **SSH on port 4242**, and enabled a firewall to minimize the machine’s exposed surface.

---

## OS choice: Debian (pros/cons) + why I chose it
I chose **Debian** because it provides a stable and lightweight server environment, a huge amount of documentation, and a simple package manager (`apt`). It’s a great distribution for building a minimal, secure VM and for learning Linux administration fundamentals.

### Debian — Pros
- **Stable and reliable**: conservative updates reduce unexpected behavior.
- **Large community + documentation**: easy to find trusted references.
- **Minimal install friendly**: straightforward to run without a GUI.
- **apt ecosystem**: easy installs, upgrades, and security updates.

### Debian — Cons
- Packages in “stable” can be **older** than rolling-release distros.
- Many enterprise guides/tools may target RHEL-like systems first (Rocky/RHEL).

---

## Main design choices in my setup

### Partitioning (LVM) — what I did and why
**Design choice:** I used **LVM** and separated key mount points into dedicated logical volumes:

- `/`  
- `/home`  
- `/var`  
- `/srv`  
- `/tmp`  
- `swap`  
- `/var/log`

**Why LVM:**
- Easier resizing and management of partitions (logical volumes) later.
- More flexible than classic fixed partitions if storage needs change.

**Why separate mount points:**
- **Containment / stability:** prevents one area (like logs or temporary files) from filling the root filesystem.
- **Security:** `/tmp` can be mounted with restrictive options (commonly `noexec`, `nodev`, `nosuid`) to reduce risk.
- **Operational clarity:** `/var` and `/var/log` are natural growth areas; separating them helps avoid system-wide outages due to log growth.
- **Service data isolation:** `/srv` keeps service/application data separate and easier to manage/backup.

> Note: In many setups `/var/log` is either part of `/var` or a separate LV. Here it is **separate**, which improves protection against log files consuming all `/var` space.

### Security policies
- Enforced strong password rules (length/complexity/expiration) according to the subject requirements.
- Used `sudo` for administrative tasks instead of day-to-day root usage.
- Hardened SSH and set it to port **4242**.
- Kept the system minimal (only required services installed).

### User management
- Created a non-root user: `mbahri`
- Granted admin privileges via the `sudo` group.
- Applied password policy rules to users as required.

### Services installed
- **OpenSSH server** (remote access)
- **UFW firewall** (restrict inbound access; only allow needed ports)

---

## Required comparisons

### Debian vs Rocky Linux
| Topic | Debian | Rocky Linux |
|---|---|---|
| Philosophy | Community-driven, stability-focused | Enterprise-oriented, RHEL-compatible |
| Package manager | `apt` | `dnf` |
| Packaging | `.deb` | `.rpm` |
| Security MAC ecosystem | AppArmor commonly used | SELinux is standard |
| Typical usage | General servers, cloud, devops | Enterprise Linux environments |

**Summary:** Debian is excellent for a minimal stable VM with simple tooling. Rocky is excellent for learning enterprise/RHEL workflows and SELinux.

### AppArmor vs SELinux
| Topic | AppArmor | SELinux |
|---|---|---|
| Control model | Path-based | Label-based |
| Learning curve | Usually easier | Steeper but more comprehensive |
| Common on | Debian/Ubuntu | Rocky/RHEL/Fedora |
| Strength | Simple to manage profiles | Strong, fine-grained MAC enforcement |

**Summary:** AppArmor is often quicker to adopt; SELinux is more complex but extremely powerful and standard in many enterprise distros.

### UFW vs firewalld
| Topic | UFW | firewalld |
|---|---|---|
| Common on | Debian/Ubuntu | Rocky/RHEL/Fedora |
| Approach | Simple rule-based CLI | Zones/services + runtime/permanent rules |
| Best for | Small, clear firewall setups | Advanced network policies |

**Summary:** UFW is ideal for a small Debian VM because it is simple and easy to audit. firewalld is better for more complex setups and is common in RHEL-like systems.

### VirtualBox vs UTM
| Topic | VirtualBox | UTM |
|---|---|---|
| Best platforms | Windows/Linux (also macOS) | macOS-focused (QEMU-based), great on Apple Silicon |
| Common in 42 | Very common | Often used when VirtualBox is limited |
| Strength | Mature tooling, lots of guides | Excellent macOS experience |

**Summary:** VirtualBox is widely used in 42 and has extensive documentation. UTM is a strong alternative, especially on macOS/Apple Silicon.

---

## Instructions

### Start the VM
1. Open **VirtualBox**
2. Start the Debian VM
3. Log in as your user

### Update the system (Debian)
```bash
sudo apt update
sudo apt upgrade -y
```

### SSH (port 4242)
Install + enable SSH:
```bash
sudo apt install openssh-server -y
sudo systemctl enable --now ssh
```

Verify SSH is listening:
```bash
sudo ss -tulpn | grep ssh
```

Connect from the host:
```bash
ssh -p 4242 <username>@<vm_ip>
```

### Firewall (UFW)
Install and enable UFW + allow SSH 4242:
```bash
sudo apt install ufw -y
sudo ufw allow 4242/tcp
sudo ufw enable
```

Check firewall rules:
```bash
sudo ufw status
```

### Verify LVM + mounts (useful for evaluation)
```bash
lsblk
sudo pvs
sudo vgs
sudo lvs
findmnt
```

---

## Resources

### Classic references
- Debian Administrator’s Handbook: https://debian-handbook.info/
- Debian Wiki: https://wiki.debian.org/
- LVM documentation (intro): https://www.sourceware.org/lvm2/
- OpenSSH manual pages: https://man.openbsd.org/ssh
- sudoers manual: https://man7.org/linux/man-pages/man5/sudoers.5.html
- UFW documentation: https://help.ubuntu.com/community/UFW
- AppArmor documentation: https://gitlab.com/apparmor/apparmor/-/wikis/Documentation

### How AI was used
I used AI assistance for:
- Building a verification checklist (LVM, SSH, firewall) to ensure the setup matches the subject.

I did not use AI to:
- Automatically configure the VM or bypass the system administration tasks.
- Provide untested commands. All steps were validated inside the Debian VM and checked against official documentation.

---

## Quick summary of my environment
- OS: **Debian**
- Virtualization: **VirtualBox**
- Storage: **LVM** with dedicated LVs for `/`, `/home`, `/var`, `/srv`, `/tmp`, `swap`, `/var/log`
- SSH port: **4242**
- Firewall: **UFW**
