#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QPainter>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <cmath>
#include <vector>
#include <algorithm>

// Структура узла бинарного дерева
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

struct DrawNode {
    TreeNode* node;
    int x, y;

    DrawNode(TreeNode* n = nullptr) : node(n), x(0), y(0) {}
};

class BinaryTreeWidget : public QWidget {
public:

    BinaryTreeWidget(QWidget* parent = nullptr) : QWidget(parent), root(nullptr), xPos(0) {
        highlightTimer = new QTimer(this);
        highlightTimer->setSingleShot(true);
        connect(highlightTimer, &QTimer::timeout, [this]() {
            highlightedNode = nullptr;
            update();
        });
    }

    void insertNode(int key) {
        root = insert(root, key);
        update();
    }

    void deleteNode(int key) {
        root = remove(root, key);
        update();
    }

    void preOrderTraversal() {
        qDebug() << "Pre-order:" << preOrder(root);
    }

    void inOrderTraversal() {
        qDebug() << "In-order:" << inOrder(root);
    }

    void postOrderTraversal() {
        qDebug() << "Post-order:" << postOrder(root);
    }

    void balanceTree() {
        root = balance(root);
        update();
    }

    int findMaxValue() {
        if (root == nullptr) throw std::runtime_error("Дерево пустое");
        return findMax(root)->key;
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    void printtoConsole() {
        qDebug() << "Вертикальное представление дерева:";
        printTree(root);
        qDebug() << "";
    }

    bool searchNode(int key) {
        TreeNode* foundNode = searchWithNode(root, key);  // Новая функция поиска
        if (foundNode) {
            highlightedNode = foundNode;
            highlightTimer->start(1000);  // Подсветка на 1 секунду
            update();
            return true;
        }
        return false;
    }

    TreeNode* searchWithNode(TreeNode* node, int key) {
        if (!node) return nullptr;
        if (key == node->key) return node;
        return key < node->key ? searchWithNode(node->left, key) : searchWithNode(node->right, key);
    }

    void paintEvent(QPaintEvent* event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        if (isEmpty())
            return;

        int radius = 20;
        int spacing = 80;

        int count = getNodeCount(root);
        int depth = getDepth(root);

        int xOffset = qMax(spacing, width() / (count + 1));
        int startX = 50;
        int startY = 50;

        QVector<DrawNode> drawNodes;

        int currentX = startX;
        drawTree(painter, root, 1, currentX, startY, xOffset, drawNodes);

        // Рисуем линии между узлами
        for (const DrawNode &dn : drawNodes) {
            if (dn.node->left) {
                auto it = std::find_if(drawNodes.begin(), drawNodes.end(),
                                       [&](const DrawNode& other) { return other.node == dn.node->left; });
                if (it != drawNodes.end()) {
                    painter.drawLine(dn.x, dn.y + radius, it->x, it->y - radius);
                }
            }

            if (dn.node->right) {
                auto it = std::find_if(drawNodes.begin(), drawNodes.end(),
                                       [&](const DrawNode& other) { return other.node == dn.node->right; });
                if (it != drawNodes.end()) {
                    painter.drawLine(dn.x, dn.y + radius, it->x, it->y - radius);
                }
            }
        }
    }

private:
    TreeNode* root;
    int xPos;
    TreeNode* highlightedNode = nullptr;  // Указатель на подсвечиваемый узел
    QTimer* highlightTimer;              // Таймер для сброса подсветки     // Таймер для сброса подсветки

    void printTree(TreeNode* node) {
        if (!node) return;

        int height = getDepth(node);
        int width = pow(2, height) - 1;
        std::vector<std::vector<QString>> levels(height, std::vector<QString>(width, " "));

        fillLevels(node, levels, 0, 0, width - 1);

        qDebug() << "Дерево:";
        for (const auto& level : levels) {
            QString line;
            for (const auto& node : level) {
                line += node;
            }
            qDebug().noquote() << line;
        }
        qDebug() << "";
    }

    void fillLevels(TreeNode* node, std::vector<std::vector<QString>>& levels,
                    int level, int left, int right) {
        if (!node) return;

        int mid = (left + right) / 2;
        levels[level][mid] = QString::number(node->key);

        fillLevels(node->left, levels, level + 1, left, mid - 1);
        fillLevels(node->right, levels, level + 1, mid + 1, right);
    }

    TreeNode* insert(TreeNode* node, int key) {
        if (!node) return new TreeNode(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        return node;
    }

    TreeNode* remove(TreeNode* node, int key) {
        if (!node) return nullptr;

        if (key < node->key)
            node->left = remove(node->left, key);
        else if (key > node->key)
            node->right = remove(node->right, key);
        else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            } else if (!node->left) {
                TreeNode* tmp = node->right;
                delete node;
                return tmp;
            } else if (!node->right) {
                TreeNode* tmp = node->left;
                delete node;
                return tmp;
            } else {
                TreeNode* maxNode = findMax(node->right);
                node->key = maxNode->key;
                node->right = remove(node->right, maxNode->key);
            }
        }
        return node;
    }


    bool search(TreeNode* node, int key) {
        if (!node) return false;
        if (key == node->key) return true;
        return key < node->key ? search(node->left, key) : search(node->right, key);
    }

    QString preOrder(TreeNode* node) {
        if (!node) return "";
        QString result = QString::number(node->key) + " ";
        result += preOrder(node->left);
        result += preOrder(node->right);
        return result;
    }

    QString inOrder(TreeNode* node) {
        if (!node) return "";
        QString result = inOrder(node->left);
        result += QString::number(node->key) + " ";
        result += inOrder(node->right);
        return result;
    }

    QString postOrder(TreeNode* node) {
        if (!node) return "";
        QString result = postOrder(node->left);
        result += postOrder(node->right);
        result += QString::number(node->key) + " ";
        return result;
    }

    TreeNode* balance(TreeNode* node) {
        if (!node) return nullptr;
        QVector<int> keys;
        collectKeys(node, keys);
        return buildBalanced(keys, 0, keys.size() - 1);
    }

    void collectKeys(TreeNode* node, QVector<int>& keys) {
        if (node) {
            collectKeys(node->left, keys);
            keys.append(node->key);
            collectKeys(node->right, keys);
        }
    }

    TreeNode* buildBalanced(const QVector<int>& keys, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(keys[mid]);
        node->left = buildBalanced(keys, left, mid - 1);
        node->right = buildBalanced(keys, mid + 1, right);
        return node;
    }

    TreeNode* findMax(TreeNode* node) {
        while (node && node->right) node = node->right;
        return node;
    }

    int getDepth(TreeNode* node) {
        if (!node) return 0;
        return 1 + qMax(getDepth(node->left), getDepth(node->right));
    }

    int getNodeCount(TreeNode* node) {
        if (!node) return 0;
        return 1 + getNodeCount(node->left) + getNodeCount(node->right);
    }

    void drawTree(QPainter &painter, TreeNode *node, int level, int &x, int y, int xOffset, QVector<DrawNode> &drawNodes) {
        if (!node) return;

        int radius = 20;
        int levelHeight = 80;

        drawTree(painter, node->left, level + 1, x, y + levelHeight, xOffset, drawNodes);

        // Подсветка найденного узла
        if (node == highlightedNode) {
            painter.setBrush(Qt::green);
        } else {
            painter.setBrush(Qt::white);
        }

        painter.drawEllipse(QPointF(x, y), radius, radius);
        painter.drawText(QRectF(x - radius, y - radius, 2 * radius, 2 * radius),
                         Qt::AlignCenter, QString::number(node->key));

        DrawNode dn(node);
        dn.x = x;
        dn.y = y;
        drawNodes.append(dn);

        x += xOffset;

        drawTree(painter, node->right, level + 1, x, y + levelHeight, xOffset, drawNodes);
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    BinaryTreeWidget binaryTreeWidget;

    QPushButton insertButton("Вставить");
    QObject::connect(&insertButton, &QPushButton::clicked, [&binaryTreeWidget]() {
        bool ok;
        int key = QInputDialog::getInt(nullptr, "Вставить узел", "Введите ключ:", 0, INT_MIN, INT_MAX, 1, &ok);
        if (ok) {
            binaryTreeWidget.insertNode(key);
        }
    });

    QPushButton deleteButton("Удалить");
    QObject::connect(&deleteButton, &QPushButton::clicked, [&binaryTreeWidget]() {
        bool ok;
        int key = QInputDialog::getInt(nullptr, "Удалить узел", "Введите ключ:", 0, INT_MIN, INT_MAX, 1, &ok);
        if (ok) {
            binaryTreeWidget.deleteNode(key);
        }
    });

    QPushButton searchButton("Поиск");
    QObject::connect(&searchButton, &QPushButton::clicked, [&binaryTreeWidget]() {
        bool ok;
        int key = QInputDialog::getInt(nullptr, "Поиск узла", "Введите ключ:", 0, INT_MIN, INT_MAX, 1, &ok);
        if (ok) {
            bool found = binaryTreeWidget.searchNode(key);
            QMessageBox::information(nullptr, "Результат поиска", found ? "Ключ найден!" : "Ключ не найден!");
        }
    });

    QPushButton printButton("Вывести в консоль");
    QObject::connect(&printButton, &QPushButton::clicked, [&binaryTreeWidget]() {
        binaryTreeWidget.printtoConsole();
    });

    QPushButton preOrderButton("Прямой обход");
    QObject::connect(&preOrderButton, &QPushButton::clicked, [&binaryTreeWidget]() {
        binaryTreeWidget.preOrderTraversal();
    });


    QPushButton inOrderButton("Симметричный обход");
    QObject::connect(&inOrderButton, &QPushButton::clicked, [&binaryTreeWidget]() {
        binaryTreeWidget.inOrderTraversal();
    });

    QPushButton postOrderButton("Обратный обход");
    QObject::connect(&postOrderButton, &QPushButton::clicked, [&binaryTreeWidget]() {
        binaryTreeWidget.postOrderTraversal();
    });

    QPushButton balanceButton("Балансировка");
    QObject::connect(&balanceButton, &QPushButton::clicked, [&binaryTreeWidget]() {
        binaryTreeWidget.balanceTree();
    });

    QPushButton findMinButton("Найти максимум");
    QObject::connect(&findMinButton, &QPushButton::clicked, [&binaryTreeWidget]() {
        if (binaryTreeWidget.isEmpty()) {
            QMessageBox::information(nullptr, "Ошибка", "Дерево пустое!");
            return;
        }
        int minValue = binaryTreeWidget.findMaxValue();
        QString message = QString("Максимальный элемент: %1").arg(minValue);
        QMessageBox::information(nullptr, "Максимум", message);
    });

    QVBoxLayout layout;
    layout.addWidget(&binaryTreeWidget);

    QHBoxLayout buttonLayout;
    buttonLayout.addWidget(&insertButton);
    buttonLayout.addWidget(&deleteButton);
    buttonLayout.addWidget(&searchButton);
    buttonLayout.addWidget(&printButton);
    buttonLayout.addWidget(&preOrderButton);
    buttonLayout.addWidget(&inOrderButton);
    buttonLayout.addWidget(&postOrderButton);
    buttonLayout.addWidget(&balanceButton);
    buttonLayout.addWidget(&findMinButton);

    QWidget mainWidget;
    mainWidget.setLayout(&buttonLayout);

    layout.addWidget(&mainWidget);

    QWidget window;
    window.setLayout(&layout);
    window.setWindowTitle("Бинарное дерево с визуализацией");
    window.resize(1000, 800);
    window.show();

    return app.exec();
}
