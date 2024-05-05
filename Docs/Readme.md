[ESP32C3- supermini]

Refs:======================
https://dl.artronshop.co.th/ESP32-C3%20SuperMini%20datasheet.pdf
https://www.sudo.is/docs/esphome/boards/esp32c3supermini/
https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf
https://hackaday.io/project/190591-mercator-origins-sat-nav-telemetry-for-divers/log/219829-behold-the-audio-navigation-module
https://dronebotworkshop.com/esp32-i2s/
https://github.com/moononournation/MiniTV

Docs link:
https://drive.google.com/drive/folders/1kJmUIwKleFa8GuZc04taklsSHpImJ9UL?usp=sharing

Setup:=========================
1) Upload code in Arduino:
	- choose ESP32C3 Dev Module
	- USB CDC On Boot -> enable: for serial monitor work ok
======================================================


[ESP I2S Audio]
Refs:======================

Note:======================

======================================================

Chuẩn bị: 
1) Đưa 2 file "vao.mp3" và "ra.mp3" vào thẻ nhớ -> cắm thẻ nhớ vào mạch
2) Cắm nguồn vào mạch
3) Thiết bị chính gồm loa, cảm biến được lắp đặt cố định. Nam châm từ lắp vào phần cánh cửa sao cho khi đóng lại thì hai mặt phẳng cảm biến và phần nam châm từ song song và gần nhau

[Kịch bản test 1]
Đi từ ngoài vào -> mở cửa -> đi qua cánh cửa -> phát ra âm thanh của file "vao.mp3" -> phát tới hết bài

[Kịch bản test 2]
Đi từ trong nhà ra -> mở cửa -> phát ra âm thanh của file "ra.mp3" -> phát tới hết bài

[Kịch bản test 3]
Cửa mở ra cố định không đóng lại sau khoảng thời gian 30s hoặc hết bài nhạc đang phát -> không phát ra âm thanh gì cả nữa



