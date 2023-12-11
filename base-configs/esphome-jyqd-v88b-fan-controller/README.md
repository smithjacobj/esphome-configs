REMINDER: Strapping pins are GPIO0, GPIO2, GPIO12 (MTDI) and GPIO15 (MTDO)

# BOM
* Juyi JYQD V8.8B BLDC motor controller (mains AC input) -
  https://www.aliexpress.us/item/3256803318592071.html
* ESP32 - any ESP will work with configuration, this uses the HiLetGo ESP32S -
  https://www.amazon.com/dp/B0718T232Z
* Mains AC to 5VDC buck converter (required because the BLDC motor controller specifically says not
  to host power off the 5v interface; any power supply including USB power will likely work) -
  https://www.amazon.com/dp/B07V5XP92F
* Optocouplers - any 5v compatible will work, keeps the BLDC controller and ESP 5v separate -
  https://www.amazon.com/dp/B01JG8EJVW
