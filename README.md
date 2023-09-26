# Automatic_programming_of_control_systems_coursework
Построение автоматной модели управления пневмоцилиндрами по заданной управляющей последовательности
<br>
Управляющая последовательность задана в следующем виде:<br>
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20205643.png">
<br>
, где P - состояние каждого из цилиндров: включен или выключен, E - исключения, переход из одного состояния в заданное в случае ошибки, T - заданное время продолжительности состояния, D - отведенное время для задержки, по истечение которого объявляется ошибка.
<br>
Составим диаграмму Мура, ориентируясь на исходные данные. 
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20211018.png">
# Работа в SimlnTech
Создаем модели пневмоцилиндра и поршня:<br>
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20210417.png"> <br>
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20210435.png">
<br>
Построим модель автомата, сгенерируем dll automate.c и automate.h, в настройках укажем директорию для сохранения dll-файла.<br>
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20213025.png">
<br>
Cгенерированный файл подключаем к автомату и смотрим график, сверяем работу состояний с заданными, а также проверяем, что работают переходы-исключения.
<br>
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20213721.png">
Работа цилиндров по заданной последовательности
<br>
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20213744.png">
Работа цилиндров с ошибкой перехода
<br>
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20213758.png">
Работа цилиндров по исключению 1-16
<br>
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/images/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20213813.png">
Работа цилиндров по исключению 2-16
