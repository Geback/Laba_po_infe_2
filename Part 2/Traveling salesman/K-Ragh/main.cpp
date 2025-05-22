#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include "gragh.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    GraphWidget graph;

    // Создаём кнопки
    QPushButton addEdgeButton("Добавить ребро");  // Новая кнопка
    QPushButton removeEdgeButton("Удалить ребро");
    QPushButton editWeightButton("Изменить вес ребра");
    QPushButton matrixButton("Показать матрицу смежности");
    QPushButton tspButton("Решить задачу коммивояжера");

    QObject::connect(&tspButton, &QPushButton::clicked, [&graph]() {
        bool ok;
        int startVertex = QInputDialog::getInt(
            nullptr,
            "Задача коммивояжера",
            "Номер начальной вершины:",
            1, 1, graph.getNumNodes(), 1, &ok
            );
        if (!ok) return;

        int pathLength;
        QVector<int> path = graph.solveTSP_BranchAndBound(startVertex, pathLength);

        if (path.isEmpty()) {
            QMessageBox::information(nullptr, "Результат",
                                     "Не удалось найти гамильтонов цикл, проходящий через все вершины!");
        } else {
            QString pathString;
            for (int i = 0; i < path.size(); ++i) {
                if (i > 0) pathString += " -> ";
                pathString += QString::number(path[i]);
            }

            QMessageBox::information(nullptr, "Результат",
                                     QString("Оптимальный путь: %1\nДлина пути: %2").arg(pathString).arg(pathLength));
        }
    });

    // Событие для добавления ребра
    QObject::connect(&addEdgeButton, &QPushButton::clicked, [&graph]() {
        bool ok;

        int from = QInputDialog::getInt(
            nullptr,
            "Добавить ребро",
            "Номер начальной вершины:",
            1,  // Минимальный номер (1)
            1,  // Минимальное значение
            graph.getNumNodes(),  // Максимальный номер (nodes.size())
            1,  // Шаг
            &ok
            );
        if (!ok) return;

        int to = QInputDialog::getInt(
            nullptr,
            "Добавить ребро",
            "Номер конечной вершины:",
            1,  // Минимальный номер (1)
            1,  // Минимальное значение
            graph.getNumNodes(),  // Максимальный номер (nodes.size())
            1,  // Шаг
            &ok
            );
        if (!ok) return;

        int weight = QInputDialog::getInt(
            nullptr,
            "Добавить ребро",
            "Вес ребра:",
            1,  // Минимальный вес
            1,  // Минимальное значение
            100,  // Максимальный вес
            1,  // Шаг
            &ok
            );
        if (!ok) return;

        graph.addEdge(from, to, weight); // Теперь addEdge работает с номерами!
    });

    // Событие для удаления ребра
    QObject::connect(&removeEdgeButton, &QPushButton::clicked, [&graph]() {
        bool ok;

        int from = QInputDialog::getInt(
            nullptr,
            "Удалить ребро",
            "Номер начальной вершины:",
            1, 1, graph.getNumNodes(), 1, &ok
            );
        if (!ok) return;

        int to = QInputDialog::getInt(
            nullptr,
            "Удалить ребро",
            "Номер конечной вершины:",
            1, 1, graph.getNumNodes(), 1, &ok
            );
        if (!ok) return;

        graph.removeEdge(from, to);
    });

    // Событие для изменения веса ребра
    QObject::connect(&editWeightButton, &QPushButton::clicked, [&graph]() {
        bool ok;

        // Запрос вершин
        int from = QInputDialog::getInt(
            nullptr,
            "Изменить вес ребра",
            "Номер начальной вершины:",
            1, 1, graph.getNumNodes(), 1, &ok
            );
        if (!ok) return;

        int to = QInputDialog::getInt(
            nullptr,
            "Изменить вес ребра",
            "Номер конечной вершины:",
            1, 1, graph.getNumNodes(), 1, &ok
            );
        if (!ok) return;

        // Проверка существования ребра
        if (graph.getEdgeWeight(from, to) == 0) {
            QMessageBox::warning(nullptr, "Ошибка", "Ребро между выбранными вершинами не существует!");
            return;
        }

        // Запрос нового веса
        int newWeight = QInputDialog::getInt(
            nullptr,
            "Изменить вес ребра",
            "Новый вес ребра:",
            graph.getEdgeWeight(from, to), 1, 100, 1, &ok
            );
        if (!ok) return;

        graph.updateEdgeWeight(from, to, newWeight);
    });

    // Событие для вывода матрицы
    QObject::connect(&matrixButton, &QPushButton::clicked, [&graph]() {
        graph.printAdjacencyMatrix();
    });

    // Расположение кнопок
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(&addEdgeButton);
    buttonLayout->addWidget(&removeEdgeButton);
    buttonLayout->addWidget(&editWeightButton);
    buttonLayout->addWidget(&matrixButton);
    buttonLayout->addWidget(&tspButton);

    // Основной layout
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(&graph);
    mainLayout->addLayout(buttonLayout);

    // Главное окно
    QWidget window;
    window.setLayout(mainLayout);
    window.setWindowTitle("Граф Коммивoяжер");
    window.resize(800, 600);
    window.show();

    return app.exec();
}
