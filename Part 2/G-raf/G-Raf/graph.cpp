#include "graph.h"
#include <QPainter>
#include <QMessageBox>
#include <QPen>
#include <cmath>

GraphWidget::GraphWidget(QWidget *parent) : QWidget(parent) {
    // Добавляем начальные вершины
    nodes.append(QPoint(600, 150));
    nodes.append(QPoint(350, 500));
    nodes.append(QPoint(650, 350));
    nodes.append(QPoint(180, 420));
    nodes.append(QPoint(220, 250));
    nodes.append(QPoint(300, 100));

    // Инициализируем матрицу смежности и весов
    adjacencyMatrix.resize(nodes.size());
    edgeWeights.resize(nodes.size());
    for (int i = 0; i < nodes.size(); ++i) {
        adjacencyMatrix[i].resize(nodes.size(), 0);
        edgeWeights[i].resize(nodes.size(), 0);
    }

    // Добавляем рёбра и их веса
    adjacencyMatrix[0][1] = adjacencyMatrix[1][0] = 1;  //
    adjacencyMatrix[0][4] = adjacencyMatrix[4][0] = 1;
    adjacencyMatrix[0][5] = adjacencyMatrix[5][0] = 1;
    adjacencyMatrix[1][2] = adjacencyMatrix[2][1] = 1;  //
    adjacencyMatrix[2][0] = adjacencyMatrix[0][2] = 1;  //
    adjacencyMatrix[1][4] = adjacencyMatrix[4][1] = 1;
    adjacencyMatrix[1][3] = adjacencyMatrix[3][1] = 1;
    adjacencyMatrix[3][4] = adjacencyMatrix[4][3] = 1;
    adjacencyMatrix[5][4] = adjacencyMatrix[4][5] = 1;

    edgeWeights[0][1] = edgeWeights[1][0] = 34;
    edgeWeights[0][4] = edgeWeights[4][0] = 2;
    edgeWeights[0][5] = edgeWeights[5][0] = 21;
    edgeWeights[1][2] = edgeWeights[2][1] = 57;  //
    edgeWeights[2][0] = edgeWeights[0][2] = 8;  //
    edgeWeights[1][4] = edgeWeights[4][1] = 5;
    edgeWeights[1][3] = edgeWeights[3][1] = 45;
    edgeWeights[3][4] = edgeWeights[4][3] = 3;
    edgeWeights[5][4] = edgeWeights[4][5] = 13;
}

void GraphWidget::breadthFirstSearch(int startVertex) {
    // Преобразуем номер вершины (начиная с 1) в индекс (начиная с 0)
    int startIndex = startVertex - 1;

    if (startIndex < 0 || startIndex >= nodes.size()) {
        qDebug() << "Недопустимый номер стартовой вершины:" << startVertex;
        return;
    }

    clearVisited();
    clearTraversal();

    QList<int> queue;
    visited[startIndex] = true;
    queue.append(startIndex);
    bfsTraversal.append(startVertex); // Записываем номер, а не индекс

    while (!queue.isEmpty()) {
        int currentIndex = queue.takeFirst();
        for (int i = 0; i < adjacencyMatrix[currentIndex].size(); ++i) {
            if (adjacencyMatrix[currentIndex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue.append(i);
                bfsTraversal.append(i + 1); // Преобразуем индекс в номер
            }
        }
    }

    qDebug() << "Обход в ширину:" << bfsTraversal;
}

void GraphWidget::depthFirstSearch(int startVertex) {
    // Преобразуем номер вершины (начиная с 1) в индекс (начиная с 0)
    int startIndex = startVertex - 1;

    if (startIndex < 0 || startIndex >= nodes.size()) {
        qDebug() << "Недопустимый номер стартовой вершины:" << startVertex;
        return;
    }

    clearVisited();
    clearTraversal();
    dfsRecursive(startIndex); // dfsRecursive работает с индексами, но сохраняет номера
    qDebug() << "Обход в глубину:" << dfsTraversal;
}

void GraphWidget::dfsRecursive(int currentIndex) {
    visited[currentIndex] = true;
    dfsTraversal.append(currentIndex + 1); // Сохраняем номер вершины (не индекс)

    for (int i = 0; i < adjacencyMatrix[currentIndex].size(); ++i) {
        if (adjacencyMatrix[currentIndex][i] == 1 && !visited[i]) {
            dfsRecursive(i);
        }
    }
}

int GraphWidget::getNumNodes() const {
    return nodes.size();
}

void GraphWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Константы вынесены в начало
    const int radius = 20;
    const float edgeTextOffset = 10.0f;
    const QPen edgePen(Qt::black, 2);
    const QPen vertexPen(Qt::black);
    const QBrush vertexBrush(Qt::white);


    QFontMetrics fm(painter.font());

    // Отрисовка рёбер
    painter.setPen(edgePen);
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        for (int j = i + 1; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                const QPoint& p1 = nodes[i];  // Используем ссылки
                const QPoint& p2 = nodes[j];

                // Рисуем линию
                painter.drawLine(p1, p2);

                // Вычисляем параметры для текста веса
                const QPointF center = (p1 + p2) / 2.0;
                const QPointF edgeVec = p2 - p1;
                const float length = std::hypot(edgeVec.x(), edgeVec.y());  // Более точный и быстрый способ

                if (length > 0) {
                    // Нормализованный перпендикуляр
                    const QPointF normal(-edgeVec.y() / length, edgeVec.x() / length);
                    const QPointF textPos = center + normal * edgeTextOffset;

                    // Рисуем вес ребра
                    painter.drawText(textPos, QString::number(edgeWeights[i][j]));
                }
                // Случай совпадающих точек можно не обрабатывать - это ошибка данных
            }
        }
    }

    // Отрисовка вершин
    painter.setPen(vertexPen);
    painter.setBrush(vertexBrush);
    for (const QPoint& pos : nodes) {
        painter.drawEllipse(pos, radius, radius);
    }

    // Отрисовка номеров вершин
    painter.setPen(vertexPen);
    for (int i = 0; i < nodes.size(); ++i) {
        const QString label = QString::number(i+1);
        const QRect rect = fm.boundingRect(label);

        // Оптимизированное центрирование текста
        const int textX = nodes[i].x() - rect.width()/2;
        const int textY = nodes[i].y() + (fm.ascent() - fm.descent())/2;

        painter.drawText(textX, textY, label);
    }
    // Рисуем вершины
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    for (const QPoint &pos : nodes) {
        painter.drawEllipse(pos, radius, radius);
    }

    // Нумерация вершин
    painter.setPen(Qt::black);
    for (int i = 0; i < nodes.size(); ++i) {
        QString label = QString::number(i+1);
        QFontMetrics fm(painter.font());
        QRect rect = fm.boundingRect(label);

        // Центрируем текст относительно точки nodes[i]
        int textX = nodes[i].x() - rect.width()/2;
        int textY = nodes[i].y() + rect.height()/2 - fm.descent();  // учитываем descent для вертикального центрирования

        painter.drawText(textX, textY, label);
    }
}


void GraphWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        const int radius = 20;

        // Проверяем, попали ли на существующую вершину
        for (int i = 0; i < nodes.size(); ++i) {
            QPoint pos = nodes[i];
            if (QVector2D(event->pos() - pos).length() <= radius) {
                selectedNodeIndex = i;
                return;
            }
        }

        // Если нажата клавиша Ctrl — добавляем ребро
        if (event->modifiers() & Qt::ControlModifier) {
            for (int i = 0; i < nodes.size(); ++i) {
                QPoint pos = nodes[i];
                if (QVector2D(event->pos() - pos).length() <= radius) {
                    static int firstIndex = -1;
                    if (firstIndex == -1) {
                        firstIndex = i;
                    } else if (firstIndex != i) {
                        adjacencyMatrix[firstIndex][i] = 1;
                        adjacencyMatrix[i][firstIndex] = 1;
                        edgeWeights[firstIndex][i] = 1;
                        edgeWeights[i][firstIndex] = 1;
                        firstIndex = -1;
                        update();
                    }
                    return;
                }
            }
        } else {
            // Иначе — добавляем вершину
            nodes.append(event->pos());

            // Обновляем матрицы
            int newSize = nodes.size();
            adjacencyMatrix.resize(newSize);
            edgeWeights.resize(newSize);
            for (int i = 0; i < newSize; ++i) {
                adjacencyMatrix[i].resize(newSize, 0);
                edgeWeights[i].resize(newSize, 0);
            }

            update();
        }
    } else if (event->button() == Qt::RightButton) {
        const int radius = 20;
        for (int i = 0; i < nodes.size(); ++i) {
            QPoint pos = nodes[i];
            if (QVector2D(event->pos() - pos).length() <= radius) {
                // Удаляем вершину
                nodes.remove(i);

                // Обновляем матрицы
                adjacencyMatrix.remove(i);
                edgeWeights.remove(i);
                for (auto &row : adjacencyMatrix) row.remove(i);
                for (auto &row : edgeWeights) row.remove(i);

                update();
                return;
            }
        }
    }
}

void GraphWidget::mouseMoveEvent(QMouseEvent *event) {
    if (selectedNodeIndex != -1) {
        nodes[selectedNodeIndex] = event->pos();
        update();
    }
}

void GraphWidget::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    selectedNodeIndex = -1;
}

void GraphWidget::clearVisited() {
    visited.clear();
    visited.resize(nodes.size(), false);
}

void GraphWidget::clearTraversal() {
    bfsTraversal.clear();
    dfsTraversal.clear();
}

void GraphWidget::addEdge(int from, int to, int weight) {
    // Преобразуем номера вершин (1, 2, 3...) в индексы (0, 1, 2...)
    int fromIndex = from - 1;
    int toIndex = to - 1;

    if (fromIndex >= 0 && fromIndex < nodes.size() && toIndex >= 0 && toIndex < nodes.size()) {
        if (adjacencyMatrix[fromIndex][toIndex] == 0){
            adjacencyMatrix[fromIndex][toIndex] = 1;
            adjacencyMatrix[toIndex][fromIndex] = 1;
            edgeWeights[fromIndex][toIndex] = weight;
            edgeWeights[toIndex][fromIndex] = weight;
            update();} // Перерисовываем граф
    } else {
        qDebug() << "Ошибка: Некорректные номера вершин" << from << "или" << to;
    }
}
void GraphWidget::removeEdge(int from, int to) {
    // Преобразуем номера вершин (1, 2, 3...) в индексы (0, 1, 2...)
    int fromIndex = from - 1;
    int toIndex = to - 1;

    if (fromIndex >= 0 && fromIndex < nodes.size() &&
        toIndex >= 0 && toIndex < nodes.size()) {

        adjacencyMatrix[fromIndex][toIndex] = 0;
        adjacencyMatrix[toIndex][fromIndex] = 0;
        edgeWeights[fromIndex][toIndex] = 0;
        edgeWeights[toIndex][fromIndex] = 0;
        update(); // Перерисовываем граф
    } else {
        qDebug() << "Ошибка: Некорректные номера вершин" << from << "или" << to;
    }
}
void GraphWidget::updateEdgeWeight(int from, int to, int newWeight) {
    // Преобразуем номера вершин в индексы
    int fromIndex = from - 1;
    int toIndex = to - 1;

    if (fromIndex >= 0 && fromIndex < nodes.size() &&
        toIndex >= 0 && toIndex < nodes.size() &&
        adjacencyMatrix[fromIndex][toIndex] == 1) {

        edgeWeights[fromIndex][toIndex] = newWeight;
        edgeWeights[toIndex][fromIndex] = newWeight;
        update(); // Перерисовываем граф
    } else {
        qDebug() << "Ошибка: Ребро между вершинами" << from << "и" << to << "не существует";
    }
}

int GraphWidget::getEdgeWeight(int from, int to) const {
    int fromIndex = from - 1;
    int toIndex = to - 1;

    if (fromIndex >= 0 && fromIndex < nodes.size() &&
        toIndex >= 0 && toIndex < nodes.size() &&
        adjacencyMatrix[fromIndex][toIndex] == 1) {
        return edgeWeights[fromIndex][toIndex];
    }
    return 0;
}

void GraphWidget::printAdjacencyMatrix() const {
    QString adjMatrixString;
    QString weightMatrixString;
    int size = nodes.size();

    // Форматированный вывод
    adjMatrixString += "Матрица смежности:\n   ";
    weightMatrixString += "\nМатрица весов:\n   ";

    for (int i = 0; i < size; ++i) {
        adjMatrixString += QString("%1 ").arg(i+1, 2);
        weightMatrixString += QString("%1 ").arg(i+1, 2);
    }

    adjMatrixString += "\n";
    weightMatrixString += "\n";

    for (int i = 0; i < size; ++i) {
        adjMatrixString += QString("%1: ").arg(i+1, 2);
        weightMatrixString += QString("%1: ").arg(i+1, 2);

        for (int j = 0; j < size; ++j) {
            adjMatrixString += QString("%1 ").arg(adjacencyMatrix[i][j], 2);
            weightMatrixString += QString("%1 ").arg(edgeWeights[i][j], 2);
        }
        adjMatrixString += "\n";
        weightMatrixString += "\n";
    }

    QMessageBox::information(nullptr, "Матрицы графа", adjMatrixString + weightMatrixString);
}

// Алгоритм Дейкстры
QVector<int> GraphWidget::dijkstra(int startVertex, QVector<int>& pathLengths) {
    int startIndex = startVertex - 1;
    if (startIndex < 0 || startIndex >= nodes.size()) {
        qDebug() << "Недопустимый номер стартовой вершины";
        return QVector<int>();
    }

    int n = nodes.size();
    QVector<bool> visited(n, false);
    QVector<int> previous(n, -1);
    pathLengths.resize(n);
    std::fill(pathLengths.begin(), pathLengths.end(), std::numeric_limits<int>::max());
    pathLengths[startIndex] = 0;

    for (int i = 0; i < n; ++i) {
        int minIndex = -1;
        // Находим вершину с минимальным расстоянием
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (minIndex == -1 || pathLengths[j] < pathLengths[minIndex])) {
                minIndex = j;
            }
        }

        if (pathLengths[minIndex] == std::numeric_limits<int>::max()) {
            break;
        }

        visited[minIndex] = true;

        // Обновляем расстояния до соседей
        for (int k = 0; k < n; ++k) {
            if (adjacencyMatrix[minIndex][k] == 1 && !visited[k]) {
                int newLength = pathLengths[minIndex] + edgeWeights[minIndex][k];
                if (newLength < pathLengths[k]) {
                    pathLengths[k] = newLength;
                    previous[k] = minIndex;
                }
            }
        }
    }

    return previous;
}

void GraphWidget::floydWarshall(QVector<QVector<int>>& dist, QVector<QVector<int>>& next) {
    int n = getNumNodes();
    dist.resize(n, QVector<int>(n, std::numeric_limits<int>::max()));
    next.resize(n, QVector<int>(n, -1));

    // Инициализация матриц на основе adjacencyMatrix и edgeWeights
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        for (int j = 0; j < n; ++j) {
            if (adjacencyMatrix[i][j] == 1) { // Если есть ребро из i в j
                dist[i][j] = edgeWeights[i][j]; // Используем вес из матрицы весов
                next[i][j] = j; // Следующая вершина на пути - j
            }
        }
    }

    // Алгоритм Флойда-Уоршелла
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != std::numeric_limits<int>::max() &&
                    dist[k][j] != std::numeric_limits<int>::max() &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

QVector<int> GraphWidget::getFloydPath(int start, int end) {
    QVector<QVector<int>> dist, next;
    floydWarshall(dist, next);

    QVector<int> path;

    // Проверка на существование пути (индексы теперь 0-based)
    if (next[start-1][end-1] == -1) {
        return path; // возвращаем пустой вектор
    }

    // Восстановление пути
    path.push_back(start);
    int u = start-1;
    int v = end-1;

    while (u != v) {
        u = next[u][v];
        path.push_back(u+1); // +1 для перехода к 1-индексации
    }

    return path;
}

void GraphWidget::showFloydMatrix() {
    QVector<QVector<int>> dist, next;
    floydWarshall(dist, next);

    QString matrixStr = "Матрица кратчайших расстояний Флойда:\n";
    for (int i = 0; i < dist.size(); ++i) {
        for (int j = 0; j < dist[i].size(); ++j) {
            if (dist[i][j] == std::numeric_limits<int>::max()) {
                matrixStr += "INF\t";
            } else {
                matrixStr += QString::number(dist[i][j]) + "\t";
            }
        }
        matrixStr += "\n";
    }

    QMessageBox::information(this, "Матрица Флойда", matrixStr);
}

