#include <iostream>
#include <cmath>
#include <vector>
#include <limits>


//structure de Point, constructeur
struct Point{
    double x,y;
    Point(double _x, double _y) : x(_x), y(_y){};
};

// calucl distance entre deux point
double distance(const Point a, const Point b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

//rassembler les points qui sont proches
double pointproche(const Point point, const std::vector<Point> centroids){
    int centroidproches = 0;
    double distancemin = std::numeric_limits<double>::max();

    for (int i = 0; i < centroids.size(); i++){
        double dist = distance(point, centroids[i]);
        if (dist < distancemin){
            distancemin = dist;
            centroidproches = i;
        }
    }

    return centroidproches;

}

int main(){
    std::vector<Point> data = {Point(1, 2), Point(2, 3), Point(5, 6), Point(9, 10), Point(10, 11), Point(12,6), Point(1,7),Point(1,17)};

    int k = 3;

    std::vector<Point> centroids;
    for (int i = 0; i < k; i++) {
        centroids.push_back(data[i]);
    }

    int maxIteration = 100;

    std::vector<std::vector<Point>> clusters(k);
    for (int iteration = 0; iteration < maxIteration; iteration++){
        for (int i = 0; i < k; i++)
        {
            /* code */
            clusters[i].clear();
        }
        

        for (const Point point : data) {
            int centroidsproche = pointproche(point, centroids);
            clusters[centroidsproche].push_back(point);
        }

        for (int i = 0; i < k; i++){
            if(!clusters[i].empty()){
                Point sum(0,0);
                for (const Point point : clusters[i]){
                    sum.x += point.x;
                    sum.y += point.y;

                }
                centroids[i] = Point(sum.x / clusters[i].size(), sum.y / clusters[i].size());
            }
        }

    }

    for (int i = 0; i < k; i++){
        std::cout << "Centroid " << i << ": (" << centroids[i].x << ", " << centroids[i].y << ")\n";
        for (const Point point : clusters[i]){
            std::cout << "(" << point.x << ", " << point.y  << ")\n";
        }
    }

    return 0;

}