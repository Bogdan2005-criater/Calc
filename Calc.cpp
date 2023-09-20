#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>

class Calculator : public QMainWindow {
    Q_OBJECT

public:
    Calculator(QWidget *parent = 0) : QMainWindow(parent) {
        setWindowTitle("Инженерный калькулятор");

        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        QVBoxLayout *layout = new QVBoxLayout;
        centralWidget->setLayout(layout);

        resultLineEdit = new QLineEdit();
        resultLineEdit->setReadOnly(true);
        layout->addWidget(resultLineEdit);

        QGridLayout *buttonLayout = new QGridLayout;
        layout->addLayout(buttonLayout);

        const char *buttons[5][4] = {
            {"7", "8", "9", "+"},
            {"4", "5", "6", "-"},
            {"1", "2", "3", "*"},
            {"0", ".", "=", "/"},
            {"sin", "cos", "tan", "^2"}
        };

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 4; ++j) {
                QPushButton *button = new QPushButton(buttons[i][j]);
                buttonLayout->addWidget(button, i, j);
                connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
            }
        }
    }

private slots:
    void buttonClicked() {
        QPushButton *button = qobject_cast<QPushButton *>(sender());
        if (button) {
            QString text = button->text();
            if (text == "=") {
                QString expression = resultLineEdit->text();
                resultLineEdit->setText(QString::number(calculate(expression)));
            } else {
                resultLineEdit->setText(resultLineEdit->text() + text);
            }
        }
    }

    double calculate(const QString &expression) {
        // В этой функции вы можете реализовать парсинг и вычисление математического выражения
        // В данном примере просто вернем результат вычисления с использованием eval
        return eval(expression.toStdString().c_str());
    }

    double eval(const char *expr) {
        // Пример функции для вычисления выражения (например, с использованием библиотеки muParser)
        // Замените эту функцию на свою реализацию или используйте библиотеки для вычисления выражений
        // В этом примере функция всегда возвращает 0
        return 0;
    }

private:
    QLineEdit *resultLineEdit;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Calculator calculator;
    calculator.show();
    return app.exec();
}

#include "main.moc"
