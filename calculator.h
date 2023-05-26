#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

#include <mybutton.h>

class Calculator : public QWidget {
    Q_OBJECT

public:
    Calculator();

private slots:
    /**
     * @brief Функция нажатия на кнопку цифры
     */
    void digitClicked();

    /**
     * @brief Функция нажатия на кнопку унарного оператора
     */
    void unaryOperatorClicked();

    /**
     * @brief Функция нажатия на кнопку бинарного оператора
     */
    void doubleOperandClicked();

    /**
     * @brief Функция нажатия на кнопку равенства
     */
    void equalClicked();

    /**
     * @brief Функция нажатия на кнопку точки
     */
    void pointClicked();

    /**
     * @brief Функция нажатия на кнопку смены знака
     */
    void changeSignClicked();

    /**
     * @brief Функция нажатия на кнопку удаления посленей цифры
     */
    void backspaceClicked();

    /**
     * @brief Функция нажатия на кнопку очистки текуего вводимого числа
     */
    void clear();

    /**
     * @brief Функция нажатия на кнопку полной очистки
     */
    void clearAll();

    /**
     * @brief Функция нажатия на кнопку очистки числа в дополнительной памяти
     */
    void clearMemory();

    /**
     * @brief Функция нажатия на кнопку чтения дополнительной памяти
     */
    void readMemory();

    /**
     * @brief Функция нажатия на кнопку прибавления к числу в дополнительной памяти
     */
    void addToMemory();

    /**
     * @brief Функция нажатия на кнопку вычитания из числа в дополнительной памяти
     */
    void minToMemory();

private:
    /**
     * @brief Функция создания кнопки
     */
    Button *createButton(const QString& text, const char* member);


    void abortOperation();

    /**
     * @brief Переменая дополнительной памяти
     */
    double m_sum_in_memory;

    /**
     * @brief Переменная, хранащая выбранный оператор
     */
    QString m_pending_operation;

    /**
     * @brief Поле для числа из основной памяти
     */
    QLineEdit* m_display_up;

    /**
     * @brief Поле набора числа
     */
    QLineEdit* m_display_down;

    /**
     * @brief Поле для оператора
     */
    QLabel*    m_sign;

    /**
     * @brief Массив кнопок с цифрами
     */
    Button* m_digitButtons[10];

    /**
     * @brief Функция вычисления результата операции выбранного оператора
     */
    bool calculate(double operand, const QString& operation);

    //-------------------------------------------------------------------
    //Символы для функциональных кнопок
    //-------------------------------------------------------------------
    QString m_squareRoot_sign = QChar(0x0000221A);
    QString m_power_sign      = 'x' + QChar(0x000000b2);
    QString m_reciprocal_sign = "1/x";

    QString m_division_sign    = QChar(0x000000F7);
    QString m_times_sign       = QChar(0x000000D7);
    QString m_plus_sign        = "+";
    QString m_minus_sign       = "-";

    QString m_change_sign       = QChar(0x000000b1);
};

#endif // CALCULATOR_H
