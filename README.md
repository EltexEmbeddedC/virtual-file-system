# Виртуальная файловая система

## Сборка и запуск

1. Необходимо перейти в корневую директорию и выполнить команду для сборки проекта ```make```

2. Исполняемые файлы появятся в папке ```bin```

3. Для удаления всех объектных и исполняемых файлов необходимо выполнить команду ```make clean```

## Задания

### Задание 1. Написать программу, которая создает файл с именем ```output.txt```, записывает в него строку ```String from file```, затем считывает ее из файла с конца и выводит на экран.

Результат работы программы:

```
Перевернутая строка: elif morf gnirtS
```

### Задание 2. Реализовать файловый менеджер на подобии mc, с функционалом навигации по папкам и двумя панелями (переключение между панелями через Tab). Использовать для графики библиотеку ncurses.

**Возможности разработанной программы:**

1. Открытие содержимого папки осуществляется нажатием клавиши ```Enter```.
    ![Переход по папкам](/img/enter.gif)

2. Переход между панелями вывода осуществляется нажатием клавишии ```Tab```.
    ![Переход между панелями](/img/tab.gif)

3. Специальный порядок вывода на экран: сначала папки, отсортированные в алфавитном порядке, затем отсортированные файлы.

4. Папки и файлы отличаются по цвету.

5. Внизу окна указывается текущий выбранный элемент соответствущюей панели.
