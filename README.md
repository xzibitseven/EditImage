# EditImage
Тестовая задача на С++14. Написана под Linux (Debian Stretch (x64)) c использованием библиотеки OpenCV 4.1.0.

На вход подается два пути к файлам (для исходного и  результирующего).
Поддерживает форматы входящих и выходящих файлов : .jpeg, .png.  Есть возможность расширения поддерживаемых форматов.

Поддерживает функции:
 - удаление шумов с изображения с помощью: Averaging; Gaussian Blurring; Median Blurring (default); Bilateral Filtering;
 - выделение контрастных контуров.

Проект можно собрать в IDE Qt Creator (есть .pro файл) или же через make (есть Makefile). Необходим g++ c поддержкой С++14. 

При отсутствии в ОС библиотеки OpenCV 4.1.0, есть скрипт install_opencv.sh, который установит все необходимое + саму библиотеку.

Для запуска проекта на чистой ОС Linux (Debian, Ubuntu), необходимо выполнить:
   - установить, если отсутствует, g++ c поддержкой С++14;
   - sudo apt-get update;
   - sudo apt-get upgrade;
   - в каталоге ../EditImage/ запускаем скрипт sudo sh install_opencv.sh;
   - переходим в каталог ../EditImage/src/ и запускаем make.

