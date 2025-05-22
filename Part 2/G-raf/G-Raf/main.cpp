#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include "graph.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    GraphWidget graph;

    // Создаём кнопки
    QPushButton bfsButton("Обход в ширину");
    QPushButton dfsButton("Обход в глубину");
    QPushButton addEdgeButton("Добавить ребро");  // Новая кнопка
    QPushButton removeEdgeButton("Удалить ребро");
    QPushButton editWeightButton("Изменить вес ребра");
    QPushButton matrixButton("Показать матрицу смежности");
    QPushButton dijkstraButton("Алгоритм Дейкстры");
    QPushButton floydPathButton("Алгоритм Флойда");

    // Событие для BFS
    QObject::connect(&bfsButton, &QPushButton::clicked, [&graph]() {
        bool ok;
        int start = QInputDialog::getInt(nullptr, "BFS", "Стартовая вершина", 0, 0, graph.getNumNodes() - 1, 1, &ok);
        if (ok) {
            graph.breadthFirstSearch(start);
        }
    });

    // Событие для DFS
    QObject::connect(&dfsButton, &QPushButton::clicked, [&graph]() {
        bool ok;
        int start = QInputDialog::getInt(nullptr, "DFS", "Стартовая вершина", 0, 0, graph.getNumNodes() - 1, 1, &ok);
        if (ok) {
            graph.depthFirstSearch(start);
        }
    });


    QObject::connect(&dijkstraButton, &QPushButton::clicked, [&graph]() {
        bool ok;
        int start = QInputDialog::getInt(nullptr, "Дейкстра", "Стартовая вершина:", 1, 1, graph.getNumNodes(), 1, &ok);
        if (!ok) return;

        QVector<int> distances;
        graph.dijkstra(start, distances);

        QString result = "Кратчайшие расстояния от вершины " + QString::number(start) + ":\n";
        for (int i = 0; i < distances.size(); ++i) {
            if (distances[i] != std::numeric_limits<int>::max()) {
                result += QString("До %1: %2\n").arg(i+1).arg(distances[i]);
            } else {
                result += QString("До %1: недостижима\n").arg(i+1);
            }
        }
        QMessageBox::information(nullptr, "Результат Дейкстры", result);
    });

    QObject::connect(&floydPathButton, &QPushButton::clicked, [&graph]() {
        bool ok;
        int start = QInputDialog::getInt(nullptr, "Путь", "Начальная вершина:", 1, 1, graph.getNumNodes(), 1, &ok);
        if (!ok) return;

        int end = QInputDialog::getInt(nullptr, "Путь", "Конечная вершина:", 1, 1, graph.getNumNodes(), 1, &ok);
        if (!ok) return;

        QVector<int> path = graph.getFloydPath(start, end);

        if (path.isEmpty()) {
            QMessageBox::information(nullptr, "Путь", "Путь между вершинами не существует!");
        } else {
            QString pathStr = "Кратчайший путь: " + QString::number(path[0]);
            for (int i = 1; i < path.size(); ++i) {
                pathStr += " → " + QString::number(path[i]);
            }

            QVector<QVector<int>> dist, next;
            graph.floydWarshall(dist, next);
            pathStr += QString("\nДлина пути: %1").arg(dist[start-1][end-1]);

            QMessageBox::information(nullptr, "Путь по Флойду", pathStr);
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
    buttonLayout->addWidget(&bfsButton);
    buttonLayout->addWidget(&dfsButton);
    buttonLayout->addWidget(&addEdgeButton);
    buttonLayout->addWidget(&removeEdgeButton);
    buttonLayout->addWidget(&editWeightButton);
    buttonLayout->addWidget(&matrixButton);
    buttonLayout->addWidget(&dijkstraButton);
    buttonLayout->addWidget(&floydPathButton);

    // Основной layout
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(&graph);
    mainLayout->addLayout(buttonLayout);

    // Главное окно
    QWidget window;
    window.setLayout(mainLayout);
    window.setWindowTitle("Граф с матрицей смежности и весами рёбер");
    window.resize(800, 600);
    window.show();

    return app.exec();
}
