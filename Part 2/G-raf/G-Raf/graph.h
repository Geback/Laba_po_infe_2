#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QMouseEvent>
#include <QList>
#include <QDebug>
#include <QVector>
#include <limits>

class GraphWidget : public QWidget {
    Q_OBJECT

public:
    QVector<int> dijkstra(int startVertex, QVector<int>& pathLengths); // Алгоритм Дейкстры////

    explicit GraphWidget(QWidget *parent = nullptr);////

    void breadthFirstSearch(int startVertex);///
    void depthFirstSearch(int startVertex);////

    void addEdge(int from, int to, int weight);////
    void removeEdge(int from, int to);/////
    void updateEdgeWeight(int from, int to, int newWeight); ////
    int getEdgeWeight(int from, int to) const;/////

    int getNumNodes() const;////
    void printAdjacencyMatrix() const;/////

    //Флойд
    void floydWarshall(QVector<QVector<int>>& dist, QVector<QVector<int>>& next);///////
    QVector<int> getFloydPath(int start, int end);//////
    void showFloydMatrix(); // Отображение матрицы//////

protected:
    void paintEvent(QPaintEvent *event) override;///
    void mousePressEvent(QMouseEvent *event) override;//
    void mouseMoveEvent(QMouseEvent *event) override;///
    void mouseReleaseEvent(QMouseEvent *event) override;///

private:
    QVector<QPoint> nodes; // Вершины графа/////
    QVector<QVector<int>> adjacencyMatrix; // Матрица смежности////
    QVector<QVector<int>> edgeWeights; // Веса рёбер//////
    int selectedNodeIndex = -1; // Индекс выбранной вершины для перемещения/////

    QVector<bool> visited;/////
    QVector<int> bfsTraversal;/////
    QVector<int> dfsTraversal;/////

    void clearVisited();////
    void clearTraversal();/////
    void dfsRecursive(int vertex);////

    //Флойд
    QVector<QVector<int>> floydDistances; // Матрица расстояний
    QVector<QVector<int>> floydNext;
};

#endif // GRAPH_H
