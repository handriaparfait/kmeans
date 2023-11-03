#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

// Structure pour représenter un point dans l'espace
struct Point {
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}
};

// Fonction pour calculer la distance euclidienne entre deux points
double distance(const Point& a, const Point& b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

// Fonction pour trouver l'indice du centroïde le plus proche d'un point
int findClosestCentroid(const Point& point, const std::vector<Point>& centroids) {
    int closestCentroid = 0;
    double minDistance = std::numeric_limits<double>::max();

    for (int i = 0; i < centroids.size(); i++) {
        double dist = distance(point, centroids[i]);
        if (dist < minDistance) {
            minDistance = dist;
            closestCentroid = i;
        }
    }

    return closestCentroid;
}

int main() {
    // Données d'exemple
    std::vector<Point> data = {Point(1, 2), Point(2, 3), Point(5, 6), Point(9, 10), Point(10, 11), Point(12,6), Point(1,7),Point(1,17)};

    // Nombre de clusters
    int k = 2;

    // Initialisation des centroïdes de manière aléatoire (peut être amélioré)
    std::vector<Point> centroids;
    for (int i = 0; i < k; i++) {
        centroids.push_back(data[i]);
    }

    // Nombre maximum d'itérations
    int maxIterations = 100;

    // Déclaration de la variable "clusters" en dehors de la boucle
    std::vector<std::vector<Point>> clusters(k);

    // Algorithme K-Means
    for (int iteration = 0; iteration < maxIterations; iteration++) {
        // Réinitialisation des clusters
        for (int i = 0; i < k; i++) {
            clusters[i].clear();
        }

        // Affectation des points aux clusters
        for (const Point& point : data) {
            int closestCentroid = findClosestCentroid(point, centroids);
            clusters[closestCentroid].push_back(point);
        }

        // Mise à jour des centroïdes
        for (int i = 0; i < k; i++) {
            if (!clusters[i].empty()) {
                Point sum(0, 0);
                for (const Point& point : clusters[i]) {
                    sum.x += point.x;
                    sum.y += point.y;
                }
                centroids[i] = Point(sum.x / clusters[i].size(), sum.y / clusters[i].size());
            }
        }
    }

    // Affichage des clusters finaux
    for (int i = 0; i < k; i++) {
        std::cout << "Cluster " << i << ":\n";
        std::cout << "Centroid " << i << ": (" << centroids[i].x << ", " << centroids[i].y << ")\n";
        for (const Point& point : clusters[i]) {
            std::cout << "(" << point.x << ", " << point.y << ")\n";
        }
    }

    return 0;
}
