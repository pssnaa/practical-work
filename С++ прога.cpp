#include <iostream> //подключение библиотек
#include <cstdlib>
#include <ctime>

int main() { //задаем функцию
    srand(time(0)); //инициализируем генератор случайных чисел
    int randomNumber = rand() % 100 + 1; //генерируем случайное число в диапазоне от 1 до 100
    int guess = 0; //задаем переменную для хранения введенных пользователем ответов

    std::cout << "I have generated a random number between 1 and 100." << std::endl; //вывод указанных сообщений
    std::cout << "Can you guess what it is?" << std::endl;

    while (guess != randomNumber) { //задаем цикл
        std::cout << "Enter your guess: "; //запрашиваем ответ у пользователя
        std::cin >> guess; //заносим этот ответ в указанную переменную

        if (guess > randomNumber) { //проверяем число на схождение с заданным программой и выводим ответ исходя из того больше оно, меньше или равно заданному
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number!" << std::endl;
        }
    }

    return 0; //сигнал об успешном завершении работы программы
}