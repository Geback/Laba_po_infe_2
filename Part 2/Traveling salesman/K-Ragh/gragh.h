#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QMouseEvent>
#include <QList>
#include <QDebug>
#include <QVector>


class GraphWidget : public QWidget {
    Q_OBJECT

public:
    explicit GraphWidget(QWidget *parent = nullptr);

    void addEdge(int from, int to, int weight);
    void removeEdge(int from, int to);
    void updateEdgeWeight(int from, int to, int newWeight);
    int getEdgeWeight(int from, int to) const;

    int getNumNodes() const;
    void printAdjacencyMatrix() const;

    // Метод для решения TSP методом ветвей и границ
    QVector<int> solveTSP_BranchAndBound(int startVertex, int& minPathLength);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QVector<QPoint> nodes; // Вершины графа
    QVector<QVector<int>> adjacencyMatrix; // Матрица смежности
    QVector<QVector<int>> edgeWeights; // Веса рёбер
    int selectedNodeIndex = -1; // Индекс выбранной вершины для перемещения

    QVector<bool> visited;

    void clearVisited();
    void clearTraversal();

    // Вспомогательные методы для Branch and Bound
    void tspBranchAndBound(int currentPos, int currentCost,
                           QVector<bool>& visited, QVector<int>& currentPath,
                           int& minCost, QVector<int>& bestPath);
    int reduceMatrix(QVector<QVector<int>>& reducedMatrix);
    int calculateLowerBound(const QVector<QVector<int>>& matrix);

};

#endif // GRAPH_H
