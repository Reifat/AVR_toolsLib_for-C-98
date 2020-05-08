### Пример программы с использованием RegisterSet

В примере показано, как с помощью класса обертки RegisterSet реализовать одну обобщенную программу, которая решает одну и туже задачу на под разную аппаратную платформу. При переносе кода, требуется только изменить конфигурацию для используемых объектов под требуемый МК.

В качестве простого примера реализована следующая программа бегущих огней.\
На 8 разрядный порт ввода/вывода подключены 8 LED диодов\
Скорость переключения LED диодов реализована аппаратным таймером\
Для изменения скорости переключения к порту ввода/вывода подключены 8 кнопок

##### Код программ и схем:
 * [Схема на МК ATmega16]
   * [Код программы для ATmega16]
 * [Схема на МК ATtiny2313]
   * [Код программы для ATtiny2313]
 
Из кода программ видно, что для обоих МК код практически идентичен и отличается только передоваемыми указателями на регистры при создании объекта класса оболочки RegisterSet.
Подключаемый файл "timer_xxxx.hpp" где xxxx - имя МК, это класс описывающий конфигурацию аппаратного таймера для конкретного МК. Для каждого МК он будет индивидуален, и вообще для любой используемой переферии МК необходимо определять конфигурационный класс с некоторым общенным интерфейсом.
##### Конфигурационный класс таймера:
 * [Класс таймера для mega16]
 * [Класс таймера для tiny2313]

Код программы скомпилирован в\
GNU C v5.4 (Atmel studio 7)\
С параметрами
Оптимизация - Optimize for size (-Os)

[Схема на МК ATmega16]:https://github.com/Reifat/MetaBitLibrary/blob/master/example/pictures/Atmega16.png
[Код программы для ATmega16]:https://github.com/Reifat/MetaBitLibrary/blob/master/example/pictures/ATmega_16_code.PNG
[Схема на МК ATtiny2313]:https://github.com/Reifat/MetaBitLibrary/blob/master/example/pictures/ATtiny2313.png
[Код программы для ATtiny2313]:https://github.com/Reifat/MetaBitLibrary/blob/master/example/pictures/ATtiny_2313_code.PNG

[Класс таймера для mega16]:https://github.com/Reifat/MetaBitLibrary/blob/master/example/Example_ATmega16/timer_mega16.hpp
[Класс таймера для tiny2313]:https://github.com/Reifat/MetaBitLibrary/blob/master/example/Example_ATtiny_2313/timer_tiny_2313.hpp
