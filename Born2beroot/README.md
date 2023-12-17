# Born2BeRoot

## GRADE: 100/100 

Welcome to Born2BeRoot 42/21, a journey into mastering virtualization! 🚀 This project is optimized for Debian, and while I can't ensure compatibility with CentOS, feel free to PM me on Discord at MMBHWR#0793 for success stories or if you encounter any issues. Let's create Linux magic together!

## monitoring.sh Script

**Known Issues:**
1. Cron may behave unpredictably on Debian boot due to a bug ([Details](https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=635473)). Refer to [rebootfix.txt](rebootfix.txt) for a workaround. Be prepared to explain this to your evaluator.

**Usage Guide:**
- Make the script executable: `chmod +x monitoring.sh`
- Run as root due to journalctl requirements.

## Important Notes

🤓 **Understanding is Key:**
Avoid blind copy-pasting! Delve into the commands, comprehend their purpose, and understand why they work. Google and read the manuals—it's your defense armor.

🔍 **Exploratory Learning:**
Be intelligent, adaptive, and SMART. A thorough knowledge of the tools you use is your superpower. 

## Setup and Configuration Guides

### 1. Cron Setup
   - Open crontab as root: `sudo crontab -e`
   - Add the following lines:
     ```
     @reboot /path/to/file/monitoring.sh
     */10 * * * * /path/to/file/monitoring.sh
     ```
   - Ensure you use the FULL PATH TO FILE (no ~/*/etc.) for cron's peculiarity.

## Additional Files

- [walkthrough37.txt](walkthrough37.txt): A guide on correctly setting up and configuring both Debian and software, including the bonus-part partition setup.
- [evalknowledge.txt](evalknowledge.txt): Q&A from the subject and evaluator checklist.

## Final Words

Congratulations on reaching the pinnacle of Born2BeRoot! 🚀 I won't provide a "full guide with the bonus part" because the journey is about repetition and understanding. Practice the installation process multiple times, especially if this is your first foray into Linux and virtual machines.

Let the Linux adventure begin! 🐧💻
