
#include "MinHeap.h"
int main() {
    //Initialiser un tas min avec une taille initiale de 6
    MinHeap<int> minHeap(6);
    vector<int> tab = { 15, 10, 5, 4, 3, 2 };

    //Construire le tas à partir du tableau
    minHeap.CreerHeap(tab);

    // Print the min heap
    cout << "Tas min construit a partir du tableau: ";
    minHeap.afficherheap();

    //Inserer un nœud dans le tas
    minHeap.InsererNoeud(1);
    cout << "Tas min apres l'insertion du noeud 1: ";
    minHeap.afficherheap();

    //Obtenir la valeur minimale du tas min
    cout << "Valeur la plus elevee du tas min: " << minHeap.peek() << endl;

    //Supprimer le nœud racine du tas min
    cout << "Valeur minimale extraite du tas min: " << minHeap.RetournerMin() << endl;
    cout << "Apres l extraction du tas min: ";
    minHeap.afficherheap();

    //Supprimer une valeur specifique du tas min
    minHeap.supprimerNoeud(4);
    cout << "Apres avoir supprime le noeud 4 du tas min: ";
    minHeap.afficherheap();

    return 0;
}