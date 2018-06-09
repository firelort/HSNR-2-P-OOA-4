#include <iostream>
#include "SFMLGraphVisualizer.h"

//Window Size is 1024 x 1024

#define MAXNODES 10
#define MAXEDGES 20

using namespace std;

int main() {
    char *strings[MAXNODES];
    try {
        srand(time(NULL));
        DiGraph graph;
        SFMLGraphVisualizer graphviz;

        graph.setVisualizer(&graphviz);
        // --- 0/0 ist oben links + offset mindestens 50
        //                                x   y
        graph.addNode(new Node("Berlin", 750, 50));
        graph.addNode(new Node("Muenchen", 835, 876));
        graph.addNode(new Node("Hamburg", 250, 123));
        graph.addNode(new Node("Krefeld", 432, 600));
        graph.addNode(new Node("Moenchengladbach", 480, 530));
        graph.addNode(new Node("Frankfurt", 680 , 342));
        graph.addNode(new Node("Bruessel", 50, 950));


        graph.addEdge(155, "Berlin", "Muenchen");
        graph.addEdge(155, "Muenchen", "Berlin");

        graph.addEdge(150, "Muenchen", "Frankfurt");
        graph.addEdge(150, "Frankfurt", "Muenchen");

        graph.addEdge(50, "Moenchengladbach", "Krefeld");
        graph.addEdge(50, "Krefeld", "Moenchengladbach");

        graph.addEdge(700, "Bruessel", "Krefeld");
        graph.addEdge(700, "Krefeld", "Bruessel");

        graph.addEdge(900, "Bruessel", "Moenchengladbach");

        graph.addEdge(1500, "Bruessel", "Berlin");

        graph.addEdge(730, "Moenchengladbach", "Frankfurt");
        graph.addEdge(730, "Frankfurt", "Moenchengladbach");




        graph.getVisualizer()->visualize(graph, "Berlin", "Bruessel");
        //graph.getVisualizer()->highlightPath(graph.getShortestPathByDijkstra("Berlin", "Muenchen")); //TODO: VISUALIZE BEKOMMEN
    } catch (MyExecption e) {
        cout << e.getMessage() << endl;
    }

    return 0;
}

char *randomString(int size) {
    char *str = (char *) malloc((size + 1) * sizeof(char));
    for (int i = 0; i < size; i++) {
        str[i] = (char) ((rand() % 26) + 'A');
    }
    str[size] = '\0';
    return str;
}