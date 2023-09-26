# Automatic_programming_of_control_systems_coursework
Построение автоматной модели управления пневмоцилиндрами по заданной управляющей последовательности
<br>
Управляющая последовательность задана в следующем виде:<br>
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20205643.png">
<br>
, где P - состояние каждого из цилиндров: включен или выключен, E - исключения, переход из одного состояния в заданное в случае ошибки, T - заданное время продолжительности состояния, D - отведенное время для задержки, по истечение которого объявляется ошибка.
<br>
Составим диаграмму Мура, ориентируясь на исходные данные. 
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20211018.png">
# Работа в SimlnTech
Создаем модели пневмоцилиндра и поршня:<br>
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20210417.png"> <br>
<img src="https://github.com/Alexa6748/Automatic_programming_of_control_systems_coursework/blob/main/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA%20%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0%202023-09-26%20210435.png">
